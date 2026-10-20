/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e24a4. Types and names are inferred; NOT original source. */

int FUN_1c0e24a4(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = DAT_1c0e24ec;
  uVar3 = (uint)*(byte *)(param_1 + 4);
  iVar4 = DAT_1c0e24ec + uVar3 * 0xc;
  if (*(char *)(iVar4 + 8) == '\0') {
    *(undefined4 *)(DAT_1c0e24ec + uVar3 * 0xc) = param_3;
    if (param_2 == 0) {
      bVar2 = true;
      iVar4 = DAT_1c0e24f0;
    }
    else {
      *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(param_2 + 8);
      iVar4 = FUN_1c0e2628();
      bVar2 = iVar4 == DAT_1c0e24f0;
    }
    *(bool *)(iVar1 + uVar3 * 0xc + 8) = bVar2;
    return iVar4;
  }
  return DAT_1c0e24f4;
}


