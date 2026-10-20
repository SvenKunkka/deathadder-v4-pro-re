import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverStorageMount extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}void h(byte[]b,int a,int x){b[a]=(byte)x;b[a+1]=(byte)(x>>>8);}
 int crc(byte[]b,int off,int n){int c=255;for(int i=0;i<n;i++){c^=b[off+i]&255;for(int j=0;j<8;j++)c=((c<<1)^((c&128)!=0?7:0))&255;}return c;}
 void sum(byte[]b,int off){b[off]=(byte)crc(b,off+1,15);}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random random=new Random(0x1205e6d4L);int start=getScriptArgs().length>2?Integer.parseInt(getScriptArgs()[2]):0;int end=getScriptArgs().length>3?Integer.parseInt(getScriptArgs()[3]):1088;
 try(PrintWriter out=new PrintWriter(new FileOutputStream(getScriptArgs()[0],start>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int id=0;id<end;id++){
 int v=id%512,ctx=0x1f30,size=4096,pages=2+v%2;long base=0x1db000L;
 int block=id<512?16:new int[]{1,2,4,8,16,32,0,33}[v%8];int slot=block==32?32:16,mode=v/8%16;
 if(id>=1024){block=16;slot=16;mode=15;}
 long params=id<512?0xe070394L:(v%41==0?0:0x23009200L);
 if(id>=1024)params=0xe070394L;
 byte[]ram=new byte[131072],pattern=new byte[256];random.nextBytes(pattern);for(int j=0;j<ram.length;j++)ram[j]=pattern[j%256];
 byte[]storage=new byte[size*pages];Arrays.fill(storage,(byte)255);int first=size-5*slot;
 for(int page=0;page<pages;page++){
  if(mode==0||(mode==1&&page!=0))continue;
  int hd=page*size+size-slot,cl=page*size+size-2*slot;
  storage[hd+1]=(byte)(page+1);h(storage,hd+2,65535);w(storage,hd+4,0xffffffffL);w(storage,hd+8,0);w(storage,hd+12,mode==4?0:mode==5?0x4202:0x4201);sum(storage,hd);
  if(mode==1||mode==2&&page==pages-1||mode==10&&page==0)continue;
  storage[cl+1]=(byte)(page+1);h(storage,cl+2,0);w(storage,cl+4,0xffffffffL);w(storage,cl+8,first);sum(storage,cl);
  for(int j=0;j<3;j++){
   int at=page*size+first+j*slot,len=new int[]{4,47,70}[(j+v)%3];storage[at+1]=(byte)(page+1);h(storage,at+2,len);w(storage,at+4,j==1?0xface0000L+page:0xa001+j);byte[]data=new byte[Math.max(len,8)];random.nextBytes(data);
   if(len<=8)System.arraycopy(data,0,storage,at+8,8);else{w(storage,at+8,32+j*128);System.arraycopy(data,0,storage,page*size+32+j*128,len);}sum(storage,at);
  }
  if(mode==6)storage[hd]^=1;if(mode==7)storage[cl]^=1;
  if(mode==8){storage[cl+1]^=1;sum(storage,cl);}
  if(mode==9){w(storage,cl+8,first+1);sum(storage,cl);}
  if(mode==11){h(storage,hd+2,0);sum(storage,hd);}
  if(mode==12){w(storage,hd+4,0x1234);sum(storage,hd);}
  if(mode==13&&page==0){w(storage,hd+12,0x4203);sum(storage,hd);}
  if(mode==14){int at=page*size+first;h(storage,at+2,0);w(storage,at+4,0xffffffffL);sum(storage,at);}
 }
 if(id>=1024){
  Arrays.fill(storage,(byte)255);
  for(int page=0;page<pages;page++){
   int hd=page*size+size-slot;storage[hd+1]=(byte)(page+1);h(storage,hd+2,65535);w(storage,hd+4,0xffffffffL);w(storage,hd+12,id>=1056?0x4202:0x4201);sum(storage,hd);
  }
  if(id<1056){
   int cl=size-2*slot;storage[cl+1]=1;h(storage,cl+2,0);w(storage,cl+4,0xffffffffL);w(storage,cl+8,size-3*slot);sum(storage,cl);
   int at=size+size-4*slot;storage[at+1]=2;h(storage,at+2,size-4*slot);w(storage,at+4,0xa001);w(storage,at+8,0);sum(storage,at);
  }
 }
 w(ram,ctx,base);w(ram,ctx+24,size);w(ram,ctx+28,v%61==0?0:v%59==0?1:pages);ram[ctx+32]=(byte)0xa5;ram[ctx+33]=(byte)(v%3==0?1:0);w(ram,ctx+56,0xe06f6ccL);w(ram,0x9200,block);ram[0x9205]=(byte)255;
 int failAt=new int[]{-1,0,1,3,10,30}[v/8%6];long failResult=new long[]{0xfffffffbL,1,2}[v/11%3];if(id>=1024)failAt=-1;final long initial=0;final int exception=0;if(id<start)continue;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});
 e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.registerCallOtherCallback("DataMemoryBarrier",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);



 byte[]mapped=new byte[0x200000];Arrays.fill(mapped,(byte)255);System.arraycopy(image,0,mapped,0x54000,image.length);System.arraycopy(storage,0,mapped,(int)base,storage.length);e.writeMemory(toAddr(0xe000000L),mapped);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeRegister("r0",0x23000000L+ctx);
 e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),0xe05e6d4L);
 byte[]before=storage.clone();int steps=0,calls=0,ios=0;StringBuilder trace=new StringBuilder();TreeMap<String,Integer> hits=new TreeMap<>();
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<1000000){long pc=e.getExecutionAddress().getOffset();
 for(long a:new long[]{0xe05e018L,0xe05e13cL,0xe05e4a8L,0xe05e9bcL,0xe05e908L,0xe05e9feL,0xe05e7e0L,0xe05ea0aL,0xe05e90eL})if(pc==a)hits.merge(Long.toHexString(pc),1,Integer::sum);
 if(pc==0xe067470L&&id>=512){e.writeRegister("r0",params);e.writeRegister(e.getPCRegister(),e.readRegister("lr").longValue()&~1L);continue;}
 if(pc==0xe06cdacL||pc==0xe06cea8L||pc==0xe067488L||pc==0xe0674b4L){
  long[]args=new long[4];for(int j=0;j<4;j++)args[j]=e.readRegister("r"+j).longValue()&0xffffffffL;
  boolean io=pc==0xe067488L||pc==0xe0674b4L;long result=0;String payload="";
  if(io){
   if(args[1]>=mapped.length||args[3]>mapped.length-args[1])result=0xffffffeaL;
   if(id>=512&&ios==failAt)result=pc==0xe067488L?0xfffffffbL:failResult;
   if(pc==0xe0674b4L)payload=hex(e.readMemory(toAddr(args[2]),(int)args[3]));
   if(id<512&&pc==0xe0674b4L&&((args[1]|args[3])&15)!=0)result=0xffffffeaL;
   ios++;
  }else result=v%7==0?0xfffffff0L:0;
  if(calls++>0)trace.append(",");trace.append("{\"entry\":").append(pc).append(",\"args\":").append(Arrays.toString(args)).append(",\"return\":").append(result).append(",\"payload\":\"").append(payload).append("\"}");
  if(!io||id>=512){
   if(io&&args[1]<mapped.length&&args[3]<=mapped.length-args[1]){
    if(pc==0xe067488L&&result==0)e.writeMemory(toAddr(args[2]),e.readMemory(toAddr(0xe000000L+args[1]),(int)args[3]));
    if(pc==0xe0674b4L)e.writeMemory(toAddr(0xe000000L+args[1]),HexFormat.of().parseHex(payload));
   }
   e.writeRegister("r0",result);e.writeRegister(e.getPCRegister(),e.readRegister("lr").longValue()&~1L);continue;
  }
 }
 if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}
 if(steps>=1000000)throw new Exception("bound"+id);
 StringBuilder hitjson=new StringBuilder();for(var hit:hits.entrySet()){if(hitjson.length()>0)hitjson.append(",");hitjson.append("\"").append(hit.getKey()).append("\":").append(hit.getValue());}
 out.println("{\"case\":"+id+",\"ctx\":"+ctx+",\"base\":"+base+",\"block\":"+block+",\"params\":"+params+",\"mode\":\""+(id<512?"mapped":"external-io")+"\",\"steps\":"+steps+",\"return\":"+(e.readRegister("r0").longValue()&0xffffffffL)+",\"hits\":{"+hitjson+"},\"trace\":["+trace+"],\"ram_before\":\""+zip(ram)+"\",\"ram_after\":\""+zip(e.readMemory(toAddr(0x23000000L),ram.length))+"\",\"mapped_after_sha256\":\""+hex(java.security.MessageDigest.getInstance("SHA-256").digest(e.readMemory(toAddr(0xe000000L),mapped.length)))+"\",\"storage_before\":\""+zip(before)+"\",\"storage_after\":\""+zip(e.readMemory(toAddr(0xe000000L+base),storage.length))+"\"}");
 }finally{e.dispose();}
 }}println("RECEIVER_STORAGE_MOUNT_BATCH_DONE start="+start+" end="+end);
 }
}
