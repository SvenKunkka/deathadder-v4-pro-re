/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230213f0. Types and names are inferred; NOT original source. */

void FUN_230213f0(undefined1 *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar6;
  undefined1 uVar7;
  uint uVar8;
  undefined1 uVar9;
  byte bVar10;
  byte bVar11;
  byte local_19 [5];
  byte *pbVar5;
  
  uVar8 = 0xff;
  pbVar3 = &DAT_230003e8 + (byte)(&DAT_230003e0)[param_2 * 2];
  if ((byte)(&DAT_230003e1)[param_2 * 2] != 0) {
    pbVar5 = pbVar3;
    uVar6 = 0xff;
    bVar1 = 0;
    bVar10 = 0;
    do {
      while( true ) {
        bVar11 = bVar1;
        pbVar4 = pbVar5 + 1;
        uVar2 = (uint)*pbVar5;
        bVar1 = (&DAT_2300315c)[uVar2];
        pbVar5 = pbVar4;
        if (bVar1 < bVar11) break;
        uVar8 = uVar6;
        uVar6 = uVar2;
        bVar10 = bVar11;
        if (pbVar3 + (byte)(&DAT_230003e1)[param_2 * 2] == pbVar4) goto LAB_2302143e;
      }
      if (bVar10 <= bVar1) {
        uVar8 = uVar2;
        bVar10 = bVar1;
      }
      bVar1 = bVar11;
    } while (pbVar3 + (byte)(&DAT_230003e1)[param_2 * 2] != pbVar4);
LAB_2302143e:
    uVar7 = (undefined1)uVar8;
    uVar9 = (undefined1)uVar6;
    if (uVar6 != 0xff) goto joined_r0x23021444;
  }
  uVar7 = (undefined1)uVar8;
  thunk_FUN_0e0621b8(local_19,1);
  uVar6 = local_19[0] & 0xf;
  uVar9 = (&DAT_230003b8)
          [uVar6 - (((uint)((ulonglong)uVar6 * 0xcccccccd >> 0x20) & 0xc) + uVar6 / 5)];
joined_r0x23021444:
  if (uVar8 == 0xff) {
    thunk_FUN_0e0621b8(local_19,1);
    uVar8 = (uint)(local_19[0] >> 4);
    uVar7 = (&DAT_230003bd)
            [uVar8 - (((uint)((ulonglong)uVar8 * 0xcccccccd >> 0x20) & 0xc) + uVar8 / 5)];
    *param_1 = uVar9;
    param_1[1] = uVar7;
    return;
  }
  *param_1 = uVar9;
  param_1[1] = uVar7;
  return;
}


