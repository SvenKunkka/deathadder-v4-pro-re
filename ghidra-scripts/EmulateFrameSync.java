import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateFrameSync extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long v){for(int j=0;j<4;j++)b[a+j]=(byte)(v>>>(8*j));}void w16(byte[]b,int a,long v){b[a]=(byte)v;b[a+1]=(byte)(v>>>8);}
 public void run()throws Exception{
 String[]sa=getScriptArgs();boolean mouse=sa[2].equals("mouse");byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(sa[1]));long base=mouse?0xe06c000L:0xe054000L;int codeSize=mouse?0xc6b0:0x7270;String hash=mouse?"c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48":"f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162";
 if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals(hash)||!Arrays.equals(image,getBytes(toAddr(base),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+codeSize),getBytes(toAddr(0x23020000L),codeSize)))throw new Exception("image/mapping");
 String[]names={"ram","timer","nvic"};long[]bases={0x23000000L,mouse?0x5f9c2000L:0x53028000L,0xe000e000L};int total=mouse?304:160;
 try(PrintWriter out=new PrintWriter(sa[0],"UTF-8")){for(int cid=0;cid<total;cid++){
 Random rng=new Random(0xf5a10000L+cid*7919L+(mouse?1:2));byte[][]windows={new byte[131072],new byte[4096],new byte[4096]};byte[]pattern=new byte[256];rng.nextBytes(pattern);for(int j=0;j<3;j++)for(int i=0;i<windows[j].length;i++)windows[j][i]=pattern[(i+j*31)%256];byte[]m=windows[0],t=windows[1];
 int family=mouse?(cid<288?0:1):(cid<144?2:3);long entry=mouse?(family==0?0x2302ba74L:0x23025f48L):0x23022204L;
 if(mouse){m[0x4a5f]=(byte)(cid<256?cid:new int[]{1,2,4,8,16,32,64,255}[(cid-256)%8]);w32(t,0x510,cid<256?0:new int[]{0,1,4,9}[(cid-256)/8%4]);m[0x774b]=(byte)new int[]{0,1,2,255}[cid%4];}
 else{
  w16(m,0x3230,3);m[0x3250]=0;m[0x3256]=0;m[0x3258]=1;w32(m,0x325a,0x10000);w32(m,0x3264,0);w32(t,0x540,16000);
  if(family==2){int av=new int[]{2400,2528,2529,2559,2560,2561,2591,2592,2720}[(cid/8)%9];long cc=new long[]{1760,1761,2528,2560,2592,3359,3360,0xffffffffL}[cid%8];int count=cid/72==0?0:31;w32(m,0x3278,count);w32(m,0x3270,(long)count*av);w32(t,0x55c,cc);}
  else{int v=cid-144;w32(m,0x3278,0);w32(m,0x3270,0);w32(t,0x55c,2560);if(v<4){w16(m,0x3230,5);m[0x3250]=1;}else if(v<8){w32(m,0x325a,1);}else if(v<12){w32(m,0x325a,0x100);w32(m,0x3264,new long[]{0,31,32,0x7fffffffL}[v%4]);}else{m[0x3258]=0;}}
 }
 final long initial=32;final int exception=60;byte[]stack=new byte[512];rng.nextBytes(stack);long sp=0x2302f000L;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.registerCallOtherCallback("DataMemoryBarrier",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){return true;}});

 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String flag:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(flag)!=null)e.writeRegister(flag,0);
 for(int i=0;i<3;i++)e.writeMemory(toAddr(bases[i]),windows[i]);e.writeMemory(toAddr(sp-512),stack);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),sp);e.writeRegister(e.getPCRegister(),entry);
 int steps=0;long boundary=0;
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<10000){long pc=e.getExecutionAddress().getOffset();if(pc==0xe06d0d0L||pc==0xe0611ccL){boundary=pc;break;}if(!e.step(monitor))throw new Exception("case"+cid+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=10000)throw new Exception("step bound");
 StringBuilder row=new StringBuilder("{\"case\":"+cid+",\"family\":"+family+",\"entry\":"+entry+",\"steps\":"+steps+",\"boundary\":"+boundary+",\"end_pc\":"+e.getExecutionAddress().getOffset()+",\"initial_priority\":"+initial+",\"final_priority\":"+cpu.getBasePriority());
 for(int i=0;i<3;i++)row.append(",\"").append(names[i]).append("_before\":\"").append(zip(windows[i])).append("\",\"").append(names[i]).append("_after\":\"").append(zip(e.readMemory(toAddr(bases[i]),windows[i].length))).append("\"");out.println(row.append('}'));
 }finally{e.dispose();}
 }}println("FRAME_SYNC_COMPLETE="+sa[2]+":"+total);
 }
}
