import ghidra.app.script.GhidraScript;import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;import java.util.zip.GZIPOutputStream;
public class EmulateReceiverRadioLog extends GhidraScript {
 String hex(byte[]b){return HexFormat.of().formatHex(b);}String zip(byte[]b)throws Exception{ByteArrayOutputStream o=new ByteArrayOutputStream();try(GZIPOutputStream z=new GZIPOutputStream(o)){z.write(b);}return Base64.getEncoder().encodeToString(o.toByteArray());}
 void w32(byte[]b,int a,long v){for(int i=0;i<4;i++)b[a+i]=(byte)(v>>(8*i));}
 long reg(EmulatorHelper e,String n){return e.readRegister(n).longValue()&0xffffffffL;}
 public void run()throws Exception {
 String[]sa=getScriptArgs();byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(sa[1]));
 if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162"))throw new Exception("hash");
 if(!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length))||!Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("mapping");
 int start=Integer.parseInt(sa[2]),end=Integer.parseInt(sa[3]);long[]formats={0xe06fbfcL,0xe06fc3cL,0xe06fc64L,0xe06fc88L,0xe06fca4L,0xe06fcc8L,0xe06fcecL};String[]names={"ram","radio","timer","egu","dppi","rtc","nvic"};long[]bases={0x23000000L,0x5302c000L,0x53029000L,0x53025000L,0x53022000L,0x5f99c000L,0xe000e000L};
 try(PrintWriter out=new PrintWriter(new FileOutputStream(sa[0],start!=0))){for(int id=start;id<end;id++){
 Random rng=new Random(620719L+id*7919L);byte[][]before=new byte[7][];for(int i=0;i<7;i++){before[i]=new byte[i==0?131072:4096];byte[]pat=new byte[32];rng.nextBytes(pat);for(int j=0;j<before[i].length;j++)before[i][j]=pat[j%32];}
 System.arraycopy(image,0x1c854,before[0],0,0x1e08);boolean changed=id>=3072;w32(before[0],0x494,changed?0x2302d801L:0xe05d625L);
 int formatIndex=id%7,v=id/7;long value;
 long[]edges={0,1,9,10,99,100,127,128,255,256,0xffffffffL,0xffffff80L,0x7fffffffL,0x80000000L,0x80000001L,0xffffff9cL};
 if(formatIndex==1||formatIndex==2)value=(Integer.toUnsignedLong(rng.nextInt())&0xffffff00L)|(v&255L);
 else value=v<edges.length?edges[v]:Integer.toUnsignedLong(rng.nextInt());
 long[]args={formats[formatIndex],value,Integer.toUnsignedLong(rng.nextInt()),Integer.toUnsignedLong(rng.nextInt()),Integer.toUnsignedLong(rng.nextInt())};
 EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
 try{e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);for(int k=0;k<=12;k++)e.writeRegister("r"+k,0);for(String f:new String[]{"CY","ZR","NG","OV","Q"})if(currentProgram.getRegister(f)!=null)e.writeRegister(f,0);
 for(int i=0;i<7;i++)e.writeMemory(toAddr(bases[i]),before[i]);e.writeMemory(toAddr(0x2302ed00L),new byte[768]);e.writeMemoryValue(toAddr(0x2302f000L),4,args[4]);
 for(int i=0;i<4;i++)e.writeRegister("r"+i,args[i]);e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);e.writeRegister(e.getPCRegister(),0xe05d634L);
 int steps=0;long boundary=0,arg0=0;while(e.getExecutionAddress().getOffset()!=0x2302df00L&&steps<20000){long pc=e.getExecutionAddress().getOffset();if(pc==0x2302d800L){boundary=pc;arg0=reg(e,"r0");break;}if(!e.step(monitor))throw new Exception("case"+id+" pc"+e.getExecutionAddress()+" "+e.getLastError());steps++;}if(steps>=20000)throw new Exception("bound"+id);
 StringBuilder row=new StringBuilder("{\"case\":"+id+",\"format_index\":"+formatIndex+",\"args\":"+Arrays.toString(args)+",\"boundary\":"+boundary+",\"arg0\":"+arg0+",\"result\":"+reg(e,"r0")+",\"steps\":"+steps);
 for(int i=0;i<7;i++)row.append(",\"").append(names[i]).append("_before\":\"").append(zip(before[i])).append("\",\"").append(names[i]).append("_after\":\"").append(zip(e.readMemory(toAddr(bases[i]),before[i].length))).append("\"");out.println(row.append('}'));
 }finally{e.dispose();}
 }}println("RECEIVER_RADIO_LOG_RANGE="+start+":"+end);
 }
}
