/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07e048. Types and names are inferred; NOT original source. */

void FUN_0e07e048(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)(DAT_0e07e0e4 + 0x6d4) = 0;
  iVar3 = DAT_0e07e0e8;
  iVar2 = FUN_0e094688(DAT_0e07e0e8);
  iVar1 = DAT_0e07e0ec;
  if (iVar2 == 0) {
    iVar3 = FUN_0e094688(DAT_0e07e0ec);
  }
  else {
    puVar4 = *(undefined4 **)(iVar3 + 8);
    **(uint **)(iVar3 + 0x10) = **(uint **)(iVar3 + 0x10) & 0xfffffffd;
    (*(code *)*puVar4)(iVar3,1,0x60000);
    iVar1 = DAT_0e07e0ec;
    iVar3 = FUN_0e094688(DAT_0e07e0ec);
  }
  if (iVar3 == 0) {
    iVar3 = FUN_0e094688(DAT_0e07e0ec);
  }
  else {
    puVar4 = *(undefined4 **)(iVar1 + 8);
    **(uint **)(iVar1 + 0x10) = **(uint **)(iVar1 + 0x10) & 0xfffffeff;
    (*(code *)*puVar4)(iVar1,8,0x60000);
    iVar3 = FUN_0e094688(DAT_0e07e0ec);
  }
  if (iVar3 != 0) {
    puVar4 = *(undefined4 **)(iVar1 + 8);
    **(uint **)(iVar1 + 0x10) = **(uint **)(iVar1 + 0x10) & 0xfffff7ff;
    (*(code *)*puVar4)(DAT_0e07e0ec,0xb,0x60000);
  }
  FUN_0e084e04();
  FUN_0e085508();
  FUN_0e0977e8();
  FUN_0e07ed0c();
  return;
}


