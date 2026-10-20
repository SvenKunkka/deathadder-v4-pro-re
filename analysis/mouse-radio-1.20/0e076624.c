/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e076624. Types and names are inferred; NOT original source. */

undefined4 FUN_0e076624(uint *param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  dword *pdVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  
  pdVar6 = (dword *)*param_1;
  uVar10 = *param_2;
  if ((pdVar6 == (dword *)0x5f8e2000) || (pdVar6 == (dword *)0x5f8e3000)) {
    uVar7 = 320000000;
    uVar9 = 320000000 / uVar10;
    if (uVar10 * uVar9 != 320000000) {
      return 0xbad0004;
    }
  }
  else if (((pdVar6 == &TIMER020_S_TASKS_START) || (pdVar6 == &TIMER021_S_TASKS_START)) ||
          (pdVar6 == &TIMER022_S_TASKS_START)) {
    uVar7 = 32000000;
    uVar9 = 32000000 / uVar10;
    if (uVar10 * uVar9 != 32000000) {
      return 0xbad0004;
    }
  }
  else {
    uVar7 = 16000000;
    uVar9 = 16000000 / uVar10;
    if (uVar10 * uVar9 != 16000000) {
      return 0xbad0004;
    }
  }
  if (((uVar10 <= uVar7) && ((uVar9 - 1 & uVar9) == 0)) && (uVar9 < 0x201)) {
    uVar7 = uVar7 / uVar10;
    bVar3 = (byte)uVar7;
    bVar4 = (byte)(uVar7 >> 8);
    bVar5 = (byte)(uVar7 >> 0x10);
    bVar2 = (byte)(uVar7 >> 0x18);
    bVar1 = *(byte *)((int)param_2 + 5);
    pdVar6[0x141] = (byte)param_2[1] & 3 | pdVar6[0x141] & 0xfffffffc;
    pdVar6[0x142] = pdVar6[0x142] & 0xfffffffc | bVar1 & 3;
    pdVar6[0x144] =
         LZCOUNT((uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1 |
                                 bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1
                              | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x18 |
                 (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1 |
                                 bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1
                              | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 0x10 |
                 (uint)(byte)((((((((bVar5 & 1) << 1 | bVar5 >> 1 & 1) << 1 | bVar5 >> 2 & 1) << 1 |
                                 bVar5 >> 3 & 1) << 1 | bVar5 >> 4 & 1) << 1 | bVar5 >> 5 & 1) << 1
                              | bVar5 >> 6 & 1) << 1 | bVar5 >> 7) << 8 |
                 (uint)(byte)((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                               bVar2 >> 3 & 1) << 1 | bVar2 >> 4) << 3));
    uVar10 = *param_1;
    puVar8 = (undefined4 *)(uVar10 + 0x140);
    do {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    } while ((undefined4 *)(uVar10 + 0x160) != puVar8);
    FUN_0e078e0c((uVar10 & 0x1fffff) >> 0xc);
    return 0xbad0000;
  }
  return 0xbad0004;
}


