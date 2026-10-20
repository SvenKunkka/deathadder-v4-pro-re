/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23022508. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23022508(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  short sVar6;
  uint uVar7;
  
  uVar2 = DAT_23002a98;
  cVar1 = DAT_23002a96;
  if (DAT_23002798 == 4) {
    if ('\0' < DAT_23002a96) {
      iVar3 = FUN_230216a8(DAT_23002a98);
      uVar4 = FUN_230216a0(uVar2);
      if (iVar3 == 0) {
        if (DAT_23002a99 == '(') {
          DAT_230026be = _DAT_23002a9a;
        }
        else if (DAT_23002a99 == ')') {
          DAT_23002972 = DAT_23002a9b << 8 | DAT_23002a9b >> 8;
          DAT_230027c5 = 1;
          DAT_230026c2 = DAT_23002a9a;
        }
        if (DAT_230029e0 != '\0') {
          uVar5 = (ushort)DAT_230029e5;
          goto LAB_23025f1c;
        }
      }
      else if (*(byte *)((int)&DAT_23002a3a + iVar3) != uVar4) {
        *(char *)((int)&DAT_23002a3a + iVar3) = (char)uVar4;
        FUN_23025e04(0,iVar3,&DAT_23002a99,(short)(char)(cVar1 + -2),DAT_230029e5);
        DAT_23002a10 = 0;
        DAT_230029d0 = 2;
        return;
      }
    }
    return;
  }
  if (DAT_23002798 != 1) {
    if (DAT_23002798 != 2) {
      return;
    }
    if ('\0' < DAT_23002a96) {
      iVar3 = FUN_230216a8(DAT_23002a98);
      uVar4 = FUN_230216a0(uVar2);
      if (iVar3 == 0) {
        if (DAT_230029e0 != '\0') {
          uVar5 = (ushort)DAT_230029e5;
LAB_23025f1c:
          uVar7 = (uint)(ushort)(DAT_23006b8a + 1);
          uVar4 = uVar7;
          if (30000 < uVar7) {
            uVar4 = 0;
          }
          sVar6 = uVar5 + _DAT_23006b88;
          _DAT_23006b88 = uVar4;
          if (uVar7 < 0x7531) {
            _DAT_23006b88 = CONCAT22((short)uVar4,sVar6);
          }
          return;
        }
      }
      else if (*(byte *)((int)&DAT_23002a3a + iVar3) != uVar4) {
        *(char *)((int)&DAT_23002a3a + iVar3) = (char)uVar4;
        FUN_23025e04(0,iVar3,&DAT_23002a99,(short)(char)(cVar1 + -2),0);
        DAT_23002a10 = 0;
        DAT_230029d0 = 2;
        return;
      }
    }
    return;
  }
  if ('\0' < DAT_23002a96) {
    iVar3 = FUN_230216a8(DAT_23002a98);
    uVar4 = FUN_230216a0(uVar2);
    if (iVar3 == 0) {
      if (DAT_230029e0 != '\0') {
        uVar5 = (ushort)DAT_230029e5;
        goto LAB_23025f1c;
      }
    }
    else if (*(byte *)((int)&DAT_23002a3a + iVar3) != uVar4) {
      *(char *)((int)&DAT_23002a3a + iVar3) = (char)uVar4;
      FUN_23025e04(0,iVar3,&DAT_23002a99,(short)(char)(cVar1 + -2),0);
      DAT_23002a10 = 0;
      DAT_230029d0 = 2;
      return;
    }
  }
  return;
}


