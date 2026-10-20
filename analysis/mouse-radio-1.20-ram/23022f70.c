/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23022f70. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23022f70(void)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  undefined1 local_28;
  byte local_27;
  ushort local_26;
  ushort local_24;
  
  bVar3 = DAT_230076f6;
  uVar5 = (uint)DAT_230076f6;
  if (DAT_230076f7 == '\0') {
    if ((((DAT_230029fc == '\0') && (DAT_230029fd == '\0')) && (DAT_230029f9 != '\0')) &&
       (DAT_230029fa < 5)) {
      DAT_230029fa = 5;
      DAT_23002a00 = 0x18;
    }
    sVar2 = DAT_23002934;
    if (DAT_23002934 != 0) {
      _DAT_23002932 = CONCAT22(DAT_23002934 + -1,DAT_23002932);
      if (sVar2 != 1) {
        return;
      }
    }
    if ((&DAT_2300294d)[uVar5] == '\x01') {
      return;
    }
    if (DAT_23002936 == 0) {
      return;
    }
    uVar4 = (&DAT_23002794)[uVar5 + 0x60];
    DAT_23002936 = 0;
    local_26 = uVar4 << 8 | uVar4 >> 8;
    if (0x1f < uVar4) {
      uVar1 = (&DAT_23002796)[uVar5 + 0x84];
      local_24 = uVar1 << 8 | uVar1 >> 8;
      if (uVar4 >> 3 < uVar1) {
        local_27 = DAT_230076f6 & 0x3f;
        local_28 = 0x2b;
        FUN_230215ac(0,0,&local_28,6,0xff);
        (&DAT_2300294d)[uVar5] = 1;
        _DAT_23002932 = 0;
        thunk_FUN_0e0973ea(&DAT_23002854,0,0x4a);
        thunk_FUN_0e0973ea(&DAT_2300289e,0,0x4a);
        thunk_FUN_0e0973ea(&DAT_230028e8,0,0x4a);
      }
    }
    uVar4 = (&DAT_23002798)[uVar5 + 0xa8];
    local_24 = uVar4 << 8 | uVar4 >> 8;
    if (4 < uVar4) {
      local_26 = (&DAT_23002794)[uVar5 + 0x60] << 8 | (ushort)(&DAT_23002794)[uVar5 + 0x60] >> 8;
      local_27 = bVar3 & 0x3f | 0x40;
      local_28 = 0x2b;
      FUN_230215ac(0,0,&local_28,6,0xff);
      (&DAT_2300294d)[uVar5] = 1;
      _DAT_23002932 = 0;
      thunk_FUN_0e0973ea(&DAT_23002854,0,0x4a);
      thunk_FUN_0e0973ea(&DAT_2300289e,0,0x4a);
      thunk_FUN_0e0973ea(&DAT_230028e8,0,0x4a);
      return;
    }
    return;
  }
  if (DAT_230076f7 != '\x01') {
    if (DAT_230076f7 != '\x02') {
      return;
    }
    if (DAT_230029ea < 0x10) {
      DAT_230029e1 = 0;
      return;
    }
    DAT_230029e8 = DAT_230029e8 - ((ushort)DAT_230029e2 + (ushort)DAT_230029e3);
    DAT_230029e1 = (char)(DAT_230029e8 / (ushort)(DAT_230029ea - 2));
    DAT_230029ea = DAT_230029ea - 2;
    return;
  }
  if (DAT_230029e5 == 0xff) goto LAB_23022050;
  if (DAT_230029e2 == 0) {
    DAT_230029e2 = DAT_230029e5;
    if (DAT_230029e3 == 0) {
LAB_23022020:
      DAT_230029e3 = DAT_230029e5;
      if (DAT_230029e5 < DAT_230029e2) goto LAB_230220a0;
    }
    else {
LAB_230220c2:
      if (DAT_230029e3 < DAT_230029e5) {
        DAT_230029e3 = DAT_230029e5;
      }
    }
  }
  else {
    if (DAT_230029e3 == 0) goto LAB_23022020;
    if (DAT_230029e2 <= DAT_230029e5) goto LAB_230220c2;
LAB_230220a0:
    DAT_230029e2 = DAT_230029e5;
  }
  DAT_230029ea = DAT_230029ea + 1;
  DAT_230029e8 = DAT_230029e5 + DAT_230029e8;
LAB_23022050:
  if (DAT_230029fc != '\0') {
    return;
  }
  if (DAT_230029fd != '\0') {
    return;
  }
  uVar4 = DAT_230029fa;
  if (DAT_230029f9 != '\0') {
    if (DAT_230029fa == 0) {
      return;
    }
    uVar4 = DAT_230029fa - 1;
    if (DAT_230029e1 - 1 < 0x46) {
      if ((ushort)(DAT_230029fa - 1) < 2) {
        DAT_230029fa = uVar4;
        DAT_23002a00 = 0xb;
        return;
      }
      if ((ushort)(DAT_230029fa - 1) < 4) {
        DAT_230029fa = uVar4;
        DAT_23002a00 = 0xe;
        return;
      }
    }
    else if ((DAT_230029e1 == 0) && (DAT_230029fa == 1)) {
      DAT_230029fa = uVar4;
      DAT_23002a00 = 0xb;
      return;
    }
  }
  DAT_230029fa = uVar4;
  DAT_23002a00 = 0x18;
  return;
}


