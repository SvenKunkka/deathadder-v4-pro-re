import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverVendorFlow extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}long u32(EmulatorHelper e,long a){byte[]b=e.readMemory(toAddr(a),4);return (b[0]&255L)|(b[1]&255L)<<8|(b[2]&255L)<<16|(b[3]&255L)<<24;}
 void chain(byte[]m,int sent,List<Integer>nodes){w32(m,sent,0x23000000L+(nodes.isEmpty()?sent:nodes.get(0)));w32(m,sent+4,0x23000000L+(nodes.isEmpty()?sent:nodes.get(nodes.size()-1)));for(int j=0;j<nodes.size();j++){int a=nodes.get(j);w32(m,a,0x23000000L+(j+1==nodes.size()?sent:nodes.get(j+1)));w32(m,a+4,0x23000000L+(j==0?sent:nodes.get(j-1)));}}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random random=new Random(0x12026090L);int start=Integer.parseInt(getScriptArgs()[2]),end=Integer.parseInt(getScriptArgs()[3]);
 try(PrintWriter out=new PrintWriter(new FileOutputStream(getScriptArgs()[0],start>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int cid=0;cid<6144;cid++){
 int family=cid<3072?0:cid<3840?1:cid<4096?2:3;
 int op=family==0?cid/1024:family==1?(cid-3072)/256:0,v=family==0?cid%1024:family==1?cid%256:family==2?cid-3840:cid-4096;
 byte[]pattern=new byte[256];random.nextBytes(pattern);
 String[]names={"ram","radio","timer","egu","dppi","rtc","nvic","normal_timer","aux","deviceid","boot"};
 long[]bases={0x23000000L,0x5302c000L,0x53029000L,0x53025000L,0x53022000L,0x5f99c000L,0xe000e000L,0x53028000L,0x5f9a2000L,0xfffe010L,0xf000L};
 byte[][]windows=new byte[names.length][];
 for(int j=0;j<names.length;j++){windows[j]=new byte[j==0?131072:j==9?8:j==10?16:4096];for(int i=0;i<windows[j].length;i++)windows[j][i]=pattern[(i+j*31)%256];}
 byte[]ram=windows[0],timer=windows[2],rtc=windows[5],aux=windows[8];
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
 ram[0x6e54]=(byte)(v%3);

 // Independent well-formed work submission destination and object.
 Arrays.fill(ram,0x2b18,0x2bc4,(byte)0);w32(ram,0x2bc0,new long[]{0,1,5,9,13,0x101}[v%6]);
 chain(ram,0x2bb0,new ArrayList<Integer>());chain(ram,0x2bb8,new ArrayList<Integer>());
 w32(ram,0x2ba8,v%4==0?0:0x23007840L);w32(ram,0x2bac,v%4==0?0:0x23007840L);w32(ram,0x7840,0);
 Arrays.fill(ram,0x2c94,0x2ca4,(byte)0);w32(ram,0x2c98,0x230205f9L);w32(ram,0x2c9c,0x23002b18L);w32(ram,0x2ca0,new long[]{0,1,2,4,8,16}[v%6]);
 if(family==3){
  int q=v%2==0?0x2b18:0x2170,work=0x7800;long queue=0x23000000L+q;
 for(int t:new int[]{q,0x29f8,0x5600,0x5700,0x5a00,0x5b00,0x5c00,0x5d00,0x6000,0x6100,0x6200,0x6300,0x7800,0x7a00})Arrays.fill(ram,t,t+0xac,(byte)0);
 w32(ram,q+0xa8,1|(v%4<2?0x100:0)|(v%2==0?4:0));w32(ram,0x7170,queue);w32(ram,0x7174,0x230029f8L);w32(ram,0x717c,queue);ram[0x7178]=0;
 ram[q+0xe]=(byte)new int[]{-3,0,1,4,8,127}[(v/7)%6];ram[0x560e]=1;ram[0x570e]=8;
 ArrayList<Integer> readyList=new ArrayList<>();readyList.add(q);if(v%4!=0)readyList.add(0x5600);if(v%3!=0)readyList.add(0x5700);readyList.sort((aa,bb)->Integer.compare(ram[aa+0xe],ram[bb+0xe]));
 w32(ram,0x7180,0x23000000L+readyList.get(0));w32(ram,0x7184,0x23000000L+readyList.get(readyList.size()-1));
 for(int j=0;j<readyList.size();j++){int t=readyList.get(j);ram[t+0xd]=(byte)128;w32(ram,t,j+1==readyList.size()?0x23007180L:0x23000000L+readyList.get(j+1));w32(ram,t+4,j==0?0x23007180L:0x23000000L+readyList.get(j-1));}
 ArrayList<Integer> timeouts=new ArrayList<>();if(v%3!=0)timeouts.add(0x5200);
 int[] queues={q+0xa0,q+0x98,0x7810,0x7a08};int[] waitThreads={0x6000,0x6200,0x5a00,0x5c00};
 for(int k=0;k<4;k++){int a=queues[k],n=(v+k)%3;w32(ram,a,n==0?0x23000000L+a:0x23000000L+waitThreads[k]);w32(ram,a+4,n==0?0x23000000L+a:0x23000000L+waitThreads[k]+256*(n-1));
  for(int j=0;j<n;j++){int t=waitThreads[k]+256*j;w32(ram,t,j+1==n?0x23000000L+a:0x23000000L+t+256);w32(ram,t+4,j==0?0x23000000L+a:0x23000000L+t-256);w32(ram,t+8,0x23000000L+a);ram[t+0xd]=(byte)new int[]{2,6,0x22,0x42}[(v/13+k)%4];ram[t+0xe]=(byte)(j==0?new int[]{-4,0,2}[(v+k)%3]:7);w32(ram,t+0x14,0xaabbccddL);w32(ram,t+0x8c,0x11223344);if((v+k+j)%2==0)timeouts.add(t+0x18);}
 }
 for(int a:new int[]{0x7810,0x7a08,0x7a48}){if(a==0x7a48){w32(ram,a,0x23000000L+a);w32(ram,a+4,0x23000000L+a);}w32(ram,a+8,v%3);w32(ram,a+12,2);}
 Arrays.fill(ram,0x2c60,0x2c78,(byte)0);if(v%2==0)timeouts.add(0x2c60);
 w32(ram,0xb48,timeouts.isEmpty()?0x23000b48L:0x23000000L+timeouts.get(0));w32(ram,0xb4c,timeouts.isEmpty()?0x23000b48L:0x23000000L+timeouts.get(timeouts.size()-1));
 for(int j=0;j<timeouts.size();j++){int t=timeouts.get(j);w32(ram,t,j+1==timeouts.size()?0x23000b48L:0x23000000L+timeouts.get(j+1));w32(ram,t+4,j==0?0x23000b48L:0x23000000L+timeouts.get(j-1));w32(ram,t+8,0xe06daf5L);w32(ram,t+16,new long[]{0,1,10,100,0x7fffffffL}[(v+j)%5]);w32(ram,t+20,0);}
 w32(ram,0x7194,new long[]{0,1,8,32,0xffffffffL}[(v/4)%5]);w32(ram,0x7190,new long[]{0,4,0xfffffffeL}[(v/20)%3]);w32(ram,0x7188,0);w32(ram,0x7198,v%11==0?1:0);w32(ram,0x2c78,v%9==0?0xfffffff0L:v%5);w32(ram,0x2c7c,v%17==0?0xffffffffL:0);w32(ram,0x2840,100);w32(ram,0x2844,0);w32(rtc,0x770,100+v*32+v%32);w32(rtc,0x774,0);ram[0x960]=(byte)new int[]{7,13,14,15}[v%4];w32(ram,0xab4,v%7==0?0xe080:0);
 long selected=v%7==0?0:0x23007800L;w32(ram,q+0x90,selected);w32(ram,q+0x94,selected==0?0:v%2==0?selected:0x23007840L);w32(ram,work,v%2==0?0:0x23007840L);w32(ram,0x7840,0);w32(ram,work+4,v%17==0?0x2302d901L:v%19==0?0x23026d29L:0x230205f9L);w32(ram,work+8,queue);w32(ram,work+12,new long[]{4,6,20,22,0x104,0x116}[(v/4)%6]);
 int shape=(v/8)%4;w32(ram,0x2bc8,shape==0?0:0x23007a00L);w32(ram,0x2bcc,shape==0?0:shape==1?0x23007a00L:0x23007a40L);w32(ram,0x7a00,shape<2?0:0x23007a40L);w32(ram,0x7a04,shape==1?0x23007800L:0x23007840L);w32(ram,0x7a40,0);w32(ram,0x7a44,shape==2?0x23007800L:0x23007840L);
 ram[0x71e4]=(byte)(v%19==0?1:0);w32(ram,0x6830,v%4);ram[0x6904]=(byte)((v/16)%3);ram[0x6901]=(byte)(v%7==0?1:0);ram[0x6902]=(byte)(v%11==0?1:0);for(int ch=0;ch<3;ch++){int read=v%4;ram[0x6834+ch]=(byte)read;ram[0x6838+ch]=(byte)((v+ch)%5==0?read:(read+1)%4);}w32(aux,0x548,new int[]{0,1,0x45,0x46}[v%4]);

 }
 if(family==3){ram[0x1fcd]=0;w32(ram,0x1fd8,0);w32(ram,0x1fdc,0);}
 for(int peer=0;peer<2;peer++){int stride=peer*0xf84,b=0x33e8+stride;int[] caps={32,16,16,32,32,96},ptrs={0x356c,0x376c,0x386c,0x396c,0x3b6c,0x3d6c};for(int c=0;c<6;c++){ram[b+0x154+c]=0;ram[b+0x15a+c]=0;ram[b+0x160+c]=(byte)caps[c];ram[b+0x166+c]=16;ram[b+0xa7+c]=1;w32(ram,b+0x16c+4*c,0x23000000L+stride+ptrs[c]);}ram[b+0x159]=(byte)(v%5==0?95:0);ram[b+0x157]=(byte)(v%7==0?31:0);}
 Arrays.fill(ram,0x1ad8,0x1b10,(byte)0);chain(ram,0x1af0,new ArrayList<Integer>());w32(ram,0x1afc,0);w32(ram,0x1b08,0x12345678L);
 ram[0x6598]=(byte)(v%3);w32(ram,0x659a,new long[]{0,1,255,65535}[(v/4)%4]);
 w32(ram,0xaf8,v%6==0?0:15);w32(ram,0xafc,15);ram[0x71df]=0;
 for(int j=0;j<4;j++){int slot=0x6e58+12*j;w32(ram,slot,0xe0707a4L);w32(ram,slot+4,0xe0707a4L);w32(ram,slot+8,0x00ff00ffL|((j&3)<<8));}
 w32(windows[4],0x500,v%2==0?15:0);w32(ram,0x6620,v%16==0?0x10114:0);ram[0x71e0]=0;ram[0x71e1]=(byte)v;w32(timer,0x510,5);
 for(int i=0;i<24;i++)ram[0x65e8+i]=0;ram[0x65e9]=4;ram[0x65ed]=1;w32(ram,0x65f0,50);
 ram[0x71c7]=(byte)((v/2)%3);ram[0x71d1]=(byte)((v/3)%3);ram[0x71dd]=(byte)((v/5)%3);ram[0x71dc]=(byte)((v/7)%3);ram[0x71d0]=(byte)((v/11)%3);
 ram[0x71de]=(byte)((v/13)%3);ram[0x71db]=(byte)(v%8);ram[0x71d9]=(byte)((v/16)%4);ram[0x71cf]=(byte)((v/16)%4);
 ram[0x71d8]=(byte)((v/8)%2);ram[0x71da]=(byte)((v/16)%2);ram[0x71d7]=(byte)v;ram[0x71d2]=(byte)v;
 ram[0x71d4]=(byte)(v%20);ram[0x71ce]=(byte)(v%20);ram[0x71ca]=(byte)v;ram[0x71c9]=(byte)(v%9);
 int[]commands={0x70,0x71,0xf1,0x72,0x7f,0xfb,0x15,0xb,0x33,0x95,4,0xff,0x73,0xf3,0xfa,0xc3};
 int cmd=commands[v%16],cls=new int[]{0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0,0,0xfe,7,0,0xfe,0xfe,0xfe,0xfe,0}[v%16];
 if(family==1){cls=0xfe;cmd=new int[]{0x70,0x71,0xf1}[op];}
 if(family==0&&v>=768){cls=new int[]{0,7,0xfe,16}[(v/64)%4];cmd=v%256;}
 ram[0x2d1c]=(byte)(v%5==0?2:1);ram[0x2d1d]=(byte)(new int[]{0,4,7,2}[(v/16)%4]<<5);ram[0x2d21]=(byte)new int[]{0,3,14,80}[(v/5)%4];ram[0x2d22]=(byte)cls;ram[0x2d23]=(byte)cmd;
 ram[0x71bb]=(byte)(v%11==0?0:1);ram[0x2c80]=(byte)(v%8);ram[0x71b2]=(byte)(v%2);ram[0x71bd]=(byte)((v/4)%4);
 ram[0x71b3]=(byte)(v%5);ram[0x71b4]=(byte)(v%128);ram[0x71b5]=(byte)(v%5);for(int j=0;j<3;j++)ram[0x2cb4+j]=(byte)((v+j)%6);
 for(int j=0;j<14;j++)ram[0x2d24+j]=(byte)((v/16)+j*17);ram[0x2d24]=(byte)((v/16)%8);
 if(cmd==0x72){ram[0x2d24]=(byte)(v%3==0?0:v>>8);ram[0x2d25]=(byte)(v%3==0?0:v);}
 if(cmd==0x7f)ram[0x2d25]=(byte)new int[]{0,1,40,41}[(v/16)%4];
 if(cls==0&&cmd==0xb)ram[0x2d24]=(byte)new int[]{1,3,5,7}[(v/16)%4];
 int sum=0;for(int j=0x2d1e;j<0x2d74;j++)sum^=ram[j]&255;ram[0x2d74]=(byte)(v%17==0?sum^1:sum);
 long entry=family==0?new long[]{0x2302604cL,0x23026090L,0x230205f8L}[op]:family==1?new long[]{0x2302048cL,0x23020510L,0x23020530L}[op]:family==2?0x23024db4L:0xe06d19cL;
 long incoming=family==1?0x23002d24L:family==2?new long[]{0,1,2,255,65535,0x10000L,0xffffffffL}[v%7]:family==3?(v%2==0?0x23002b18L:0x23002170L):0x12340000L+cid;
 long[]args={incoming,0,0,0,0};long eventValue=v%3==0?0:v%3==1?1:0x80000000L;
 final long initial=new long[]{0,32,128}[(v/3)%3];final int exception=v%5==0?0:60;boolean resultValid=false;
 if(cid<start||cid>=end)continue;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.registerCallOtherCallback("DataMemoryBarrier",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 for(int i=0;i<windows.length;i++)e.writeMemory(toAddr(bases[i]),windows[i]);
 for(int i=0;i<4;i++)e.writeRegister("r"+i,args[i]);e.writeMemoryValue(toAddr(0x2302f000L),4,args[4]);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),entry);
 boolean headerSeen=false;int steps=0,kind=0,mask=0,consumed=0;long boundary=0;long[]bargs=new long[4];Set<Long>polls=Set.of(0xe05cbdcL,0xe05cc70L,0xe05cf14L,0xe05ce86L,0xe05d066L);
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<100000){long pc=e.getExecutionAddress().getOffset();
 if(family==3&&pc==0xe06d1baL){if(headerSeen)break;headerSeen=true;}
 if(polls.contains(pc)){if(eventValue==0){kind=2;boundary=pc;bargs[0]=0x5302c220L;mask=1;break;}e.writeMemoryValue(toAddr(0x5302c220L),4,eventValue);consumed++;}
 if(Set.of(0xe0611ccL,0x2302d800L,0x2302d900L,0xe05be8cL,0x23025300L,0x230252a4L,0x23025954L,0x23025fe0L,0xe064288L).contains(pc)){kind=1;boundary=pc;bargs[0]=e.readRegister("r0").longValue();mask=pc==0xe064288L?7:1;if(mask==7){bargs[1]=e.readRegister("r1").longValue();bargs[2]=e.readRegister("r2").longValue();}break;}
 if(!e.step(monitor))throw new Exception("case"+cid+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=100000)throw new Exception("bound"+cid+" "+e.getExecutionAddress());
 StringBuilder row=new StringBuilder("{\"case\":"+cid+",\"family\":"+family+",\"op\":"+op+",\"entry\":"+entry+",\"args\":"+Arrays.toString(args)+",\"event_value\":"+eventValue+",\"consumed\":"+consumed+",\"initial_priority\":"+initial+",\"exception\":"+exception+",\"final_priority\":"+cpu.getBasePriority()+",\"kind\":"+kind+",\"boundary\":"+boundary+",\"boundary_args\":"+Arrays.toString(bargs)+",\"arg_mask\":"+mask+",\"result_valid\":"+resultValid+",\"result\":"+(resultValid&&boundary==0?e.readRegister("r0").longValue():0)+",\"steps\":"+steps);
 for(int i=0;i<windows.length;i++)row.append(",\"").append(names[i]).append("_before\":\"").append(zip(windows[i])).append("\",\"").append(names[i]).append("_after\":\"").append(zip(e.readMemory(toAddr(bases[i]),windows[i].length))).append("\"");row.append("}");out.println(row);
 }finally{e.dispose();}
 }}println("RECEIVER_VENDOR_FLOW_RANGE="+start+":"+end);
 }
}
