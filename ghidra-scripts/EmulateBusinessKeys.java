// Pure original software cipher instructions, no CPU/MMIO overrides.
import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateBusinessKeys extends GhidraScript {
 String hex(byte[] b){return HexFormat.of().formatHex(b);}
 public void run() throws Exception {
  boolean mouse=getScriptArgs()[2].equals("mouse");
  long flash=mouse?0x0e06c000L:0x0e054000L,entry=mouse?0x23020e24L:0x23020108L;
  int size=mouse?0xc6b0:0x7270,table=mouse?0x2c904:0x1ba74;
  String expected=mouse?"c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48":"f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162";
  byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
  if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals(expected))throw new Exception("Hash mismatch");
  if(!Arrays.equals(image,getBytes(toAddr(flash),image.length)) || !Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+size),getBytes(toAddr(0x23020000L),size)))throw new Exception("Mapping mismatch");
  println("VERIFIED_IMAGE="+expected);Random random=new Random(12020108);
  long keyAddr=mouse?0x23002600L:0x23003020L,wrapper=mouse?0x23020e44L:0x23020128L;
  try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
   for(int test=0;test<528;test++){
    int selector=test/33,len=test%33;long identity=Integer.toUnsignedLong((random.nextInt()&~15)|selector);
    byte[] input=new byte[64],before=new byte[64],lengthBefore=new byte[4];random.nextBytes(input);random.nextBytes(before);random.nextBytes(lengthBefore);lengthBefore[0]=(byte)len;
    EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
    try{
     e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);
     for(int reg=0;reg<=12;reg++)e.writeRegister("r"+reg,0);
     for(String flag:new String[]{"CY","ZR","NG","OV"})if(currentProgram.getRegister(flag)!=null)e.writeRegister(flag,0);
     e.writeMemory(toAddr(0x2302ee00L),new byte[512]);e.writeMemory(toAddr(0x2302e000L),input);e.writeMemory(toAddr(0x2302e050L),lengthBefore);e.writeMemory(toAddr(keyAddr-16),before);
     e.writeRegister("r0",identity);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),entry);
     int steps=0;
     while(e.getExecutionAddress().getOffset()!=0x2302df00L && steps<500){if(!e.step(monitor))throw new Exception(e.getLastError());steps++;}
     if(steps>=500)throw new Exception("Install bound");
     byte[] installed=e.readMemory(toAddr(keyAddr-16),64);
     e.writeRegister("r0",0x2302e000L);e.writeRegister("r1",0x2302e050L);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),wrapper);
     int wrapSteps=0;
     while(e.getExecutionAddress().getOffset()!=0x2302df00L && wrapSteps<30000){if(!e.step(monitor))throw new Exception(e.getLastError());wrapSteps++;}
     if(wrapSteps>=30000)throw new Exception("Wrapper bound "+test);
     out.println("{\"case\":"+test+",\"side\":\""+getScriptArgs()[2]+"\",\"identity\":"+identity+",\"length\":"+len+",\"input\":\""+hex(input)+"\",\"key_region_before\":\""+hex(before)+"\",\"key_region_installed\":\""+hex(installed)+"\",\"key_region_after\":\""+hex(e.readMemory(toAddr(keyAddr-16),64))+"\",\"length_before\":\""+hex(lengthBefore)+"\",\"length_after\":\""+hex(e.readMemory(toAddr(0x2302e050L),4))+"\",\"output\":\""+hex(e.readMemory(toAddr(0x2302e000L),64))+"\",\"return\":"+e.readRegister("r0").longValue()+",\"install_steps\":"+steps+",\"wrapper_steps\":"+wrapSteps+"}");
    }finally{e.dispose();}
   }
  }
  println("ORIGINAL_KEY_WRAPPER_CASES=528 SIDE="+getScriptArgs()[2]);
 }
}
