import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverPeriodicService extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}void w64(byte[]b,int a,long x){w32(b,a,x);w32(b,a+4,x>>>32);}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length)))throw new Exception("image/mapping");
 Random random=new Random(0x120bde0L);int start=Integer.parseInt(getScriptArgs()[2]),end=Integer.parseInt(getScriptArgs()[3]);
 try(PrintWriter out=new PrintWriter(new FileOutputStream(getScriptArgs()[0],start>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int id=0;id<1792;id++){
 int op=id/256,v=id%256;String[]names={"ram","rtc","service"};long[]addresses={0x23000000L,0x5f99c000L,0x53014000L};byte[][]windows={new byte[131072],new byte[4096],new byte[4096]};byte[]pattern=new byte[256];random.nextBytes(pattern);
 for(int j=0;j<3;j++)for(int k=0;k<windows[j].length;k++)windows[j][k]=pattern[(k+j*7)%256];byte[]ram=windows[0],rtc=windows[1];System.arraycopy(image,0x1c854,ram,0,0x1e08);
 ram[0x71eb]=(byte)new int[]{0,1,2,3,255}[v%5];w32(ram,0xab4,new long[]{0,0xe080,0xe000,0xc000,0x8000,0x80,1,0x80000000L,0xffffffffL}[(v/5)%9]);w32(ram,0xab8,new long[]{0,0xe080,0x80,0x8000,0xffffffffL}[(v/3)%5]);w32(ram,0x6db0,new long[]{0,0xe080,0x80,0x8000,0xffffffffL}[(v/7)%5]);
 long channel=new long[]{7,13,14,15,0,31,32,255,263,0xfffffff4L}[(v/5)%10];w32(ram,0x2df8,channel);
 long now=new long[]{100,0xfffffffeL,0xffffffffL,0x100000000L,0xfffffffffffe0L}[(v/9)%5];w64(rtc,0x770,now);w64(ram,0x2840,now-v%3);w64(ram,0x2c78,new long[]{0,1,100,0xffffffffL,0x100000000L,0x7fffffffffffffffL,-1}[(v/11)%7]);w32(ram,0x7198,v%2);
 long duration=new long[]{0,1,100000,-1,-2,-100001,0x000fffffffffffffL,0x0010000000000000L,0x7fffffffffffffffL,0x8000000000000000L}[(v/3)%10];long deadline=new long[]{0,1,0xffffffffL,0x123456789abcdef0L,-1}[(v/2)%5];long callback=0xe05bde1L,user=0x12345678L+v;
 if(op==6){
  w32(ram,0xab4,0);w32(ram,0xab8,0xe080);w32(rtc,0x350,new long[]{0,0x80,0x8000,0xe080}[v%4]);w32(ram,0x6db0,0xe080);w32(ram,0x2df8,15);w64(rtc,0x770,100+v);w64(ram,0x2840,100);w64(ram,0x2c78,100);w32(ram,0x7198,0);w32(ram,0xb48,0x23000b48L);w32(ram,0xb4c,0x23000b48L);
  Arrays.fill(ram,0x6000,0x6090,(byte)0);w32(ram,0x7170,0x23006000L);w32(ram,0x717c,0x23006000L);w32(ram,0x7174,0x23006000L);w32(ram,0x7180,0x23007180L);w32(ram,0x7184,0x23007180L);ram[0x7178]=0;w32(ram,0x7188,0);w32(ram,0x718c,0);w32(ram,0x7194,0);w32(ram,0x958,0xe0683a1L);w32(ram,0x95c,0);ram[0x960]=7;
  for(int j=0;j<4;j++){int ch=new int[]{7,13,14,15}[j];long cb=new long[]{0xe0683a1L,0xe05bde1L,0,0xe05bde1L}[j];if(v%13==0&&j==2)cb=0x23024fd9L;w32(ram,0xabc+j*12,cb);w32(ram,0xac0+j*12,0x12345678L+j);ram[0xac4+j*12]=(byte)ch;w32(rtc,0x100+ch*4,(v+j)%3==0?0:1);w64(rtc,0x520+ch*16,100+v);}
 }
 byte[]stack=new byte[1024];random.nextBytes(stack);w32(stack,0x300,callback);w32(stack,0x304,user);final long initial=new long[]{0,0x20,0x40,0x80}[v%4];final int exception=125;
 if(id<start||id>=end)continue;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});
 e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.registerCallOtherCallback("DataMemoryBarrier",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);


 for(int j=0;j<3;j++)e.writeMemory(toAddr(addresses[j]),windows[j]);e.writeMemory(toAddr(0x2302ed00L),stack);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister("lr",0x2302df01L);
 e.writeRegister("r0",op==4?(duration&0xffffffffL):channel);e.writeRegister("r1",op==4?(duration>>>32):0);e.writeRegister("r2",deadline&0xffffffffL);e.writeRegister("r3",deadline>>>32);
 e.writeRegister(e.getPCRegister(),new long[]{0xe06841cL,0xe05be20L,0xe05bde0L,0xe05be4cL,0xe0684dcL,0xe068454L,0xe069898L}[op]);
 int steps=0;long boundary=0;long[]args=new long[5];while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<20000){long pc=e.getExecutionAddress().getOffset();if(pc==0x23024fd8L){boundary=pc;for(int k=0;k<4;k++)args[k]=e.readRegister("r"+k).longValue()&0xffffffffL;args[4]=Integer.toUnsignedLong(java.nio.ByteBuffer.wrap(e.readMemory(toAddr(e.readRegister(e.getStackPointerRegister()).longValue()),4)).order(java.nio.ByteOrder.LITTLE_ENDIAN).getInt());break;}if(!e.step(monitor))throw new Exception("case"+id+" "+e.getLastError());steps++;}if(steps>=20000)throw new Exception("bound"+id);
 StringBuilder row=new StringBuilder("{\"case\":"+id+",\"op\":"+op+",\"channel\":"+channel+",\"duration\":\""+Long.toUnsignedString(duration)+"\",\"deadline\":\""+Long.toUnsignedString(deadline)+"\",\"callback\":"+callback+",\"user\":"+user+",\"initial_priority\":"+initial+",\"final_priority\":"+cpu.getBasePriority()+",\"boundary\":"+boundary+",\"pending_args\":"+Arrays.toString(args)+",\"r0\":"+(e.readRegister("r0").longValue()&0xffffffffL)+",\"r1\":"+(e.readRegister("r1").longValue()&0xffffffffL)+",\"steps\":"+steps);
 for(int j=0;j<3;j++){row.append(",\"").append(names[j]).append("_before\":\"").append(zip(windows[j])).append("\",\"").append(names[j]).append("_after\":\"").append(zip(e.readMemory(toAddr(addresses[j]),windows[j].length))).append("\"");}row.append("}");out.println(row);
 }finally{e.dispose();}
 }}println("RECEIVER_PERIODIC_RANGE="+start+":"+end);
 }
}
