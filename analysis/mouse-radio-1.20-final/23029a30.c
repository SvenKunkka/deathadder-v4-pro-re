/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23029a30. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23029a30(void)

{
  byte bVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = ~DAT_23001458 & 0xe080 & DAT_2300145c;
  if (uVar7 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = 0;
    uVar2 = uVar7;
    do {
      bVar1 = (byte)(uVar2 >> 8);
      iVar4 = LZCOUNT((uVar2 >> 7 & 1) << 0x18 |
                      (uint)(byte)(((bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7) <<
                      0x10);
      piVar5 = (int *)(iVar4 * 4 + 0x5f99c100);
      if (((uVar7 & 1 << iVar4) != 0) && (*piVar5 != 0)) {
        *piVar5 = 0;
        uVar8 = uVar8 | 1 << iVar4;
      }
      uVar2 = uVar2 & ~(1 << iVar4);
    } while (uVar2 != 0);
  }
  puVar6 = &DAT_23001454;
  uVar8 = _DAT_5f99c350 & uVar8;
  do {
    bVar1 = puVar6[0x14];
    if ((1 << (uint)bVar1 & uVar8) != 0) {
      pcVar3 = *(code **)(puVar6 + 0xc);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)((uint)bVar1,pcVar3,*(undefined4 *)((short)(ushort)bVar1 * 0x10 + 0x5f99c520),
                  *(undefined4 *)((short)(ushort)bVar1 * 0x10 + 0x5f99c524),
                  *(undefined4 *)(puVar6 + 0x10));
      }
    }
    puVar6 = puVar6 + 0xc;
  } while (puVar6 != (undefined1 *)0x23001484);
  return;
}


