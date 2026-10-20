// Original1.20 TX/ring instructions. No replacements or CPU userop patches.
import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;import java.util.zip.GZIPOutputStream;
public class EmulateBusinessTx extends GhidraScript {
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
 boolean m=getScriptArgs()[2].equals("mouse");byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
 String expected=m?"c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48":"f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162";
 if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals(expected))throw new Exception("hash");
 if(!Arrays.equals(image,getBytes(toAddr(m?0xe06c000L:0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+(m?0xc6b0:0x7270)),getBytes(toAddr(0x23020000L),m?0xc6b0:0x7270)))throw new Exception("mapping");
 Random rng=new Random(12025184);int test=0;
 try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
 for(int op=0;op<6;op++)for(int cls=0;cls<6;cls++)for(int peer=0;peer<2;peer++)for(int variant=0;variant<(op==5?12:4);variant++){
  // 0init,1free,2peek,3pop,4enqueue,5whole TX.
  byte[] ram=new byte[65536];Arrays.fill(ram,(byte)0xa5);init(ram,m,0);init(ram,m,1);
  int ctx=(m?0x2978:0x33e8)+peer*(m?0xee0:0xf84),wo=m?0x15e:0x154,ro=m?0x164:0x15a,co=m?0x16a:0x160,qo=m?0xb2:0xa7;
  int cap=ram[ctx+co+cls]&255,wr=(variant%2==0?cap-1:2),free=new int[]{0,1,cap-1,2}[variant%4];
  int len=op==4?new int[]{1,5,7,9}[variant%4]:new int[]{0,1,4,5,6,7,8,12,16,31,90,6}[variant];
  if(op!=4&&op!=5)len=6;
  if(op==5&&m&&cls==1)len=6;
  if(op==5&&m&&(cls==2||cls==4))len=new int[]{0,2,8,16,32}[variant%5];
  if(op==5&&variant>=4){int eff=m?(cls==2?8:cls==4?16:len):len+1,need=(eff+(m?5:3))/(m?6:4);free=Math.min(cap-1,Math.max(0,need+(variant%3)-1));}
  ram[ctx+wo+cls]=(byte)wr;ram[ctx+ro+cls]=(byte)((wr+free+1)%cap);
  ram[ctx+qo+cls]=(byte)new int[]{0,1,7,255}[variant%4];
  byte[] key=new byte[16];rng.nextBytes(key);System.arraycopy(key,0,ram,m?0x2600:0x3020,16);
  byte[] motion=new byte[12];rng.nextBytes(motion);System.arraycopy(motion,0,ram,0x6b60,12);
  if(op==0){for(int i=0;i<12;i++)ram[ctx+wo+i]=(byte)(0x40+i);}
  byte[] input=new byte[128];rng.nextBytes(input);int failAt=op==5&&variant>=10?11-variant:-1;
  EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
  try{
   e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);
   for(int r=0;r<=12;r++)e.writeRegister("r"+r,0);for(String f:new String[]{"CY","ZR","NG","OV"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
   e.writeRegister("r0",peer);e.writeRegister("r1",cls);e.writeRegister("r2",0x2302e000L);e.writeRegister("r3",len);
   e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);
   e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x2302e000L),input);e.writeMemory(toAddr(0x2302ee00L),new byte[520]);e.writeMemoryValue(toAddr(0x2302f000L),4,0x12ef);
   long[] entries=m?new long[]{0x23021528L,0x23021488L,0x230214e0L,0x2302145cL,0x230215acL,0x23025ab0L}:new long[]{0x2302083cL,0x23020768L,0x230207ecL,0x2302073cL,0x230208b8L,0x230251e4L};
   e.writeRegister(e.getPCRegister(),entries[op]);int steps=0,enqueueCount=0;boolean injected=false;
   while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<50000){
    if(op==5&&e.getExecutionAddress().getOffset()==entries[4]){
     if(enqueueCount==failAt){int w=e.readMemory(toAddr(0x23000000L+ctx+wo+cls),1)[0]&255;int next=(w+1)%cap;e.writeMemoryValue(toAddr(0x23000000L+ctx+ro+cls),1,next);injected=true;}enqueueCount++;
    }
    if(!e.step(monitor))throw new Exception("case"+test+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;
   }
   if(steps>=50000)throw new Exception("bound"+test);
   out.println("{\"case\":"+test+",\"mouse\":"+(m?1:0)+",\"op\":"+op+",\"class\":"+cls+",\"peer\":"+peer+",\"variant\":"+variant+",\"length\":"+len+",\"fail_at\":"+failAt+",\"injected\":"+injected+",\"enqueue_calls\":"+enqueueCount+",\"before_gzip\":\""+zip(ram)+"\",\"after_gzip\":\""+zip(e.readMemory(toAddr(0x23000000L),65536))+"\",\"input\":\""+hex(input)+"\",\"input_after\":\""+hex(e.readMemory(toAddr(0x2302e000L),128))+"\",\"r0\":"+e.readRegister("r0")+",\"steps\":"+steps+"}");test++;
  }finally{e.dispose();}
 }
 }println("BUSINESS_TX_ORIGINAL_CASES="+test);
 }
}
