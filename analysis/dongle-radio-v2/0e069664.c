/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069664. Types and names are inferred; NOT original source. */

void FUN_0e069664(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = (uint)*(byte *)(param_1 + 2);
  if (uVar7 == 7) {
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
    if (uVar7 != 0xd) {
      uVar4 = 0xd;
      uVar3 = 0xe000;
      do {
        uVar3 = uVar3 & ~(1 << uVar4);
        bVar1 = (byte)(uVar3 >> 8);
        uVar4 = LZCOUNT((uint)(byte)(((bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7) <<
                        0x10);
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar7 != uVar4);
    }
  }
  *(undefined4 *)(uVar7 * 0x10 + 0x5f99c52c) = 0;
  iVar2 = DAT_0e0696dc;
  iVar6 = DAT_0e0696dc + uVar5 * 0xc;
  *(undefined4 *)(iVar6 + 0xc) = *param_1;
  *(undefined4 *)(iVar6 + 0x10) = param_1[1];
  bVar1 = *(byte *)(param_1 + 2);
  uVar7 = *(uint *)(iVar2 + 8);
  *(byte *)(iVar6 + 0x14) = bVar1;
  *(uint *)(iVar2 + 8) = uVar7 | 1 << (uint)bVar1;
  return;
}


