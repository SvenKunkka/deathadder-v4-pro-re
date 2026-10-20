/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0d95c0. Types and names are inferred; NOT original source. */

void FUN_1c0d95c0(uint param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  puVar1 = DAT_1c0d95dc;
  puVar4 = (undefined4 *)(DAT_1c0d95d8 + (param_1 & 0xf) * 0x10);
  uVar2 = puVar4[1];
  uVar3 = puVar4[2];
  uVar5 = puVar4[3];
  *DAT_1c0d95dc = *puVar4;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  puVar1[3] = uVar5;
  return;
}


