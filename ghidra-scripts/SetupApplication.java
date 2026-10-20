import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.data.DWordDataType;
public class SetupApplication extends GhidraScript {
 public void run() throws Exception {
  MemoryBlock code = currentProgram.getMemory().getBlocks()[0];
  code.setExecute(true); code.setWrite(false);
  Address base=code.getStart();
  for(int i=0;i<16;i++) {
   Address slot=base.add(i*4); long value=Integer.toUnsignedLong(getInt(slot));
   createData(slot,DWordDataType.dataType);
   if(i>0 && (value&1)==1 && code.contains(toAddr(value&~1L))) {
    Address target=toAddr(value&~1L);
    if(getInstructionContaining(target)!=null && getInstructionAt(target)==null)continue;
    if(getInstructionAt(target)==null)disassemble(target);
    if(getFunctionAt(target)==null)createFunction(target,i==1?"Reset_Handler":"vector_"+i);
    currentProgram.getSymbolTable().addExternalEntryPoint(target);
   }
  }
  println("Application flash vectors initialized, RAM extent intentionally not inferred");
 }
}
