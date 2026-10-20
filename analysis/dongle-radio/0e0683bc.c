/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0683bc. Types and names are inferred; NOT original source. */

uint FUN_0e0683bc(int param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_0e0613f0(0x1c4,1,0);
  iVar1 = FUN_0e069bec(*(int *)(param_1 + 4),*(int *)(param_1 + 4) + 8,DAT_0e0683f4,
                       *(undefined4 *)(param_1 + 0x10));
  if (iVar1 == DAT_0e0683f8) {
    uVar2 = FUN_0e06816c(param_1);
    return uVar2 & (int)uVar2 >> 0x1f;
  }
  return 0xfffffff0;
}


