/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e4ec. Types and names are inferred; NOT original source. */

void FUN_0e06e4ec(undefined *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)DAT_23007178;
  iVar2 = uVar1 * 0x18 + 0x23002c60;
  FUN_0e06e768(iVar2);
  (&DAT_2300718c)[uVar1] = 0;
  if ((((*(ushort *)(param_1 + 0xe) < 0x80) && (DAT_23007194 != 0)) &&
      (DAT_23007190 <= (char)param_1[0xe])) &&
     (((param_1[0xd] & 0x1f) == 0 && (param_1 != &DAT_230029f8)))) {
    FUN_0e06e648(iVar2,&LAB_0e06e4c8_1,DAT_23007194 + -1,DAT_23007194 + -1 >> 0x1f);
    return;
  }
  return;
}


