import ghidra.app.script.GhidraScript;import ghidra.app.decompiler.*;import ghidra.program.model.listing.*;import ghidra.program.model.address.*;import java.io.*;import java.util.*;import java.math.BigInteger;
public class ExpandReceiverVendorRom extends GhidraScript {
 public void run()throws Exception{
 byte[]image=java.nio.file.Files.readAllBytes(java.nio.file.Path.of(getScriptArgs()[1]));if(!HexFormat.of().formatHex(java.security.MessageDigest.getInstance("SHA-256").digest(image)).equals("f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162")||!Arrays.equals(image,getBytes(toAddr(0xe054000L),image.length)))throw new Exception("image");
 File dir=new File(getScriptArgs()[0]);dir.mkdirs();long[]entries={0xe05be8cL,0xe05c504L,0xe05c5ecL,0xe05c6d4L,0xe05c774L,0xe05c0e8L,0xe05c200L,0xe05c214L,0xe05cd78L,0xe05d028L};
 for(long v:entries){Address a=toAddr(v);if(getInstructionAt(a)==null)currentProgram.getProgramContext().setValue(currentProgram.getRegister("TMode"),a,a,BigInteger.ONE);disassemble(a);if(getFunctionAt(a)==null)createFunction(a,"vendor_rom_"+Long.toHexString(v));}
 analyzeChanges(currentProgram);
 DecompInterface d=new DecompInterface();DecompileOptions opts=new DecompileOptions();opts.setRespectReadOnly(true);d.setOptions(opts);d.openProgram(currentProgram);
 Set<Function>fs=new LinkedHashSet<>();for(long v:entries){Function f=getFunctionAt(toAddr(v));if(f==null)throw new Exception("function"+Long.toHexString(v));fs.add(f);fs.addAll(f.getCalledFunctions(monitor));}
 try(PrintWriter idx=new PrintWriter(new File(dir,"functions.tsv"),"UTF-8")){for(Function f:fs){DecompileResults x=d.decompileFunction(f,60,monitor);boolean ok=x.decompileCompleted()&&x.getDecompiledFunction()!=null;idx.println(f.getEntryPoint()+"\t"+ok+"\t"+f.getBody().getNumAddresses());if(ok)try(PrintWriter o=new PrintWriter(new File(dir,f.getEntryPoint()+".c"),"UTF-8")){o.println(x.getDecompiledFunction().getC());}}}
 try(PrintWriter o=new PrintWriter(new File(dir,"disassembly.txt"),"UTF-8")){for(Instruction i:currentProgram.getListing().getInstructions(new AddressSet(toAddr(0xe05be8cL),toAddr(0xe05d080L)),true))o.println(i.getAddress()+"  "+i);}
 d.dispose();println("VENDOR_ROM_EXPANDED="+fs.size());
 }
}
