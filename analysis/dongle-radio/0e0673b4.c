/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0673b4. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0673b4(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = DAT_0e067410;
  if (*(int *)(DAT_0e067410 + 0x404) << 0x1f < 0) {
    if ((param_1 == 0) || (param_2 == 0)) {
      uVar2 = 0xffffffea;
    }
    else {
      uVar3 = param_1 & 0xffffffe0 | 0x10000000;
      do {
        do {
        } while (*(int *)(iVar1 + 0x400) << 0x1f < 0);
        *(uint *)(iVar1 + 0x410) = uVar3;
        *(undefined4 *)(iVar1 + 0x18) = 1;
      } while ((uVar3 != *(uint *)(iVar1 + 0x410)) ||
              (uVar3 = uVar3 + 0x20, uVar3 < (param_1 | 0x10000000) + param_2));
      do {
      } while ((*(uint *)(DAT_0e067410 + 0x400) & 1) != 0);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xfffffff5;
  }
  return uVar2;
}


