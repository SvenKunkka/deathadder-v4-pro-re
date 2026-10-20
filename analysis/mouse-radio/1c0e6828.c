/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e6828. Types and names are inferred; NOT original source. */

void FUN_1c0e6828(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  sbyte *psVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  
  psVar5 = DAT_1c0e6884;
  FUN_1c0e64d8();
  if (param_1 == 0) {
    FUN_1c0fe750(*psVar5,DAT_1c0e688c,DAT_1c0e6898);
    uVar7 = 4;
  }
  else {
    FUN_1c0fe750(*psVar5,DAT_1c0e688c,DAT_1c0e6888);
    uVar7 = 0x10;
  }
  puVar6 = DAT_1c0e6890;
  *DAT_1c0e6890 = *DAT_1c0e6890 | uVar7;
  FUN_1c0fe690(*psVar5,DAT_1c0e6894);
  *puVar6 = *puVar6 | 0x10000;
  uVar7 = 1 << *psVar5;
  if (uVar7 != 0) {
    do {
      bVar2 = (byte)uVar7;
      bVar3 = (byte)(uVar7 >> 8);
      bVar4 = (byte)(uVar7 >> 0x10);
      bVar1 = (byte)(uVar7 >> 0x18);
      iVar8 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1)
                                       << 1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                    bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) <<
                      0x18 | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
                                              bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
                                            bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                                          bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                      (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1)
                                       << 1 | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 |
                                    bVar4 >> 5 & 1) << 1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                      (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1)
                                       << 1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                    bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
      FUN_1c0fe0f8(iVar8,1);
      uVar7 = uVar7 & ~(1 << iVar8);
    } while (uVar7 != 0);
    return;
  }
  return;
}


