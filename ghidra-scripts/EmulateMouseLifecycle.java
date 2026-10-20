// Execute unmodified original Thumb through state17, no physical peripherals.
import ghidra.app.script.GhidraScript;
import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateMouseLifecycle extends GhidraScript {
 String hex(byte[] d){return HexFormat.of().formatHex(d);}
 public void run() throws Exception {
  byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
  String sha=hex(java.security.MessageDigest.getInstance("SHA-256").digest(image));
  if(!sha.equals("c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48"))throw new Exception("Image hash mismatch");
  if(!Arrays.equals(image,getBytes(toAddr(0x0e06c000L),image.length)))throw new Exception("Flash mismatch");
  if(!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0xc6b0),getBytes(toAddr(0x23020000L),0xc6b0)))throw new Exception("Runtime mismatch");
  println("ORIGINAL_FLASH_AND_RUNTIME_COPY_VERIFIED_SHA256="+sha);
  Random rng=new Random(120230);
  try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
   for(int test=0;test<400;test++) {
    int mode=new int[]{0,1,2,4,8,65535}[test%6],selector=(test/6)%4,rate=new int[]{1,4,8,65535}[(test/24)%4];
    int pairing=(test/96)%2,pending=(test/192)%2,event=test<384?5:4;
    byte[] ram=new byte[0x8000],radio=new byte[0x1000],timer=new byte[0x600];rng.nextBytes(ram);rng.nextBytes(radio);rng.nextBytes(timer);
    EmulatorHelper emu=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
    try{
     // Ghidra's ARM library implements setBasePriority but omits its getter.
     // Bridge the missing getter to the SAME built-in ArmCpuState instance,
     // not a separate shadow value. Reflection is confined to this emulator.
     java.lang.reflect.Field machineField=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");
     machineField.setAccessible(true);
     ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)machineField.get(emu.getEmulator());
     Object armLibrary=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();
     java.lang.reflect.Field cpuField=armLibrary.getClass().getDeclaredField("cpuState");cpuField.setAccessible(true);
     ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)cpuField.get(armLibrary);
     final long initialPriority=new long[]{0,0x20,0x80}[test%3];
     cpu.setBasePriority(initialPriority);cpu.setPrivileged(true);cpu.setThreadMode(false);
     final int[] cpuCalls={0,0};
     emu.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){
      public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw op){emu.getEmulator().getMemState().setValue(op.getOutput(),cpu.getBasePriority());cpuCalls[0]++;return true;}
     });
     emu.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){
      public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw op){emu.getEmulator().getMemState().setValue(op.getOutput(),60);cpuCalls[1]++;return true;}
     });
     emu.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);
     for(int reg=0;reg<=12;reg++)emu.writeRegister("r"+reg,0);
     for(String f:new String[]{"CY","ZR","NG","OV"})if(currentProgram.getRegister(f)!=null)emu.writeRegister(f,0);
     emu.writeRegister("r0",event);emu.writeRegister("lr",0x2302df01L);
     emu.writeRegister(emu.getStackPointerRegister(),0x2302f000L);emu.writeMemory(toAddr(0x2302ec00L),new byte[0x400]);
     emu.writeMemory(toAddr(0x23000000L),ram);emu.writeMemory(toAddr(0x53028000L),timer);emu.writeMemory(toAddr(0x5302c000L),radio);
     emu.writeMemoryValue(toAddr(0x23002a04L),4,0x17);
     emu.writeMemoryValue(toAddr(0x2300298cL),4,pairing==0?0:0xffffffffL);
     emu.writeMemoryValue(toAddr(0x23002798L),2,mode);emu.writeMemoryValue(toAddr(0x230027a2L),2,selector);emu.writeMemoryValue(toAddr(0x230029acL),2,rate);
     // Original RTOS code executes naturally: inactive timers, and either
     // pending notification or work flags taking a natural fast-return path.
     emu.writeMemoryValue(toAddr(0x23001540L),4,0);emu.writeMemoryValue(toAddr(0x23001578L),4,0);
     emu.writeMemoryValue(toAddr(0x23006b7eL),2,pending);
     emu.writeMemoryValue(toAddr(0x230067ccL),4,(test&1)==0?2:4);
     emu.writeMemoryValue(toAddr(0x5302c8a0L),4,new long[]{0x80000000L,0x58120eL,0x12345678L}[test%3]);
     String before=hex(emu.readMemory(toAddr(0x23000000L),0x8000)),rb=hex(emu.readMemory(toAddr(0x5302c000L),0x1000)),tb=hex(emu.readMemory(toAddr(0x53028000L),0x600));
     emu.writeRegister(emu.getPCRegister(),0x230227b8L);int steps=0;
     while(emu.getExecutionAddress().getOffset()!=0x2302df00L && steps<5000){
      if(!emu.step(monitor))throw new Exception("case "+test+" pc="+emu.getExecutionAddress()+": "+emu.getLastError());steps++;
     }
     if(steps>=5000)throw new Exception("Step bound "+test+" pc="+emu.getExecutionAddress());
     if(cpu.getBasePriority()!=initialPriority)throw new Exception("BASEPRI not restored");
     out.println("{\"case\":"+test+",\"event\":"+event+",\"mode\":"+mode+",\"selector\":"+selector+",\"rate\":"+rate+",\"pairing\":"+pairing+",\"pending\":"+pending+",\"before\":\""+before+"\",\"after\":\""+hex(emu.readMemory(toAddr(0x23000000L),0x8000))+"\",\"radio_before\":\""+rb+"\",\"radio_after\":\""+hex(emu.readMemory(toAddr(0x5302c000L),0x1000))+"\",\"timer_before\":\""+tb+"\",\"timer_after\":\""+hex(emu.readMemory(toAddr(0x53028000L),0x600))+"\",\"basepri_initial\":"+initialPriority+",\"basepri_final\":"+cpu.getBasePriority()+",\"steps\":"+steps+"}");
    }finally{emu.dispose();}
   }
  }
  println("MOUSE_ORIGINAL_LIFECYCLE_CASES=400");
 }
}
