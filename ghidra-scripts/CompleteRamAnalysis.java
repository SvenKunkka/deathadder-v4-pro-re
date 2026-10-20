import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.listing.*;
import java.util.*;

public class CompleteRamAnalysis extends GhidraScript {
 public void run() throws Exception {
  Memory memory = currentProgram.getMemory();
  MemoryBlock runtime = memory.getBlock("radio_runtime_copy");
  long start = runtime.getStart().getOffset(), end = runtime.getEnd().getOffset();
  TreeSet<Long> seeds = new TreeSet<>();
  for (MemoryBlock block : memory.getBlocks()) {
   if (!block.isInitialized() || block.getStart().getOffset() >= 0x24000000L) continue;
   for (long address = block.getStart().getOffset(); address+3 <= block.getEnd().getOffset(); address+=4) {
    long value = Integer.toUnsignedLong(getInt(toAddr(address)));
    if ((value & 1) == 1 && value >= start && value <= end) seeds.add(value & ~1L);
   }
  }
  int skipped=0;
  for (long value : seeds) {
   Address target = toAddr(value);
   if (getInstructionContaining(target) != null && getInstructionAt(target) == null) { skipped++; continue; }
   if (getInstructionAt(target) == null) {
    currentProgram.getProgramContext().setValue(currentProgram.getRegister("TMode"),target,target,java.math.BigInteger.ONE);
    disassemble(target);
   }
   if (getFunctionAt(target) == null && getInstructionAt(target) != null) createFunction(target,"ram_candidate_"+target);
  }
  println("RAM seed completion total="+seeds.size()+" skipped_mid_instruction="+skipped);
 }
}
