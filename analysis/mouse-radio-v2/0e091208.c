/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091208. Types and names are inferred; NOT original source. */

undefined4 FUN_0e091208(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = DAT_0e091254;
  uVar2 = (uint)*(byte *)(param_1 + 4);
  iVar3 = DAT_0e091254 + uVar2 * 0x14;
  if (*(char *)(iVar3 + 8) == '\0') {
    *(undefined4 *)(DAT_0e091254 + uVar2 * 0x14) = param_3;
    *(undefined4 *)(iVar3 + 4) = param_4;
    if (param_2 != 0) {
      *(undefined1 *)(iVar3 + 0x10) = *(undefined1 *)(param_2 + 0x1c);
      FUN_0e0910dc();
    }
    *(undefined1 *)(iVar1 + uVar2 * 0x14 + 8) = 1;
    return DAT_0e091258;
  }
  return DAT_0e09125c;
}


