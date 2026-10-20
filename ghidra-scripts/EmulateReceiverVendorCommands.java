import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateReceiverVendorCommands extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(java.util.zip.GZIPOutputStream z=new java.util.zip.GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long x){for(int i=0;i<4;i++)b[a+i]=(byte)(x>>>(8*i));}long u32(EmulatorHelper e,long a){byte[]b=e.readMemory(toAddr(a),4);return (b[0]&255L)|(b[1]&255L)<<8|(b[2]&255L)<<16|(b[3]&255L)<<24;}
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("image/mapping");
 Random random=new Random(0x1202604cL);int start=Integer.parseInt(getScriptArgs()[2]),end=Integer.parseInt(getScriptArgs()[3]);try(PrintWriter out=new PrintWriter(new FileOutputStream(getScriptArgs()[0],start>0),false,java.nio.charset.StandardCharsets.UTF_8)){for(int cid=0;cid<8704;cid++){
 int op=cid/4096,v=cid%4096,group=v/1024,variant=(v/256)%4,cmd=v%256;
 if(op==2){group=(v/128)%4;variant=(v/16)%8;cmd=new int[]{4,0xb,0x15,0x45,0x33,0x70,0x71,0x72,0x73,0x7f,0xf1,0xf3,0xfa,0xfb,0xff,0x95}[v%16];}
 int cls=new int[]{0,7,0xfe,variant%2==0?15:16}[group];
 byte[]ram=new byte[131072],radio=new byte[4096],device=new byte[8],boot=new byte[16],pattern=new byte[256];random.nextBytes(pattern);for(byte[]b:new byte[][]{ram,radio,device,boot})for(int i=0;i<b.length;i++)b[i]=pattern[i%256];
 for(int peer=0;peer<2;peer++){int stride=peer*0xf84,b=0x33e8+stride;int[] caps={32,16,16,32,32,96},bases={0x356c,0x376c,0x386c,0x396c,0x3b6c,0x3d6c};for(int c=0;c<6;c++){ram[b+0x154+c]=0;ram[b+0x15a+c]=0;ram[b+0x160+c]=(byte)caps[c];ram[b+0x166+c]=16;ram[b+0xa7+c]=1;w32(ram,b+0x16c+4*c,0x23000000L+stride+bases[c]);}ram[b+0x159]=(byte)(variant==3?95:variant==1?94:0);}
 int target=new int[]{0,4,7,2}[variant%4];ram[0x2d1d]=(byte)((target<<5)|(v&31));ram[0x2d1c]=(byte)(op==2&&v%5==0?2:1);ram[0x2d21]=(byte)new int[]{0,1,3,4,7,31,79,80}[(v/8)%8];ram[0x2d22]=(byte)cls;ram[0x2d23]=(byte)cmd;
 ram[0x2c80]=(byte)new int[]{0,1,2,4,6,7,255}[(v/7)%7];ram[0x71bb]=(byte)(op==2&&v%11==0?0:1);ram[0x71b2]=(byte)(v%2);ram[0x71bd]=(byte)(variant%4);ram[0x2dd3]=(byte)(variant%4);ram[0x71b3]=(byte)(v%5);ram[0x71b4]=(byte)(v%128);ram[0x71b5]=(byte)(v%5);
 for(int j=0;j<3;j++){ram[0x2cb4+j]=(byte)((variant+j)%6);ram[0x2d24+j]=(byte)((variant+j)%6);}
 if(cls==7&&variant==2)for(int j=0;j<3;j++){ram[0x2d24+j]=(byte)j;ram[0x2d91+j]=(byte)j;ram[0x2daa+j]=(byte)j;}
 if(cls==0&&cmd==0x15){long value=new long[]{0,0xffffffffL,0xfffffffeL,0x10203040L}[variant%4];w32(ram,0x2d24,value);if(variant==3)w32(ram,0x2dcf,value);}
 if(cls==0&&cmd==0xb)ram[0x2d24]=(byte)new int[]{1,3,5,7}[variant%4];
 if(cls==0xfe&&cmd==0x7f)ram[0x2d25]=(byte)new int[]{0,1,40,41}[variant%4];
 if(op==2&&cls==0xfe&&cmd==0x33){ram[0x2d1d]=(byte)0xe0;ram[0x71bd]=2;ram[0x2d24]=(byte)(variant%5==0?1:0);ram[0x2d25]=(byte)(variant%2==0?255:0);ram[0x2d26]=(byte)(variant%3==0?255:0);ram[0x2d27]=(byte)(variant%4==0?255:0);}
 int sum=0;for(int i=0x2d1e;i<0x2d74;i++)sum^=ram[i]&255;ram[0x2d74]=(byte)(op==2&&v%17==0?sum^1:sum);
 long incoming=0x12340000L+cid;final long initial=0;final int exception=0;if(cid<start||cid>=end)continue;
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{
 java.lang.reflect.Field field=ghidra.app.emulator.AdaptedEmulator.class.getDeclaredField("emu");field.setAccessible(true);ghidra.pcode.emu.PcodeMachine<?> machine=(ghidra.pcode.emu.PcodeMachine<?>)field.get(e.getEmulator());Object lib=machine.getUseropLibrary().getUserops().get("setBasePriority").getDefiningLibrary();field=lib.getClass().getDeclaredField("cpuState");field.setAccessible(true);ghidra.program.emulation.ArmCpuState cpu=(ghidra.program.emulation.ArmCpuState)field.get(lib);cpu.setBasePriority(initial);cpu.setPrivileged(true);cpu.setThreadMode(exception==0);
 e.registerCallOtherCallback("getBasePriority",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),cpu.getBasePriority());return true;}});e.registerCallOtherCallback("getCurrentExceptionNumber",new ghidra.pcode.emulate.BreakCallBack(){public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw p){e.getEmulator().getMemState().setValue(p.getOutput(),exception);return true;}});
 e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int i=0;i<=12;i++)e.writeRegister("r"+i,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 e.writeMemory(toAddr(0x23000000L),ram);e.writeMemory(toAddr(0x5302c000L),radio);e.writeMemory(toAddr(0xfffe010L),device);e.writeMemory(toAddr(0xf000L),boot);long entry=op==0?0x2302604cL:op==1?0x23026090L:0x230205f8L;
 e.writeRegister("r0",incoming);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),entry);
 int steps=0;long boundary=0,arg0=0;boolean argValid=false;Set<Long> stops=Set.of(0xe05be8cL,0x23025300L,0x230252a4L,0x23025954L,0x23025fe0L,0xe05c504L,0xe05c5ecL,0x23024db4L,0xe05c6d4L,0xe05c774L);
 while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<16000){long pc=e.getExecutionAddress().getOffset();if(stops.contains(pc)){boundary=pc;argValid=pc!=0xe05c774L;arg0=argValid?e.readRegister("r0").longValue():0;break;}if(!e.step(monitor))throw new Exception("case"+cid+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=16000)throw new Exception("bound"+cid);
 StringBuilder row=new StringBuilder("{\"case\":"+cid+",\"op\":"+op+",\"entry\":"+entry+",\"class\":"+cls+",\"command\":"+cmd+",\"variant\":"+variant+",\"incoming_r0\":"+incoming+",\"boundary\":"+boundary+",\"arg0\":"+arg0+",\"arg0_valid\":"+(argValid?1:0)+",\"steps\":"+steps);
 String[]names={"ram","radio","deviceid","boot"};byte[][]windows={ram,radio,device,boot};long[]bases={0x23000000L,0x5302c000L,0xfffe010L,0xf000L};for(int i=0;i<4;i++)row.append(",\"").append(names[i]).append("_before\":\"").append(zip(windows[i])).append("\",\"").append(names[i]).append("_after\":\"").append(zip(e.readMemory(toAddr(bases[i]),windows[i].length))).append("\"");row.append("}");out.println(row);
 }finally{e.dispose();}
 }}println("RECEIVER_VENDOR_COMMANDS_RANGE="+start+":"+end);
 }
}
