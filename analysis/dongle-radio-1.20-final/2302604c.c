/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302604c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_2302604c(uint param_1)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  uint3 uVar4;
  byte bVar5;
  byte bVar6;
  undefined4 uVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  
  cVar8 = DAT_230071bd;
  cVar1 = DAT_23002d24;
  bVar3 = DAT_23002d25;
  uVar2 = _DAT_23002d24;
  bVar5 = DAT_23002d26;
  bVar6 = DAT_23002d27;
  if (DAT_23002d22 < 0x11) {
    uVar4 = _DAT_23002d25;
    switch(DAT_23002d22) {
    case 0:
      goto LAB_2302617c;
    default:
      return param_1;
    case 7:
      if (DAT_23002d23 == 0x95) {
        DAT_23002d1c = 2;
        _DAT_23002d24 = CONCAT12(DAT_23002cb6,_DAT_23002cb4);
        _DAT_23002d24 = CONCAT13(bVar6,_DAT_23002d24);
        return param_1;
      }
      if (DAT_23002d23 < 0x96) {
        if (DAT_23002d23 == 0x15) {
          uVar10 = _DAT_23002d24 & 0xff;
          if (((uVar10 < 5) && (bVar3 < 5)) && (bVar5 < 5)) {
            _DAT_23002cb4 = uVar2;
            DAT_23002cb6 = bVar5;
            if (((DAT_23002d90._1_1_ != uVar10) || (DAT_23002d90._2_1_ != bVar3)) ||
               (DAT_23002d90._3_1_ != bVar5)) {
              DAT_23002d90._1_2_ = uVar2;
              DAT_23002d90._3_1_ = bVar5;
              FUN_23026f30(2);
            }
            uVar10 = FUN_23025a44();
            DAT_23002d1c = 2;
            return uVar10;
          }
          DAT_23002d1c = 3;
          return uVar10;
        }
        if (DAT_23002d23 == 0x17) {
          if (((DAT_23002da8._2_1_ != cVar1) || (DAT_23002da8._2_2_ >> 8 != uVar2 >> 8)) ||
             (uVar10 = (uint)(byte)DAT_23002dac, uVar10 != bVar5)) {
            DAT_23002da8._2_2_ = uVar2;
            DAT_23002dac._0_1_ = bVar5;
            uVar10 = FUN_23026f30(2);
          }
          DAT_23002d1c = 2;
          return uVar10;
        }
      }
      else {
        if (DAT_23002d23 == 0x96) {
          DAT_23002d1c = 2;
          _DAT_23002d24 = CONCAT31(uVar4,DAT_230071b3);
          return param_1;
        }
        if (DAT_23002d23 == 0x97) {
          DAT_23002d1c = 2;
          _DAT_23002d24 = CONCAT12((byte)DAT_23002dac,DAT_23002da8._2_2_);
          _DAT_23002d24 = CONCAT13(bVar6,_DAT_23002d24);
        }
      }
      return param_1;
    case 0xf:
      DAT_23002d1c = 2;
      return param_1;
    case 0x10:
      uVar10 = (*(code *)0xe05be8d)();
      return uVar10;
    }
  }
  if (DAT_23002d22 != 0xfe) {
    return param_1;
  }
  if ((char)DAT_23002d23 < '\0') {
    if (0xf0 < DAT_23002d23) {
      switch(DAT_23002d23) {
      case 0xf1:
        FUN_23020530(&DAT_23002d24);
        DAT_23002d1c = 2;
        uVar10 = ram_candidate_230266b0();
        return uVar10;
      case 0xf3:
        if (DAT_23002d1d >> 5 == 7) {
          _DAT_23002d24 = DAT_23002d94;
          DAT_23002d30 = DAT_23002da0;
          _DAT_23002d28 = DAT_23002d98;
          DAT_23002d2c = DAT_23002d9c;
          DAT_23002d34 = DAT_23002da4;
          DAT_23002d38 = (undefined2)DAT_23002da8;
          goto LAB_2302680e;
        }
        break;
      case 0xfa:
        DAT_23002d1c = 2;
        _DAT_23002d24 = _DAT_0fffe014;
        _DAT_23002d28 = _DAT_0fffe010;
        uVar10 = ram_candidate_230266b0();
        return uVar10;
      case 0xfb:
        FUN_23020a34(&DAT_23002d24);
        DAT_23002d1c = 2;
        uVar10 = ram_candidate_230266b0();
        return uVar10;
      case 0xff:
        FUN_230204b8(&DAT_23002d24);
        DAT_23002d1c = 2;
        uVar10 = ram_candidate_230266b0();
        return uVar10;
      }
    }
    return 1;
  }
  if (0x6f < DAT_23002d23) {
    switch(DAT_23002d23) {
    case 0x70:
      FUN_2302048c(&DAT_23002d24);
      DAT_23002d1c = 2;
      uVar10 = ram_candidate_230266b0();
      return uVar10;
    case 0x71:
      FUN_23020510(&DAT_23002d24);
      DAT_23002d1c = 2;
      uVar10 = ram_candidate_230266b0();
      return uVar10;
    case 0x72:
      thunk_FUN_23024db4((_DAT_23002d24 & 0xff) << 8 | (uint)(_DAT_23002d24 >> 8));
      DAT_23002d1c = 2;
      uVar10 = ram_candidate_230266b0();
      return uVar10;
    case 0x73:
      goto ram_candidate_230267e2;
    default:
      return 1;
    case 0x7f:
      thunk_FUN_23020fec(&DAT_23002d24);
      DAT_23002d1c = 2;
      uVar10 = ram_candidate_230266b0();
      return uVar10;
    }
  }
  if (DAT_23002d23 != 0x33) {
    return 1;
  }
  if (DAT_23002d1d >> 5 != 7) {
    return 1;
  }
  if (DAT_230071bd != '\x02') {
    DAT_23002d1c = 3;
    uVar10 = ram_candidate_230266b0();
    return uVar10;
  }
  DAT_230071b2 = '\x01';
  if ((_DAT_23002d24 & 0xff) != 0) {
    FUN_23025fe0();
    DAT_23002d1c = cVar8;
    uVar10 = ram_candidate_230266b0();
    return uVar10;
  }
  if (bVar3 == 0xff) {
    if (DAT_23002d26 == 0) {
      if (DAT_23002d27 == 0) {
        FUN_23025954(2);
        goto LAB_2302680e;
      }
    }
    else if ((DAT_23002d26 & DAT_23002d27) == 0xff) {
      FUN_23025954(1);
      goto LAB_2302680e;
    }
  }
  else if (bVar3 == 0) {
    if (DAT_23002d26 == 0xff) {
      if (DAT_23002d27 == 0) {
        FUN_23025954(3);
        goto LAB_2302680e;
      }
    }
    else if ((DAT_23002d26 == 0) && (DAT_23002d27 == 0xff)) {
      FUN_23025954(4);
      goto LAB_2302680e;
    }
  }
  FUN_23025954(0);
LAB_2302680e:
  DAT_23002d1c = 2;
  uVar10 = ram_candidate_230266b0();
  return uVar10;
ram_candidate_230267e2:
  if (DAT_23002d1d >> 5 != 7) {
    return 1;
  }
  DAT_23002d94 = _DAT_23002d24;
  DAT_23002da0 = DAT_23002d30;
  DAT_23002d98 = _DAT_23002d28;
  DAT_23002d9c = DAT_23002d2c;
  DAT_23002da4 = DAT_23002d34;
  DAT_23002da8._0_2_ = DAT_23002d38;
  FUN_23026f30(2);
  goto LAB_2302680e;
LAB_2302617c:
  if (0xc6 < DAT_23002d23) {
    return 1;
  }
  if (DAT_23002d23 < 0x8d) {
    if (DAT_23002d23 < 0x16) {
      if (DAT_23002d23 < 4) {
        return 1;
      }
      switch(DAT_23002d23) {
      case 4:
        if (DAT_23002d1d >> 5 != 7) {
          return 1;
        }
        DAT_230071bd = cVar1;
        if ((((_DAT_23002d24 & 0xff) == 0) || ((_DAT_23002d24 & 0xff) == 3)) &&
           (DAT_230071b2 != '\0')) {
          iVar9 = FUN_230204ac();
          if (iVar9 == 0) {
            FUN_23025954();
          }
          else {
            FUN_23025a44();
          }
          DAT_230071b2 = '\0';
        }
        break;
      default:
        goto code_r0x23026216;
      case 0xb:
        uVar10 = _DAT_23002d24 & 0xff;
        if (uVar10 == 1) {
          FUN_23026f68();
          thunk_FUN_23025300(ram0x23002d8b << 0x18 | (ram0x23002d8b >> 8 & 0xff) << 0x10 |
                             (ram0x23002d8b >> 0x10 & 0xff) << 8 | ram0x23002d8b >> 0x18);
          uVar10 = ram_candidate_23026216();
          return uVar10;
        }
        if (uVar10 != 3) {
          if (uVar10 != 5) {
            return 1;
          }
          FUN_23020608(0x2ee);
          DAT_23002d1c = 2;
          uVar10 = ram_candidate_23026216();
          return uVar10;
        }
        DAT_23002d80._2_2_ = 0xffff;
        FUN_23026f30(2);
        FUN_23020608(0x2ee);
        DAT_23002d1c = 2;
        uVar10 = ram_candidate_23026216();
        return uVar10;
      case 0xd:
        DAT_23002db5 = _DAT_23002d24;
        FUN_23026f30(4);
        DAT_23002d1c = 2;
        uVar10 = ram_candidate_23026216();
        return uVar10;
      case 0x12:
        DAT_23002db9 = _DAT_23002d24;
        DAT_23002dbd = _DAT_23002d28;
        DAT_23002dc1 = DAT_23002d2c;
        DAT_23002dc5 = DAT_23002d30;
        DAT_23002dc9 = DAT_23002d34;
        FUN_23026f30(4);
        DAT_23002d1c = 2;
        uVar10 = ram_candidate_23026216();
        return uVar10;
      case 0x15:
        if (((((DAT_23002dcf & 0xff) != (_DAT_23002d24 & 0xff)) ||
             ((DAT_23002dcf >> 8 & 0xff) != (_DAT_23002d24 & 0xffff) >> 8)) ||
            ((DAT_23002dcf >> 0x10 & 0xff) != (_DAT_23002d24 & 0xffffff) >> 0x10)) ||
           (DAT_23002dcf >> 0x18 != _DAT_23002d24 >> 0x18)) {
          DAT_23002dcf = _DAT_23002d24;
          ram0x23002d8b = _DAT_23002d24;
          if (0xfffffffc < _DAT_23002d24 - 1 && _DAT_23002d24 != 0xfffffffe) {
            register0x0000002c =
                 _DAT_0fffe010 >> 0x18 | ((_DAT_0fffe010 & 0xffffff) >> 0x10) << 8 |
                 ((_DAT_0fffe010 & 0xffff) >> 8) << 0x10 | _DAT_0fffe010 << 0x18;
            DAT_23002dcf = CONCAT13((char)_DAT_0fffe010,
                                    CONCAT12((char)(_DAT_0fffe010 >> 8),
                                             CONCAT11((char)(_DAT_0fffe010 >> 0x10),
                                                      (char)(_DAT_0fffe010 >> 0x18))));
          }
          FUN_23026f30(4);
          FUN_23026f30(2);
          thunk_FUN_230252a4(DAT_23002dcf << 0x18 | (DAT_23002dcf >> 8 & 0xff) << 0x10 |
                             (DAT_23002dcf >> 0x10 & 0xff) << 8 | DAT_23002dcf >> 0x18);
        }
      }
    }
    else {
      if (DAT_23002d23 == 0x45) {
        if ((_DAT_23002d24 & 0xff) == 1) {
          DAT_23002dd3 = cVar1;
          DAT_23002d80._2_2_ = _DAT_23002d25;
          DAT_23002d1c = 2;
          FUN_23026f30(4);
          FUN_23026f30(2);
          uVar10 = ram_candidate_23026216();
          return uVar10;
        }
        if ((_DAT_23002d24 & 0xff) != 2) {
          return 1;
        }
        DAT_23002dd3 = cVar1;
        DAT_23002d84._0_2_ = _DAT_23002d25;
        DAT_23002d1c = cVar1;
        FUN_23026f30(4);
        FUN_23026f30(2);
        uVar10 = ram_candidate_23026216();
        return uVar10;
      }
      if (DAT_23002d23 != 0x46) {
        if (DAT_23002d23 != 0x3c) {
          return 1;
        }
        DAT_23002db3 = uVar2;
        FUN_23026f30(4);
        DAT_23002d1c = 2;
        uVar10 = ram_candidate_23026216();
        return uVar10;
      }
    }
    goto switchD_23026190_caseD_c6;
  }
  switch(DAT_23002d23) {
  case 0x8d:
    DAT_23002d1c = 2;
    _DAT_23002d24 = DAT_23002db5;
    uVar10 = ram_candidate_23026216();
    return uVar10;
  default:
    goto code_r0x23026216;
  case 0x91:
    DAT_23002d1c = 2;
    _DAT_23002d24 = CONCAT22(_DAT_23002d26,0x1401);
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0x92:
    _DAT_23002d24 = DAT_23002db9;
    DAT_23002d2c = DAT_23002dc1;
    _DAT_23002d28 = DAT_23002dbd;
    DAT_23002d30 = DAT_23002dc5;
    DAT_23002d34 = DAT_23002dc9;
    break;
  case 0x93:
    DAT_23002d1c = 2;
    _DAT_23002d24 = 0x1401;
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0x95:
    _DAT_23002d24 = DAT_23002dcf;
    _DAT_23002d28 = ram0x23002d8b;
    DAT_23002d1c = 2;
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0x9f:
    _DAT_23002d24 = CONCAT12(DAT_0000f008,CONCAT11(DAT_0000f004,DAT_0000f000));
    _DAT_23002d24 = CONCAT13(DAT_0000f00c,_DAT_23002d24);
    DAT_23002d1c = 2;
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0xb8:
    _DAT_23002d24 = (uint)uVar4 << 8;
    iVar9 = FUN_230204ac();
    if (iVar9 << 0x1e < 0) {
      _DAT_23002d24 = _DAT_23002d24 | 1;
    }
    iVar9 = FUN_230204ac();
    if (iVar9 << 0x1d < 0) {
      _DAT_23002d24 = _DAT_23002d24 | 2;
    }
    break;
  case 0xba:
    _DAT_23002d24 = CONCAT31(uVar4,2);
    iVar9 = FUN_230204ac();
    _DAT_23002d24 = CONCAT11((byte)((uint)(iVar9 << 0x1e) >> 0x1f),DAT_23002d24);
    iVar9 = FUN_230204ac();
    DAT_23002d1c = 2;
    _DAT_23002d24 = CONCAT12((byte)((uint)(iVar9 << 0x1d) >> 0x1f),_DAT_23002d24);
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0xbc:
    DAT_23002d1c = 2;
    _DAT_23002d24 = CONCAT22(_DAT_23002d26,DAT_23002db3);
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0xbf:
    _DAT_23002d24 = CONCAT31(uVar4,2);
    iVar9 = FUN_230204ac();
    _DAT_23002d24 = CONCAT11((byte)((uint)(iVar9 << 0x1e) >> 0x1f),DAT_23002d24);
    _DAT_23002d24 = CONCAT12(DAT_23002d80._2_1_,_DAT_23002d24);
    _DAT_23002d24 = CONCAT13(DAT_23002d80._3_1_,_DAT_23002d24);
    iVar9 = FUN_230204ac();
    uVar7 = _DAT_23002d28;
    DAT_23002d28_1._2_1_ = SUB41(uVar7,3);
    _DAT_23002d28 = CONCAT12(DAT_23002d84._1_1_,(short)DAT_23002d84 << 8);
    DAT_23002d1c = 2;
    _DAT_23002d28 = CONCAT31(_DAT_23002d29,(byte)((uint)(iVar9 << 0x1d) >> 0x1f));
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0xc3:
    _DAT_23002d24 = 0;
    DAT_23002d1c = 2;
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0xc5:
    if (DAT_23002dd3 == '\x01') {
      _DAT_23002d24 = CONCAT11(DAT_23002d80._2_1_,1);
      _DAT_23002d24 = CONCAT12(DAT_23002d80._3_1_,_DAT_23002d24);
      _DAT_23002d24 = CONCAT13(bVar6,_DAT_23002d24);
      DAT_23002d1c = 2;
      uVar10 = ram_candidate_23026216();
      return uVar10;
    }
    if (DAT_23002dd3 == '\x02') {
      _DAT_23002d24 = CONCAT11((undefined1)DAT_23002d84,2);
      _DAT_23002d24 = CONCAT12(DAT_23002d84._1_1_,_DAT_23002d24);
      _DAT_23002d24 = CONCAT13(bVar6,_DAT_23002d24);
      DAT_23002d1c = DAT_23002dd3;
      uVar10 = ram_candidate_23026216();
      return uVar10;
    }
    goto code_r0x23026216;
  case 0xc6:
    break;
  }
switchD_23026190_caseD_c6:
  DAT_23002d1c = 2;
code_r0x23026216:
  return 1;
}


