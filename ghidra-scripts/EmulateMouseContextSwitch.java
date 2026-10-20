import ghidra.app.script.GhidraScript;
import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateMouseContextSwitch extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}
 String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}
 String state(EmulatorHelper e,ghidra.program.emulation.ArmCpuState c,long lim){long[]v=new long[24];for(int i=0;i<13;i++)v[i]=e.readRegister("r"+i).longValue()&0xffffffffL;v[13]=e.readRegister(e.getStackPointerRegister()).longValue()&0xffffffffL;v[14]=e.readRegister("lr").longValue()&0xffffffffL;v[15]=e.getExecutionAddress().getOffset();v[16]=c.getProcessStackPointer();v[17]=lim;v[18]=c.getBasePriority();int k=19;for(String f:new String[]{"CY","ZR","NG","OV","Q"})v[k++]=e.readRegister(f).longValue();return Arrays.toString(v);}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48")||!Arrays.equals(image,getBytes(toAddr(0xe06c000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0xc6b0),getBytes(toAddr(0x23020000L),0xc6b0)))throw new Exception("image/mapping");
 Random random=new Random(0x12089dccL);
 try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){for(int id=0;id<2048;id++){
 int op=id/512,v=id%512;byte[]ram=new byte[65536],nvic=new byte[4096],scratch=new byte[32],pattern=new byte[256];random.nextBytes(pattern);for(int i=0;i<ram.length;i++)ram[i]=pattern[i%256];for(int i=0;i<nvic.length;i++)nvic[i]=pattern[(i+37)%256];random.nextBytes(scratch);
 int current=new int[]{0x5200,0x5400,0x5600}[v%3],next=v%4==0?current:new int[]{0x5600,0x5200,0x5400}[v%3];w32(ram,0x7654,0x23000000L+current);w32(ram,0x7664,0x23000000L+next);
 for(int t:new int[]{0x5200,0x5400,0x5600}){for(int j=0;j<8;j++)w32(ram,t+0x30+4*j,Integer.toUnsignedLong(random.nextInt()));w32(ram,t+0x50,0x23008000L+(t-0x5200)*8+v*4);w32(ram,t+0x74,0x23007000L+(t-0x5200)*8);w32(ram,t+0x84,Integer.toUnsignedLong(random.nextInt()));w32(ram,t+0x88,new long[]{0,16,32,128,255}[(v+t)%5]);w32(ram,t+0x8c,Integer.toUnsignedLong(random.nextInt()));}
 w32(nvic,0xd04,new long[]{0,0x10000000L,0x08000000L,0xffffffffL,Integer.toUnsignedLong(random.nextInt())}[v%5]);
 long[]psplim={0x23004000L+v*8};final long initialPriority=new long[]{0,16,32,128,255}[v%5];long psp=0x2300c000L+v*8;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initialPriority);cpu.setPrivileged(true);cpu.setThreadMode(op!=2);cpu.setProcessStackPointer(psp);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});
 // Ghidra has native shared PSP getter/setter, but no PSPLIM state userop.
 // Model only the literal MSR target assignment, not protection or faults.
 e.registerCallOtherCallback("setProcStackPointerLimit",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){psplim[0]=e.getEmulator().getMemState().getValue(p.getInput(1))&0xffffffffL;return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int k=0;k<13;k++)e.writeRegister("r"+k,Integer.toUnsignedLong(random.nextInt()));int fl=0;for(String f:new String[]{"CY","ZR","NG","OV","Q"})e.writeRegister(f,(v>>(fl++))&1);
 if(op==0)e.writeRegister("r0",new long[]{0,16,32,128,255}[(v/5)%5]);if(op==3)e.writeRegister("r0",0x23000000L+next);
 e.writeRegister("lr",op==2?new long[]{0xfffffff9L,0xfffffffdL,0xffffffe9L,0xffffffedL}[v%4]:0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0xe000e000L),nvic);e.writeMemory(toAddr(0x2302efe0L),scratch);e.writeRegister(e.getPCRegister(),new long[]{0xe089d4cL,0xe089d84L,0xe089dccL,0xe089f3cL}[op]);String before=state(e,cpu,psplim[0]);
 int steps=0;long stop=op==2?0xe089e06L:0x2302df00L;while(e.getExecutionAddress().getOffset()!=stop&&steps<256){if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=256)throw new Exception("step bound "+id);
 out.println("{\"case\":"+id+",\"op\":"+op+",\"before_gzip\":\""+zip(ram)+"\",\"after_gzip\":\""+zip(e.readMemory(toAddr(0x23000000L),ram.length))+"\",\"nvic_before\":\""+zip(nvic)+"\",\"nvic_after\":\""+zip(e.readMemory(toAddr(0xe000e000L),nvic.length))+"\",\"scratch_before\":\""+hex(scratch)+"\",\"scratch_after\":\""+hex(e.readMemory(toAddr(0x2302efe0L),32))+"\",\"cpu_before\":"+before+",\"cpu_after\":"+state(e,cpu,psplim[0])+",\"steps\":"+steps+"}");
 }finally{e.dispose();}
 }}println("MOUSE_CONTEXT_SWITCH_CASES=2048");
 }
}
