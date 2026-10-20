/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302678c. Types and names are inferred; NOT original source. */

void FUN_2302678c(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  if (param_1 == 1) {
    uVar6 = (uint)DAT_23004477;
    puVar2 = (undefined4 *)&DAT_23004a5c;
    puVar3 = (undefined4 *)(&DAT_230044ce + uVar6 * 0xf4);
    do {
      puVar5 = puVar3;
      puVar4 = puVar2;
      *puVar5 = *puVar4;
      puVar5[1] = puVar4[1];
      puVar5[2] = puVar4[2];
      puVar5[3] = puVar4[3];
      puVar2 = puVar4 + 4;
      puVar3 = puVar5 + 4;
    } while (puVar4 + 4 != &DAT_23004a7c);
    puVar5[4] = DAT_23004a7c;
    uVar1 = DAT_23004a8c;
    puVar5[5] = puVar4[5];
    puVar5[6] = puVar4[6];
    *(undefined4 *)(&DAT_230044ca + uVar6 * 0xf4) = uVar1;
    return;
  }
  if (param_1 != 0) {
    return;
  }
  FUN_23026800();
  return;
}


