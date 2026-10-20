/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07e9e8. Types and names are inferred; NOT original source. */

void FUN_0e07e9e8(int param_1,int param_2,int param_3,int param_4,byte param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(uint *)(param_3 + 9) != 0) {
    uVar3 = (((uint)*(byte *)(param_1 + 5) * *(int *)(param_3 + 5)) / *(uint *)(param_3 + 9) + 1) *
            0xff >> 8;
  }
  if (param_5 != 0) {
    uVar3 = (uVar3 + 1) * 0xff >> 8;
    iVar1 = param_4;
    do {
      iVar2 = iVar1 + 6;
      *(char *)(iVar1 + 3) = (char)(uVar3 * *(byte *)(param_2 + 4) + 0xff >> 8);
      *(char *)(iVar1 + 4) = (char)(uVar3 * *(byte *)(param_2 + 5) + 0xff >> 8);
      *(char *)(iVar1 + 5) = (char)(uVar3 * *(byte *)(param_2 + 6) + 0xff >> 8);
      iVar1 = iVar2;
      param_2 = param_2 + 0xc;
    } while (iVar2 != (short)(ushort)param_5 * 6 + param_4);
  }
  if ((((DAT_2300778e == '\0') && (DAT_2300772f == '\0')) && (DAT_23007758 == '\0')) &&
     (((DAT_2300775d == '\0' && (DAT_2300775e == '\0')) &&
      ((DAT_23007755 == '\0' && (DAT_23007763 == '\0')))))) {
    if (DAT_230077a2 == '\0') {
      DAT_23007743 = DAT_230077a2;
      DAT_23007742 = DAT_230077a2;
      DAT_23007741 = DAT_230077a2;
      return;
    }
    DAT_23007743 = *(undefined1 *)(param_4 + 3);
    DAT_23007742 = *(undefined1 *)(param_4 + 4);
    DAT_23007741 = *(undefined1 *)(param_4 + 5);
  }
  return;
}


