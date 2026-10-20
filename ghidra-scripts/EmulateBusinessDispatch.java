// Original reassembly/format/decrypt instructions, paused BEFORE downstream
// work-submit/management/consumer. No instruction or function substitutions.
import ghidra.app.script.GhidraScript;
import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateBusinessDispatch extends GhidraScript {
 String hex(byte[] b){return HexFormat.of().formatHex(b);}
 int u(byte b){return b&255;}
 public void run() throws Exception {
  boolean mouse=false;
  long flash=mouse?0x0e06c000L:0x0e054000L,entry=0x2302455cL;
  long bank=mouse?0x23006850L:0x23006278L;
  int size=mouse?0xc6b0:0x7270,table=mouse?0x2c904:0x1ba74;
  String expected=mouse?"c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48":"f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162";
  byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
  if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals(expected))throw new Exception("Hash mismatch");
  if(!Arrays.equals(image,getBytes(toAddr(flash),image.length)) || !Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+size),getBytes(toAddr(0x23020000L),size)))throw new Exception("Mapping mismatch");
  println("VERIFIED_IMAGE="+expected);Random random=new Random(120245);
  try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
   for(int test=0;test<640;test++){
    int cls=test%5+1,peer=(test/5)%2,seq=(test/10)%8;
    int[] lengths={0,1,2,3,8,31,127,128,255,9};
    byte[] before=new byte[512],motion=new byte[6],counters=new byte[4];
    random.nextBytes(before);random.nextBytes(motion);random.nextBytes(counters);
    before[0x114]=(byte)lengths[(test/10)%lengths.length];
    before[0x116]=(byte)((cls<<3)|seq|(((test/20)%4)<<6));
    before[0xb7+cls]=(byte)(((test/40)%2==0)?seq:(seq+1)%8);
    before[0x9d]=(byte)((test/5)%3);before[0xa6]=(byte)((test/15)%3);
    if(test%17==0)Arrays.fill(counters,(byte)255);
    long context=0x230033e8L+peer*0xf84L;
    EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
    try{
     e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);
     for(int reg=0;reg<=12;reg++)e.writeRegister("r"+reg,0);
     for(String flag:new String[]{"CY","ZR","NG","OV"})if(currentProgram.getRegister(flag)!=null)e.writeRegister(flag,0);
     e.writeRegister("r0",peer);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);
     e.writeMemory(toAddr(0x2302ee00L),new byte[512]);e.writeMemory(toAddr(context),before);
     e.writeMemory(toAddr(0x230030a2L),motion);e.writeMemory(toAddr(0x230033dcL),counters);
     e.writeRegister(e.getPCRegister(),entry);int steps=0,forward=0,len=0,metadata=0,forwardClass=0,forwardPeer=-1;
     byte[] payload=new byte[0];long stopped=0;
     while(steps<5000){
      long pc=e.getExecutionAddress().getOffset();stopped=pc;
      if(pc==0x2302df00L)break;
      if(pc==0x230254a0L){
       forward=1;forwardPeer=e.readRegister("r0").intValue();forwardClass=e.readRegister("r1").intValue();
       len=e.readRegister("r3").intValue()&255;
       payload=e.readMemory(toAddr(e.readRegister("r2").longValue()),len);
       metadata=u(e.readMemory(toAddr(e.readRegister(e.getStackPointerRegister()).longValue()),1)[0]);break;
      }
      if(!e.step(monitor))throw new Exception("case"+test+" "+e.getLastError());steps++;
     }
     if(steps>=5000)throw new Exception("Bound "+test);
     out.println("{\"case\":"+test+",\"peer\":"+peer+",\"before\":\""+hex(before)+"\",\"motion_before\":\""+hex(motion)+"\",\"counters_before\":\""+hex(counters)+"\",\"after\":\""+hex(e.readMemory(toAddr(context),512))+"\",\"motion_after\":\""+hex(e.readMemory(toAddr(0x230030a2L),6))+"\",\"counters_after\":\""+hex(e.readMemory(toAddr(0x230033dcL),4))+"\",\"forward\":"+forward+",\"forward_peer\":"+forwardPeer+",\"class\":"+forwardClass+",\"length\":"+len+",\"metadata\":"+metadata+",\"payload\":\""+hex(payload)+"\",\"stop\":\""+Long.toHexString(stopped)+"\",\"steps\":"+steps+"}");
    }finally{e.dispose();}
   }
  }
  println("ORIGINAL_DISPATCH_CASES=640");
 }
}
