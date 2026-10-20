// Establish Cortex-M vector entry points; no device access.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.DWordDataType;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;

public class SetupRadio extends GhidraScript {
 public void run() throws Exception {
  MemoryBlock code = currentProgram.getMemory().getBlocks()[0];
  Address base = code.getStart();
  code.setExecute(true);
  code.setWrite(false);
  // Nordic nRF54H20 radio-local RAM, 192 KiB.
  MemoryBlock ram = currentProgram.getMemory().createUninitializedBlock("radio_ram", toAddr(0x23000000L), 0x30000, false);
  ram.setRead(true); ram.setWrite(true); ram.setExecute(false);
  if (getScriptArgs().length > 0) {
   for (String line : java.nio.file.Files.readAllLines(java.nio.file.Path.of(getScriptArgs()[0]))) {
    String[] fields = line.split("\\t");
    Address address = toAddr(Long.parseUnsignedLong(fields[2],16));
    if (fields[0].equals("B")) {
     if (currentProgram.getMemory().getBlock(address) == null) {
      MemoryBlock block = currentProgram.getMemory().createUninitializedBlock(fields[1],address,Long.parseLong(fields[3],16),false);
      block.setRead(true); block.setWrite(true); block.setVolatile(true);
     }
    } else {
     if (getDataAt(address) == null) createData(address,DWordDataType.dataType);
     createLabel(address,fields[1],true);
    }
   }
  }
  // Only architecturally defined core vectors, not unverified peripheral IRQ slots.
  for (int i = 0; i < 16; i++) {
   Address slot = base.add(i * 4);
   long value = Integer.toUnsignedLong(getInt(slot));
   createData(slot, DWordDataType.dataType);
   if (i > 0 && (value & 1) != 0) {
    Address target = toAddr(value & ~1L);
    if (code.contains(target)) {
     if (getInstructionAt(target) == null) {
      currentProgram.getProgramContext().setValue(currentProgram.getRegister("TMode"), target, target, java.math.BigInteger.ONE);
      disassemble(target);
     }
     if (getFunctionAt(target) == null) createFunction(target, i == 1 ? "Reset_Handler" : "vector_" + i);
     currentProgram.getSymbolTable().addExternalEntryPoint(target);
    }
   }
  }
  println("Core vectors seeded at " + base);
 }
}
