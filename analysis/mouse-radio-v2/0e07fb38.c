/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07fb38. Types and names are inferred; NOT original source. */

uint FUN_0e07fb38(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_2 < param_1) {
    uVar3 = param_1 - param_2;
    uVar2 = param_2;
    param_2 = param_1;
  }
  else {
    uVar3 = param_2 - param_1;
    uVar2 = param_1;
    if (uVar3 == 0) {
      return param_2;
    }
  }
  uVar5 = 0xffffffff;
  if (-1 < (int)uVar3) {
    uVar4 = 0x80000000;
    do {
      uVar4 = uVar4 >> 1;
      uVar5 = uVar5 >> 1;
    } while ((uVar4 & uVar3) == 0);
  }
  uVar3 = *DAT_0e07fbb8;
  do {
    iVar1 = (int)((int)((ulonglong)((longlong)DAT_0e07fbbc * (longlong)(int)uVar3) >> 0x20) + uVar3)
            >> 0x10;
    uVar3 = (((int)uVar3 >> 0x1f) - iVar1) * 0xb14 +
            (uVar3 - DAT_0e07fbc0 * (iVar1 - ((int)uVar3 >> 0x1f))) * 0x41a7;
    if ((int)uVar3 < 1) {
      uVar3 = uVar3 + 0x7fffffff;
    }
    uVar4 = (uVar3 & uVar5) + uVar2;
  } while (param_2 < uVar4);
  *DAT_0e07fbb8 = uVar3;
  return uVar4;
}


