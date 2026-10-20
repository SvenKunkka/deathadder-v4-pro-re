import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverWorkerRuntime extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}long u32(EmulatorHelper e,long a){byte[]b=e.readMemory(toAddr(a),4);return (b[0]&255L)|(b[1]&255L)<<8|(b[2]&255L)<<16|(b[3]&255L)<<24;}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random random=new Random(0x1206d19cL);int start=Integer.parseInt(getScriptArgs()[2]),end=Integer.parseInt(getScriptArgs()[3]);try(PrintWriter out=new PrintWriter(new FileOutputStream(getScriptArgs()[0],start>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int id=0;id<3072;id++){
 int op=id/512,v=id%512;byte[]ram=new byte[131072],rtc=new byte[4096],aux=new byte[4096],pattern=new byte[256];random.nextBytes(pattern);for(byte[]b:new byte[][]{ram,rtc,aux})for(int i=0;i<b.length;i++)b[i]=pattern[i%256];
 int q=v%2==0?0x2b18:0x2170,work=0x7800;long queue=0x23000000L+q;
 for(int t:new int[]{q,0x29f8,0x5600,0x5700,0x5a00,0x5b00,0x5c00,0x5d00,0x6000,0x6100,0x6200,0x6300,0x7800,0x7a00})Arrays.fill(ram,t,t+0xac,(byte)0);
 w32(ram,q+0xa8,1|(v%4<2?0x100:0)|(v%2==0?4:0));w32(ram,0x7170,queue);w32(ram,0x7174,0x230029f8L);w32(ram,0x717c,queue);ram[0x7178]=0;
 ram[q+0xe]=(byte)new int[]{-3,0,1,4,8,127}[(v/7)%6];ram[0x560e]=1;ram[0x570e]=8;
 ArrayList<Integer> readyList=new ArrayList<>();readyList.add(q);if(v%4!=0)readyList.add(0x5600);if(v%3!=0)readyList.add(0x5700);readyList.sort((aa,bb)->Integer.compare(ram[aa+0xe],ram[bb+0xe]));
 w32(ram,0x7180,0x23000000L+readyList.get(0));w32(ram,0x7184,0x23000000L+readyList.get(readyList.size()-1));
 for(int j=0;j<readyList.size();j++){int t=readyList.get(j);ram[t+0xd]=(byte)128;w32(ram,t,j+1==readyList.size()?0x23007180L:0x23000000L+readyList.get(j+1));w32(ram,t+4,j==0?0x23007180L:0x23000000L+readyList.get(j-1));}
 ArrayList<Integer> timeouts=new ArrayList<>();if(v%3!=0)timeouts.add(0x5200);
 int[] queues={q+0xa0,q+0x98,0x7810,0x7a08};int[] threads={0x6000,0x6200,0x5a00,0x5c00};
 for(int k=0;k<4;k++){int a=queues[k],n=(v+k)%3;w32(ram,a,n==0?0x23000000L+a:0x23000000L+threads[k]);w32(ram,a+4,n==0?0x23000000L+a:0x23000000L+threads[k]+256*(n-1));
  for(int j=0;j<n;j++){int t=threads[k]+256*j;w32(ram,t,j+1==n?0x23000000L+a:0x23000000L+t+256);w32(ram,t+4,j==0?0x23000000L+a:0x23000000L+t-256);w32(ram,t+8,0x23000000L+a);ram[t+0xd]=(byte)new int[]{2,6,0x22,0x42}[(v/13+k)%4];ram[t+0xe]=(byte)(j==0?new int[]{-4,0,2}[(v+k)%3]:7);w32(ram,t+0x14,0xaabbccddL);w32(ram,t+0x8c,0x11223344);if((v+k+j)%2==0)timeouts.add(t+0x18);}
 }
 for(int a:new int[]{0x7810,0x7a08,0x7a48}){if(a==0x7a48){w32(ram,a,0x23000000L+a);w32(ram,a+4,0x23000000L+a);}w32(ram,a+8,v%3);w32(ram,a+12,2);}
 Arrays.fill(ram,0x2c60,0x2c78,(byte)0);if(v%2==0)timeouts.add(0x2c60);
 w32(ram,0xb48,timeouts.isEmpty()?0x23000b48L:0x23000000L+timeouts.get(0));w32(ram,0xb4c,timeouts.isEmpty()?0x23000b48L:0x23000000L+timeouts.get(timeouts.size()-1));
 for(int j=0;j<timeouts.size();j++){int t=timeouts.get(j);w32(ram,t,j+1==timeouts.size()?0x23000b48L:0x23000000L+timeouts.get(j+1));w32(ram,t+4,j==0?0x23000b48L:0x23000000L+timeouts.get(j-1));w32(ram,t+8,0xe06daf5L);w32(ram,t+16,new long[]{0,1,10,100,0x7fffffffL}[(v+j)%5]);w32(ram,t+20,0);}
 w32(ram,0x7194,new long[]{0,1,8,32,0xffffffffL}[(v/4)%5]);w32(ram,0x7190,new long[]{0,4,0xfffffffeL}[(v/20)%3]);w32(ram,0x7188,0);w32(ram,0x7198,v%11==0?1:0);w32(ram,0x2c78,v%9==0?0xfffffff0L:v%5);w32(ram,0x2c7c,v%17==0?0xffffffffL:0);w32(ram,0x2840,100);w32(ram,0x2844,0);w32(rtc,0x770,100+v*32+v%32);w32(rtc,0x774,0);ram[0x960]=(byte)new int[]{7,13,14,15}[v%4];w32(ram,0xab4,v%7==0?0xe080:0);
 long selected=v%7==0?0:0x23007800L;w32(ram,q+0x90,selected);w32(ram,q+0x94,selected==0?0:v%2==0?selected:0x23007840L);w32(ram,work,v%2==0?0:0x23007840L);w32(ram,0x7840,0);w32(ram,work+4,v%13==0?0x230205f9L:0x23026d29L);w32(ram,work+8,queue);w32(ram,work+12,new long[]{4,6,20,22,0x104,0x116}[(v/4)%6]);
 int shape=(v/8)%4;w32(ram,0x2bc8,shape==0?0:0x23007a00L);w32(ram,0x2bcc,shape==0?0:shape==1?0x23007a00L:0x23007a40L);w32(ram,0x7a00,shape<2?0:0x23007a40L);w32(ram,0x7a04,shape==1?0x23007800L:0x23007840L);w32(ram,0x7a40,0);w32(ram,0x7a44,shape==2?0x23007800L:0x23007840L);
 ram[0x71e4]=(byte)(op<4||v%17==0?0:1);w32(ram,0x6830,v%4);ram[0x6904]=(byte)((v/16)%3);ram[0x6901]=(byte)(v%7==0?1:0);ram[0x6902]=(byte)(v%11==0?1:0);for(int ch=0;ch<3;ch++){int read=v%4;ram[0x6834+ch]=(byte)read;ram[0x6838+ch]=(byte)((v+ch)%5==0?read:(read+1)%4);}w32(aux,0x548,new int[]{0,1,0x45,0x46}[v%4]);
 long timeout=new long[]{-1L,0,1,2,32,-2,-33,0x7fffffffL,0x80000000L,0x100000000L,Long.MAX_VALUE,Long.MIN_VALUE}[v%12];
 long waitQueue=v%7==0?0:queue+0x98,savedPriority=new long[]{0,0x10,0x80}[(v/11)%3],wakeResult=new long[]{0,1,0xfffffff5L,0x12345678}[(v/9)%4],wakeData=0x12000000L+v;
 final long initial=new long[]{0,0x10,0x80}[(v/3)%3];final int exception=v%4==0?0:60;if(id<start||id>=end)continue;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x5f99c000L),rtc);e.writeMemory(toAddr(0x5f9a2000L),aux);long entry=new long[]{0xe06e3f4L,0xe06e1dcL,0xe06e460L,0xe06d19cL,0xe06d19cL,0xe06d19cL}[op];
 e.writeRegister("r0",op==0?queue+0xa0:op==2?0x23007188L:queue);e.writeRegister("r1",op==0?wakeResult:op==2?savedPriority:0);e.writeRegister("r2",op==0?wakeData:op==2?waitQueue:0);
 e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeMemoryValue(toAddr(0x2302f000L),8,timeout);e.writeMemoryValue(toAddr(0x2302f008L),4,0);e.writeRegister(e.getPCRegister(),entry);
 int steps=0;long boundary=0,arg0=0;boolean headerSeen=false;StringJoiner calls=new StringJoiner(",");int callCount=0;
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<18000){long pc=e.getExecutionAddress().getOffset();if(op>=3&&pc==0xe06d1baL){if(headerSeen)break;headerSeen=true;}
 if(pc==0xe064288L){long dev=e.readRegister("r0").longValue(),len=e.readRegister("r1").longValue(),buf=e.readRegister("r2").longValue();int ch=dev==0xe06f6a4L?0:dev==0xe06f690L?1:dev==0xe06f67cL?2:-1;if(ch<0||len!=(ch==1?16:8))throw new Exception("badUSB");int result=(v+ch)%2==0?0:-13;
 calls.add("{\"entry\":"+pc+",\"device\":"+dev+",\"length\":"+len+",\"buffer\":"+buf+",\"payload\":\""+hex(e.readMemory(toAddr(buf),(int)len))+"\",\"external_result\":"+(op==5?Integer.toString(result):"null")+"}");callCount++;
 if(op==5){e.writeRegister("r0",Integer.toUnsignedLong(result));e.writeRegister(e.getPCRegister(),e.readRegister("lr").longValue()&~1L);continue;}
 }
 if(pc==0x230205f8L||pc==0xe0611ccL||pc==0xe064288L){boundary=pc;arg0=e.readRegister("r0").longValue();break;}
 if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}
 if(steps>=18000||callCount>3)throw new Exception("bound"+id);
 out.println("{\"case\":"+id+",\"op\":"+op+",\"v\":"+v+",\"queue\":"+queue+",\"timeout\":\""+Long.toUnsignedString(timeout)+"\",\"wait_queue\":"+waitQueue+",\"saved_priority\":"+savedPriority+",\"wake_result\":"+wakeResult+",\"wake_data\":"+wakeData+",\"ram_before\":\""+zip(ram)+"\",\"ram_after\":\""+zip(e.readMemory(toAddr(0x23000000L),ram.length))+"\",\"rtc_before\":\""+zip(rtc)+"\",\"rtc_after\":\""+zip(e.readMemory(toAddr(0x5f99c000L),rtc.length))+"\",\"aux_before\":\""+zip(aux)+"\",\"aux_after\":\""+zip(e.readMemory(toAddr(0x5f9a2000L),aux.length))+"\",\"initial_priority\":"+initial+",\"exception\":"+exception+",\"final_priority\":"+cpu.getBasePriority()+",\"boundary\":"+boundary+",\"arg0\":"+arg0+",\"return\":"+e.readRegister("r0").longValue()+",\"calls\":["+calls+"],\"steps\":"+steps+"}");
 }finally{e.dispose();}
 }}println("RECEIVER_WORKER_RUNTIME_RANGE="+start+":"+end);
 }
}
