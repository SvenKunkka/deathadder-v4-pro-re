/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07c9e0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e07c9e0(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined1 uVar5;
  byte bVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  
  uVar5 = DAT_23003f08._3_1_;
  bVar6 = DAT_23003f05;
  if (DAT_23003f03 < 0x12) {
    if (DAT_23003f03 != 0) {
      switch(DAT_23003f03) {
      case 1:
        DAT_23004963 = DAT_23003f04;
        FUN_0e07d4ac(2,0);
        return;
      case 2:
        DAT_23004964 = DAT_23003f04;
        FUN_0e07d4ac(2,0);
        return;
      case 3:
        DAT_23004960 = CONCAT11(DAT_23003f05,DAT_23003f04) << 8 | (ushort)DAT_23003f05;
        FUN_0e07d4ac(2,0);
        return;
      default:
        break;
      case 0xd:
        goto switchD_0e07ca20_caseD_d;
      case 0x11:
        if (DAT_23003f04 != 1) {
          return;
        }
        FUN_0e097598();
        FUN_0e07ae4c(100);
                    /* WARNING: Subroutine does not return */
        FUN_0e085ed0(0);
      }
    }
  }
  else if ((DAT_23003f03 ^ 0x80) < 0xe) {
    switch(DAT_23003f03) {
    case 0x80:
      DAT_23003f05 = DAT_23007733;
      return;
    case 0x81:
      DAT_23003f04 = DAT_23004963;
      return;
    case 0x82:
      DAT_23003f04 = DAT_23004964;
      return;
    case 0x83:
      DAT_23003f04 = (char)(DAT_23004960 >> 8);
      DAT_23003f05 = (char)DAT_23004960;
      return;
    case 0x84:
      if (DAT_230077a2 == '\0') {
        DAT_23003f05 = DAT_230077a2;
        return;
      }
      DAT_23003f05 = 1;
      return;
    case 0x85:
      DAT_23003f05 = (byte)((uint)_DAT_23006c30 >> 0x18);
      DAT_23003f06._0_1_ = (undefined1)((uint)_DAT_23006c30 >> 0x10);
      DAT_23003f06._1_1_ = (undefined1)((uint)_DAT_23006c30 >> 8);
      DAT_23003f08._0_1_ = (undefined1)_DAT_23006c30;
      return;
    case 0x8d:
      if (DAT_23003f04 == 0) {
        DAT_23003f08._2_1_ = (undefined1)DAT_23003f58;
        DAT_23003f08._3_1_ = (undefined1)((ushort)DAT_23003f58 >> 8);
        DAT_23003f05 = DAT_23007716;
        DAT_23003f06._0_1_ = (undefined1)DAT_23003f60;
        DAT_23003f06._1_1_ = DAT_23003f60._1_1_;
        DAT_23003f08._0_1_ = (undefined1)DAT_23003f5c;
        DAT_23003f08._1_1_ = DAT_23003f5c._1_1_;
        return;
      }
      iVar10 = (DAT_23003f04 - 1) * 0xf4;
      uVar7 = *(undefined4 *)(&DAT_230044f3 + iVar10);
      DAT_23003f05 = (byte)uVar7;
      DAT_23003f06._0_1_ = (undefined1)((uint)uVar7 >> 8);
      DAT_23003f06._1_1_ = (undefined1)((uint)uVar7 >> 0x10);
      DAT_23003f08._0_1_ = (undefined1)((uint)uVar7 >> 0x18);
      DAT_23003f08._1_1_ = (undefined1)*(undefined2 *)(&DAT_230044f7 + iVar10);
      DAT_23003f08._2_1_ = (undefined1)((ushort)*(undefined2 *)(&DAT_230044f7 + iVar10) >> 8);
      DAT_23003f08._3_1_ = (&DAT_230044f9)[iVar10];
      return;
    }
  }
  DAT_23003efc = 5;
  return;
switchD_0e07ca20_caseD_d:
  uVar9 = (uint)DAT_23003f04;
  uVar1 = CONCAT11(DAT_23003f06._1_1_,(undefined1)DAT_23003f06);
  uVar2 = CONCAT11(DAT_23003f08._1_1_,(undefined1)DAT_23003f08);
  uVar3 = CONCAT11(DAT_23003f08._2_1_,DAT_23003f08._1_1_);
  uVar4 = CONCAT11(DAT_23003f08._3_1_,DAT_23003f08._2_1_);
  if (uVar9 != 0) {
    uVar11 = uVar9 - 1;
    iVar10 = uVar11 * 0xf4;
    *(uint *)(&DAT_230044f3 + iVar10) =
         CONCAT13((undefined1)DAT_23003f08,
                  CONCAT12(DAT_23003f06._1_1_,CONCAT11((undefined1)DAT_23003f06,DAT_23003f05)));
    *(undefined2 *)(&DAT_230044f7 + iVar10) = uVar3;
    uVar8 = (uint)DAT_23004476;
    (&DAT_230044f9)[iVar10] = uVar5;
    if (uVar8 != uVar9) goto LAB_0e07cb56;
  }
  DAT_23007716 = bVar6;
  DAT_23003f58 = uVar4;
  DAT_23003f5c = uVar2;
  DAT_23003f60 = uVar1;
  if (bVar6 == 0) {
    bVar6 = FUN_0e0976a0(0x40);
    FUN_0e097698(0x40,bVar6 | 0x80);
    uVar9 = (uint)DAT_23003f04;
  }
  else if (bVar6 == 1) {
    uVar9 = FUN_0e0976a0(0x40);
    FUN_0e097698(0x40,uVar9 & 0x7f);
    FUN_0e097698(0x77,(undefined1)DAT_23003f06);
    FUN_0e097698(0x78,DAT_23003f06._1_1_);
    FUN_0e097698(0x79,(undefined1)DAT_23003f08);
    FUN_0e097698(0x7a,DAT_23003f08._1_1_);
    FUN_0e097698(0x7b,DAT_23003f08._2_1_);
    FUN_0e097698(0x7c,DAT_23003f08._3_1_);
    uVar9 = (uint)DAT_23003f04;
  }
  if (uVar9 == 0) {
    return;
  }
  uVar11 = uVar9 - 1;
LAB_0e07cb56:
  FUN_0e07d4ac(8,uVar11 & 0xff);
  return;
}


