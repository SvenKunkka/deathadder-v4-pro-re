/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230227b8. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_230227b8(int param_1)

{
  dword dVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  int local_24;
  uint local_20;
  undefined2 local_1c;
  
  sVar3 = DAT_23002a4a;
  if (DAT_23002a04 == 0x16) {
    if (param_1 != 5) {
      return;
    }
    RADIO_S_SUBSCRIBE_TXEN = 0;
    FUN_23021b90(&DAT_23002a04,&RADIO_S_TASKS_RXEN,0x14);
    _DAT_23002a4e = 0x50001;
    return;
  }
  if (DAT_23002a04 == 0x17) {
    if (param_1 != 5) {
      return;
    }
    RADIO_S_SUBSCRIBE_TXEN = 0;
    TIMER020_S_SUBSCRIBE_CLEAR = 0;
    if (DAT_2300298c != 0) {
      DAT_2300298c = 0;
      local_1c = 0;
      local_20 = DAT_230027b0;
      local_24 = 0x10000;
      FUN_23025f44(&local_24);
      FUN_23021c40(0,DAT_230027b0);
    }
    FUN_23021bf8(0);
    FUN_23021bb0(0);
    FUN_230217f0();
    thunk_FUN_0e096ac4(&DAT_23001540);
    thunk_FUN_0e096ac4(&DAT_23001540);
    if (DAT_23002798 == 2) {
      FUN_23023544();
    }
    else if (DAT_23002798 == 1) {
      FUN_23021a7c();
      FUN_230244cc();
    }
    else if (DAT_23002798 == 4) {
      FUN_23021a7c();
      FUN_23025778();
    }
    local_20 = CONCAT22(local_20._2_2_,DAT_23002982);
    local_24 = (uint)DAT_23002798 << 0x10;
    FUN_23025dc0(&local_24);
    return;
  }
  if (DAT_23002a04 != 0x14) {
    return;
  }
  if (param_1 != 5) {
    return;
  }
  dVar1 = RADIO_S_EVENTS_CRCOK;
  if (dVar1 == 1) {
    TIMER020_S_SUBSCRIBE_CLEAR = 0;
    iVar4 = FUN_23021688(DAT_23002a57);
    if ((iVar4 == 0) && (iVar4 = FUN_23021680(DAT_23002a57), iVar4 == 0)) {
      if (DAT_23002a4a == 1) {
        if ((DAT_23002a59 == '\x13') && (DAT_23002a56 == '\v')) {
          DAT_23002798 = (byte)DAT_23002a5a & 0xf;
          DAT_23002a56 = 0xb;
          DAT_230029d5 = DAT_23002a5a._2_1_ & 0xf;
          DAT_230029d6 = DAT_23002a5a._2_1_ >> 4;
          DAT_230027a2 = (ushort)((DAT_23002a5a << 0x1a) >> 0x1e);
          DAT_23002a57 = FUN_2302168c(0,0);
          DAT_23002a58 = FUN_23021698(0,DAT_23002a2a);
          DAT_23002a2a = DAT_23002a2a + '\x01';
          if (DAT_23002a2a == '\b') {
            DAT_23002a2a = '\x01';
          }
          DAT_23002a4a = 4;
          DAT_23002a59 = 0x14;
          DAT_23002a5a = (uint)(DAT_230029ac & 0xff);
LAB_230229ba:
          RADIO_S_SUBSCRIBE_TXEN = DAT_230076f5 | 0x80000000;
          DAT_23002a04 = 0x16;
          _DAT_23002a4e = 0x50001;
          DAT_23002a52 = 0;
          return;
        }
      }
      else {
        bVar2 = DAT_23002a5e;
        if (DAT_23002a4a == 4) {
          if ((DAT_23002a59 == '\x15') && (DAT_23002a56 == '\v')) {
            if (DAT_230027a2 < 2) {
              DAT_230029d7 = DAT_23002a5a;
              DAT_230029db = _DAT_23002a5e;
              DAT_230029df = 4;
            }
            else if (DAT_230027a2 == 2) {
              DAT_230026bd = DAT_23002a5e;
              _DAT_230026b9 = DAT_23002a5a;
              DAT_23002738 = _DAT_23002a5e >> 8 & 0xff;
            }
            else if (DAT_230027a2 == 3) {
              _DAT_230026b9 = DAT_23002a5a;
              DAT_230026bd = DAT_23002a5e;
            }
            DAT_23002a56 = 0xb;
            DAT_23002a57 = FUN_2302168c(0,0);
            DAT_23002a58 = FUN_23021698(0,DAT_23002a2a);
            DAT_23002a2a = DAT_23002a2a + '\x01';
            if (DAT_23002a2a == '\b') {
              DAT_23002a2a = '\x01';
            }
            DAT_23002a5a = DAT_23002a5a & 0xffff0000;
            RADIO_S_SUBSCRIBE_TXEN = DAT_230076f5 | 0x80000000;
            DAT_23002a04 = 0x17;
            DAT_23002a4a = 6;
            _DAT_23002a4e = 0x50001;
            DAT_23002a52 = 0;
            DAT_23002a59 = 0x16;
            return;
          }
        }
        else if (((DAT_23002a4a == 0) && (DAT_23002a59 == '\x11')) && (DAT_23002a56 == '\v')) {
          DAT_23002846 = _DAT_23002a5e;
          DAT_23002a09 = bVar2 >> 7;
          DAT_23002990 = CONCAT22((ushort)((_DAT_23002a5e << 0x19) >> 0x1f),(undefined2)DAT_23002990
                                 );
          if (((uint)DAT_2300279c & _DAT_23002a5e & 0xf) != 0) {
            if (DAT_2300298c != 0) {
              sVar3 = DAT_23002a4a;
              if (DAT_23002990 == 0x10000) goto LAB_23022806;
              DAT_230027b0 = DAT_23002a5a << 0x18 | (DAT_23002a5a >> 8 & 0xff) << 0x10 |
                             (DAT_23002a5a >> 0x10 & 0xff) << 8 | DAT_23002a5a >> 0x18;
            }
            DAT_23002838 = 500;
            DAT_23002a0a = DAT_23002a60 << 8 | DAT_23002a60 >> 8;
            DAT_23002a56 = 0xb;
            DAT_23002a57 = FUN_2302168c(0,0);
            DAT_23002a58 = FUN_23021698(0,DAT_23002a2a);
            DAT_23002a2a = DAT_23002a2a + '\x01';
            if (DAT_23002a2a == '\b') {
              DAT_23002a2a = '\x01';
            }
            DAT_23002a5a = CONCAT22((undefined2)DAT_2300297e,
                                    (ushort)(byte)((byte)DAT_2300279c & 0xf | DAT_23002a08 << 7));
            DAT_23002a4a = 1;
            DAT_23002a59 = 0x12;
            _DAT_23002a5e = CONCAT22(DAT_23002a60,DAT_2300297e._2_2_);
            TIMER020_S_CC_0 = 0x1b0;
            goto LAB_230229ba;
          }
        }
      }
    }
  }
LAB_23022806:
  DAT_23002a4a = sVar3;
  FUN_23022c8c();
  DAT_23002a4a = 0;
  DAT_23002a04 = 0x13;
  return;
}


