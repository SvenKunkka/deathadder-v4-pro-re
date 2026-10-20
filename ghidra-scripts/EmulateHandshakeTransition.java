// Bounded software-only execution of original receiver handshake transitions.
// Excludes state=3, notification flag !=0 (external queue/notification path).
import ghidra.app.script.GhidraScript;
import ghidra.app.emulator.EmulatorHelper;
import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class EmulateHandshakeTransition extends GhidraScript {
 String hex(byte[] data){return HexFormat.of().formatHex(data);}
 public void run() throws Exception {
  byte[] original=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));
  String sha=hex(java.security.MessageDigest.getInstance("SHA-256").digest(original));
  if(!sha.equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162"))throw new Exception("Unexpected image");
  if(!Arrays.equals(original,getBytes(toAddr(0x0e054000L),original.length)))throw new Exception("Flash mismatch");
  if(!Arrays.equals(Arrays.copyOfRange(original,0x79c,0x79c+0x7270),getBytes(toAddr(0x23020000L),0x7270)))throw new Exception("Runtime mismatch");
  println("ORIGINAL_FLASH_AND_RUNTIME_COPY_VERIFIED_SHA256="+sha);
  Random rng=new Random(120223);
  try(PrintWriter out=new PrintWriter(getScriptArgs()[0],"UTF-8")) {
   for(int test=0;test<640;test++) {
    int slot=test&1; long stride=slot*0xf84L;
    int state=test<256?0:test<384?2:test<448?3:new int[]{0,2,3,1,6,65535}[test%6];
    int local=test<256?test>>4:rng.nextInt(16), remote=test<256?test&15:rng.nextInt(16);
    int selector=test<384?(test&3):new int[]{0,1,2,3,4,65535}[test%6];
    int status0=test%5,status1=(test/5)%5;
    int seq=1+test%7,selected=0xa55a;
    byte[] before=new byte[0xe0],rx=new byte[12],freq=new byte[8],mask=new byte[5];
    rng.nextBytes(before);rng.nextBytes(rx);rng.nextBytes(freq);rng.nextBytes(mask);
    rx[0]=11;rx[1]=(byte)(rng.nextInt(128));rx[3]=(byte)(state==0?0x12:state==2?0x14:0x16);
    rx[4]=(byte)(remote|((test&2)!=0?0x80:0));
    int flag=state==3?0:test%3;
    if(state==0 && flag!=0){
     if(test%3==1){before[6]=(byte)0xff;before[7]=(byte)0xff;}
     else {rx[6]=before[6];rx[7]=before[7];}
    }
    if(test>=448){
     switch(test%5){
      case 0:rx[1]|=(byte)0x80;break;
      case 1:rx[0]=10;break;
      case 2:rx[3]=0x55;break;
      case 3:if(state==0){flag=1;before[6]=0;before[7]=0;rx[6]=1;}break;
     }
    }
    int idx0=rng.nextInt(256),idx1=rng.nextInt(256),extra=rng.nextInt(256);
    EmulatorHelper emu=new EmulatorHelper(currentProgram){protected ghidra.app.emulator.Emulator newEmulator(){return new ghidra.app.emulator.AdaptedEmulator(this);}};
    try {
     emu.setContextRegister(currentProgram.getRegister("TMode"),BigInteger.ONE);
     for(int reg=0;reg<=12;reg++)emu.writeRegister("r"+reg,0);
     for(String f:new String[]{"CY","ZR","NG","OV"})if(currentProgram.getRegister(f)!=null)emu.writeRegister(f,0);
     emu.writeRegister("r0",slot);emu.writeRegister("r1",0x2302e000L);
     emu.writeRegister("lr",0x23027f01L);emu.writeRegister(emu.getStackPointerRegister(),0x2302f000L);
     emu.writeMemory(toAddr(0x2302ee00L),new byte[0x200]);
     emu.writeMemory(toAddr(0x230033e8L+stride),before);
     emu.writeMemoryValue(toAddr(0x230033e8L),4,status0);emu.writeMemoryValue(toAddr(0x2300436cL),4,status1);
     emu.writeMemoryValue(toAddr(0x230034b0L+stride),2,state);
     emu.writeMemoryValue(toAddr(0x230033fcL+stride),4,flag);
     emu.writeMemoryValue(toAddr(0x2300348fL+stride),1,seq);
     emu.writeMemoryValue(toAddr(0x23003236L),2,selected);
     // Both capability sources separately initialized: active selection uses
     // primary iff both status words <=2, fallback otherwise.
     int primary=local, fallback=local^15;
     emu.writeMemoryValue(toAddr(0x23003238L),2,primary);
     emu.writeMemoryValue(toAddr(0x23003234L),2,fallback);
     emu.writeMemoryValue(toAddr(0x2300323eL),2,selector);
     emu.writeMemoryValue(toAddr(0x23005349L),1,idx0);emu.writeMemoryValue(toAddr(0x2300534aL),1,idx1);
     emu.writeMemory(toAddr(0x2300534bL),freq);emu.writeMemory(toAddr(0x230030d9L),mask);
     emu.writeMemoryValue(toAddr(0x23003158L),4,extra);
     emu.writeMemory(toAddr(0x2302e000L),rx);
     before=emu.readMemory(toAddr(0x230033e8L+stride),0xe0);
     emu.writeRegister(emu.getPCRegister(),0x230223f0L);
     int steps=0;
     while(emu.getExecutionAddress().getOffset()!=0x23027f00L && steps<700){
      if(!emu.step(monitor))throw new Exception("case "+test+" "+emu.getLastError());steps++;
     }
     if(steps>=700)throw new Exception("Instruction bound: "+test);
     String after=hex(emu.readMemory(toAddr(0x230033e8L+stride),0xe0));
     out.println("{\"case\":"+test+",\"slot\":"+slot+",\"status0\":"+status0+",\"status1\":"+status1+",\"primary_cap\":"+primary+",\"fallback_cap\":"+fallback+",\"selector\":"+selector+",\"index0\":"+idx0+",\"index1\":"+idx1+",\"extra\":"+extra+",\"frequencies\":\""+hex(freq)+"\",\"mask\":\""+hex(mask)+"\",\"incoming\":\""+hex(rx)+"\",\"before\":\""+hex(before)+"\",\"after\":\""+after+"\",\"selected_before\":"+selected+",\"selected_after\":"+((emu.readMemoryByte(toAddr(0x23003236L))&255)|((emu.readMemoryByte(toAddr(0x23003237L))&255)<<8))+",\"return\":"+emu.readRegister("r0")+",\"steps\":"+steps+"}");
    } finally {emu.dispose();}
   }
  }
  println("ORIGINAL_TRANSITION_CASES=640");
 }
}
