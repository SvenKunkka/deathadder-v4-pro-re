import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;import java.util.zip.GZIPOutputStream;
public class EmulateMouseMode4Rtos extends GhidraScript {
 String hex(byte[] b){return HexFormat.of().formatHex(b);}
 String zip(byte[] b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(GZIPOutputStream z=new GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[] b,int a,long v){for(int i=0;i<4;i++)b[a+i]=(byte)(v>>(i*8));}

 void w16(byte[] b,int a,int v){b[a]=(byte)v;b[a+1]=(byte)(v>>8);}
 public void run()throws Exception{
 byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
 if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48"))throw new Exception("hash");
 if(!Arrays.equals(image,getBytes(toAddr(0xe06c000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0xc6b0),getBytes(toAddr(0x23020000L),0xc6b0)))throw new Exception("mapping");
 Random rng=new Random(12025596);
 try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
 for(int test=0;test<512;test++){
 int kind=1,action=0;
 byte[] ram=new byte[65536],radio=new byte[4096],timer=new byte[1536],spim=new byte[16],nvic=new byte[4],clock=new byte[8];
 rng.nextBytes(ram);rng.nextBytes(radio);rng.nextBytes(timer);rng.nextBytes(spim);rng.nextBytes(nvic);rng.nextBytes(clock);
 w16(ram,0x2798,4);w16(ram,0x2794,new int[]{0,1,2,3,4,5}[test%6]);w32(ram,0x2a04,new int[]{0x18,0x19,0x1a}[test%3]);
 int event=kind==1?2:test%2==0?0:2;for(int i=0;i<8;i++)w32(timer,0x140+i*4,0);w32(timer,0x140+event*4,1);
 w16(ram,0x283c,5);w16(ram,0x27a2,new int[]{0,1,2,3,4}[test%5]);
 int counter=new int[]{0,1,511,512,2047,2048,4095,4096,8191,65535}[(test/5)%10];w16(ram,0x2a0a,counter);w16(ram,0x2972,test%3==0?counter:counter+1);ram[0x27c5]=1;
 w16(ram,0x2a0c,new int[]{0,1,98,65535}[(test/7)%4]);w32(ram,0x2a10,new long[]{0,198,199,200,0xffffffffL}[(test/9)%5]);
 w16(ram,0x29ae,new int[]{0,1,2,3,4,8,65535}[(test/3)%7]);w16(ram,0x29ac,new int[]{1,2,4,8}[(test/11)%4]);ram[0x76ee]=(byte)(test%3);ram[0x29f9]=1;ram[0x29e4]=(byte)(test%2);w32(ram,0x29c0,test%3);
 for(int i=0;i<5;i++){ram[0x26b9+i]=(byte)(test%3==0?255:test%3==1?85:1);ram[0x26be+i]=(byte)(test%4==0?255:test%4==1?170:test%4==2?1:0);}
 int nn=0;for(int i=0;i<37;i++){int v=255;if((ram[0x26b9+i/8]&(1<<(i%8)))!=0){ram[0x26c8+nn]=(byte)nn;ram[0x26ed+nn]=(byte)i;nn++;v=i;}ram[0x2712+i]=(byte)v;}ram[0x2737]=(byte)nn;
 if(kind==1){w16(ram,0x2794,3);w16(ram,0x2a0c,new int[]{99,100,65534}[test%3]);w32(ram,0x3864,new int[]{0,2,4,6}[test%4]);w16(ram,0x6b80,new int[]{0,1,2,999,65535}[test%5]);}

 byte[]rtc=new byte[4096];rng.nextBytes(rtc);
 for(int a:new int[]{0x2498,0x5600,0x5700,0x5800,0x5900,0x5c00,0x5d00}){Arrays.fill(ram,a,a+0xac,(byte)0);ram[a+0xe]=(byte)new int[]{-8,0,1,4,8,127}[(test+a/256)%6];}
 w32(ram,0x3864,new int[]{0,1,2,4,8,9}[test%6]);w32(ram,0x3860,0x23002498L);w32(ram,0x2528,test%3==0?0:0x23005400L);w32(ram,0x252c,test%3==0?0:0x23005420L);w32(ram,0x5400,0x23005420L);w32(ram,0x5420,0);w32(ram,0x2540,new int[]{1,3,5,9,13}[(test/6)%5]);
 int n=test%3;w32(ram,0x2530,n==0?0x23002530L:0x23005c00L);w32(ram,0x2534,n==0?0x23002530L:0x23005c00L+(n-1)*256);
 for(int i=0;i<n;i++){int a=0x5c00+i*256;w32(ram,a,i+1==n?0x23002530L:0x23005d00L);w32(ram,a+4,i==0?0x23002530L:0x23005c00L);w32(ram,a+8,0x23002530L);ram[a+0xd]=2;w32(ram,a+0x14,0x12345678);w32(ram,a+0x8c,0x12345678);}
 w32(ram,0x7654,0x23005800L);w32(ram,0x7658,0x23005900L);w32(ram,0x7664,0x23005800L);ram[0x765c]=0;ram[0x580e]=(byte)new int[]{-1,0,4,127}[(test/6)%4];ram[0x580d]=(byte)(test%5==0?4:0);
 w32(ram,0x7668,0x23005600L);w32(ram,0x766c,0x23005700L);w32(ram,0x5600,0x23005700L);w32(ram,0x5604,0x23007668L);w32(ram,0x5700,0x23007668L);w32(ram,0x5704,0x23005600L);ram[0x560d]=(byte)128;ram[0x570d]=(byte)128;ram[0x560e]=1;ram[0x570e]=8;
 ArrayList<Integer> ts=new ArrayList<>();ts.add(0x5200);for(int i=0;i<n;i++)if((test+i)%2==0)ts.add(0x5c18+i*256);w32(ram,0x25e0,0);w32(ram,0x25e4,0);if(test%2==0)ts.add(0x25e0);w32(ram,0x1578,0);w32(ram,0x157c,0);if(test%3!=0)ts.add(test%2==0?0:ts.size(),0x1578);
 w32(ram,0x14f4,0x23000000L+ts.get(0));w32(ram,0x14f8,0x23000000L+ts.get(ts.size()-1));for(int i=0;i<ts.size();i++){int a=ts.get(i);w32(ram,a,i+1==ts.size()?0x230014f4L:0x23000000L+ts.get(i+1));w32(ram,a+4,i==0?0x230014f4L:0x23000000L+ts.get(i-1));w32(ram,a+16,new long[]{0,1,10,100,0x7fffffffL}[(test+i)%5]);w32(ram,a+20,0);}
 w32(ram,0x767c,new long[]{0,1,10,0x7fffffffL,0x80000000L,0xffffffffL}[(test/4)%6]);w32(ram,0x7678,0);w32(ram,0x7680,test%11==0?1:0);w32(ram,0x25f8,test%5);w32(ram,0x25fc,0);w32(ram,0x21c0,100);w32(ram,0x21c4,0);w32(rtc,0x770,100+test*32+test%32);w32(rtc,0x774,0);ram[0x1304]=(byte)new int[]{7,13,14,15}[test%4];w32(ram,0x1458,0);
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field mf=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");mf.setAccessible(true);
 ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)mf.get(e.getEmulator());Object arm=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();
 java.lang.reflect.Field cf=arm.getClass().getDeclaredField("cpuState");cf.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)cf.get(arm);final long initial=new long[]{0,32,128}[test%3];cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(false);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw op){e.getEmulator().getMemState().setValue(op.getOutput(),cpu.getBasePriority());return true;}});
 e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw op){e.getEmulator().getMemState().setValue(op.getOutput(),60);return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int reg=0;reg<=12;reg++)e.writeRegister("r"+reg,0);
 for(String f:new String[]{"CY","ZR","NG","OV"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 e.writeRegister("r0",action);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x5f99c000L),rtc);e.writeMemory(toAddr(0x2302ec00L),new byte[0x400]);e.writeMemory(toAddr(0x5302c000L),radio);e.writeMemory(toAddr(0x53028000L),timer);e.writeMemory(toAddr(0x5f9c2000L),spim);e.writeMemory(toAddr(0xe000e208L),nvic);
 e.writeMemory(toAddr(0x5302e040L),clock);e.writeRegister(e.getPCRegister(),0x2302516cL);int steps=0,workCalls=0,startCalls=0;long stop=0;
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<50000){long pc=e.getExecutionAddress().getOffset();if(pc==0x0e0952ecL)workCalls++;if(pc==0x0e096a50L)startCalls++;if(!e.step(monitor))throw new Exception("case"+test+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}
 if(steps>=50000)throw new Exception("bound"+test+" pc"+e.getExecutionAddress());
 if(cpu.getBasePriority()!=initial)throw new Exception("basepri");
 out.println("{\"initial_priority\":"+initial+",\"final_priority\":"+cpu.getBasePriority()+",\"work_calls\":"+workCalls+",\"timer_start_calls\":"+startCalls+",\"rtc_before\":\""+zip(rtc)+"\",\"rtc_after\":\""+zip(e.readMemory(toAddr(0x5f99c000L),4096))+"\",\"pending\":"+stop+",\"args\":["+e.readRegister("r0")+","+e.readRegister("r1")+","+e.readRegister("r2")+","+e.readRegister("r3")+"],\"clock_before\":\""+hex(clock)+"\",\"clock_after\":\""+hex(e.readMemory(toAddr(0x5302e040L),8))+"\",\"case\":"+test+",\"kind\":"+kind+",\"action\":"+action+",\"before_gzip\":\""+zip(ram)+"\",\"after_gzip\":\""+zip(e.readMemory(toAddr(0x23000000L),65536))+"\",\"radio_before\":\""+hex(radio)+"\",\"radio_after\":\""+hex(e.readMemory(toAddr(0x5302c000L),4096))+"\",\"timer_before\":\""+hex(timer)+"\",\"timer_after\":\""+hex(e.readMemory(toAddr(0x53028000L),1536))+"\",\"spim_before\":\""+hex(spim)+"\",\"spim_after\":\""+hex(e.readMemory(toAddr(0x5f9c2000L),16))+"\",\"nvic_before\":\""+hex(nvic)+"\",\"nvic_after\":\""+hex(e.readMemory(toAddr(0xe000e208L),4))+"\",\"steps\":"+steps+"}");
 }finally{e.dispose();}
 }
 }println("MOUSE_MODE4_RTOS_ORIGINAL_CASES=512");
 }
}
