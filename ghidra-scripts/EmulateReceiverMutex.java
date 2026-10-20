import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverMutex extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}
 void chain(byte[]m,int sent,List<Integer>nodes){w32(m,sent,0x23000000L+(nodes.isEmpty()?sent:nodes.get(0)));w32(m,sent+4,0x23000000L+(nodes.isEmpty()?sent:nodes.get(nodes.size()-1)));for(int j=0;j<nodes.size();j++){int a=nodes.get(j);w32(m,a,0x23000000L+(j+1==nodes.size()?sent:nodes.get(j+1)));w32(m,a+4,0x23000000L+(j==0?sent:nodes.get(j-1)));}}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random random=new Random(0x1206cdacL);int start=getScriptArgs().length>2?Integer.parseInt(getScriptArgs()[2]):0;
 String[]names={"ram","rtc"};long[]addresses={0x23000000L,0x5f99c000L};
 try(PrintWriter out=new PrintWriter(new FileOutputStream(getScriptArgs()[0],start>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int id=0;id<2240;id++){
 int family=id>=2048?(id-2048)/32:-1;int op=family<0?id/512:new int[]{0,1,3,3,4,5}[family],v=id%512;byte[][]windows={new byte[131072],new byte[4096]};byte[]pattern=new byte[256];random.nextBytes(pattern);for(int j=0;j<windows.length;j++)for(int k=0;k<windows[j].length;k++)windows[j][k]=pattern[(k+j*7)%256];
 byte[]ram=windows[0];System.arraycopy(image,0x1c854,ram,0,0x1e08);
 int current=0x6000,owner=0x6100,mutex=0x7000;int[]threads={current,owner,0x6200,0x6300,0x6400,0x29f8};
 for(int t:threads){Arrays.fill(ram,t,t+0x90,(byte)0);w32(ram,t+0x8c,0x87654321L);}
 int[]priorities={-128,-127,-8,0,4,127};ram[current+0xe]=(byte)priorities[v%6];ram[owner+0xe]=(byte)priorities[v/6%6];ram[current+0xd]=(byte)128;ram[owner+0xd]=(byte)(v%3==0?4:128);ram[0x640d]=(byte)128;ram[0x640e]=8;ram[0x29fe]=127;
 ram[0x620e]=-8;ram[0x630e]=4;ram[0x620d]=2;ram[0x630d]=(byte)(v%4==0?6:2);
 w32(ram,0x7170,0x23000000L+current);w32(ram,0x7174,0x230029f8L);w32(ram,0x717c,0x23000000L+current);ram[0x7178]=0;
 ArrayList<Integer> ready=new ArrayList<>();ready.add(current);if((ram[owner+0xd]&128)!=0)ready.add(owner);ready.add(0x6400);ready.sort((aa,bb)->Byte.compare(ram[aa+0xe],ram[bb+0xe]));chain(ram,0x7180,ready);
 long count=new long[]{0,1,2,0xffffffffL}[v/6%4];long owning=op==0?(v%4==0?0x23006000L:0x23006100L):new long[]{0,0x23006000L,0x23006100L}[v/4%3];
 ArrayList<Integer> waiters=new ArrayList<>();if(count!=0||op!=0){if(v/12%3>0)waiters.add(0x6200);if(v/12%3>1)waiters.add(0x6300);}chain(ram,mutex,waiters);w32(ram,mutex+8,owning);w32(ram,mutex+12,count);w32(ram,mutex+16,priorities[v/24%6]);for(int t:waiters)w32(ram,t+8,0x23000000L+mutex);
 Arrays.fill(ram,0x2c60,0x2c78,(byte)0);Arrays.fill(ram,0x5000,0x5018,(byte)0);w32(ram,0x7194,new long[]{0,1,10,0xffffffffL}[v/4%4]);w32(ram,0x7190,0);w32(windows[1],0x770,100+v*13);w32(windows[1],0x774,0);w32(ram,0x2840,100);w32(ram,0x2844,0);ram[0x960]=(byte)new int[]{7,13,14,15}[v%4];w32(ram,0xab4,0);w32(ram,0x7198,v%11==0?1:0);w32(ram,0x2c78,v%5);w32(ram,0x2c7c,0);
 ArrayList<Integer> ts=new ArrayList<>();ts.add(0x5000);for(int t:waiters)if(v%2==0)ts.add(t+0x18);if(v%3==0)ts.add(owner+0x18);if(v%2==0)ts.add(0x2c60);chain(ram,0xb48,ts);for(int j=0;j<ts.size();j++){int t=ts.get(j);w32(ram,t+16,new long[]{0,1,10,100,0x7fffffffL}[(v+j)%5]);w32(ram,t+20,0);}
 long timeout=new long[]{0,-1L,1,10,1000,0x100000002L}[v/4%6];int newpriority=new int[]{-128,-127,-8,0,1,4,127}[v%7],changed=v%2;long pendresult=new long[]{0,1,0xfffffff5L}[v%3];
 if(family>=0){
  changed=1;pendresult=0xfffffff5L;
  if(family==0){timeout=0;w32(ram,mutex+8,0x23006100L);w32(ram,mutex+12,1);}
  if(family>=1&&family<=3){
   ram[current+0xd]=(byte)128;ram[current+0xe]=4;ram[owner+0xd]=(byte)128;ram[owner+0xe]=(byte)(family==2?-8:8);ram[0x640d]=(byte)128;ram[0x640e]=16;
   w32(ram,owner+0x18,0);w32(ram,owner+0x1c,0);ready=new ArrayList<>(Arrays.asList(current,owner,0x6400));ready.sort((aa,bb)->Byte.compare(ram[aa+0xe],ram[bb+0xe]));chain(ram,0x7180,ready);
   waiters=new ArrayList<>(Arrays.asList(0x6200));chain(ram,mutex,waiters);ram[0x620d]=2;ram[0x620e]=(byte)(family==2?-16:-8);w32(ram,0x6208,0x23007000L);
   w32(ram,mutex+8,family==1?0x23006000L:family==2?0x23006100L:0);w32(ram,mutex+12,1);w32(ram,mutex+16,family==1?4:8);
   ts=new ArrayList<>(Arrays.asList(0x5000));if(v%2==0)ts.add(0x6218);else{w32(ram,0x6218,0);w32(ram,0x621c,0);}w32(ram,0x2c60,0);w32(ram,0x2c64,0);chain(ram,0xb48,ts);for(int j=0;j<ts.size();j++){w32(ram,ts.get(j)+16,10);w32(ram,ts.get(j)+20,0);}
   if(family==3)w32(ram,0x717c,0x23006100L);
  }
 }
 final long initial=family>=0?0:new long[]{0,0x20,0x40,0x80}[v/3%4];final int exception=family>=0?0:v%5==0?0:60;
 if(id<start)continue;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});
 e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.registerCallOtherCallback("DataMemoryBarrier",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);

 for(int j=0;j<windows.length;j++)e.writeMemory(toAddr(addresses[j]),windows[j]);
 e.writeRegister("r0",op==2?0x23006100L:0x23007000L);e.writeRegister("r1",newpriority&255);e.writeRegister("r2",timeout&0xffffffffL);e.writeRegister("r3",timeout>>>32);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);
 if(op>=3){byte[]stack=new byte[32];w32(stack,28,0x2302df01L);e.writeMemory(toAddr(0x2302efe0L),stack);e.writeRegister(e.getStackPointerRegister(),0x2302efe0L);e.writeRegister("r0",pendresult);e.writeRegister("r4",0x23007000L);e.writeRegister("r6",changed);if(op==5){byte[]tail=new byte[16];w32(tail,12,0x2302df01L);e.writeMemory(toAddr(0x2302eff0L),tail);e.writeRegister(e.getStackPointerRegister(),0x2302eff0L);}}
 e.writeRegister(e.getPCRegister(),new long[]{0xe06cdacL,0xe06cea8L,0xe06dfc8L,0xe06ce22L,0xe06ce7eL,0xe06cf04L}[op]);
 int steps=0;long boundary=0,arg0=0;while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<100000){long pc=e.getExecutionAddress().getOffset();if(pc==0xe0611ccL){boundary=pc;arg0=e.readRegister("r0").longValue()&0xffffffffL;break;}if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=100000)throw new Exception("bound"+id);
 StringBuilder row=new StringBuilder("{\"case\":"+id+",\"op\":"+op+",\"mutex\":587231232,\"timeout\":\""+Long.toUnsignedString(timeout)+"\",\"newpriority\":"+newpriority+",\"changed\":"+changed+",\"pendresult\":"+pendresult+",\"saved_changed\":"+(e.readRegister("r6").longValue()&0xffffffffL)+",\"initial_priority\":"+initial+",\"exception\":"+exception+",\"final_priority\":"+cpu.getBasePriority()+",\"boundary\":"+boundary+",\"arg0\":"+arg0+",\"return\":"+(e.readRegister("r0").longValue()&0xffffffffL)+",\"steps\":"+steps+",\"end_pc\":"+e.getExecutionAddress().getOffset());
 for(int j=0;j<windows.length;j++){row.append(",\"").append(names[j]).append("_before\":\"").append(zip(windows[j])).append("\",\"").append(names[j]).append("_after\":\"").append(zip(e.readMemory(toAddr(addresses[j]),windows[j].length))).append("\"");}row.append("}");out.println(row);
 }finally{e.dispose();}
 }}println("RECEIVER_MUTEX_CASES=2240");
 }
}
