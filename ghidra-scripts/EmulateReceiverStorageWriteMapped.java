import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverStorageWriteMapped extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}void h(byte[]b,int a,int x){b[a]=(byte)x;b[a+1]=(byte)(x>>>8);}
 int crc(byte[]b,int off,int n){int c=255;for(int i=0;i<n;i++){c^=b[off+i]&255;for(int j=0;j<8;j++)c=((c<<1)^((c&128)!=0?7:0))&255;}return c;}
 void sum(byte[]b,int off){b[off]=(byte)crc(b,off+1,15);}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random random=new Random(0x1205eb1cL);int start=getScriptArgs().length>2?Integer.parseInt(getScriptArgs()[2]):0;int end=getScriptArgs().length>3?Integer.parseInt(getScriptArgs()[3]):512;
 try(PrintWriter out=new PrintWriter(new FileOutputStream(getScriptArgs()[0],start>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int id=0;id<end;id++){
 int op=6,v=id%512;byte[]ram=new byte[131072],pattern=new byte[256];random.nextBytes(pattern);for(int j=0;j<ram.length;j++)ram[j]=pattern[j%256];
 int size=4096,pages=2+v%2,block=16,slot=block==32?32:16,index=op==7?v%3:0,ctx=0x1f30+72*(index==1?1:0);long base=index==1?0x1df000L:0x1db000L;
 byte[]storage=new byte[size*pages];Arrays.fill(storage,(byte)255);int first=size-5*slot;
 for(int page=0;page<pages;page++){
  int hd=page*size+size-slot,cl=page*size+size-2*slot;storage[hd+1]=(byte)(page+1);h(storage,hd+2,65535);w(storage,hd+4,0xffffffffL);w(storage,hd+8,0);w(storage,hd+12,0x4201);sum(storage,hd);
  storage[cl+1]=(byte)(page+1);h(storage,cl+2,0);w(storage,cl+4,0xffffffffL);w(storage,cl+8,first);sum(storage,cl);
  for(int j=0;j<3;j++){
   int at=page*size+first+j*slot,len=new int[]{4,47,70}[(j+v)%3];storage[at+1]=(byte)(page+1);h(storage,at+2,len);w(storage,at+4,j==1?0xface0000L+page:0xa001+j);byte[]data=new byte[Math.max(len,8)];random.nextBytes(data);
   if(len<=8)System.arraycopy(data,0,storage,at+8,8);else{w(storage,at+8,32+j*128);System.arraycopy(data,0,storage,page*size+32+j*128,len);}sum(storage,at);
  }
  int corrupt=(v/24)%5;if(corrupt==1)storage[hd]^=1;if(corrupt==2)storage[cl]^=1;if(corrupt==3){storage[cl+1]^=1;sum(storage,cl);}if(corrupt==4){h(storage,hd+2,0);sum(storage,hd);}
 }
 Arrays.fill(ram,ctx,ctx+72,(byte)0);w(ram,ctx,base);w(ram,ctx+8,v%4==0?128:first-slot);w(ram,ctx+12,0);w(ram,ctx+16,v%4==0?128:512);w(ram,ctx+20,0);w(ram,ctx+24,size);w(ram,ctx+28,pages);ram[ctx+32]=1;ram[ctx+33]=(byte)(v%17==0?0:1);w(ram,ctx+56,0xe06f6ccL);w(ram,ctx+60,0x23009200L);w(ram,ctx+64,slot);w(ram,0x9200,block);ram[0x9205]=(byte)255;
 int len=op>=6?new int[]{0,1,8,9,47,70,65536,4096}[v%8]:new int[]{0,1,7,8,15,16,17,31,32,33,47,70}[v%12];long key=0xa001+v%3,src=(op>=6&&v%13==0)?0:0x23009000L;long pos=64+(long)(v%pages)*0x100000000L;int page=v%pages;
 int failAt=new int[]{-1,0,1,3,10,30}[v/8%6];long failResult=new long[]{0xfffffffbL,1,2}[v/11%3];final long initial=0;final int exception=0;if(id<start)continue;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});
 e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.registerCallOtherCallback("DataMemoryBarrier",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);



 byte[]mapped=new byte[0x200000];Arrays.fill(mapped,(byte)255);System.arraycopy(image,0,mapped,0x54000,image.length);System.arraycopy(storage,0,mapped,(int)base,storage.length);e.writeMemory(toAddr(0xe000000L),mapped);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeRegister("r0",op==7?index:0x23000000L+ctx);e.writeRegister("r1",op>=6?key:src);e.writeRegister("r2",op>=6?src:op==0?pos&0xffffffffL:len);e.writeRegister("r3",op>=6?len:op==0?pos>>>32:page);
 e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);byte[]stack=new byte[8];w(stack,0,src);w(stack,4,len);e.writeMemory(toAddr(0x2302f000L),stack);
 e.writeRegister(e.getPCRegister(),new long[]{0xe05df2cL,0xe05dfa4L,0xe05dfe0L,0xe05e13cL,0xe05e1bcL,0xe05e4a8L,0xe05eb1cL,0x23025924L}[op]);
 byte[]before=storage.clone();int steps=0,calls=0;StringBuilder trace=new StringBuilder();
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<1000000){long pc=e.getExecutionAddress().getOffset();
 if(pc==0xe06cdacL||pc==0xe06cea8L){
  long[]args=new long[4];for(int j=0;j<4;j++)args[j]=e.readRegister("r"+j).longValue()&0xffffffffL;long result=v%7==0?0xfffffff0L:0;
  if(calls++>0)trace.append(",");trace.append("{\"entry\":").append(pc).append(",\"args\":").append(Arrays.toString(args)).append(",\"return\":").append(result).append("}");
  e.writeRegister("r0",result);e.writeRegister(e.getPCRegister(),e.readRegister("lr").longValue()&~1L);continue;
 }
 if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}
 if(steps>=1000000)throw new Exception("bound"+id);
 out.println("{\"case\":"+id+",\"op\":"+op+",\"ctx\":"+ctx+",\"base\":"+base+",\"index\":"+index+",\"block\":"+block+",\"erase\":"+(ram[0x9205]&255)+",\"len\":"+len+",\"key\":"+key+",\"src\":"+src+",\"position\":"+pos+",\"page\":"+page+",\"steps\":"+steps+",\"return\":"+(e.readRegister("r0").longValue()&0xffffffffL)+",\"trace\":["+trace+"],\"ram_before\":\""+zip(ram)+"\",\"ram_after\":\""+zip(e.readMemory(toAddr(0x23000000L),ram.length))+"\",\"mapped_after_sha256\":\""+hex(java.security.MessageDigest.getInstance("SHA-256").digest(e.readMemory(toAddr(0xe000000L),mapped.length)))+"\",\"storage_before\":\""+zip(before)+"\",\"storage_after\":\""+zip(e.readMemory(toAddr(0xe000000L+base),storage.length))+"\"}");
 }finally{e.dispose();}
 }}println("RECEIVER_STORAGE_WRITE_BATCH_DONE start="+start+" end="+end);
 }
}
