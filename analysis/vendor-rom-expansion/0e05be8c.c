
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vendor_rom_e05be8c(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  uVar4 = DAT_2300300c;
  puVar5 = &DAT_23002d1c;
  if (5 < DAT_23002d23) {
    if (DAT_23002d23 != 0x80) {
      if (DAT_23002d23 != 0x83) {
        DAT_23002d1c = 5;
        return;
      }
      if (DAT_2300300c != 0) {
        iVar1 = DAT_2300300c - DAT_23003008 * (DAT_2300300c / DAT_23003008);
        if (iVar1 != 0) {
          uVar4 = (DAT_2300300c + DAT_23003008) - iVar1;
        }
        iVar1 = FUN_0e05fe20(DAT_2300301c,DAT_23003010,&DAT_23002e08,uVar4);
        if (iVar1 != 0) {
          DAT_23002d1c = 3;
          return;
        }
        DAT_2300300c = 0;
      }
      iVar1 = FUN_0e05fde8(DAT_2300301c,
                           (uint)ram0x23002d25 << 0x18 | ((ram0x23002d25 & 0xff00) >> 8) << 0x10 |
                           (uint)(ram0x23002d25 >> 0x10) << 8 | _DAT_23002d28 & 0xff,&DAT_23002d29,
                           _DAT_23002d24 & 0xff);
      if (iVar1 != 0) {
        DAT_23002d1c = 3;
        return;
      }
      DAT_23002d1c = 2;
      return;
    }
    _DAT_23002d28 = 0;
    _DAT_23002d24 = 0x103b07;
    DAT_23002d2c._0_1_ = 0xbf;
    DAT_23002d1c = 2;
    uVar2 = 1;
    goto LAB_0e06f4b8;
  }
  switch(DAT_23002d23) {
  case 1:
    uVar4 = FUN_0e05fd94(3,&DAT_2300301c);
    if (uVar4 == 0) {
      if (_DAT_23003014 <= *(uint *)(DAT_2300301c + 8)) {
        DAT_23003008 = FUN_0e05fe58();
        uVar2 = FUN_0e05fe68(DAT_2300301c);
        DAT_230071be = (undefined1)uVar2;
        DAT_2300300c = uVar4;
        DAT_23003010 = uVar4;
        FUN_0e06f3aa(&DAT_23002e08,uVar2,0x200);
        DAT_23002d1c = 2;
        _DAT_23003014 =
             _DAT_23002d28 << 0x18 | (_DAT_23002d28 >> 8 & 0xff) << 0x10 |
             (_DAT_23002d28 >> 0x10 & 0xff) << 8 | _DAT_23002d28 >> 0x18;
        _DAT_23002dfc = 0xffffffff;
        uVar2 = 0;
        _DAT_23003018 = 0;
        goto LAB_0e06f4b8;
      }
    }
    else {
      DAT_2300301c = 0;
    }
    DAT_23002d1c = 3;
    return;
  case 2:
    uVar3 = (uint)ram0x23002d25 << 0x18 | ((ram0x23002d25 & 0xff00) >> 8) << 0x10 |
            (uint)(ram0x23002d25 >> 0x10) << 8 | _DAT_23002d28 & 0xff;
    uVar7 = _DAT_23002d24 & 0xff;
    if (_DAT_23002dfc != uVar3) {
      puVar6 = &DAT_2300300c;
      _DAT_23003018 = uVar3 + uVar7;
      _DAT_23002dfc = uVar3;
      FUN_0e06f35c(&DAT_23002e08 + DAT_2300300c,&DAT_23002d29,uVar7);
      DAT_2300300c = uVar4 + uVar7;
      if (DAT_2300300c == 0x200) goto code_r0x0e05c02c;
    }
    break;
  default:
    DAT_23002d1c = 5;
    return;
  case 4:
    func_0x0e05fde4(DAT_2300301c);
    uVar2 = 2;
    DAT_23002d1c = 2;
    DAT_23003010 = 0;
    DAT_2300301c = 0;
    DAT_2300300c = 0;
    goto LAB_0e06f4b8;
  case 5:
    puVar6 = (undefined4 *)&DAT_23003014;
    if (_DAT_23003018 == _DAT_23003014) {
      iRam23002e00 = func_0x0e068a38(0x100000);
      uRam23002e04 = _DAT_23003014;
    }
    puVar5 = (undefined1 *)0x23002e00;
    func_0x0e05fde4(DAT_2300301c);
    DAT_2300301c = 0;
    DAT_2300300c = 0;
    DAT_23003010 = 0;
    if (((iRam23002e00 != 0) && (uRam23002e04 != 0)) && (_DAT_23003018 == _DAT_23003014)) {
      func_0x0e0689c0(0x23002e00,1);
    }
    FUN_0e05d698(0);
code_r0x0e05c02c:
    iVar1 = FUN_0e05fe20(DAT_2300301c,DAT_23003010,&DAT_23002e08);
    if (iVar1 != 0) {
      func_0x0e05fde4(DAT_2300301c);
      DAT_2300301c = 0;
      *puVar5 = 3;
      *puVar6 = 0;
      DAT_23003010 = 0;
      return;
    }
    *puVar6 = 0;
    DAT_23003010 = DAT_23003010 + 0x200;
    FUN_0e06f3aa(&DAT_23002e08,DAT_230071be,0x200);
  }
  *puVar5 = 2;
  uVar2 = 0;
LAB_0e06f4b8:
  ram_candidate_230203cc(uVar2);
  return;
}


