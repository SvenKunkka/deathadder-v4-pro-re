/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ae8d4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0e0ae8d4(undefined4 *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  *param_1 = 0;
  param_1[1] = 0;
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  do {
  } while (0x3fffffff < _DAT_5f99c754);
  uVar3 = _DAT_5f99c754 & 0xfffff;
  *param_1 = _DAT_5f99c750;
  param_1[1] = uVar3;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar2);
  }
  InstructionSynchronizationBarrier(0xf);
  return CONCAT44(uVar2,0xbad0000);
}


