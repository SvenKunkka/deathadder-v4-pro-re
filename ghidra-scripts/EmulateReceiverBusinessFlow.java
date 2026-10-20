import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;import java.util.zip.GZIPOutputStream;
public class EmulateReceiverBusinessFlow extends GhidraScript{
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(GZIPOutputStream z=new GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w16(byte[]b,int a,int v){b[a]=(byte)v;b[a+1]=(byte)(v>>8);}void w32(byte[]b,int a,long v){for(int i=0;i<4;i++)b[a+i]=(byte)(v>>(8*i));}
 long u32(EmulatorHelper e,long a){byte[]b=e.readMemory(toAddr(a),4);return (b[0]&255L)|(b[1]&255L)<<8|(b[2]&255L)<<16|(b[3]&255L)<<24;}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162"))throw new Exception("hash");
 if(!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("mapping");
 Random rng=new Random(12024556);int id=0;
 try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
 for(int cls=0;cls<6;cls++)for(int peer=0;peer<2;peer++)for(int v=0;v<96;v++){
  byte[]r=new byte[65536];Arrays.fill(r,(byte)0xa5);byte[]rnd=new byte[1024];rng.nextBytes(rnd);System.arraycopy(rnd,0,r,0x6200,1024);rng.nextBytes(rnd);System.arraycopy(rnd,0,r,0x2c00,1024);
  byte[]mapping={0,0,2,0,1,0};System.arraycopy(mapping,0,r,0x48c,6);int base=0x33e8+peer*0xf84;
  int wr=new int[]{0,2,3,4,255}[v%5],rd=(v/5)%4;for(int i=0;i<3;i++){r[0x6838+i]=(byte)wr;r[0x6834+i]=(byte)rd;r[0x2cb4+i]=(byte)((v+i)%5);}
  r[0x71e4]=(byte)new int[]{0,1,255}[(v/20)%3];w16(r,0x2c82,v>=64?new int[]{0,2,257}[v%3]:1);r[0x2c88]=(byte)(v%3);r[0x71e3]=(byte)((v/2)%2);r[0x71e6]=(byte)((v/4)%4);w32(r,0x690c,0x23006910L);
  int index=new int[]{0,1,3,31}[v%4],more=(v/4)%2,oldlen=(v%2==0?4:12);int size;
  if(cls==2||cls==4){size=index==0?(v%2==0?8:16):4;}
  else if(cls==3){size=new int[]{0,1,2,8}[v%4];if(v%4==1)index=0;}
  else if(cls==5){size=2+(v%12);}
  else size=6;
  r[0x6578+cls]=(byte)((v/8)%3==0?index+1:index);r[0x6580+cls]=(byte)oldlen;
  r[base+0x114]=(byte)(cls==1?8:size+3);r[base+0x115]=(byte)0xa5;r[base+0x116]=(byte)((cls<<3)|(v%7+1)|((v/16)%4<<6));r[base+0xb7+cls]=(byte)(v%9==0?v%7+1:0);
  r[base+0x69]=(byte)new int[]{0,1,127,128,254,255}[v%6];r[base+0x9d]=(byte)(v%3);r[base+0xa6]=(byte)((v/3)%2);
  byte[]payload=new byte[32];rng.nextBytes(payload);System.arraycopy(payload,0,r,base+0x117,32);
  if(cls==0){r[base+0x117]=(byte)new int[]{0x2b,0x2c,0x17,0x00}[v%4];}
  else if(cls!=1){r[base+0x117]=(byte)(index|(more<<7));
   if(cls==3){byte command=(byte)new int[]{0xa4,0xb1,0xac,0xab,0x55}[(v/4)%5];r[base+0x118]=command;r[0x6278+cls*128]=command;}
   if(cls==5){r[base+0x118]=(byte)(v%2==0?0x5a:0x59);r[0x6278+cls*128]=r[base+0x118];}
  }
  // Dedicated invalid/signed packet lengths preserve all state.
  if(v>=90)r[base+0x114]=(byte)new int[]{0,128,255}[v%3];
  EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
  try{
   e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int k=0;k<=12;k++)e.writeRegister("r"+k,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
   e.writeMemory(toAddr(0x23000000L),r);e.writeMemory(toAddr(0x2302ed00L),new byte[768]);e.writeMemoryValue(toAddr(0xe000e208L),4,0x12345678L);e.writeRegister("r0",peer);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),0x2302455cL);
   int steps=0;boolean pending=false;while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<30000){if(e.getExecutionAddress().getOffset()==0xe0622bcL){pending=true;break;}if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=30000)throw new Exception("bound"+id);
   String after=zip(e.readMemory(toAddr(0x23000000L),65536));long nvic=u32(e,0xe000e208L),device=pending?e.readRegister("r0").longValue():0;
   String continuation="";int result=new int[]{0,-1,-13,-134}[v%4],tailSteps=0;
   if(pending){
    // Explicit external-environment result. Driver is NOT executed. Real saved
    // call stack and actual continuation instructions are retained.
    long ret=e.readRegister("lr").longValue()&~1L;e.writeRegister("r0",Integer.toUnsignedLong(result));e.writeRegister(e.getPCRegister(),ret);
    while(e.getExecutionAddress().getOffset()!=0x2302df00L&&tailSteps<30000){if(!e.step(monitor))throw new Exception("tail"+id+" "+e.getLastError());tailSteps++;}if(tailSteps>=30000)throw new Exception("tailbound");continuation=zip(e.readMemory(toAddr(0x23000000L),65536));
   }
   out.println("{\"case\":"+id+",\"class\":"+cls+",\"peer\":"+peer+",\"variant\":"+v+",\"before_gzip\":\""+zip(r)+"\",\"after_gzip\":\""+after+"\",\"pending\":"+pending+",\"device\":"+device+",\"nvic_after\":"+nvic+",\"steps\":"+steps+",\"driver_result\":"+result+",\"continuation_gzip\":\""+continuation+"\",\"tail_steps\":"+tailSteps+"}");id++;
  }finally{e.dispose();}
 }
 }println("RECEIVER_BUSINESS_FLOW_CASES="+id);
 }
}
