/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23024078. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23024078(void)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  byte bVar3;
  short sVar4;
  uint uVar5;
  short sVar6;
  uint uVar7;
  
  if (DAT_230029ac == 1) {
    if (DAT_23002670 == '\0') {
      if (DAT_2300283c == 0) {
        if ((int)((uint)DAT_23002a0a << 0x1f) < 0) {
          sVar6 = 2;
          do {
            puVar2 = (undefined4 *)FUN_230214e0(0,sVar6);
            sVar4 = sVar6 + 1;
            if (puVar2 != (undefined4 *)0x0) goto LAB_2302435c;
            sVar6 = sVar4;
          } while (sVar4 != 6);
        }
        uVar5 = 0;
        do {
          uVar7 = uVar5 & 0xffff;
          puVar2 = (undefined4 *)FUN_230214e0(0,uVar7);
          uVar5 = uVar5 + 1;
          if (puVar2 != (undefined4 *)0x0) goto LAB_23024382;
        } while (uVar5 != 6);
LAB_2302419e:
        if (DAT_23002671 != '\0') {
          if (DAT_2300283c == 3) {
            DAT_23002670 = '\x01';
            goto LAB_230241e4;
          }
LAB_230241b8:
          if (DAT_23002670 != '\0') goto LAB_230241e4;
        }
      }
      else {
        if (DAT_2300283c != 1) {
          if (DAT_2300283c == 2) {
            if (DAT_23002a26 == '\x01') {
              return;
            }
            if (DAT_23002671 != '\0') {
              puVar2 = (undefined4 *)FUN_230214e0(0,1);
              if (puVar2 == (undefined4 *)0x0) {
                return;
              }
              goto LAB_23024264;
            }
            uVar5 = 0;
            do {
              uVar7 = uVar5 & 0xffff;
              puVar2 = (undefined4 *)FUN_230214e0(0,uVar7);
              uVar5 = uVar5 + 1;
              if (puVar2 != (undefined4 *)0x0) goto LAB_23024382;
            } while (uVar5 != 6);
            goto LAB_2302419e;
          }
          if (DAT_2300283c != 3) goto LAB_230240a8;
          if (DAT_23002a26 == '\x01') {
            return;
          }
          puVar2 = (undefined4 *)FUN_230214e0(0,1);
          if (puVar2 != (undefined4 *)0x0) goto LAB_23024264;
          if (DAT_23002671 == '\0') goto LAB_230240a8;
          if (DAT_2300283c == 3) goto LAB_2302434e;
          goto LAB_230241b8;
        }
        if (DAT_23002a26 == '\x01') {
          return;
        }
        puVar2 = (undefined4 *)FUN_230214e0();
        if (puVar2 != (undefined4 *)0x0) {
LAB_23024264:
          DAT_23002a20 = 1;
          DAT_23002671 = '\x01';
          bVar3 = *(byte *)((int)puVar2 + 3) | DAT_23002a19;
          *(byte *)((int)puVar2 + 3) = bVar3;
          DAT_23002687 = bVar3 | DAT_23002687;
          DAT_23002686 = DAT_23002686 + *(char *)(puVar2 + 1);
          DAT_23002682 = (*(ushort *)((int)puVar2 + 5) << 8 | *(ushort *)((int)puVar2 + 5) >> 8) +
                         DAT_23002682;
          DAT_23002684 = DAT_23002684 +
                         (*(ushort *)((int)puVar2 + 7) << 8 | *(ushort *)((int)puVar2 + 7) >> 8);
          *(byte *)((int)puVar2 + 3) = DAT_23002687;
          *(char *)(puVar2 + 1) = DAT_23002686;
          *(char *)((int)puVar2 + 5) = (char)((ushort)DAT_23002682 >> 8);
          *(char *)((int)puVar2 + 6) = (char)DAT_23002682;
          *(char *)((int)puVar2 + 7) = (char)((ushort)DAT_23002684 >> 8);
          DAT_23002676 = puVar2[1];
          *(char *)(puVar2 + 2) = (char)DAT_23002684;
          _DAT_23002672 = *puVar2;
          DAT_2300267a = *(undefined1 *)(puVar2 + 2);
          if (DAT_2300283c != 3) {
            DAT_23002a20 = 0;
          }
          FUN_2302145c(0,1);
          if (DAT_23002671 != '\0') {
            if (DAT_2300283c == 3) {
              DAT_23002670 = '\x01';
            }
            goto LAB_2302437e;
          }
          sVar6 = 1;
          goto LAB_23024212;
        }
        if (DAT_23002671 != '\0') {
          return;
        }
      }
    }
    else if (DAT_23002671 != '\0') {
      if (DAT_2300283c == 3) {
LAB_2302434e:
        DAT_23002670 = '\x01';
      }
      goto LAB_230241e4;
    }
  }
  else {
    uVar5 = 0;
    DAT_23002a20 = 1;
    do {
      sVar6 = (short)uVar5;
      puVar2 = (undefined4 *)FUN_230214e0(0,uVar5 & 0xffff);
      uVar5 = uVar5 + 1;
      if (puVar2 != (undefined4 *)0x0) goto LAB_23024212;
    } while (uVar5 != 6);
  }
LAB_230240a8:
  (&DAT_230029d1)[DAT_23002836] = 0;
  DAT_23002a1a._0_2_ = 0xff;
  _DAT_23002a76 = CONCAT31(_DAT_23002a77,5);
  DAT_23002a20 = 1;
  uVar1 = FUN_2302168c(1,0,0);
  _DAT_23002a76 = CONCAT11(uVar1,DAT_23002a76);
  uVar1 = FUN_23021698(0,DAT_23002a2a);
  DAT_23002a2a = DAT_23002a2a + '\x01';
  if (DAT_23002a2a == '\b') {
    DAT_23002a2a = '\x01';
  }
  DAT_23002a7a = CONCAT22(DAT_23002a7a._2_2_,
                          (ushort)((DAT_23002a10 & 0xff) << 8) | (ushort)DAT_23002a10 >> 8);
  _DAT_23002a76 = CONCAT13(0x17,CONCAT12(uVar1,_DAT_23002a76));
  uVar1 = FUN_2302168c(1,DAT_23002a1e,*(undefined1 *)((int)&DAT_23002a14 + (uint)DAT_23002836 * 2));
  puVar2 = (undefined4 *)&DAT_23002a76;
  _DAT_23002a76 = CONCAT11(uVar1,DAT_23002a76);
  goto LAB_23024126;
LAB_23024382:
  sVar6 = (short)uVar7;
  if (uVar7 == 1) goto LAB_23024264;
LAB_2302435c:
  DAT_23002a20 = 1;
  DAT_23002a26 = '\x01';
  if (DAT_23002671 != '\0') {
    if (DAT_2300283c == 3) {
      DAT_23002670 = '\x01';
    }
    else if (DAT_23002670 == '\0') {
LAB_2302437e:
      sVar6 = 0xff;
      goto LAB_23024212;
    }
LAB_230241e4:
    DAT_23002a20 = 1;
    sVar6 = 0xff;
    _DAT_23002672 = CONCAT13(DAT_23002675 | DAT_23002a19,_DAT_23002672);
    _DAT_23002a76 = _DAT_23002672;
    puVar2 = (undefined4 *)&DAT_23002a76;
    DAT_23002a7a = DAT_23002676;
    DAT_23002a7e._0_1_ = DAT_2300267a;
  }
LAB_23024212:
  uVar1 = DAT_23002a20;
  uVar5 = (uint)DAT_23002836;
  DAT_23002a10 = 0;
  (&DAT_230029d1)[uVar5] = 0;
  DAT_23002a1a._0_2_ = sVar6;
  uVar1 = FUN_2302168c(uVar1,DAT_23002a1e,*(undefined1 *)((int)&DAT_23002a14 + uVar5 * 2));
  *(undefined1 *)((int)puVar2 + 1) = uVar1;
LAB_23024126:
  RADIO_S_PACKETPTR = (dword)puVar2;
  DAT_2300265c = puVar2[3];
  DAT_23002658 = puVar2[2];
  DAT_23002654 = puVar2[1];
  DAT_23002650 = *puVar2;
  return;
}


