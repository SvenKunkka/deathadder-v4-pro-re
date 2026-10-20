/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b142a. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 thunk_FUN_0e0af688(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 8) == 0) {
    uVar3 = 0xffffffea;
  }
  else if (*(int *)(param_1 + 8) == _DAT_2f011ba0) {
    if (*(uint *)(param_1 + 0xc) < 2) {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      FUN_0e0b2268(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x10),_DAT_2f011ba0,0x20,
                   param_4);
      iVar4 = FUN_0e0b2596(param_1);
      *(int *)(param_1 + 8) = iVar4;
      if (iVar4 == 0) {
        *(undefined4 *)(param_1 + 0xc) = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar3);
        }
        InstructionSynchronizationBarrier(0xf);
      }
      else {
        *(int *)(param_1 + 0x10) = (int)*(char *)(iVar4 + 0xe);
        *(undefined4 *)(iVar4 + 0x88) = 0;
        FUN_0e0b24cc();
        FUN_0e0afeac(0x2f011bda,uVar3);
      }
    }
    else {
      *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) - 1;
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


