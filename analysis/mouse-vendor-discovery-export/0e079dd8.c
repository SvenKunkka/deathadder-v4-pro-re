
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e079dd8(int param_1,int param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  
  if (param_2 == 0) {
    if (param_1 != 0) goto LAB_0e079dea;
LAB_0e079e46:
    switch(DAT_230076fb) {
    case 1:
s_6N3x_0e079fb9_1:
      if (DAT_23007710 != '\0') {
        FUN_0e07abec();
        DAT_23007710 = '\0';
      }
      DAT_23003868 = 0;
      DAT_2300386e._0_1_ = 0;
      DAT_2300386e._2_2_ = 0;
      DAT_23003872._0_2_ = 0;
      DAT_23003872._2_1_ = 0;
      DAT_2300386a._2_1_ = (undefined1)_DAT_23003882;
      DAT_2300386a._3_1_ = (undefined1)((uint)_DAT_23003882 >> 8);
      break;
    case 2:
s_DN3x_0e079f7f_1:
      if (DAT_23007710 != '\0') {
        FUN_0e07abec();
        DAT_23007710 = '\0';
      }
      DAT_2300386a._3_1_ = DAT_23003880;
      DAT_23003868 = 1;
      DAT_23003872._2_1_ = 0;
      DAT_2300386a._2_1_ = DAT_23003882;
      DAT_2300386e._0_1_ = DAT_23003883;
      DAT_2300386e._2_2_ = (undefined2)DAT_23003894;
      DAT_23003872._0_2_ = (undefined2)((uint)DAT_23003894 >> 0x10);
      break;
    case 3:
LAB_0e079f4c:
      DAT_23003868 = 5;
      DAT_2300386e._1_1_ = 0;
      DAT_2300386a._2_1_ = DAT_23003882;
      DAT_2300386a._3_1_ = DAT_23003880;
      DAT_2300386e._0_1_ = DAT_23003883;
      DAT_23003872._2_1_ = (undefined1)DAT_23003894;
      DAT_23003872._3_1_ = (undefined1)((uint)DAT_23003894 >> 8);
      DAT_23003876._0_2_ = (undefined2)((uint)DAT_23003894 >> 0x10);
      DAT_2300386e._2_2_ = (undefined2)DAT_2300388c;
      DAT_23003872._0_2_ = (undefined2)(DAT_2300388c >> 0x10);
      goto LAB_0e079f34;
    case 4:
LAB_0e07a012:
      DAT_23003868 = 3;
      DAT_23003872._2_1_ = 0;
      DAT_23003872._3_1_ = 0;
      DAT_23003876._0_2_ = 0;
      DAT_2300386e._2_2_ = (undefined2)DAT_23003888;
      DAT_23003872._0_2_ = (undefined2)(DAT_23003888 >> 0x10);
      DAT_2300386a._2_1_ = (undefined1)_DAT_23003882;
      DAT_2300386a._3_1_ = (undefined1)((uint)_DAT_23003882 >> 8);
      DAT_2300386e._0_1_ = (undefined1)((uint)_DAT_23003882 >> 0x10);
      DAT_2300386e._1_1_ = (undefined1)((uint)_DAT_23003882 >> 0x18);
LAB_0e079f34:
      DAT_2300387a._2_2_ = 0;
      DAT_2300387a._0_2_ = 0;
      DAT_23003876._2_2_ = 0;
      DAT_2300386a._0_2_ = 0;
      DAT_2300387e = 0;
      DAT_23003869 = DAT_23003881;
      FUN_0e07a93c();
      DAT_230076fa = DAT_230076fb;
      DAT_230076fb = 0;
      DAT_23007710 = 1;
      return 0;
    case 5:
      goto LAB_0e079e00;
    case 6:
      uVar1 = _DAT_23003883;
LAB_0e079f0c:
      DAT_2300386e._1_1_ = 0;
      DAT_23003872._2_1_ = 0;
      DAT_23003872._3_1_ = 0;
      DAT_2300386e._2_2_ = (undefined2)DAT_23003888;
      DAT_23003872._0_2_ = (undefined2)(DAT_23003888 >> 0x10);
      DAT_23003868 = 4;
      DAT_2300386a._2_1_ = (undefined1)uVar1;
      DAT_2300386a._3_1_ = (undefined1)((ushort)uVar1 >> 8);
      DAT_23003876._0_2_ = 0;
      DAT_2300386e._0_1_ = DAT_23003884._1_1_;
      goto LAB_0e079f34;
    default:
      goto switchD_0e079e50_default;
    }
  }
  else {
    DAT_230076fb = 0;
    DAT_230076fa = 0;
    if (param_1 == 0) {
      DAT_230076fa = 0;
      DAT_230076fb = 0;
      return 0;
    }
LAB_0e079dea:
    switch(DAT_2300770d) {
    case 1:
    case 3:
      iVar3 = 1;
      DAT_23003880 = 0;
      if (DAT_2300770b != '\x01') goto LAB_0e079e7c;
      goto LAB_0e079efa;
    case 2:
    case 4:
      iVar3 = 2;
      DAT_23003880 = 0;
      break;
    default:
      iVar3 = 0;
    }
    if (DAT_2300770b == '\x01') {
LAB_0e079efa:
      DAT_23003881 = 4;
      DAT_23003898 = 2;
    }
    else {
LAB_0e079e7c:
      if (DAT_2300770b == '\x02') {
        DAT_23003881 = 9;
        DAT_23003898 = 4;
      }
      else if (DAT_2300770b == '\0') {
        DAT_23003881 = 3;
        DAT_23003898 = 1;
      }
    }
    if (DAT_23007706 < 0x11) {
      uVar5 = (&DAT_0e098a40)[DAT_23007706];
    }
    else {
      uVar5 = 4;
    }
    _DAT_23003882 = CONCAT31(_DAT_23003883,uVar5);
    if (DAT_2300770d < 6) {
      _DAT_23003882 = CONCAT13(2,_DAT_23003882);
    }
    uVar2 = _DAT_23003882;
    uVar4 = (uint)DAT_23007704;
    DAT_23003888 = (uint)DAT_23007709;
    DAT_23003890 = (uint)DAT_23007705;
    if (DAT_23003888 < 10) {
      DAT_23003888 = 10;
    }
    DAT_2300388c = uVar4;
    if (99 < uVar4) {
      DAT_2300388c = 100;
    }
    DAT_23003884._1_1_ = SUB41(uVar2,3);
    _DAT_23003882 = CONCAT12(DAT_23007707,CONCAT11(DAT_23007708,DAT_23003882));
    if (iVar3 == 1) {
      if (DAT_2300770a != '\0') {
        DAT_230076fb = 4;
        DAT_23003894 = 0;
        goto LAB_0e07a012;
      }
      if (DAT_2300770c != '\0') {
        if (uVar4 != 0) {
          DAT_230076fb = 3;
          DAT_23003894 = 0;
          goto LAB_0e079f4c;
        }
        DAT_230076fb = 2;
        DAT_23003894 = 0;
        goto s_DN3x_0e079f7f_1;
      }
      DAT_230076fb = 1;
      DAT_23003894 = 0;
      goto s_6N3x_0e079fb9_1;
    }
    if (iVar3 != 2) goto LAB_0e079e46;
    if (DAT_2300770a != '\0') {
      DAT_230076fb = 6;
      uVar1 = CONCAT11(DAT_23007707,DAT_23007708);
      goto LAB_0e079f0c;
    }
    DAT_230076fb = 5;
LAB_0e079e00:
    if (DAT_23007710 != '\0') {
      FUN_0e07abec();
      DAT_23007710 = '\0';
    }
    DAT_23003868 = 2;
    DAT_2300386a._3_1_ = 0;
    DAT_23003872._0_2_ = 0;
    DAT_2300386e._0_1_ = 0;
    DAT_2300386e._2_2_ = 0;
    DAT_23003872._2_1_ = DAT_23003883;
    DAT_2300386a._2_1_ = DAT_23003880;
  }
  DAT_2300387e = 0;
  DAT_2300387a._2_2_ = 0;
  DAT_2300387a._0_2_ = 0;
  DAT_23003876._2_2_ = 0;
  DAT_23003876._0_2_ = 0;
  DAT_23003872._3_1_ = 0;
  DAT_2300386e._1_1_ = 0;
  DAT_2300386a._0_2_ = 0;
  DAT_23003869 = DAT_23003881;
  FUN_0e07a93c();
  DAT_230076fa = DAT_230076fb;
  DAT_230076fb = 0;
switchD_0e079e50_default:
  return 0;
}


