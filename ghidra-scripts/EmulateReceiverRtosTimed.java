import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverRtosTimed extends GhidraScript {
 String hex(byte[] b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}
 long u32(EmulatorHelper e,long a){byte[]b=e.readMemory(toAddr(a),4);return (b[0]&255L)|(b[1]&255L)<<8|(b[2]&255L)<<16|(b[3]&255L)<<24;}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random random=new Random(0x1206d0d0L);try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
 for(int id=0;id<1536;id++){
 int op=id/384,v=id%384,q=op==0?0x1c54:0x1b8c,n=v%4;
 byte[]ram=new byte[131072],pattern=new byte[256],stack=new byte[1024],msg=new byte[36],pair=new byte[8];random.nextBytes(pattern);for(int i=0;i<ram.length;i++)ram[i]=pattern[i%256];random.nextBytes(stack);random.nextBytes(msg);random.nextBytes(pair);
 for(int t:new int[]{0x5c00,0x5d00,0x5e00,0x4800,0x4900,0x4a00,0x4b00}){Arrays.fill(ram,t,t+0x90,(byte)0);ram[t+0xe]=(byte)new int[]{-8,0,1,4,8,127}[(v+t/256)%6];}
 w32(ram,q,n==0?0x23000000L+q:0x23005c00L);w32(ram,q+4,n==0?0x23000000L+q:0x23005c00L+(n-1)*256);
 for(int i=0;i<n;i++){int t=0x5c00+i*256;w32(ram,t,i+1==n?0x23000000L+q:0x23000000L+t+256);w32(ram,t+4,i==0?0x23000000L+q:0x23000000L+t-256);w32(ram,t+8,0x23000000L+q);ram[t+0xd]=(byte)new int[]{2,6,0x22,0x42}[(v/4+i)%4];w32(ram,t+0x14,0x23006000L+i*64);w32(ram,t+0x8c,0x12345678);if(v%31==0&&i==0)w32(ram,t+0x18,0x23005000L);}
 w32(ram,0x7170,0x23004a00L);w32(ram,0x7174,0x23004b00L);w32(ram,0x717c,0x23004a00L);ram[0x7178]=0;
 ram[0x4a0e]=(byte)new int[]{-1,0,4,127}[(v/4)%4];ram[0x4a0f]=0;ram[0x4a0d]=(byte)(v%5==0?4:0);
 if(v%3==0){w32(ram,0x7180,0x23007180L);w32(ram,0x7184,0x23007180L);}else{w32(ram,0x7180,0x23004800L);w32(ram,0x7184,0x23004900L);w32(ram,0x4800,0x23004900L);w32(ram,0x4804,0x23007180L);w32(ram,0x4900,0x23007180L);w32(ram,0x4904,0x23004800L);ram[0x480d]=(byte)0x80;ram[0x490d]=(byte)0x80;ram[0x480e]=1;ram[0x490e]=8;}
 w32(ram,0x2c60,v%37==0?0x23005000L:0);w32(ram,0x7194,v%19==0?10:0);w32(ram,0x7190,0);
 if(op==0){w32(ram,q+8,new long[]{0,1,9,10,0xffffffffL}[(v/4)%5]);w32(ram,q+12,v%2==0?1:10);}else{w32(ram,q+8,36);w32(ram,q+12,5);w32(ram,q+16,0x23015760L);w32(ram,q+20,0x23015814L);w32(ram,q+24,0x23015760L+((v/5)%5)*36);w32(ram,q+28,0x23015760L+((v/7)%5)*36);w32(ram,q+32,n==0?(v/4)%6:0);}
 byte[]rtc=new byte[4096];for(int i=0;i<rtc.length;i++)rtc[i]=pattern[i%256];w32(rtc,0x770,100+v*13);w32(rtc,0x774,0);w32(ram,0x2840,100);w32(ram,0x2844,0);ram[0x960]=(byte)new int[]{7,13,14,15}[v%4];w32(ram,0xab4,0);w32(ram,0x7198,v%11==0?1:0);w32(ram,0x2c78,v%5);w32(ram,0x2c7c,0);
 ArrayList<Integer> ts=new ArrayList<>();if(v%3!=0)ts.add(0x5200);for(int i=0;i<n;i++){int t=0x5c00+i*256;w32(ram,t+0x18,0);w32(ram,t+0x1c,0);if((v+i)%2==0)ts.add(t+0x18);}w32(ram,0x2c60,0);w32(ram,0x2c64,0);if(v%2==0)ts.add(0x2c60);w32(ram,0x7194,new long[]{0,1,10,0x7fffffffL,0x80000000L,0xffffffffL}[(v/4)%6]);
 w32(ram,0xb48,ts.isEmpty()?0x23000b48L:0x23000000L+ts.get(0));w32(ram,0xb4c,ts.isEmpty()?0x23000b48L:0x23000000L+ts.get(ts.size()-1));for(int i=0;i<ts.size();i++){int t=ts.get(i);w32(ram,t,i+1==ts.size()?0x23000b48L:0x23000000L+ts.get(i+1));w32(ram,t+4,i==0?0x23000b48L:0x23000000L+ts.get(i-1));w32(ram,t+16,new long[]{0,1,10,100,0x7fffffffL}[(v+i)%5]);w32(ram,t+20,0);}
 final long initial=new long[]{0,0x20,0x80}[(v/3)%3];final int exception=v%7==0?0:60;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});
 e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x5f99c000L),rtc);e.writeMemory(toAddr(0x2302ec00L),stack);e.writeMemory(toAddr(0x2302e000L),op==3?pair:msg);e.writeRegister("r0",op==3?0x2302e000L:0x23000000L+q);e.writeRegister("r1",0x2302e000L);e.writeRegister("r2",0);e.writeRegister("r3",0);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),new long[]{0x0e06d0d0L,0x0e06cbdcL,0x0e06cd54L,0x230254f8L}[op]);
 int steps=0;long boundary=0,arg0=0;while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<12000){long pc=e.getExecutionAddress().getOffset(),r0=e.readRegister("r0").longValue();if(pc==0xe0611ccL){boundary=pc;arg0=r0;break;}if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=12000)throw new Exception("bound"+id);
 out.println("{\"case\":"+id+",\"op\":"+op+",\"address\":"+(0x23000000L+q)+",\"before_gzip\":\""+zip(ram)+"\",\"after_gzip\":\""+zip(e.readMemory(toAddr(0x23000000L),ram.length))+"\",\"message\":\""+hex(msg)+"\",\"pair\":\""+hex(pair)+"\",\"opaque_tail\":\""+hex(Arrays.copyOfRange(stack,992,1016))+"\",\"rtc_before\":\""+zip(rtc)+"\",\"rtc_after\":\""+zip(e.readMemory(toAddr(0x5f99c000L),rtc.length))+"\",\"initial_priority\":"+initial+",\"exception\":"+exception+",\"final_priority\":"+cpu.getBasePriority()+",\"boundary\":"+boundary+",\"arg0\":"+arg0+",\"return\":"+e.readRegister("r0").longValue()+",\"steps\":"+steps+"}");
 }finally{e.dispose();}
 }
 }println("RECEIVER_RTOS_TIMED_CASES=1536");
 }
}
