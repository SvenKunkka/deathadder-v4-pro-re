/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f9ac. Types and names are inferred; NOT original source. */

uint FUN_0e07f9ac(uint param_1,uint param_2)

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
  do {
    iVar1 = (int)DAT_230004fc / 0x1f31d + ((int)DAT_230004fc >> 0x1f);
    DAT_230004fc = ((int)DAT_230004fc >> 0x1f) * 0x7fffffff + iVar1 * -0xb14 +
                   DAT_230004fc * 0x41a7 + iVar1 * -0x7ffff4eb;
    if ((int)DAT_230004fc < 1) {
      DAT_230004fc = DAT_230004fc + 0x7fffffff;
    }
    uVar3 = (DAT_230004fc & uVar5) + uVar2;
  } while (param_2 < uVar3);
  return uVar3;
}


