// Original mode1/2 RADIO handlers, all target instructions unchanged.
import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;import java.util.zip.GZIPOutputStream;
public class EmulateMouseRadioIrq extends GhidraScript {
 String hex(byte[] b){return HexFormat.of().formatHex(b);}
 String zip(byte[] b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(GZIPOutputStream z=new GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[] b,int a,long v){for(int i=0;i<4;i++)b[a+i]=(byte)(v>>(i*8));}

 void w16(byte[] b,int a,int v){b[a]=(byte)v;b[a+1]=(byte)(v>>8);}
 public void run()throws Exception{
 byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
 if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48"))throw new Exception("hash");
 if(!Arrays.equals(image,getBytes(toAddr(0xe06c000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0xc6b0),getBytes(toAddr(0x23020000L),0xc6b0)))throw new Exception("mapping");
 Random rng=new Random(12021704);
 try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
 for(int test=0;test<2944;test++){
 int mode=1+test%2,v=test/2,kind=v%8,j=v/8;byte[] ram=new byte[65536],radio=new byte[4096],timer=new byte[1536],nvic=new byte[4];
 rng.nextBytes(ram);rng.nextBytes(radio);rng.nextBytes(timer);rng.nextBytes(nvic);
 int state=0x1a,disabled=1,crc=1;
 if(kind==0)disabled=0;if(kind==1)disabled=2;if(kind==2)state=0x19;
 if(kind==3)state=new int[]{0,0x18,0x17,-1}[j%4];if(kind==5)crc=0;if(kind==6)crc=2;
 w16(ram,0x2798,mode);w32(ram,0x2a04,state);w32(radio,0x220,disabled);w32(radio,0x22c,crc);
 for(int i=0;i<4;i++)w32(radio,new int[]{0x204,0x208,0x20c,0x218}[i],new int[]{0,1,2,-1}[(j+i)%4]);
 w16(ram,0x2836,j%2);w16(ram,0x2794,new int[]{0,1,2,3,4,5,65535}[(j/2)%7]);
 w16(ram,0x29ac,new int[]{1,2,4,8,16,32,64,0,3,65535}[j%10]);
 w16(ram,0x283c,new int[]{0,1,3,5}[(j/3)%4]);w16(ram,0x2a0a,j%16);ram[0x2a25]=(byte)((j/5)%2);
 w16(ram,0x2a14+(j%2)*2,new int[]{0,1,2,3,4,65535}[(j/2)%6]);
 ram[0x29df]=(byte)new int[]{0,1,4,40,255}[j%5];ram[0x29d5+j%2]=(byte)new int[]{0,3,39,254,255}[j%5];
 ram[0x2a1e]=(byte)new int[]{0,1,6,7,8,255}[j%6];
 w32(ram,0x29c4,j%3==0?0:0x11223344);w32(ram,0x29cc,j%4==0?1:0);
 w32(timer,0x55c,new long[]{0,1,249,250,251,0xfffffff0L}[j%6]);
 int qid=new int[]{0,1,2,3,4,5,6,255,65535}[j%9];w16(ram,0x2a1a,qid);
 if(qid==3)w32(ram,0x6b68,0);
 for(int q=0;q<6;q++){ram[0x2adc+q]=(byte)new int[]{0,1,4,31,254,255}[(j+q)%6];ram[0x2ae2+q]=(byte)new int[]{0,1,5,32,255}[(j+q)%5];}
 if(test>=2048&&test<2688){
 int z=test-2048;mode=1;kind=8;w16(ram,0x2798,1);w32(ram,0x2a04,0x1a);w32(radio,0x220,1);w32(radio,0x22c,0);
 w16(ram,0x2794,3);w16(ram,0x29ac,new int[]{1,2,4,8,16,32,64,0,3,65535}[z%10]);
 w16(ram,0x2a0a,(z/10)%16);w16(ram,0x283c,3);ram[0x2a25]=1;w16(ram,0x2a14+(j%2)*2,new int[]{0,2,3,65535}[z/160]);
 }
 boolean handoff=test>=2688;
 if(handoff){
 int z=test-2688;mode=1+z%2;kind=9;w16(ram,0x2798,mode);w32(ram,0x2a04,0x1a);w32(radio,0x220,1);w32(radio,0x22c,1);
 int cls=1+(z/2)%5,seq=(z/10)%8;
 ram[0x2630]=(byte)new int[]{3,4,8,15}[(z/40)%4];ram[0x2632]=(byte)(cls*8+seq);ram[0x2633]=0;
 ram[0x2a3a+cls]=(byte)(seq^1);w32(ram,0x67ac,z%4<2?2:4);
 }
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 if(handoff){
     java.lang.reflect.Field machineField=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");
     machineField.setAccessible(true);
     ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)machineField.get(e.getEmulator());
     Object armLibrary=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();
     java.lang.reflect.Field cpuField=armLibrary.getClass().getDeclaredField("cpuState");cpuField.setAccessible(true);
     ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)cpuField.get(armLibrary);
     final long initialPriority=new long[]{0,0x20,0x80}[test%3];
     cpu.setBasePriority(initialPriority);cpu.setPrivileged(true);cpu.setThreadMode(false);
     final int[] cpuCalls={0,0};
     e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){
      public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw op){e.getEmulator().getMemState().setValue(op.getOutput(),cpu.getBasePriority());cpuCalls[0]++;return true;}
     });
     e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){
      public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw op){e.getEmulator().getMemState().setValue(op.getOutput(),60);cpuCalls[1]++;return true;}
     });

 }
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int reg=0;reg<=12;reg++)e.writeRegister("r"+reg,0);
 for(String f:new String[]{"CY","ZR","NG","OV"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x2302ec00L),new byte[0x400]);
 e.writeMemory(toAddr(0x5302c000L),radio);e.writeMemory(toAddr(0x53028000L),timer);e.writeMemory(toAddr(0xe000e208L),nvic);
 e.writeRegister(e.getPCRegister(),mode==1?0x230236acL:0x23022fbcL);int steps=0;
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<20000){if(!e.step(monitor))throw new Exception("case"+test+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}
 if(steps>=20000)throw new Exception("bound"+test+" pc"+e.getExecutionAddress());
 if(handoff){
 e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getPCRegister(),0x23022508L);
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<40000){if(!e.step(monitor))throw new Exception("handoff"+test+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}
 if(steps>=40000)throw new Exception("handoffbound"+test);
 }

 out.println("{\"case\":"+test+",\"kind\":"+kind+",\"mode\":"+mode+",\"before_gzip\":\""+zip(ram)+"\",\"after_gzip\":\""+zip(e.readMemory(toAddr(0x23000000L),65536))+"\",\"radio_before\":\""+hex(radio)+"\",\"radio_after\":\""+hex(e.readMemory(toAddr(0x5302c000L),4096))+"\",\"timer_before\":\""+hex(timer)+"\",\"timer_after\":\""+hex(e.readMemory(toAddr(0x53028000L),1536))+"\",\"nvic_before\":\""+hex(nvic)+"\",\"nvic_after\":\""+hex(e.readMemory(toAddr(0xe000e208L),4))+"\",\"steps\":"+steps+"}");
 }finally{e.dispose();}
 }
 }println("MOUSE_RADIO_IRQ_ORIGINAL_CASES=2944");
 }
}
