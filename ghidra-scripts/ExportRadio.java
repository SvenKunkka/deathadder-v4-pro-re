// Reproducible private analysis export; generated C is not original source.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ExportRadio extends GhidraScript {
 public void run() throws Exception {
  File dir = new File(getScriptArgs()[0]); dir.mkdirs();
  DecompInterface decompiler = new DecompInterface();
  ghidra.app.decompiler.DecompileOptions opts = new ghidra.app.decompiler.DecompileOptions();
  opts.setRespectReadOnly(true);
  decompiler.setOptions(opts);
  decompiler.openProgram(currentProgram);
  PrintWriter index = new PrintWriter(new File(dir, "functions.tsv"), "UTF-8");
  PrintWriter calls = new PrintWriter(new File(dir, "calls.tsv"), "UTF-8");
  PrintWriter refs = new PrintWriter(new File(dir, "references.tsv"), "UTF-8");
  PrintWriter asm = new PrintWriter(new File(dir, "disassembly.txt"), "UTF-8");
  index.println("address\tname\tbody_bytes\tdecompiled\terror");
  calls.println("caller\tcallee"); refs.println("from\tto\ttype\tfunction");
  int total = 0, good = 0;
  for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
   if (monitor.isCancelled()) break;
   DecompileResults r = decompiler.decompileFunction(f, 30, monitor);
   boolean ok = r.decompileCompleted() && r.getDecompiledFunction() != null;
   total++; if (ok) good++;
   index.println(f.getEntryPoint()+"\t"+f.getName()+"\t"+f.getBody().getNumAddresses()+"\t"+ok+"\t"+r.getErrorMessage().replace('\n',' '));
   if (ok) try (PrintWriter out = new PrintWriter(new File(dir, f.getEntryPoint()+".c"), "UTF-8")) {
    out.println("/* Automatically decompiled from "+currentProgram.getName()+" at "+f.getEntryPoint()+". Types and names are inferred; NOT original source. */");
    out.println(r.getDecompiledFunction().getC());
   }
   for (Function callee : f.getCalledFunctions(monitor)) calls.println(f.getEntryPoint()+"\t"+callee.getEntryPoint());
  }
  long count = 0;
  for (Instruction i : currentProgram.getListing().getInstructions(true)) {
   count++; asm.println(i.getAddress()+"  "+i);
   Function f = getFunctionContaining(i.getAddress());
   for (Reference r : i.getReferencesFrom()) refs.println(r.getFromAddress()+"\t"+r.getToAddress()+"\t"+r.getReferenceType()+"\t"+(f == null ? "" : f.getEntryPoint()));
  }
  index.close(); calls.close(); refs.close(); asm.close(); decompiler.dispose();
  try (PrintWriter out = new PrintWriter(new File(dir,"summary.txt"), "UTF-8")) {
   out.println("program="+currentProgram.getName()); out.println("language="+currentProgram.getLanguageID());
   out.println("program_image_base="+currentProgram.getImageBase());
   for (ghidra.program.model.mem.MemoryBlock block : currentProgram.getMemory().getBlocks()) out.println("memory="+block.getName()+":"+block.getStart()+":"+block.getSize());
   out.println("functions="+total); out.println("decompiled="+good); out.println("instructions="+count);
  }
  println("EXPORTED functions="+total+" decompiled="+good+" instructions="+count);
 }
}
