// Unmodified mouse consumer23025e38 and real helper instructions; inert MMIO.
import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;import java.util.zip.GZIPOutputStream;
public class EmulateMouseBusinessConsumer extends GhidraScript {
 String hex(byte[] b){return HexFormat.of().formatHex(b);}
 String zip(byte[] b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(GZIPOutputStream z=new GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[] b,int a,long v){for(int i=0;i<4;i++)b[a+i]=(byte)(v>>(i*8));}
 void init(byte[] b,boolean m,int peer){
 int ctx=(m?0x2978:0x33e8)+peer*(m?0xee0:0xf84),wo=m?0x15e:0x154,co=m?0x16a:0x160,so=m?0x170:0x166,po=m?0x178:0x16c;
 int[] cap=m?new int[]{32,5,16,32,32,96}:new int[]{32,16,16,32,32,96};int[] bases=m?new int[]{0x2b08,0x2d08,0x2d58,0x2e58,0x3058,0x3258}:new int[]{0x356c,0x376c,0x386c,0x396c,0x3b6c,0x3d6c};
 Arrays.fill(b,ctx+wo,ctx+wo+12,(byte)0);
 for(int c=0;c<6;c++){b[ctx+co+c]=(byte)cap[c];b[ctx+so+c]=16;w32(b,ctx+po+4*c,0x23000000L+bases[c]+peer*(m?0xee0:0xf84));}
 }

 public void run()throws Exception{
 byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
 if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48"))throw new Exception("hash");
 if(!Arrays.equals(image,getBytes(toAddr(0xe06c000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0xc6b0),getBytes(toAddr(0x23020000L),0xc6b0)))throw new Exception("mapping");
 Random rng=new Random(1202538);
 try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
 for(int test=0;test<512;test++){
  int kind=test%8,v=test/8;byte[] ram=new byte[65536];Arrays.fill(ram,(byte)0xa5);init(ram,true,0);init(ram,true,1);
  byte[] data=new byte[256];rng.nextBytes(data);System.arraycopy(data,0,ram,0x67d0,256);
  int cls=3,n=7,cmd=0x42;
  if(kind==0||kind==1){cmd=0xac;n=v%4==0?0:3;ram[0x67d1]=(byte)(kind==0?v+1:0);ram[0x67d2]=(byte)(kind==0?v*3:0);w32(ram,0x6b88,((long)(v%7)<<16)|(v*1000&65535));}
  if(kind==2){cmd=0xa3;n=2;}
  if(kind==3){cmd=0xb1;n=v%16==0?0:7;ram[0x67d1]=(byte)((v>>3)&1);ram[0x67d4]=(byte)((v>>4)&1);ram[0x67d5]=(byte)((v>>5)&1);}
  if(kind==4){cls=5;cmd=0x5a;n=new int[]{3,4,8,89,90,91,93,128,255}[v%9];}
  if(kind==5){cmd=0x42;n=v%3==0?0:5;}
  if(kind==6){cls=new int[]{0,1,2,4,5,255}[v%6];cmd=0x43;n=4;}
  if(kind==7){cmd=0xb1;n=7;}
  ram[0x779b]=(byte)cls;ram[0x779c]=(byte)n;ram[0x67d0]=(byte)cmd;
  if(kind!=0&&kind!=1&&n>0){int sum=0;for(int i=0;i<n-1;i++)sum+=ram[0x67d0+i]&255;ram[0x67d0+n-1]=(byte)(-sum+(kind==7?1:0));}
  // Natural helper paths, not patches: no RTOS timer start or active sensor reinit.
  ram[0x7748]=(byte)(v&1);ram[0x7747]=1;ram[0x774b]=0;ram[0x774c]=0;
  ram[0x76e0]=1;ram[0x76e1]=0;ram[0x771f]=(byte)((v>>1)&1);
  ram[0x7723]=(byte)new int[]{1,4,0}[v%3];ram[0x773f]=(byte)(v&1);ram[0x779e]=(byte)((v>>2)&1);
  ram[0x4a5f]=(byte)new int[]{1,2,4,8,16,64,0,255}[v%8];ram[0x2794]=(byte)(v%2==0?0:3);ram[0x2795]=0;
  ram[0x29ac]=(byte)(v%3==0?0:8);ram[0x29ad]=0;ram[0x76ee]=(byte)(v&1);
  ram[0x7775]=(byte)((v>>1)&1);ram[0x7773]=(byte)((v>>2)&1);ram[0x7776]=(byte)(v&1);
  ram[0x7772]=(byte)new int[]{1,2,4,8}[v%4];ram[0x7774]=4;ram[0x7781]=8;
  ram[0x7796]=(byte)(v&1);ram[0x1508]=(byte)((v>>1)&1);
  for(int c:new int[]{0,3}){int free=new int[]{0,1,31}[v%3];ram[0x2978+0x15e+c]=5;ram[0x2978+0x164+c]=(byte)((5+free+1)%32);ram[0x2978+0xb2+c]=(byte)(1+v%7);}
  byte[] spim=new byte[16],dppi=new byte[72];rng.nextBytes(spim);rng.nextBytes(dppi);
  EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
  try{
   e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int r=0;r<=12;r++)e.writeRegister("r"+r,0);
   for(String f:new String[]{"CY","ZR","NG","OV"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
   e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);
   e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x2302ec00L),new byte[0x400]);
   e.writeMemory(toAddr(0x5f9c2000L),spim);e.writeMemory(toAddr(0x5302e000L),dppi);
   e.writeRegister(e.getPCRegister(),0x23025e38L);int steps=0;
   while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<20000){if(!e.step(monitor))throw new Exception("case"+test+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}
   if(steps>=20000)throw new Exception("bound"+test+" pc"+e.getExecutionAddress());
   out.println("{\"case\":"+test+",\"kind\":"+kind+",\"class\":"+cls+",\"length\":"+n+",\"before_gzip\":\""+zip(ram)+"\",\"after_gzip\":\""+zip(e.readMemory(toAddr(0x23000000L),65536))+"\",\"spim_before\":\""+hex(spim)+"\",\"spim_after\":\""+hex(e.readMemory(toAddr(0x5f9c2000L),16))+"\",\"dppi_before\":\""+hex(dppi)+"\",\"dppi_after\":\""+hex(e.readMemory(toAddr(0x5302e000L),72))+"\",\"steps\":"+steps+"}");
  }finally{e.dispose();}
 }
 }println("MOUSE_BUSINESS_CONSUMER_ORIGINAL_CASES=512");
 }
}
