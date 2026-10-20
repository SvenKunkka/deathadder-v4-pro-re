/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0622b8. Types and names are inferred; NOT original source. */

void FUN_0e0622b8(int param_1,uint param_2)

{
  bool bVar1;
  longlong lVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 local_24;
  
  uVar6 = DAT_0e062340;
  iVar5 = DAT_0e06233c;
  uVar4 = DAT_0e062338;
  puVar3 = DAT_0e062334;
  if (param_2 != 0) {
    do {
      uVar9 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar9 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar7 = getBasePriority(), uVar7 == 0 || 0x40 < uVar7)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar7 = FUN_0e0685dc();
      uVar8 = uVar7 + *puVar3;
      lVar2 = (ulonglong)uVar8 * (ulonglong)uVar4 +
              CONCAT44(uVar4 * (puVar3[1] + (uint)CARRY4(uVar7,*puVar3)) + iVar5 * uVar8,uVar6);
      local_24 = (undefined4)((ulonglong)lVar2 >> 0x20);
      *(longlong *)puVar3 = lVar2;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar9);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar7 = param_2;
      if (3 < param_2) {
        uVar7 = 4;
      }
      FUN_0e06f3f8(param_1,&local_24,uVar7);
      param_2 = param_2 - uVar7;
      param_1 = param_1 + uVar7;
    } while (param_2 != 0);
    return;
  }
  return;
}


