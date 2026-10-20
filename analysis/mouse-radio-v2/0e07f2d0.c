/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f2d0. Types and names are inferred; NOT original source. */

void FUN_0e07f2d0(void)

{
  ushort *puVar1;
  uint *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte bVar5;
  uint uVar6;
  undefined1 uVar7;
  
  puVar2 = DAT_0e07f2bc;
  puVar1 = DAT_0e07f2b8;
  if ((((*DAT_0e07f2f0 == '\0') && (*DAT_0e07f2f4 == '\0')) && (*DAT_0e07f2f8 == '\0')) &&
     (*DAT_0e07f2fc != '\0')) {
    if ((uint)*DAT_0e07f2b8 <= *DAT_0e07f2bc) {
      return;
    }
    bVar5 = *DAT_0e07f2c0 + 1;
    if ((*DAT_0e07f2c0 & 1) == 0) {
      uVar7 = 0x1a;
    }
    else {
      uVar7 = 0;
    }
    if (bVar5 < 4) {
      uVar6 = 0x6e;
    }
    else {
      bVar5 = 0;
      uVar6 = 1000;
    }
    *DAT_0e07f2c0 = bVar5;
    *puVar2 = uVar6;
    puVar3 = DAT_0e07f2c8;
    *DAT_0e07f2c4 = uVar7;
    puVar4 = DAT_0e07f2cc;
    *puVar3 = 0;
    *puVar4 = 0;
    *puVar1 = 0;
    return;
  }
  return;
}


