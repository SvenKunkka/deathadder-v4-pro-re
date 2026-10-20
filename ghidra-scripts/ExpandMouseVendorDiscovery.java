import ghidra.app.script.GhidraScript;import ghidra.app.decompiler.*;import ghidra.program.model.listing.*;import ghidra.program.model.address.*;import java.io.*;import java.util.*;import java.math.BigInteger;
public class ExpandMouseVendorDiscovery extends GhidraScript {
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!HexFormat.of().formatHex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48")||!Arrays.equals(image,getBytes(toAddr(0xe06c000L),image.length)))throw new Exception("image");
 File dir=new File(getScriptArgs()[0]);dir.mkdirs();long[]entries={0xe07a338L,0xe07a0c8L,0xe07a1b0L,0x23025c78L,0x23021c40L,0x23025c70L,0x23021278L};
 for(long v:entries){Address a=toAddr(v);if(getInstructionAt(a)==null)currentProgram.getProgramContext().setValue(currentProgram.getRegister("TMode"),a,a,BigInteger.ONE);disassemble(a);if(getFunctionAt(a)==null)createFunction(a,"vendor_rom_"+Long.toHexString(v));}
 analyzeChanges(currentProgram);
 DecompInterface d=new DecompInterface();DecompileOptions opts=new DecompileOptions();opts.setRespectReadOnly(true);d.setOptions(opts);d.openProgram(currentProgram);
 Set<Function>fs=new LinkedHashSet<>();for(long v:entries){Function f=getFunctionAt(toAddr(v));if(f==null)throw new Exception("function"+Long.toHexString(v));fs.add(f);fs.addAll(f.getCalledFunctions(monitor));}
 try(PrintWriter idx=new PrintWriter(new File(dir,"functions.tsv"),"UTF-8")){for(Function f:fs){DecompileResults x=d.decompileFunction(f,60,monitor);boolean ok=x.decompileCompleted()&&x.getDecompiledFunction()!=null;idx.println(f.getEntryPoint()+"\t"+ok+"\t"+f.getBody().getNumAddresses());if(ok)try(PrintWriter o=new PrintWriter(new File(dir,f.getEntryPoint()+".c"),"UTF-8")){o.println(x.getDecompiledFunction().getC());}}}
 try(PrintWriter o=new PrintWriter(new File(dir,"disassembly.txt"),"UTF-8")){for(Instruction i:currentProgram.getListing().getInstructions(new AddressSet(toAddr(0xe07a0c8L),toAddr(0xe07a434L)),true))o.println(i.getAddress()+"  "+i);}
 d.dispose();println("MOUSE_VENDOR_EXPANDED="+fs.size());
 }
}
