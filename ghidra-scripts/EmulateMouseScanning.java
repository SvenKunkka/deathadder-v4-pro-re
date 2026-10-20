import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateMouseScanning extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}long u32(EmulatorHelper e,long a){byte[]b=e.readMemory(toAddr(a),4);return (b[0]&255L)|(b[1]&255L)<<8|(b[2]&255L)<<16|(b[3]&255L)<<24;}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48")||!Arrays.equals(image,getBytes(toAddr(0xe06c000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0xc6b0),getBytes(toAddr(0x23020000L),0xc6b0)))throw new Exception("image/mapping");
 Random random=new Random(0x120952ecL);try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){for(int id=0;id<6144;id++){
 int op=id/1024,v=id%1024;byte[]ram=new byte[65536],rtc=new byte[4096],pattern=new byte[256];random.nextBytes(pattern);for(int i=0;i<ram.length;i++)ram[i]=pattern[i%256];for(int i=0;i<rtc.length;i++)rtc[i]=pattern[i%256];
 int work=0x67c0;int flags=new int[]{0,1,2,3,4,5,6,7,8,9,12,13,0xffffff00,0xffffff01,0xffffff02,0xffffffff}[v%16];long owner=new long[]{0,0x23005000L,0x23002498L}[(v/16)%3],queue=op==0?new long[]{0,0x23002498L,0x23005000L}[(v/48)%3]:0x23002498L;
 long chosen=(flags&1)!=0?owner:queue==0?owner:queue;int q=chosen==0?0x2498:(int)(chosen-0x23000000L),n=(v/16)%3;
 for(int a:new int[]{0x2498,0x5000,0x5600,0x5700,0x5800,0x5900,0x5c00,0x5d00}){Arrays.fill(ram,a,a+0xac,(byte)0);ram[a+0xe]=(byte)new int[]{-8,0,1,4,8,127}[(v+a/256)%6];}
 w32(ram,work+12,Integer.toUnsignedLong(flags));w32(ram,work+8,owner);
 for(int a:new int[]{0x2498,0x5000}){w32(ram,a+0x98,0x23000000L+a+0x98);w32(ram,a+0x9c,0x23000000L+a+0x98);w32(ram,a+0x90,v%3==0?0:0x23005400L);w32(ram,a+0x94,v%3==0?0:0x23005420L);w32(ram,a+0xa8,new long[]{0,1,3,5,9,13,0xffffffffL,17}[(v/8)%8]);}
 w32(ram,0x5400,0x23005420L);w32(ram,0x5420,0);
 w32(ram,q+0x98,n==0?0x23000000L+q+0x98:0x23005c00L);w32(ram,q+0x9c,n==0?0x23000000L+q+0x98:0x23005c00L+(n-1)*256);
 for(int i=0;i<n;i++){int a=0x5c00+i*256;w32(ram,a,i+1==n?0x23000000L+q+0x98:0x23005d00L);w32(ram,a+4,i==0?0x23000000L+q+0x98:0x23005c00L);w32(ram,a+8,0x23000000L+q+0x98);ram[a+0xd]=(byte)new int[]{2,6,0x22,0x42}[(v/16)%4];w32(ram,a+0x14,0x12345678);w32(ram,a+0x8c,0x12345678);}
 long current=v%3==0?0x23000000L+q:0x23005800L;w32(ram,0x7654,current);w32(ram,0x7658,0x23005900L);w32(ram,0x7664,v%11==0?0x23005900L:current);ram[0x765c]=0;ram[(int)(current-0x23000000L)+0xe]=(byte)new int[]{-1,0,4,127}[(v/32)%4];ram[(int)(current-0x23000000L)+0xd]=(byte)(v%5==0?4:0);
 if(v%3==0){w32(ram,0x7668,0x23007668L);w32(ram,0x766c,0x23007668L);}else{w32(ram,0x7668,0x23005600L);w32(ram,0x766c,0x23005700L);w32(ram,0x5600,0x23005700L);w32(ram,0x5604,0x23007668L);w32(ram,0x5700,0x23007668L);w32(ram,0x5704,0x23005600L);ram[0x560d]=(byte)128;ram[0x570d]=(byte)128;ram[0x560e]=1;ram[0x570e]=8;}
 ArrayList<Integer> ts=new ArrayList<>();if(v%3!=0)ts.add(0x5200);for(int i=0;i<n;i++){int a=0x5c18+i*256;if((v+i)%2==0)ts.add(a);}w32(ram,0x25e0,0);w32(ram,0x25e4,0);if(v%2==0)ts.add(0x25e0);
 w32(ram,0x14f4,ts.isEmpty()?0x230014f4L:0x23000000L+ts.get(0));w32(ram,0x14f8,ts.isEmpty()?0x230014f4L:0x23000000L+ts.get(ts.size()-1));for(int i=0;i<ts.size();i++){int a=ts.get(i);w32(ram,a,i+1==ts.size()?0x230014f4L:0x23000000L+ts.get(i+1));w32(ram,a+4,i==0?0x230014f4L:0x23000000L+ts.get(i-1));w32(ram,a+16,new long[]{0,1,10,100,0x7fffffffL}[(v+i)%5]);w32(ram,a+20,0);}
 w32(ram,0x767c,new long[]{0,1,10,0x7fffffffL,0x80000000L,0xffffffffL}[(v/4)%6]);w32(ram,0x7678,0);w32(ram,0x7680,v%11==0?1:0);w32(ram,0x25f8,v%5);w32(ram,0x25fc,0);w32(ram,0x21c0,100);w32(ram,0x21c4,0);w32(rtc,0x770,100+v*32+v%32);w32(rtc,0x774,0);ram[0x1304]=(byte)new int[]{7,13,14,15}[v%4];w32(ram,0x1458,0);

 // Original timer expiry receives an already unlinked timeout. Some fixtures
 // deliberately re-link it to test the original early-return guard.
 byte[]aux=new byte[16];random.nextBytes(aux);
 int target=0x1578;Arrays.fill(ram,target,target+0x38,(byte)0);
 long period=new long[]{0,1,-1,2,32,-2,-5,0x7fffffffL,0x80000000L,0x100000000L,Long.MAX_VALUE,Long.MIN_VALUE,0,1,32,625}[(v/4)%16];
 w32(ram,target+0x28,period);w32(ram,target+0x2c,period>>>32);w32(ram,target+0x30,new long[]{0,1,0xffffffffL,0x7fffffffL}[(v/64)%4]);
 long user=op==0?0:((v%8==0)?0x23022311L:0x23025f65L);w32(ram,target+0x20,user);
 int nw=(v/16)%3;w32(ram,target+0x18,nw==0?0x23001590L:0x23006000L);w32(ram,target+0x1c,nw==0?0x23001590L:0x23006000L+(nw-1)*256);
 for(int i=0;i<nw;i++){int z=0x6000+256*i;Arrays.fill(ram,z,z+0x90,(byte)0);w32(ram,z,i+1==nw?0x23001590L:0x23006100L);w32(ram,z+4,i==0?0x23001590L:0x23006000L);w32(ram,z+8,0x23001590L);ram[z+0xd]=(byte)new int[]{2,6,0x22,0x42}[(v/48)%4];ram[z+0xe]=(byte)new int[]{-2,0,3,8}[(v/24)%4];w32(ram,z+0x8c,0x11223344);}
 if(v%13==0){long last=((ram[0x14f8]&255L)|(ram[0x14f9]&255L)<<8|(ram[0x14fa]&255L)<<16|(ram[0x14fb]&255L)<<24);w32(ram,target,0x230014f4L);w32(ram,target+4,last);w32(ram,(int)(last-0x23000000L),0x23001578L);w32(ram,0x14f8,0x23001578L);w32(ram,target+16,50);}
 // optional application timer1B48 used by link-state callback.
 Arrays.fill(ram,0x1b48,0x1b80,(byte)0);w32(ram,0x1b60,0x23001b60L);w32(ram,0x1b64,0x23001b60L);
 if(op==3&&v%3!=0){long last=((ram[0x14f8]&255L)|(ram[0x14f9]&255L)<<8|(ram[0x14fa]&255L)<<16|(ram[0x14fb]&255L)<<24);w32(ram,0x1b48,0x230014f4L);w32(ram,0x1b4c,last);w32(ram,(int)(last-0x23000000L),0x23001b48L);w32(ram,0x14f8,0x23001b48L);w32(ram,0x1b58,80);}
 int state=new int[]{0,1,2,0x100,0xffff}[(v/2)%5];ram[0x6b7e]=(byte)state;ram[0x6b7f]=(byte)(state>>8);
 ram[0x7748]=(byte)((v/3)%2);ram[0x7747]=(byte)((v/6)%2);ram[0x7723]=(byte)((v/12)%3);ram[0x775e]=(byte)((v/36)%2);ram[0x775d]=(byte)((v/72)%2);ram[0x775c]=(byte)((v/144)%2);ram[0x7736]=(byte)((v/288)%2);
 if(v%9==0){w32(ram,0x25f8,0xfffffff0L);w32(ram,0x25fc,new long[]{0,0x7fffffffL,0xffffffffL}[(v/9)%3]);}

 byte[]radio=new byte[4096],timer=new byte[1536],nvic=new byte[4096],clock=new byte[8];
 for(byte[]b:new byte[][]{radio,timer,nvic,clock})for(int i=0;i<b.length;i++)b[i]=pattern[(i+17)%256];
 w32(radio,0x8a0,new long[]{0x80000000L,0x58120e,0x58090e,0}[(v/4)%4]);
 ram[0x27bb]=(byte)((v/4)%2);ram[0x297c]=(byte)((v/8)%2);ram[0x76ee]=(byte)((v/16)%2);ram[0x76ef]=(byte)(v%32);ram[0x774b]=(byte)((v/32)%2);
 w32(ram,0x2a04,new long[]{0,19,20,21,22,23,24,0xffffffffL}[(v/2)%8]);
 int dwell=new int[]{0,1,6,7,8,0xffff}[(v/16)%6],index=v%4,wait=new int[]{0,1,2,0xffff}[(v/96)%4],retry=new int[]{0,3,4,5,0xffff}[(v/32)%5];
 ram[0x2a4c]=(byte)index;ram[0x2a4d]=0;ram[0x2a4e]=(byte)dwell;ram[0x2a4f]=(byte)(dwell>>8);ram[0x2a50]=(byte)wait;ram[0x2a51]=(byte)(wait>>8);ram[0x2a52]=(byte)retry;ram[0x2a53]=(byte)(retry>>8);
 w32(ram,0x2998,new long[]{0,1,2,1000,0xffffffffL}[(v/8)%5]);
 System.arraycopy(ram,0x67c0,ram,0x3858,16);
 Arrays.fill(ram,0x1540,0x1578,(byte)0);w32(ram,0x1558,0x23001558L);w32(ram,0x155c,0x23001558L);w32(ram,0x1548,0xe096951L);w32(ram,0x1560,0x23022311L);w32(ram,0x1568,new long[]{0,1,32,0xffffffffL}[(v/4)%4]);w32(ram,0x156c,(v/4)%4==3?0xffffffffL:0);
 if((op==4&&v%13==0)||(op!=4&&v%3!=0)){long last=((ram[0x14f8]&255L)|(ram[0x14f9]&255L)<<8|(ram[0x14fa]&255L)<<16|(ram[0x14fb]&255L)<<24);w32(ram,0x1540,0x230014f4L);w32(ram,0x1544,last);w32(ram,(int)(last-0x23000000L),0x23001540L);w32(ram,0x14f8,0x23001540L);w32(ram,0x1550,20);}
 if(op==5){long selected=v%7==0?0:0x23003858L;w32(ram,0x2528,selected);w32(ram,0x252c,selected);w32(ram,0x2540,1|(v%4<2?0x100:0)|(v%9==0?4:0));w32(ram,0x3858,0);w32(ram,0x385c,0x23022621L);w32(ram,0x3860,0x23002498L);w32(ram,0x3864,new long[]{4,6,20,22}[(v/8)%4]);w32(ram,0x3868,0x23003868L);w32(ram,0x386c,0x23003868L);w32(ram,0x3870,v%2);w32(ram,0x3874,1);w32(ram,0x2548,0);w32(ram,0x254c,0);}
 target=0x1540;
 final long initial=new long[]{0,0x10,0x80}[(v/3)%3];final int exception=v%4==0?0:60;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x5f99c000L),rtc);e.writeMemory(toAddr(0x5f9c2000L),aux);e.writeMemory(toAddr(0x5302c000L),radio);e.writeMemory(toAddr(0x53028000L),timer);e.writeMemory(toAddr(0xe000e000L),nvic);e.writeMemory(toAddr(0x5302e040L),clock);e.writeMemoryValue(toAddr(0x2302e000L),4,queue);e.writeRegister("r0",op==5?0x23002498L:0x23000000L+target);e.writeRegister("r1",0x2302e000L);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),new long[]{0x23022620L,0x23022310L,0x2302253cL,0x23022cf0L,0xe096950L,0xe09504cL}[op]);
 int steps=0;long boundary=0,arg0=0;boolean headerSeen=false;while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<12000){long pc=e.getExecutionAddress().getOffset();if(op==5&&pc==0xe09506aL){if(headerSeen)break;headerSeen=true;}if(pc==0xe089d4cL||(op==5&&(pc==0xe09600cL||pc==0xe09628cL||(pc==0xe096220L&&e.readRegister("r0").longValue()==0x23002538L)))){boundary=pc;arg0=pc==0xe09600cL?0:e.readRegister("r0").longValue();break;}if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=12000)throw new Exception("bound"+id);
 out.println("{\"case\":"+id+",\"op\":"+op+",\"address\":"+(0x23000000L+target)+",\"queue\":"+queue+",\"queue_after\":"+u32(e,0x2302e000L)+",\"before_gzip\":\""+zip(ram)+"\",\"after_gzip\":\""+zip(e.readMemory(toAddr(0x23000000L),ram.length))+"\",\"rtc_before\":\""+zip(rtc)+"\",\"rtc_after\":\""+zip(e.readMemory(toAddr(0x5f99c000L),rtc.length))+"\",\"aux_before\":\""+zip(aux)+"\",\"aux_after\":\""+zip(e.readMemory(toAddr(0x5f9c2000L),aux.length))+"\",\"radio_before\":\""+zip(radio)+"\",\"radio_after\":\""+zip(e.readMemory(toAddr(0x5302c000L),radio.length))+"\",\"timer_before\":\""+zip(timer)+"\",\"timer_after\":\""+zip(e.readMemory(toAddr(0x53028000L),timer.length))+"\",\"nvic_before\":\""+zip(nvic)+"\",\"nvic_after\":\""+zip(e.readMemory(toAddr(0xe000e000L),nvic.length))+"\",\"clock_before\":\""+zip(clock)+"\",\"clock_after\":\""+zip(e.readMemory(toAddr(0x5302e040L),clock.length))+"\",\"initial_priority\":"+initial+",\"exception\":"+exception+",\"final_priority\":"+cpu.getBasePriority()+",\"boundary\":"+boundary+",\"arg0\":"+arg0+",\"return\":"+e.readRegister("r0").longValue()+",\"steps\":"+steps+"}");
 }finally{e.dispose();}
 }}println("MOUSE_SCANNING_CASES=6144");
 }
}
