import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;import java.util.zip.GZIPOutputStream;
public class EmulateReceiverRadioTimer extends GhidraScript{
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(GZIPOutputStream z=new GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w16(byte[]b,int a,int v){b[a]=(byte)v;b[a+1]=(byte)(v>>8);}void w32(byte[]b,int a,long v){for(int i=0;i<4;i++)b[a+i]=(byte)(v>>(8*i));}
 long u32(EmulatorHelper e,long a){byte[]b=e.readMemory(toAddr(a),4);return (b[0]&255L)|(b[1]&255L)<<8|(b[2]&255L)<<16|(b[3]&255L)<<24;}
 void queues(byte[]r,int peer,int variant){int b=0x33e8+peer*0xf84;int[]caps={32,16,16,32,32,96},ptr={0x356c,0x376c,0x386c,0x396c,0x3b6c,0x3d6c};for(int q=0;q<6;q++){r[b+0x154+q]=(byte)(q==variant%7?2:0);r[b+0x15a+q]=0;r[b+0x160+q]=(byte)caps[q];r[b+0x166+q]=16;w32(r,b+0x16c+4*q,0x23000000L+peer*0xf84+ptr[q]);}}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162"))throw new Exception("hash");
 if(!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("mapping");
 Random rng=new Random(12024800);int id=0;try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
 for(int event=-1;event<8;event++)for(int v=0;v<256;v++){
 byte[]r=new byte[65536],radio=new byte[4096],timer=new byte[2048],aux=new byte[2048];rng.nextBytes(r);System.arraycopy(image,0x1c854,r,0,0x1e08);
 for(int peer=0;peer<3;peer++)queues(r,peer,v);
 w16(r,0x3230,v%41==0?v%2:3);w16(r,0x3234,4);w16(r,0x32ca,v%2);w16(r,0x32d0,v%6);w16(r,0x323e,(v/6)%5);
 w32(radio,0x400,0x12345678);w32(radio,0x104,0x80000003L);w32(radio,0x100,0x80000004L);w32(radio,0xe30,Integer.toUnsignedLong(rng.nextInt()));w32(radio,0x8a0,new long[]{0x80000000L,0x58120eL,0x12345678L}[v%3]);
 w32(timer,0x55c,new int[]{3199,3200,5280,5281,8000,8001,13280,13281}[v%8]);
 if(event>=0)w32(timer,0x140+4*event,1);
 if(event>=0&&v%7==0)for(int other=event+1;other<8;other++)w32(timer,0x140+4*other,1); // priority, still one event consumed
 w32(r,0x3468,new int[]{11,12,13,0}[v%4]);w32(r,0x43ec,v%2==0?9:12);w32(r,0x5370,13);r[0x3484]=(byte)((v/3)%3);r[0x3488]=(byte)(v%2);r[0x5397]=(byte)new int[]{0,1,7,255}[v%4];
 w32(r,0x33e8,new int[]{2,3,4,0xffffffff}[(v/6)%4]);w32(r,0x52f0,new int[]{2,3,4}[(v/6)%3]);
 w16(r,0x3470,new int[]{0,98,99,100,65535,65534}[(v/6)%6]);w16(r,0x346e,65535-v);w32(r,0x3474,new long[]{0,198,199,200,0xffffffffL}[(v/6)%5]);w32(r,0x537c,new long[]{0,199,0xffffffffL}[v%3]);w16(r,0x5378,65535-v);
 int counter=new int[]{0,1,2047,2048,65535,65534}[(v/6)%6];w16(r,0x5376,counter);w16(r,0x33d6,v%2==0?counter:counter+1);r[0x325d]=(byte)(v%3);
 int interval=new int[]{0,1,2,4,8,16,32,64,3,255}[(v/3)%10];w16(r,0x341c,interval);
 int threshold=interval==2?3994:interval==4?1997:interval==8?999:interval==16?500:interval==32?250:interval==64?125:8090;w32(r,0x33dc,((long)(threshold+(v%3)-1)<<16)|(v*13));
 for(int i=0;i<2;i++){r[0x5349+i]=(byte)(v%4);for(int k=0;k<4;k++)r[0x534b+i*4+k]=(byte)(2+((v+k)%38)*2);}
 // Valid original map arrays, including sparse remapping and stale disabled slots.
 int count=0;for(int ch=0;ch<37;ch++){boolean enabled=ch%3==v%3; r[0x3132+ch]=(byte)(enabled?ch:255);if(enabled){r[0x30e8+count]=(byte)count;r[0x310d+count]=(byte)ch;count++;}}
 r[0x3157]=(byte)count;w16(r,0x30e6,v*7919);for(int i=0;i<5;i++)r[0x30de+i]=(byte)new int[]{0xff,0x55,0xaa,1,0x1f}[(i+v)%5];
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int k=0;k<=12;k++)e.writeRegister("r"+k,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 e.writeMemory(toAddr(0x23000000L),r);e.writeMemory(toAddr(0x2302ed00L),new byte[768]);e.writeMemory(toAddr(0x5302c000L),radio);e.writeMemory(toAddr(0x53028000L),timer);e.writeMemory(toAddr(0x5300e000L),aux);e.writeMemoryValue(toAddr(0xe000e208L),4,0x12345678L);
 e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),0x23021bbcL);
 int steps=0;long boundary=0,arg0=0;while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<40000){long pc=e.getExecutionAddress().getOffset();if(pc==0xe06d0d0L){boundary=pc;arg0=e.readRegister("r0").longValue();break;}if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=40000)throw new Exception("bound"+id);
 out.println("{\"case\":"+id+",\"event\":"+event+",\"variant\":"+v+",\"before_gzip\":\""+zip(r)+"\",\"radio_before_gzip\":\""+zip(radio)+"\",\"timer_before_gzip\":\""+zip(timer)+"\",\"after_gzip\":\""+zip(e.readMemory(toAddr(0x23000000L),65536))+"\",\"radio_after_gzip\":\""+zip(e.readMemory(toAddr(0x5302c000L),4096))+"\",\"timer_after_gzip\":\""+zip(e.readMemory(toAddr(0x53028000L),2048))+"\",\"aux_after_gzip\":\""+zip(e.readMemory(toAddr(0x5300e000L),2048))+"\",\"nvic_after\":"+u32(e,0xe000e208L)+",\"boundary\":"+boundary+",\"arg0\":"+arg0+",\"steps\":"+steps+"}");id++;
 }finally{e.dispose();}
 }
 }println("RECEIVER_RADIO_TIMER_CASES="+id);
 }
}
