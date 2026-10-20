/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e076628. Types and names are inferred; NOT original source. */

undefined4 FUN_0e076628(uint *param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  
  uVar6 = *param_1;
  uVar10 = *param_2;
  if ((uVar6 == DAT_0e0766ec) || (uVar6 == DAT_0e0766f0)) {
    uVar9 = DAT_0e076700 / uVar10;
    uVar7 = DAT_0e076700;
    if (DAT_0e076700 != uVar10 * uVar9) {
      return DAT_0e076704;
    }
  }
  else if (((uVar6 == DAT_0e0766f4) || (uVar6 == DAT_0e0766f4 + 0x1000)) ||
          (uVar6 == DAT_0e0766f4 + 0x2000)) {
    uVar9 = DAT_0e076708 / uVar10;
    uVar7 = DAT_0e076708;
    if (DAT_0e076708 != uVar10 * uVar9) {
      return DAT_0e076704;
    }
  }
  else {
    uVar9 = DAT_0e0766f8 / uVar10;
    uVar7 = DAT_0e0766f8;
    if (DAT_0e0766f8 != uVar10 * uVar9) {
      return DAT_0e076704;
    }
  }
  if (((uVar10 <= uVar7) && ((uVar9 - 1 & uVar9) == 0)) && (uVar9 < 0x201)) {
    uVar7 = uVar7 / uVar10;
    bVar3 = (byte)uVar7;
    bVar4 = (byte)(uVar7 >> 8);
    bVar5 = (byte)(uVar7 >> 0x10);
    bVar2 = (byte)(uVar7 >> 0x18);
    bVar1 = *(byte *)((int)param_2 + 5);
    *(uint *)(uVar6 + 0x504) = (byte)param_2[1] & 3 | *(uint *)(uVar6 + 0x504) & 0xfffffffc;
    *(uint *)(uVar6 + 0x508) = *(uint *)(uVar6 + 0x508) & 0xfffffffc | bVar1 & 3;
    *(int *)(uVar6 + 0x510) =
         LZCOUNT((uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1 |
                                 bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1
                              | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x18 |
                 (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1 |
                                 bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1
                              | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 0x10 |
                 (uint)(byte)((((((((bVar5 & 1) << 1 | bVar5 >> 1 & 1) << 1 | bVar5 >> 2 & 1) << 1 |
                                 bVar5 >> 3 & 1) << 1 | bVar5 >> 4 & 1) << 1 | bVar5 >> 5 & 1) << 1
                              | bVar5 >> 6 & 1) << 1 | bVar5 >> 7) << 8 |
                 (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                                 bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1
                              | bVar2 >> 6 & 1) << 1 | bVar2 >> 7));
    uVar6 = *param_1;
    puVar8 = (undefined4 *)(uVar6 + 0x140);
    do {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    } while ((undefined4 *)(uVar6 + 0x160) != puVar8);
    thunk_FUN_0e089fb8((uVar6 & 0x1fffff) >> 0xc);
    return DAT_0e0766fc;
  }
  return DAT_0e076704;
}


