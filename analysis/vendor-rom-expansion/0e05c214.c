
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e05c214(int param_1,int param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  
  if (param_2 == 0) {
    if (param_1 != 0) goto LAB_0e05c226;
LAB_0e05c282:
    switch(DAT_230071c9) {
    case 1:
s_6N3x_0e05c3f5_1:
      if (DAT_230071de != '\0') {
        FUN_0e05d028();
        DAT_230071de = '\0';
      }
      DAT_230065e8 = 0;
      DAT_230065ee._0_1_ = 0;
      DAT_230065ee._2_2_ = 0;
      DAT_230065f2._0_2_ = 0;
      DAT_230065f2._2_1_ = 0;
      DAT_230065ea._2_1_ = (undefined1)_DAT_23006602;
      DAT_230065ea._3_1_ = (undefined1)((uint)_DAT_23006602 >> 8);
      break;
    case 2:
s_DN3x_0e05c3bb_1:
      if (DAT_230071de != '\0') {
        FUN_0e05d028();
        DAT_230071de = '\0';
      }
      DAT_230065ea._3_1_ = DAT_23006600;
      DAT_230065e8 = 1;
      DAT_230065f2._2_1_ = 0;
      DAT_230065ea._2_1_ = DAT_23006602;
      DAT_230065ee._0_1_ = DAT_23006603;
      DAT_230065ee._2_2_ = (undefined2)DAT_23006614;
      DAT_230065f2._0_2_ = (undefined2)((uint)DAT_23006614 >> 0x10);
      break;
    case 3:
LAB_0e05c388:
      DAT_230065e8 = 5;
      DAT_230065ee._1_1_ = 0;
      DAT_230065ea._2_1_ = DAT_23006602;
      DAT_230065ea._3_1_ = DAT_23006600;
      DAT_230065ee._0_1_ = DAT_23006603;
      DAT_230065f2._2_1_ = (undefined1)DAT_23006614;
      DAT_230065f2._3_1_ = (undefined1)((uint)DAT_23006614 >> 8);
      DAT_230065f6._0_2_ = (undefined2)((uint)DAT_23006614 >> 0x10);
      DAT_230065ee._2_2_ = (undefined2)DAT_2300660c;
      DAT_230065f2._0_2_ = (undefined2)(DAT_2300660c >> 0x10);
      goto LAB_0e05c370;
    case 4:
LAB_0e05c44e:
      DAT_230065e8 = 3;
      DAT_230065f2._2_1_ = 0;
      DAT_230065f2._3_1_ = 0;
      DAT_230065f6._0_2_ = 0;
      DAT_230065ee._2_2_ = (undefined2)DAT_23006608;
      DAT_230065f2._0_2_ = (undefined2)(DAT_23006608 >> 0x10);
      DAT_230065ea._2_1_ = (undefined1)_DAT_23006602;
      DAT_230065ea._3_1_ = (undefined1)((uint)_DAT_23006602 >> 8);
      DAT_230065ee._0_1_ = (undefined1)((uint)_DAT_23006602 >> 0x10);
      DAT_230065ee._1_1_ = (undefined1)((uint)_DAT_23006602 >> 0x18);
LAB_0e05c370:
      DAT_230065fa._2_2_ = 0;
      DAT_230065fa._0_2_ = 0;
      DAT_230065f6._2_2_ = 0;
      DAT_230065ea._0_2_ = 0;
      DAT_230065fe = 0;
      DAT_230065e9 = DAT_23006601;
      FUN_0e05cd78();
      DAT_230071c8 = DAT_230071c9;
      DAT_230071c9 = 0;
      DAT_230071de = 1;
      return 0;
    case 5:
      goto LAB_0e05c23c;
    case 6:
      uVar1 = _DAT_23006603;
LAB_0e05c348:
      DAT_230065ee._1_1_ = 0;
      DAT_230065f2._2_1_ = 0;
      DAT_230065f2._3_1_ = 0;
      DAT_230065ee._2_2_ = (undefined2)DAT_23006608;
      DAT_230065f2._0_2_ = (undefined2)(DAT_23006608 >> 0x10);
      DAT_230065e8 = 4;
      DAT_230065ea._2_1_ = (undefined1)uVar1;
      DAT_230065ea._3_1_ = (undefined1)((ushort)uVar1 >> 8);
      DAT_230065f6._0_2_ = 0;
      DAT_230065ee._0_1_ = DAT_23006604._1_1_;
      goto LAB_0e05c370;
    default:
      goto switchD_0e05c28c_default;
    }
  }
  else {
    DAT_230071c9 = 0;
    DAT_230071c8 = 0;
    if (param_1 == 0) {
      DAT_230071c8 = 0;
      DAT_230071c9 = 0;
      return 0;
    }
LAB_0e05c226:
    switch(DAT_230071db) {
    case 1:
    case 3:
      iVar3 = 1;
      DAT_23006600 = 0;
      if (DAT_230071d9 != '\x01') goto LAB_0e05c2b8;
      goto LAB_0e05c336;
    case 2:
    case 4:
      iVar3 = 2;
      DAT_23006600 = 0;
      break;
    default:
      iVar3 = 0;
    }
    if (DAT_230071d9 == '\x01') {
LAB_0e05c336:
      DAT_23006601 = 4;
      DAT_23006618 = 2;
    }
    else {
LAB_0e05c2b8:
      if (DAT_230071d9 == '\x02') {
        DAT_23006601 = 9;
        DAT_23006618 = 4;
      }
      else if (DAT_230071d9 == '\0') {
        DAT_23006601 = 3;
        DAT_23006618 = 1;
      }
    }
    if (DAT_230071d4 < 0x11) {
      uVar5 = (&DAT_0e06fbe8)[DAT_230071d4];
    }
    else {
      uVar5 = 4;
    }
    _DAT_23006602 = CONCAT31(_DAT_23006603,uVar5);
    if (DAT_230071db < 6) {
      _DAT_23006602 = CONCAT13(2,_DAT_23006602);
    }
    uVar2 = _DAT_23006602;
    uVar4 = (uint)DAT_230071d2;
    DAT_23006608 = (uint)DAT_230071d7;
    DAT_23006610 = (uint)DAT_230071d3;
    if (DAT_23006608 < 10) {
      DAT_23006608 = 10;
    }
    DAT_2300660c = uVar4;
    if (99 < uVar4) {
      DAT_2300660c = 100;
    }
    DAT_23006604._1_1_ = SUB41(uVar2,3);
    _DAT_23006602 = CONCAT12(DAT_230071d5,CONCAT11(DAT_230071d6,DAT_23006602));
    if (iVar3 == 1) {
      if (DAT_230071d8 != '\0') {
        DAT_230071c9 = 4;
        DAT_23006614 = 0;
        goto LAB_0e05c44e;
      }
      if (DAT_230071da != '\0') {
        if (uVar4 != 0) {
          DAT_230071c9 = 3;
          DAT_23006614 = 0;
          goto LAB_0e05c388;
        }
        DAT_230071c9 = 2;
        DAT_23006614 = 0;
        goto s_DN3x_0e05c3bb_1;
      }
      DAT_230071c9 = 1;
      DAT_23006614 = 0;
      goto s_6N3x_0e05c3f5_1;
    }
    if (iVar3 != 2) goto LAB_0e05c282;
    if (DAT_230071d8 != '\0') {
      DAT_230071c9 = 6;
      uVar1 = CONCAT11(DAT_230071d5,DAT_230071d6);
      goto LAB_0e05c348;
    }
    DAT_230071c9 = 5;
LAB_0e05c23c:
    if (DAT_230071de != '\0') {
      FUN_0e05d028();
      DAT_230071de = '\0';
    }
    DAT_230065e8 = 2;
    DAT_230065ea._3_1_ = 0;
    DAT_230065f2._0_2_ = 0;
    DAT_230065ee._0_1_ = 0;
    DAT_230065ee._2_2_ = 0;
    DAT_230065f2._2_1_ = DAT_23006603;
    DAT_230065ea._2_1_ = DAT_23006600;
  }
  DAT_230065fe = 0;
  DAT_230065fa._2_2_ = 0;
  DAT_230065fa._0_2_ = 0;
  DAT_230065f6._2_2_ = 0;
  DAT_230065f6._0_2_ = 0;
  DAT_230065f2._3_1_ = 0;
  DAT_230065ee._1_1_ = 0;
  DAT_230065ea._0_2_ = 0;
  DAT_230065e9 = DAT_23006601;
  FUN_0e05cd78();
  DAT_230071c8 = DAT_230071c9;
  DAT_230071c9 = 0;
switchD_0e05c28c_default:
  return 0;
}


