import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;import java.util.zip.GZIPOutputStream;
public class EmulateDongleBusinessConsumer extends GhidraScript{
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(GZIPOutputStream z=new GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long v){for(int i=0;i<4;i++)b[a+i]=(byte)(v>>(8*i));}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
 if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162"))throw new Exception("hash");
 if(!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("mapping");
 Random rng=new Random(12020250);int id=0;
 try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
 for(int op=0;op<5;op++)for(int t=0;t<new int[]{432,576,128,1536,64}[op];t++){
  byte[]ram=new byte[65536];Arrays.fill(ram,(byte)0xa5);
  byte[]mapping={0,0,2,0,1,0};System.arraycopy(mapping,0,ram,0x48c,6);
  byte[]random=new byte[192];rng.nextBytes(random);System.arraycopy(random,0,ram,0x2c80,160);System.arraycopy(random,0,ram,0x71b0,32);
  int cls=t%6,peer=t%2,wr=new int[]{0,1,2,3,4,255}[(t/6)%6],rd=(t/36)%4,enable=new int[]{0,1,255}[(t/144)%3];
  if(op!=0){wr=new int[]{0,3,4,255}[(t/6)%4];rd=(t/24)%4;enable=new int[]{0,1,255}[(t/96)%3];}
  for(int i=0;i<3;i++){ram[0x6838+i]=(byte)wr;ram[0x6834+i]=(byte)rd;ram[0x2cb4+i]=(byte)((t+i)%5);}
  ram[0x71e4]=(byte)enable;ram[0x2c82]=1;ram[0x2c83]=0;ram[0x2c88]=(byte)(t%3);ram[0x71e3]=(byte)((t/4)%2);ram[0x71e6]=(byte)((t/8)%4);w32(ram,0x690c,0x23006910L);
  byte[]input=new byte[128];rng.nextBytes(input);int len=cls==4?16:8,opcode=0,value=0;
  if(op==0)len=new int[]{0,8,16}[(t/6)%3];
  if(op==1){
   if(cls==3){input[0]=(byte)(t%12<6?0xb1:0xb0);input[5]=(byte)new int[]{0,1,2,4,64,128,255}[(t/6)%7];input[6]=(byte)((t/6)%7);input[7]=(byte)new int[]{0,15,16,127,254,255}[(t/6)%6];}
   if(cls==4){input[1]=(byte)(t%12<6?0x31:0x30);input[2]=(byte)new int[]{0,15,16,127,254,255}[(t/6)%6];}
   if(cls==5){len=2+(t/6)%89;input[0]=(byte)(t%12<6?0x5a:0x59);}
   if(t>=288){ram[0x2c82]=(byte)new int[]{0,2,1}[(t/6)%3];ram[0x2c83]=(byte)((t/18)%2);if((t/6)%2==0)Arrays.fill(input,(byte)0);else if(cls==4)input[0]=1;}
  }
  if(op==2){input[0]=(byte)new int[]{0xa4,0xab,0xac,0xb1}[(t/2)%4];}
  if(op==3){opcode=new int[]{0xe0,0xe1,0xe2,0xe3,0xff,0xe4}[t/256];value=t%256;}
  int resumeResult=new int[]{0,-1,-13,-134}[t%4];
  EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
  try{
   e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int k=0;k<=12;k++)e.writeRegister("r"+k,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
   e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x2302e000L),input);e.writeMemory(toAddr(0x2302ee00L),new byte[512]);
   e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);
   e.writeRegister("r0",op==2?peer:op==3?opcode:cls);e.writeRegister("r1",op==3?value:0x2302e000L);e.writeRegister("r2",len);
   long entry=new long[]{0x230268b0L,0x23020250L,0x23024c88L,0x23025b40L,0x23026af0L}[op];
   if(op==4){
    // Isolated post-driver continuation, synthetic ABI frame. NOT driver execution.
    e.writeRegister("r0",Integer.toUnsignedLong(resumeResult));e.writeRegister("r4",0x230071e3L);e.writeRegister(e.getStackPointerRegister(),0x2302efc0L);
    e.writeMemoryValue(toAddr(0x2302efc4L),4,0x2302027dL);e.writeMemoryValue(toAddr(0x2302efdcL),4,0x2302df01L);
   }
   e.writeRegister(e.getPCRegister(),entry);int steps=0;boolean boundary=false;
   while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<20000){
    if(e.getExecutionAddress().getOffset()==0x0e0622bcL){boundary=true;break;}
    if(!e.step(monitor))throw new Exception("case"+id+" op"+op+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;
   }
   if(steps>=20000)throw new Exception("bound"+id);
   out.println("{\"case\":"+id+",\"op\":"+op+",\"class\":"+cls+",\"peer\":"+peer+",\"length\":"+len+",\"opcode\":"+opcode+",\"value\":"+value+",\"resume_result\":"+resumeResult+",\"before_gzip\":\""+zip(ram)+"\",\"after_gzip\":\""+zip(e.readMemory(toAddr(0x23000000L),65536))+"\",\"input\":\""+hex(input)+"\",\"input_after\":\""+hex(e.readMemory(toAddr(0x2302e000L),128))+"\",\"boundary\":"+boundary+",\"r0\":"+e.readRegister("r0")+",\"steps\":"+steps+"}");id++;
  }finally{e.dispose();}
 }
 }println("DONGLE_CONSUMER_ORIGINAL_CASES="+id);
 }
}
