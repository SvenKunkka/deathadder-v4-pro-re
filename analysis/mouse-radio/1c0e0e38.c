/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e0e38. Types and names are inferred; NOT original source. */

void FUN_1c0e0e38(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined2 *puVar6;
  uint uVar7;
  
  *DAT_1c0e0ea0 = 0;
  pcVar2 = DAT_1c0e0ea4;
  if (param_1 == 0) {
    FUN_1c0d9ad8();
    FUN_1c0e4114();
  }
  else {
    cVar1 = *DAT_1c0e0ea4;
    *DAT_1c0e0ea8 = 0;
    if (cVar1 == '\0') {
      FUN_1c0d9b00();
      *pcVar2 = '\x01';
    }
    FUN_1c0e4034();
    uVar7 = *(uint *)(DAT_1c0e0eac + 0x1f);
    FUN_1c0d98ec(uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 |
                 uVar7 >> 0x18,*(undefined1 *)(DAT_1c0e0eb0 + 3),DAT_1c0e0eac,DAT_1c0e0eb0,param_4);
    FUN_1c0d9a90();
  }
  FUN_1c0df510();
  FUN_1c0e3d6c();
  FUN_1c0e3f1c();
  puVar3 = DAT_1c0e0eb8;
  *DAT_1c0e0eb4 = 0;
  puVar6 = DAT_1c0e0ec8;
  puVar5 = DAT_1c0e0ec0;
  puVar4 = DAT_1c0e0ebc;
  *DAT_1c0e0ec4 = 0;
  *puVar3 = 0;
  *puVar4 = 0;
  *puVar5 = 0;
  *puVar6 = 0;
  return;
}


