import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateMouseInitialization extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long v){for(int j=0;j<4;j++)b[a+j]=(byte)(v>>>(8*j));}void w16(byte[]b,int a,long v){b[a]=(byte)v;b[a+1]=(byte)(v>>>8);}
 public void run()throws Exception{
 String[]sa=getScriptArgs();byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(sa[1]));
 if(image.length!=201044||!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48")||!Arrays.equals(image,getBytes(toAddr(0xe06c000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0xc6b0),getBytes(toAddr(0x23020000L),0xc6b0)))throw new Exception("image/mapping");
 int start=Integer.parseInt(sa[2]),end=Integer.parseInt(sa[3]);String[]names={"ram","radio","timer","nvic","dppi","clock"};long[]bases={0x23000000L,0x5302c000L,0x53028000L,0xe000e000L,0x53022000L,0x5302e000L};
 try(PrintWriter out=new PrintWriter(new FileOutputStream(sa[0],start>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int cid=start;cid<end;cid++){
 int family=cid<3072?cid/1024:3+(cid-3072)/256,v=cid<3072?cid%1024:(cid-3072)%256;
 Random rng=new Random(0x12022e28L+cid*7919L);byte[]pat=new byte[256];rng.nextBytes(pat);byte[][]windows=new byte[6][];
 for(int j=0;j<6;j++){windows[j]=new byte[j==0?131072:4096];for(int i=0;i<windows[j].length;i++)windows[j][i]=pat[(i+j*31)%256];}
 byte[]ram=windows[0];ram[0x76ee]=(byte)new int[]{0,1,2,255}[(v/10)%4];
 long[]edge={0,1,2,4,8,16,32,64,65,65535};
 long identity=new long[]{0,0xffffffffL,0x12345678L,0x87654321L,0x80000000L,(v&15),Integer.toUnsignedLong(rng.nextInt()),Integer.toUnsignedLong(rng.nextInt())}[v%8];
 long capability=family==1?7:new long[]{0,1,7,0xffffL,0x10000L,0xffffffffL,0x80000007L,Integer.toUnsignedLong(rng.nextInt())}[(v/8)%8];
 long p2=(Integer.toUnsignedLong(rng.nextInt())&0xffff0000L)|edge[(v/3)%10],p3=(Integer.toUnsignedLong(rng.nextInt())&0xffff0000L)|edge[(v/7)%10],rate=(Integer.toUnsignedLong(rng.nextInt())&0xffff0000L)|edge[v%10];
 int phy=v&255,peer=new int[]{0,1,2,3,7,15,31}[v%7];
 w32(ram,0x8000,identity);w32(ram,0x8004,capability);w16(ram,0x8008,p2);w16(ram,0x800a,p3);w16(ram,0x800c,rate);
 if(family==2){w32(ram,0x8004,identity);ram[0x8020]=(byte)phy;}
 for(int j=1;j<6;j++){int[]offsets=j==1?new int[]{0x200,0x510,0x514,0x304,0x308}:j==2?new int[]{0x504,0x508,0x510,0x304,0x308}:j==3?new int[]{0x104,0x108,0x184,0x188,0x284,0x288}:j==4?new int[]{0x500,0x504,0x508}:new int[]{0x40,0x44};for(int k=0;k<offsets.length;k++)w32(windows[j],offsets[k],new long[]{0,0xffffffffL,0xa5a5a5a5L,Integer.toUnsignedLong(rng.nextInt())}[(v+k)%4]);}
 long entry=new long[]{0x23022e28L,0x230259a4L,0x230218ecL,0x230225ccL,0x23021800L,0x23021528L}[family];
 long[]args={family==1?identity:family==5?peer:0x23008000L,family==1?p2:Integer.toUnsignedLong(rng.nextInt()),family==1?p3:Integer.toUnsignedLong(rng.nextInt()),family==1?rate:Integer.toUnsignedLong(rng.nextInt()),Integer.toUnsignedLong(rng.nextInt())};
 final long initial=new long[]{0,32,64,128}[v%4];final int exception=v%5==0?0:60;byte[]stack=new byte[512];rng.nextBytes(stack);long sp=0x2302f000L;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.registerCallOtherCallback("DataMemoryBarrier",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String flag:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(flag)!=null)e.writeRegister(flag,0);
 for(int i=0;i<6;i++)e.writeMemory(toAddr(bases[i]),windows[i]);e.writeMemory(toAddr(sp-512),stack);e.writeMemoryValue(toAddr(sp),4,args[4]);
 for(int i=0;i<4;i++)e.writeRegister("r"+i,args[i]);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),sp);e.writeRegister(e.getPCRegister(),entry);
 int steps=0,kind=0,mask=0;long boundary=0;long[]bargs=new long[4];
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<200000){long pc=e.getExecutionAddress().getOffset();
  if(pc==0xe089d4cL){kind=1;boundary=pc;mask=1;bargs[0]=e.readRegister("r0").longValue()&0xffffffffL;break;}
  if(!((pc>=0x23020000L&&pc<0x2302c6b0L)||(pc>=0xe06c000L&&pc<0xe06c000L+image.length))){kind=1;boundary=pc;mask=15;for(int i=0;i<4;i++)bargs[i]=e.readRegister("r"+i).longValue()&0xffffffffL;break;}
  if(!e.step(monitor))throw new Exception("case"+cid+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;
 }
 if(steps>=200000)throw new Exception("bound"+cid+" "+e.getExecutionAddress());
 StringBuilder row=new StringBuilder("{\"case\":"+cid+",\"family\":"+family+",\"entry\":"+entry+",\"args\":"+Arrays.toString(args)+",\"params\":"+Arrays.toString(new long[]{identity,capability,p2,p3,rate})+",\"phy\":"+(family<2?4:phy)+",\"peer\":"+peer+",\"stack_before\":\""+hex(stack)+"\",\"initial_sp\":"+sp+",\"initial_priority\":"+initial+",\"exception\":"+exception+",\"final_priority\":"+cpu.getBasePriority()+",\"kind\":"+kind+",\"boundary\":"+boundary+",\"boundary_args\":"+Arrays.toString(bargs)+",\"arg_mask\":"+mask+",\"result_valid\":false,\"result\":0,\"steps\":"+steps+",\"end_pc\":"+e.getExecutionAddress().getOffset());
 for(int i=0;i<6;i++)row.append(",\"").append(names[i]).append("_before\":\"").append(zip(windows[i])).append("\",\"").append(names[i]).append("_after\":\"").append(zip(e.readMemory(toAddr(bases[i]),windows[i].length))).append("\"");row.append('}');out.println(row);
 }finally{e.dispose();}
 }}println("MOUSE_INITIALIZATION_RANGE="+start+":"+end);
 }
}
