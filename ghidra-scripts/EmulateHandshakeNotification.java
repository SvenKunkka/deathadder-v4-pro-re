// Software-only execution of receiver handshake including actual queue code.
import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateHandshakeNotification extends GhidraScript {
 String hex(byte[] x){return HexFormat.of().formatHex(x);}
 long u32(EmulatorHelper e,long a){byte[] b=e.readMemory(toAddr(a),4);return (b[0]&255L)|((b[1]&255L)<<8)|((b[2]&255L)<<16)|((b[3]&255L)<<24);}
 public void run() throws Exception {
  byte[] original=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
  String sha=hex(java.security.MessageDigest.getInstance("SHA-256").digest(original));
  if(!sha.equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162"))throw new Exception("Image mismatch");
  if(!Arrays.equals(original,getBytes(toAddr(0x0e054000L),original.length)))throw new Exception("Flash mismatch");
  if(!Arrays.equals(Arrays.copyOfRange(original,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("RAM mismatch");
  println("ORIGINAL_IMAGE_AND_CODE_VERIFIED="+sha);
  Random random=new Random(12025580);
  try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
   for(int test=0;test<96;test++){
    int slot=test&1,count=test%6,writeIndex=(test/6)%5,readIndex=(writeIndex-count+5)%5;
    int pending=test%7==0?0:1,otherPending=(test/2)%2;
    long stride=slot*0xf84L,base=Integer.toUnsignedLong(random.nextInt()),rxMask=Integer.toUnsignedLong(random.nextInt());
    byte[] stack=new byte[512],before=new byte[224],buffer=new byte[180];
    random.nextBytes(stack);random.nextBytes(before);random.nextBytes(buffer);
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
     final long initialPriority=new long[]{0,0x20,0x80}[(test/6)%3];
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
     emu.writeRegister("r0",slot);emu.writeRegister("r1",0x2302e000L);
     emu.writeRegister("lr",0x23027f01L);emu.writeRegister(emu.getStackPointerRegister(),0x2302f000L);
     emu.writeMemory(toAddr(0x2302ee00L),stack);
     emu.writeMemory(toAddr(0x230033e8L+stride),before);
     emu.writeMemoryValue(toAddr(0x230033fcL),4,slot==0?pending:otherPending);
     emu.writeMemoryValue(toAddr(0x23004380L),4,slot==1?pending:otherPending);
     emu.writeMemoryValue(toAddr(0x230034b0L+stride),2,3);
     emu.writeMemoryValue(toAddr(0x23003244L),4,base);
     emu.writeMemoryValue(toAddr(0x5302ce40L),4,rxMask);
     byte[] packet=new byte[12];packet[0]=11;packet[3]=0x16;
     emu.writeMemory(toAddr(0x2302e000L),packet);
     // Empty waiter list; ring occupancy covers empty, partial and full.
     long[] queue={0x23001b8cL,0x23001b8cL,36,5,0x23015760L,0x23015814L,
                   0x23015760L+readIndex*36,0x23015760L+writeIndex*36,count,0};
     for(int i=0;i<queue.length;i++)emu.writeMemoryValue(toAddr(0x23001b8cL+i*4),4,queue[i]);
     emu.writeMemory(toAddr(0x23015760L),buffer);
     // No reschedule required in the no-waiter fixture, including purge.
     emu.writeMemoryValue(toAddr(0x23007170L),4,0);
     emu.writeMemoryValue(toAddr(0x2300717cL),4,0);
     before=emu.readMemory(toAddr(0x230033e8L+stride),224);
     String queueBefore=hex(emu.readMemory(toAddr(0x23001b8cL),40));
     emu.writeRegister(emu.getPCRegister(),0x230223f0L);int steps=0;
     while(emu.getExecutionAddress().getOffset()!=0x23027f00L && steps<4000){
      if(!emu.step(monitor))throw new Exception("case "+test+" at "+emu.getExecutionAddress()+": "+emu.getLastError());steps++;
     }
     if(steps>=4000)throw new Exception("Step bound "+test);
     if(cpu.getBasePriority()!=initialPriority)throw new Exception("BASEPRI not restored");
     out.println("{\"case\":"+test+",\"slot\":"+slot+",\"pending\":"+pending+",\"other_pending\":"+otherPending+",\"base\":"+base+",\"rx_mask_before\":"+rxMask+",\"rx_mask_after\":"+u32(emu,0x5302ce40L)+",\"before\":\""+hex(before)+"\",\"after\":\""+hex(emu.readMemory(toAddr(0x230033e8L+stride),224))+"\",\"queue_before\":\""+queueBefore+"\",\"queue_after\":\""+hex(emu.readMemory(toAddr(0x23001b8cL),40))+"\",\"buffer_before\":\""+hex(buffer)+"\",\"buffer_after\":\""+hex(emu.readMemory(toAddr(0x23015760L),180))+"\",\"opaque_tail\":\""+hex(Arrays.copyOfRange(stack,512-92,512-72))+"\",\"return\":"+emu.readRegister("r0")+",\"steps\":"+steps+",\"cpu_support_calls\":"+Arrays.toString(cpuCalls)+",\"basepri_final\":"+cpu.getBasePriority()+",\"basepri_initial\":"+initialPriority+"}");
    }finally{emu.dispose();}
   }
  }
  println("NOTIFICATION_ORIGINAL_CASES=96");
 }
}
