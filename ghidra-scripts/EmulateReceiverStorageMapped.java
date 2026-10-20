import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverStorageMapped extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}void h(byte[]b,int a,int x){b[a]=(byte)x;b[a+1]=(byte)(x>>>8);}
 int crc(byte[]b,int off,int n,int seed){int c=seed;for(int i=0;i<n;i++){c^=b[off+i]&255;for(int j=0;j<8;j++)c=((c<<1)^((c&128)!=0?7:0))&255;}return c;}
 void sum(byte[]b,int off){b[off]=(byte)crc(b,off+1,15,255);}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length)))throw new Exception("image/mapping");
 Random random=new Random(0x1205ec88L);int start=getScriptArgs().length>2?Integer.parseInt(getScriptArgs()[2]):0;
 try(PrintWriter out=new PrintWriter(new FileOutputStream(getScriptArgs()[0],start>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int id=0;id<1792;id++){if(getScriptArgs().length>3&&id>=Integer.parseInt(getScriptArgs()[3]))break;
 int op=id<1024?id/512:2+(id-1024)/256,v=op<2?id%512:(id-1024)%256;
 byte[]ram=new byte[131072],pattern=new byte[256];random.nextBytes(pattern);for(int j=0;j<ram.length;j++)ram[j]=pattern[j%256];
 int size=1024,pages=2+v%2,align=new int[]{16,32}[v/2%2],records=2+v/4%4;int first=size-(records+2)*align,ctx=0x1f30;long base=0x1db000L,key=new long[]{0xa001,0xa002,0x12345678,0xffffffffL}[v/8%4];
 byte[]storage=new byte[size*pages];Arrays.fill(storage,(byte)255);
 for(int page=0;page<pages;page++){
  int epoch=page+1;int hd=page*size+size-align,cl=page*size+size-2*align;
  storage[hd+1]=(byte)epoch;h(storage,hd+2,65535);w(storage,hd+4,0xffffffffL);w(storage,hd+8,0);w(storage,hd+12,0x4201);sum(storage,hd);
  storage[cl+1]=(byte)epoch;h(storage,cl+2,0);w(storage,cl+4,0xffffffffL);w(storage,cl+8,first);sum(storage,cl);
  for(int j=0;j<records;j++){
   int off=page*size+first+j*align,len=new int[]{0,1,8,9,47,70}[(v+j+page)%6];storage[off+1]=(byte)epoch;h(storage,off+2,len);w(storage,off+4,new long[]{0xa001,0xa002,0x12345678}[j%3]);
   byte[]data=new byte[Math.max(len,8)];random.nextBytes(data);if(len<=8)System.arraycopy(data,0,storage,off+8,8);else{int pos=32+j*128;w(storage,off+8,pos);System.arraycopy(data,0,storage,page*size+pos,len);}
   sum(storage,off);
   int corruption=(v/32)%8;if(j==0){if(corruption==1)storage[off]^=1;if(corruption==2){storage[off+1]^=1;sum(storage,off);}if(corruption==3)storage[hd]^=1;if(corruption==4){h(storage,hd+2,0);sum(storage,hd);}if(corruption==5)storage[cl]^=1;if(corruption==6){storage[cl+1]^=1;sum(storage,cl);}if(corruption==7){w(storage,cl+8,first+1);sum(storage,cl);}}
  }
 }
 Arrays.fill(ram,ctx,ctx+72,(byte)0);w(ram,ctx,base);w(ram,ctx+8,first);w(ram,ctx+12,0);w(ram,ctx+24,size);w(ram,ctx+28,pages);ram[ctx+33]=(byte)(v%19==0?0:1);w(ram,ctx+56,0xe06f6ccL);w(ram,ctx+64,align);
 int capacity=new int[]{0,1,7,8,9,46,47,69,70,100}[v/3%10],history=new int[]{0,1,2,3,5,10}[v/17%6];long destination=v%13==0?0:0x23009000L;
 int failAt=v%7==0?0:v%7==1?2:v%7==2?7:-1;long failure=new long[]{0xfffffff3L,0xfffffffbL,1,2}[v/11%4];
 int length=v%129,seed=v%256;final long initial=0;final int exception=0;if(id<start)continue;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});
 e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.registerCallOtherCallback("DataMemoryBarrier",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);


 byte[]mapped=new byte[0x200000];for(int j=0;j<mapped.length;j++)mapped[j]=pattern[j%256];System.arraycopy(image,0,mapped,0x54000,image.length);System.arraycopy(storage,0,mapped,(int)base,storage.length);
 long offset=new long[]{0,1,0x1db000,0x1db001,0x1ffff0,0x1fffff,0x200000,0xffffffffL}[v%8];long transfer=new long[]{0,1,15,16,17,32,70,256,0x200001,0xffffffffL}[v/8%10];
 e.writeMemory(toAddr(0xe000000L),mapped);e.writeMemory(toAddr(0x23000000L),ram);
 e.writeRegister("r0",op<2?0x23001f30L:0xe06f6ccL);e.writeRegister("r1",op<2?key:offset);e.writeRegister("r2",op<2?destination:op==4?transfer:0x23009000L);e.writeRegister("r3",op<2?capacity:transfer);
 e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);byte[]stack=new byte[8];w(stack,0,history);e.writeMemory(toAddr(0x2302f000L),stack);
 byte[]prior=Arrays.copyOf(pattern,16);h(prior,2,8);w(prior,4,key);if(op<2)e.writeMemory(toAddr(op==0?0x2302efc8L:0x2302efb8L),prior);
 e.writeRegister(e.getPCRegister(),new long[]{0xe05ec88L,0xe05ed64L,0xe067488L,0xe0674b4L,0xe0674f0L}[op]);
 int steps=0,calls=0;StringBuilder trace=new StringBuilder();
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<250000){long pc=e.getExecutionAddress().getOffset();
 if(pc==0xe067488L){calls++;}
 if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}
 if(steps>=250000)throw new Exception("bound"+id);
 out.println("{\"case\":"+id+",\"op\":"+op+",\"key\":"+key+",\"capacity\":"+capacity+",\"history\":"+history+",\"destination\":"+destination+",\"length\":"+length+",\"seed\":"+seed+",\"steps\":"+steps+",\"return\":"+(e.readRegister("r0").longValue()&0xffffffffL)+",\"prior\":\""+hex(prior)+"\",\"driver_reads\":"+calls+",\"offset\":"+offset+",\"transfer\":"+transfer+",\"mapped_after_sha256\":\""+hex(java.security.MessageDigest.getInstance("SHA-256").digest(e.readMemory(toAddr(0xe000000L),mapped.length)))+"\",\"ram_before\":\""+zip(ram)+"\",\"ram_after\":\""+zip(e.readMemory(toAddr(0x23000000L),ram.length))+"\",\"storage\":\""+zip(storage)+"\"}");
 }finally{e.dispose();}
 }}println("RECEIVER_STORAGE_MAPPED_BATCH_DONE start="+start+" end="+(getScriptArgs().length>3?getScriptArgs()[3]:"1792"));
 }
}
