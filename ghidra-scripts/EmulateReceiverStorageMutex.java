import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverStorageMutex extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}void h(byte[]b,int a,int x){b[a]=(byte)x;b[a+1]=(byte)(x>>>8);}
 int crc(byte[]b,int off,int n){int c=255;for(int i=0;i<n;i++){c^=b[off+i]&255;for(int j=0;j<8;j++)c=((c<<1)^((c&128)!=0?7:0))&255;}return c;}
 void sum(byte[]b,int off){b[off]=(byte)crc(b,off+1,15);}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random random=new Random(0x12025848L);int start=getScriptArgs().length>2?Integer.parseInt(getScriptArgs()[2]):0;int end=getScriptArgs().length>3?Integer.parseInt(getScriptArgs()[3]):128;
 try(PrintWriter out=new PrintWriter(new FileOutputStream(getScriptArgs()[0],start>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int id=0;id<end;id++){
 int op=id/512,v=id%512,ctx=0x1f30,size=4096,block=16,slot=16;long base=0x1db000L;
 byte[]ram=new byte[131072],pattern=new byte[256];random.nextBytes(pattern);for(int j=0;j<ram.length;j++)ram[j]=pattern[j%256];
 byte[]storage=new byte[7*size];Arrays.fill(storage,(byte)255);int first=size-5*slot,mode=v%8;
 for(int page=0;page<7;page++){
  if(mode==0||mode==1&&(page!=0&&page!=4))continue;
  int hd=page*size+size-slot,cl=page*size+size-2*slot;
  storage[hd+1]=(byte)(page+1);h(storage,hd+2,65535);w(storage,hd+4,0xffffffffL);w(storage,hd+8,0);w(storage,hd+12,mode==4?0:mode==5?0x4202:0x4201);sum(storage,hd);
  if(mode==1||mode==2&&(page==1||page==6))continue;
  storage[cl+1]=(byte)(page+1);h(storage,cl+2,0);w(storage,cl+4,0xffffffffL);w(storage,cl+8,first);sum(storage,cl);
  for(int j=0;j<3;j++){
   int at=page*size+first+j*slot,len=new int[]{4,47,70}[(j+v)%3];storage[at+1]=(byte)(page+1);h(storage,at+2,len);w(storage,at+4,j==1?0xface0000L+page:0xa001+j);byte[]data=new byte[Math.max(len,8)];random.nextBytes(data);
   if(len<=8)System.arraycopy(data,0,storage,at+8,8);else{w(storage,at+8,32+j*128);System.arraycopy(data,0,storage,page*size+32+j*128,len);}sum(storage,at);
  }
  if(mode==6)storage[hd]^=1;if(mode==7)storage[cl]^=1;
 }
 ram[0x1a1a]=(byte)(op==2?(v/256==0?0:1):(v%13==0?1:0));ram[0x1a1b]=(byte)(op==2?v%256:v%11==0?0:1);
 int entries=v%6;byte[]layout=new byte[40];for(int j=0;j<5;j++){w(layout,8*j,new int[]{0,1,2,512,0xffffffff}[(j+v/6)%5]);w(layout,8*j+4,new int[]{0,1,16,256,4096,0x80000000}[(j+v/30)%6]);}System.arraycopy(layout,0,ram,0x9400,40);
 long offset=new long[]{0,1,15,4095,4096,0x1db000,0x1df000,0x1fffff,0x200000,0xffffffffL}[v/6%10],queryindex=new long[]{0,1,2,511,512,0xffffffffL}[v/60%6];
 long device=op==2&&v%31==0?0:0xe06f6ccL;
 long entry=op==0?(v<256?0x23025848L:0x23025874L):op==1?0xe0673e8L:0xe06c6c0L;
 w(ram,0x7170,0x230020e0L);ram[0x20ee]=(byte)(v%32-16);final long initial=new long[]{0,0x20,0x40,0x80}[v%4];final int exception=0;if(id<start)continue;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});
 e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.registerCallOtherCallback("DataMemoryBarrier",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);



 byte[]mapped=new byte[0x200000];Arrays.fill(mapped,(byte)255);System.arraycopy(image,0,mapped,0x54000,image.length);System.arraycopy(storage,0,mapped,(int)base,storage.length);e.writeMemory(toAddr(0xe000000L),mapped);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeRegister("r0",device);e.writeRegister("r1",offset);e.writeRegister("r2",queryindex);e.writeRegister("r3",0x23009300L);
 e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),entry);
 byte[]before=storage.clone();int steps=0,calls=0;StringBuilder trace=new StringBuilder();TreeMap<String,Integer> hits=new TreeMap<>();
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<1000000){long pc=e.getExecutionAddress().getOffset();
 for(long a:new long[]{0xe06c6c0L,0xe0673e8L,0xe05e6d4L})if(pc==a)hits.merge(Long.toHexString(pc),1,Integer::sum);
 if(pc==0xe067478L&&op==1){
  byte[]word=new byte[4];w(word,0,0x23009400L);e.writeMemory(toAddr(e.readRegister("r1").longValue()),word);w(word,0,entries);e.writeMemory(toAddr(e.readRegister("r2").longValue()),word);e.writeRegister("r0",0x0e07039cL);e.writeRegister(e.getPCRegister(),e.readRegister("lr").longValue()&~1L);continue;
 }
 if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}
 if(steps>=1000000)throw new Exception("bound"+id);
 StringBuilder hitjson=new StringBuilder();for(var hit:hits.entrySet()){if(hitjson.length()>0)hitjson.append(",");hitjson.append("\"").append(hit.getKey()).append("\":").append(hit.getValue());}
 out.println("{\"case\":"+id+",\"op\":"+op+",\"entry\":"+entry+",\"ctx\":"+ctx+",\"base\":"+base+",\"entries\":"+entries+",\"offset\":"+offset+",\"index\":"+queryindex+",\"device\":"+device+",\"initial_priority\":"+initial+",\"final_priority\":"+cpu.getBasePriority()+",\"steps\":"+steps+",\"return\":"+(e.readRegister("r0").longValue()&0xffffffffL)+",\"hits\":{"+hitjson+"},\"trace\":["+trace+"],\"ram_before\":\""+zip(ram)+"\",\"ram_after\":\""+zip(e.readMemory(toAddr(0x23000000L),ram.length))+"\",\"mapped_after_sha256\":\""+hex(java.security.MessageDigest.getInstance("SHA-256").digest(e.readMemory(toAddr(0xe000000L),mapped.length)))+"\",\"storage_before\":\""+zip(before)+"\",\"storage_after\":\""+zip(e.readMemory(toAddr(0xe000000L+base),storage.length))+"\"}");
 }finally{e.dispose();}
 }}println("RECEIVER_STORAGE_MUTEX_BATCH_DONE start="+start+" end="+end);
 }
}
