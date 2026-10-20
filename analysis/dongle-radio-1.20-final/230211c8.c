/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230211c8. Types and names are inferred; NOT original source. */

void FUN_230211c8(int param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  undefined1 uVar6;
  byte bVar7;
  byte bVar8;
  byte local_19 [5];
  
  if (DAT_230031f7 == '\0') {
    thunk_FUN_0e0621b8(local_19,1);
    uVar5 = local_19[0] & 0xf;
    uVar3 = (uint)(local_19[0] >> 4);
    DAT_230031d2 = (&DAT_230003bd)
                   [uVar3 - (((uint)((ulonglong)uVar3 * 0xcccccccd >> 0x20) & 0xc) + uVar3 / 5)];
    DAT_230031d1 = (&DAT_230003b8)
                   [uVar5 - (((uint)((ulonglong)uVar5 * 0xcccccccd >> 0x20) & 0xc) + uVar5 / 5)];
    thunk_FUN_0e0621b8(local_19,1);
    uVar5 = local_19[0] & 0xf;
    uVar3 = (uint)(local_19[0] >> 4);
    DAT_230031d3 = (&DAT_230003c2)
                   [uVar5 - (((uint)((ulonglong)uVar5 * 0xcccccccd >> 0x20) & 0xc) + uVar5 / 5)];
    DAT_230031d4 = (&DAT_230003c7)
                   [uVar3 - (((uint)((ulonglong)uVar3 * 0xcccccccd >> 0x20) & 0xc) + uVar3 / 5)];
    thunk_FUN_0e0621b8(local_19,1);
    uVar5 = local_19[0] & 0xf;
    uVar3 = (uint)(local_19[0] >> 4);
    DAT_230031d5 = (&DAT_230003cc)
                   [uVar5 - (((uint)((ulonglong)uVar5 * 0xcccccccd >> 0x20) & 0xc) + uVar5 / 5)];
    DAT_230031d6 = (&DAT_230003d1)
                   [uVar3 - (((uint)((ulonglong)uVar3 * 0xcccccccd >> 0x20) & 0xc) + uVar3 / 5)];
    thunk_FUN_0e0621b8(local_19,1);
    uVar3 = local_19[0] & 0xf;
    uVar5 = (uint)(local_19[0] >> 4);
    DAT_230031d7 = (&DAT_230003d6)
                   [uVar3 - (((uint)((ulonglong)uVar3 * 0xcccccccd >> 0x20) & 0xc) + uVar3 / 5)];
    uVar3 = uVar5 - (((uint)((ulonglong)uVar5 * 0xaaaaaaab >> 0x20) & 0xe) + uVar5 / 3) & 0xff;
    if (uVar3 == 0) {
      param_1 = 1;
    }
    else if (uVar3 == 1) {
      param_1 = 6;
    }
    else {
      param_1 = 0xb;
    }
  }
  else {
    FUN_230213f0(&DAT_230031d1,0);
    FUN_230213f0(&DAT_230031d3,1);
    FUN_230213f0(&DAT_230031d5,2);
  }
  pbVar4 = (byte *)0x230003d5;
  uVar3 = 0xff;
  uVar5 = 0xff;
  bVar1 = 0;
  bVar7 = 0;
  do {
    while( true ) {
      bVar8 = bVar1;
      pbVar4 = pbVar4 + 1;
      uVar2 = (uint)*pbVar4;
      bVar1 = (&DAT_2300315c)[uVar2];
      if (bVar1 < bVar8) break;
      uVar3 = uVar5;
      uVar5 = uVar2;
      bVar7 = bVar8;
      if (pbVar4 == &DAT_230003da) goto LAB_23021334;
    }
    if (bVar7 <= bVar1) {
      uVar3 = uVar2;
      bVar7 = bVar1;
    }
    bVar1 = bVar8;
  } while (pbVar4 != &DAT_230003da);
LAB_23021334:
  uVar6 = (undefined1)uVar5;
  if (uVar5 == 0xff) {
    thunk_FUN_0e0621b8(local_19,1);
    uVar5 = local_19[0] & 0xf;
    uVar6 = (&DAT_230003d6)
            [uVar5 - (((uint)((ulonglong)uVar5 * 0xcccccccd >> 0x20) & 0xc) + uVar5 / 5)];
  }
  if (uVar3 == 0xff) {
    thunk_FUN_0e0621b8(local_19,1);
  }
  DAT_230031d7 = uVar6;
  if (param_1 != 1) {
    if (param_1 == 6) {
      DAT_230031ac = DAT_230031d1;
      DAT_230031ad = DAT_230031d5;
      DAT_230031f6 = 2;
    }
    else if (param_1 == 0xb) {
      DAT_230031ac = DAT_230031d1;
      DAT_230031ad = DAT_230031d3;
      DAT_230031f6 = 2;
      return;
    }
    return;
  }
  DAT_230031ac = DAT_230031d3;
  DAT_230031ad = DAT_230031d5;
  DAT_230031f6 = 2;
  return;
}


