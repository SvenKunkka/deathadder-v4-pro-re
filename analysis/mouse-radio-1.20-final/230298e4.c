/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230298e4. Types and names are inferred; NOT original source. */

void FUN_230298e4(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = (uint)*(byte *)(param_1 + 2);
  if (uVar5 == 7) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
    if (uVar5 != 0xd) {
      uVar3 = 0xd;
      uVar2 = 0xe000;
      do {
        uVar2 = uVar2 & ~(1 << uVar3);
        bVar1 = (byte)(uVar2 >> 8);
        uVar3 = LZCOUNT((uint)(byte)(((bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7) <<
                        0x10);
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar5 != uVar3);
    }
  }
  *(undefined4 *)(uVar5 * 0x10 + 0x5f99c52c) = 0;
  (&DAT_23001460)[uVar4 * 3] = *param_1;
  (&DAT_23001464)[uVar4 * 3] = param_1[1];
  bVar1 = *(byte *)(param_1 + 2);
  (&DAT_23001468)[uVar4 * 0xc] = bVar1;
  DAT_2300145c = DAT_2300145c | 1 << (uint)bVar1;
  return;
}


