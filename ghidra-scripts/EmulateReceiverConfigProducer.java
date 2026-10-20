import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverConfigProducer extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}
 void chain(byte[]m,int sent,List<Integer>nodes){w32(m,sent,0x23000000L+(nodes.isEmpty()?sent:nodes.get(0)));w32(m,sent+4,0x23000000L+(nodes.isEmpty()?sent:nodes.get(nodes.size()-1)));for(int j=0;j<nodes.size();j++){int a=nodes.get(j);w32(m,a,0x23000000L+(j+1==nodes.size()?sent:nodes.get(j+1)));w32(m,a+4,0x23000000L+(j==0?sent:nodes.get(j-1)));}}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random random=new Random(0x1202539cL);int start=getScriptArgs().length>2?Integer.parseInt(getScriptArgs()[2]):0;
 String[]names={"ram","radio","timer","nvic","dppi","rtc","clock0","clock1","clock2","deviceid"};
 long[]addresses={0x23000000L,0x5302c000L,0x53028000L,0xe000e000L,0x53022000L,0x5f99c000L,0x5300e000L,0x5301e000L,0x5302e000L,0x0fffe010L};
 try(PrintWriter out=new PrintWriter(new FileOutputStream(getScriptArgs()[0],start>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int id=0;id<10240;id++){
 int op=(id%5120)/512,v=id%512;byte[][]windows=new byte[names.length][];byte[]pattern=new byte[256];random.nextBytes(pattern);
 for(int j=0;j<windows.length;j++){windows[j]=new byte[j==0?131072:j==9?8:4096];for(int k=0;k<windows[j].length;k++)windows[j][k]=pattern[(k+j*7)%256];}
 byte[]ram=windows[0];System.arraycopy(image,0x1c854,ram,0,0x1e08);
 int[]threads={0x1fc0,0x6000,0x6100,0x29f8,0x6600,0x6700,0x6800};
 for(int t:threads){Arrays.fill(ram,t,t+0x90,(byte)0);ram[t+0xe]=(byte)new int[]{-8,0,1,4,8,127}[(v+t/256)%6];w32(ram,t+0x8c,0x87654321L);}
 int target=0x1fc0;ram[target+0xd]=(byte)new int[]{0,16,128,2,0x42,0x90}[v%6];ram[0x600e]=(byte)new int[]{-1,0,4,127}[(v/4)%4];ram[0x600d]=(byte)(v%5==0?4:0);ram[0x610e]=4;ram[0x610d]=(byte)128;
 int cur=v%7==0?target:0x6000;w32(ram,0x7170,0x23000000L+cur);w32(ram,0x7174,0x230029f8L);w32(ram,0x717c,0x23000000L+cur);ram[0x7178]=0;
 ArrayList<Integer> ready=new ArrayList<>();if((ram[target+0xd]&128)!=0)ready.add(target);if(v%3!=0)ready.add(0x6100);ready.sort((aa,bb)->Byte.compare(ram[aa+0xe],ram[bb+0xe]));chain(ram,0x7180,ready);
 if((ram[target+0xd]&2)!=0){chain(ram,0x6d00,Arrays.asList(target));w32(ram,target+8,0x23006d00L);}
 int[]timers={0x5000,0x1a68,0x1aa0,0x1ad8,0x1b10};
 for(int t:timers){Arrays.fill(ram,t,t+0x38,(byte)0);chain(ram,t+0x18,new ArrayList<Integer>());w32(ram,t+0x24,v%11==0?0x23024fd9L:0);w32(ram,t+0x30,0x98765432L);}
 int timer=op<4?0x5000:0x1aa0;ArrayList<Integer> waiters=new ArrayList<>();if(v%4>0)waiters.add(0x6600);if(v%4>1)waiters.add(0x6700);chain(ram,timer+0x18,waiters);for(int t:waiters){ram[t+0xd]=(byte)new int[]{2,6,0x22,0x42}[(v/4)%4];w32(ram,t+8,0x23000000L+timer+0x18);}
 chain(ram,0x1c54,v%5==0?Arrays.asList(0x6800):new ArrayList<Integer>());ram[0x680d]=2;w32(ram,0x6808,0x23001c54L);w32(ram,0x1c5c,v%2);w32(ram,0x1c60,1);
 Arrays.fill(ram,0x2c60,0x2c78,(byte)0);w32(ram,0x7194,new long[]{0,1,10,0x7fffffffL,0x80000000L,0xffffffffL}[(v/4)%6]);w32(ram,0x7190,0);
 w32(windows[5],0x770,100+v*13);w32(windows[5],0x774,0);w32(ram,0x2840,100);w32(ram,0x2844,0);ram[0x960]=(byte)new int[]{7,13,14,15}[v%4];w32(ram,0xab4,0);w32(ram,0x7198,v%11==0?1:0);w32(ram,0x2c78,v%5);w32(ram,0x2c7c,0);
 ArrayList<Integer> ts=new ArrayList<>();for(int t:timers)if((v+t/8)%3!=0)ts.add(t);for(int t:threads)if((v+t/256)%4==0)ts.add(t+0x18);if(v%2==0)ts.add(0x2c60);chain(ram,0xb48,ts);for(int i=0;i<ts.size();i++){int t=ts.get(i);w32(ram,t+16,new long[]{0,1,10,100,0x7fffffffL}[(v+i)%5]);w32(ram,t+20,0);}
 ram[0x6590]=(byte)(v%4);ram[0x6591]=0;ram[0x6592]=(byte)(v%3);ram[0x6593]=(byte)((v/3)%2);ram[0x6598]=(byte)((v/5)%2);for(int j=0;j<8;j++)ram[0x71c6-j]=(byte)((v%9==0)?32+j:j);
 for(int peer=0;peer<2;peer++){int base=0x33e8+peer*0xf84;Arrays.fill(ram,base+0x154,base+0x160,(byte)0);int[]caps={32,16,16,32,32,96},ptrs={0x356c,0x376c,0x386c,0x396c,0x3b6c,0x3d6c};for(int j=0;j<6;j++){ram[base+0x160+j]=(byte)caps[j];ram[base+0x166+j]=16;w32(ram,base+0x16c+4*j,0x23000000L+ptrs[j]+peer*0xf84);ram[base+0xa7+j]=(byte)(1+(v+j)%7);}ram[base+0x154+3]=(byte)(v%32);ram[base+0x15a+3]=(byte)((v%32+(v%3==0?31:0))%32);}
 int capacity=id<5120?5:10,ringbase=capacity==5?0x15760:0x155f8;int queue=0x1bb4,count=v%(capacity+1),read=(v/(capacity+1))%capacity;long timeout=new long[]{0,-1L,1,10,1000,-2L,0x100000002L}[(v/6)%7];
 // Detach old timer waiters; these same two synthetic threads now wait on queue.
 for(int t:timers)chain(ram,t+0x18,new ArrayList<Integer>());
 int current=0x6000;w32(ram,0x7170,0x23006000L);w32(ram,0x717c,0x23006000L);ram[0x600d]=(byte)(v%3==0?0x80:0);ram[0x600e]=(byte)new int[]{-8,0,1,4,127}[(v/3)%5];
 // Current thread has no active timeout before entering a new wait.
 ts.remove(Integer.valueOf(0x6018));w32(ram,0x6018,0);w32(ram,0x601c,0);chain(ram,0xb48,ts);
 ready=new ArrayList<>();if((ram[0x1fcd]&128)!=0)ready.add(0x1fc0);if(v%3!=1)ready.add(0x6100);if((ram[0x600d]&128)!=0)ready.add(current);ready.sort((aa,bb)->Byte.compare(ram[aa+0xe],ram[bb+0xe]));chain(ram,0x7180,ready);
 waiters=new ArrayList<>();if(count==0||count==capacity){if((v/6)%3>0)waiters.add(0x6600);if((v/6)%3>1)waiters.add(0x6700);}chain(ram,queue,waiters);
 for(int t:new int[]{0x6600,0x6700}){ram[t+0xd]=(byte)new int[]{2,6,0x22,0x42}[(v/7)%4];ram[t+0xe]=(byte)(t==0x6600?-1:8);w32(ram,t+8,0x23000000L+queue);w32(ram,t+0x14,0x23008000L+(t-0x6600));}
 w32(ram,queue+8,36);w32(ram,queue+12,capacity);w32(ram,queue+16,0x23000000L+ringbase);w32(ram,queue+20,0x23000000L+ringbase+capacity*36);w32(ram,queue+24,0x23000000L+ringbase+read*36);w32(ram,queue+28,0x23000000L+ringbase+((read+count)%capacity)*36);w32(ram,queue+32,count);
 Arrays.fill(ram,0x1ea0,0x1f30,(byte)0);ram[0x1ead]=(byte)new int[]{0,16,128,2,0x42,0x90}[v%6];ram[0x1eae]=(byte)new int[]{-8,0,1,4,8,127}[(v/7)%6];w32(ram,0x1f2c,0x87654321L);
 if((ram[0x1ead]&2)!=0){chain(ram,0x6e00,Arrays.asList(0x1ea0));w32(ram,0x1ea8,0x23006e00L);}
 if((ram[0x1ead]&128)!=0){ready.add(0x1ea0);ready.sort((aa,bb)->Byte.compare(ram[aa+0xe],ram[bb+0xe]));chain(ram,0x7180,ready);}
 if(v%17==0){w32(ram,0x7170,0x23001ea0L);w32(ram,0x717c,0x23001ea0L);}
 if(v%4==0){ts.add(0x1eb8);w32(ram,0x1ec8,100);w32(ram,0x1ecc,0);chain(ram,0xb48,ts);}
 long value=Integer.toUnsignedLong(random.nextInt()),event=op<3?new long[]{1,8,9}[op]:op>=6?new long[]{41,40,44,43}[op-6]:new long[]{0,4,10,40,41,43,44,45,0xffffffffL}[v%9];
 byte[]stack=new byte[1024];random.nextBytes(stack);long sp=0x2302f000L;
 int tailstart=op<3?0x2dc:op==3?0x2d8:op==4?0x2d4:0x2d0;int taillen=op<3||op==4?28:32;byte[]opaque=Arrays.copyOfRange(stack,tailstart,tailstart+taillen);
 final long initial=new long[]{0,0x20,0x40,0x80}[(v/11)%4];final int exception=v%7==0?0:60;
 if(id<start)continue;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});
 e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.registerCallOtherCallback("DataMemoryBarrier",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);

 for(int j=0;j<windows.length;j++)e.writeMemory(toAddr(addresses[j]),windows[j]);e.writeMemory(toAddr(0x2302ed00L),stack);
 e.writeRegister("r0",op==3?event:value);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),sp);
 e.writeRegister(e.getPCRegister(),new long[]{0x23024fd8L,0x230252a4L,0x23025300L,0x2302539cL,0x23020680L,0x230252d4L,0x2302069cL,0x230206c4L,0x230206e4L,0x2302070cL}[op]);
 int steps=0;long boundary=0,arg0=0;while(e.getExecutionAddress().getOffset()!=0x2302df00L&&(steps==0||e.getExecutionAddress().getOffset()!=0x23024e46L)&&steps<100000){long pc=e.getExecutionAddress().getOffset();if(pc==0x0e0611ccL||pc==0x23025954L){boundary=pc;arg0=e.readRegister("r0").longValue();break;}if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=100000)throw new Exception("bound"+id);
 StringBuilder row=new StringBuilder("{\"case\":"+id+",\"op\":"+op+",\"value\":"+value+",\"opaque_tail\":\""+hex(opaque)+"\",\"event\":"+event+",\"initial_priority\":"+initial+",\"exception\":"+exception+",\"final_priority\":"+cpu.getBasePriority()+",\"boundary\":"+boundary+",\"arg0\":"+arg0+",\"steps\":"+steps+",\"end_pc\":"+e.getExecutionAddress().getOffset());
 for(int j=0;j<windows.length;j++){row.append(",\"").append(names[j]).append("_before\":\"").append(zip(windows[j])).append("\",\"").append(names[j]).append("_after\":\"").append(zip(e.readMemory(toAddr(addresses[j]),windows[j].length))).append("\"");}row.append("}");out.println(row);
 }finally{e.dispose();}
 }}println("RECEIVER_CONFIG_PRODUCER_CASES=10240");
 }
}
