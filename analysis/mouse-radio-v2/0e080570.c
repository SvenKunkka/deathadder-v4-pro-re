/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e080570. Types and names are inferred; NOT original source. */

void FUN_0e080570(undefined1 param_1,undefined1 param_2)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  ushort *puVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  
  puVar3 = DAT_0e0805a8;
  puVar2 = DAT_0e0805a4;
  uVar6 = (uint)*DAT_0e0805a0;
  bVar7 = (byte)(uVar6 + 1);
  if (7 < (uVar6 + 1 & 0xff)) {
    bVar7 = 0;
  }
  *DAT_0e0805a0 = bVar7;
  puVar4 = DAT_0e0805ac;
  *puVar3 = param_1;
  uVar1 = *puVar4;
  *puVar2 = param_2;
  *puVar4 = uVar1 | 0x80;
  iVar5 = DAT_0e0805b4;
  *(undefined1 *)(DAT_0e0805b0 + uVar6) = param_1;
  *(undefined1 *)(iVar5 + uVar6) = param_2;
  return;
}


