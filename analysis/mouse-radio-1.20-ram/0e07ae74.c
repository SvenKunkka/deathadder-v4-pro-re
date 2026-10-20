/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07ae74. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_0e07ae74(void)

{
  int iVar1;
  undefined3 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  byte bVar5;
  undefined1 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined2 local_1c;
  
  uVar8 = DAT_2300497f;
  uVar7 = DAT_2300497b;
  uVar6 = DAT_2300497a;
  uVar3 = DAT_23003f06;
  uVar2 = _DAT_23003f05;
  switch(DAT_23003f03) {
  case 2:
    DAT_230049b5 = _DAT_23003f04;
    DAT_230049b9 = DAT_23003f08;
    DAT_230049bd = DAT_23003f0c;
    DAT_230049c1 = DAT_23003f10;
    DAT_230049c5 = DAT_23003f14;
    DAT_230049c9 = DAT_23003f18;
    bVar5 = 0;
    uVar4 = 4;
    goto LAB_0e07b0a0;
  default:
    goto switchD_0e07ae86_caseD_3;
  case 4:
    uVar8 = _DAT_23003f04 & 0xff;
    uVar7 = (uint)DAT_23007724;
    if (uVar8 != DAT_23007724) {
      if (uVar8 == 0) {
        DAT_23007761 = DAT_23003f04;
        DAT_23007763 = DAT_23003f04;
      }
      else {
        uVar7 = uVar8;
        if (uVar8 != 3) goto LAB_0e07b1e8;
      }
      thunk_FUN_2302843c();
      if (DAT_2300775f != '\0') {
        DAT_2300775f = '\0';
        FUN_0e0798e0();
      }
      uVar7 = _DAT_23003f04 & 0xff;
    }
LAB_0e07b1e8:
    DAT_23007724 = (byte)uVar7;
    if (uVar7 == 1) {
      FUN_0e07d6d8(0);
      if (DAT_23004a4c != -0x55555556) {
        DAT_23004a4c = -0x55555556;
        FUN_0e07ddfc(3,0xa004,&DAT_23004a48,8);
      }
      FUN_0e07ae4c(200);
                    /* WARNING: Subroutine does not return */
      FUN_0e085ed0(0);
    }
    break;
  case 5:
    if (DAT_23007723 == '\x01') {
      DAT_23004a5e = DAT_23003f04;
      (&DAT_230044d0)[(uint)DAT_23004477 * 0xf4] = DAT_23003f04;
    }
    else {
      DAT_23004a5c = DAT_23003f04;
      (&DAT_230044ce)[(uint)DAT_23004477 * 0xf4] = DAT_23003f04;
    }
    FUN_0e07d4ac(8);
    bVar5 = DAT_23004a5e;
    goto LAB_0e07b1b6;
  case 6:
    DAT_230049af = _DAT_23003f04;
    bVar5 = 0;
    uVar4 = 4;
    goto LAB_0e07b0a0;
  case 0xb:
    if ((_DAT_23003f04 & 0xff) == 0) {
      FUN_0e07d6d8(0);
      FUN_0e07ae4c(200);
                    /* WARNING: Subroutine does not return */
      FUN_0e085ed0(0);
    }
    if ((_DAT_23003f04 & 0xff) != 1) {
      return;
    }
    DAT_23007729 = DAT_23003f04;
    local_30 = DAT_23004994;
    uStack_2c = DAT_23004998;
    uStack_28 = DAT_2300499c;
    uStack_24 = DAT_230049a0;
    local_20 = DAT_230049a4;
    local_1c = DAT_230049a8;
    if (DAT_23007724 == 2) {
      FUN_0e09739c(&DAT_23004958,&DAT_0e099058,0x54);
      DAT_2300497b = DAT_230049cb;
      DAT_2300497f = DAT_230049cb;
    }
    else {
      FUN_0e09739c(&DAT_23004958,&DAT_0e099058,0x54,&local_30);
      DAT_2300497a = uVar6;
      DAT_2300497b = uVar7;
      DAT_2300497f = uVar8;
    }
    DAT_23004994 = local_30;
    DAT_230049a0 = uStack_24;
    DAT_23004998 = uStack_2c;
    DAT_2300499c = uStack_28;
    DAT_230049a4 = local_20;
    DAT_230049a8 = local_1c;
    FUN_0e09739c(&DAT_23004474,&DAT_0e098b74,0x4e4);
    thunk_FUN_2302678c(0);
    iVar1 = (uint)DAT_23004477 * 0xf4;
    FUN_0e09739c(&DAT_23006660,&DAT_23004505 + (uint)DAT_23004477 * 0xf4,0x80);
    FUN_0e08042c(*(undefined2 *)(&DAT_230044ca + iVar1),*(undefined2 *)(&DAT_230044cc + iVar1));
    FUN_0e07d4ac(2,DAT_23004477);
    uVar4 = 8;
    bVar5 = DAT_23004477;
    goto LAB_0e07b0a0;
  case 0xd:
    uVar4 = 4;
    DAT_230049b1 = _DAT_23003f04;
    bVar5 = 0;
    goto LAB_0e07b0a0;
  case 0xe:
    if ((_DAT_23003f04 & 0xff) != 0) {
      uVar7 = (_DAT_23003f04 & 0xff) - 1;
      if (DAT_23007723 == '\x01') {
        DAT_23004a5e = DAT_23003f05;
        (&DAT_230044d0)[uVar7 * 0xf4] = DAT_23003f05;
      }
      else {
        DAT_23004a5c = DAT_23003f05;
        (&DAT_230044ce)[uVar7 * 0xf4] = DAT_23003f05;
      }
      FUN_0e07d4ac(8,uVar7 & 0xff);
      if (((uint)DAT_23004476 != (_DAT_23003f04 & 0xff)) &&
         (bVar5 = DAT_23004a5e, (_DAT_23003f04 & 0xff) != 0)) goto LAB_0e07b1b6;
    }
    bVar5 = DAT_23003f05;
    if (DAT_23007723 != '\x01') {
      DAT_23004a5c = DAT_23003f05;
      bVar5 = DAT_23004a5e;
    }
LAB_0e07b1b6:
    DAT_23004a5e = bVar5;
    (*(code *)0x23028045)();
    return;
  case 0x17:
  case 0x24:
    DAT_230049cb = _DAT_23003f04;
    if (0xfffffffc < _DAT_23003f04 - 1 && _DAT_23003f04 != 0xfffffffe) {
      DAT_230049cb = CONCAT13((char)_DAT_0fffe010,
                              CONCAT12((char)((uint)_DAT_0fffe010 >> 8),
                                       CONCAT11((char)((uint)_DAT_0fffe010 >> 0x10),
                                                (char)((uint)_DAT_0fffe010 >> 0x18))));
    }
    FUN_0e07d4ac(4,0);
    if (((((DAT_2300497b & 0xff) == 0x66) && (DAT_2300497b._1_1_ == 'w')) &&
        (DAT_2300497b._2_1_ == -0x78)) && (DAT_2300497b._3_1_ == -0x67)) {
      DAT_2300497b = _DAT_23003f04;
      FUN_0e07d4ac(2,0);
      DAT_2300768e = 0;
      FUN_0e07d590();
    }
    if ((((DAT_2300497f & 0xff) == 0x66) && (DAT_2300497f._1_1_ == 'w')) &&
       ((DAT_2300497f._2_1_ == -0x78 && (DAT_2300497f._3_1_ == -0x67)))) {
      DAT_2300497f = _DAT_23003f04;
      FUN_0e07d4ac(2,0);
      DAT_2300768e = 0;
      FUN_0e07d590();
    }
    thunk_FUN_23025c48(DAT_230049cb << 0x18 | (DAT_230049cb >> 8 & 0xff) << 0x10 |
                       (DAT_230049cb >> 0x10 & 0xff) << 8 | DAT_230049cb >> 0x18);
    return;
  case 0x33:
    DAT_23004966 = DAT_23003f04;
    uVar4 = 2;
    bVar5 = DAT_23004477;
LAB_0e07b0a0:
    FUN_0e07d4ac(uVar4,bVar5);
    return;
  case 0x40:
    if (DAT_23007723 == '\x01') {
      if ((DAT_23007771 != '\0') || (7 < DAT_23003f05)) {
        uVar7 = _DAT_23003f04 & 0xff;
        if (uVar7 == 0) {
          DAT_23007781 = DAT_23003f05;
        }
        else {
          uVar8 = uVar7 - 1;
          if (DAT_23004476 == uVar7) {
            DAT_23007781 = DAT_23003f05;
            (&DAT_230044d1)[uVar8 * 0xf4] = DAT_23003f05;
            FUN_0e07d4ac(8,uVar8 & 0xff);
          }
          else {
            (&DAT_230044d1)[uVar8 * 0xf4] = DAT_23003f05;
            FUN_0e07d4ac(8,uVar8 & 0xff);
          }
        }
        thunk_FUN_23026ce0(1,DAT_23007781);
        ram_candidate_230212d8(DAT_23004a5f);
        return;
      }
    }
    else if ((DAT_23007723 == '\x04') && (DAT_2300779e != '\0')) {
      uVar7 = _DAT_23003f04 & 0xff;
      if (uVar7 == 0) {
        DAT_23007781 = DAT_23003f05;
      }
      else {
        uVar8 = uVar7 - 1;
        if (DAT_23004476 == uVar7) {
          DAT_23007781 = DAT_23003f05;
          (&DAT_230044cf)[uVar8 * 0xf4] = DAT_23003f05;
          FUN_0e07d4ac(8,uVar8 & 0xff);
        }
        else {
          (&DAT_230044cf)[uVar8 * 0xf4] = DAT_23003f05;
          FUN_0e07d4ac(8,uVar8 & 0xff);
        }
      }
      thunk_FUN_23026ce0(4,DAT_23007781);
      return;
    }
    goto switchD_0e07ae86_caseD_3;
  case 0x81:
    _DAT_23003f04 = CONCAT22(uVar3,0x1401);
    break;
  case 0x82:
    DAT_23003f10 = DAT_230049c1;
    _DAT_23003f04 = DAT_230049b5;
    DAT_23003f08 = DAT_230049b9;
    DAT_23003f0c = DAT_230049bd;
    DAT_23003f18 = DAT_230049c9;
    DAT_23003f14 = DAT_230049c5;
    break;
  case 0x83:
    _DAT_23003f04 = CONCAT22(uVar3,0x3601);
    break;
  case 0x84:
    _DAT_23003f04 = CONCAT31(uVar2,DAT_23007724);
    break;
  case 0x85:
    if (DAT_23007723 == '\x01') {
      uVar6 = (&DAT_230044d0)[(uint)DAT_23004477 * 0xf4];
    }
    else {
      uVar6 = (&DAT_230044ce)[(uint)DAT_23004477 * 0xf4];
    }
    _DAT_23003f04 = CONCAT31(uVar2,uVar6);
    break;
  case 0x86:
    _DAT_23003f04 = CONCAT22(uVar3,DAT_230049af);
    break;
  case 0x87:
    _DAT_23003f04 = 0x1401;
    break;
  case 0x8d:
    _DAT_23003f04 = DAT_230049b1;
    break;
  case 0x8e:
    if ((_DAT_23003f04 & 0xff) == 0) {
      bVar5 = DAT_23004a5e;
      if (DAT_23007723 != '\x01') {
        bVar5 = DAT_23004a5c;
      }
      _DAT_23003f04 = CONCAT11(bVar5,DAT_23003f04);
      _DAT_23003f04 = CONCAT22(uVar3,_DAT_23003f04);
    }
    else {
      iVar1 = ((_DAT_23003f04 & 0xff) - 1) * 0xf4;
      if (DAT_23007723 == '\x01') {
        uVar6 = (&DAT_230044d0)[iVar1];
      }
      else {
        uVar6 = (&DAT_230044ce)[iVar1];
      }
      _DAT_23003f04 = CONCAT11(uVar6,DAT_23003f04);
      _DAT_23003f04 = CONCAT22(uVar3,_DAT_23003f04);
    }
    break;
  case 0x97:
  case 0xa4:
    DAT_23003f0c = DAT_2300497f;
    _DAT_23003f04 = DAT_230049cb;
    DAT_23003f08 = DAT_2300497b;
    DAT_23003f10 = CONCAT31(DAT_23003f10._1_3_,DAT_2300497a);
    break;
  case 0xb3:
    _DAT_23003f04 = CONCAT31(uVar2,DAT_23004966);
    break;
  case 0xc0:
    uVar7 = _DAT_23003f04 & 0xff;
    if (uVar7 == 0) {
      if (DAT_23007723 == '\x01') {
        _DAT_23003f04 = CONCAT11(DAT_23004a5f,DAT_23003f04);
        _DAT_23003f04 = CONCAT22(uVar3,_DAT_23003f04);
        return;
      }
      if (DAT_23007723 == '\x04') {
        _DAT_23003f04 = CONCAT11(DAT_23004a5d,DAT_23003f04);
        _DAT_23003f04 = CONCAT22(uVar3,_DAT_23003f04);
        return;
      }
    }
    else {
      if (DAT_23007723 == '\x01') {
        _DAT_23003f04 = CONCAT11((&DAT_230044d1)[(uVar7 - 1) * 0xf4],DAT_23003f04);
        _DAT_23003f04 = CONCAT22(uVar3,_DAT_23003f04);
        return;
      }
      if (DAT_23007723 == '\x04') {
        _DAT_23003f04 = CONCAT11((&DAT_230044cf)[(uVar7 - 1) * 0xf4],DAT_23003f04);
        _DAT_23003f04 = CONCAT22(uVar3,_DAT_23003f04);
        return;
      }
    }
switchD_0e07ae86_caseD_3:
    DAT_23003efc = 5;
  }
  return;
}


