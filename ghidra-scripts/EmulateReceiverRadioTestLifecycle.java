import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverRadioTestLifecycle extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}long u32(EmulatorHelper e,long a){byte[]b=e.readMemory(toAddr(a),4);return (b[0]&255L)|(b[1]&255L)<<8|(b[2]&255L)<<16|(b[3]&255L)<<24;}
 void chain(byte[]m,int sent,List<Integer>nodes){w32(m,sent,0x23000000L+(nodes.isEmpty()?sent:nodes.get(0)));w32(m,sent+4,0x23000000L+(nodes.isEmpty()?sent:nodes.get(nodes.size()-1)));for(int j=0;j<nodes.size();j++){int a=nodes.get(j);w32(m,a,0x23000000L+(j+1==nodes.size()?sent:nodes.get(j+1)));w32(m,a+4,0x23000000L+(j==0?sent:nodes.get(j-1)));}}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random random=new Random(0x120cbb8L);int start=Integer.parseInt(getScriptArgs()[2]),end=Integer.parseInt(getScriptArgs()[3]);try(PrintWriter out=new PrintWriter(new FileOutputStream(getScriptArgs()[0],start>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int cid=0;cid<4224;cid++){
 int group=cid/128,v=cid%128;int family=group<11?0:group<27?3:4;int op=family==0?group:family==3?(group-11)/2:group-27;
 long[]engineEntries={0xe05c8fcL,0xe05c9ecL,0xe05cac4L,0xe05c7f4L,0xe05cb44L,0xe05cbb8L,0xe05cc4cL,0xe05c8a0L,0xe05cd04L,0xe05cd78L,0xe05d028L};
 long[]timerEntries={0xe069e04L,0xe069ee8L,0xe069f3cL,0xe069f5cL,0xe069f7cL,0xe069f84L,0xe069ff0L,0xe06a064L,0xe069d98L,0xe06a0c4L};
 long[]gpEntries={0xe06a658L,0xe06a760L,0xe06a8e0L,0xe06a6a0L,0xe06a708L,0xe06aaccL,0xe06ab28L,0xe06ab4cL,0xe06ab80L,0xe06a484L,0xe06a264L,0xe068a5cL};
 long entry=family==0?engineEntries[op]:0;
 byte[]ram=new byte[131072],pattern=new byte[256];random.nextBytes(pattern);for(int i=0;i<ram.length;i++)ram[i]=pattern[i%256];
 String[]names={"ram","radio","timer","egu","dppi","rtc","nvic","normal_timer"};long[]bases={0x23000000L,0x5302c000L,0x53029000L,0x53025000L,0x53022000L,0x5f99c000L,0xe000e000L,0x53028000L};byte[][]windows=new byte[8][];windows[0]=ram;for(int j=1;j<8;j++){windows[j]=new byte[4096];for(int i=0;i<4096;i++)windows[j][i]=pattern[(i+j*31)%256];}
 byte[]timer=windows[2];w32(windows[5],0x770,0x10203040L+cid);w32(windows[5],0x774,v);
 w32(ram,0xaf8,v%6==0?0:15);w32(ram,0xafc,15);ram[0x71df]=0;
 for(int j=0;j<4;j++){int slot=0x6e58+12*j;w32(ram,slot,0xe0707a4L);w32(ram,slot+4,0xe0707a4L);w32(ram,slot+8,0x00ff00ffL|((j&3)<<8));}
 if(family==2&&op==5)ram[0x6e60]=(byte)(v%5==0?255:v%4);
 w32(windows[4],0x500,v%2==0?15:0);
 w32(ram,0x6620,((v&1)!=0?0x10000:0)|((v&2)!=0?4:0)|((v&4)!=0?16:0)|((v&8)!=0?256:0));
 ram[0x71e0]=(byte)((v/8)%2);ram[0x71e1]=(byte)(v*3);
 long[]modes={0,3,4,5,6,9,15,255};long[]powers={-70,-40,-30,-20,-16,-12,-8,-4,-2,-1,0,1,2,3,4,5,6,7,8,9,10,-128,11,0x12345678};long[]lengths={0,1,255,256,65535};
 long mode=modes[(v/8)%8],power=powers[v%powers.length]&0xffffffffL,channel=v%32,patternValue=new long[]{0,1,2,3,255,256}[v%6],length=lengths[v%5];
 long[]args={mode,power,channel,0,0};
 ram[0x65e8]=(byte)(v%8);ram[0x65e9]=(byte)mode;ram[0x65ec]=(byte)power;ram[0x65ed]=(byte)(v%4);ram[0x65ee]=(byte)channel;ram[0x65ef]=(byte)(v%8);
 w32(ram,0x65f0,new long[]{1,10,50,99,100,101,0,0xffffffffL}[v%8]);w32(ram,0x65f4,v%3);w32(ram,0x65f8,length);
 if(family==0){
 if(op==0)args[0]=power;
 if(op==1||op==2){args[0]=mode;args[1]=patternValue;args[2]=length;}
 if(op==4)args[0]=v%2;
 if(op==6){args[0]=mode;args[1]=channel;args[2]=patternValue;}
 if(op==7){args[0]=channel;args[1]=v%2==0?v:0xffffffffL;}
 if(op==8){args[0]=v%5==0?0x144:0x140;args[1]=0x230065e8L;ram[0x65e8]=(byte)(v%3==0?3:v%3==1?4:7);}
 if(op==9)args[0]=0x230065e8L;
 }
 w32(timer,0x510,new long[]{0,1,5,31,32,33,64,255}[v%8]);
 if(family==0)w32(timer,0x510,5);
 if(family==1){
 args[0]=0xe06fd14L;args[1]=v%2==0?v:0xffffffffL;
 if(op==0||op==1){args[1]=op==1&&v%7==0?0:0x23002d24L;args[2]=0x2302d801L;w32(ram,0x2d24,new long[]{0,1000000,32000000,16000000,123,62500,1,64000000}[v%8]);ram[0x2d28]=(byte)(v%4);ram[0x2d29]=(byte)((v/4)%4);w32(ram,0x2d2c,0x230065e8L);ram[0x6e54]=(byte)(v%3);}
 if(op==7){args[1]=v%8;args[2]=0x12345678L+v;args[3]=new long[]{0,1,2,0x10001,0xffffffffL}[v%5];args[4]=v%2;}
 if(op>=8){args[0]=0x53029000L;args[1]=0x23006e4cL;w32(ram,0x6e4c,v%5==0?0:0x2302d801L);w32(ram,0x6e50,0x230065e8L);w32(timer,0x304,(long)v<<16);for(int j=0;j<8;j++)w32(timer,0x140+j*4,((v+j)%3)==0?1:0);}
 }
 if(family==2){
 args[0]=0;args[1]=0x53025100L;args[2]=v%2==0?0x5302c000L:0x5302c004L;
 if(op==0){args[0]=0x230071dfL;}
 if(op==1){w32(ram,0xafc,v%5==0?0:15);w32(ram,0x6e58,0);w32(ram,0x6e5c,0);w32(ram,0x6e60,0x00ffffffL);}
 if(op==2)w32(ram,0xafc,v%2==0?14:15);
 if(op==3||op==4)args[1]=0x53029000L;
 if(op==6||op==7)args[0]=v%16;
 if(op==8)args[0]=new long[]{0x53025100L,0x53029000L,0x5302c000L,0x5f991140L,0x5f9a1100L,0x12345678L}[v%6];
 if(op==9){args[0]=0xe0707a4L;args[1]=0xe0707a4L;args[2]=0x230071dfL;w32(ram,0xafc,v%5==0?0:15);}
 if(op==10){args[0]=0xe0707a4L;args[1]=0xe0707a4L;args[2]=v%5==0?255:v%4;w32(ram,0xafc,v%2==0?0:15);}
 if(op==11){args[0]=0x23000af8L;args[1]=0x230071dfL;}
 }
 long eventValue=v%3==0?0:v%3==1?1:0x80000000L;final long initial=new long[]{0,32,128}[v%3];final int exception=v%5==0?0:60;
 boolean resultValid=family==1&&(op==0||op==1||op==5||op==6)||family==2&&(op==0||op==5||op==8||op==9||op==10||op==11);

 // RTOS state is bounded and coherent; the CPU-switch instruction remains a boundary.
 int[]threads={0x1fc0,0x6000,0x6100,0x29f8};
 for(int t:threads){Arrays.fill(ram,t,t+0x90,(byte)0);ram[t+0xe]=(byte)new int[]{-8,0,1,4,8,127}[(v+t/256)%6];w32(ram,t+0x8c,0x87654321L);}
 int target=0x1fc0;ram[target+0xd]=(byte)new int[]{0,16,128,2,0x42,0x90}[v%6];ram[0x600e]=(byte)new int[]{-1,0,4,127}[(v/4)%4];ram[0x600d]=(byte)(v%5==0?4:0);ram[0x610e]=4;ram[0x610d]=(byte)128;
 int cur=v%7==0?target:0x6000;w32(ram,0x7170,0x23000000L+cur);w32(ram,0x7174,0x230029f8L);w32(ram,0x717c,0x23000000L+cur);ram[0x7178]=0;
 ArrayList<Integer> ready=new ArrayList<>();if((ram[target+0xd]&128)!=0)ready.add(target);if(v%3!=0)ready.add(0x6100);ready.sort((aa,bb)->Byte.compare(ram[aa+0xe],ram[bb+0xe]));chain(ram,0x7180,ready);
 if((ram[target+0xd]&2)!=0){chain(ram,0x6d00,Arrays.asList(target));w32(ram,target+8,0x23006d00L);}
 Arrays.fill(ram,0x2c60,0x2c78,(byte)0);w32(ram,0x7194,new long[]{0,1,10,0x7fffffffL,0x80000000L,0xffffffffL}[(v/4)%6]);w32(ram,0x7190,0);ram[0x718c]=0;
 w32(windows[5],0x770,100+v*13);w32(windows[5],0x774,0);w32(ram,0x2840,100);w32(ram,0x2844,0);ram[0x960]=(byte)new int[]{7,13,14,15}[v%4];w32(ram,0xab4,0);w32(ram,0x7198,v%11==0?1:0);w32(ram,0x2c78,v%5);w32(ram,0x2c7c,0);
 ArrayList<Integer> ts=new ArrayList<>();ts.add(0x5000);if(v%3==0)ts.add(target+0x18);if(v%2==0)ts.add(0x2c60);chain(ram,0xb48,ts);for(int i=0;i<ts.size();i++){int t=ts.get(i);w32(ram,t+16,new long[]{0,1,10,100,0x7fffffffL}[(v+i)%5]);w32(ram,t+20,0);}
 if(!ts.contains(target+0x18)){w32(ram,target+0x18,0);w32(ram,target+0x1c,0);}
 for(int j=0;j<8;j++)ram[0x71c6-j]=(byte)(v%9==0?32+j:j);
 w32(ram,0x494,v%8==0?0x2302d801L:0xe05d625L);
 ram[0x6e54]=(byte)(v%3);resultValid=false;
 if(family==3){
  entry=new long[]{0xe05c504L,0xe05c5ecL,0xe05c6d4L,0xe05c774L,0xe05c214L,0xe05c0e8L,0xe05c200L,0xe05c0d4L}[op];
 int cv=(cid-1408)%256;resultValid=false;
 for(int i=0;i<14;i++)ram[0x2d24+i]=(byte)(cv+i*17);ram[0x2d24]=(byte)(cv%8);
 ram[0x71c7]=(byte)((cv/2)%3);ram[0x71d1]=(byte)((cv/3)%3);ram[0x71dd]=(byte)((cv/5)%3);ram[0x71dc]=(byte)((cv/7)%3);ram[0x71d0]=(byte)((cv/11)%3);
 ram[0x71de]=(byte)((cv/13)%3);ram[0x71db]=(byte)(cv%8);ram[0x71d9]=(byte)((cv/16)%4);ram[0x71cf]=(byte)((cv/16)%4);
 ram[0x71d8]=(byte)((cv/8)%2);ram[0x71da]=(byte)((cv/16)%2);ram[0x71d7]=(byte)cv;ram[0x71d2]=(byte)cv;
 ram[0x71d4]=(byte)(cv%20);ram[0x71ce]=(byte)(cv%20);ram[0x71ca]=(byte)cv;ram[0x71c9]=(byte)(cv%9);w32(timer,0x510,5);
 if(op==3){ram[0x71dd]=(byte)((cv/64)%2);ram[0x71dc]=(byte)((cv/32)%2);ram[0x71d1]=(byte)((cv/16)%2);ram[0x71d0]=(byte)((cv/8)%2);ram[0x71c7]=(byte)((cv/4)%2);ram[0x71de]=(byte)((cv/2)%2);}
 args[0]=op<3?0x23002d24L:op==4?(cv/64)%2:0x12345678L+cv;args[1]=op==4?(cv/128)%2:0x87654321L-cv;

 }
 if(family==4){
 entry=new long[]{0x23021f04L,0x23021f88L,0x23021d9cL,0x23021db0L,0xe05d1acL,0xe0612f0L}[op];
 args[0]=0x230065e8L;args[1]=v;args[2]=v%4;
 if(op==5){args[0]=new long[]{-12,-1,0,41,127,255,0xfffffff4L,0x10029L}[v%8]&0xffffffffL;}
 resultValid=op==4;
 }

 if(cid<start||cid>=end)continue;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.registerCallOtherCallback("DataMemoryBarrier",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 for(int i=0;i<windows.length;i++)e.writeMemory(toAddr(bases[i]),windows[i]);
 for(int i=0;i<4;i++)e.writeRegister("r"+i,args[i]);e.writeMemoryValue(toAddr(0x2302f000L),4,args[4]);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),entry);
 int steps=0,kind=0,mask=0,consumed=0;long boundary=0;long[]bargs=new long[4];Set<Long>polls=Set.of(0xe05cbdcL,0xe05cc70L,0xe05cf14L,0xe05ce86L,0xe05d066L);
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<100000){long pc=e.getExecutionAddress().getOffset();
 if(polls.contains(pc)){if(eventValue==0){kind=2;boundary=pc;bargs[0]=0x5302c220L;mask=1;break;}e.writeMemoryValue(toAddr(0x5302c220L),4,eventValue);consumed++;}
 if(pc==0xe0611ccL||pc==0x2302d800L){kind=1;boundary=pc;bargs[0]=e.readRegister("r0").longValue();mask=1;break;}
 if(!e.step(monitor))throw new Exception("case"+cid+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=100000)throw new Exception("bound"+cid+" "+e.getExecutionAddress());
 StringBuilder row=new StringBuilder("{\"case\":"+cid+",\"family\":"+family+",\"op\":"+op+",\"entry\":"+entry+",\"args\":"+Arrays.toString(args)+",\"event_value\":"+eventValue+",\"consumed\":"+consumed+",\"initial_priority\":"+initial+",\"exception\":"+exception+",\"final_priority\":"+cpu.getBasePriority()+",\"kind\":"+kind+",\"boundary\":"+boundary+",\"boundary_args\":"+Arrays.toString(bargs)+",\"arg_mask\":"+mask+",\"result_valid\":"+resultValid+",\"result\":"+(resultValid&&boundary==0?e.readRegister("r0").longValue():0)+",\"steps\":"+steps);
 for(int i=0;i<windows.length;i++)row.append(",\"").append(names[i]).append("_before\":\"").append(zip(windows[i])).append("\",\"").append(names[i]).append("_after\":\"").append(zip(e.readMemory(toAddr(bases[i]),windows[i].length))).append("\"");row.append("}");out.println(row);
 }finally{e.dispose();}
 }}println("RECEIVER_RADIO_LIFECYCLE_RANGE="+start+":"+end);
 }
}
