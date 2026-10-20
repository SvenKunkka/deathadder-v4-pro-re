import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverInitialization extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random random=new Random(0x1202206cL);
 String[]names={"ram","radio","timer","nvic","dppi","rtc","clock0","clock1","clock2","deviceid"};
 long[]addresses={0x23000000L,0x5302c000L,0x53028000L,0xe000e000L,0x53022000L,0x5f99c000L,0x5300e000L,0x5301e000L,0x5302e000L,0x0fffe010L};
 try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){for(int id=0;id<3072;id++){
 int op=id/1024,v=id%1024;byte[][]windows=new byte[names.length][];byte[]pattern=new byte[256];random.nextBytes(pattern);
 for(int j=0;j<windows.length;j++){windows[j]=new byte[j==0?65536:j==9?8:4096];for(int k=0;k<windows[j].length;k++)windows[j][k]=pattern[(k+j*7)%256];}
 byte[]ram=windows[0];System.arraycopy(image,0x1c854,ram,0,0x1e08);w32(ram,0x230,Integer.toUnsignedLong(random.nextInt()));w32(ram,0x234,Integer.toUnsignedLong(random.nextInt()));
 w32(windows[4],0x500,v%2==0?0:0xff);w32(windows[5],0x774,new long[]{0,1,0xfffff,0x3fffffff}[v%4]);w32(windows[5],0x770,new long[]{0,1,0xffffffffL,0x80000000L,Integer.toUnsignedLong(random.nextInt())}[v%5]);
 long identity=Integer.toUnsignedLong(random.nextInt()),cap=Integer.toUnsignedLong(random.nextInt());w32(ram,0x7000,identity);w32(ram,0x7004,cap);ram[0x7020]=(byte)v;
 long event=new long[]{1,8,9,0,2,3,5,6,7,11,39,42,45,0xffffffffL}[v%14];
 byte[]stack=new byte[512];random.nextBytes(stack);long sp=op==2?0x2302ef00L:0x2302f000L;int phy=op==1?(v&255):(stack[op==2?0xdc:0x1dc]&255);
 if(op==2){w32(stack,0x114,event);w32(stack,0x118,identity);}
 final long initial=new long[]{0,0x20,0x40,0x80}[v%4];
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(false);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);

 for(int j=0;j<windows.length;j++)e.writeMemory(toAddr(addresses[j]),windows[j]);e.writeMemory(toAddr(0x2302ee00L),stack);
 e.writeRegister("r0",0x23007000L);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),sp);
 if(op==2){e.writeRegister("r4",0x23001bb4L);e.writeRegister("r5",0x23006590L);e.writeRegister("r6",1000000);e.writeRegister("r7",0);}
 e.writeRegister(e.getPCRegister(),new long[]{0x2302206cL,0x23020c44L,0x23024e56L}[op]);
 int steps=0;while(e.getExecutionAddress().getOffset()!=0x2302df00L&&e.getExecutionAddress().getOffset()!=0x23024e46L&&steps<100000){if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=100000)throw new Exception("bound"+id);
 StringBuilder row=new StringBuilder("{\"case\":"+id+",\"op\":"+op+",\"identity\":"+identity+",\"capability\":"+cap+",\"phy\":"+phy+",\"event\":"+event+",\"initial_priority\":"+initial+",\"final_priority\":"+cpu.getBasePriority()+",\"steps\":"+steps+",\"end_pc\":"+e.getExecutionAddress().getOffset());
 for(int j=0;j<windows.length;j++){row.append(",\"").append(names[j]).append("_before\":\"").append(zip(windows[j])).append("\",\"").append(names[j]).append("_after\":\"").append(zip(e.readMemory(toAddr(addresses[j]),windows[j].length))).append("\"");}row.append("}");out.println(row);
 }finally{e.dispose();}
 }}println("RECEIVER_INITIALIZATION_CASES=3072");
 }
}
