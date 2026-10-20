/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230290e4. Types and names are inferred; NOT original source. */

undefined4 FUN_230290e4(int *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  bVar1 = *(byte *)(param_1 + 1);
  iVar3 = (uint)bVar1 * 0xa4;
  if ((&DAT_230013ac)[iVar3] == '\0') {
    thunk_FUN_0e0973ea(&DAT_2300131c + iVar3,0,0x80);
    uVar4 = *(uint *)(&DAT_2300139c + iVar3);
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
    thunk_FUN_0e089e2c(0x69);
    iVar3 = (uint)bVar1 * 0xa4;
    (&DAT_230013ac)[iVar3] = 1;
    *(undefined4 *)(&DAT_230013a4 + iVar3) = 1;
    return 0xbad0000;
  }
  return 0xbad000c;
}


