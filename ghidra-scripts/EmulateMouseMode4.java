import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;import java.util.zip.GZIPOutputStream;
public class EmulateMouseMode4 extends GhidraScript {
 String hex(byte[] b){return HexFormat.of().formatHex(b);}
 String zip(byte[] b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(GZIPOutputStream z=new GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[] b,int a,long v){for(int i=0;i<4;i++)b[a+i]=(byte)(v>>(i*8));}

 void w16(byte[] b,int a,int v){b[a]=(byte)v;b[a+1]=(byte)(v>>8);}
 public void run()throws Exception{
 byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
 if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48"))throw new Exception("hash");
 if(!Arrays.equals(image,getBytes(toAddr(0xe06c000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0xc6b0),getBytes(toAddr(0x23020000L),0xc6b0)))throw new Exception("mapping");
 Random rng=new Random(12024650);
 try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
 for(int test=0;test<3072;test++){
 int kind=test<1536?0:test<2560?1:test<2816?2:3,j=kind==0?test:kind==1?test-1536:kind==2?test-2560:test-2816,v=j/12,action=0;
 byte[] ram=new byte[65536],radio=new byte[4096],timer=new byte[1536],spim=new byte[16],nvic=new byte[4];
 rng.nextBytes(ram);rng.nextBytes(radio);rng.nextBytes(timer);rng.nextBytes(spim);rng.nextBytes(nvic);
 w16(ram,0x2798,4);w16(ram,0x2836,v%2==0?0:2);w16(ram,0x278e,v%37);w32(ram,0x2a04,0x1a);
 w32(ram,0x6b68,0);w16(ram,0x2a1a,new int[]{0,1,2,3,4,5,6,255,65535}[v%9]);
 w32(radio,0x220,1);w32(radio,0x22c,1);w32(radio,0x218,0);w32(radio,0xed0,0x23002630L);
 w32(ram,0x29c4,v%3==0?0:1);w32(ram,0x29cc,v%4==0?1:0);w16(ram,0x283c,new int[]{0,1,2,3,4,5}[v%6]);
 w32(timer,0x55c,new long[]{0,165,166,249,250,415,416,499,500,0xffffffffL}[v%10]);
 ram[0x29e0]=(byte)(v&1);ram[0x29e4]=(byte)((v>>1)&1);ram[0x2a1e]=(byte)new int[]{0,1,6,7,8,255}[v%6];
 if(kind==0){
 int cat=j%12;for(int i=0;i<3;i++)w32(radio,0x204+i*4,new int[]{0,1,2,-1}[(v+i)%4]);
 if(cat==0)w32(radio,0x220,0);if(cat==1)w32(radio,0x220,2);
 if(cat==2||cat==3){w32(ram,0x2a04,0x19);w32(radio,0x218,cat==2?1:0);}
 if(cat==4)w32(ram,0x2a04,new int[]{0,0x18,0x17,-1}[v%4]);
 if(cat==5)w32(radio,0x22c,0);if(cat==6)w32(radio,0x22c,2);
 ram[0x2633]=(byte)(cat>=8&&cat<=10?0x1f:0x42);
 }else if(kind==1){
 v=j/8;int ev=j%8;for(int i=0;i<8;i++)w32(timer,0x140+i*4,2);w32(timer,0x140+ev*4,1);if((v&1)!=0&&ev<7)w32(timer,0x140+(ev+1)*4,1);
 int state=new int[]{0x18,0x19,0x1a,0}[v%4];w32(ram,0x2a04,state);
 int rate=new int[]{0,1,2,3,4,5,8,65535}[v%8];w16(ram,0x29ac,rate);ram[0x27c7]=(byte)((v/8)%2);
 int compare=new int[]{75,140,220,325,390,470,99}[v%7];w32(timer,0x544,compare);
 if(ev==1&&state==0x18&&(compare==75||compare==325||compare==470||(compare==220&&rate<=4)))w32(ram,0x2a04,0x19);
 w16(ram,0x283c,v%7);ram[0x2630]=(byte)(v%13);ram[0x2a20]=(byte)(v%3);
 w16(ram,0x2794,new int[]{0,1,2,3,4,5}[v%6]);w16(ram,0x27a2,new int[]{0,1,4}[v%3]);
 w16(ram,0x2a0c,new int[]{0,1,98,65535}[v%4]);w16(ram,0x29ae,0);w32(ram,0x2a10,new long[]{0,198,199,200,0xffffffffL}[v%5]);
 w16(ram,0x2a0a,new int[]{0,1,511,512,2047,2048,4095,4096,65535}[v%9]);
 ram[0x27c5]=(byte)(v&1);w16(ram,0x2972,v%2==0?1234:new int[]{0,1,511,512,2047,2048,4095,4096,65535}[v%9]);
 w32(ram,0x29b4,new long[]{0,1,200,250,0xffffffffL}[v%5]);w32(ram,0x29b8,new long[]{0,1,400,1000,0xfffffff0L}[v%5]);
 w32(ram,0x29bc,new long[]{0,1,2,3,4,5,0xffffffffL}[v%7]);w32(ram,0x29c4,new long[]{0,1,200,250,0xffffffffL}[(v/5)%5]);
 w32(ram,0x29c8,new long[]{0,200,250,0xffffffffL}[v%4]);w32(ram,0x29c0,v%4);ram[0x774b]=(byte)(v&1);
 ram[0x29f9]=1;ram[0x29e4]=(byte)(v%2);w16(ram,0x293c,new int[]{0,14,15,59,60,65535}[v%6]);
 }else if(kind==2){
 int state=new int[]{0,0x18,0x19,0x1a}[j%4];action=new int[]{0,1,3,6,8,255}[(j/4)%6];if(state==0x18&&action==3)state=0x19;
 w32(ram,0x2a04,state);ram[0x2630]=(byte)((j/24)%13);ram[0x2a20]=(byte)((j/8)%3);
 }else{
 int cls=1+j%5,seq=(j/5)%8;ram[0x2630]=(byte)new int[]{3,4,8,15}[(j/40)%4];ram[0x2632]=(byte)(cls*8+seq);ram[0x2633]=0;ram[0x2a3a+cls]=(byte)(seq^1);w32(ram,0x67ac,(j&1)==0?2:4);
 }
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 if(kind==3){
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
 e.writeRegister("r0",action);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x2302ec00L),new byte[0x400]);e.writeMemory(toAddr(0x5302c000L),radio);e.writeMemory(toAddr(0x53028000L),timer);e.writeMemory(toAddr(0x5f9c2000L),spim);e.writeMemory(toAddr(0xe000e208L),nvic);
 e.writeRegister(e.getPCRegister(),kind==1?0x2302516cL:kind==2?0x23024918L:0x23024650L);int steps=0;
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<50000){if(!e.step(monitor))throw new Exception("case"+test+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}
 if(steps>=50000)throw new Exception("bound"+test+" pc"+e.getExecutionAddress());
 if(kind==3)for(long entry:new long[]{0x23022508L,0x23022f70L}){
 e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getPCRegister(),entry);
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<100000){if(!e.step(monitor))throw new Exception("handoff"+test+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}
 if(steps>=100000)throw new Exception("handoffbound"+test);}
 out.println("{\"case\":"+test+",\"kind\":"+kind+",\"action\":"+action+",\"before_gzip\":\""+zip(ram)+"\",\"after_gzip\":\""+zip(e.readMemory(toAddr(0x23000000L),65536))+"\",\"radio_before\":\""+hex(radio)+"\",\"radio_after\":\""+hex(e.readMemory(toAddr(0x5302c000L),4096))+"\",\"timer_before\":\""+hex(timer)+"\",\"timer_after\":\""+hex(e.readMemory(toAddr(0x53028000L),1536))+"\",\"spim_before\":\""+hex(spim)+"\",\"spim_after\":\""+hex(e.readMemory(toAddr(0x5f9c2000L),16))+"\",\"nvic_before\":\""+hex(nvic)+"\",\"nvic_after\":\""+hex(e.readMemory(toAddr(0xe000e208L),4))+"\",\"steps\":"+steps+"}");
 }finally{e.dispose();}
 }
 }println("MOUSE_MODE4_ORIGINAL_CASES=3072");
 }
}
