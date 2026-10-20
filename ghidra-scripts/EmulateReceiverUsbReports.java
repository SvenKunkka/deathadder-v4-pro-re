import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverUsbReports extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}long u32(EmulatorHelper e,long a){byte[]b=e.readMemory(toAddr(a),4);return (b[0]&255L)|(b[1]&255L)<<8|(b[2]&255L)<<16|(b[3]&255L)<<24;}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random random=new Random(0x12026d28L);int start=Integer.parseInt(getScriptArgs()[2]),end=Integer.parseInt(getScriptArgs()[3]);try(PrintWriter out=new PrintWriter(new FileOutputStream(getScriptArgs()[0],start>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int id=0;id<2048;id++){
 int op=id/1024,v=id%256,mode=(id/256)%4;byte[]ram=new byte[131072],aux=new byte[4096],pattern=new byte[256];random.nextBytes(pattern);for(int i=0;i<ram.length;i++)ram[i]=pattern[i%256];for(int i=0;i<aux.length;i++)aux[i]=pattern[i%256];
 w32(ram,0x6830,new long[]{0,1,2,3,0xffffffffL}[(v/3)%5]);ram[0x71e4]=(byte)(v%17==0?0:1);ram[0x6904]=(byte)new int[]{0,1,2,255}[(v/16)%4];ram[0x6901]=(byte)(v%7==0?2:0);ram[0x6902]=(byte)(v%11==0?1:0);
 for(int ch=0;ch<3;ch++){int read=(v/(ch+1))%4;if((v+ch)%19==0)read=new int[]{4,7,255}[(v/19)%3];ram[0x6834+ch]=(byte)read;ram[0x6838+ch]=(byte)((v+ch)%5==0?read:(read+1)%4);}
 w32(aux,0x548,new long[]{0,1,0x45,0x46,0xffffffffL}[v%5]);
 final long initial=0;final int exception=0;if(id<start||id>=end)continue;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x5f9a2000L),aux);long entry=op==0?0x23026948L:0x23026d28L;
 e.writeRegister("r0",0x23002220L);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),entry);
 int steps=0;long boundary=0;StringJoiner calls=new StringJoiner(",");int count=0;
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<4000){long pc=e.getExecutionAddress().getOffset();if(pc==0xe064288L){
  long dev=e.readRegister("r0").longValue(),len=e.readRegister("r1").longValue(),buf=e.readRegister("r2").longValue();int ch=dev==0xe06f6a4L?0:dev==0xe06f690L?1:dev==0xe06f67cL?2:-1;if(ch<0||len!=(ch==1?16:8))throw new Exception("bad driver args");
  int result=mode==2?-13:mode==3&&((v+ch)%2==1)?-12:0;
  calls.add("{\"entry\":"+pc+",\"device\":"+dev+",\"length\":"+len+",\"buffer\":"+buf+",\"payload\":\""+hex(e.readMemory(toAddr(buf),(int)len))+"\",\"external_result\":"+(mode==0?"null":Integer.toString(result))+"}");count++;
  if(mode==0){boundary=pc;break;}
  if(mode==3){e.writeMemoryValue(toAddr(0x23006834L+ch),1,new int[]{3,255,7,0}[v%4]);e.writeMemoryValue(toAddr(0x23006904L),1,new int[]{0,1,255}[v%3]);e.writeMemoryValue(toAddr(0x23006830L),4,0xfffffffeL);}
  e.writeRegister("r0",Integer.toUnsignedLong(result));e.writeRegister(e.getPCRegister(),e.readRegister("lr").longValue()&~1L);continue;
 }
 if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}
 if(steps>=4000||count>3)throw new Exception("bound"+id);
 out.println("{\"case\":"+id+",\"entry\":"+entry+",\"mode\":"+mode+",\"v\":"+v+",\"ram_before\":\""+zip(ram)+"\",\"ram_after\":\""+zip(e.readMemory(toAddr(0x23000000L),ram.length))+"\",\"aux_before\":\""+zip(aux)+"\",\"aux_after\":\""+zip(e.readMemory(toAddr(0x5f9a2000L),aux.length))+"\",\"boundary\":"+boundary+",\"calls\":["+calls+"],\"steps\":"+steps+"}");
 }finally{e.dispose();}
 }}println("RECEIVER_USB_REPORTS_RANGE="+start+":"+end);
 }
}
