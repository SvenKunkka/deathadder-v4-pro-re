/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0694a0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0694a0(int *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = DAT_0e069518;
  bVar1 = *(byte *)(param_1 + 1);
  iVar3 = (uint)bVar1 * 0xa4 + DAT_0e069518;
  if (*(char *)(iVar3 + 0xa0) == '\0') {
    FUN_0e06f446(iVar3 + 0x10,0,0x80);
    uVar4 = *(uint *)(iVar3 + 0x90);
    iVar3 = *param_1;
    if (uVar4 != 0) {
      uVar2 = 0;
      do {
        if ((uVar2 & 0xff) == 0x15) {
          *(undefined4 *)(iVar3 + (uVar2 & 0xff) * 4 + 0x100) = 0;
        }
        uVar2 = uVar2 + 1;
      } while (uVar4 != uVar2);
    }
    *(undefined4 *)(iVar3 + 0x154) = 0;
    FUN_0e0613ac(0x69);
    iVar5 = (uint)bVar1 * 0xa4 + iVar5;
    *(undefined1 *)(iVar5 + 0xa0) = 1;
    *(undefined4 *)(iVar5 + 0x98) = 1;
    return DAT_0e069520;
  }
  return DAT_0e06951c;
}


