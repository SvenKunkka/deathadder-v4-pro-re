/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07390c. Types and names are inferred; NOT original source. */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e07390c(int param_1,byte param_2)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  uVar7 = 0;
  uVar5 = (uint)param_2;
  DAT_230076c8 = 0;
  if (DAT_23004966 == '\x01') {
    if (uVar5 == 0) {
      if (DAT_23007724 == '\x03') {
        uVar7 = 1;
        goto LAB_0e0739fe;
      }
      uVar5 = 2;
      uVar7 = 1;
    }
    else {
      if (uVar5 != 1) goto LAB_0e07392c;
      if (DAT_23007724 == '\x03') goto LAB_0e0739fe;
      uVar5 = 1;
    }
  }
  else {
LAB_0e07392c:
    uVar7 = uVar5;
    if (DAT_23007724 == '\x03') {
      if (4 < uVar5) {
        if (uVar5 != 5) {
          DAT_230076c8 = 0;
          return;
        }
        if (DAT_230066b0 != '`') {
          DAT_230076c8 = 0;
          return;
        }
        if (param_1 != 0) {
          DAT_230076c8 = 0;
          return;
        }
        if (DAT_230077a2 == '\0') {
          if ((DAT_2300777c == '\0') && (DAT_2300777b == '\0')) {
            DAT_230076c8 = 0;
            return;
          }
          if (DAT_2300777d != '\0') {
            DAT_230076c8 = 0;
            return;
          }
        }
        DAT_230066f0._0_2_ = 0x5204;
        DAT_230076c8 = 0;
        DAT_230076d2 = DAT_230076d2 | 0x40;
        DAT_23007764 = 5;
        return;
      }
LAB_0e0739fe:
      uVar3 = (ushort)(1 << ((byte)(&DAT_2300045e)[uVar7 * 0x10] - 1 & 0xff));
      if (param_1 == 1) {
        DAT_230076b8 = uVar3 | DAT_230076b8;
      }
      else {
        DAT_230076b8 = DAT_230076b8 & ~uVar3;
      }
      DAT_230076c8 = 0;
      DAT_230076d2 = DAT_230076d2 | 1;
      return;
    }
    uVar5 = 1 << uVar5;
  }
  uVar3 = (ushort)uVar5;
  if (DAT_2300776b != '\0') {
    if (param_1 == 1) {
      DAT_230076be = DAT_230076be | uVar3;
      switch((&DAT_23006663)[uVar7 * 0x10]) {
      case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 2:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 3:
      case 4:
      case 5:
      case 7:
      case 8:
switchD_0e0741a6_caseD_3:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 6:
switchD_0e0741a6_caseD_6:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 9:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 10:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xb:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xc:
        goto switchD_0e073ade_caseD_c;
      case 0xd:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xe:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      default:
        DAT_230076c8 = 0;
        return;
      }
    }
    DAT_230076be = DAT_230076be & ~uVar3;
    if (DAT_230076ba == 0) {
LAB_0e073972:
      iVar10 = 1;
    }
    else {
      if (param_1 != 0) {
        switch((&DAT_23006663)[uVar7 * 0x10]) {
        case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 2:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 3:
        case 4:
        case 5:
        case 7:
        case 8:
        case 0xb:
          goto switchD_0e0741a6_caseD_3;
        case 6:
          goto switchD_0e0741a6_caseD_6;
        case 9:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 10:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0xc:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0xd:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0xe:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        default:
          DAT_230076c8 = 0;
          return;
        }
      }
      if (((int)(uint)DAT_230076bc >> uVar7 & 1U) == 0) goto LAB_0e073972;
      DAT_230076bc = ~uVar3 & DAT_230076bc;
      iVar10 = 0;
    }
    uVar9 = (byte)(&DAT_23006662)[uVar7 * 0x10 + iVar10] - 1;
    switch((byte)(&DAT_23006662)[uVar7 * 0x10 + iVar10] - 1) {
    case 0:
      cVar1 = (&DAT_23006666)[uVar7 * 0x10 + iVar10];
LAB_0e073d08:
      if (cVar1 == '\t') {
        DAT_230076c8 = 0;
        return;
      }
      if ((&DAT_2300450b)[uVar7 * 0x10 + iVar10] == '\n') {
        DAT_230076c8 = 0;
        return;
      }
      DAT_230076b8 = DAT_230076b8 & ~(ushort)(1 << (uint)(byte)(cVar1 - 1));
      DAT_230076c8 = 0;
      DAT_230076d2 = DAT_230076d2 | 1;
      return;
    case 1:
      bVar2 = (&DAT_23006666)[uVar7 * 0x10 + iVar10];
LAB_0e073cc2:
      uVar9 = (uint)DAT_23006720;
      uVar5 = 0;
      bVar4 = false;
      pcVar6 = &DAT_2300675c;
      do {
        if (((int)(uint)bVar2 >> (uVar5 & 0xff)) << 0x1f < 0) {
          cVar1 = *pcVar6;
          if ((cVar1 == '\0') || (*pcVar6 = cVar1 + -1, cVar1 == '\x01')) {
            bVar4 = true;
            uVar9 = uVar9 & ~(1 << (uVar5 & 0xff));
          }
        }
        uVar5 = uVar5 + 1;
        pcVar6 = pcVar6 + 1;
      } while (uVar5 != 8);
      if (bVar4) {
        DAT_23006720 = (byte)uVar9;
      }
      iVar8 = 2;
      pcVar6 = &DAT_23006721;
      do {
        pcVar6 = pcVar6 + 1;
        if (*pcVar6 == *(char *)(uVar7 * 0x10 + iVar10 + 0x23006668)) {
          (&DAT_23006720)[iVar8] = 0;
          DAT_230076d2 = DAT_230076d2 | 8;
          return;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 != 8);
      return;
    default:
      DAT_230076c8 = 0;
      return;
    case 5:
      goto switchD_0e07398a_caseD_5;
    case 8:
switchD_0e07398a_caseD_8:
      DAT_23006700 = 3;
      DAT_23006701 = 0;
      DAT_230076c8 = 0;
      DAT_230076d2 = DAT_230076d2 | 0x20;
      return;
    case 9:
switchD_0e07398a_caseD_9:
      _DAT_23006710 = 2;
      DAT_23006712 = 0;
      DAT_230076c8 = 0;
      DAT_230076d2 = DAT_230076d2 | 0x10;
      return;
    case 0xb:
switchD_0e07398a_caseD_b:
      uVar7 = (uint)DAT_230076ba & ~uVar5;
      if (uVar7 != 0) {
        DAT_230076ba = (short)uVar7;
        DAT_230076c8 = 0;
        return;
      }
      uVar7 = 0;
      DAT_230076ba = 0;
      do {
        if (((int)(uint)DAT_230076be >> (uVar7 & 0xff)) << 0x1f < 0) {
          FUN_0e07390c(0,uVar7);
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 != 8);
      DAT_230076be = 0;
      DAT_2300776b = 0;
      return;
    case 0xc:
switchD_0e07398a_caseD_c:
      uVar5 = 0;
      bVar2 = (&DAT_23006666)[uVar7 * 0x10 + iVar10];
      pcVar6 = &DAT_23006754;
      iVar10 = (uVar7 + 0x18) * 2;
      do {
        if (((int)(uint)bVar2 >> (uVar5 & 0xff)) << 0x1f < 0) {
          cVar1 = *pcVar6;
          if ((cVar1 == '\0') || (*pcVar6 = cVar1 + -1, cVar1 == '\x01')) {
            (&DAT_230065a2)[iVar10] = (&DAT_230065a2)[iVar10] & ~(byte)(1 << (uVar5 & 0xff));
          }
        }
        uVar5 = uVar5 + 1;
        pcVar6 = pcVar6 + 1;
      } while (uVar5 != 8);
      iVar10 = (uVar7 + 8) * 2;
      (&DAT_230065d3)[uVar7 * 2] = 0;
      (&DAT_230065a1)[iVar10] = 0;
      (&DAT_230065a2)[iVar10] = 0;
      (&DAT_230065a9)[uVar7] = 3;
      return;
    case 0xd:
switchD_0e07398a_caseD_d:
      if ((byte)(&DAT_23006666)[uVar7 * 0x10 + iVar10] - 9 < 2) {
        (&DAT_2300662e)[uVar7] = 0;
      }
      else {
        DAT_2300662d = DAT_2300662d &
                       ~(byte)(1 << ((byte)(&DAT_23006666)[uVar7 * 0x10 + iVar10] - 1 & 0xff));
      }
      cVar1 = DAT_2300661c;
      iVar10 = (uVar7 + 0x2c) * 2;
      (&DAT_230065a4)[iVar10] = 0;
      (&DAT_230065a5)[iVar10] = 0;
      if ((cVar1 != '\0') && (DAT_2300661c = cVar1 + -1, cVar1 != '\x01')) {
        return;
      }
      (&DAT_230065f4)[uVar7] = 3;
      return;
    }
  }
  if (param_1 == 1) {
    DAT_230076bc = DAT_230076bc | uVar3;
    switch((&DAT_23006662)[uVar7 * 0x10]) {
    case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 2:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
      goto switchD_0e0741a6_caseD_3;
    case 6:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 9:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 10:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0xb:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0xc:
switchD_0e073ade_caseD_c:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0xd:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0xe:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    default:
      DAT_230076c8 = 0;
      return;
    }
  }
  DAT_230076bc = DAT_230076bc & ~uVar3;
  switch((&DAT_23006662)[uVar7 * 0x10]) {
  case 1:
    iVar10 = 0;
    cVar1 = (&DAT_23006666)[uVar7 * 0x10];
    goto LAB_0e073d08;
  case 2:
    iVar10 = 0;
    bVar2 = (&DAT_23006666)[uVar7 * 0x10];
    goto LAB_0e073cc2;
  default:
    DAT_230076c8 = 0;
    return;
  case 6:
    iVar10 = 0;
    uVar9 = uVar7;
    break;
  case 9:
    goto switchD_0e07398a_caseD_8;
  case 10:
    goto switchD_0e07398a_caseD_9;
  case 0xc:
    goto switchD_0e07398a_caseD_b;
  case 0xd:
    iVar10 = 0;
    goto switchD_0e07398a_caseD_c;
  case 0xe:
    iVar10 = 0;
    goto switchD_0e07398a_caseD_d;
  }
switchD_0e07398a_caseD_5:
  iVar8 = uVar7 * 0x10;
  switch((&DAT_23006666)[iVar8 + iVar10]) {
  case 1:
    if (param_1 == 1) {
      iVar10 = DAT_23004a60._1_1_ - 1;
      if ((int)(DAT_23004a60._2_1_ + 1) <= (int)(DAT_23004a60._1_1_ - 1)) {
        iVar10 = DAT_23004a60._2_1_ + 1;
      }
      DAT_23004a60._2_1_ = (byte)iVar10;
      thunk_FUN_0e080328();
      thunk_FUN_0e07f0c4();
      return;
    }
    break;
  case 2:
    if (param_1 == 1) {
      if (DAT_23004a60._2_1_ == 0) {
        DAT_23004a60._2_1_ = 1;
      }
      DAT_23004a60._2_1_ = DAT_23004a60._2_1_ - 1;
      thunk_FUN_0e080328(1,uVar9);
      thunk_FUN_0e07f0c4();
      return;
    }
    break;
  case 3:
    if (param_1 == 1) {
      DAT_23004a60._2_1_ = *(char *)(iVar8 + iVar10 + 0x23006668) - 1;
      thunk_FUN_0e07f0c4();
      if (DAT_23004a60._2_1_ < 5) {
        thunk_FUN_0e080328();
        return;
      }
    }
    break;
  case 4:
    if (param_1 == 1) {
      DAT_23007765 = 1;
    }
    else {
      DAT_23007765 = 0;
    }
    break;
  case 5:
    if (param_1 == 1) {
      iVar10 = iVar10 + iVar8;
      DAT_23004a8a = CONCAT11((&DAT_23006660)[iVar10 + 0xc],(&DAT_23006660)[iVar10 + 0xe]);
      DAT_23004a88 = CONCAT11((&DAT_23006660)[iVar10 + 8],(&DAT_23006660)[iVar10 + 10]);
      DAT_23007766 = (char)param_1;
      thunk_FUN_0e080454(DAT_23004a88);
      thunk_FUN_0e0803e4(2,0);
      return;
    }
    DAT_23007766 = 0;
    thunk_FUN_0e08042c((undefined2)DAT_23004a8c,DAT_23004a8c._2_2_);
    thunk_FUN_0e0803e4(2,0);
    return;
  case 6:
    if ((&DAT_23006660)[iVar8] == '`') {
      if (param_1 != 0) {
        DAT_230076c8 = 0;
        return;
      }
      if (DAT_230077a2 == '\0') {
        if ((DAT_2300777c == '\0') && (DAT_2300777b == '\0')) {
          DAT_230076c8 = 0;
          return;
        }
        if (DAT_2300777d != '\0') {
          DAT_230076c8 = 0;
          return;
        }
      }
      uVar7 = (uint)DAT_23004a60._2_1_;
      DAT_23004a60._2_1_ = 0;
      if (uVar7 + 1 < (uint)DAT_23004a60._1_1_) {
        DAT_23004a60._2_1_ = (byte)(uVar7 + 1);
      }
      thunk_FUN_0e080328();
      thunk_FUN_0e07f0c4();
      return;
    }
    if (param_1 != 1) {
      DAT_230076c8 = 0;
      return;
    }
    uVar9 = (uint)DAT_23004a60._1_1_;
    uVar7 = DAT_23004a60._2_1_ + 1;
    if (uVar9 <= uVar7) {
      DAT_23004a60._2_1_ = 0;
      goto LAB_0e073f8c;
    }
    goto LAB_0e073f8a;
  case 7:
    if (param_1 != 1) {
      DAT_230076c8 = 0;
      return;
    }
    uVar7 = (uint)DAT_23004a60._2_1_;
    if (uVar7 == 0) {
      uVar7 = (uint)DAT_23004a60._1_1_;
    }
    uVar7 = uVar7 - 1;
LAB_0e073f8a:
    DAT_23004a60._2_1_ = (byte)uVar7;
LAB_0e073f8c:
    thunk_FUN_0e080328(param_1,uVar9);
    thunk_FUN_0e07f0c4();
    return;
  }
  return;
}


