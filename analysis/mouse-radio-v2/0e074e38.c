/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e074e38. Types and names are inferred; NOT original source. */

void FUN_0e074e38(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined2 *puVar6;
  uint uVar7;
  
  *DAT_0e074ea0 = 0;
  pcVar2 = DAT_0e074ea4;
  if (param_1 == 0) {
    FUN_0e06dad8();
    FUN_0e078114();
  }
  else {
    cVar1 = *DAT_0e074ea4;
    *DAT_0e074ea8 = 0;
    if (cVar1 == '\0') {
      FUN_0e06db00();
      *pcVar2 = '\x01';
    }
    FUN_0e078034();
    uVar7 = *(uint *)(DAT_0e074eac + 0x1f);
    FUN_0e06d8ec(uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 |
                 uVar7 >> 0x18,*(undefined1 *)(DAT_0e074eb0 + 3),DAT_0e074eac,DAT_0e074eb0,param_4);
    FUN_0e06da90();
  }
  FUN_0e073510();
  FUN_0e077d6c();
  FUN_0e077f1c();
  puVar3 = DAT_0e074eb8;
  *DAT_0e074eb4 = 0;
  puVar6 = DAT_0e074ec8;
  puVar5 = DAT_0e074ec0;
  puVar4 = DAT_0e074ebc;
  *DAT_0e074ec4 = 0;
  *puVar3 = 0;
  *puVar4 = 0;
  *puVar5 = 0;
  *puVar6 = 0;
  return;
}


