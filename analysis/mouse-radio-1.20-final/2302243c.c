/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302243c. Types and names are inferred; NOT original source. */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * ram_candidate_2302243c(undefined4 *param_1)

{
  undefined2 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  ushort uVar6;
  int iVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  char *pcVar10;
  char cVar11;
  byte bVar12;
  ushort uVar13;
  undefined4 *puVar14;
  dword dVar15;
  dword dVar16;
  uint *puVar17;
  uint uVar18;
  uint uVar19;
  bool bVar20;
  bool bVar21;
  bool bVar22;
  undefined4 local_20 [2];
  
  if ((DAT_23002794 == 0) || (DAT_23002794 == 1)) {
LAB_23022bb4:
    dVar15 = TIMER020_S_EVENTS_COMPARE_0;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_0 = 0;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_1;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_1 = 0;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_2;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_2 = 0;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_3;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_3 = 0;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_4;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_4 = 0;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_5;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_5 = 0;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_6;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_6 = 0;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_7;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_7 = 0;
    }
    return param_1;
  }
  if (DAT_23002794 == 2) {
    dVar15 = TIMER020_S_EVENTS_COMPARE_0;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_0 = 0;
      TIMER020_S_CC_0 = 500;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_1;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_1 = 0;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_2;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_2 = 0;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_3;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_3 = 0;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_4;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_4 = 0;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_5;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_5 = 0;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_6;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_6 = 0;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_7;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_7 = 0;
      return param_1;
    }
    return param_1;
  }
  if (DAT_23002798 == 2) {
    dVar15 = TIMER020_S_EVENTS_COMPARE_0;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_0 = 0;
      TIMER020_S_CC_0 = 500;
      TIMER020_S_CC_1 = 0x113;
      TIMER020_S_CC_2 = 300;
      DAT_2300283c = 0;
      return (undefined4 *)0x113;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_1;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_1 = 0;
      if (DAT_2300283c == 0) {
        if (DAT_23002a04 != (undefined4 *)0x19) {
          return DAT_23002a04;
        }
        if ((undefined4 *)(uint)DAT_23002a20 == (undefined4 *)0x1) {
          RADIO_S_SUBSCRIBE_RXEN = DAT_230076f3 | 0x80000000;
          RADIO_S_SUBSCRIBE_DISABLE = DAT_230076f4 | 0x80000000;
          TIMER020_S_SUBSCRIBE_CAPTURE_7 = (dword)(DAT_230076ef | 0x80000000);
          RADIO_S_PACKETPTR = 0x23002630;
          DAT_23002a04 = (undefined4 *)0x1a;
          DAT_23002a20 = 0;
          return (undefined4 *)(DAT_230076ef | 0x80000000);
        }
        DAT_23002a04 = (undefined4 *)0x18;
        return (undefined4 *)(uint)DAT_23002a20;
      }
      if (DAT_2300283c != 2) {
        return (undefined4 *)0x0;
      }
      if (DAT_23002a04 != (undefined4 *)0x18) {
        return (undefined4 *)0x0;
      }
      puVar5 = (undefined4 *)FUN_230216b0();
      if (((puVar5 != (undefined4 *)0x0) && (DAT_230029d0 == '\0')) &&
         ((byte)(&DAT_230029d1)[DAT_23002836] < 4)) {
        return puVar5;
      }
      RADIO_S_SUBSCRIBE_TXEN = DAT_230076f5 | 0x80000000;
      RADIO_S_FREQUENCY = _DAT_2300278c & 0xffff;
      DAT_23002a04 = (undefined4 *)0x19;
      uVar19 = 0;
      do {
        puVar5 = (undefined4 *)FUN_230214e0(0,uVar19 & 0xffff);
        uVar2 = DAT_23002a1e;
        uVar18 = uVar19 + 1;
        if (puVar5 != (undefined4 *)0x0) {
          uVar3 = *(undefined1 *)((int)&DAT_23002a14 + (uint)DAT_23002836 * 2);
          DAT_23002a1a._0_2_ = (ushort)uVar19;
          (&DAT_230029d1)[DAT_23002836] = 0;
          DAT_23002a20 = 1;
          DAT_23002a10 = 0;
          uVar2 = FUN_2302168c(1,uVar2,uVar3);
          *(undefined1 *)((int)puVar5 + 1) = uVar2;
          goto LAB_2302324a;
        }
        uVar19 = uVar18;
      } while (uVar18 != 6);
      DAT_23002a1a._0_2_ = 0xff;
      _DAT_23002a76 = CONCAT31(_DAT_23002a77,5);
      (&DAT_230029d1)[DAT_23002836] = 0;
      DAT_23002a20 = 1;
      uVar2 = FUN_2302168c(0,0,0);
      _DAT_23002a76 = CONCAT11(uVar2,DAT_23002a76);
      uVar2 = FUN_23021698(0,DAT_23002a2a);
      DAT_23002a2a = DAT_23002a2a + '\x01';
      if (DAT_23002a2a == '\b') {
        DAT_23002a2a = '\x01';
      }
      _DAT_23002a76 = CONCAT12(uVar2,_DAT_23002a76);
      DAT_23002a7a = CONCAT22(DAT_23002a7a._2_2_,
                              (ushort)((DAT_23002a10 & 0xff) << 8) | (ushort)DAT_23002a10 >> 8);
      _DAT_23002a76 = CONCAT13(0x17,_DAT_23002a76);
      uVar2 = FUN_2302168c(1,DAT_23002a1e,
                           *(undefined1 *)((int)&DAT_23002a14 + (uint)DAT_23002836 * 2));
      puVar5 = (undefined4 *)&DAT_23002a76;
      _DAT_23002a76 = CONCAT11(uVar2,DAT_23002a76);
LAB_2302324a:
      RADIO_S_PACKETPTR = 0x23002650;
      DAT_23002650 = *puVar5;
      DAT_23002654 = puVar5[1];
      DAT_23002658 = (undefined4 *)puVar5[2];
      DAT_2300265c = puVar5[3];
      return (undefined4 *)puVar5[2];
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_2;
    if (dVar15 != 1) {
      dVar15 = TIMER020_S_EVENTS_COMPARE_3;
      if (dVar15 == 1) {
        TIMER020_S_EVENTS_COMPARE_3 = 0;
        return param_1;
      }
      dVar15 = TIMER020_S_EVENTS_COMPARE_4;
      if (dVar15 == 1) {
        TIMER020_S_EVENTS_COMPARE_4 = 0;
        return param_1;
      }
      dVar15 = TIMER020_S_EVENTS_COMPARE_5;
      if (dVar15 == 1) {
        TIMER020_S_EVENTS_COMPARE_5 = 0;
        return param_1;
      }
      dVar15 = TIMER020_S_EVENTS_COMPARE_6;
      if (dVar15 == 1) {
        TIMER020_S_EVENTS_COMPARE_6 = 0;
        return param_1;
      }
      dVar15 = TIMER020_S_EVENTS_COMPARE_7;
      if (dVar15 == 1) {
        TIMER020_S_EVENTS_COMPARE_7 = 0;
        return param_1;
      }
      return param_1;
    }
    puVar5 = (undefined4 *)0x2;
    TIMER020_S_EVENTS_COMPARE_2 = 0;
    DAT_2300283c = 2;
    TIMER020_S_CC_1 = 0x1cc;
    if (DAT_230029c4 != (undefined4 *)0x0) {
      puVar14 = (undefined4 *)((int)DAT_230029c4 + (int)DAT_230029b8);
      puVar8 = (undefined4 *)((int)puVar14 >> 2);
      puVar5 = DAT_230029b4;
      DAT_230029b8 = puVar14;
      if (DAT_230029b4 == (undefined4 *)0x0) {
        DAT_230029bc = (undefined4 *)((int)DAT_230029bc + 1);
        if (DAT_230029bc == (undefined4 *)0x4) {
          DAT_230029b8 = DAT_230029b4;
          DAT_230029bc = DAT_230029b4;
          DAT_230029b4 = puVar8;
        }
      }
      else {
        DAT_230029bc = (undefined4 *)((int)DAT_230029bc + 1);
        if (DAT_23002794 == 3) {
          if (DAT_230029bc == (undefined4 *)0x4) {
            DAT_230029b8 = (undefined4 *)0x0;
            DAT_230029bc = (undefined4 *)0x0;
            if (puVar8 == (undefined4 *)0x0) {
              DAT_230029c4 = (undefined4 *)0x0;
              DAT_230029c8 = DAT_230029c4;
              goto LAB_23023314;
            }
          }
          else {
            if (4 < (int)DAT_230029bc) {
              DAT_230029b8 = (undefined4 *)0x0;
              DAT_230029bc = (undefined4 *)0x0;
            }
            puVar8 = DAT_230029c8;
            DAT_230029c4 = DAT_230029c8;
            if (DAT_230029c8 == (undefined4 *)0x0) goto LAB_23023314;
          }
        }
        else {
          if (DAT_230029bc == (undefined4 *)0x1) {
            DAT_230029b8 = (undefined4 *)0x0;
            DAT_230029bc = (undefined4 *)0x0;
            DAT_230029c8 = puVar14;
          }
          else if (1 < (int)DAT_230029bc) {
            DAT_230029b8 = (undefined4 *)0x0;
            DAT_230029bc = (undefined4 *)0x0;
          }
          puVar8 = DAT_230029c8;
          if (DAT_230029c8 == (undefined4 *)0x0) goto LAB_23023418;
        }
        if (DAT_230029b4 < puVar8) {
          if (1 < (int)puVar8 - (int)DAT_230029b4) {
            DAT_230029c0 = 1;
            DAT_230029cc = 4;
          }
        }
        else if ((puVar8 < DAT_230029b4) &&
                (puVar5 = (undefined4 *)((int)DAT_230029b4 - (int)puVar8), 1 < (int)puVar5)) {
          DAT_230029c0 = 2;
          DAT_230029cc = 4;
        }
        DAT_230029c8 = (undefined4 *)0x0;
      }
LAB_23023418:
      DAT_230029c4 = (undefined4 *)0x0;
    }
    if (DAT_23002794 < 3) {
      if (DAT_230029c0 == 1) {
        TIMER020_S_CC_0 = 0x1f7;
        DAT_2300283c = 2;
        DAT_230029c0 = 0;
        return puVar5;
      }
      if (DAT_230029c0 == 2) {
        TIMER020_S_CC_0 = 0x1f1;
        DAT_2300283c = 2;
        DAT_230029c0 = 0;
        return puVar5;
      }
      DAT_2300283c = 2;
      DAT_230029c0 = 0;
      return puVar5;
    }
LAB_23023314:
    DAT_23002a0c = DAT_23002a0c + 1;
    DAT_23002a10 = DAT_23002a10 + 1;
    DAT_23002a0a = DAT_23002a0a + 1;
    (&DAT_230029d1)[DAT_23002836] = (&DAT_230029d1)[DAT_23002836] + '\x01';
    if (DAT_230029d0 != '\0') {
      DAT_230029d0 = DAT_230029d0 + -1;
    }
    if (DAT_230029cc != 0) {
      DAT_230029cc = DAT_230029cc + -1;
    }
    puVar5 = (undefined4 *)FUN_2302218c();
    _DAT_2300278c = CONCAT22(DAT_2300278e,(short)puVar5);
    if (DAT_230029c0 == 1) {
      TIMER020_S_CC_0 = 0x1f7;
    }
    else if (DAT_230029c0 == 2) {
      TIMER020_S_CC_0 = 0x1f1;
    }
    DAT_230029c0 = 0;
    if (2 < DAT_23002794) {
      if (DAT_23002a0c < 100) {
        if (DAT_23002a10 < 200) {
          DAT_23002794 = 3;
        }
        else {
          DAT_23002794 = 4;
        }
      }
      else {
        FUN_23021b90(&DAT_23002a04,&RADIO_S_TASKS_DISABLE,0);
        RADIO_S_SUBSCRIBE_RXEN = 0;
        RADIO_S_SUBSCRIBE_DISABLE = 0;
        TIMER020_S_SUBSCRIBE_CAPTURE_7 = 0;
        TIMER020_S_TASKS_STOP = 1;
        FUN_230217e0();
        DAT_23002794 = 0;
        DAT_23002978 = 0;
        FUN_23022c3c();
        FUN_23022f5c();
        local_20[0] = 0;
        puVar5 = (undefined4 *)FUN_23025ed4(local_20);
      }
    }
    return puVar5;
  }
  if (DAT_23002798 == 1) {
    dVar15 = TIMER020_S_EVENTS_COMPARE_0;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_0 = 0;
      TIMER020_S_CC_0 = 500;
      if (DAT_230029ac == 1) {
        dVar15 = 0x5a;
        dVar16 = 0x78;
      }
      else {
        dVar15 = 0x6e;
        dVar16 = 0x8c;
      }
      TIMER020_S_CC_1 = dVar15;
      TIMER020_S_CC_2 = dVar16;
      TIMER020_S_CC_3 = 0;
      DAT_2300283c = 0;
      puVar8 = (undefined4 *)FUN_23023ab8(1);
      puVar5 = DAT_230029b4;
      if (DAT_230029c4 == (undefined4 *)0x0) {
        return puVar8;
      }
      DAT_230029b8 = (undefined4 *)((int)DAT_230029c4 + (int)DAT_230029b8);
      puVar14 = (undefined4 *)((int)DAT_230029b8 >> 2);
      if (DAT_230029b4 == (undefined4 *)0x0) {
        if ((int)DAT_230029bc + 1U == 4) {
          DAT_230029b4 = puVar14;
          DAT_230029b8 = puVar5;
          DAT_230029bc = puVar5;
          DAT_230029c4 = (undefined4 *)0x0;
          return puVar8;
        }
        DAT_230029bc = (undefined4 *)((int)DAT_230029bc + 1U);
        DAT_230029c4 = (undefined4 *)0x0;
        return puVar8;
      }
      puVar5 = (undefined4 *)(uint)DAT_23002794;
      iVar7 = (int)DAT_230029bc + 1;
      if (puVar5 == (undefined4 *)0x3) {
        bVar21 = SBORROW4(iVar7,4);
        DAT_230029bc = (undefined4 *)((int)DAT_230029bc - 3);
        if (iVar7 == 4) goto LAB_23023ee0;
      }
      else {
        bVar21 = SBORROW4(iVar7,1);
        puVar14 = DAT_230029b8;
        if (iVar7 == 1) {
LAB_23023ee0:
          if (puVar14 == (undefined4 *)0x0) {
            DAT_230029b8 = (undefined4 *)0x0;
            DAT_230029bc = (undefined4 *)0x0;
            DAT_230029c4 = (undefined4 *)0x0;
            DAT_230029c8 = puVar14;
            return puVar5;
          }
          if (DAT_230029b4 < puVar14) {
            if ((int)puVar14 - (int)DAT_230029b4 < 2) {
              DAT_230029b8 = (undefined4 *)0x0;
              DAT_230029bc = (undefined4 *)0x0;
              DAT_230029c4 = (undefined4 *)0x0;
              DAT_230029c8 = (undefined4 *)0x0;
              return puVar5;
            }
            DAT_230029b8 = (undefined4 *)0x0;
            DAT_230029bc = (undefined4 *)0x0;
            DAT_230029c0 = 1;
            DAT_230029c4 = (undefined4 *)0x0;
            DAT_230029c8 = (undefined4 *)0x0;
            DAT_230029cc = 4;
            return puVar5;
          }
          if (DAT_230029b4 == puVar14) {
            DAT_230029b8 = (undefined4 *)0x0;
            DAT_230029bc = (undefined4 *)0x0;
            DAT_230029c4 = (undefined4 *)0x0;
            DAT_230029c8 = (undefined4 *)0x0;
            return puVar5;
          }
          if ((int)DAT_230029b4 - (int)puVar14 < 2) {
            DAT_230029b8 = (undefined4 *)0x0;
            DAT_230029bc = (undefined4 *)0x0;
            DAT_230029c4 = (undefined4 *)0x0;
            DAT_230029c8 = (undefined4 *)0x0;
            return puVar5;
          }
          DAT_230029b8 = (undefined4 *)0x0;
          DAT_230029bc = (undefined4 *)0x0;
          DAT_230029c0 = 2;
          DAT_230029c4 = (undefined4 *)0x0;
          DAT_230029c8 = (undefined4 *)0x0;
          DAT_230029cc = 4;
          return puVar5;
        }
      }
      if ((int)DAT_230029bc < 0 != bVar21) {
        DAT_230029c8 = (undefined4 *)0x0;
        DAT_230029bc = (undefined4 *)iVar7;
        DAT_230029c4 = (undefined4 *)0x0;
        return puVar5;
      }
      DAT_230029b8 = (undefined4 *)0x0;
      DAT_230029bc = (undefined4 *)0x0;
      DAT_230029c4 = (undefined4 *)0x0;
      DAT_230029c8 = (undefined4 *)0x0;
      return puVar5;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_1;
    if (dVar15 == 1) {
      TIMER020_S_EVENTS_COMPARE_1 = 0;
      if (DAT_230029ac == 1) {
        if (DAT_2300283c == 0) {
          DAT_2300283c = DAT_230029ac;
          puVar5 = (undefined4 *)FUN_23023ab8(3);
          return puVar5;
        }
        switch(DAT_2300283c) {
        case 1:
          goto switchD_23023e60_caseD_1;
        case 2:
          DAT_2300283c = 3;
          puVar5 = (undefined4 *)FUN_23023ab8();
          return puVar5;
        case 3:
          DAT_2300283c = 4;
          puVar5 = (undefined4 *)FUN_23023ab8(6);
          return puVar5;
        case 4:
          DAT_2300283c = 0;
          FUN_23023a10();
          puVar5 = (undefined4 *)FUN_23023ab8(3);
          return puVar5;
        default:
          return (undefined4 *)0x0;
        }
      }
      uVar1 = 1;
      if (DAT_2300283c != 0) {
        if (DAT_2300283c == 1) {
switchD_23023e60_caseD_1:
          DAT_2300283c = 2;
          puVar5 = (undefined4 *)FUN_23023ab8(3);
          return puVar5;
        }
        if (DAT_2300283c != 2) {
          if (DAT_2300283c == 3) {
            DAT_2300283c = 0;
            FUN_23023a10();
            puVar5 = (undefined4 *)FUN_23023ab8(3);
            return puVar5;
          }
          return (undefined4 *)0x0;
        }
        uVar1 = 3;
      }
      DAT_2300283c = uVar1;
      puVar5 = (undefined4 *)FUN_23023ab8(6);
      return puVar5;
    }
    dVar15 = TIMER020_S_EVENTS_COMPARE_2;
    if (dVar15 != 1) {
      dVar15 = TIMER020_S_EVENTS_COMPARE_3;
      if (dVar15 == 1) {
        TIMER020_S_EVENTS_COMPARE_3 = 0;
        if ((DAT_2300283c != 1) && (1 < DAT_2300283c - 3)) {
          return param_1;
        }
        puVar5 = (undefined4 *)FUN_23023ab8(8);
        return puVar5;
      }
      dVar15 = TIMER020_S_EVENTS_COMPARE_4;
      if (dVar15 == 1) {
        TIMER020_S_EVENTS_COMPARE_4 = 0;
        return param_1;
      }
      dVar15 = TIMER020_S_EVENTS_COMPARE_5;
      if (dVar15 == 1) {
        TIMER020_S_EVENTS_COMPARE_5 = 0;
        return param_1;
      }
      dVar15 = TIMER020_S_EVENTS_COMPARE_6;
      if (dVar15 == 1) {
        TIMER020_S_EVENTS_COMPARE_6 = 0;
        return param_1;
      }
      dVar15 = TIMER020_S_EVENTS_COMPARE_7;
      if (dVar15 == 1) {
        TIMER020_S_EVENTS_COMPARE_7 = 0;
        return param_1;
      }
      return param_1;
    }
    puVar5 = (undefined4 *)(uint)DAT_2300283c;
    TIMER020_S_EVENTS_COMPARE_2 = 0;
    if (DAT_230029ac == 1) {
      if (puVar5 == (undefined4 *)0x1) {
        TIMER020_S_CC_1 = 0xaf;
        TIMER020_S_CC_2 = 0xcd;
        TIMER020_S_CC_3 = 0;
        puVar5 = (undefined4 *)FUN_23023ab8();
        return puVar5;
      }
      if (puVar5 == (undefined4 *)0x2) {
        dVar16 = 0x104;
        dVar15 = 0x122;
LAB_2302404c:
        TIMER020_S_CC_1 = dVar16;
        TIMER020_S_CC_2 = dVar15;
        TIMER020_S_CC_3 = 0;
        puVar5 = (undefined4 *)FUN_23023ab8(1);
        return puVar5;
      }
      if (puVar5 == (undefined4 *)0x3) {
        dVar16 = 0x16d;
        dVar15 = 0x18b;
        goto LAB_2302404c;
      }
      if (puVar5 != (undefined4 *)0x4) {
        return puVar5;
      }
      TIMER020_S_CC_1 = 0x1db;
      TIMER020_S_CC_2 = 0;
      TIMER020_S_CC_3 = 0x1c7;
      puVar5 = (undefined4 *)FUN_23023ab8(1);
      if (DAT_230029c0 != 1) {
        if (DAT_230029c0 == 2) {
          TIMER020_S_CC_0 = 0x1f1;
        }
        goto LAB_23023994;
      }
    }
    else {
      if (puVar5 == (undefined4 *)0x1) {
        TIMER020_S_CC_1 = 0xdc;
        TIMER020_S_CC_2 = 0xfa;
        TIMER020_S_CC_3 = 200;
        puVar5 = (undefined4 *)FUN_23023ab8();
        return puVar5;
      }
      if (puVar5 == (undefined4 *)0x2) {
        TIMER020_S_CC_1 = 0x168;
        TIMER020_S_CC_2 = 0x186;
        TIMER020_S_CC_3 = 0;
        puVar5 = (undefined4 *)FUN_23023ab8(1);
        return puVar5;
      }
      if (puVar5 != (undefined4 *)0x3) {
        return puVar5;
      }
      TIMER020_S_CC_1 = 0x1d6;
      TIMER020_S_CC_2 = 0;
      TIMER020_S_CC_3 = 0x1c2;
      puVar5 = (undefined4 *)FUN_23023ab8(1);
      if (DAT_230029c0 != 1) {
        if (DAT_230029c0 == 2) {
          TIMER020_S_CC_0 = 0x1f1;
        }
        goto LAB_23023994;
      }
    }
    TIMER020_S_CC_0 = 0x1f7;
LAB_23023994:
    DAT_230029c0 = 0;
    if (2 < DAT_23002794) {
      if (99 < DAT_23002a0c) {
        FUN_23021b90(&DAT_23002a04,&RADIO_S_TASKS_DISABLE,0);
        RADIO_S_SUBSCRIBE_RXEN = 0;
        RADIO_S_SUBSCRIBE_DISABLE = 0;
        TIMER020_S_SUBSCRIBE_CAPTURE_7 = 0;
        TIMER020_S_TASKS_STOP = 1;
        FUN_230217e0();
        DAT_23002794 = 0;
        DAT_23002978 = 0;
        FUN_23022c3c();
        FUN_23022f5c();
        puVar5 = (undefined4 *)FUN_23025ed4(&stack0xffffffe8);
        return puVar5;
      }
      if (DAT_23002a10 < 200) {
        DAT_23002794 = 3;
      }
      else {
        DAT_23002794 = 4;
      }
    }
    return puVar5;
  }
  if (DAT_23002798 != 4) goto LAB_23022bb4;
  dVar15 = TIMER020_S_EVENTS_COMPARE_0;
  if (dVar15 == 1) {
    TIMER020_S_EVENTS_COMPARE_0 = 0;
    TIMER020_S_CC_0 = 500;
    if (DAT_230029ac == 1) {
      TIMER020_S_CC_1 = 0x4b;
      TIMER020_S_CC_2 = 100;
      TIMER020_S_CC_3 = 0;
      TIMER020_S_CC_4 = 0xa0;
LAB_23025252:
      if (DAT_23002a04 == (undefined4 *)0x19) {
LAB_23025388:
        RADIO_S_SUBSCRIBE_TXEN = 0;
        RADIO_S_SUBSCRIBE_TXEN = 0;
        RADIO_S_SUBSCRIBE_START = 0;
      }
    }
    else {
      if (DAT_230029ac == 2) {
        if (DAT_230027c7 == '\0') {
          TIMER020_S_CC_1 = 0x8c;
          TIMER020_S_CC_2 = 0xa5;
          TIMER020_S_CC_3 = 0;
          TIMER020_S_CC_4 = 0x8c;
        }
        else {
          TIMER020_S_CC_1 = 0x4b;
          TIMER020_S_CC_2 = 100;
          TIMER020_S_CC_3 = 0;
          TIMER020_S_CC_4 = 0xa0;
        }
        goto LAB_23025252;
      }
      if (DAT_230029ac < 5) {
        TIMER020_S_CC_1 = 0x8c;
        TIMER020_S_CC_2 = 0xa5;
        TIMER020_S_CC_3 = 0;
        TIMER020_S_CC_4 = 0x8c;
        goto LAB_23025252;
      }
      if (DAT_23002a04 == (undefined4 *)0x19) {
        TIMER020_S_CC_1 = 0x8c;
        TIMER020_S_CC_2 = 0xa5;
        TIMER020_S_CC_3 = 0;
        TIMER020_S_CC_4 = 0x8c;
        goto LAB_23025388;
      }
      TIMER020_S_CC_1 = 0x186;
      TIMER020_S_CC_2 = 0x19f;
      TIMER020_S_CC_3 = 0;
      TIMER020_S_CC_4 = 0;
    }
    DAT_2300283c = 0;
    if (DAT_230029c4 == (undefined4 *)0x0) goto LAB_2302528a;
    puVar5 = (undefined4 *)((int)DAT_230029c4 + (int)DAT_230029b8);
    DAT_230029b8 = puVar5;
    if (DAT_230029b4 == (undefined4 *)0x0) {
      DAT_230029bc = (undefined4 *)((int)DAT_230029bc + 1);
      if (DAT_230029bc == (undefined4 *)0x4) {
        DAT_230029b8 = DAT_230029b4;
        DAT_230029bc = DAT_230029b4;
        DAT_230029b4 = (undefined4 *)((int)puVar5 >> 2);
      }
    }
    else {
      puVar8 = (undefined4 *)((int)DAT_230029bc + 1);
      if (DAT_23002794 == 3) {
        bVar22 = SBORROW4((int)puVar8,4);
        DAT_230029bc = (undefined4 *)((int)DAT_230029bc - 3);
        bVar21 = puVar8 == (undefined4 *)0x4;
        if (!bVar21) goto LAB_23025340;
        DAT_230029b8 = (undefined4 *)0x0;
        DAT_230029bc = (undefined4 *)0x0;
        DAT_230029c8 = (undefined4 *)((int)puVar5 >> 2);
      }
      else {
        bVar22 = SBORROW4((int)puVar8,1);
        bVar21 = false;
        if (puVar8 == (undefined4 *)0x1) {
          DAT_230029b8 = (undefined4 *)0x0;
          DAT_230029bc = (undefined4 *)0x0;
          DAT_230029c8 = puVar5;
        }
        else {
LAB_23025340:
          bVar20 = (int)DAT_230029bc < 0;
          DAT_230029bc = puVar8;
          if (!bVar21 && bVar20 == bVar22) {
            DAT_230029b8 = (undefined4 *)0x0;
            DAT_230029bc = (undefined4 *)0x0;
          }
        }
      }
      if (DAT_230029c8 != (undefined4 *)0x0) {
        if (DAT_230029b4 < DAT_230029c8) {
          if (1 < (int)DAT_230029c8 - (int)DAT_230029b4) {
            DAT_230029c0 = 1;
            DAT_230029cc = 4;
          }
        }
        else if ((DAT_230029b4 != DAT_230029c8) && (1 < (int)DAT_230029b4 - (int)DAT_230029c8)) {
          DAT_230029c0 = 2;
          DAT_230029cc = 4;
        }
        DAT_230029c8 = (undefined4 *)0x0;
      }
    }
    DAT_230029c4 = (undefined4 *)0x0;
LAB_2302528a:
    FUN_230248c8();
    if (DAT_2300774b != '\0') {
      _DAT_5f9c200c = 1;
      _DAT_5f9c2000 = 1;
      return (undefined4 *)0x1;
    }
    return (undefined4 *)0x1;
  }
  dVar15 = TIMER020_S_EVENTS_COMPARE_1;
  if (dVar15 == 1) {
    TIMER020_S_EVENTS_COMPARE_1 = 0;
    dVar15 = TIMER020_S_CC_1;
    uVar6 = 1;
    if (dVar15 == 0x4b) {
LAB_230252da:
      DAT_2300283c = uVar6;
      puVar5 = (undefined4 *)0x3;
    }
    else {
      dVar15 = TIMER020_S_CC_1;
      if (dVar15 == 0x8c) {
        puVar5 = (undefined4 *)0x6;
        DAT_2300283c = 2;
      }
      else {
        dVar15 = TIMER020_S_CC_1;
        if (dVar15 == 0xdc) {
          puVar5 = (undefined4 *)0x3;
          DAT_2300283c = 3;
          if (4 < DAT_230029ac) {
            TIMER020_S_CC_1 = 0x186;
            TIMER020_S_CC_2 = 0x19f;
            TIMER020_S_CC_4 = 0;
            DAT_2300283c = 3;
            return (undefined4 *)0x186;
          }
        }
        else {
          puVar5 = (undefined4 *)TIMER020_S_CC_1;
          if (puVar5 == (undefined4 *)0x145) {
            uVar6 = 4;
            goto LAB_230252da;
          }
          dVar15 = TIMER020_S_CC_1;
          if (dVar15 == 0x186) {
            puVar5 = (undefined4 *)0x6;
            DAT_2300283c = 5;
          }
          else {
            dVar15 = TIMER020_S_CC_1;
            if (dVar15 != 0x1d6) {
              return puVar5;
            }
            puVar5 = (undefined4 *)0x3;
            DAT_2300283c = 0;
          }
        }
      }
    }
LAB_23024918:
    if (DAT_23002a04 == (undefined4 *)0x19) {
      if (puVar5 == (undefined4 *)0x1) {
        RADIO_S_SUBSCRIBE_TXEN = 0;
        RADIO_S_SUBSCRIBE_TXEN = 0;
        RADIO_S_SUBSCRIBE_START = 0;
        return (undefined4 *)0x1;
      }
      return puVar5;
    }
    if (DAT_23002a04 == (undefined4 *)0x1a) {
      if (puVar5 != (undefined4 *)0x8) {
        return puVar5;
      }
      pbVar9 = (byte *)RADIO_S_PACKETPTR;
      if (9 < *pbVar9 - 1) {
        puVar5 = (undefined4 *)FUN_23021b90(&DAT_23002a04,&RADIO_S_TASKS_DISABLE);
        return puVar5;
      }
      return (undefined4 *)0x8;
    }
    if (DAT_23002a04 != (undefined4 *)0x18) {
      return puVar5;
    }
    if (puVar5 != (undefined4 *)0x3) {
      if (puVar5 != (undefined4 *)0x6) {
        return puVar5;
      }
      if (DAT_23002a20 != 1) {
        puVar5 = (undefined4 *)FUN_23021b90(&DAT_23002a04,&RADIO_S_TASKS_DISABLE);
        return puVar5;
      }
      RADIO_S_SUBSCRIBE_DISABLE = DAT_230076f4 | 0x80000000;
      dVar15 = RADIO_S_SHORTS;
      RADIO_S_SHORTS = dVar15 | 0x80000;
      RADIO_S_PACKETPTR = 0x23002630;
      if (DAT_230029e0 != '\0' || DAT_230029e4 != 0) {
        dVar15 = RADIO_S_SHORTS;
        RADIO_S_SHORTS = dVar15 | 0x10;
        DAT_23002a04 = (undefined4 *)0x1a;
        DAT_23002a20 = 0;
        return (undefined4 *)&DAT_23002630;
      }
      DAT_23002a04 = (undefined4 *)0x1a;
      DAT_23002a20 = 0;
      return (undefined4 *)&DAT_23002630;
    }
    if (DAT_2300283c != 0) {
      if (DAT_2300283c == 3) {
        if (DAT_230029ac == 2) goto LAB_23024c5c;
        if (DAT_23002671 == '\0') goto LAB_23024c74;
LAB_23024df0:
        RADIO_S_SUBSCRIBE_TXEN = DAT_230076f3 | 0x80000000;
        dVar15 = RADIO_S_SHORTS;
        RADIO_S_SHORTS = dVar15 | 1;
        _DAT_2300278c = _DAT_23002790;
        if (DAT_230029ac != 1) {
          if (DAT_230029ac == 2) {
            if (DAT_230027c7 == '\0') {
              dVar15 = RADIO_S_SHORTS;
              RADIO_S_SHORTS = dVar15 | 0x80000;
            }
            goto LAB_23024f66;
          }
          dVar15 = RADIO_S_SHORTS;
          RADIO_S_SHORTS = dVar15 | 0x80000;
          RADIO_S_FREQUENCY = _DAT_23002790 & 0xffff;
          RADIO_S_TXPOWER = (uint)(byte)DAT_23002a00;
          if (DAT_23002670 != 0) goto joined_r0x23024db2;
LAB_23024e3e:
          if (DAT_23002671 == '\0') {
            if ((int)((uint)DAT_23002a0a << 0x1f) < 0) {
              uVar6 = 2;
              do {
                puVar17 = (uint *)FUN_230214e0(0,uVar6);
                uVar13 = uVar6 + 1;
                if (puVar17 != (uint *)0x0) goto LAB_23024eee;
                uVar6 = uVar13;
              } while (uVar13 != 6);
            }
            uVar19 = 0;
            do {
              uVar18 = uVar19 & 0xffff;
              puVar17 = (uint *)FUN_230214e0(0,uVar18);
              uVar19 = uVar19 + 1;
              if (puVar17 != (uint *)0x0) goto LAB_230250c8;
            } while (uVar19 != 6);
          }
          else {
            puVar17 = (uint *)FUN_230214e0(0,1);
            if (puVar17 != (uint *)0x0) {
              uVar6 = 1;
              goto joined_r0x230250f8;
            }
          }
          goto joined_r0x23024db2;
        }
LAB_23024f66:
        RADIO_S_FREQUENCY = _DAT_23002790 & 0xffff;
        RADIO_S_TXPOWER = (uint)(byte)DAT_23002a00;
        if (DAT_23002670 == 0) goto LAB_23024e3e;
        goto LAB_23024b44;
      }
      if ((DAT_2300283c == 1) || (DAT_2300283c == 4)) {
        if (DAT_230029ac == 1) {
          if (DAT_23002671 == '\0') {
            if ((undefined4 *)(uint)DAT_23002a26 != (undefined4 *)0x0) {
              return (undefined4 *)(uint)DAT_23002a26;
            }
            puVar5 = (undefined4 *)FUN_230216e0(0,1);
            if (puVar5 != (undefined4 *)0x0) goto LAB_23024a06;
            goto LAB_23024c8a;
          }
        }
        else {
          if (DAT_230029ac != 2) {
            return (undefined4 *)0x3;
          }
          if (DAT_230027c7 == '\0') {
            return (undefined4 *)0x3;
          }
          if (DAT_23002671 == '\0') {
            return (undefined4 *)0x3;
          }
        }
      }
      else {
        puVar5 = (undefined4 *)0x3;
        if (DAT_230029d0 == '\0') goto LAB_230249ee;
      }
LAB_23024c9a:
      uVar6 = DAT_230029ac;
      RADIO_S_SUBSCRIBE_START = DAT_230076f3 | 0x80000000;
      dVar15 = RADIO_S_SHORTS;
      RADIO_S_SHORTS = dVar15 | 1;
      _DAT_2300278c = _DAT_23002790;
      RADIO_S_FREQUENCY = _DAT_23002790 & 0xffff;
      RADIO_S_TXPOWER = (uint)(byte)DAT_23002a00;
      if (DAT_23002670 != 0) goto joined_r0x23024db2;
      if (DAT_2300283c != 1) {
        if (DAT_2300283c != 4) goto joined_r0x23024db2;
        if (DAT_230029ac != 1) {
          if (DAT_230029ac < 3) goto LAB_23024fa2;
          goto LAB_23024cee;
        }
        if (DAT_23002a26 != 0) goto LAB_23024b44;
        puVar17 = (uint *)FUN_230214e0(0,1);
        if (puVar17 == (uint *)0x0) goto joined_r0x2302515a;
joined_r0x230250f8:
        DAT_23002a20 = 1;
        if (DAT_230029ac < 3) goto LAB_23025020;
        goto LAB_23024b80;
      }
      if (DAT_230029ac == 1) {
        if (DAT_23002a26 == 0) {
          puVar17 = (uint *)FUN_230214e0();
          if (puVar17 != (uint *)0x0) {
            if (2 < DAT_230029ac) goto LAB_23024f0e;
            goto LAB_23025020;
          }
joined_r0x2302515a:
          if (2 < DAT_230029ac) goto LAB_23024cee;
        }
        goto LAB_23024b44;
      }
      if (2 < DAT_230029ac) goto LAB_23024cee;
LAB_23024fa2:
      DAT_23002a20 = 1;
      if (DAT_23002671 == '\0') goto LAB_23024cee;
      if (DAT_230029ac == 2) {
        if (DAT_2300283c != 3) {
          DAT_23002a20 = 0;
          goto LAB_23024b5a;
        }
        goto LAB_23024fe2;
      }
      goto LAB_23024b5a;
    }
    if (DAT_230029ac == 2) {
LAB_23024c5c:
      DAT_230027c7 = DAT_230027c8;
      if (DAT_23002670 != 0) {
        DAT_230027c7 = '\x01';
      }
      if (DAT_23002671 == '\0') {
LAB_23024c74:
        puVar5 = (undefined4 *)FUN_230216b0(0);
        if ((puVar5 != (undefined4 *)0x0) && (DAT_230029d0 == '\0')) {
LAB_230249ee:
          if (DAT_23002794 == 3) {
            if ((byte)(&DAT_230029d1)[DAT_23002836] < 4) goto LAB_23024a06;
          }
          else if ((byte)(&DAT_230029d1)[DAT_23002836] < 0x10) {
LAB_23024a06:
            if (DAT_230029ac != 1) {
              return puVar5;
            }
            if (DAT_2300283c == 0) {
              pbVar9 = &DAT_230076f5;
            }
            else {
              if (DAT_2300283c != 3) {
                return puVar5;
              }
              pbVar9 = &DAT_230076f3;
            }
            RADIO_S_SUBSCRIBE_TXEN = *pbVar9 | 0x80000000;
            dVar15 = RADIO_S_SHORTS;
            RADIO_S_SHORTS = dVar15 | 1;
            uVar19 = DAT_23002650 >> 0x10;
            puVar5 = (undefined4 *)(uint)DAT_2300283c;
            DAT_23002650 = CONCAT22((ushort)uVar19 & 0xff00,0x5502);
            RADIO_S_PACKETPTR = 0x23002650;
            RADIO_S_FREQUENCY = _DAT_23002790 & 0xffff;
            RADIO_S_TXPOWER = (uint)(byte)DAT_23002a00;
            TIMER020_S_TASKS_CAPTURE_7 = 1;
            if (puVar5 == (undefined4 *)0x0) {
              dVar15 = TIMER020_S_CC_7;
              if (99 < dVar15) {
                _DAT_2300278c = _DAT_23002790;
                DAT_23002a04 = (undefined4 *)0x19;
                return (undefined4 *)0x0;
              }
            }
            else {
              if (puVar5 != (undefined4 *)0x3) {
                _DAT_2300278c = _DAT_23002790;
                DAT_23002a04 = (undefined4 *)0x19;
                return puVar5;
              }
              dVar15 = TIMER020_S_CC_7;
              if (dVar15 < 0xfb) {
                _DAT_2300278c = _DAT_23002790;
                DAT_23002a04 = (undefined4 *)0x19;
                return (undefined4 *)0x3;
              }
            }
            RADIO_S_SUBSCRIBE_TXEN = 0;
            RADIO_S_SUBSCRIBE_TXEN = 0;
            _DAT_2300278c = _DAT_23002790;
            DAT_23002a04 = (undefined4 *)0x18;
            return puVar5;
          }
        }
      }
LAB_23024c8a:
      if (DAT_2300283c != 0) {
        if (DAT_2300283c != 3) goto LAB_23024c9a;
        goto LAB_23024df0;
      }
    }
    else if (DAT_23002671 == '\0') goto LAB_23024c74;
    RADIO_S_SUBSCRIBE_TXEN = DAT_230076f5 | 0x80000000;
    dVar15 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar15 | 1;
    if ((DAT_230029ac != 1) && ((DAT_230029ac != 2 || (DAT_230027c7 == '\0')))) {
      dVar15 = RADIO_S_SHORTS;
      RADIO_S_SHORTS = dVar15 | 0x80000;
    }
    _DAT_2300278c = _DAT_23002790;
    RADIO_S_FREQUENCY = _DAT_23002790 & 0xffff;
    RADIO_S_TXPOWER = (uint)(byte)DAT_23002a00;
    if (DAT_23002670 == 0) {
      if ((int)((uint)DAT_23002a0a << 0x1f) < 0) {
        uVar6 = 2;
        do {
          puVar17 = (uint *)FUN_230214e0(0,uVar6);
          uVar13 = uVar6 + 1;
          if (puVar17 != (uint *)0x0) goto LAB_23024eee;
          uVar6 = uVar13;
        } while (uVar13 != 6);
      }
      uVar19 = 0;
      do {
        uVar18 = uVar19 & 0xffff;
        puVar17 = (uint *)FUN_230214e0(0,uVar18);
        uVar19 = uVar19 + 1;
        if (puVar17 != (uint *)0x0) goto LAB_230250c8;
      } while (uVar19 != 6);
    }
joined_r0x23024db2:
    if (DAT_230029ac < 3) {
LAB_23024b44:
      if (DAT_23002671 != '\0') goto LAB_23024b4c;
    }
LAB_23024cee:
    (&DAT_230029d1)[DAT_23002836] = 0;
    DAT_23002a1a._0_2_ = 0xff;
    _DAT_23002a76 = CONCAT31(_DAT_23002a77,5);
    DAT_23002a20 = 1;
    uVar2 = FUN_2302168c(1,0,0);
    _DAT_23002a76 = CONCAT11(uVar2,DAT_23002a76);
    uVar3 = FUN_23021698(0,DAT_23002a2a);
    uVar2 = DAT_23002a1e;
    DAT_23002a2a = DAT_23002a2a + '\x01';
    if (DAT_23002a2a == '\b') {
      DAT_23002a2a = '\x01';
    }
    _DAT_23002a76 = CONCAT12(uVar3,_DAT_23002a76);
    DAT_23002a7a = CONCAT22(DAT_23002a7a._2_2_,
                            (ushort)((DAT_23002a10 & 0xff) << 8) | (ushort)DAT_23002a10 >> 8);
    _DAT_23002a76 = CONCAT13(0x17,_DAT_23002a76);
    uVar4 = FUN_230221ec((undefined1)DAT_23002836);
    uVar2 = FUN_2302168c(1,uVar2,uVar4);
    puVar17 = (uint *)&DAT_23002a76;
    _DAT_23002a76 = CONCAT11(uVar2,DAT_23002a76);
    goto LAB_23024baa;
  }
  dVar15 = TIMER020_S_EVENTS_COMPARE_2;
  if (dVar15 != 1) {
    dVar15 = TIMER020_S_EVENTS_COMPARE_3;
    if (dVar15 != 1) {
      dVar15 = TIMER020_S_EVENTS_COMPARE_4;
      if (dVar15 == 1) {
        TIMER020_S_EVENTS_COMPARE_4 = 0;
        return param_1;
      }
      dVar15 = TIMER020_S_EVENTS_COMPARE_5;
      if (dVar15 == 1) {
        TIMER020_S_EVENTS_COMPARE_5 = 0;
        return param_1;
      }
      dVar15 = TIMER020_S_EVENTS_COMPARE_6;
      if (dVar15 == 1) {
        TIMER020_S_EVENTS_COMPARE_6 = 0;
        return param_1;
      }
      dVar15 = TIMER020_S_EVENTS_COMPARE_7;
      if (dVar15 == 1) {
        TIMER020_S_EVENTS_COMPARE_7 = 0;
        return param_1;
      }
      return param_1;
    }
    TIMER020_S_EVENTS_COMPARE_3 = 0;
    if ((DAT_2300283c != 2) && (DAT_2300283c != 5)) {
      return param_1;
    }
    puVar5 = (undefined4 *)0x8;
    goto LAB_23024918;
  }
  TIMER020_S_EVENTS_COMPARE_2 = 0;
  if (DAT_2300283c == 1) {
    puVar5 = (undefined4 *)0xa5;
    TIMER020_S_CC_1 = 0x8c;
    TIMER020_S_CC_2 = 0xa5;
    TIMER020_S_CC_3 = 0;
joined_r0x23025534:
    if (DAT_23002a04 == (undefined4 *)0x19) {
      RADIO_S_SUBSCRIBE_TXEN = 0;
      RADIO_S_SUBSCRIBE_TXEN = 0;
      RADIO_S_SUBSCRIBE_START = 0;
      return puVar5;
    }
    return puVar5;
  }
  switch(DAT_2300283c) {
  case 2:
    if (DAT_230029ac < 5) {
      puVar5 = (undefined4 *)0xfa;
      TIMER020_S_CC_1 = 0xdc;
      TIMER020_S_CC_2 = 0xfa;
      TIMER020_S_CC_4 = 0;
    }
    else {
      puVar5 = (undefined4 *)0xdc;
      TIMER020_S_CC_1 = 0xdc;
      TIMER020_S_CC_2 = 0;
      TIMER020_S_CC_4 = 0;
    }
    goto joined_r0x23025534;
  case 3:
    if (DAT_230029ac == 1) {
LAB_23025652:
      param_1 = (undefined4 *)0x15e;
      TIMER020_S_CC_1 = 0x145;
      TIMER020_S_CC_2 = 0x15e;
      TIMER020_S_CC_3 = 0;
      TIMER020_S_CC_4 = 0x19a;
    }
    else if (DAT_230029ac == 2) {
      if (DAT_230027c7 != '\0') goto LAB_23025652;
      param_1 = (undefined4 *)0x19f;
      TIMER020_S_CC_1 = 0x186;
      TIMER020_S_CC_2 = 0x19f;
      TIMER020_S_CC_3 = 0;
      TIMER020_S_CC_4 = 0x186;
    }
    else {
      param_1 = (undefined4 *)0x186;
      TIMER020_S_CC_1 = 0x186;
      TIMER020_S_CC_2 = 0x19f;
      TIMER020_S_CC_3 = 0;
      TIMER020_S_CC_4 = 0x186;
    }
    break;
  case 4:
    param_1 = (undefined4 *)0x19f;
    TIMER020_S_CC_1 = 0x186;
    TIMER020_S_CC_2 = 0x19f;
    TIMER020_S_CC_3 = 0;
    break;
  case 5:
    TIMER020_S_CC_1 = 0x1d6;
    TIMER020_S_CC_2 = 0;
    TIMER020_S_CC_4 = 0;
    if (DAT_23002a04 == (undefined4 *)0x19) {
      RADIO_S_SUBSCRIBE_TXEN = 0;
      RADIO_S_SUBSCRIBE_TXEN = 0;
      RADIO_S_SUBSCRIBE_START = 0;
    }
    if (DAT_23002794 < 3) {
      if (DAT_230029c0 == 1) {
        TIMER020_S_CC_0 = 0x1f7;
        DAT_230029c0 = 0;
      }
      else if (DAT_230029c0 == 2) {
        TIMER020_S_CC_0 = 0x1f1;
        DAT_230029c0 = 0;
      }
      else {
        DAT_230029c0 = 0;
      }
    }
    else {
      DAT_23002a0a = DAT_23002a0a + 1;
      DAT_23002a0c = DAT_23002a0c + 1;
      uVar19 = DAT_23002a10;
      if (DAT_23002a10 < 200) {
        uVar19 = DAT_23002a10 + 1;
      }
      uVar18 = (int)(uint)DAT_23002a0a >> 1 & 2;
      if (DAT_23002a10 < 200) {
        DAT_23002a10 = uVar19;
      }
      DAT_23002836 = (ushort)uVar18;
      if (DAT_230029d0 != '\0') {
        DAT_230029d0 = DAT_230029d0 + -1;
      }
      if (DAT_230029cc != 0) {
        DAT_230029cc = DAT_230029cc + -1;
      }
      (&DAT_230029d1)[uVar18] = (&DAT_230029d1)[uVar18] + '\x01';
      param_1 = (undefined4 *)FUN_2302218c();
      _DAT_23002790 = CONCAT22(DAT_23002792,(short)param_1);
      if ((DAT_230029f9 != '\0') && (uVar6 = DAT_23002a0a & 0x7ff, (DAT_23002a0a & 0x7ff) == 0)) {
        param_1 = (undefined4 *)(uint)DAT_230029e4;
        if ((DAT_23002a0a & 0x1800) == 0) {
          if (param_1 == (undefined4 *)0x0) {
            param_1 = (undefined4 *)FUN_2302223c();
            DAT_230029e4 = 1;
          }
        }
        else if (param_1 == (undefined4 *)0x1) {
          param_1 = (undefined4 *)FUN_23022f90(2,uVar6,uVar6);
          DAT_230029e4 = (byte)uVar6;
        }
      }
      uVar6 = DAT_230029ae;
      if (DAT_230029ae != 0) {
        DAT_230029ac = DAT_230029ae;
        DAT_230029ae = 0;
        FUN_230217a4(0,uVar6,1);
        FUN_23021744(0);
        param_1 = (undefined4 *)FUN_2302223c(0);
      }
      if (DAT_230029c0 == 1) {
        TIMER020_S_CC_0 = 0x1f7;
      }
      else if (DAT_230029c0 == 2) {
        TIMER020_S_CC_0 = 0x1f1;
      }
      DAT_230029c0 = 0;
      if (2 < DAT_23002794) {
        if (DAT_23002a0c < 100) {
          if (DAT_23002a10 < 200) {
            DAT_23002794 = 3;
          }
          else {
            DAT_23002794 = 4;
          }
        }
        else {
          FUN_23021b90(&DAT_23002a04,&RADIO_S_TASKS_DISABLE,0);
          RADIO_S_SUBSCRIBE_TXEN = 0;
          RADIO_S_SUBSCRIBE_TXEN = 0;
          RADIO_S_SUBSCRIBE_START = 0;
          RADIO_S_SUBSCRIBE_RXEN = 0;
          RADIO_S_SUBSCRIBE_DISABLE = 0;
          TIMER020_S_SUBSCRIBE_CAPTURE_7 = 0;
          TIMER020_S_CC_6 = 0;
          TIMER020_S_TASKS_STOP = 1;
          FUN_230217e0();
          DAT_23002794 = 0;
          DAT_23002978 = 0;
          FUN_23022c3c();
          FUN_23022f5c();
          param_1 = (undefined4 *)FUN_23025ed4(&stack0xffffffe8);
        }
      }
    }
  default:
    goto switchD_23025306_default;
  }
  if (DAT_23002a04 == (undefined4 *)0x19) {
    RADIO_S_SUBSCRIBE_TXEN = 0;
    RADIO_S_SUBSCRIBE_TXEN = 0;
    RADIO_S_SUBSCRIBE_START = 0;
  }
switchD_23025306_default:
  return param_1;
LAB_23024eee:
  if (2 < DAT_230029ac) {
LAB_23024f0e:
    DAT_23002a20 = 1;
    goto LAB_23024b80;
  }
LAB_23024efa:
  DAT_23002a20 = 1;
  DAT_23002a26 = 1;
  if (DAT_23002671 == '\0') goto LAB_23024b80;
LAB_23024b4c:
  DAT_23002a20 = 1;
  if (DAT_230029ac == 1) {
    if (DAT_2300283c == 4) goto LAB_23024fe2;
LAB_23024fca:
    if (DAT_23002670 == 0) {
      DAT_23002a20 = DAT_23002670;
    }
  }
  else if (DAT_230029ac == 2) {
    if (DAT_2300283c != 3) goto LAB_23024fca;
LAB_23024fe2:
    DAT_23002a20 = 1;
    DAT_23002670 = 1;
  }
LAB_23024b5a:
  puVar17 = (uint *)&DAT_23002a76;
  _DAT_23002672 = CONCAT13(DAT_23002675 | DAT_23002a19,_DAT_23002672);
  _DAT_23002a76 = _DAT_23002672;
  DAT_23002a7e._0_1_ = DAT_2300267a;
  DAT_23002a7a = DAT_23002676;
  uVar6 = 0xff;
  goto LAB_23024b80;
LAB_230250c8:
  uVar6 = (ushort)uVar18;
  DAT_23002a20 = 1;
  if (DAT_230029ac < 3) {
    if (uVar18 != 1) goto LAB_23024efa;
LAB_23025020:
    DAT_23002a20 = 1;
    bVar12 = *(byte *)((int)puVar17 + 3) | DAT_23002a19;
    *(byte *)((int)puVar17 + 3) = bVar12;
    DAT_23002671 = '\x01';
    DAT_23002687 = bVar12 | DAT_23002687;
    DAT_23002686 = DAT_23002686 + (char)puVar17[1];
    DAT_23002682 = (*(ushort *)((int)puVar17 + 5) << 8 | *(ushort *)((int)puVar17 + 5) >> 8) +
                   DAT_23002682;
    DAT_23002684 = DAT_23002684 +
                   (*(ushort *)((int)puVar17 + 7) << 8 | *(ushort *)((int)puVar17 + 7) >> 8);
    *(byte *)((int)puVar17 + 3) = DAT_23002687;
    *(char *)(puVar17 + 1) = DAT_23002686;
    *(char *)((int)puVar17 + 5) = (char)((ushort)DAT_23002682 >> 8);
    *(char *)((int)puVar17 + 6) = (char)DAT_23002682;
    *(char *)((int)puVar17 + 7) = (char)((ushort)DAT_23002684 >> 8);
    _DAT_23002672 = *puVar17;
    *(char *)(puVar17 + 2) = (char)DAT_23002684;
    DAT_23002676 = puVar17[1];
    DAT_2300267a = (undefined1)puVar17[2];
    FUN_2302145c(0,1);
    uVar6 = 1;
    if (DAT_23002671 != '\0') {
      if (DAT_230029ac == 1) {
        if (DAT_2300283c == 4) goto LAB_2302513e;
LAB_2302512a:
        if (DAT_23002670 == 0) {
          DAT_23002a20 = DAT_23002670;
        }
      }
      else if (DAT_230029ac == 2) {
        if (DAT_2300283c != 3) goto LAB_2302512a;
LAB_2302513e:
        DAT_23002670 = 1;
      }
      uVar6 = 0xff;
    }
  }
LAB_23024b80:
  DAT_23002a1a._0_2_ = uVar6;
  bVar12 = DAT_23002a20;
  uVar2 = (undefined1)DAT_23002836;
  (&DAT_230029d1)[DAT_23002836] = 0;
  uVar3 = DAT_23002a1e;
  DAT_23002a10 = 0;
  uVar4 = FUN_230221ec(uVar2);
  uVar2 = FUN_2302168c(bVar12,uVar3,uVar4);
  *(undefined1 *)((int)puVar17 + 1) = uVar2;
LAB_23024baa:
  uVar19 = *puVar17;
  DAT_23002658 = (undefined4 *)puVar17[2];
  DAT_23002654 = puVar17[1];
  DAT_2300265c = puVar17[3];
  RADIO_S_PACKETPTR = 0x23002650;
  DAT_23002650._0_1_ = (char)uVar19;
  uVar18 = uVar19 & 0xff;
  pcVar10 = (char *)&DAT_23002650;
  if (uVar18 == 0) {
    pcVar10 = (char *)((int)&DAT_23002650 + 1);
  }
  else {
    cVar11 = '\0';
    do {
      pcVar10 = pcVar10 + 1;
      cVar11 = cVar11 + *pcVar10;
    } while (pcVar10 != (char *)((int)&DAT_23002650 + uVar18));
    DAT_23002650._0_1_ = -cVar11;
    pcVar10 = (char *)((int)&DAT_23002650 + uVar18 + 1);
  }
  *pcVar10 = (char)DAT_23002650;
  DAT_23002650 = uVar19;
  DAT_23002650 = CONCAT31(DAT_23002650._1_3_,(char)DAT_23002650 + '\x01');
  TIMER020_S_TASKS_CAPTURE_7 = 1;
  if (DAT_2300283c == 0) {
    dVar15 = TIMER020_S_CC_7;
    if (99 < dVar15) goto LAB_23024d76;
  }
  else if (DAT_2300283c == 1) {
    dVar15 = TIMER020_S_CC_7;
    if (dVar15 < 0x65) goto LAB_23024d76;
  }
  else if (DAT_2300283c == 3) {
    dVar15 = TIMER020_S_CC_7;
    if (dVar15 < 0xfb) goto LAB_23024d76;
  }
  else if ((DAT_2300283c != 4) || (dVar15 = TIMER020_S_CC_7, dVar15 < 0x15f)) {
LAB_23024d76:
    if (DAT_23002a20 == 1) {
      RADIO_S_SUBSCRIBE_RXEN = DAT_230076f1 | 0x80000000;
      DAT_23002a04 = (undefined4 *)0x19;
      return &DAT_23002650;
    }
    RADIO_S_SUBSCRIBE_RXEN = 0;
    DAT_23002a04 = (undefined4 *)0x19;
    return &DAT_23002650;
  }
  RADIO_S_SUBSCRIBE_TXEN = 0;
  RADIO_S_SUBSCRIBE_TXEN = 0;
  RADIO_S_SUBSCRIBE_START = 0;
  DAT_23002a04 = (undefined4 *)0x18;
  return &DAT_23002650;
}


