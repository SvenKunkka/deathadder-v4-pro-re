import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverSettings extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}
 void h(byte[]b,int a,int x){b[a]=(byte)x;b[a+1]=(byte)(x>>>8);}
 int crc(byte[]b,int n){int c=65535;for(int i=0;i<n;i++){c^=(b[i]&255)<<8;for(int j=0;j<8;j++)c=((c<<1)^((c&0x8000)!=0?0x1021:0))&65535;}return c;}
 byte[] record(Random random,int n,int v,boolean first){byte[]b=new byte[n];random.nextBytes(b);h(b,0,n);long[]ids={0,0xffffffffL,0xfffffffeL,1,0x80,0x12345678L};w(b,first?31:11,ids[(v/(first?1:6))%ids.length]);h(b,n-2,crc(b,n-2));int kind=(v/(first?36:144))%4;if(kind==1)h(b,0,n+1);if(kind==2)b[n-1]^=1;return b;}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random random=new Random(0x12026f6cL);int start=getScriptArgs().length>2?Integer.parseInt(getScriptArgs()[2]):0;
 try(PrintWriter out=new PrintWriter(new FileOutputStream(getScriptArgs()[0],start>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int id=0;id<2304;id++){
 int op=id<1024?0:id<1536?1:id<2048?2:3,v=op==0?id:op==1?id-1024:op==2?id-1536:id-2048;
 byte[]ram=new byte[131072],rtc=new byte[4096],device=new byte[8],pattern=new byte[256];random.nextBytes(pattern);for(int j=0;j<ram.length;j++)ram[j]=pattern[j%256];System.arraycopy(image,0x1c854,ram,0,0x1e08);for(int j=0;j<rtc.length;j++)rtc[j]=pattern[(j+7)%256];
 byte[]a=record(random,70,v,true),b=record(random,47,v,false);System.arraycopy(a,0,ram,0x2db0,70);System.arraycopy(b,0,ram,0x2d80,47);
 ram[0x71ba]=(byte)new int[]{0,1,2,3,4,255,129,130}[v%8];h(ram,0x719e,new int[]{0,0,0,1,65535}[v/8%5]);
 w(device,0,new long[]{0x80000000L,0,0xffffffffL,0x12345678L}[v/12%4]);w(device,4,v/3%2==0?0xc000:0xc001);
 w(rtc,0x770,Integer.toUnsignedLong(random.nextInt()));w(rtc,0x774,0);
 if(op==0&&v>=768){w(device,0,0x80000000L);w(device,4,0xc000);w(a,31,v%2==0?0:128);h(a,0,70);h(a,68,crc(a,68));System.arraycopy(a,0,ram,0x2db0,70);}
 int length=v%129,seed=(v*65521)&65535;h(ram,0x9100,seed);long event=new long[]{0,1,2,3,4,5,0xffffffffL}[v%7];
 final long initial=new long[]{0,0x20,0x40,0x80}[v%4];final int exception=v%3==0?0:60;if(id<start)continue;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});
 e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.registerCallOtherCallback("DataMemoryBarrier",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);

 e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x5f99c000L),rtc);e.writeMemory(toAddr(0x0fffe010L),device);
 e.writeRegister("r0",op==2?0x23009000L:op==3?event:0);e.writeRegister("r1",length);e.writeRegister("r2",v%2==0?0:0x23009100L);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);
 e.writeRegister(e.getPCRegister(),new long[]{0x23026f6cL,0x23026ea4L,0x23020000L,0x23026f30L}[op]);
 int steps=0,reads=0;StringBuilder events=new StringBuilder();int evcount=0;
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<20000){long pc=e.getExecutionAddress().getOffset();
 if(pc==0xe05ed64L||pc==0xe05eb1cL){
  long[]args=new long[4];for(int j=0;j<4;j++)args[j]=e.readRegister("r"+j).longValue()&0xffffffffL;
  long result=new long[]{0,args[3],0xfffffff3L,0xfffffffeL,args[3]-1,1}[((v/5)+evcount)%6];
  byte[]effect=new byte[0];if(pc==0xe05ed64L){byte[]record=reads++==0?a:b;int n=v%11==0?0:v%11==1?record.length/2:record.length;effect=Arrays.copyOf(record,n);}
  if(evcount++>0)events.append(",");events.append("{\"entry\":").append(pc).append(",\"args\":").append(Arrays.toString(args)).append(",\"ram\":\"").append(zip(e.readMemory(toAddr(0x23000000L),ram.length))).append("\",\"raw_result\":").append(result).append(",\"read_effect\":\"").append(hex(effect)).append("\"}");
  if(effect.length>0)e.writeMemory(toAddr(args[2]),effect);e.writeRegister("r0",result);e.writeRegister(e.getPCRegister(),e.readRegister("lr").longValue()&~1L);continue;
 }
 if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}
 if(steps>=20000)throw new Exception("bound"+id);
 out.println("{\"case\":"+id+",\"op\":"+op+",\"length\":"+length+",\"seed\":"+(v%2==0?65535:seed)+",\"event\":"+event+",\"initial_priority\":"+initial+",\"final_priority\":"+cpu.getBasePriority()+",\"steps\":"+steps+",\"return\":"+(e.readRegister("r0").longValue()&0xffffffffL)+",\"events\":["+events+"],\"ram_before\":\""+zip(ram)+"\",\"ram_after\":\""+zip(e.readMemory(toAddr(0x23000000L),ram.length))+"\",\"rtc_before\":\""+zip(rtc)+"\",\"rtc_after\":\""+zip(e.readMemory(toAddr(0x5f99c000L),rtc.length))+"\",\"deviceid\":\""+hex(device)+"\"}");
 }finally{e.dispose();}
 }}println("RECEIVER_SETTINGS_CASES=2304");
 }
}
