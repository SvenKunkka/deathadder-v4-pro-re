/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ac90. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06ac90(uint *param_1)

{
  int iVar1;
  uint *puVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = *param_1;
  uVar5 = param_1[5];
  iVar1 = FUN_0e06ac0c();
  if (iVar1 != 0xf) {
    return DAT_0e06ace8;
  }
  if ((uVar4 & -uVar5 & 0xffffff) >> 0x10 != (-param_1[5] >> 0x10 & 0x92)) {
    bVar3 = 0;
    do {
      uVar4 = FUN_0e06ac6c();
      uVar5 = (uint)bVar3;
      bVar3 = bVar3 + 1;
      if (uVar4 <= uVar5) {
        return 0;
      }
      puVar2 = (uint *)FUN_0e06ac70(uVar5);
    } while (*puVar2 != *param_1);
  }
  return DAT_0e06ace4;
}


