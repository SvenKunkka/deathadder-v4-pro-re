/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069bec. Types and names are inferred; NOT original source. */

undefined4 FUN_0e069bec(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = DAT_0e069c38;
  uVar2 = (uint)*(byte *)(param_1 + 4);
  iVar3 = DAT_0e069c38 + uVar2 * 0x14;
  if (*(char *)(iVar3 + 8) == '\0') {
    *(undefined4 *)(DAT_0e069c38 + uVar2 * 0x14) = param_3;
    *(undefined4 *)(iVar3 + 4) = param_4;
    if (param_2 != 0) {
      *(undefined1 *)(iVar3 + 0x10) = *(undefined1 *)(param_2 + 0x1c);
      FUN_0e069ac0();
    }
    *(undefined1 *)(iVar1 + uVar2 * 0x14 + 8) = 1;
    return DAT_0e069c3c;
  }
  return DAT_0e069c40;
}


