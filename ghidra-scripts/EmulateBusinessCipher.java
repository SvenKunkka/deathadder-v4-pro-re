// Pure original software cipher instructions, no CPU/MMIO overrides.
import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateBusinessCipher extends GhidraScript {
 String hex(byte[] b){return HexFormat.of().formatHex(b);}
 public void run() throws Exception {
  boolean mouse=getScriptArgs()[2].equals("mouse");
  long flash=mouse?0x0e06c000L:0x0e054000L,entry=mouse?0x23020d50L:0x2302003cL;
  int size=mouse?0xc6b0:0x7270,table=mouse?0x2c904:0x1ba74;
  String expected=mouse?"c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48":"f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162";
  byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
  if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals(expected))throw new Exception("Hash mismatch");
  if(!Arrays.equals(image,getBytes(toAddr(flash),image.length)) || !Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+size),getBytes(toAddr(0x23020000L),size)))throw new Exception("Mapping mismatch");
  println("VERIFIED_IMAGE="+expected);
  Random random=new Random(1202026);
  try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
   for(int test=0;test<64;test++){
    int selector=test%16,len=((test/16)%2==0)?8:16;
    byte[] input=new byte[len];random.nextBytes(input);
    byte[] key=Arrays.copyOfRange(image,table+selector*16,table+selector*16+16);
    byte[] buffer=new byte[32];Arrays.fill(buffer,(byte)0xa5);System.arraycopy(input,0,buffer,0,len);
    EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
    try{
     e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);
     for(int reg=0;reg<=12;reg++)e.writeRegister("r"+reg,0);
     for(String flag:new String[]{"CY","ZR","NG","OV"})if(currentProgram.getRegister(flag)!=null)e.writeRegister(flag,0);
     e.writeRegister("r0",0x2302e000L);e.writeRegister("r1",len/4);e.writeRegister("r2",0x2302e040L);
     e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);
     e.writeMemory(toAddr(0x2302ee00L),new byte[512]);e.writeMemory(toAddr(0x2302e000L),buffer);e.writeMemory(toAddr(0x2302e040L),key);
     e.writeRegister(e.getPCRegister(),entry);int steps=0;
     while(e.getExecutionAddress().getOffset()!=0x2302df00L && steps<20000){if(!e.step(monitor))throw new Exception(e.getLastError());steps++;}
     if(steps>=20000)throw new Exception("Bound "+test);
     out.println("{\"case\":"+test+",\"side\":\""+getScriptArgs()[2]+"\",\"selector\":"+selector+",\"length\":"+len+",\"input\":\""+hex(input)+"\",\"key\":\""+hex(key)+"\",\"output_with_guard\":\""+hex(e.readMemory(toAddr(0x2302e000L),32))+"\",\"key_after\":\""+hex(e.readMemory(toAddr(0x2302e040L),16))+"\",\"steps\":"+steps+"}");
    }finally{e.dispose();}
   }
  }
  println("ORIGINAL_CIPHER_CASES=64 SIDE="+getScriptArgs()[2]);
 }
}
