import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;import java.util.zip.GZIPOutputStream;
public class EmulateReceiverRadioIrq extends GhidraScript{
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(GZIPOutputStream z=new GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w16(byte[]b,int a,int v){b[a]=(byte)v;b[a+1]=(byte)(v>>8);}void w32(byte[]b,int a,long v){for(int i=0;i<4;i++)b[a+i]=(byte)(v>>(8*i));}
 long u32(EmulatorHelper e,long a){byte[]b=e.readMemory(toAddr(a),4);return (b[0]&255L)|(b[1]&255L)<<8|(b[2]&255L)<<16|(b[3]&255L)<<24;}
 void queues(byte[]r,int peer,int variant){int b=0x33e8+peer*0xf84;int[]caps={32,16,16,32,32,96},ptr={0x356c,0x376c,0x386c,0x396c,0x3b6c,0x3d6c};for(int q=0;q<6;q++){r[b+0x154+q]=(byte)(q==variant%7?2:0);r[b+0x15a+q]=0;r[b+0x160+q]=(byte)caps[q];r[b+0x166+q]=16;w32(r,b+0x16c+4*q,0x23000000L+peer*0xf84+ptr[q]);}}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162"))throw new Exception("hash");
 if(!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("mapping");
 Random rng=new Random(12021000);int id=0;try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
 for(int op=0;op<3;op++)for(int v=0;v<(op==0?768:op==1?576:192);v++){
 byte[]r=new byte[65536],radio=new byte[4096],timer=new byte[2048],aux=new byte[2048];rng.nextBytes(r);System.arraycopy(image,0x1c854,r,0,0x1e08);
 for(int p=0;p<3;p++)queues(r,p,v);
 w16(r,0x3230,op==0&&v%31==0?v%2:3);w16(r,0x3234,4);w16(r,0x32ca,v%2);w16(r,0x32d0,v%6);w16(r,0x323e,v%4);w16(r,0x3228,v%40);
 w32(radio,0x400,0x12345678);w32(radio,0x718,30+v%200);w32(radio,0x22c,1);w32(radio,0x230,v%2);w32(timer,0x55c,new int[]{0,3199,3200,5280,5281,8000,8001,13280,13281}[v%9]);
 w32(r,0x3468,new int[]{11,12,13}[v%3]);w32(r,0x5370,13);r[0x3484]=(byte)((v/3)%3);r[0x3488]=(byte)(v%2);r[0x5397]=(byte)new int[]{0,1,7,255}[v%4];
 w16(r,0x31aa,v%4==0?2:0);r[0x31a8]=(byte)(v%23);r[0x31a7]=(byte)new int[]{0,9,255}[v%3];r[0x31a6]=(byte)(v%2==0?255:0);r[0x31a9]=(byte)(v%2);for(int i=0;i<23;i++)r[0x3e8+i]=(byte)i;
 int peer=(v%6==2||v%6==5)?2:0,ctx=0x33e8+peer*0xf84;
 if(op==0){int state=11+(v/6)%7;w32(r,ctx+0x80,state);int mask=(v/42)%16;w32(radio,0x204,mask&1);w32(radio,0x208,(mask>>1)&1);w32(radio,0x20c,(mask>>2)&1);w32(radio,0x218,(mask>>3)&1);w32(radio,0x220,1);}
 if(op==1)w32(timer,0x144,1);
 if(op==2){peer=0;ctx=0x33e8;w16(r,0x32d0,0);w32(r,ctx+0x80,12);w32(radio,0x218,1);w32(radio,0x220,1);}
 if(op!=1){int length=op==2?10:1+v%15;r[0x3050]=(byte)length;r[0x3051]=(byte)(0x80|((v%7+1)<<4)|(v%16));w16(r,ctx+0x96,v%8);r[ctx+0x9a]=(byte)new int[]{1,7,255}[v%3];r[ctx+0x9b]=(byte)(v%2==0?v%7+1:0);
 if(op==2){int cls=new int[]{0,1,3,5}[v%4];r[0x3052]=(byte)((cls<<3)|(v%7+1));r[ctx+0xb7+cls]=0;r[0x3053]=(byte)(cls==0?0x2b:0);r[0x3054]=(byte)(cls==3?0xb1:cls==5?0x5a:0x44);r[0x6578+cls]=0;r[0x6580+cls]=0;System.arraycopy(new byte[]{0,0,2,0,1,0},0,r,0x48c,6);w16(r,0x2c82,1);r[0x71e4]=1;for(int q=0;q<3;q++){r[0x6834+q]=0;r[0x6838+q]=0;r[0x2cb4+q]=0;}}
 int sum=0;for(int k=1;k<length;k++)sum+=r[0x3050+k]&255;r[0x3050+length]=(byte)-sum;
 if(op==0&&v%5==0)r[0x3050+length]++;if(op==0&&v%7==0)w32(radio,0x22c,0);if(op==0&&v%11==0)r[0x3050]=0;
 }
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int k=0;k<=12;k++)e.writeRegister("r"+k,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 e.writeMemory(toAddr(0x23000000L),r);e.writeMemory(toAddr(0x2302ed00L),new byte[768]);e.writeMemory(toAddr(0x5302c000L),radio);e.writeMemory(toAddr(0x53028000L),timer);e.writeMemory(toAddr(0x5300e000L),aux);e.writeMemoryValue(toAddr(0xe000e208L),4,0x12345678L);
 long requests=0;int steps=0,stages=op==2?2:1;for(int stage=0;stage<stages;stage++){
 e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),stage==1?0x23021be4L:op==1?0x23021bbcL:0x23020a00L);
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<40000){long pc=e.getExecutionAddress().getOffset();if(pc==0x23021c24L)requests|=0x10000000L;if(pc==0x2302233cL)requests|=0x08000000L;if(pc==0xe0622bcL)throw new Exception("unexpected USB boundary"+id);if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=40000)throw new Exception("bound"+id);
 }
 out.println("{\"case\":"+id+",\"op\":"+op+",\"variant\":"+v+",\"before_gzip\":\""+zip(r)+"\",\"radio_before_gzip\":\""+zip(radio)+"\",\"timer_before_gzip\":\""+zip(timer)+"\",\"after_gzip\":\""+zip(e.readMemory(toAddr(0x23000000L),65536))+"\",\"radio_after_gzip\":\""+zip(e.readMemory(toAddr(0x5302c000L),4096))+"\",\"timer_after_gzip\":\""+zip(e.readMemory(toAddr(0x53028000L),2048))+"\",\"aux_after_gzip\":\""+zip(e.readMemory(toAddr(0x5300e000L),2048))+"\",\"nvic_after\":"+u32(e,0xe000e208L)+",\"requests\":"+requests+",\"steps\":"+steps+"}");id++;
 }finally{e.dispose();}
 }
 }println("RECEIVER_RADIO_IRQ_CASES="+id);
 }
}
