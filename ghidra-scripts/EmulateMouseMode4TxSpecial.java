import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;import java.util.zip.GZIPOutputStream;
public class EmulateMouseMode4TxSpecial extends GhidraScript {
 String hex(byte[] b){return HexFormat.of().formatHex(b);}
 String zip(byte[] b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(GZIPOutputStream z=new GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[] b,int a,long v){for(int i=0;i<4;i++)b[a+i]=(byte)(v>>(i*8));}

 void w16(byte[] b,int a,int v){b[a]=(byte)v;b[a+1]=(byte)(v>>8);}
 public void run()throws Exception{
 byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
 if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48"))throw new Exception("hash");
 if(!Arrays.equals(image,getBytes(toAddr(0xe06c000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0xc6b0),getBytes(toAddr(0x23020000L),0xc6b0)))throw new Exception("mapping");
 Random rng=new Random(12024918);
 try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
 for(int test=0;test<256;test++){
 int kind=test<3072?0:1,j=test,action=3;
 byte[] ram=new byte[65536],radio=new byte[4096],timer=new byte[1536],spim=new byte[16],nvic=new byte[4];
 rng.nextBytes(ram);rng.nextBytes(radio);rng.nextBytes(timer);rng.nextBytes(spim);rng.nextBytes(nvic);
 w32(ram,0x2a04,0x18);w16(ram,0x2798,4);w16(ram,0x2794,new int[]{0,3,4}[test%3]);
 w16(ram,0x2836,test%2==0?0:2);w16(ram,0x283c,new int[]{0,1,2,3,4,5,6}[(test/2)%7]);
 w16(ram,0x29ac,new int[]{0,1,2,3,4,5,8,65535}[(test/14)%8]);w16(ram,0x27a2,test%5);w16(ram,0x2792,(test/5)%37);
 ram[0x2670]=(byte)((test/112)%3==0?1:0);ram[0x2671]=(byte)((test/336)%3==0?1:0);ram[0x2672]=(byte)new int[]{0,5,8,15,16,31,255}[(test/7)%7];
 ram[0x27c7]=(byte)(test%2);ram[0x27c8]=(byte)((test/2)%2);ram[0x2a26]=(byte)((test/4)%2);ram[0x29d0]=(byte)((test/8)%2);
 ram[0x29d1]=(byte)new int[]{0,3,4,15,16,255}[(test/3)%6];ram[0x29d3]=(byte)new int[]{0,3,4,15,16,255}[(test/5)%6];
 w16(ram,0x2a0a,test%2);ram[0x2a1e]=(byte)new int[]{0,1,7,8,255}[test%5];ram[0x2a2a]=(byte)new int[]{0,1,7,8,255}[(test/5)%5];
 w32(timer,0x55c,new long[]{0,99,100,101,249,250,251,349,350,351,0xffffffffL}[(test/11)%11]);
 int[] caps={32,5,16,32,32,96},bases={0x2b08,0x2d08,0x2d58,0x2e58,0x3058,0x3258};
 int mask=new int[]{0,1,2,4,8,16,32,63,3,6,10,34,40,48,62,21}[(test/7)%16];
 for(int q=0;q<6;q++){
 int rd=(test/16+q)%caps[q],wr=((mask>>q)&1)!=0?(rd+1)%caps[q]:rd;
 ram[0x2ad6+q]=(byte)wr;ram[0x2adc+q]=(byte)rd;ram[0x2ae2+q]=(byte)caps[q];ram[0x2ae8+q]=16;w32(ram,0x2af0+q*4,0x23000000L+bases[q]);
 int at=bases[q]+16*rd;ram[at+4]=(byte)(q==1?8:new int[]{0,3,5,8,15,16,31,255}[(test/128+q)%8]);ram[at+6]=(byte)((q<<3)|(test%8));
 }
 if(kind==1){for(int k=0;k<8;k++)w32(timer,0x140+4*k,0);w32(timer,0x144,1);w32(timer,0x544,new int[]{75,220,325,470}[test%4]);}
 kind=0;w16(ram,0x29ac,1);w16(ram,0x283c,new int[]{0,3,1,4}[test%4]);ram[0x2670]=0;ram[0x2671]=0;ram[0x29d0]=0;ram[0x2a26]=0;
 ram[0x29d1]=(byte)(test%3==0?3:0);ram[0x29d3]=(byte)(test%3==0?3:0);
 for(int q=0;q<6;q++)ram[0x2ad6+q]=ram[0x2adc+q];
 w32(timer,0x55c,new long[]{0,99,100,101,249,250,251,0xffffffffL}[(test/4)%8]);
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int reg=0;reg<=12;reg++)e.writeRegister("r"+reg,0);
 for(String f:new String[]{"CY","ZR","NG","OV"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 e.writeRegister("r0",action);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x2302ec00L),new byte[0x400]);e.writeMemory(toAddr(0x5302c000L),radio);e.writeMemory(toAddr(0x53028000L),timer);e.writeMemory(toAddr(0x5f9c2000L),spim);e.writeMemory(toAddr(0xe000e208L),nvic);
 e.writeRegister(e.getPCRegister(),kind==1?0x2302516cL:0x23024918L);int steps=0;
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<50000){if(!e.step(monitor))throw new Exception("case"+test+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}
 if(steps>=50000)throw new Exception("bound"+test+" pc"+e.getExecutionAddress());
 out.println("{\"case\":"+test+",\"kind\":"+kind+",\"action\":"+action+",\"before_gzip\":\""+zip(ram)+"\",\"after_gzip\":\""+zip(e.readMemory(toAddr(0x23000000L),65536))+"\",\"radio_before\":\""+hex(radio)+"\",\"radio_after\":\""+hex(e.readMemory(toAddr(0x5302c000L),4096))+"\",\"timer_before\":\""+hex(timer)+"\",\"timer_after\":\""+hex(e.readMemory(toAddr(0x53028000L),1536))+"\",\"spim_before\":\""+hex(spim)+"\",\"spim_after\":\""+hex(e.readMemory(toAddr(0x5f9c2000L),16))+"\",\"nvic_before\":\""+hex(nvic)+"\",\"nvic_after\":\""+hex(e.readMemory(toAddr(0xe000e208L),4))+"\",\"steps\":"+steps+"}");
 }finally{e.dispose();}
 }
 }println("MOUSE_MODE4_TX_SPECIAL_CASES=256");
 }
}
