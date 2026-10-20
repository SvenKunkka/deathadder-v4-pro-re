/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021bbc. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x23023be8) */
/* WARNING: Removing unreachable block (ram,0x23023bec) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23021bbc(void)

{
  ushort uVar1;
  undefined1 uVar2;
  int iVar3;
  dword dVar4;
  undefined4 uVar5;
  dword dVar6;
  undefined2 uVar7;
  uint uVar8;
  dword dVar9;
  undefined4 *puVar10;
  uint uVar11;
  
  if (DAT_23003230 < 2) {
    return;
  }
  if (DAT_23003234 != 4) {
    if (DAT_23003234 != 1) {
      if (DAT_23003234 != 2) {
        return;
      }
      dVar9 = TIMER020_S_EVENTS_COMPARE_0;
      if (dVar9 == 1) {
        TIMER020_S_EVENTS_COMPARE_0 = 0;
        TIMER020_S_CC_0 = 16000;
        RADIO_S_SUBSCRIBE_TXEN = 0;
        RADIO_S_SUBSCRIBE_RXEN = 0;
        TIMER020_S_CC_1 = 0x1040;
        TIMER020_S_CC_2 = 0x1220;
        FUN_23022888(0);
        DAT_230032d0 = 0;
        return;
      }
      dVar9 = TIMER020_S_EVENTS_COMPARE_1;
      if (dVar9 != 1) {
        dVar9 = TIMER020_S_EVENTS_COMPARE_2;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_2 = 0;
          if (DAT_230032d0 == 1) {
            RADIO_S_SUBSCRIBE_TXEN = 0;
            RADIO_S_SUBSCRIBE_RXEN = 0;
            TIMER020_S_CC_1 = 0x2260;
            TIMER020_S_CC_2 = 0x2580;
            FUN_23022888(1);
            return;
          }
          if (DAT_230032d0 == 2) {
            RADIO_S_SUBSCRIBE_TXEN = 0;
            TIMER020_S_CC_1 = 0x3980;
            TIMER020_S_CC_2 = 0;
            if (DAT_23005370 == 0xb) {
              FUN_23020f1c(&DAT_23005370,&RADIO_S_TASKS_DISABLE);
            }
            if (2 < DAT_230033e8) {
              DAT_23003470 = DAT_23003470 + 1;
              DAT_2300346e = DAT_2300346e + 1;
              DAT_23003474 = DAT_23003474 + 1;
            }
            if (2 < DAT_2300436c) {
              DAT_230043f2 = DAT_230043f2 + 1;
              DAT_230043f4 = DAT_230043f4 + 1;
              DAT_230043f8 = DAT_230043f8 + 1;
            }
            if (2 < DAT_230052f0) {
              DAT_23005376 = DAT_23005376 + 1;
              DAT_23005378 = DAT_23005378 + 1;
              DAT_2300537c = DAT_2300537c + 1;
            }
            DAT_23003222 = FUN_23021654(DAT_23005376,DAT_230032ca);
            DAT_230032ca = (ushort)(((uint)DAT_23005376 << 0x1e) >> 0x1f);
            FUN_23022e48(0);
            FUN_23022e48(1);
            return;
          }
          return;
        }
        dVar9 = TIMER020_S_EVENTS_COMPARE_3;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_3 = 0;
          return;
        }
        dVar9 = TIMER020_S_EVENTS_COMPARE_4;
        if (dVar9 != 1) {
          dVar9 = TIMER020_S_EVENTS_COMPARE_5;
          if (dVar9 == 1) {
            TIMER020_S_EVENTS_COMPARE_5 = 0;
            return;
          }
          dVar9 = TIMER020_S_EVENTS_COMPARE_6;
          if (dVar9 == 1) {
            TIMER020_S_EVENTS_COMPARE_6 = 0;
            return;
          }
          dVar9 = TIMER020_S_EVENTS_COMPARE_7;
          if (dVar9 == 1) {
            TIMER020_S_EVENTS_COMPARE_7 = 0;
            return;
          }
          return;
        }
        TIMER020_S_EVENTS_COMPARE_4 = 0;
        return;
      }
      TIMER020_S_EVENTS_COMPARE_1 = 0;
      RADIO_S_SUBSCRIBE_DISABLE = 0;
      RADIO_S_SUBSCRIBE_DISABLE = 0;
      uVar1 = DAT_230032d0;
      if (DAT_230032d0 == 0) {
        FUN_230226c8();
        if (DAT_23003468 == 9) {
          DAT_23003468 = 7;
          DAT_230034b0 = uVar1;
        }
        DAT_230032d0 = 1;
        return;
      }
      if (DAT_230032d0 != 1) {
        if (DAT_230032d0 == 2) {
          FUN_230226c8(0);
          DAT_230032d0 = 0;
          return;
        }
        return;
      }
      FUN_230226c8(2);
      if (DAT_230043ec == 9) {
        DAT_23004434 = 0;
        DAT_230043ec = 7;
      }
      DAT_230032d0 = 2;
      if (DAT_23005370 != 0xd) {
        DAT_230032d0 = 2;
        return;
      }
      if (DAT_23003484 == '\0') {
        if (DAT_23004408 == '\0') {
          RADIO_S_SUBSCRIBE_TXEN = 0;
          FUN_23020f1c(&DAT_23005370,&RADIO_S_TASKS_DISABLE);
          DAT_23003484 = 0;
          DAT_23004408 = 0;
          return;
        }
        DAT_2300347e._0_2_ = 0xff;
        DAT_23004402._0_2_ = 0xff;
      }
      else {
        DAT_2300347e._0_2_ = 0xff;
        DAT_23004402._0_2_ = 0xff;
        if (DAT_23003484 == '\x01') {
          uVar8 = 0;
          do {
            puVar10 = (undefined4 *)FUN_230207ec(0,uVar8 & 0xffff);
            uVar11 = uVar8 + 1;
            if (puVar10 != (undefined4 *)0x0) {
              uVar5 = 0;
              DAT_2300347e._0_2_ = (undefined2)uVar8;
              uVar2 = 1;
              goto LAB_23023124;
            }
            uVar8 = uVar11;
          } while (uVar11 != 6);
        }
      }
      if (DAT_23004408 == '\x01') {
        uVar8 = 0;
        do {
          puVar10 = (undefined4 *)FUN_230207ec(1,uVar8 & 0xffff);
          uVar11 = uVar8 + 1;
          if (puVar10 != (undefined4 *)0x0) {
            DAT_23004402._0_2_ = (undefined2)uVar8;
            uVar5 = 1;
            uVar2 = 0;
            goto LAB_23023124;
          }
          uVar8 = uVar11;
        } while (uVar11 != 6);
      }
      uVar2 = 0;
      DAT_230053e4 = 5;
      DAT_230053e6 = FUN_230209dc(0,DAT_23005397);
      uVar5 = 0;
      DAT_23005397 = DAT_23005397 + '\x01';
      if (DAT_23005397 == '\b') {
        DAT_23005397 = '\x01';
      }
      DAT_230053e7 = 0x1f;
      puVar10 = (undefined4 *)&DAT_230053e4;
      DAT_230053e8._0_2_ = CONCAT11(DAT_230053e8._1_1_,DAT_23005349 & 0xf | DAT_2300534a << 4);
LAB_23023124:
      uVar2 = FUN_2302098c(DAT_23004408,DAT_23003484,uVar5,uVar2,
                           *(undefined1 *)((int)&DAT_230033e8 + (DAT_230032ca + 0xfcc) * 2));
      *(undefined1 *)((int)puVar10 + 1) = uVar2;
      RADIO_S_PACKETPTR = 0x23003070;
      DAT_23004408 = 0;
      DAT_23003484 = 0;
      DAT_2300307c = puVar10[3];
      DAT_23003078 = puVar10[2];
      DAT_23003074 = puVar10[1];
      DAT_23003070 = *puVar10;
      return;
    }
    dVar9 = TIMER020_S_EVENTS_COMPARE_0;
    if (dVar9 == 1) {
      TIMER020_S_EVENTS_COMPARE_0 = 0;
      TIMER020_S_CC_0 = 16000;
      RADIO_S_SUBSCRIBE_RXEN = 0;
      if (DAT_2300341c == 1) {
        uVar5 = 0xf00;
        TIMER020_S_CC_1 = 0xb40;
        TIMER020_S_CC_2 = 0xf00;
        TIMER020_S_CC_3 = 0x2bc0;
      }
      else {
        uVar5 = 0x1220;
        TIMER020_S_CC_1 = 0xe60;
        TIMER020_S_CC_2 = 0x1220;
        TIMER020_S_CC_3 = 0xa00;
      }
      DAT_230032d0 = 0;
      FUN_230233b0(1,uVar5,0,1);
      return;
    }
    dVar9 = TIMER020_S_EVENTS_COMPARE_1;
    if (dVar9 != 1) {
      dVar9 = TIMER020_S_EVENTS_COMPARE_2;
      if (dVar9 != 1) {
        dVar9 = TIMER020_S_EVENTS_COMPARE_3;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_3 = 0;
          if (DAT_2300341c == 1) {
            TIMER020_S_CC_3 = 0;
            FUN_230233b0(5,1,0,1);
            return;
          }
          if ((DAT_230032d0 & 0xfffd) == 0) {
            FUN_230233b0(5,DAT_2300341c,0,1);
            return;
          }
          return;
        }
        dVar9 = TIMER020_S_EVENTS_COMPARE_4;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_4 = 0;
          return;
        }
        dVar9 = TIMER020_S_EVENTS_COMPARE_5;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_5 = 0;
          return;
        }
        dVar9 = TIMER020_S_EVENTS_COMPARE_6;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_6 = 0;
          return;
        }
        dVar9 = TIMER020_S_EVENTS_COMPARE_7;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_7 = 0;
          return;
        }
        return;
      }
      TIMER020_S_EVENTS_COMPARE_2 = 0;
      if (DAT_2300341c == 1) {
        if (DAT_230032d0 == 0) {
          dVar9 = 0xb40;
          dVar4 = 0xf00;
        }
        else {
          switch(DAT_230032d0) {
          case 1:
            dVar9 = 0x15e0;
            dVar4 = 0x19a0;
            break;
          case 2:
            dVar9 = 0x2080;
            dVar4 = 0x2440;
            break;
          case 3:
            dVar9 = 0x2e40;
            dVar4 = 0x3160;
            break;
          case 4:
            TIMER020_S_CC_1 = 0x3ac0;
            TIMER020_S_CC_2 = 0;
joined_r0x23023dd4:
            if (DAT_23005370 == 0xd) {
              FUN_23023268();
            }
            if (2 < DAT_230033e8) {
              DAT_2300346e = DAT_2300346e + 1;
              DAT_23003470 = DAT_23003470 + 1;
              if (DAT_23003474 < 200) {
                DAT_23003474 = DAT_23003474 + 1;
              }
            }
            FUN_23023b5c(2);
            if (2 < DAT_230033e8) {
              if (99 < DAT_23003470) {
                RADIO_S_SUBSCRIBE_RXEN = 0;
                RADIO_S_SUBSCRIBE_TXEN = 0;
                RADIO_S_SUBSCRIBE_RXEN = 0;
                RADIO_S_SUBSCRIBE_TXEN = 0;
                RADIO_S_SUBSCRIBE_TXEN = 0;
                RADIO_S_SUBSCRIBE_DISABLE = 0;
                FUN_23020f1c(&DAT_23003468,&RADIO_S_TASKS_DISABLE,0);
                FUN_23021dfc(0);
                FUN_230221a4(0);
                FUN_230254f8(&stack0xffffffe8);
                return;
              }
              if (DAT_23003474 < 200) {
                DAT_230033e8 = 3;
              }
              else {
                DAT_230033e8 = 4;
              }
            }
            return;
          default:
            goto switchD_23023e40_default;
          }
        }
        TIMER020_S_CC_1 = dVar9;
        TIMER020_S_CC_2 = dVar4;
        FUN_230233b0(1,dVar9,dVar4,1);
        return;
      }
      if (DAT_230032d0 == 0) {
        dVar9 = 0xe60;
        dVar4 = 0x1220;
        dVar6 = 0;
LAB_23023ec8:
        TIMER020_S_CC_1 = dVar9;
        TIMER020_S_CC_2 = dVar4;
        TIMER020_S_CC_3 = dVar6;
        FUN_230233b0();
        return;
      }
      if (DAT_230032d0 == 1) {
        TIMER020_S_CC_1 = 0x1b80;
        TIMER020_S_CC_2 = 8000;
        TIMER020_S_CC_3 = 0;
        if (DAT_23005370 == 0xd) {
          FUN_23023268();
          return;
        }
      }
      else {
        if (DAT_230032d0 == 2) {
          dVar9 = 0x2da0;
          dVar4 = 0x3160;
          dVar6 = 0x2940;
          goto LAB_23023ec8;
        }
        if (DAT_230032d0 == 3) {
          TIMER020_S_CC_1 = 0x3ac0;
          TIMER020_S_CC_2 = 0;
          TIMER020_S_CC_3 = 0;
          goto joined_r0x23023dd4;
        }
      }
switchD_23023e40_default:
      return;
    }
    TIMER020_S_EVENTS_COMPARE_1 = 0;
    if (DAT_2300341c == 1) {
      uVar7 = 1;
      if (DAT_230032d0 == 0) {
LAB_23023e64:
        DAT_230032d0 = uVar7;
        FUN_230232d0();
        return;
      }
      switch(DAT_230032d0) {
      case 1:
        uVar7 = 2;
        goto LAB_23023e64;
      case 2:
        DAT_230032d0 = 3;
        FUN_230232d0();
        return;
      case 3:
        FUN_230233b0(2);
        DAT_230032d0 = 4;
        break;
      case 4:
        uVar1 = DAT_2300341e;
        DAT_230032d0 = 0;
        if ((DAT_2300341e != 0) && (DAT_23003420 == DAT_23005376)) {
          DAT_2300341e = 0;
          DAT_2300341c = uVar1;
        }
        goto LAB_23023cfc;
      default:
        goto switchD_23023e40_default;
      }
    }
    else {
      if (DAT_230032d0 == 0) {
        DAT_230032d0 = 1;
        FUN_230232d0();
        goto LAB_23023bcc;
      }
      if (DAT_230032d0 == 1) {
        DAT_230032d0 = 2;
LAB_23023cfc:
        FUN_230232d0();
        FUN_230233b0(4);
        return;
      }
      if (DAT_230032d0 != 2) {
        if (DAT_230032d0 != 3) {
          return;
        }
        DAT_230032d0 = 0;
        if ((DAT_2300341e != 0) && (DAT_23003420 == DAT_23005376)) {
          DAT_2300341c = DAT_2300341e;
          DAT_2300341e = 0;
        }
        goto LAB_23023cfc;
      }
      DAT_230032d0 = 3;
    }
    FUN_230232d0();
LAB_23023bcc:
    if (DAT_23005370 != 0xd) {
      return;
    }
    if (DAT_2300341c == 1) {
      if ((DAT_23003484 == '\0') || (iVar3 = FUN_230237e0(), iVar3 == 0)) {
        RADIO_S_SUBSCRIBE_TXEN = 0;
        FUN_23020f1c(&DAT_23005370,&RADIO_S_TASKS_DISABLE,0xd);
        FUN_23023708(0);
      }
    }
    else if ((DAT_23003484 == '\0') || (iVar3 = FUN_230237e0(), iVar3 == 0)) {
      RADIO_S_SUBSCRIBE_TXEN = 0;
      RADIO_S_SUBSCRIBE_TXEN = 0;
      FUN_23020f1c(&DAT_23005370,&RADIO_S_TASKS_DISABLE,0xd);
    }
    DAT_23003484 = 0;
    return;
  }
  dVar9 = TIMER020_S_EVENTS_COMPARE_0;
  if (dVar9 == 1) {
    TIMER020_S_EVENTS_COMPARE_0 = 0;
    DAT_230032d0 = 0;
    TIMER020_S_CC_0 = 16000;
    RADIO_S_SUBSCRIBE_RXEN = 0;
    TIMER020_S_CC_1 = 0xaa0;
    TIMER020_S_CC_4 = 0;
    TIMER020_S_CC_2 = 0xc80;
    if ((DAT_23003468 == 0xb) || (DAT_23003468 == 0xc)) {
      RADIO_S_SUBSCRIBE_RXEN = 0;
    }
    uVar8 = (uint)DAT_23005376;
    if ((DAT_2300325d != '\0') && (DAT_230033d6 == uVar8)) {
      DAT_2300325d = '\0';
      FUN_23021718();
      uVar8 = (uint)DAT_23005376;
    }
    uVar5 = DAT_230033dc;
    uVar8 = uVar8 & 0x7ff;
    if (uVar8 != 0) {
      return;
    }
    DAT_230033d8 = DAT_230033dc;
    DAT_230033dc = uVar8;
    DAT_230033d8._2_2_ = (ushort)((uint)uVar5 >> 0x10);
    DAT_230033e0 = 0;
    if (DAT_2300341c != 1) {
      if (DAT_2300341c < 0x21) {
        switch(DAT_2300341c) {
        case 2:
          if (DAT_230033d8._2_2_ < 0xf9a) {
            DAT_230033d8 = uVar5;
            return;
          }
          DAT_230033d8 = uVar5;
          DAT_230033e0 = 1;
          return;
        case 4:
          if (DAT_230033d8._2_2_ < 0x7cd) {
            DAT_230033d8 = uVar5;
            return;
          }
          DAT_230033d8 = uVar5;
          DAT_230033e0 = 1;
          return;
        case 8:
          if (DAT_230033d8._2_2_ < 999) {
            DAT_230033d8 = uVar5;
            return;
          }
          DAT_230033d8 = uVar5;
          DAT_230033e0 = 1;
          return;
        case 0x10:
          if (DAT_230033d8._2_2_ < 500) {
            DAT_230033d8 = uVar5;
            return;
          }
          DAT_230033d8 = uVar5;
          DAT_230033e0 = 1;
          return;
        case 0x20:
          if (DAT_230033d8._2_2_ < 0xfa) {
            DAT_230033d8 = uVar5;
            return;
          }
          DAT_230033d8 = uVar5;
          DAT_230033e0 = 1;
          return;
        }
      }
      else if (DAT_2300341c == 0x40) {
        if (DAT_230033d8._2_2_ < 0x7d) {
          DAT_230033d8 = uVar5;
          return;
        }
        DAT_230033d8 = uVar5;
        DAT_230033e0 = 1;
        return;
      }
    }
    if (DAT_230033d8._2_2_ < 0x1f9a) {
      DAT_230033d8 = uVar5;
      return;
    }
    DAT_230033e0 = 1;
    DAT_230033d8 = uVar5;
    return;
  }
  dVar9 = TIMER020_S_EVENTS_COMPARE_1;
  if (dVar9 != 1) {
    dVar9 = TIMER020_S_EVENTS_COMPARE_2;
    if (dVar9 == 1) {
      TIMER020_S_EVENTS_COMPARE_2 = 0;
      if (DAT_230032d0 == 1) {
        TIMER020_S_CC_1 = 0x1220;
        TIMER020_S_CC_4 = 0x1220;
        TIMER020_S_CC_2 = 0x14a0;
        if ((DAT_23003468 == 0xb) || (DAT_23003468 == 0xc)) {
          RADIO_S_SUBSCRIBE_RXEN = 0;
        }
      }
      else {
        switch(DAT_230032d0) {
        case 2:
          RADIO_S_SUBSCRIBE_TXEN = 0;
          TIMER020_S_CC_1 = 0x1b80;
          TIMER020_S_CC_4 = 0;
          TIMER020_S_CC_2 = 8000;
          break;
        case 3:
          RADIO_S_SUBSCRIBE_RXEN = 0;
          TIMER020_S_CC_1 = 0x29e0;
          TIMER020_S_CC_4 = 0;
          TIMER020_S_CC_2 = 0x2bc0;
          if ((DAT_23003468 == 0xb) || (DAT_23003468 == 0xc)) {
            RADIO_S_SUBSCRIBE_RXEN = 0;
          }
          break;
        case 4:
          TIMER020_S_CC_1 = 0x3160;
          TIMER020_S_CC_4 = 0x3160;
          TIMER020_S_CC_2 = 0x33e0;
          if ((DAT_23003468 == 0xb) || (DAT_23003468 == 0xc)) {
            RADIO_S_SUBSCRIBE_RXEN = 0;
          }
          break;
        case 5:
          RADIO_S_SUBSCRIBE_TXEN = 0;
          TIMER020_S_CC_1 = 0x3ac0;
          TIMER020_S_CC_4 = 0;
          TIMER020_S_CC_2 = 0;
          if (2 < DAT_230033e8) {
            DAT_2300346e = DAT_2300346e + 1;
            DAT_23003470 = DAT_23003470 + 1;
            DAT_23003474 = DAT_23003474 + 1;
          }
          if (2 < DAT_230052f0) {
            DAT_23005376 = DAT_23005376 + 1;
            DAT_23005378 = DAT_23005378 + 1;
            DAT_2300537c = DAT_2300537c + 1;
          }
          _DAT_23003226 = FUN_23021654(DAT_23005376,DAT_230032ca);
          DAT_230032ca = (ushort)(((uint)DAT_23005376 << 0x1e) >> 0x1f);
          if (2 < DAT_230033e8) {
            if (DAT_23003470 < 100) {
              if (DAT_23003474 < 200) {
                DAT_230033e8 = 3;
              }
              else {
                DAT_230033e8 = 4;
              }
            }
            else {
              RADIO_S_SUBSCRIBE_RXEN = 0;
              RADIO_S_SUBSCRIBE_RXEN = 0;
              RADIO_S_SUBSCRIBE_STOP = 0;
              RADIO_S_SUBSCRIBE_TXEN = 0;
              FUN_23020f1c(&DAT_23003468,&RADIO_S_TASKS_DISABLE,0);
              FUN_23021dfc(0);
              FUN_230221a4(0);
              FUN_230254f8(&stack0xffffffe0);
            }
          }
        }
      }
    }
    else {
      dVar9 = TIMER020_S_EVENTS_COMPARE_3;
      if (dVar9 == 1) {
        TIMER020_S_EVENTS_COMPARE_3 = 0;
        return;
      }
      dVar9 = TIMER020_S_EVENTS_COMPARE_4;
      if (dVar9 == 1) {
        TIMER020_S_EVENTS_COMPARE_4 = 0;
      }
      else {
        dVar9 = TIMER020_S_EVENTS_COMPARE_5;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_5 = 0;
        }
        else {
          dVar9 = TIMER020_S_EVENTS_COMPARE_6;
          if (dVar9 == 1) {
            TIMER020_S_EVENTS_COMPARE_6 = 0;
          }
          else {
            dVar9 = TIMER020_S_EVENTS_COMPARE_7;
            if (dVar9 == 1) {
              TIMER020_S_EVENTS_COMPARE_7 = 0;
            }
          }
        }
      }
    }
switchD_23024a52_default:
    return;
  }
  TIMER020_S_EVENTS_COMPARE_1 = 0;
  if (DAT_230032d0 == 0) {
    DAT_230032d0 = 1;
    goto LAB_23024a6c;
  }
  switch(DAT_230032d0) {
  case 1:
    FUN_230240ac(2);
    DAT_230032d0 = 2;
    goto LAB_23024aa6;
  case 2:
    DAT_230032d0 = 3;
    break;
  case 3:
    DAT_230032d0 = 4;
    break;
  case 4:
    FUN_230240ac(2);
    DAT_230032d0 = 5;
LAB_23024aa6:
    FUN_23023fa4();
    if (DAT_23005370 != 0xd) {
      return;
    }
    if (DAT_23003484 == '\0') {
      FUN_23020f1c(&DAT_23005370,&RADIO_S_TASKS_DISABLE,0xe);
      DAT_23003484 = 0;
      return;
    }
    uVar8 = 0;
    do {
      puVar10 = (undefined4 *)FUN_230207ec(0,uVar8 & 0xffff);
      uVar11 = uVar8 + 1;
      if (puVar10 != (undefined4 *)0x0) {
        DAT_2300347e._0_2_ = (undefined2)uVar8;
        DAT_23003488 = 1;
        goto LAB_230248be;
      }
      uVar8 = uVar11;
    } while (uVar11 != 6);
    DAT_2300347e._0_2_ = 0xff;
    DAT_230053e4 = 5;
    DAT_230053e6 = FUN_230209dc(0,DAT_23005397);
    DAT_230053e8._0_2_ = DAT_23005376 << 8 | DAT_23005376 >> 8;
    DAT_23005397 = DAT_23005397 + '\x01';
    DAT_230053e7 = 0x1f;
    if (DAT_23005397 == '\b') {
      puVar10 = (undefined4 *)&DAT_230053e4;
      DAT_23005397 = '\x01';
    }
    else {
      puVar10 = (undefined4 *)&DAT_230053e4;
    }
LAB_230248be:
    uVar2 = FUN_230209d0(1,DAT_23003488,
                         *(undefined1 *)((int)&DAT_230033e8 + (DAT_230032ca + 0xfcc) * 2));
    *(undefined1 *)((int)puVar10 + 1) = uVar2;
    DAT_23003074 = puVar10[1];
    DAT_23003078 = puVar10[2];
    DAT_23003070 = *puVar10;
    DAT_2300307c = puVar10[3];
    RADIO_S_PACKETPTR = 0x23003070;
    TIMER020_S_TASKS_CAPTURE_7 = 1;
    if (DAT_230032d0 == 2) {
      dVar9 = TIMER020_S_CC_7;
      if (0x14a0 < dVar9) goto LAB_23024932;
    }
    else if ((DAT_230032d0 == 5) && (dVar9 = TIMER020_S_CC_7, 0x33e0 < dVar9)) {
LAB_23024932:
      FUN_23020f1c(&DAT_23005370,&RADIO_S_TASKS_DISABLE,0xd);
      DAT_23003484 = 0;
      return;
    }
    _DAT_5300e440 = 1;
    _DAT_5300e000 = 1;
    DAT_23003484 = 0;
    return;
  case 5:
    DAT_230032d0 = 0;
    break;
  default:
    goto switchD_23024a52_default;
  }
LAB_23024a6c:
  FUN_23023fa4();
  FUN_230240ac(4);
  return;
}


