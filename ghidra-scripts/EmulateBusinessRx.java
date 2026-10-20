// Original reassembly/format/decrypt instructions, paused BEFORE downstream
// work-submit/management/consumer. No instruction or function substitutions.
import ghidra.app.script.GhidraScript;
import ghidra.app.emulator.EmulatorHelper;
import java.io.*;import java.util.*;import java.math.BigInteger;
public class EmulateBusinessRx extends GhidraScript {
 String hex(byte[] b){return HexFormat.of().formatHex(b);}
 int u(byte b){return b&255;}
 byte[] cipherFixture(byte[] plain,byte[] key){
  int n=plain.length/4;int[] v=new int[n],k=new int[4];
  for(int i=0;i<n;i++)for(int j=0;j<4;j++)v[i]|=(plain[4*i+j]&255)<<(8*j);
  for(int i=0;i<4;i++)for(int j=0;j<4;j++)k[i]|=(key[4*i+j]&255)<<(8*j);
  int sum=0,z=v[n-1];
  for(int r=0;r<6+52/n;r++){sum+=0x9e3779b9;int e=sum>>>2;
   for(int p=0;p<n;p++){int y=v[p==n-1?0:p+1];v[p]+=((y<<2^z>>>5)+(z<<4^y>>>3))^((k[(e^p)&3]^z)+(sum^y));z=v[p];}}
  byte[] out=new byte[plain.length];for(int i=0;i<n;i++)for(int j=0;j<4;j++)out[4*i+j]=(byte)(v[i]>>>(8*j));return out;
 }
 public void run() throws Exception {
  boolean mouse=getScriptArgs()[2].equals("mouse");
  long flash=mouse?0x0e06c000L:0x0e054000L,entry=mouse?0x230259ecL:0x23025004L;
  long bank=mouse?0x23006850L:0x23006278L;
  int size=mouse?0xc6b0:0x7270,table=mouse?0x2c904:0x1ba74;
  String expected=mouse?"c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48":"f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162";
  byte[] image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
  if(!hex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals(expected))throw new Exception("Hash mismatch");
  if(!Arrays.equals(image,getBytes(toAddr(flash),image.length)) || !Arrays.equals(Arrays.copyOfRange(image,0x79c,0x79c+size),getBytes(toAddr(0x23020000L),size)))throw new Exception("Mapping mismatch");
  println("VERIFIED_IMAGE="+expected);Random random=new Random(120259);
  try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")){
   for(int test=0;test<(mouse?576:704);test++){
    int cls=test%6,mode=(test/6)%6,n=1+random.nextInt(mouse?5:7),index=1+random.nextInt(31);
    boolean more=mode<3;
    byte[] before=new byte[784],completed=new byte[128],meta=new byte[2],motion=new byte[8];
    random.nextBytes(before);random.nextBytes(completed);random.nextBytes(meta);random.nextBytes(motion);
    before[768+cls]=(byte)index;before[776+cls]=(byte)random.nextInt(113);
    if(mode==0||mode==3)index=0;
    if(mode==2||mode==5)before[768+cls]=(byte)((index+1)&31);
    if(!mouse && !more && (cls==2||cls==4) && mode!=5){
     index=1+random.nextInt(31);before[768+cls]=(byte)index;
     before[776+cls]=(byte)(((test/36)%2==0?8:16)-(n-1));
    }
    byte[] fragment=new byte[n];random.nextBytes(fragment);
    fragment[0]=(byte)(index|(more?128:0)|((test/36)%4)*32);
    byte[] key=Arrays.copyOfRange(image,table+(test/6%16)*16,table+(test/6%16)*16+16);
    if(!mouse && test>=576){
     int target=test-576,selector=target%16,pattern=target/32;
     cls=(target/16)%2==0?2:4;n=7;index=7;more=false;
     key=Arrays.copyOfRange(image,table+selector*16,table+selector*16+16);
     int total=cls==2?8:16;byte[] plain=new byte[total];
     if(pattern==1||pattern==2)plain[0]=1;
     if(pattern==2)plain[total-1]=37;
     if(pattern==3)plain[1]=1;
     byte[] cipher=cipherFixture(plain,key);
     System.arraycopy(cipher,0,before,cls*128,total-6);
     before[768+cls]=7;before[776+cls]=(byte)(total-6);
     fragment=new byte[7];fragment[0]=7;System.arraycopy(cipher,total-6,fragment,1,6);
    }
    int activity=random.nextInt(256);
    EmulatorHelper e=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
    try{
     e.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);
     for(int reg=0;reg<=12;reg++)e.writeRegister("r"+reg,0);
     for(String flag:new String[]{"CY","ZR","NG","OV"})if(currentProgram.getRegister(flag)!=null)e.writeRegister(flag,0);
     e.writeRegister("r0",test%2);e.writeRegister("r1",cls);e.writeRegister("r2",0x2302e000L);e.writeRegister("r3",n);
     e.writeRegister("lr",0x2302df01L);e.writeRegister(e.getStackPointerRegister(),0x2302f000L);
     byte[] stack=new byte[512];random.nextBytes(stack);e.writeMemory(toAddr(0x2302ee00L),stack);
     e.writeMemory(toAddr(0x2302e000L),fragment);e.writeMemory(toAddr(bank),before);
     if(mouse){e.writeMemory(toAddr(0x230067d0L),completed);e.writeMemory(toAddr(0x2300779bL),meta);}
     else {e.writeMemory(toAddr(0x23006588L),motion);e.writeMemory(toAddr(0x23006594L),new byte[]{(byte)activity});e.writeMemory(toAddr(0x23003020L),key);}
     e.writeRegister(e.getPCRegister(),entry);int steps=0,kind=0,len=0;byte[] payload=new byte[0];long stopped=0;
     while(steps<30000){
      long pc=e.getExecutionAddress().getOffset();stopped=pc;
      if(pc==0x2302df00L){kind=(index!=0&&u(before[768+cls])!=index)?1:0;break;}
      if(mouse && pc==0x2302c4b0L){kind=2;len=u(e.readMemory(toAddr(0x2300779cL),1)[0]);payload=len==0?new byte[0]:e.readMemory(toAddr(0x230067d0L),len);break;}
      if(!mouse && (pc==0x23024c88L||pc==0x23020250L)){
       kind=pc==0x23024c88L?3:4;len=e.readRegister("r2").intValue()&255;
       payload=len==0?new byte[0]:e.readMemory(toAddr(e.readRegister("r1").longValue()),len);break;
      }
      if(!e.step(monitor))throw new Exception("case"+test+" "+e.getLastError());steps++;
     }
     if(steps>=30000)throw new Exception("Bound "+test);
     out.println("{\"case\":"+test+",\"side\":\""+getScriptArgs()[2]+"\",\"class\":"+cls+",\"fragment\":\""+hex(fragment)+"\",\"before\":\""+hex(before)+"\",\"completed_before\":\""+hex(completed)+"\",\"meta_before\":\""+hex(meta)+"\",\"motion_before\":\""+hex(motion)+"\",\"activity_before\":"+activity+",\"key\":\""+hex(key)+"\",\"after\":\""+hex(e.readMemory(toAddr(bank),784))+"\",\"completed_after\":\""+hex(mouse?e.readMemory(toAddr(0x230067d0L),128):completed)+"\",\"meta_after\":\""+hex(mouse?e.readMemory(toAddr(0x2300779bL),2):meta)+"\",\"motion_after\":\""+hex(mouse?motion:e.readMemory(toAddr(0x23006588L),8))+"\",\"activity_after\":"+(mouse?activity:u(e.readMemory(toAddr(0x23006594L),1)[0]))+",\"kind\":"+kind+",\"length\":"+len+",\"payload\":\""+hex(payload)+"\",\"stop\":\""+Long.toHexString(stopped)+"\",\"steps\":"+steps+"}");
    }finally{e.dispose();}
   }
  }
  println("ORIGINAL_RX_CASES="+(mouse?576:704)+" SIDE="+getScriptArgs()[2]);
 }
}
