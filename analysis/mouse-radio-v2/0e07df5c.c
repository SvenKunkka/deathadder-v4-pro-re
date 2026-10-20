/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07df5c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e07df5c(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined1 auStack_1c [4];
  uint local_18;
  
  uVar3 = DAT_0e07df84;
  puVar1 = DAT_0e07df80;
  puVar5 = DAT_0e07df7c;
  *DAT_0e07df80 = 0;
  *puVar5 = uVar3;
  iVar2 = FUN_0e094688();
  if (iVar2 != 0) {
    *puVar1 = 1;
  }
  puVar8 = DAT_0e07df54 + 0x5a;
  puVar5 = DAT_0e07df54;
  puVar7 = DAT_0e07df58;
  do {
    puVar5[0xe] = *puVar7;
    iVar2 = FUN_0e094688();
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    uVar3 = puVar7[1];
    *puVar5 = uVar3;
    iVar2 = FUN_0e08ff98(puVar5[0xe],uVar3,auStack_1c);
    if (iVar2 != 0) {
      return 0xffffffea;
    }
    uVar4 = puVar7[2];
    puVar5[6] = local_18;
    puVar5[7] = uVar4 / local_18;
    puVar6 = puVar5 + 0x12;
    puVar7 = puVar7 + 3;
    iVar2 = FUN_0e087098(puVar5);
    if (iVar2 != 0) {
      return 0xffffffea;
    }
    puVar5 = puVar6;
  } while (puVar6 != puVar8);
  return 0;
}


