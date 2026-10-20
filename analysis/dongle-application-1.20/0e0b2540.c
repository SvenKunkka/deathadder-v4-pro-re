/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b2540. Types and names are inferred; NOT original source. */

void FUN_0e0b2540(int param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  byte bVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  uVar6 = CONCAT44(param_2,param_1);
  uVar5 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar5 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  cVar1 = *(char *)(param_1 + 0x6c);
  *(undefined1 *)(param_1 + 0x6c) = 0;
  if (((cVar1 == '\0') || (param_2 == 0)) && ((*(byte *)(param_1 + 0xd) & 0x28) == 0)) {
    if (*(int *)(param_1 + 8) != 0) {
      uVar6 = FUN_0e0b2468();
    }
    bVar4 = *(byte *)((int)uVar6 + 0xd);
    if ((int)((ulonglong)uVar6 >> 0x20) == 0) {
      bVar4 = bVar4 & 0xfb;
    }
    else {
      bVar4 = bVar4 & 0xeb;
    }
    *(byte *)((int)uVar6 + 0xd) = bVar4;
    FUN_0e0afc14();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


