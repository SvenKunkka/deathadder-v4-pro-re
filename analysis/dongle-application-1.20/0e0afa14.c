/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0afa14. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0afa14(undefined4 param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_14;
  int iStack_10;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((*(uint *)(param_2 + 0xc) & 0x1e) == 0) {
    local_14 = param_1;
    iStack_10 = param_3;
    if (param_4 == 0 && param_3 == 0) {
      uVar3 = FUN_0e0af8d8(param_2,&local_14);
    }
    else {
      *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 8;
      *(undefined4 *)(param_2 + 0x28) = param_1;
      FUN_0e0b02bc(param_2 + 0x10,0xe0b2347,param_3,param_4,param_1);
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 0;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
}


