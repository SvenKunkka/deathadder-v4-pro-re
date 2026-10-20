// Execute ONLY the pure packet producer in Ghidra's software p-code emulator.
// No device, host executable, OS service, or firmware update is invoked.
import ghidra.app.script.GhidraScript;
import ghidra.app.emulator.EmulatorHelper;
import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class EmulateHandshakeOffer extends GhidraScript {
 public void run() throws Exception {
  byte[] original=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
  String actual=java.util.HexFormat.of().formatHex(java.security.MessageDigest.getInstance("SHA-256").digest(original));
  if(!actual.equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162"))throw new Exception("Unexpected original image identity");
  if(!Arrays.equals(original,getBytes(toAddr(0x0e054000L),original.length)))throw new Exception("Loaded flash differs from original image");
  if(!Arrays.equals(Arrays.copyOfRange(original,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("Runtime code copy differs from original image");
  println("ORIGINAL_FLASH_AND_RUNTIME_COPY_VERIFIED_SHA256="+actual);
  Random random = new Random(120);
  PrintWriter out = new PrintWriter(getScriptArgs()[0],"UTF-8");
  int successful=0;
  try {
   for (int testcase=0;testcase<128;testcase++) {
    int slot=testcase&1, seq=1+(testcase%7), cap=random.nextInt(16);
    long base=Integer.toUnsignedLong(random.nextInt());
    int flag7=(testcase>>1)&1,flag6=(testcase>>2)&1,counter=random.nextInt(65536);
    long stride=slot*0xf84L, packetAddress=0x230034bcL+stride;
    // Modern p-code engine: legacy DefaultEmulator fails on ARM BL context
    // transitions in this installed Ghidra version. No opcode substitutions.
    EmulatorHelper emu=new EmulatorHelper(currentProgram){
     protected ghidra.app.emulator.Emulator newEmulator(){
      return new ghidra.app.emulator.AdaptedEmulator(this);
     }
    };
    try {
     emu.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);
     for(int reg=0;reg<=12;reg++)emu.writeRegister("r"+reg,0);
     for(String flag:new String[]{"CY","ZR","NG","OV"}) if(currentProgram.getRegister(flag)!=null)emu.writeRegister(flag,0);
     emu.writeRegister("r0",slot);
     emu.writeRegister("lr",0x23027f01L);
     emu.writeRegister(emu.getStackPointerRegister(),0x2302f000L);
     emu.writeMemory(toAddr(0x2302ee00L),new byte[0x200]);
     byte[] initial=new byte[12];Arrays.fill(initial,(byte)0xa5);
     emu.writeMemory(toAddr(packetAddress),initial);
     emu.writeMemoryValue(toAddr(0x23003244L),4,base);
     emu.writeMemoryValue(toAddr(0x23003238L),2,cap);
     emu.writeMemoryValue(toAddr(0x2300346dL+stride),1,flag7);
     emu.writeMemoryValue(toAddr(0x23003402L+stride),2,flag6);
     emu.writeMemoryValue(toAddr(0x2300348fL+stride),1,seq);
     emu.writeMemoryValue(toAddr(0x23005376L),2,counter);
     emu.writeRegister(emu.getPCRegister(),0x23022360L);
     int steps=0;
     while(emu.getExecutionAddress().getOffset()!=0x23027f00L && steps<500) {
      if(!emu.step(monitor))throw new Exception("Emulation failed: "+emu.getLastError());
      steps++;
     }
     if(steps>=500)throw new Exception("Instruction bound exceeded");
     byte[] packet=emu.readMemory(toAddr(packetAddress),12);
     StringBuilder hex=new StringBuilder();for(byte b:packet)hex.append(String.format("%02x",b&255));
     int next=emu.readMemoryByte(toAddr(0x2300348fL+stride))&255;
     out.println("{\"case\":"+testcase+",\"slot\":"+slot+",\"sequence\":"+seq+",\"base1\":"+base+",\"capabilities\":"+cap+",\"flag7\":"+flag7+",\"flag6\":"+flag6+",\"event_counter\":"+counter+",\"next_sequence\":"+next+",\"steps\":"+steps+",\"packet_hex\":\""+hex+"\"}");
     successful++;
    } finally { emu.dispose(); }
   }
  } finally { out.close(); }
  println("OFFLINE_ORIGINAL_INSTRUCTION_CASES="+successful);
 }
}
