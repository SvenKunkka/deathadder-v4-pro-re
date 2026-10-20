import ghidra.app.script.GhidraScript;
import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateMouseAdaptive extends GhidraScript {
 String hex(byte[] b){return HexFormat.of().formatHex(b);}
 String pack(byte[] b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.DeflaterOutputStream z=new java.util.zip.DeflaterOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w16(byte[] b,int a,int x){b[a]=(byte)x;b[a+1]=(byte)(x>>>8);}
 void w32(byte[] b,int a,int x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(i*8));}
 public void run()throws Exception {
  String expected="c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48";
  byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
  if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals(expected)||!Arrays.equals(image,getBytes(toAddr(0x0e06c000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0xc6b0),getBytes(toAddr(0x23020000L),0xc6b0)))throw new Exception("Image/mapping mismatch");
  println("VERIFIED_IMAGE="+expected);Random random=new Random(0x120221ea8L);
  int[] channels={0,1,18,36,37,63,127,255},counts={0,1,14,15,16,17,255,65535},avgs={0,1,69,70,71,127,254,255};
  try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
   for(int test=0;test<1536;test++){
    int op=test>=1408?2:test%4==0?1:0,phase=test<512?0:test<1024?1:test<1280?2:test<1408?new int[]{3,255,256,-1}[test%4]:random.nextInt();
    int peer=op==1?0:(test/4)%2,channel=channels[test%8],reason=random.nextInt();
    if(op==1)phase&=255;
    byte[] ram=new byte[65536],pattern=new byte[256];random.nextBytes(pattern);for(int i=0;i<ram.length;i++)ram[i]=pattern[i%256];
    for(int pp=0;pp<2;pp++){
     int b=0x2978+pp*0xee0,w=test%32,rd=(test/8)%3==0?(w+1)%32:(test/8)%3==1?(w+2)%32:w;
     ram[b+0x15e]=(byte)w;ram[b+0x164]=(byte)rd;ram[b+0x16a]=32;ram[b+0x170]=16;w32(ram,b+0x178,0x23002b08+pp*0xee0);ram[b+0xb2]=(byte)((test/3)%8);
    }
    int b=0x2978+peer*0xee0;
    ram[b+0x84]=(byte)(test%17==0?1:0);ram[b+0x85]=(byte)(test%19==0?1:0);ram[b+0x81]=(byte)(test%13==0?0:1);
    w16(ram,b+0x82,new int[]{0,1,2,3,4,5,6,65535}[(test/3)%8]);
    ram[b+0x69]=(byte)avgs[(test/16)%8];ram[b+0x6a]=(byte)new int[]{0,1,80,255}[(test/4)%4];ram[b+0x6b]=(byte)new int[]{0,1,70,254}[(test/8)%4];ram[b+0x6d]=(byte)avgs[test%8];w16(ram,b+0x70,test%9==0?0:test%9==1?65535:random.nextInt());w16(ram,b+0x72,counts[(test/2)%8]);
    if(phase==0){
     w16(ram,0x2854+channel*2,new int[]{0,31,32,33,64,256,65534,65535}[(test/8)%8]);
     w16(ram,0x289e+channel*2,new int[]{0,3,4,5,8,4095,8191,8192}[(test/16)%8]);
     w16(ram,0x28e8+channel*2,new int[]{0,4,5,6,65535}[(test/32)%5]);
     ram[0x294d+channel]=(byte)(test%7==0?1:test%11==0?2:0);
     w16(ram,0x2934,test%5==0?2:test%5==1?1:0);w16(ram,0x2936,test%11==0?0:1);
    }
    ram[0x76f6]=(byte)channel;ram[0x76f7]=(byte)phase;
    byte[] nvic=new byte[4];random.nextBytes(nvic);
    EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
    try{
     e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);
     for(int j=0;j<=12;j++)e.writeRegister("r"+j,Integer.toUnsignedLong(random.nextInt()));
     for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
     e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x2302ee00L),new byte[512]);e.writeMemory(toAddr(0xe000e208L),nvic);
     e.writeRegister("r0",op==2?Integer.toUnsignedLong(phase):peer);e.writeRegister("r1",op==2?channel:Integer.toUnsignedLong(phase));e.writeRegister("r2",op==2?Integer.toUnsignedLong(reason):channel);e.writeRegister("r3",Integer.toUnsignedLong(reason));
     e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),op==2?0x23022f90L:op==1?0x23022f70L:0x23021ea8L);
     int steps=0;while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<30000){if(!e.step(monitor))throw new Exception("case"+test+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=30000)throw new Exception("step bound"+test);
     out.println("{\"case\":"+test+",\"op\":"+op+",\"phase\":"+Integer.toUnsignedLong(phase)+",\"peer\":"+peer+",\"channel\":"+channel+",\"reason\":"+Integer.toUnsignedLong(reason)+",\"ram_before_z\":\""+pack(ram)+"\",\"ram_after_z\":\""+pack(e.readMemory(toAddr(0x23000000L),65536))+"\",\"nvic_before\":\""+hex(nvic)+"\",\"nvic_after\":\""+hex(e.readMemory(toAddr(0xe000e208L),4))+"\",\"steps\":"+steps+"}");
    }finally{e.dispose();}
   }
  }
  println("ORIGINAL_MOUSE_ADAPTIVE_CASES=1536");
 }
}
