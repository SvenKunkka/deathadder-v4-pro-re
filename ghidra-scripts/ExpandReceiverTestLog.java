import ghidra.app.script.GhidraScript;import ghidra.app.decompiler.*;import ghidra.program.model.listing.*;import ghidra.program.model.address.*;import java.io.*;import java.util.*;import java.math.BigInteger;
public class ExpandReceiverTestLog extends GhidraScript {
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!HexFormat.of().formatHex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length)))throw new Exception("image");
 File dir=new File(getScriptArgs()[0]);dir.mkdirs();long[]entries={0xe05d624L,0xe05d628L,0xe05d634L,0xe06eea8L,0xe06f3feL,0xe06b44cL};
 for(long v:entries){Address a=toAddr(v);if(getInstructionAt(a)==null)currentProgram.getProgramContext().setValue(currentProgram.getRegister("TMode"),a,a,BigInteger.ONE);disassemble(a);if(getFunctionAt(a)==null)createFunction(a,"vendor_rom_"+Long.toHexString(v));}
 analyzeChanges(currentProgram);
 DecompInterface d=new DecompInterface();DecompileOptions opts=new DecompileOptions();opts.setRespectReadOnly(true);d.setOptions(opts);d.openProgram(currentProgram);
 Set<Function>fs=new LinkedHashSet<>();for(long v:entries){Function f=getFunctionAt(toAddr(v));if(f==null)throw new Exception("function"+Long.toHexString(v));fs.add(f);fs.addAll(f.getCalledFunctions(monitor));}
 try(PrintWriter idx=new PrintWriter(new File(dir,"functions.tsv"),"UTF-8")){for(Function f:fs){DecompileResults x=d.decompileFunction(f,60,monitor);boolean ok=x.decompileCompleted()&&x.getDecompiledFunction()!=null;idx.println(f.getEntryPoint()+"\t"+ok+"\t"+f.getBody().getNumAddresses());if(ok)try(PrintWriter o=new PrintWriter(new File(dir,f.getEntryPoint()+".c"),"UTF-8")){o.println(x.getDecompiledFunction().getC());}}}
 try(PrintWriter o=new PrintWriter(new File(dir,"disassembly.txt"),"UTF-8")){for(Instruction i:currentProgram.getListing().getInstructions(new AddressSet(toAddr(0xe06eea8L),toAddr(0xe06f4b7L)),true))o.println(i.getAddress()+"  "+i);}
 try(PrintWriter o=new PrintWriter(new File(dir,"sink-references.tsv"),"UTF-8")){for(ghidra.program.model.symbol.Reference r:getReferencesTo(toAddr(0x23000494L)))o.println(r.getFromAddress()+"\t"+r.getReferenceType()+"\t"+r); for(ghidra.program.model.symbol.Reference r:getReferencesTo(toAddr(0xe05d624L)))o.println(r.getFromAddress()+"\t"+r.getReferenceType()+"\t"+r);}
 d.dispose();println("RECEIVER_TEST_LOG_EXPANDED="+fs.size());
 }
}
