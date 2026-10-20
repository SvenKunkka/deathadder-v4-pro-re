import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;import java.util.zip.GZIPOutputStream;
public class EmulateReceiverLegacyRadio extends GhidraScript{
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(GZIPOutputStream z=new GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w16(byte[]b,int a,int v){b[a]=(byte)v;b[a+1]=(byte)(v>>8);}void w32(byte[]b,int a,long v){for(int i=0;i<4;i++)b[a+i]=(byte)(v>>(8*i));}
 long u32(EmulatorHelper e,long a){byte[]b=e.readMemory(toAddr(a),4);return (b[0]&255L)|(b[1]&255L)<<8|(b[2]&255L)<<16|(b[3]&255L)<<24;}
 void queues(byte[]r,int peer,int variant){int b=0x33e8+peer*0xf84;int[]caps={32,16,16,32,32,96},ptr={0x356c,0x376c,0x386c,0x396c,0x3b6c,0x3d6c};for(int q=0;q<6;q++){r[b+0x154+q]=(byte)(q==variant%7?2:0);r[b+0x15a+q]=0;r[b+0x160+q]=(byte)caps[q];r[b+0x166+q]=16;w32(r,b+0x16c+4*q,0x23000000L+peer*0xf84+ptr[q]);}}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random rng=new Random(0x12023498);int id=0;try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
 for(int op=0;op<4;op++)for(int v=0;v<new int[]{1536,512,256,384}[op];v++){
 int mode=(op==1||op==2)?2:1+v%2,peer=(v/2)%3,b=0x33e8+peer*0xf84;
 byte[]r=new byte[131072],radio=new byte[4096],timer=new byte[2048],aux=new byte[2048],pattern=new byte[256],stack=new byte[768];rng.nextBytes(pattern);for(int i=0;i<r.length;i++)r[i]=pattern[i%256];rng.nextBytes(stack);System.arraycopy(image,0x1c854,r,0,0x1e08);rng.nextBytes(radio);rng.nextBytes(timer);rng.nextBytes(aux);
 for(int p=0;p<3;p++)queues(r,p,v);w16(r,0x6274,peer);w16(r,0x32d0,mode==2?peer:(v/6)%6);w16(r,0x32ca,(v/6)%2);w16(r,0x3230,op==0&&v%17==0?v%2:3);w16(r,0x3234,mode);
 w16(r,b+0x96,(v/6)%6);r[b+0x9a]=(byte)new int[]{1,7,255}[(v/36)%3];r[b+0x9b]=(byte)(v%3==0?(v/4)%8:255);
 w32(r,0x33e8,new int[]{0,3,4,5}[(v/6)%4]);w16(r,0x341c,new int[]{0,1,2,3,4,8,16,32,64,65}[(v/24)%10]);w16(r,0x346e,(v/12)%16);w16(r,0x5376,(v/12)%32);r[0x348a]=(byte)((v/12)%2);r[0x5384]=(byte)((v/48)%2);r[0x5353]=10;r[0x5349]=(byte)new int[]{0,9,255}[(v/3)%3];r[0x534a]=9;
 w16(r,0x3478,3);w16(r,0x347a,3);w16(r,b+0x90,new int[]{0,2,3,65535}[(v/6)%4]);w16(r,b+0x92,4);
 int state=op==1?9:op==2?10:op==3?12:new int[]{7,8,11,12,13,14}[(v/6)%6];w32(r,b+0x80,state);
 w32(radio,0x204,(v/2)%3);w32(radio,0x208,(v/6)%3);w32(radio,0x20c,(v/18)%3);w32(radio,0x218,op==0?(v/36)%3:1);w32(radio,0x220,op==0?(v/108)%3:1);w32(radio,0x22c,op==0?(v/3)%3:1);w32(radio,0x230,(v/6)%3);
 r[0x3050]=(byte)(op==0&&v%5==0?0:9);r[0x3051]=(byte)(0x80|(((v/4)%8)<<4)|(v%16));
 // Exact notification queue, no waiters, includes full->purge->retry and wrap.
 int q=0x1b8c;w32(r,q,0x23001b8cL);w32(r,q+4,0x23001b8cL);w32(r,q+8,36);w32(r,q+12,5);w32(r,q+16,0x23015760L);w32(r,q+20,0x23015814L);w32(r,q+24,0x23015760L+(v%5)*36);w32(r,q+28,0x23015760L+(v%5)*36);w32(r,q+32,v%6);w32(r,0x7170,0x23004a00L);w32(r,0x717c,0x23004a00L);
 if(op==1){int hs=new int[]{0,2,3,6}[(v/4)%4];w16(r,b+0xc8,hs);w32(r,b+0x14,(v/16)%2);w16(r,b+6,65535);r[b+0xd4]=11;r[b+0xd5]=(byte)(v%7==0?128:0);r[b+0xd7]=(byte)(v%5==0?0:hs==0?0x12:hs==2?0x14:0x16);r[b+0xd8]=(byte)new int[]{0,1,2,4,8,15,128,143}[v%8];w16(r,0x3238,new int[]{1,2,4,15}[v%4]);w16(r,0x323e,(v/8)%5);w32(r,0x33e8,v%3==0?3:2);w32(r,0x436c,2);if(peer!=0&&v%2==0)w32(r,0x33fc,0);if(peer!=1&&v%2==0)w32(r,0x4380,0);r[b+0xa7]=(byte)new int[]{0,7,255}[v%3];}
 if(op==2){w16(r,0x3236,new int[]{0,1,2,4,8}[v%5]);w16(r,b+0x34,v%2);w32(radio,0x8a0,new long[]{0x80000000L,0x58120e,0x12345678}[v%3]);}
 if(op==3){int cls=(v/2)%6;r[0x3050]=(byte)(cls==2||cls==4?11:9);r[0x3052]=(byte)((cls<<3)|1);r[b+0xb7+cls]=(byte)(v%11==0?1:0);r[b+0x69]=(byte)(v%256);r[b+0x9d]=0;r[b+0xa6]=0;r[0x6578+cls]=0;r[0x6580+cls]=0;
 if(cls==0)r[0x3053]=(byte)new int[]{0x17,0x2c,0x2b,0x55}[(v/12)%4];else if(cls!=1){r[0x3053]=0;r[0x3054]=(byte)(cls==3?new int[]{0xa4,0xb1,0xac,0xab}[(v/12)%4]:cls==5?0x5a:0);}
 System.arraycopy(new byte[]{0,0,2,0,1,0},0,r,0x48c,6);w16(r,0x2c82,v%13==0?0:1);r[0x71e4]=1;r[0x2c88]=1;r[0x71e6]=3;r[0x71e3]=0;w32(r,0x690c,0x23006910L);for(int k=0;k<3;k++){r[0x6838+k]=0;r[0x6834+k]=0;r[0x2cb4+k]=0;}}
 long initial=new long[]{0,0x20,0x80}[v%3];long oldnvic=new long[]{0x12345678,0x08000000,0x10000000}[v%3];
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(false);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});
 e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),60);return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int k=0;k<=12;k++)e.writeRegister("r"+k,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 e.writeMemory(toAddr(0x23000000L),r);e.writeMemory(toAddr(0x2302ed00L),stack);e.writeMemory(toAddr(0x5302c000L),radio);e.writeMemory(toAddr(0x53028000L),timer);e.writeMemory(toAddr(0x5300e000L),aux);e.writeMemoryValue(toAddr(0xe000e208L),4,oldnvic);
 int steps=0,puts=0,purges=0,tailSteps=0;long requests=0,device=0;boolean pending=false;byte[]tail=new byte[24],pad=new byte[2];String irq="",continuation="";int result=new int[]{0,-1,-13,-134}[v%4];
 for(int stage=0;stage<(op==3?2:1);stage++){
 if(stage==1&&requests==0)throw new Exception("chain requires actual request");
 e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),stage==0?(mode==1?0x23023498L:0x23022a50L):0x23021be4L);
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<40000){long pc=e.getExecutionAddress().getOffset();if(pc==0x23021c24L)requests|=0x10000000L;
 if(pc==0xe06cbdcL){puts++;long mp=e.readRegister("r1").longValue();byte[]msg=e.readMemory(toAddr(mp),36);int type=msg[0]&255;System.arraycopy(msg,type==5?16:12,tail,0,type==5?20:24);if(type==1)System.arraycopy(msg,6,pad,0,2);}
 if(pc==0xe06cd54L)purges++;
 if(pc==0xe0622bcL){pending=true;device=e.readRegister("r0").longValue();break;}
 if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=40000)throw new Exception("bound"+id);if(stage==0)irq=zip(e.readMemory(toAddr(0x23000000L),r.length));
 }
 String after=zip(e.readMemory(toAddr(0x23000000L),r.length));if(pending){long ret=e.readRegister("lr").longValue()&~1L;e.writeRegister("r0",Integer.toUnsignedLong(result));e.writeRegister(e.getPCRegister(),ret);while(e.getExecutionAddress().getOffset()!=0x2302df00L&&tailSteps<30000){if(!e.step(monitor))throw new Exception("tail"+id+" "+e.getLastError());tailSteps++;}if(tailSteps>=30000)throw new Exception("tailbound");continuation=zip(e.readMemory(toAddr(0x23000000L),r.length));}
 out.println("{\"case\":"+id+",\"op\":"+op+",\"mode\":"+mode+",\"peer\":"+peer+",\"variant\":"+v+",\"before_gzip\":\""+zip(r)+"\",\"radio_before_gzip\":\""+zip(radio)+"\",\"timer_before_gzip\":\""+zip(timer)+"\",\"aux_before_gzip\":\""+zip(aux)+"\",\"irq_gzip\":\""+irq+"\",\"after_gzip\":\""+after+"\",\"radio_after_gzip\":\""+zip(e.readMemory(toAddr(0x5302c000L),4096))+"\",\"timer_after_gzip\":\""+zip(e.readMemory(toAddr(0x53028000L),2048))+"\",\"aux_after_gzip\":\""+zip(e.readMemory(toAddr(0x5300e000L),2048))+"\",\"nvic_before\":"+oldnvic+",\"nvic_after\":"+u32(e,0xe000e208L)+",\"requests\":"+requests+",\"steps\":"+steps+",\"puts\":"+puts+",\"purges\":"+purges+",\"opaque_tail\":\""+hex(tail)+"\",\"opaque_padding\":\""+hex(pad)+"\",\"initial_priority\":"+initial+",\"final_priority\":"+cpu.getBasePriority()+",\"pending\":"+pending+",\"device\":"+device+",\"driver_result\":"+result+",\"continuation_gzip\":\""+continuation+"\",\"tail_steps\":"+tailSteps+"}");id++;
 }finally{e.dispose();}
 }
 }println("RECEIVER_LEGACY_RADIO_CASES="+id);
 }
}
