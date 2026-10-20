import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateMouseLifecycleRuntime extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}long u32(EmulatorHelper e,long a){byte[]b=e.readMemory(toAddr(a),4);return (b[0]&255L)|(b[1]&255L)<<8|(b[2]&255L)<<16|(b[3]&255L)<<24;}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48")||!Arrays.equals(image,getBytes(toAddr(0xe06c000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0xc6b0),getBytes(toAddr(0x23020000L),0xc6b0)))throw new Exception("image/mapping");
 Random random=new Random(0x120952ecL);try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){for(int id=0;id<3072;id++){
 int op=id/1024,v=id%1024;byte[]ram=new byte[65536],rtc=new byte[4096],pattern=new byte[256];random.nextBytes(pattern);for(int i=0;i<ram.length;i++)ram[i]=pattern[i%256];for(int i=0;i<rtc.length;i++)rtc[i]=pattern[i%256];

 byte[]aux=new byte[16];random.nextBytes(aux);long queue=0x23002498L;int target=0x67d0;
 for(int t:new int[]{0x2498,0x5000,0x2378,0x5600,0x5700,0x5a00,0x5b00,0x5c00,0x5d00,0x6000,0x6100,0x6200,0x6300})Arrays.fill(ram,t,t+0xac,(byte)0);
 for(int t:new int[]{0x1578,0x1b48}){Arrays.fill(ram,t,t+0x38,(byte)0);w32(ram,t+0x18,0x23000000L+t+0x18);w32(ram,t+0x1c,0x23000000L+t+0x18);}
 for(int t:new int[]{0x2498,0x5000}){w32(ram,t+0x98,0x23000000L+t+0x98);w32(ram,t+0x9c,0x23000000L+t+0x98);w32(ram,t+0xa0,0x23000000L+t+0xa0);w32(ram,t+0xa4,0x23000000L+t+0xa0);w32(ram,t+0xa8,1);}
 w32(ram,0x7654,0x23002498L);w32(ram,0x7658,0x23002378L);w32(ram,0x7664,0x23002498L);ram[0x765c]=0;
 ram[0x24a6]=(byte)new int[]{-3,0,1,4,8,127}[(v/7)%6];ram[0x560e]=1;ram[0x570e]=8;
 ArrayList<Integer> readyList=new ArrayList<>();readyList.add(0x2498);if(v%4!=0)readyList.add(0x5600);if(v%3!=0)readyList.add(0x5700);readyList.sort((aa,bb)->Integer.compare(ram[aa+0xe],ram[bb+0xe]));
 w32(ram,0x7668,0x23000000L+readyList.get(0));w32(ram,0x766c,0x23000000L+readyList.get(readyList.size()-1));
 for(int j=0;j<readyList.size();j++){int t=readyList.get(j);ram[t+0xd]=(byte)128;w32(ram,t,j+1==readyList.size()?0x23007668L:0x23000000L+readyList.get(j+1));w32(ram,t+4,j==0?0x23007668L:0x23000000L+readyList.get(j-1));}
 ArrayList<Integer> timeouts=new ArrayList<>();if(v%3!=0)timeouts.add(0x5200);
 int[] queues={0x2538,0x2530,0x5098,0x5e00};int[] threads={0x5c00,0x6000,0x6200,0x5a00};
 for(int k=0;k<4;k++){int q=queues[k],n=(v+k)%3;w32(ram,q,n==0?0x23000000L+q:0x23000000L+threads[k]);w32(ram,q+4,n==0?0x23000000L+q:0x23000000L+threads[k]+256*(n-1));
  for(int j=0;j<n;j++){int t=threads[k]+256*j;w32(ram,t,j+1==n?0x23000000L+q:0x23000000L+t+256);w32(ram,t+4,j==0?0x23000000L+q:0x23000000L+t-256);w32(ram,t+8,0x23000000L+q);ram[t+0xd]=(byte)new int[]{2,6,0x22,0x42}[(v/13+k)%4];ram[t+0xe]=(byte)(j==0?new int[]{-4,0,2}[(v+k)%3]:7);w32(ram,t+0x14,0xaabbccddL);w32(ram,t+0x8c,0x11223344);if((v+k+j)%2==0)timeouts.add(t+0x18);}
 }
 Arrays.fill(ram,0x25e0,0x25f8,(byte)0);if(v%2==0)timeouts.add(0x25e0);
 w32(ram,0x14f4,timeouts.isEmpty()?0x230014f4L:0x23000000L+timeouts.get(0));w32(ram,0x14f8,timeouts.isEmpty()?0x230014f4L:0x23000000L+timeouts.get(timeouts.size()-1));
 for(int j=0;j<timeouts.size();j++){int t=timeouts.get(j);w32(ram,t,j+1==timeouts.size()?0x230014f4L:0x23000000L+timeouts.get(j+1));w32(ram,t+4,j==0?0x230014f4L:0x23000000L+timeouts.get(j-1));w32(ram,t+8,0xe0959a5L);w32(ram,t+16,new long[]{0,1,10,100,0x7fffffffL}[(v+j)%5]);w32(ram,t+20,0);}
 w32(ram,0x767c,new long[]{0,1,8,32,0xffffffffL}[(v/4)%5]);w32(ram,0x7678,new long[]{0,4,0xfffffffeL}[(v/20)%3]);w32(ram,0x7670,0);w32(ram,0x7680,v%11==0?1:0);w32(ram,0x25f8,v%9==0?0xfffffff0L:v%5);w32(ram,0x25fc,v%17==0?0xffffffffL:0);w32(ram,0x21c0,100);w32(ram,0x21c4,0);w32(rtc,0x770,100+v*32+v%32);w32(rtc,0x774,0);ram[0x1304]=(byte)new int[]{7,13,14,15}[v%4];w32(ram,0x1458,v%7==0?0xe080:0);w32(ram,0x12fc,0x23028c09L);
 Arrays.fill(ram,0x67c0,0x67f0,(byte)0);w32(ram,0x67c4,0x23025df1L);w32(ram,0x67c8,new long[]{0,0x23002498L,0x23005000L}[(v/8)%3]);w32(ram,0x67cc,v%32);w32(ram,0x67e8,new long[]{0,0x23002498L,0x23005000L}[(v/24)%3]);
 {w32(ram,0x2540,new long[]{0,1,5,9,13,0x101}[(v/72)%6]);w32(ram,0x50a8,new long[]{0,1,5,9,13,0x101}[(v/144)%6]);}
 if(op==4){long selected=v%3==0?0:0x230067c0L;w32(ram,0x2528,selected);w32(ram,0x252c,selected);w32(ram,0x2540,1|(v%4<2?0x100:0)|(v%2==0?4:0));w32(ram,0x67c4,v%13==0?0x23022621L:0x23025df1L);w32(ram,0x67c8,0x23002498L);w32(ram,0x67cc,4);}
 int state=new int[]{0,1,2,0x100,0xffff}[(v/2)%5];ram[0x6b7e]=(byte)state;ram[0x6b7f]=(byte)(state>>8);
 for(int off:new int[]{0x7748,0x7747,0x7723,0x775e,0x775d,0x775c,0x7736})ram[off]=0;
 long timeout=new long[]{-1L,0,1,2,32,-2,-33,0x7fffffffL,0x80000000L,0x100000000L,Long.MAX_VALUE,Long.MIN_VALUE}[v%12];
 long waitQueue=v%7==0?0:0x23005e00L,savedPriority=new long[]{0,0x10,0x80}[(v/11)%3],wakeResult=new long[]{0,1,0xfffffff5L,0x12345678}[(v/9)%4],wakeData=0x12000000L+v;
 byte[]radio=new byte[4096],timer=new byte[1536],nvic=new byte[4096],clock=new byte[8];
 for(byte[]b:new byte[][]{radio,timer,nvic,clock})for(int i=0;i<b.length;i++)b[i]=pattern[(i+17)%256];
 if(op==5){
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
 }
 long inputQueue=new long[]{0,0x23002498L,0x23005000L}[(v/17)%3];queue=inputQueue;
 w32(ram,0x67cc,(v>=512?0xffffff00L:0)|(v%32));
 if((v&8)!=0&&v%3!=0){long last=((ram[0x14f8]&255L)|(ram[0x14f9]&255L)<<8|(ram[0x14fa]&255L)<<16|(ram[0x14fb]&255L)<<24);w32(ram,0x67d0,0x230014f4L);w32(ram,0x67d4,last);w32(ram,(int)(last-0x23000000L),0x230067d0L);w32(ram,0x14f8,0x230067d0L);w32(ram,0x67e0,25);w32(ram,0x67e4,0);}

 Arrays.fill(ram,0x5300,0x5338,(byte)0);target=0x5300;
 int n=v%3;w32(ram,0x5318,n==0?0x23005318L:0x23006400L);w32(ram,0x531c,n==0?0x23005318L:0x23006400L+(n-1)*256);
 for(int j=0;j<n;j++){int t=0x6400+j*256;Arrays.fill(ram,t,t+0x90,(byte)0);w32(ram,t,j+1==n?0x23005318L:0x23000000L+t+256);w32(ram,t+4,j==0?0x23005318L:0x23000000L+t-256);w32(ram,t+8,0x23005318L);ram[t+0xd]=(byte)new int[]{2,6,0x22,0x42}[(v/13)%4];ram[t+0xe]=(byte)new int[]{-4,0,2,10}[(v/5+j)%4];w32(ram,t+0x8c,0xaabbccddL);}
 if(v%5!=0){long first=((ram[0x14f4]&255L)|(ram[0x14f5]&255L)<<8|(ram[0x14f6]&255L)<<16|(ram[0x14f7]&255L)<<24);w32(ram,0x5300,first);w32(ram,0x5304,0x230014f4L);w32(ram,0x14f4,0x23005300L);w32(ram,(int)(first-0x23000000L)+4,0x23005300L);w32(ram,0x5310,7);}
 if(n>0&&v%7==0){long last=((ram[0x14f8]&255L)|(ram[0x14f9]&255L)<<8|(ram[0x14fa]&255L)<<16|(ram[0x14fb]&255L)<<24);w32(ram,0x6418,0x230014f4L);w32(ram,0x641c,last);w32(ram,(int)(last-0x23000000L),0x23006418L);w32(ram,0x14f8,0x23006418L);w32(ram,0x6428,19);w32(ram,0x642c,0);}
 w32(ram,0x5324,op==1?0x23028c55L:0);

 for(int t:new int[]{0x1540,0x15b0}){Arrays.fill(ram,t,t+0x38,(byte)0);w32(ram,t+0x18,0x23000000L+t+0x18);w32(ram,t+0x1c,0x23000000L+t+0x18);}
 target=op==0?0x1540:0x15b0;System.arraycopy(ram,0x5300,ram,target,0x38);
 for(int i=0;i<ram.length;i+=4){long word=(ram[i]&255L)|(ram[i+1]&255L)<<8|(ram[i+2]&255L)<<16|(ram[i+3]&255L)<<24;if(word==0x23005300L)w32(ram,i,0x23000000L+target);else if(word==0x23005318L)w32(ram,i,0x23000000L+target+0x18);}
 w32(ram,target+0x24,v%11==0?0x23028c55L:0);
 ram[0x76ee]=(byte)(v%2);ram[0x6b7b]=(byte)v;
 w32(ram,0x6b68,v%5==0?0:0x23025c2dL);ram[0x5002]=(byte)(v%7==0?1:3);ram[0x5003]=0;
 long reason=0x12340000L+v;
 final long initial=new long[]{0,0x10,0x80}[(v/3)%3];final int exception=v%4==0?0:60;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x5f99c000L),rtc);e.writeMemory(toAddr(0x5f9c2000L),aux);e.writeMemory(toAddr(0x5302c000L),radio);e.writeMemory(toAddr(0x53028000L),timer);e.writeMemory(toAddr(0xe000e000L),nvic);e.writeMemory(toAddr(0x5302e040L),clock);
 long entry=new long[]{0x23022d88L,0x23025c2cL,0x23025eb4L}[op];e.writeRegister("r0",op==0?reason:0x23005000L);
 e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),entry);
 int steps=0;long boundary=0,arg0=0;while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<12000){long pc=e.getExecutionAddress().getOffset();if(pc==0x23028c54L||pc==0xe089d4cL){boundary=pc;arg0=e.readRegister("r0").longValue();break;}if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=12000)throw new Exception("bound"+id);
 out.println("{\"reason\":"+reason+",\"radio_before\":\""+zip(radio)+"\",\"radio_after\":\""+zip(e.readMemory(toAddr(0x5302c000L),radio.length))+"\",\"timer_before\":\""+zip(timer)+"\",\"timer_after\":\""+zip(e.readMemory(toAddr(0x53028000L),timer.length))+"\",\"nvic_before\":\""+zip(nvic)+"\",\"nvic_after\":\""+zip(e.readMemory(toAddr(0xe000e000L),nvic.length))+"\",\"clock_before\":\""+zip(clock)+"\",\"clock_after\":\""+zip(e.readMemory(toAddr(0x5302e040L),clock.length))+"\",\"timeout\":\""+Long.toUnsignedString(timeout)+"\",\"wait_queue\":"+waitQueue+",\"saved_priority\":"+savedPriority+",\"wake_result\":"+wakeResult+",\"wake_data\":"+wakeData+",\"case\":"+id+",\"op\":"+op+",\"address\":"+(0x23000000L+target)+",\"queue\":"+queue+",\"queue_after\":"+0+",\"before_gzip\":\""+zip(ram)+"\",\"after_gzip\":\""+zip(e.readMemory(toAddr(0x23000000L),ram.length))+"\",\"rtc_before\":\""+zip(rtc)+"\",\"rtc_after\":\""+zip(e.readMemory(toAddr(0x5f99c000L),rtc.length))+"\",\"aux_before\":\""+zip(aux)+"\",\"aux_after\":\""+zip(e.readMemory(toAddr(0x5f9c2000L),aux.length))+"\",\"initial_priority\":"+initial+",\"exception\":"+exception+",\"final_priority\":"+cpu.getBasePriority()+",\"boundary\":"+boundary+",\"arg0\":"+arg0+",\"return\":"+e.readRegister("r0").longValue()+",\"steps\":"+steps+"}");
 }finally{e.dispose();}
 }}println("MOUSE_LIFECYCLE_RUNTIME_CASES=3072");
 }
}
