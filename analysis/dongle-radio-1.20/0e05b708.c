/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05b708. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e05b708(void)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_lr;
  
  FUN_0e05a098(0,0xa001,&DAT_23002db0,0x46);
  if ((DAT_23002db0 != 0x46) ||
     (uVar3 = (uint)DAT_23002df4, uVar4 = FUN_0e05479c(&DAT_23002db0,0x44,0), uVar3 != uVar4)) {
    thunk_FUN_0e06f35c(&DAT_23002db0,&DAT_0e06fa28,0x46);
  }
  FUN_0e05a098(1,0xa002,&DAT_23002d80,0x2f);
  if ((DAT_23002d80 & 0xffff) == 0x2f) {
    uVar3 = (uint)ram0x23002dad;
    uVar4 = FUN_0e05479c(&DAT_23002d80,0x2d,0);
    if (uVar3 == uVar4) goto LAB_0e05b79e;
  }
  DAT_23002d80 = 0xffff002f;
  DAT_23002d84 = 0x102ffff;
  DAT_23002d88 = 0xff000101;
  DAT_23002d8c = 0xffffff;
  DAT_23002d90 = 0x3010200;
  _DAT_23002dac = 0x46;
  DAT_23002da8 = CONCAT22(0x3c32,(short)DAT_23002da8);
LAB_0e05b79e:
  if (0xfffffffd < DAT_23002dcf - 1) {
    DAT_23002dcf = CONCAT13((char)_DAT_0fffe010,
                            CONCAT12((char)(_DAT_0fffe010 >> 8),
                                     CONCAT11((char)(_DAT_0fffe010 >> 0x10),
                                              (char)(_DAT_0fffe010 >> 0x18))));
    DAT_230071ba = DAT_230071ba | 2;
    DAT_2300719e = 0;
  }
  if (0xfffffffd < CONCAT31((undefined3)DAT_23002d8c,DAT_23002d88._3_1_) - 1U) {
    DAT_23002d88._3_1_ = (undefined1)DAT_23002dcf;
    DAT_23002d8c._0_3_ = (undefined3)(DAT_23002dcf >> 8);
    DAT_2300719e = 0;
    DAT_230071ba = DAT_230071ba | 1;
  }
  uVar4 = 0xfffe000;
  if (((_DAT_0fffe014 == 0xc000) && (uVar4 = _DAT_0fffe010, _DAT_0fffe010 == 0x80000000)) &&
     (uVar4 = DAT_23002dcf, DAT_23002dcf == 0x80)) {
    thunk_FUN_0e0621b8(&DAT_23002dcf,4);
    DAT_2300719e = 0;
    uVar4 = DAT_230071ba | 2;
    DAT_230071ba = (byte)uVar4;
  }
  uVar3 = (uint)DAT_230071ba;
  if ((uVar3 != 0) && (DAT_2300719e == 0)) {
    if ((int)(uVar3 << 0x1e) < 0) {
      DAT_23002db0 = 0x46;
      DAT_23002df4 = FUN_0e05479c(&DAT_23002db0,0x44,0,uVar3,uVar4,unaff_r4,unaff_r5,unaff_r6,
                                  unaff_r7,unaff_lr);
      iVar2 = FUN_0e05a0c0(0,0xa001,&DAT_23002db0,0x46);
      uVar3 = (uint)DAT_230071ba;
      if (iVar2 != 0) {
        uVar3 = uVar3 & 0xfd;
        DAT_230071ba = (byte)uVar3;
      }
    }
    if ((int)(uVar3 << 0x1f) < 0) {
      DAT_23002d80 = CONCAT22(DAT_23002d80._2_2_,0x2f);
      uVar1 = FUN_0e05479c(&DAT_23002d80,0x2d,0,uVar3 << 0x1f,uVar4,unaff_r4,unaff_r5,unaff_r6,
                           unaff_r7,unaff_lr);
      _DAT_23002dac = CONCAT21(uVar1,(undefined1)DAT_23002dac);
      iVar2 = FUN_0e05a0c0(1,0xa002,&DAT_23002d80,0x2f);
      if (iVar2 != 0) {
        DAT_230071ba = DAT_230071ba & 0xfe;
        return;
      }
    }
  }
  return;
}


