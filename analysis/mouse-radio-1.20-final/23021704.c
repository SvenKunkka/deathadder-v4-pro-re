/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23021704. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23021704(void)

{
  ushort uVar1;
  dword dVar2;
  uint3 uVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  undefined2 local_20;
  ushort local_1e;
  undefined2 local_1c;
  undefined2 local_18;
  ushort local_16;
  
  uVar4 = DAT_2300278e;
  if (DAT_23002794 != 0) {
    if (DAT_23002794 == 1) {
      dVar2 = RADIO_S_EVENTS_TXREADY;
      if (dVar2 == 1) {
        RADIO_S_EVENTS_TXREADY = 0;
      }
      dVar2 = RADIO_S_EVENTS_RXREADY;
      if (dVar2 == 1) {
        RADIO_S_EVENTS_RXREADY = 0;
      }
      dVar2 = RADIO_S_EVENTS_ADDRESS;
      if (dVar2 == 1) {
        RADIO_S_EVENTS_ADDRESS = 0;
      }
      dVar2 = RADIO_S_EVENTS_END;
      if (dVar2 == 1) {
        RADIO_S_EVENTS_END = 0;
      }
      dVar2 = RADIO_S_EVENTS_DISABLED;
      if (dVar2 == 1) {
        RADIO_S_EVENTS_DISABLED = 0;
      }
      return;
    }
    if (DAT_23002794 == 2) {
      dVar2 = RADIO_S_EVENTS_TXREADY;
      if (dVar2 == 1) {
        RADIO_S_EVENTS_TXREADY = 0;
      }
      dVar2 = RADIO_S_EVENTS_RXREADY;
      if (dVar2 == 1) {
        RADIO_S_EVENTS_RXREADY = 0;
      }
      dVar2 = RADIO_S_EVENTS_ADDRESS;
      if (dVar2 == 1) {
        RADIO_S_EVENTS_ADDRESS = 0;
      }
      dVar2 = RADIO_S_EVENTS_END;
      if (dVar2 != 0) {
        RADIO_S_EVENTS_END = 0;
      }
      dVar2 = RADIO_S_EVENTS_DISABLED;
      if (dVar2 != 1) {
        return;
      }
      RADIO_S_EVENTS_DISABLED = 0;
      FUN_230227b8(5);
    }
    else {
      if (DAT_23002794 == 5) {
        (*(code *)0xe07ac5d)();
        return;
      }
      uVar3 = DAT_23002630_1;
      if (DAT_23002798 == 2) {
        dVar2 = RADIO_S_EVENTS_TXREADY;
        if (dVar2 == 1) {
          RADIO_S_EVENTS_TXREADY = 0;
        }
        dVar2 = RADIO_S_EVENTS_RXREADY;
        if (dVar2 == 1) {
          RADIO_S_EVENTS_RXREADY = 0;
        }
        dVar2 = RADIO_S_EVENTS_ADDRESS;
        if (dVar2 == 1) {
          RADIO_S_EVENTS_ADDRESS = 0;
        }
        dVar2 = RADIO_S_EVENTS_END;
        if (dVar2 == 1) {
          RADIO_S_EVENTS_END = 0;
        }
        dVar2 = RADIO_S_EVENTS_DISABLED;
        if (dVar2 != 1) {
          return;
        }
        RADIO_S_EVENTS_DISABLED = 0;
        if (DAT_23002a04 == 0x19) {
          RADIO_S_SUBSCRIBE_TXEN = 0;
        }
        else if (DAT_23002a04 == 0x1a) {
          RADIO_S_SUBSCRIBE_RXEN = 0;
          RADIO_S_SUBSCRIBE_DISABLE = 0;
          TIMER020_S_SUBSCRIBE_CAPTURE_7 = 0;
          dVar2 = RADIO_S_EVENTS_CRCOK;
          if (dVar2 == 1) {
            if (DAT_230029c4 == 0 && DAT_230029cc == 0) {
              DAT_230029c4 = TIMER020_S_CC_7;
            }
            DAT_23002a22 = 1;
            _DAT_23002a96 = _DAT_23002630;
            _DAT_23002630 = (uint)DAT_23002630_1 << 8;
            _DAT_23002a9a = DAT_23002634;
            DAT_23002a0c = 0;
            DAT_23002a1e = DAT_23002a1e + '\x01';
            if (DAT_23002a1e == '\b') {
              DAT_23002a1e = '\x01';
            }
            *(undefined2 *)(&DAT_2300297c + (DAT_23002836 + 0x4c) * 2) = 0;
            DAT_23002a9e = DAT_23002638;
            DAT_23002aa2 = DAT_2300263c;
            if ((ushort)DAT_23002a1a < 6) {
              FUN_2302145c(0);
              local_18 = 0;
              local_16 = (ushort)DAT_23002a1a;
              FUN_23025eb4(&local_18);
            }
            FUN_2302252c();
          }
          else {
            DAT_23002a26 = 0;
            DAT_230029d0 = 2;
          }
          DAT_23002a04 = 0x18;
        }
      }
      else if (DAT_23002798 == 1) {
        dVar2 = RADIO_S_EVENTS_TXREADY;
        if (dVar2 == 1) {
          RADIO_S_EVENTS_TXREADY = 0;
        }
        dVar2 = RADIO_S_EVENTS_RXREADY;
        if (dVar2 == 1) {
          RADIO_S_EVENTS_RXREADY = 0;
        }
        dVar2 = RADIO_S_EVENTS_ADDRESS;
        if (dVar2 == 1) {
          RADIO_S_EVENTS_ADDRESS = 0;
        }
        dVar2 = RADIO_S_EVENTS_END;
        if (dVar2 == 1) {
          RADIO_S_EVENTS_END = 0;
        }
        dVar2 = RADIO_S_EVENTS_DISABLED;
        if (dVar2 != 1) {
          return;
        }
        RADIO_S_EVENTS_DISABLED = 0;
        if (DAT_23002a04 == 0x1a) {
          RADIO_S_SUBSCRIBE_RXEN = 0;
          RADIO_S_SUBSCRIBE_RXEN = 0;
          dVar2 = RADIO_S_SHORTS;
          RADIO_S_SHORTS = dVar2 & 0xfff7ffff;
          dVar2 = RADIO_S_EVENTS_CRCOK;
          if (dVar2 == 1) {
            RADIO_S_EVENTS_CRCOK = 0;
            if (DAT_230029ac == 1) {
              if (DAT_230029c4 == 0 && DAT_230029cc == 0) {
                DAT_230029c4 = TIMER020_S_CC_7;
              }
            }
            else if (DAT_230029c4 == 0 && DAT_230029cc == 0) {
              if (DAT_2300283c == 1) {
                DAT_230029c4 = TIMER020_S_CC_7;
              }
              else if (DAT_2300283c == 3) {
                dVar2 = TIMER020_S_CC_7;
                DAT_230029c4 = dVar2 - 0xfa;
              }
            }
            DAT_23002aa2 = DAT_2300263c;
            DAT_23002a9e = DAT_23002638;
            _DAT_23002a9a = DAT_23002634;
            _DAT_23002a96 = _DAT_23002630;
            uVar5 = (uint)DAT_23002836;
            iVar6 = (uVar5 + 0x4c) * 2;
            _DAT_23002630 = (uint)DAT_23002630_1 << 8;
            if (2 < *(ushort *)(&DAT_2300297c + iVar6)) {
              *(undefined2 *)(&DAT_2300297c + iVar6) = 0;
              cVar7 = (&DAT_230029d5)[uVar5] + '\x01';
              if (DAT_230029df == cVar7) {
                cVar7 = '\0';
              }
              (&DAT_230029d5)[uVar5] = cVar7;
            }
            uVar4 = (ushort)DAT_23002a1a;
            DAT_23002a1e = DAT_23002a1e + '\x01';
            if (DAT_23002a1e == '\b') {
              DAT_23002a1e = '\x01';
            }
            DAT_23002a0c = 0;
            *(undefined2 *)(&DAT_2300297c + (uVar5 + 0x4c) * 2) = 0;
            DAT_23002a22 = 1;
            DAT_23002a26 = 0;
            _DAT_23002670 = 0;
            _DAT_23002674 = 0;
            ram0x23002678 = 0;
            DAT_2300267c = 0;
            _DAT_23002680 = 0;
            _DAT_23002684 = 0;
            if (uVar4 < 6) {
              FUN_2302145c(0);
              local_18 = 0;
              local_16 = (ushort)DAT_23002a1a;
              FUN_23025eb4(&local_18);
            }
            FUN_2302252c();
          }
          else {
            if (DAT_230029ac == 1) {
              DAT_23002a26 = 0;
              FUN_230238f0();
            }
            else {
              DAT_23002a26 = 0;
              if (DAT_2300283c == 1) {
                DAT_23002a25 = 1;
              }
              else if (DAT_2300283c == 3) {
                FUN_230238f0(1,1);
              }
            }
            DAT_230029d0 = 2;
          }
          DAT_23002a04 = 0x18;
        }
      }
      else {
        if (DAT_23002798 != 4) goto LAB_230226fc;
        dVar2 = RADIO_S_EVENTS_TXREADY;
        if (dVar2 == 1) {
          RADIO_S_EVENTS_TXREADY = 0;
        }
        dVar2 = RADIO_S_EVENTS_RXREADY;
        if (dVar2 == 1) {
          RADIO_S_EVENTS_RXREADY = 0;
        }
        dVar2 = RADIO_S_EVENTS_ADDRESS;
        if (dVar2 == 1) {
          RADIO_S_EVENTS_ADDRESS = 0;
        }
        dVar2 = RADIO_S_EVENTS_END;
        if ((dVar2 == 1) && (RADIO_S_EVENTS_END = 0, DAT_23002a04 == 0x19)) {
          DAT_23002a04 = 0x18;
        }
        dVar2 = RADIO_S_EVENTS_DISABLED;
        if (dVar2 != 1) {
          return;
        }
        RADIO_S_EVENTS_DISABLED = 0;
        if (DAT_23002a04 == 0x19) {
          dVar2 = RADIO_S_SHORTS;
          RADIO_S_SHORTS = dVar2 & 0xfff7ffff;
        }
        else if (DAT_23002a04 == 0x1a) {
          RADIO_S_SUBSCRIBE_RXEN = 0;
          RADIO_S_SUBSCRIBE_DISABLE = 0;
          dVar2 = RADIO_S_SHORTS;
          RADIO_S_SHORTS = dVar2 & 0xfff7ffff;
          dVar2 = RADIO_S_EVENTS_CRCOK;
          if (dVar2 == 1) {
            RADIO_S_EVENTS_CRCOK = 0;
            if (DAT_230029c4 == 0 && DAT_230029cc == 0) {
              if (DAT_2300283c == 2) {
                DAT_230029c4 = TIMER020_S_CC_7;
              }
              else if (DAT_2300283c == 5) {
                dVar2 = TIMER020_S_CC_7;
                DAT_230029c4 = dVar2 - 0xfa;
              }
            }
            uVar4 = DAT_23002a0a;
            if (DAT_23002633 == '\x1f') {
              dVar2 = TIMER020_S_CC_7;
              uVar1 = (ushort)DAT_23002634 << 8 | (ushort)DAT_23002634 >> 8;
              uVar4 = uVar1;
              if ((0x53 < dVar2 - 0xa6) && (uVar4 = DAT_23002a0a, dVar2 - 0x1a0 < 0x54)) {
                uVar4 = uVar1 + 1;
              }
            }
            DAT_23002a0a = uVar4;
            _DAT_23002a96 = _DAT_23002630;
            DAT_23002a1e = DAT_23002a1e + '\x01';
            if (DAT_23002a1e == '\b') {
              DAT_23002a1e = '\x01';
            }
            _DAT_23002630 = (uint)uVar3 << 8;
            *(undefined2 *)(&DAT_2300297c + (DAT_23002836 + 0x4c) * 2) = 0;
            DAT_23002a0c = 0;
            _DAT_23002670 = 0;
            _DAT_23002674 = 0;
            ram0x23002678 = 0;
            DAT_2300267c = 0;
            _DAT_23002680 = 0;
            _DAT_23002684 = 0;
            DAT_23002a26 = 0;
            _DAT_23002a9a = DAT_23002634;
            DAT_230027c7 = 0;
            DAT_23002a9e = DAT_23002638;
            DAT_23002a22 = 1;
            DAT_23002aa2 = DAT_2300263c;
            if (((ushort)DAT_23002a1a < 6) && (FUN_2302145c(0), 1 < (ushort)DAT_23002a1a)) {
              local_20 = 0;
              local_1e = (ushort)DAT_23002a1a;
              local_1c = 1;
              FUN_23025eb4(&local_20);
            }
            FUN_2302252c();
            uVar5 = (uint)DAT_2300278e;
            (&DAT_23002798)[uVar5 + 0xa8] = 0;
            if (DAT_230029e0 == '\0' && DAT_230029e4 == '\0') {
              FUN_23022f90(1,uVar5 & 0xff,0xff);
            }
            else {
              dVar2 = RADIO_S_RSSISAMPLE;
              DAT_230029e5 = (undefined1)dVar2;
              FUN_23022f90(1,uVar5 & 0xff);
            }
          }
          else {
            DAT_23002a26 = 0;
            iVar6 = DAT_2300278e + 0x84;
            iVar8 = DAT_2300278e + 0xa8;
            (&DAT_23002796)[iVar6] = (&DAT_23002796)[iVar6] + 1;
            (&DAT_23002798)[iVar8] = (&DAT_23002798)[iVar8] + 1;
            DAT_2300293a = DAT_2300293a + 1;
            DAT_230029d0 = 2;
            FUN_23022f90(0,(char)uVar4,0xff);
          }
          DAT_23002932 = DAT_23002932 + 1;
          (&DAT_23002794)[DAT_2300278e + 0x60] = (&DAT_23002794)[DAT_2300278e + 0x60] + 1;
          DAT_23002938 = DAT_23002938 + 1;
          dVar2 = RADIO_S_SHORTS;
          RADIO_S_SHORTS = dVar2 & 0xffffffef;
          DAT_23002a04 = 0x18;
        }
      }
    }
    RADIO_S_EVENTS_CRCOK = 0;
    RADIO_S_EVENTS_CRCERROR = 0;
    return;
  }
LAB_230226fc:
  dVar2 = RADIO_S_EVENTS_TXREADY;
  if (dVar2 == 1) {
    RADIO_S_EVENTS_TXREADY = 0;
  }
  dVar2 = RADIO_S_EVENTS_RXREADY;
  if (dVar2 == 1) {
    RADIO_S_EVENTS_RXREADY = 0;
  }
  dVar2 = RADIO_S_EVENTS_ADDRESS;
  if (dVar2 == 1) {
    RADIO_S_EVENTS_ADDRESS = 0;
  }
  dVar2 = RADIO_S_EVENTS_END;
  if (dVar2 == 1) {
    RADIO_S_EVENTS_END = 0;
  }
  dVar2 = RADIO_S_EVENTS_DISABLED;
  if (dVar2 == 1) {
    RADIO_S_EVENTS_DISABLED = 0;
  }
  return;
}


