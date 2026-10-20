/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07c33c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e07c33c(void)

{
  int iVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  uint uVar8;
  uint uVar9;
  
  uVar2 = DAT_23003f04;
  bVar4 = DAT_23003f05;
  bVar6 = (byte)DAT_23003f06;
  bVar5 = DAT_23003f06._1_1_;
  uVar3 = _DAT_23003f04;
  switch(DAT_23003f03) {
  case 3:
    if (bVar4 == 4) {
      if (bVar6 == 1) {
        DAT_2300778c = bVar6;
        DAT_230077b6 = 0;
        return;
      }
      if (bVar6 == 0) {
        DAT_2300778b = bVar6;
        DAT_230077b6 = 1;
        return;
      }
      return;
    }
    break;
  case 5:
    DAT_230077b8 = bVar6;
    DAT_230077b7 = bVar5;
    if ((((DAT_2300778c == '\x01') && (bVar4 == 4)) && (DAT_23007719 == 4)) &&
       ((bVar6 < 0x1a && (bVar5 < 0x1a)))) {
      FUN_0e080598();
LAB_0e080600:
      DAT_23004983 = CONCAT13(DAT_230077b7,
                              CONCAT12(DAT_230077b8,CONCAT11(DAT_23007717,DAT_23007719)));
      DAT_23004987 = DAT_230077bb;
      DAT_23004988 = DAT_230077ba;
      DAT_23004989 = DAT_230077b9;
      FUN_0e07d4ac(2,0);
      return;
    }
    break;
  case 0xb:
    if (bVar4 != 4) {
      return;
    }
    DAT_23007719 = bVar6;
    DAT_23007718 = bVar5;
    if (bVar6 == 1) {
      cVar7 = '\0';
      if (bVar5 != 0) {
        if (bVar5 == 1) {
          cVar7 = -0x7b;
        }
        else {
          if (bVar5 != 2) {
            DAT_23003efc = 3;
            return;
          }
          cVar7 = -0x71;
        }
      }
      DAT_23007717 = cVar7;
      FUN_0e080538();
      goto LAB_0e080600;
    }
    if (bVar6 == 4) {
      return;
    }
    break;
  case 0x10:
    uVar8 = _DAT_23003f04 & 0xff;
    if (uVar8 == 0) {
      DAT_23004a50._0_1_ = bVar4;
      ram_candidate_23020354();
    }
    else if (uVar8 < 6) {
      DAT_23004a50._0_1_ = bVar4;
      (&DAT_230044fa)[(uVar8 - 1) * 0xf4] = bVar4;
      FUN_0e07d4ac(8,uVar8 - 1 & 0xff);
      FUN_0e0973ea(&DAT_23003ab0,0,1000);
      ram_candidate_23020354();
    }
    else {
      DAT_23003efc = 3;
    }
    DAT_23007761 = 0;
    DAT_23007760 = 0;
    DAT_23007763 = 0;
    DAT_23007762 = 0;
    return;
  case 0x11:
    uVar8 = _DAT_23003f04 & 0xff;
    if (uVar8 == 0) {
      DAT_23007763 = uVar2;
      DAT_23007760 = uVar2;
      DAT_23007761 = uVar2;
      DAT_23007762 = uVar2;
      if ((bVar4 == 3) && (DAT_230077a2 == '\0')) {
        DAT_23007761 = 1;
      }
      if (bVar4 != DAT_23004a50._1_1_) {
        ram_candidate_23020354();
        DAT_23004a50._1_1_ = DAT_23003f05;
      }
      return;
    }
    if (uVar8 < 6) {
      DAT_23007760 = 0;
      DAT_23007762 = 0;
      DAT_23007763 = 0;
      DAT_23007761 = 0;
      if ((bVar4 == 3) && (DAT_230077a2 == '\0')) {
        DAT_23007761 = 1;
      }
      uVar8 = uVar8 - 1;
      bVar6 = (&DAT_230044fb)[uVar8 * 0xf4];
      if (bVar4 != (&DAT_230044fb)[uVar8 * 0xf4]) {
        ram_candidate_23020354();
        uVar8 = (_DAT_23003f04 & 0xff) - 1;
        bVar6 = (byte)(_DAT_23003f04 >> 8);
      }
      DAT_23004a50._1_1_ = bVar6;
      (&DAT_230044fb)[uVar8 * 0xf4] = DAT_23004a50._1_1_;
      FUN_0e07d4ac(8,uVar8 & 0xff);
      return;
    }
    break;
  case 0x12:
    uVar8 = _DAT_23003f04 & 0xff;
    if (uVar8 == 0) {
      *(byte *)((int)&DAT_23004a54 + bVar4 + 1) = bVar6;
      return;
    }
    if (uVar8 < 6) {
      *(byte *)((uVar8 - 1) * 0xf4 + (uint)bVar4 + 0x230044ff) = bVar6;
      FUN_0e07d4ac(8,uVar8 - 1 & 0xff);
      return;
    }
    break;
  case 0x13:
    if (((bVar6 < 0xfb) && (bVar4 == 3)) || (DAT_23007763 != '\0')) {
      uVar8 = (uint)DAT_23007762;
      unique0x001fb700 = (ushort)bVar6;
      *(ushort *)(&DAT_23004503 + (uint)DAT_23004477 * 0xf4) = unique0x001fb700;
      if (uVar8 != bVar5) {
        DAT_23007763 = 1;
        return;
      }
      uVar9 = uVar8 + (byte)DAT_23003f08;
      DAT_23007762 = (byte)uVar9;
      FUN_0e09739c(&DAT_23003ab0 + uVar8 * 4,0x23003f09,((byte)DAT_23003f08 & 0x3f) << 2);
      if (bVar6 <= uVar9) {
        DAT_23007761 = 0;
        FUN_0e09739c(&DAT_23005014,&DAT_23003ab0,1000);
        ram_candidate_23020354();
        DAT_23007725 = DAT_23007725 | 8;
        return;
      }
      return;
    }
    break;
  case 0x14:
    if (0xa6 < (byte)(bVar6 - 0x2d)) {
      uVar8 = _DAT_23003f04 & 0xff;
      if (uVar8 == 0) {
        DAT_23004a50._3_1_ = bVar6;
        DAT_23004a50._2_1_ = bVar4;
      }
      else {
        if (uVar8 < 6) {
          iVar1 = (uVar8 - 1 & 0xff) * 0xf4;
          (&DAT_230044fc)[iVar1] = bVar4;
          DAT_23004a50._2_1_ = bVar4;
          (&DAT_230044fd)[iVar1] = bVar6;
          DAT_23004a50._3_1_ = bVar6;
          FUN_0e07d4ac(8);
          uVar8 = _DAT_23003f04 & 0xff;
          if (uVar8 == 0) goto LAB_0e07c52a;
        }
        else {
          DAT_23003efc = 3;
        }
        if (DAT_23004476 != uVar8) {
          return;
        }
      }
LAB_0e07c52a:
      FUN_0e08494c(DAT_23004a50._2_1_);
      return;
    }
    break;
  case 0x15:
    uVar8 = _DAT_23003f04 & 0xff;
    if (uVar8 == 0) {
      DAT_23004a54._0_1_ = bVar4;
      return;
    }
    if (uVar8 < 6) {
      DAT_23004a54._0_1_ = bVar4;
      (&DAT_230044fe)[(uVar8 - 1) * 0xf4] = bVar4;
      FUN_0e07d4ac(8,uVar8 - 1 & 0xff);
      return;
    }
    break;
  case 0x80:
    _DAT_23003f04 = CONCAT22(DAT_23003f06,0x401);
    return;
  case 0x83:
    if (bVar4 == 4) {
      _DAT_23003f04 = CONCAT12(DAT_2300778c,_DAT_23003f04);
      _DAT_23003f04 = CONCAT13(bVar5,_DAT_23003f04);
      DAT_2300778b = 0;
      return;
    }
    break;
  case 0x85:
    _DAT_23003f04 = _DAT_23003f04 & 0xffff;
    if (DAT_23007717 != '\0') {
      if (DAT_23007717 == -0x7b) {
        _DAT_23003f04 = CONCAT12(1,uVar3);
        _DAT_23003f04 = (uint)_DAT_23003f04;
      }
      else if (DAT_23007717 == -0x71) {
        _DAT_23003f04 = CONCAT12(2,uVar3);
        _DAT_23003f04 = (uint)_DAT_23003f04;
      }
    }
    _DAT_23003f04 = CONCAT13(DAT_230077b8,_DAT_23003f04);
    DAT_23003f08._0_1_ = DAT_230077b7;
    ram0x23003f09 = 0;
    DAT_23003f0c._1_2_ = 0;
    return;
  case 0x8b:
    if (bVar4 == 4) {
      _DAT_23003f04 = CONCAT12(DAT_23007719,_DAT_23003f04);
      _DAT_23003f04 = CONCAT13(DAT_23007718,_DAT_23003f04);
      return;
    }
    return;
  case 0x8e:
    _DAT_23003f04 = 4;
    DAT_23003f08._0_1_ = 8;
    ram0x23003f09 = CONCAT31(DAT_23003f08_2,0x12);
    return;
  case 0x90:
    uVar8 = _DAT_23003f04 & 0xff;
    if (uVar8 == 0) {
      _DAT_23003f04 = CONCAT11((byte)DAT_23004a50,uVar2);
      return;
    }
    if (uVar8 < 6) {
      _DAT_23003f04 = CONCAT11((&DAT_230044fa)[(uVar8 - 1) * 0xf4],uVar2);
      return;
    }
    break;
  case 0x91:
    uVar8 = _DAT_23003f04 & 0xff;
    if (uVar8 == 0) {
      _DAT_23003f04 = CONCAT11(DAT_23004a50._1_1_,uVar2);
      return;
    }
    if (uVar8 < 6) {
      _DAT_23003f04 = CONCAT11((&DAT_230044fb)[(uVar8 - 1) * 0xf4],uVar2);
      return;
    }
    break;
  case 0x92:
    uVar8 = _DAT_23003f04 & 0xff;
    if (uVar8 == 0) {
      _DAT_23003f04 = CONCAT12(*(undefined1 *)((int)&DAT_23004a54 + bVar4 + 1),_DAT_23003f04);
      _DAT_23003f04 = CONCAT13(bVar5,_DAT_23003f04);
      return;
    }
    if (uVar8 < 6) {
      _DAT_23003f04 =
           CONCAT12(*(undefined1 *)((uVar8 - 1) * 0xf4 + (uint)bVar4 + 0x230044ff),_DAT_23003f04);
      _DAT_23003f04 = CONCAT13(bVar5,_DAT_23003f04);
      return;
    }
    break;
  case 0x93:
    if (((bVar6 < 0xfb) && (bVar6 <= ram0x23004a59)) && (bVar4 == 3)) {
      FUN_0e09739c(0x23003f09,&DAT_23003ab0 + (uint)bVar5 * 4,((byte)DAT_23003f08 & 0x3f) << 2);
      return;
    }
    break;
  case 0x94:
    uVar8 = _DAT_23003f04 & 0xff;
    if (uVar8 == 0) {
      _DAT_23003f04 = CONCAT11(DAT_23004a50._2_1_,uVar2);
      _DAT_23003f04 = CONCAT12(DAT_23004a50._3_1_,_DAT_23003f04);
      _DAT_23003f04 = CONCAT13(bVar5,_DAT_23003f04);
      return;
    }
    if (uVar8 < 6) {
      iVar1 = (uVar8 - 1 & 0xff) * 0xf4;
      _DAT_23003f04 = CONCAT11((&DAT_230044fc)[iVar1],uVar2);
      _DAT_23003f04 = CONCAT12((&DAT_230044fd)[iVar1],_DAT_23003f04);
      _DAT_23003f04 = CONCAT13(bVar5,_DAT_23003f04);
      return;
    }
    break;
  case 0x95:
    uVar8 = _DAT_23003f04 & 0xff;
    if (uVar8 == 0) {
      _DAT_23003f04 = CONCAT11((byte)DAT_23004a54,uVar2);
      return;
    }
    if (uVar8 < 6) {
      _DAT_23003f04 = CONCAT11((&DAT_230044fe)[(uVar8 - 1) * 0xf4],uVar2);
      return;
    }
  }
  DAT_23003efc = 3;
  return;
}


