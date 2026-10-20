// Map startup memcpy destinations from independently verified source/destination/size.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class MapRuntimeRam extends GhidraScript {
 public void run() throws Exception {
  String[] args = getScriptArgs();
  long lma = Long.parseUnsignedLong(args[0],16), vma = Long.parseUnsignedLong(args[1],16);
  int size = Integer.parseInt(args[2],16);
  Memory memory = currentProgram.getMemory();
  if (args.length >= 5) {
   long dataSource = Long.parseUnsignedLong(args[3],16);
   int dataSize = Integer.parseInt(args[4],16);
   Address dataDestination = toAddr(0x23000000L);
   byte[] data = getBytes(toAddr(dataSource),dataSize);
   MemoryBlock dataOld = memory.getBlock(dataDestination);
   if (dataOld.getSize() > dataSize) memory.split(dataOld,dataDestination.add(dataSize));
   memory.removeBlock(memory.getBlock(dataDestination),monitor);
   MemoryBlock initialized = memory.createInitializedBlock("radio_initial_data",dataDestination,new ByteArrayInputStream(data),dataSize,monitor,false);
   initialized.setRead(true); initialized.setWrite(true); initialized.setExecute(false);
  }
  byte[] content = getBytes(toAddr(lma),size);
  MemoryBlock old = memory.getBlock(toAddr(vma));
  if (!old.getStart().equals(toAddr(vma))) memory.split(old,toAddr(vma));
  old = memory.getBlock(toAddr(vma));
  if (old.getSize() > size) memory.split(old,toAddr(vma+size));
  memory.removeBlock(memory.getBlock(toAddr(vma)),monitor);
  MemoryBlock runtime = memory.createInitializedBlock("radio_runtime_copy",toAddr(vma),new ByteArrayInputStream(content),size,monitor,false);
  runtime.setRead(true); runtime.setWrite(false); runtime.setExecute(true);
  // Retire incorrect execution-at-LMA interpretation. Keep original bytes as source data.
  ArrayList<Function> sourceFunctions = new ArrayList<>();
  for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
   long address = function.getEntryPoint().getOffset();
   if (address >= lma && address < lma+size) sourceFunctions.add(function);
  }
  for (Function function : sourceFunctions) removeFunction(function);
  clearListing(toAddr(lma),toAddr(lma+size-1));
  MemoryBlock source = memory.getBlock(toAddr(lma));
  if (!source.getStart().equals(toAddr(lma))) memory.split(source,toAddr(lma));
  source = memory.getBlock(toAddr(lma));
  if (source.getSize() > size) memory.split(source,toAddr(lma+size));
  memory.getBlock(toAddr(lma)).setExecute(false);
  TreeSet<Long> seeds = new TreeSet<>();
  for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
   long address = function.getEntryPoint().getOffset();
   if (address >= vma && address < vma+size) seeds.add(address);
  }
  // Static aligned pointers from the firmware image are candidates, not named semantics.
  for (MemoryBlock block : memory.getBlocks()) {
   if (!block.isInitialized() || block.getStart().getOffset() >= 0x10000000L) continue;
   for (long address = block.getStart().getOffset(); address+4 <= block.getEnd().getOffset()+1; address+=4) {
    long value = Integer.toUnsignedLong(getInt(toAddr(address)));
    if ((value & 1) == 1 && value >= vma && value < vma+size) seeds.add(value & ~1L);
   }
  }
  seeds.add(vma);
  for (long value : seeds) {
   Address target = toAddr(value);
   if (getInstructionContaining(target) != null && getInstructionAt(target) == null) continue;
   if (getInstructionAt(target) == null) {
    currentProgram.getProgramContext().setValue(currentProgram.getRegister("TMode"),target,target,java.math.BigInteger.ONE);
    disassemble(target);
   }
   if (getFunctionAt(target) == null && getInstructionAt(target) != null) createFunction(target,"ram_candidate_"+target);
  }
  println("Mapped verified startup copy "+Long.toHexString(lma)+" -> "+Long.toHexString(vma)+" size="+Integer.toHexString(size)+" pointer_seeds="+seeds.size());
 }
}
