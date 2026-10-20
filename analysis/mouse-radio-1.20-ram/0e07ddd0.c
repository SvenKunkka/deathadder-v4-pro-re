/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07ddd0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e07ddd0(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 auStack_1c [4];
  uint local_18;
  
  DAT_2300773c = 0;
  DAT_23004cd4 = &DAT_0e097994;
  iVar1 = FUN_0e094560();
  if (iVar1 != 0) {
    DAT_2300773c = 1;
  }
  puVar6 = &DAT_0e0990dc;
  puVar4 = &DAT_230019e0;
  do {
    puVar4[0xe] = *puVar6;
    iVar1 = FUN_0e094560();
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    uVar2 = puVar6[1];
    *puVar4 = uVar2;
    iVar1 = FUN_0e08fe70(puVar4[0xe],uVar2,auStack_1c);
    if (iVar1 != 0) {
      return 0xffffffea;
    }
    uVar3 = puVar6[2];
    puVar4[6] = local_18;
    puVar4[7] = uVar3 / local_18;
    puVar5 = puVar4 + 0x12;
    puVar6 = puVar6 + 3;
    iVar1 = FUN_0e086f0c(puVar4);
    if (iVar1 != 0) {
      return 0xffffffea;
    }
    puVar4 = puVar5;
  } while (puVar5 != (undefined4 *)&DAT_23001b48);
  return 0;
}


