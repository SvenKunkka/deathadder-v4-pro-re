// Original Thumb execution with inert in-memory MMIO, never physical hardware.
import ghidra.app.script.GhidraScript;
import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateMouseHandshakeExtended extends GhidraScript {
 String hex(byte[] d){return HexFormat.of().formatHex(d);}
 public void run() throws Exception {
  byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
  String sha=hex(java.security.MessageDigest.getInstance("SHA-256").digest(image));
  if(!sha.equals("c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48"))throw new Exception("Image hash mismatch");
  if(!Arrays.equals(image,getBytes(toAddr(0x0e06c000L),image.length)))throw new Exception("Flash mismatch");
  if(!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0xc6b0),getBytes(toAddr(0x23020000L),0xc6b0)))throw new Exception("Runtime mismatch");
  println("ORIGINAL_FLASH_AND_RUNTIME_COPY_VERIFIED_SHA256="+sha);
  Random rng=new Random(120229);
  try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
   for(int test=0;test<384;test++) {
    int phase=0,substate=0,selector=test%4,seq=new int[]{0,1,7,8,255}[test%5];
    int capabilities=1|rng.nextInt(16),flag7=test&1,event=5,crc=1;
    int state=test<256?0x14:0x16;
    long pairingFlag=new long[]{1,0xffffffffL,0x80000000L,0}[test%4];
    int lowIdentity=new int[]{0,1,0xffff,0x8000}[test%4];
    byte[] before=new byte[0x3e0],packet=new byte[12];rng.nextBytes(before);rng.nextBytes(packet);
    packet[0]=11;packet[1]=0;packet[3]=0x11;packet[8]=(byte)(1 | ((test/4)%2)*64 | ((test/8)%2)*128);
    if(test<256 && test%16==8)lowIdentity=0;
    if(test>=192 && test<256){switch(test%6){case 0:crc=0;break;case 1:packet[1]=0x40;break;case 2:packet[0]=10;break;case 3:packet[3]=0x55;break;case 4:event=4;break;case 5:capabilities=0;break;}}
    if(test>=256){event=test%4==0?4:5;crc=test%3;}
    long[] addresses={0x5302c100L,0x5302808cL,0x53028004L,0x5302800cL,0x53028200L,0x53028304L,0x53028308L,0x53028540L,0x53028544L,0x53028548L,0x5302854cL,0x53028550L,0x53028554L,0x53028558L,0x5302855cL,0x5302c200L,0x5302c218L,0x5302c220L,0x5302c004L};
    EmulatorHelper emu=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
    try{
     emu.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);
     for(int reg=0;reg<=12;reg++)emu.writeRegister("r"+reg,0);
     for(String f:new String[]{"CY","ZR","NG","OV"})if(currentProgram.getRegister(f)!=null)emu.writeRegister(f,0);
     emu.writeRegister("r0",event);emu.writeRegister("lr",0x2302df01L);
     emu.writeRegister(emu.getStackPointerRegister(),0x2302f000L);emu.writeMemory(toAddr(0x2302ee00L),new byte[0x200]);
     emu.writeMemory(toAddr(0x23002688L),before);
     // Registers are ordinary zeroed emulator bytes. No peripheral evolution.
     emu.writeMemory(toAddr(0x53028000L),new byte[0x600]);
     emu.writeMemory(toAddr(0x5302c000L),new byte[0x600]);
     String registersBefore="";
     for(long addr:addresses){emu.writeMemoryValue(toAddr(addr),4,Integer.toUnsignedLong(rng.nextInt()));if(!registersBefore.isEmpty())registersBefore+=",";registersBefore+="\""+Long.toHexString(addr)+"\":\""+hex(emu.readMemory(toAddr(addr),4))+"\"";}
     emu.writeMemoryValue(toAddr(0x5302c22cL),4,crc);
     emu.writeMemoryValue(toAddr(0x23002a04L),4,state);
     emu.writeMemoryValue(toAddr(0x23002a4aL),2,substate);
     emu.writeMemoryValue(toAddr(0x2300298cL),4,pairingFlag);
     emu.writeMemoryValue(toAddr(0x23002990L),2,lowIdentity);
     emu.writeMemoryValue(toAddr(0x2300279cL),2,capabilities);
     emu.writeMemoryValue(toAddr(0x230027a2L),2,selector);
     emu.writeMemoryValue(toAddr(0x23002a2aL),1,seq);
     emu.writeMemoryValue(toAddr(0x23002a08L),1,flag7);
     int channel=rng.nextInt(32);emu.writeMemoryValue(toAddr(0x230076f5L),1,channel);
     emu.writeMemory(toAddr(0x23002a56L),packet);
     before=emu.readMemory(toAddr(0x23002688L),0x3e0);
     emu.writeRegister(emu.getPCRegister(),0x230227b8L);int steps=0;
     while(emu.getExecutionAddress().getOffset()!=0x2302df00L && steps<700){
      if(!emu.step(monitor))throw new Exception("case "+test+": "+emu.getLastError());steps++;
     }
     if(steps>=700)throw new Exception("Step bound "+test);
     String after=hex(emu.readMemory(toAddr(0x23002688L),0x3e0));
     String registers="";
     for(long addr:addresses){if(!registers.isEmpty())registers+=",";registers+="\""+Long.toHexString(addr)+"\":\""+hex(emu.readMemory(toAddr(addr),4))+"\"";}
     out.println("{\"case\":"+test+",\"event\":"+event+",\"crc_ok\":"+crc+",\"channel\":"+channel+",\"before\":\""+hex(before)+"\",\"after\":\""+after+"\",\"registers_before\":{"+registersBefore+"},\"registers_after\":{"+registers+"},\"steps\":"+steps+"}");
    }finally{emu.dispose();}
   }
  }
  println("MOUSE_ORIGINAL_HANDSHAKE_EXTENDED_CASES=384");
 }
}
