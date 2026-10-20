// Pure original software cipher instructions, no CPU/MMIO overrides.
import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateBusinessControl extends GhidraScript {
 String hex(byte[] b){return HexFormat.of().formatHex(b);}
 String pack(byte[] b)throws Exception{ByteArrayOutputStream out=new ByteArrayOutputStream();try(java.util.zip.DeflaterOutputStream z=new java.util.zip.DeflaterOutputStream(out)){z.write(b);}return Base64.getEncoder().encodeToString(out.toByteArray());}
 void w16(byte[] b,int a,int x){b[a]=(byte)x;b[a+1]=(byte)(x>>>8);}
 void w32(byte[] b,int a,int x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}
 public void run() throws Exception {
  boolean mouse=getScriptArgs()[2].equals("mouse");
  long flash=mouse?0x0e06c000L:0x0e054000L,entry=mouse?0x23020d50L:0x2302003cL;
  int size=mouse?0xc6b0:0x7270,table=mouse?0x2c904:0x1ba74;
  String expected=mouse?"c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48":"f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162";
  byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
  if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals(expected))throw new Exception("Hash mismatch");
  if(!Arrays.equals(image,getBytes(toAddr(flash),image.length)) || !Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+size),getBytes(toAddr(0x23020000L),size)))throw new Exception("Mapping mismatch");
  println("VERIFIED_IMAGE="+expected);Random random=new Random(12022508);
  try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
   for(int test=0;test<448;test++){
    int op=test<256?0:test<384?1:mouse?0:2,peer=(test/4)%2;
    int base=(mouse?0x2978:0x33e8)+peer*(mouse?0xee0:0xf84);
    byte[] pattern=new byte[256];random.nextBytes(pattern);byte[] ram=new byte[65536];for(int i=0;i<ram.length;i++)ram[i]=pattern[i%256];
    int[] lengths={5,0,1,127,128,255};int[] commands=mouse?new int[]{0x28,0x29,0x2b,0x17}:new int[]{0x2b,0x2c,0x17,0x28};
    int[] values={0,1,2,64,65,-1,255,65535};int arg=values[test%8];
    if(mouse){
     int[] modes={1,2,4,0,8,65535};w16(ram,0x2798,modes[(test/4)%6]);
     ram[0x2a96]=(byte)lengths[(test/24)%6];ram[0x2a98]=(byte)(random.nextInt()&0xc7);ram[0x2a99]=(byte)commands[test%4];
     ram[0x29e0]=(byte)((test/8)%2);ram[0x29e5]=(byte)values[(test/3)%8];
     int[] counts={0,29999,30000,30001,65535};w16(ram,0x6b8a,counts[(test/6)%5]);
     w16(ram,0x2794,(test/8)%4);w16(ram,0x29ac+peer*0xee0,(test/16)%2==0?0:8);ram[0x76ee]=(byte)((test/32)%2);
    }else{
     ram[base+0x114]=(byte)lengths[(test/16)%6];ram[base+0x116]=(byte)(random.nextInt()&0xc7);ram[base+0x117]=(byte)commands[test%4];
     ram[base+0x69]=(byte)values[(test/8)%8];w16(ram,0x33dc,test%7==0?65535:random.nextInt());
    }
    // Valid class0 ring initial state; a full/one-slot/empty ring is explicit input.
    if(op==1){
     int qb=mouse?base:0x33e8,wo=mouse?0x15e:0x154,ro=mouse?0x164:0x15a,co=mouse?0x16a:0x160,so=mouse?0x170:0x166,po=mouse?0x178:0x16c;
     int storage=(mouse?0x2b08+peer*0xee0:0x356c),w=test%32,r=(test/8)%3==0?(w+1)%32:(test/8)%3==1?(w+2)%32:w;
     ram[qb+wo]=(byte)w;ram[qb+ro]=(byte)r;ram[qb+co]=32;ram[qb+so]=16;w32(ram,qb+po,0x23000000+storage);
     ram[qb+(mouse?0xb2:0xa7)]=(byte)((test/3)%8);
    }
    byte[] clock=new byte[8],nvic=new byte[4];random.nextBytes(clock);random.nextBytes(nvic);
    EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
    try{
     e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);
     for(int reg=0;reg<=12;reg++)e.writeRegister("r"+reg,0);
     for(String flag:new String[]{"CY","ZR","NG","OV"})if(currentProgram.getRegister(flag)!=null)e.writeRegister(flag,0);
     e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x2302ee00L),new byte[512]);e.writeMemory(toAddr(0xe000e208L),nvic);e.writeMemory(toAddr(0x5302e040L),clock);
     long target=op==0?(mouse?0x23022508L:0x2302455cL):op==1?(mouse?0x23021c6cL:0x230214bcL):0x2302552cL;
     e.writeRegister("r0",peer);e.writeRegister("r1",Integer.toUnsignedLong(arg));e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),target);
     int steps=0;
     while(e.getExecutionAddress().getOffset()!=0x2302df00L && steps<10000){if(!e.step(monitor))throw new Exception("case"+test+" "+e.getLastError());steps++;}
     if(steps>=10000)throw new Exception("Bound "+test);
     out.println("{\"case\":"+test+",\"side\":\""+getScriptArgs()[2]+"\",\"op\":"+op+",\"peer\":"+peer+",\"arg\":"+Integer.toUnsignedLong(arg)+",\"ram_before_z\":\""+pack(ram)+"\",\"ram_after_z\":\""+pack(e.readMemory(toAddr(0x23000000L),65536))+"\",\"clock_before\":\""+hex(clock)+"\",\"clock_after\":\""+hex(e.readMemory(toAddr(0x5302e040L),8))+"\",\"nvic_before\":\""+hex(nvic)+"\",\"nvic_after\":\""+hex(e.readMemory(toAddr(0xe000e208L),4))+"\",\"steps\":"+steps+"}");
    }finally{e.dispose();}
   }
  }
  println("ORIGINAL_CONTROL_CASES=448 SIDE="+getScriptArgs()[2]);
 }
}
