/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021dbc. Types and names are inferred; NOT original source. */

void FUN_23021dbc(int param_1)

{
  dword dVar1;
  int iVar2;
  undefined2 uVar3;
  
  DAT_23003234 = DAT_23003236;
  if (DAT_23003236 == 4) {
    FUN_23020dd4();
    iVar2 = param_1 * 0xf84;
    (&DAT_230033e8)[param_1 * 0x3e1] = 3;
    DAT_23005370 = 0xd;
    (&DAT_23003474)[param_1 * 0x3e1] = 0;
    (&DAT_23003468)[param_1 * 0x3e1] = 0xb;
    *(undefined4 *)(&DAT_2300346e + param_1 * 0x7c2) = 0;
    *(undefined4 *)(&DAT_23003478 + iVar2) = 0;
    (&DAT_2300346d)[iVar2] = 1;
    (&DAT_23003483)[iVar2] = 0xff;
    RADIO_S_SHORTS = 0;
    dVar1 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar1 | 1;
    dVar1 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar1 | 0x10;
    RADIO_S_INTENCLR00 = 0xffffffff;
    RADIO_S_INTENSET00 = 0x144;
    FUN_23020e84(4);
    TIMER020_S_CC_1 = 0;
    TIMER020_S_CC_2 = 0x33e0;
    DAT_230032d0 = 5;
    TIMER020_S_EVENTS_COMPARE_1 = 0;
    TIMER020_S_EVENTS_COMPARE_2 = 0;
    TIMER020_S_EVENTS_COMPARE_3 = 0;
    return;
  }
  if (DAT_23003236 != 1) {
    if (DAT_23003236 != 2) {
      return;
    }
    iVar2 = param_1 * 0xf84;
    (&DAT_230033e8)[param_1 * 0x3e1] = 3;
    DAT_23005370 = 0xd;
    (&DAT_23003474)[param_1 * 0x3e1] = 0;
    (&DAT_23003468)[param_1 * 0x3e1] = 0xb;
    *(undefined4 *)(&DAT_2300346e + param_1 * 0x7c2) = 0;
    *(undefined4 *)(&DAT_23003478 + iVar2) = 0;
    (&DAT_2300346d)[iVar2] = 1;
    (&DAT_23003483)[iVar2] = 0xff;
    dVar1 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar1 | 0x10;
    RADIO_S_INTENCLR00 = 0xffffffff;
    RADIO_S_INTENSET00 = 0x100;
    FUN_23020e84(2);
    return;
  }
  FUN_23020dd4();
  uVar3 = 3;
  iVar2 = param_1 * 0xf84;
  (&DAT_230033e8)[param_1 * 0x3e1] = 3;
  DAT_23005370 = 0xd;
  (&DAT_23003474)[param_1 * 0x3e1] = 0;
  (&DAT_23003468)[param_1 * 0x3e1] = 0xb;
  *(undefined4 *)(&DAT_2300346e + param_1 * 0x7c2) = 0;
  *(undefined4 *)(&DAT_23003478 + iVar2) = 0;
  (&DAT_2300346d)[iVar2] = 1;
  (&DAT_23003483)[iVar2] = 0xff;
  RADIO_S_SHORTS = 0;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 | 1;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 | 0x10;
  RADIO_S_INTENCLR00 = 0xffffffff;
  RADIO_S_INTENSET00 = 0x148;
  FUN_23020e84(2);
  if ((&DAT_2300341c)[param_1 * 0x7c2] == 1) {
    uVar3 = 4;
  }
  TIMER020_S_CC_1 = 0;
  TIMER020_S_CC_2 = 0x3160;
  TIMER020_S_CC_3 = 0;
  DAT_230032d0 = uVar3;
  TIMER020_S_EVENTS_COMPARE_1 = 0;
  TIMER020_S_EVENTS_COMPARE_2 = 0;
  TIMER020_S_EVENTS_COMPARE_3 = 0;
  return;
}


