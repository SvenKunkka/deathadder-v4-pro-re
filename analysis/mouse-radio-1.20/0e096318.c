/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e096318. Types and names are inferred; NOT original source. */

void FUN_0e096318(undefined *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)DAT_2300765c;
  iVar2 = uVar1 * 0x18 + 0x230025e0;
  FUN_0e096594(iVar2);
  (&DAT_23007674)[uVar1] = 0;
  if ((((*(ushort *)(param_1 + 0xe) < 0x80) && (DAT_2300767c != 0)) &&
      (DAT_23007678 <= (char)param_1[0xe])) &&
     (((param_1[0xd] & 0x1f) == 0 && (param_1 != &DAT_23002378)))) {
    FUN_0e096474(iVar2,&LAB_0e0962f4_1,DAT_2300767c + -1,DAT_2300767c + -1 >> 0x1f);
    return;
  }
  return;
}


