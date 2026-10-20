/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23023ab8. Types and names are inferred; NOT original source. */

void FUN_23023ab8(int param_1)

{
  dword dVar1;
  int iVar2;
  byte *pbVar3;
  
  if (DAT_230029ac == 1) {
    if (DAT_23002a04 == 0x19) {
      if (param_1 != 3) {
        if (param_1 != 6) {
          if (param_1 != 1) {
            return;
          }
          dVar1 = RADIO_S_SUBSCRIBE_TXEN;
          if (-1 < (int)dVar1) {
            dVar1 = RADIO_S_SUBSCRIBE_START;
          }
          RADIO_S_SUBSCRIBE_TXEN = 0;
          RADIO_S_SUBSCRIBE_START = 0;
          return;
        }
        goto LAB_23023b2c;
      }
      iVar2 = FUN_23024408();
      if (iVar2 != 0) {
LAB_23023c46:
        if ((2 < DAT_2300283c) && (DAT_2300283c != 3)) goto LAB_23023c4e;
        RADIO_S_SUBSCRIBE_START = DAT_230076f3 | 0x80000000;
LAB_23023cce:
        dVar1 = RADIO_S_SHORTS;
        RADIO_S_SHORTS = dVar1 | 1;
        dVar1 = RADIO_S_SHORTS;
        RADIO_S_SHORTS = dVar1 & 0xfff7ffff;
LAB_23023c4e:
        RADIO_S_FREQUENCY = (uint)DAT_2300278c;
        FUN_23024078();
        DAT_23002a04 = 0x19;
        return;
      }
    }
    else {
      if (DAT_23002a04 == 0x1a) {
        if (param_1 == 8) {
          pbVar3 = (byte *)RADIO_S_PACKETPTR;
          if (*pbVar3 - 1 < 8) {
            return;
          }
          goto LAB_23023b86;
        }
        goto LAB_23023b16;
      }
      if (DAT_23002a04 != 0x18) {
        return;
      }
      if (param_1 != 3) {
        if (param_1 != 6) {
          if (param_1 != 1) {
            return;
          }
          RADIO_S_SUBSCRIBE_TXEN = 0;
          return;
        }
        goto LAB_23023b66;
      }
      iVar2 = FUN_23024408();
      if (iVar2 != 0) {
        if (DAT_2300283c != 0) goto LAB_23023c46;
        RADIO_S_SUBSCRIBE_TXEN = DAT_230076f5 | 0x80000000;
        goto LAB_23023cce;
      }
      if (DAT_2300283c == 0) {
        RADIO_S_SUBSCRIBE_TXEN = DAT_230076f5 | 0x80000000;
        RADIO_S_FREQUENCY = (uint)DAT_2300278c;
        dVar1 = RADIO_S_SHORTS;
        RADIO_S_SHORTS = dVar1 & 0xfff7fffe;
        return;
      }
    }
    if (DAT_2300283c == 3) {
      FUN_230238f0(0);
      return;
    }
  }
  else {
    if (DAT_23002a04 == 0x19) {
      if (param_1 == 3) {
        return;
      }
      if (param_1 == 6) {
LAB_23023b2c:
        if (DAT_23002a20 == '\x01') {
          RADIO_S_SUBSCRIBE_RXEN = DAT_230076f3 | 0x80000000;
          dVar1 = RADIO_S_SHORTS;
          RADIO_S_SHORTS = dVar1 | 0x80000;
          DAT_23002a20 = 0;
          DAT_23002a04 = 0x1a;
          RADIO_S_PACKETPTR = 0x23002630;
          DAT_23002630 = 0;
          return;
        }
LAB_23023b66:
        FUN_23021b90(&DAT_23002a04,&RADIO_S_TASKS_DISABLE,0x18);
        return;
      }
    }
    else {
      if (DAT_23002a04 == 0x1a) {
        if (param_1 == 8) {
          pbVar3 = (byte *)RADIO_S_PACKETPTR;
          if (*pbVar3 - 1 < 10) {
            return;
          }
LAB_23023b86:
          FUN_23021b90(&DAT_23002a04,&RADIO_S_TASKS_DISABLE);
          return;
        }
LAB_23023b16:
        if (param_1 != 1) {
          return;
        }
        RADIO_S_SUBSCRIBE_RXEN = 0;
        return;
      }
      if (DAT_23002a04 != 0x18) {
        return;
      }
      if (param_1 == 3) {
        iVar2 = FUN_23024408();
        if (iVar2 == 0) {
          if (DAT_2300283c == 0) {
            DAT_23002a25 = 1;
          }
          else if (DAT_2300283c == 2) {
            FUN_230238f0(0,1);
          }
          RADIO_S_FREQUENCY = (uint)DAT_2300278c;
          return;
        }
        if (DAT_2300283c == 0) {
          pbVar3 = &DAT_230076f5;
        }
        else {
          if (DAT_2300283c != 2) goto LAB_23023c90;
          pbVar3 = &DAT_230076f3;
        }
        RADIO_S_SUBSCRIBE_TXEN = *pbVar3 | 0x80000000;
        dVar1 = RADIO_S_SHORTS;
        RADIO_S_SHORTS = dVar1 | 1;
        dVar1 = RADIO_S_SHORTS;
        RADIO_S_SHORTS = dVar1 & 0xfff7ffff;
LAB_23023c90:
        RADIO_S_FREQUENCY = (uint)DAT_2300278c;
        FUN_23024078();
        DAT_23002a04 = 0x19;
        return;
      }
      if (param_1 == 6) goto LAB_23023b66;
    }
    if (param_1 == 1) {
      RADIO_S_SUBSCRIBE_TXEN = 0;
      RADIO_S_SUBSCRIBE_TXEN = 0;
      return;
    }
  }
  return;
}


