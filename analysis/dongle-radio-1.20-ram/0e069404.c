/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069404. Types and names are inferred; NOT original source. */

undefined4 FUN_0e069404(int *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  bVar1 = *(byte *)(param_1 + 1);
  iVar3 = (uint)bVar1 * 0xa4;
  if ((&DAT_23000a08)[iVar3] == '\0') {
    FUN_0e06f3aa(&DAT_23000978 + iVar3,0,0x80);
    uVar4 = *(uint *)(&DAT_230009f8 + iVar3);
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
    FUN_0e0612ac(0x69);
    iVar3 = (uint)bVar1 * 0xa4;
    (&DAT_23000a08)[iVar3] = 1;
    *(undefined4 *)(&DAT_23000a00 + iVar3) = 1;
    return 0xbad0000;
  }
  return 0xbad000c;
}


