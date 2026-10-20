import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateMouseAckLifecycle extends GhidraScript {
 String hex(byte[] b){return HexFormat.of().formatHex(b);}
 String pack(byte[] b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.DeflaterOutputStream z=new java.util.zip.DeflaterOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w16(byte[]b,int a,int x){b[a]=(byte)x;b[a+1]=(byte)(x>>>8);}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(i*8));}
 void w64(byte[]b,int a,long x){w32(b,a,x);w32(b,a+4,x>>>32);}
 public void run()throws Exception{
  byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));String expected="c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48";
  if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals(expected)||!Arrays.equals(image,getBytes(toAddr(0x0e06c000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0xc6b0),getBytes(toAddr(0x23020000L),0xc6b0)))throw new Exception("Image/mapping mismatch");
  println("VERIFIED_IMAGE="+expected);Random rng=new Random(0x12096594L);
  try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
   for(int test=1920;test<2304;test++){
    int mode=(test/6)%2+1;int op=5,shape=test%6,target=op>=3?0x15b0:0x1540,reason=rng.nextInt(),cls=test%11==0?2:3;
    byte[] ram=new byte[65536],pattern=new byte[256],radio=new byte[4096],timer=new byte[1536],rtc=new byte[4096],clock=new byte[8];rng.nextBytes(pattern);for(int i=0;i<ram.length;i++)ram[i]=pattern[i%256];rng.nextBytes(radio);rng.nextBytes(timer);rng.nextBytes(rtc);rng.nextBytes(clock);
    for(int address:new int[]{0x1540,0x15b0,0x6000,0x6040}){w32(ram,address,0);w32(ram,address+4,0);w32(ram,address+0x24,0);w32(ram,address+0x18,test%2==0?0:0x23000000L+address+0x18);}
    w32(ram,0x2a04,0x1a);w16(ram,0x2836,test%2);w16(ram,0x2a1a,3);ram[0x2ae2+3]=32;ram[0x2adc+3]=(byte)(test%32);w32(radio,0x220,1);w32(radio,0x22c,1);
    int other=target==0x1540?0x15b0:0x1540;
    int[][] shapes={new int[]{},new int[]{target},new int[]{target,other},new int[]{other,target},new int[]{0x6000,target,0x6040},new int[]{target,other,0x6000}};int[] nodes=shapes[shape];
    w32(ram,0x14f4,0x23000000L+(nodes.length==0?0x14f4:nodes[0]));w32(ram,0x14f8,0x23000000L+(nodes.length==0?0x14f4:nodes[nodes.length-1]));
    long[] delta={0,1,31,32,100,0x7fffffffL,0x80000000L,0xffffffffL,0x100000000L,-1L,0x7fffffffffffffffL,0x8000000000000000L};
    for(int i=0;i<nodes.length;i++){int t=nodes[i];w32(ram,t,0x23000000L+(i+1==nodes.length?0x14f4:nodes[i+1]));w32(ram,t+4,0x23000000L+(i==0?0x14f4:nodes[i-1]));w64(ram,t+16,delta[(test/6+i)%delta.length]);}
    w32(ram,0x7680,test%5==0?1:0);long baseline=new long[]{0,0xfffffff0L,0x100000001L,0x000fffffffffffe0L}[(test/24)%4];w64(ram,0x21c0,baseline);
    long current=baseline+new long[]{0,31,32,63,64,3200,0x100000020L}[(test/12)%7];w32(rtc,0x770,current);w32(rtc,0x774,(current>>>32)&0xfffffL);
    int[] chs={7,13,14,15,0,32,255};ram[0x1304]=(byte)chs[(test/18)%7];w32(ram,0x1458,test%7==0?0xe080:0);
    w32(ram,0x6b68,test%13==0?0:0x23025c2dL);ram[0x6b7b]=(byte)reason;ram[0x76ee]=(byte)(test%3);
    EmulatorHelper emu=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
    try{
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

     emu.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);
     for(int j=0;j<=12;j++)emu.writeRegister("r"+j,Integer.toUnsignedLong(rng.nextInt()));
     for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)emu.writeRegister(f,0);
     emu.writeMemory(toAddr(0x23000000L),ram);emu.writeMemory(toAddr(0x5302c000L),radio);emu.writeMemory(toAddr(0x53028000L),timer);emu.writeMemory(toAddr(0x5f99c000L),rtc);emu.writeMemory(toAddr(0x5302e040L),clock);emu.writeMemory(toAddr(0x2302ec00L),new byte[1024]);
     emu.writeMemoryValue(toAddr(0x2302e002L),2,cls);emu.writeMemoryValue(toAddr(0xe000e208L),4,0x12345678L);
     emu.writeRegister("r0",op<=1?0x23000000L+target:op==2?Integer.toUnsignedLong(reason):op==4?0x2302e000L:0);
     emu.writeRegister("lr",0x2302df01L);emu.writeRegister(emu.getStackPointerRegister(),0x2302f000L);emu.writeRegister(emu.getPCRegister(),mode==1?0x230236acL:0x23022fbcL);
     int steps=0;while(emu.getExecutionAddress().getOffset()!=0x2302df00L&&steps<20000){if(!emu.step(monitor))throw new Exception("case"+test+" pc"+emu.getExecutionAddress()+" "+emu.getLastError());steps++;}if(steps>=20000)throw new Exception("Bound "+test+" pc"+emu.getExecutionAddress());
     if(cpu.getBasePriority()!=initialPriority)throw new Exception("BASEPRI not restored");
     StringBuilder line=new StringBuilder("{\"mode\":"+mode+",\"nvic_after\":"+Integer.toUnsignedLong(java.nio.ByteBuffer.wrap(emu.readMemory(toAddr(0xe000e208L),4)).order(java.nio.ByteOrder.LITTLE_ENDIAN).getInt())+",\"case\":"+test+",\"op\":"+op+",\"shape\":"+shape+",\"target\":"+(0x23000000L+target)+",\"reason\":"+Integer.toUnsignedLong(reason)+",\"message_class\":"+cls+",\"original_r0\":"+emu.readRegister("r0").longValue()+",\"steps\":"+steps+",\"basepri_initial\":"+initialPriority+",\"basepri_final\":"+cpu.getBasePriority());
     String[] names={"ram","radio","timer","rtc","clock"};long[] addresses={0x23000000L,0x5302c000L,0x53028000L,0x5f99c000L,0x5302e040L};byte[][] inputs={ram,radio,timer,rtc,clock};
     for(int j=0;j<names.length;j++){line.append(",\"").append(names[j]).append("_before_z\":\"").append(pack(inputs[j])).append("\",\"").append(names[j]).append("_after_z\":\"").append(pack(emu.readMemory(toAddr(addresses[j]),inputs[j].length))).append("\"");}
     out.println(line.append("}").toString());
    }finally{emu.dispose();}
   }
  }
  println("ORIGINAL_MOUSE_ACK_LIFECYCLE_CASES=384");
 }
}
