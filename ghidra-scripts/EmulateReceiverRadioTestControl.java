import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverRadioTestControl extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}long u32(EmulatorHelper e,long a){byte[]b=e.readMemory(toAddr(a),4);return (b[0]&255L)|(b[1]&255L)<<8|(b[2]&255L)<<16|(b[3]&255L)<<24;}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random random=new Random(0x120c774L);int start=Integer.parseInt(getScriptArgs()[2]),end=Integer.parseInt(getScriptArgs()[3]);try(PrintWriter out=new PrintWriter(new FileOutputStream(getScriptArgs()[0],start>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int cid=0;cid<2048;cid++){
 int op=cid/256,v=cid%256;byte[]ram=new byte[131072],pattern=new byte[256];random.nextBytes(pattern);for(int i=0;i<ram.length;i++)ram[i]=pattern[i%256];
 for(int i=0;i<10;i++)ram[0x2d24+i]=(byte)((v+i*17)&255);ram[0x2d24]=(byte)(v%3==0?0:1+v%8);
 ram[0x71c7]=(byte)((v/2)%3);ram[0x71d1]=(byte)((v/3)%3);ram[0x71dd]=(byte)((v/5)%3);ram[0x71dc]=(byte)((v/7)%3);ram[0x71d0]=(byte)((v/11)%3);
 ram[0x71de]=(byte)((v/13)%3);ram[0x71db]=(byte)(v%8);ram[0x71d9]=(byte)((v/16)%4);ram[0x71cf]=(byte)((v/16)%4);
 ram[0x71d8]=(byte)((v/8)%2);ram[0x71da]=(byte)((v/16)%2);ram[0x71d7]=(byte)v;ram[0x71d2]=(byte)v;
 ram[0x71d4]=(byte)(v%20);ram[0x71ce]=(byte)(v%20);ram[0x71ca]=(byte)v;ram[0x71c9]=(byte)(v%9);
 if(op==3){ram[0x71dd]=(byte)((v/64)%2);ram[0x71dc]=(byte)((v/32)%2);ram[0x71d1]=(byte)((v/16)%2);ram[0x71d0]=(byte)((v/8)%2);ram[0x71c7]=(byte)((v/4)%2);ram[0x71de]=(byte)((v/2)%2);}
 if(op==5)ram[0x71de]=(byte)(v%5==0?1:0);
 long entry=new long[]{0xe05c504L,0xe05c5ecL,0xe05c6d4L,0xe05c774L,0xe05c214L,0xe05c0e8L,0xe05c200L,0xe05c0d4L}[op];
 long arg0=op<3?0x23002d24L:op==4?(v/64)%2:random.nextInt()&0xffffffffL;
 long arg1=op==4?(v/128)%2:random.nextInt()&0xffffffffL;
 final long initial=0;final int exception=0;if(cid<start||cid>=end)continue;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 e.writeMemory(toAddr(0x23000000L),ram);
 e.writeRegister("r0",arg0);e.writeRegister("r1",arg1);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),entry);
 int steps=0;long boundary=0,barg=0;boolean argValid=false;Set<Long> stops=Set.of(0x23021f88L,0xe05d028L,0xe05cd78L);
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<16000){long pc=e.getExecutionAddress().getOffset();if(stops.contains(pc)){boundary=pc;argValid=pc!=0xe05d028L;barg=argValid?e.readRegister("r0").longValue():0;break;}if(!e.step(monitor))throw new Exception("case"+cid+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=16000)throw new Exception("bound"+cid);
 StringBuilder row=new StringBuilder("{\"case\":"+cid+",\"op\":"+op+",\"entry\":"+entry+",\"arg0\":"+arg0+",\"arg1\":"+arg1+",\"boundary\":"+boundary+",\"boundary_arg0\":"+barg+",\"arg0_valid\":"+(argValid?1:0)+",\"steps\":"+steps);
 row.append(",\"ram_before\":\"").append(zip(ram)).append("\",\"ram_after\":\"").append(zip(e.readMemory(toAddr(0x23000000L),ram.length))).append("\"}");out.println(row);
 }finally{e.dispose();}
 }}println("RECEIVER_RADIO_TEST_RANGE="+start+":"+end);
 }
}
