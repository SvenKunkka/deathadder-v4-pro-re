/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230226c8. Types and names are inferred; NOT original source. */

void FUN_230226c8(int param_1)

{
  dword dVar1;
  undefined4 uVar2;
  byte *pbVar3;
  
  if ((uint)(&DAT_230033e8)[param_1 * 0x3e1] < 2) {
    if ((DAT_23005376 & 0x80) == 0) {
      uVar2 = 0x27;
    }
    else {
      uVar2 = 0x25;
    }
    dVar1 = FUN_230216b0(uVar2);
    RADIO_S_FREQUENCY = dVar1;
    RADIO_S_BASE1 = DAT_23003240;
    FUN_23020f3c(7);
    if (param_1 == 0) {
      pbVar3 = &DAT_230071c6;
    }
    else {
      pbVar3 = &DAT_230071c4;
    }
    RADIO_S_SUBSCRIBE_RXEN = *pbVar3 | 0x80000000;
    RADIO_S_SUBSCRIBE_DISABLE = DAT_230071c5 | 0x80000000;
    RADIO_S_PACKETPTR = (dword)(&DAT_230034bc + param_1 * 0xf84);
    (&DAT_230034b0)[param_1 * 0x7c2] = 0;
    return;
  }
  if ((&DAT_230033e8)[param_1 * 0x3e1] != 2) {
    RADIO_S_FREQUENCY = (uint)DAT_23003222;
    RADIO_S_BASE1 = DAT_23003244;
    FUN_23020f84(2);
    FUN_23020f3c(2);
    if (param_1 == 0) {
      pbVar3 = &DAT_230071c6;
    }
    else {
      if (param_1 != 1) {
        if (DAT_23005370 != 0xd) {
          return;
        }
        RADIO_S_SUBSCRIBE_TXEN = DAT_230071c4 | 0x80000000;
        return;
      }
      pbVar3 = &DAT_230071c4;
    }
    RADIO_S_SUBSCRIBE_RXEN = *pbVar3 | 0x80000000;
    RADIO_S_SUBSCRIBE_DISABLE = DAT_230071c5 | 0x80000000;
    return;
  }
  RADIO_S_BASE1 = DAT_23003244;
  dVar1 = FUN_230216b0((&DAT_0e06fbac)[(ushort)(&DAT_230034b2)[param_1 * 0x7c2]]);
  RADIO_S_FREQUENCY = dVar1;
  RADIO_S_PACKETPTR = (dword)(&DAT_230034bc + param_1 * 0xf84);
  if (-1 < (int)((uint)DAT_23005376 << 0x1f)) {
    if (param_1 == 0) {
      RADIO_S_SUBSCRIBE_TXEN = DAT_230071c6 | 0x80000000;
    }
    else if (param_1 == 1) {
      RADIO_S_SUBSCRIBE_TXEN = DAT_230071c4 | 0x80000000;
    }
    if (((&DAT_230033fc)[param_1 * 0x3e1] == 0) && (*(int *)(&DAT_23003410 + param_1 * 0xf84) == 0))
    {
      FUN_23020f84(param_1);
      return;
    }
    FUN_23020f84(0xff);
    return;
  }
  if (param_1 == 0) {
    pbVar3 = &DAT_230071c6;
  }
  else {
    if (param_1 != 1) goto LAB_23022768;
    pbVar3 = &DAT_230071c4;
  }
  RADIO_S_SUBSCRIBE_RXEN = *pbVar3 | 0x80000000;
  RADIO_S_SUBSCRIBE_DISABLE = DAT_230071c5 | 0x80000000;
LAB_23022768:
  FUN_23020f3c(param_1);
  if (((&DAT_230033fc)[param_1 * 0x3e1] != 0) || (*(int *)(&DAT_23003410 + param_1 * 0xf84) != 0)) {
    dVar1 = RADIO_S_RXADDRESSES;
    RADIO_S_RXADDRESSES = dVar1 | 1;
  }
  return;
}


