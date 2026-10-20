import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverTimerExpiry extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}long u32(EmulatorHelper e,long a){byte[]b=e.readMemory(toAddr(a),4);return (b[0]&255L)|(b[1]&255L)<<8|(b[2]&255L)<<16|(b[3]&255L)<<24;}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 int first=getScriptArgs().length>2?Integer.parseInt(getScriptArgs()[2]):0,last=getScriptArgs().length>3?Integer.parseInt(getScriptArgs()[3]):8192;
 Random random=new Random(0x1206eb00L);
 try(PrintWriter out=new PrintWriter(new FileOutputStream(getScriptArgs()[0],first>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int id=0;id<8192;id++){
 int op=id/2048,v=id%2048;byte[]ram=new byte[131072],rtc=new byte[4096],pattern=new byte[256];random.nextBytes(pattern);for(int i=0;i<ram.length;i++)ram[i]=pattern[i%256];for(int i=0;i<rtc.length;i++)rtc[i]=pattern[(i+17)%256];
 // Coherent delta queue and ready queue; supported callbacks execute original instructions.
 // Timer expiry and two explicit unknown callback addresses remain entry boundaries.
 for(int z:new int[]{0x5600,0x5700,0x5800,0x5900,0x29f8,0x6200})Arrays.fill(ram,z,z+0x90,(byte)0);
 w32(ram,0x5c18,0);w32(ram,0x5c1c,0);w32(ram,0x5d18,0);w32(ram,0x5d1c,0);
 long cur=v%19==0?0x230029f8L:0x23005800L;w32(ram,0x7170,cur);w32(ram,0x7174,0x23005900L);w32(ram,0x717c,cur);ram[0x7178]=0;
 int curOff=(int)(cur-0x23000000L);ram[curOff+0xe]=(byte)new int[]{-1,0,4,8}[(v/8)%4];ram[curOff+0xd]=(byte)new int[]{0,4,128,0}[(v/32)%4];
 ArrayList<Integer>readyList=new ArrayList<>();readyList.add(0x5600);if((ram[curOff+0xd]&128)!=0)readyList.add(curOff);readyList.add(0x5700);ram[0x560d]=(byte)128;ram[0x570d]=(byte)128;ram[0x560e]=1;ram[0x570e]=9;
 readyList.sort((a,b)->Byte.compare(ram[a+0xe],ram[b+0xe]));w32(ram,0x7180,0x23000000L+readyList.get(0));w32(ram,0x7184,0x23000000L+readyList.get(readyList.size()-1));for(int j=0;j<readyList.size();j++){int z=readyList.get(j);w32(ram,z,j+1==readyList.size()?0x23007180L:0x23000000L+readyList.get(j+1));w32(ram,z+4,j==0?0x23007180L:0x23000000L+readyList.get(j-1));}
 w32(ram,0x7188,v%5==0?cur:0);ram[0x718c]=(byte)((v/7)%2);w32(ram,0x7190,new long[]{-2,0,4,10}[(v/11)%4]);w32(ram,0x7194,new long[]{0,1,8,16,0xffffffffL}[(v/13)%5]);
 w32(ram,0x2528,0);w32(ram,0x252c,0);w32(ram,0x2540,1);w32(ram,0x2530,0x23002530L);w32(ram,0x2534,0x23002530L);
 for(int z:new int[]{0x1a30,0x1578,0x5300}){Arrays.fill(ram,z,z+0x38,(byte)0);w32(ram,z+8,0xe06eb01L);w32(ram,z+0x18,0x23000000L+z+0x18);w32(ram,z+0x1c,0x23000000L+z+0x18);}
 w32(ram,0x1a50,0x230255b9L);w32(ram,0x1a58,32);w32(ram,0x1598,0x230255b9L);w32(ram,0x15a0,v%3==0?8:0);w32(ram,0x5320,v%17==0?0x23024fd9L:0);w32(ram,0x5328,v%3==0?1:0);
 Arrays.fill(ram,0x2c60,0x2c78,(byte)0);w32(ram,0x2c68,0xe06e4c9L);Arrays.fill(ram,0x6000,0x6018,(byte)0);w32(ram,0x6008,0xe06c001L);
 w32(ram,0x6200,0x23006800L);w32(ram,0x6204,0x23006800L);w32(ram,0x6208,0x23006800L);ram[0x620d]=(byte)new int[]{2,6,18,0x22,0x42}[(v/16)%5];ram[0x620e]=(byte)new int[]{-4,0,2,7}[(v/40)%4];ram[0x626c]=(byte)(v%7==0?1:0);w32(ram,0x6220,0xe06daf5L);w32(ram,0x6800,0x23006200L);w32(ram,0x6804,0x23006200L);
 int[]allNodes={0x1a30,0x1578,0x2c60,0x6218,0x5300,0x6000};int nodeCount=v%7,rotation=(v/7)%6;ArrayList<Integer>nodes=new ArrayList<>();for(int j=0;j<nodeCount;j++)nodes.add(allNodes[(rotation+j)%6]);
 if(op==0&&v%13!=0){nodes.remove(Integer.valueOf(0x1a30));w32(ram,0x1a30,0);w32(ram,0x1a34,0);}nodeCount=nodes.size();
 w32(ram,0xb48,nodeCount==0?0x23000b48L:0x23000000L+nodes.get(0));w32(ram,0xb4c,nodeCount==0?0x23000b48L:0x23000000L+nodes.get(nodeCount-1));for(int j=0;j<nodeCount;j++){int z=nodes.get(j);w32(ram,z,j+1==nodeCount?0x23000b48L:0x23000000L+nodes.get(j+1));w32(ram,z+4,j==0?0x23000b48L:0x23000000L+nodes.get(j-1));w32(ram,z+16,new long[]{0,1,2,4,16,32}[(v/3+j)%6]);w32(ram,z+20,0);}
 w32(ram,0x7198,0);w32(ram,0x2c78,new long[]{0,100,0xfffffff0L}[(v/9)%3]);w32(ram,0x2c7c,v%23==0?0xffffffffL:0);
 long base=v%11==0?0xffffffe0L:1000+v*32L;long clockCurrent=base+2048+(v%32);w32(ram,0x2840,base);w32(ram,0x2844,base>>>32);w32(rtc,0x770,clockCurrent);w32(rtc,0x774,clockCurrent>>>32);
 long tickArg=new long[]{0,1,2,5,16,48,0xffffffffL,0x80000000L}[(v/4)%8];long deadline=base+new long[]{0,32,64,160,512,1536,2112,4096}[(v/8)%8]+v%32;
 w32(ram,0x958,0xe0683a1L);w32(ram,0x95c,0x13572468);ram[0x960]=(byte)new int[]{7,13,14,15}[(v/16)%4];w32(ram,0xab4,new long[]{0,0x80,0x2000,0xe080}[(v/32)%4]);w32(ram,0xab8,new long[]{0xe080,0x80,0xe000,0}[(v/128)%4]);w32(rtc,0x350,new long[]{0xe080,0x80,0xe000,0}[(v/512)%4]);
 for(int j=0;j<4;j++){int ch=new int[]{7,13,14,15}[j],slot=0xabc+j*12;w32(ram,slot,v%13==0&&j==2?0xe05bde1L:v%17==0?0:0xe0683a1L);w32(ram,slot+4,0x11223344L+j);ram[slot+8]=(byte)(v%19==0&&j==3?7:ch);w32(rtc,0x100+ch*4,new long[]{0,1,2,0xffffffffL}[(v+j)%4]);long cd=base+new long[]{0,512,2112,1536}[(v/5+j)%4];w32(rtc,0x520+ch*16,cd);w32(rtc,0x524+ch*16,cd>>>32);}
 // Direct timer paths include recurrence edge values and0..2 waiters.
 if(op==0){long period=new long[]{0,1,-1L,2,32,-2L,-5L,0x7fffffffL,0x80000000L,0x100000000L,Long.MAX_VALUE,Long.MIN_VALUE}[(v/4)%12];w32(ram,0x1a58,period);w32(ram,0x1a5c,period>>>32);w32(ram,0x1a50,new long[]{0,0x230255b9L,0x23024fd9L}[(v/48)%3]);w32(ram,0x1a60,new long[]{0,1,0xffffffffL,0x7fffffffL}[(v/64)%4]);
 int nw=v%3;w32(ram,0x1a48,nw==0?0x23001a48L:0x23006a00L);w32(ram,0x1a4c,nw==0?0x23001a48L:0x23006a00L+(nw-1)*256);
 for(int j=0;j<nw;j++){int t=0x6a00+j*256;Arrays.fill(ram,t,t+0x90,(byte)0);ram[t+0xd]=(byte)new int[]{2,6,0x22,0x42}[(v/7)%4];ram[t+0xe]=(byte)(j==0?-1:8);w32(ram,t, j+1==nw?0x23001a48L:0x23006b00L);w32(ram,t+4,j==0?0x23001a48L:0x23006a00L);w32(ram,t+8,0x23001a48L);w32(ram,t+0x8c,0x87654321L);}
 }
 ram[0x71e4]=(byte)new int[]{0,1,2,255}[(v/7)%4];ram[0x490]=(byte)(v%3);for(int j=0;j<3;j++){ram[0x6834+j]=(byte)((v/3+j)%4);ram[0x6838+j]=(byte)new int[]{0,1,2,3,4,255}[(v/11+j)%6];}
 final long initial=new long[]{0,0x10,0x80}[(v/3)%3];final int exception=op==0?(v%4==0?0:60):125;
 if(id<first||id>=last)continue;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x5f99c000L),rtc);e.writeRegister("r0",op==0?0x23001a30L:op==1?tickArg:7);e.writeRegister("r1",0xe0683a1L);e.writeRegister("r2",deadline&0xffffffffL);e.writeRegister("r3",deadline>>>32);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),new long[]{0xe06eb00L,0xe06e7fcL,0xe0683a0L,0xe069898L}[op]);
 int steps=0;long boundary=0,arg0=0;long[]pendingArgs=new long[5];while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<100000){long pc=e.getExecutionAddress().getOffset();if(pc==0x23024fd8L||pc==0xe06c000L||pc==0xe05bde0L){boundary=pc;arg0=e.readRegister("r0").longValue();pendingArgs[0]=arg0;if(pc==0xe05bde0L){for(int j=1;j<4;j++)pendingArgs[j]=e.readRegister("r"+j).longValue();pendingArgs[4]=u32(e,e.readRegister(e.getStackPointerRegister()).longValue());}break;}if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" SP"+e.readRegister(e.getStackPointerRegister())+" fetched"+hex(e.readMemory(e.getExecutionAddress(),16))+" image"+hex(getBytes(e.getExecutionAddress(),16))+" "+e.getLastError());steps++;}if(steps>=100000)throw new Exception("bound"+id);
 out.println("{\"ticks\":"+tickArg+",\"deadline\":"+deadline+",\"pending_args\":"+Arrays.toString(pendingArgs)+",\"case\":"+id+",\"op\":"+op+",\"before_gzip\":\""+zip(ram)+"\",\"after_gzip\":\""+zip(e.readMemory(toAddr(0x23000000L),ram.length))+"\",\"rtc_before\":\""+zip(rtc)+"\",\"rtc_after\":\""+zip(e.readMemory(toAddr(0x5f99c000L),rtc.length))+"\",\"initial_priority\":"+initial+",\"exception\":"+exception+",\"final_priority\":"+cpu.getBasePriority()+",\"boundary\":"+boundary+",\"arg0\":"+arg0+",\"steps\":"+steps+"}");
 }finally{e.dispose();}
 }}println("RECEIVER_TIMER_EXPIRY_RANGE="+first+":"+last);
 }
}
