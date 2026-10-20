// Entire original23022508 plus actual memcpy and work-submit fast returns.
import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;import java.util.zip.GZIPOutputStream;
public class EmulateMouseBusinessFlow extends GhidraScript {
 String hex(byte[] b){return HexFormat.of().formatHex(b);}
 String zip(byte[] b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(GZIPOutputStream z=new GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w16(byte[] b,int a,int v){b[a]=(byte)v;b[a+1]=(byte)(v>>8);}
 void w32(byte[] b,int a,long v){for(int i=0;i<4;i++)b[a+i]=(byte)(v>>(i*8));}
 public void run()throws Exception{
 byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
 if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48"))throw new Exception("hash");
 if(!Arrays.equals(image,getBytes(toAddr(0xe06c000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0xc6b0),getBytes(toAddr(0x23020000L),0xc6b0)))throw new Exception("mapping");
 Random rng=new Random(12022508);
 try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
 for(int test=0;test<1600;test++){
 int kind=test%12,v=test/12;byte[] ram=new byte[65536];rng.nextBytes(ram);
 int mode=new int[]{1,2,4}[v%3],cls=1+(v%5),len=new int[]{3,4,5,8,16,32,64,127}[v%8],seq=v%8;
 int index=0,expected=0,offset=0;boolean more=false,duplicate=false;
 switch(kind){
 case 0:mode=new int[]{0,3,5,65535}[v%4];break;
 case 1:len=new int[]{0,128,255,129}[v%4];break;
 case 2:duplicate=true;break;
 case 3:cls=0;break;
 case 4:more=true;break;
 case 5:break;
 case 6:index=1+v%31;expected=index;offset=v%(129-(len-3));more=true;break;
 case 7:index=1+v%31;expected=index;offset=v%(129-(len-3));break;
 case 8:index=1+v%31;expected=(index+1)%32;offset=v%256;break;
 case 9:index=1+v%31;expected=(index+1)%32;offset=v%256;len=(v&1)+1;break;
 case 10:cls=6+v%2;duplicate=true;break;
 case 11:len=3;index=1+v%31;expected=index;offset=128;break;
 }
 if(test>=1536){kind=12;v=test-1536;mode=4;cls=0;len=new int[]{1,2,3,127}[v%4];}
 w16(ram,0x2798,mode);ram[0x2a96]=(byte)len;ram[0x2a98]=(byte)((v%4)*64+cls*8+seq);
 ram[0x2a3a+cls]=(byte)(duplicate?seq:(seq+1)%8);
 ram[0x2a99]=(byte)(index|(more?128:0)|((v%4)<<5));
 if(cls==0){ram[0x2a99]=(byte)new int[]{0x28,0x29,0x42}[(v/3)%3];ram[0x29e0]=(byte)(v&1);}
 ram[0x6b50+cls]=(byte)expected;ram[0x6b58+cls]=(byte)offset;
 w32(ram,0x67ac,((long)(v*0x101)&0xfffffff8L)|new int[]{2,4,6}[v%3]);
 if((kind==4||kind==6||kind==8||kind==9)&&(v&1)!=0)w32(ram,0x67ac,0);
 w16(ram,0x6b8a,new int[]{0,29999,30000,65534,65535}[v%5]);w16(ram,0x6b88,v*517);
 EmulatorHelper emu=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
     java.lang.reflect.Field machineField=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");
     machineField.setAccessible(true);
     ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)machineField.get(emu.getEmulator());
     Object armLibrary=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();
     java.lang.reflect.Field cpuField=armLibrary.getClass().getDeclaredField("cpuState");cpuField.setAccessible(true);
     ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)cpuField.get(armLibrary);
     final long initialPriority=new long[]{0,0x20,0x80}[test%3];
     cpu.setBasePriority(initialPriority);cpu.setPrivileged(true);cpu.setThreadMode(false);
     final int[] cpuCalls={0,0};
     emu.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){
      public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw op){emu.getEmulator().getMemState().setValue(op.getOutput(),cpu.getBasePriority());cpuCalls[0]++;return true;}
     });
     emu.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){
      public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw op){emu.getEmulator().getMemState().setValue(op.getOutput(),60);cpuCalls[1]++;return true;}
     });

 emu.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int reg=0;reg<=12;reg++)emu.writeRegister("r"+reg,0);
 for(String f:new String[]{"CY","ZR","NG","OV"})if(currentProgram.getRegister(f)!=null)emu.writeRegister(f,0);
 emu.writeRegister("lr",0x2302df01L);emu.writeRegister(emu.getStackPointerRegister(),0x2302f000L);
 emu.writeMemory(toAddr(0x23000000L),ram);emu.writeMemory(toAddr(0x2302ec00L),new byte[0x400]);
 emu.writeRegister(emu.getPCRegister(),0x23022508L);int steps=0;
 while(emu.getExecutionAddress().getOffset()!=0x2302df00L&&steps<20000){if(!emu.step(monitor))throw new Exception("case"+test+" pc"+emu.getExecutionAddress()+" "+emu.getLastError());steps++;}
 if(steps>=20000)throw new Exception("bound"+test+" pc"+emu.getExecutionAddress());
 if(cpu.getBasePriority()!=initialPriority)throw new Exception("BASEPRI");
 out.println("{\"case\":"+test+",\"kind\":"+kind+",\"mode\":"+mode+",\"class\":"+cls+",\"length\":"+len+",\"before_gzip\":\""+zip(ram)+"\",\"after_gzip\":\""+zip(emu.readMemory(toAddr(0x23000000L),65536))+"\",\"basepri_initial\":"+initialPriority+",\"basepri_final\":"+cpu.getBasePriority()+",\"steps\":"+steps+"}");
 }finally{emu.dispose();}
 }
 }println("MOUSE_BUSINESS_FLOW_ORIGINAL_CASES=1600");
 }
}
