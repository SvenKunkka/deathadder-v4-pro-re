import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverTimeout extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}void w64(byte[]b,int a,long x){w32(b,a,x);w32(b,a+4,x>>>32);}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random random=new Random(0x120e648L);long[]delays={0,1,9,99,0x7fffffffL,0x80000000L,0xffffffffL,0x100000000L,Long.MAX_VALUE,-1,-2,-3,-1000,Long.MIN_VALUE,0x7ffffffffffffffeL,0xfffffff000000000L};
 try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){for(int id=0;id<2048;id++){
 int op=id/1024,v=id%1024,n=(v/16)%4;byte[]ram=new byte[131072],rtc=new byte[4096],pattern=new byte[256];random.nextBytes(pattern);for(int i=0;i<ram.length;i++)ram[i]=pattern[i%256];for(int i=0;i<rtc.length;i++)rtc[i]=pattern[i%256];
 w32(ram,0xb48,n==0?0x23000b48L:0x23005000L);w32(ram,0xb4c,n==0?0x23000b48L:0x23005000L+(n-1)*32);
 long[]ds={0,1,100,1000,0x7fffffffL,0x80000000L,0x100000000L,Long.MAX_VALUE,-1,-100,Long.MIN_VALUE};
 for(int i=0;i<n;i++){int t=0x5000+i*32;w32(ram,t,i+1==n?0x23000b48L:0x23000000L+t+32);w32(ram,t+4,i==0?0x23000b48L:0x23000000L+t-32);w64(ram,t+16,ds[(v/64+i)%ds.length]);}
 int target=op==0&&n>0?0x5000+(v%n)*32:0x5100;w32(ram,0x5100,0);w32(ram,0x5104,0);
 w32(ram,0x7198,(v/128)%2);long base=new long[]{0,100,0xfffffff0L,0x100000030L,0xfffffffffffffL,0xfffffff800000000L}[v%6];long elapsed=new long[]{0,1,32,0x7fffffffL,0x80000000L,0xffffffffL,-32}[v%7];w64(ram,0x2840,base);w64(rtc,0x770,(base+elapsed)&0xfffffffffffffL);
 w64(ram,0x2c78,new long[]{0,5,0x100000000L,Long.MAX_VALUE,Long.MIN_VALUE,-3}[(v/16)%6]);ram[0x960]=(byte)new int[]{7,13,14,15,0,31,128,255}[(v/32)%8];w32(ram,0xab4,v%17==0?0xe080:0);
 long delay=delays[v%16],callback=0xe06e4c9L;final long initial=new long[]{0,0x20,0x80}[v%3];
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(false);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x5f99c000L),rtc);e.writeRegister("r0",0x23000000L+target);e.writeRegister("r1",callback);e.writeRegister("r2",delay&0xffffffffL);e.writeRegister("r3",delay>>>32);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),op==0?0xe06e768L:0xe06e648L);
 int steps=0;while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<6000){if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=6000)throw new Exception("bound"+id);
 out.println("{\"case\":"+id+",\"op\":"+op+",\"address\":"+(0x23000000L+target)+",\"callback\":"+callback+",\"delay\":\""+Long.toUnsignedString(delay)+"\",\"before_gzip\":\""+zip(ram)+"\",\"after_gzip\":\""+zip(e.readMemory(toAddr(0x23000000L),ram.length))+"\",\"rtc_before\":\""+zip(rtc)+"\",\"rtc_after\":\""+zip(e.readMemory(toAddr(0x5f99c000L),rtc.length))+"\",\"initial_priority\":"+initial+",\"final_priority\":"+cpu.getBasePriority()+",\"return\":"+e.readRegister("r0").longValue()+",\"steps\":"+steps+"}");
 }finally{e.dispose();}
 }}println("RECEIVER_TIMEOUT_CASES=2048");
 }
}
