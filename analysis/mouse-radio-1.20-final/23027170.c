/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23027170. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23027170(int param_1,byte param_2)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  undefined2 uVar5;
  bool bVar6;
  short sVar7;
  short sVar8;
  uint uVar9;
  char *pcVar10;
  char cVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  
  uVar12 = 0;
  uVar9 = (uint)param_2;
  DAT_230076c8 = 0;
  if (DAT_23004966 == '\x01') {
    if (uVar9 == 0) {
      if (DAT_23007724 == '\x03') {
        uVar12 = 1;
        goto LAB_23027262;
      }
      uVar9 = 2;
      uVar12 = 1;
    }
    else {
      if (uVar9 != 1) goto LAB_23027190;
      if (DAT_23007724 == '\x03') goto LAB_23027262;
      uVar9 = 1;
    }
  }
  else {
LAB_23027190:
    uVar12 = uVar9;
    if (DAT_23007724 == '\x03') {
      if (4 < uVar9) {
        if (uVar9 != 5) {
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
        DAT_230076d2 = DAT_230076d2 | 0x40;
        DAT_23007764 = 5;
        ram_candidate_23027290();
        return;
      }
LAB_23027262:
      uVar4 = (ushort)(1 << ((byte)(&DAT_2300045e)[uVar12 * 0x10] - 1 & 0xff));
      if (param_1 == 1) {
        DAT_230076b8 = uVar4 | DAT_230076b8;
      }
      else {
        DAT_230076b8 = DAT_230076b8 & ~uVar4;
      }
      DAT_230076c8 = 0;
      DAT_230076d2 = DAT_230076d2 | 1;
      return;
    }
    uVar9 = 1 << uVar9;
  }
  uVar3 = (undefined1)uVar12;
  uVar4 = (ushort)uVar9;
  if (DAT_2300776b == '\0') {
    iVar15 = uVar12 * 0x10;
    if (param_1 == 1) {
      DAT_230076bc = DAT_230076bc | uVar4;
      switch((&DAT_23006662)[uVar12 * 0x10]) {
      case 1:
        cVar11 = (&DAT_23006666)[iVar15];
        goto LAB_2302776c;
      case 2:
        iVar16 = 0;
        bVar1 = (&DAT_23006666)[iVar15];
        goto LAB_2302771a;
      default:
        goto code_r0x23027290;
      case 6:
        goto ram_candidate_230272ee;
      case 9:
        iVar15 = 0;
        goto LAB_23027658;
      case 10:
        iVar15 = 0;
        goto LAB_23027684;
      case 0xb:
        iVar15 = 0;
        goto LAB_23027664;
      case 0xc:
        goto ram_candidate_230275ce;
      case 0xd:
        iVar15 = 0;
        goto LAB_230275e2;
      case 0xe:
        iVar15 = 0;
        goto LAB_2302769c;
      }
    }
    DAT_230076bc = DAT_230076bc & ~uVar4;
    switch((&DAT_23006662)[uVar12 * 0x10]) {
    case 1:
      iVar16 = 0;
      cVar11 = (&DAT_23006666)[iVar15];
      goto LAB_2302756c;
    case 2:
      iVar16 = 0;
      uVar9 = (uint)(byte)(&DAT_23006666)[iVar15];
      goto LAB_23027526;
    default:
      goto code_r0x23027290;
    case 6:
ram_candidate_230272ee:
      iVar16 = 0;
      break;
    case 9:
      goto ram_candidate_230275a0;
    case 10:
      goto ram_candidate_230273ea;
    case 0xc:
      goto ram_candidate_23027400;
    case 0xd:
      iVar16 = 0;
      goto switchD_230271ee_caseD_d;
    case 0xe:
      iVar16 = 0;
      goto switchD_230271ee_caseD_e;
    }
  }
  else {
    if (param_1 != 1) {
      DAT_230076be = DAT_230076be & ~uVar4;
      if (DAT_230076ba == 0) {
LAB_230271d6:
        iVar16 = 1;
      }
      else {
        if (param_1 != 0) {
          switch((&DAT_23006663)[uVar12 * 0x10]) {
          case 1:
            iVar16 = 1;
            cVar11 = (&DAT_23006667)[uVar12 * 0x10];
            goto LAB_2302756c;
          case 2:
            iVar16 = 1;
            uVar9 = (uint)(byte)(&DAT_23006667)[uVar12 * 0x10];
            goto LAB_23027526;
          default:
            goto code_r0x23027290;
          case 6:
            goto ram_candidate_230275d8;
          case 9:
            goto ram_candidate_230275a0;
          case 10:
            goto ram_candidate_230273ea;
          case 0xc:
            goto ram_candidate_23027400;
          case 0xd:
            iVar16 = 1;
            goto switchD_230271ee_caseD_d;
          case 0xe:
            iVar16 = 1;
            goto switchD_230271ee_caseD_e;
          }
        }
        if (((int)(uint)DAT_230076bc >> uVar12 & 1U) == 0) goto LAB_230271d6;
        DAT_230076bc = ~uVar4 & DAT_230076bc;
        iVar16 = 0;
      }
      switch((&DAT_23006662)[uVar12 * 0x10 + iVar16]) {
      case 1:
        cVar11 = (&DAT_23006666)[uVar12 * 0x10 + iVar16];
LAB_2302756c:
        if (cVar11 == '\t') {
          DAT_230076c8 = 0;
          return;
        }
        if ((&DAT_2300450b)[uVar12 * 0x10 + iVar16] == '\n') {
          DAT_230076c8 = 0;
          return;
        }
        DAT_230076d2 = DAT_230076d2 | 1;
        DAT_230076b8 = DAT_230076b8 & ~(ushort)(1 << (uint)(byte)(cVar11 - 1));
        ram_candidate_23027290();
        return;
      case 2:
        uVar9 = (uint)(byte)(&DAT_23006666)[uVar12 * 0x10 + iVar16];
LAB_23027526:
        uVar14 = (uint)DAT_23006720;
        uVar13 = 0;
        bVar6 = false;
        pcVar10 = &DAT_2300675c;
        do {
          if (((int)uVar9 >> (uVar13 & 0xff)) << 0x1f < 0) {
            cVar11 = *pcVar10;
            if ((cVar11 == '\0') || (*pcVar10 = cVar11 + -1, cVar11 == '\x01')) {
              bVar6 = true;
              uVar14 = uVar14 & ~(1 << (uVar13 & 0xff));
            }
          }
          uVar13 = uVar13 + 1;
          pcVar10 = pcVar10 + 1;
        } while (uVar13 != 8);
        if (bVar6) {
          DAT_23006720 = (byte)uVar14;
        }
        iVar15 = 2;
        pcVar10 = &DAT_23006721;
        do {
          pcVar10 = pcVar10 + 1;
          if (*pcVar10 == (&DAT_23006668)[uVar12 * 0x10 + iVar16]) {
            (&DAT_23006720)[iVar15] = 0;
            DAT_230076d2 = DAT_230076d2 | 8;
            ram_candidate_23027290();
            return;
          }
          iVar15 = iVar15 + 1;
        } while (iVar15 != 8);
        ram_candidate_23027290();
        return;
      default:
        goto code_r0x23027290;
      case 6:
        goto switchD_230271ee_caseD_6;
      case 9:
ram_candidate_230275a0:
        DAT_23006701 = 0;
LAB_230275a2:
        DAT_230076d2 = DAT_230076d2 | 0x20;
        DAT_23006700 = 3;
        ram_candidate_23027290();
        return;
      case 10:
ram_candidate_230273ea:
        DAT_23006712 = 0;
        _DAT_23006710 = 2;
LAB_230273f2:
        DAT_230076d2 = DAT_230076d2 | 0x10;
        ram_candidate_23027290();
        return;
      case 0xc:
ram_candidate_23027400:
        uVar12 = (uint)DAT_230076ba & ~uVar9;
        if (uVar12 != 0) {
          DAT_230076ba = (short)uVar12;
          DAT_230076c8 = 0;
          return;
        }
        uVar12 = 0;
        DAT_230076ba = 0;
        do {
          if (((int)(uint)DAT_230076be >> (uVar12 & 0xff)) << 0x1f < 0) {
            FUN_23027170(0,uVar12);
          }
          uVar12 = uVar12 + 1;
        } while (uVar12 != 8);
        DAT_230076be = 0;
        DAT_2300776b = 0;
        ram_candidate_23027290();
        return;
      case 0xd:
switchD_230271ee_caseD_d:
        uVar9 = 0;
        bVar1 = (&DAT_23006666)[uVar12 * 0x10 + iVar16];
        pcVar10 = &DAT_23006754;
        iVar15 = (uVar12 + 0x18) * 2;
        do {
          if (((int)(uint)bVar1 >> (uVar9 & 0xff)) << 0x1f < 0) {
            cVar11 = *pcVar10;
            if ((cVar11 == '\0') || (*pcVar10 = cVar11 + -1, cVar11 == '\x01')) {
              (&DAT_230065a2)[iVar15] = (&DAT_230065a2)[iVar15] & ~(byte)(1 << (uVar9 & 0xff));
            }
          }
          uVar9 = uVar9 + 1;
          pcVar10 = pcVar10 + 1;
        } while (uVar9 != 8);
        iVar15 = (uVar12 + 8) * 2;
        (&DAT_230065d3)[uVar12 * 2] = 0;
        (&DAT_230065a1)[iVar15] = 0;
        (&DAT_230065a2)[iVar15] = 0;
        (&DAT_230065a9)[uVar12] = 3;
        ram_candidate_23027290();
        return;
      case 0xe:
switchD_230271ee_caseD_e:
        if ((byte)(&DAT_23006666)[uVar12 * 0x10 + iVar16] - 9 < 2) {
          (&DAT_2300662e)[uVar12] = 0;
        }
        else {
          DAT_2300662d = DAT_2300662d &
                         ~(byte)(1 << ((byte)(&DAT_23006666)[uVar12 * 0x10 + iVar16] - 1 & 0xff));
        }
        cVar11 = DAT_2300661c;
        iVar15 = (uVar12 + 0x2c) * 2;
        (&DAT_230065a4)[iVar15] = 0;
        (&DAT_230065a5)[iVar15] = 0;
        if (cVar11 == '\0') {
LAB_230274bc:
          (&DAT_230065f4)[uVar12] = 3;
          ram_candidate_23027290();
          return;
        }
        DAT_2300661c = cVar11 + -1;
        if (cVar11 == '\x01') {
          DAT_2300661c = '\0';
          goto LAB_230274bc;
        }
        goto code_r0x23027290;
      }
    }
    DAT_230076be = DAT_230076be | uVar4;
    switch((&DAT_23006663)[uVar12 * 0x10]) {
    case 1:
      cVar11 = (&DAT_23006667)[uVar12 * 0x10];
LAB_2302776c:
      if (cVar11 == '\t') {
        if (DAT_23007765 == '\0') {
          DAT_2300778a = DAT_2300778a + '\x01';
          ram_candidate_23027290();
          return;
        }
        if (0xaf63 < (ushort)DAT_23004a8c) {
          DAT_23004a8c._0_2_ = 0xaf64;
        }
        if (0xaf63 < DAT_23004a8c._2_2_) {
          DAT_23004a8c._2_2_ = 0xaf64;
        }
        sVar7 = (ushort)DAT_23004a8c + 100;
        uVar12 = (uint)DAT_23004477;
        sVar8 = DAT_23004a8c._2_2_ + 100;
        DAT_23004a8c._0_2_ = sVar7;
        DAT_23004a8c._2_2_ = sVar8;
        *(short *)(&DAT_230044ca + uVar12 * 0xf4) = sVar7;
        *(short *)(&DAT_230044cc + uVar12 * 0xf4) = sVar8;
      }
      else {
        if (cVar11 != '\n') {
          DAT_230076d2 = DAT_230076d2 | 1;
          DAT_230076b8 = (ushort)(1 << (uint)(byte)(cVar11 - 1)) | DAT_230076b8;
          ram_candidate_23027290();
          return;
        }
        if (DAT_23007765 == '\0') {
          DAT_2300778a = DAT_2300778a + -1;
          ram_candidate_23027290();
          return;
        }
        if ((ushort)DAT_23004a8c < 100) {
          DAT_23004a8c._0_2_ = 100;
        }
        if (DAT_23004a8c._2_2_ < 100) {
          DAT_23004a8c._2_2_ = 100;
        }
        sVar7 = (ushort)DAT_23004a8c - 100;
        uVar12 = (uint)DAT_23004477;
        sVar8 = DAT_23004a8c._2_2_ - 100;
        DAT_23004a8c._0_2_ = sVar7;
        DAT_23004a8c._2_2_ = sVar8;
        *(short *)(&DAT_230044ca + uVar12 * 0xf4) = sVar7;
        *(short *)(&DAT_230044cc + uVar12 * 0xf4) = sVar8;
      }
      thunk_FUN_0e08042c(sVar7,sVar8);
      thunk_FUN_0e07d4ac(8,DAT_23004477);
      return;
    case 2:
      iVar16 = 1;
      bVar1 = (&DAT_23006667)[uVar12 * 0x10];
LAB_2302771a:
      uVar9 = (uint)DAT_23006720;
      uVar13 = 0;
      bVar6 = false;
      pcVar10 = &DAT_2300675c;
      do {
        if (((int)(uint)bVar1 >> (uVar13 & 0xff)) << 0x1f < 0) {
          bVar6 = true;
          *pcVar10 = *pcVar10 + '\x01';
          uVar9 = uVar9 | 1 << (uVar13 & 0xff) & 0xffU;
        }
        uVar13 = uVar13 + 1;
        pcVar10 = pcVar10 + 1;
      } while (uVar13 != 8);
      if (bVar6) {
        DAT_23006720 = (byte)uVar9;
      }
      iVar15 = 2;
      pcVar10 = &DAT_23006721;
      do {
        pcVar10 = pcVar10 + 1;
        if (*pcVar10 == '\0') {
          (&DAT_23006720)[iVar15] = (&DAT_23006668)[uVar12 * 0x10 + iVar16];
          DAT_230076d2 = DAT_230076d2 | 8;
          ram_candidate_23027290();
          return;
        }
        iVar15 = iVar15 + 1;
      } while (iVar15 != 8);
      ram_candidate_23027290();
      return;
    default:
      goto code_r0x23027290;
    case 6:
ram_candidate_230275d8:
      iVar16 = 1;
      break;
    case 9:
      iVar15 = 1;
LAB_23027658:
      DAT_23006701 = (&DAT_23006666)[uVar12 * 0x10 + iVar15];
      goto LAB_230275a2;
    case 10:
      iVar15 = 1;
LAB_23027684:
      iVar15 = iVar15 + uVar12 * 0x10;
      DAT_23006712 = (&DAT_23006660)[iVar15 + 6];
      _DAT_23006710 = CONCAT11((&DAT_23006660)[iVar15 + 8],2);
      goto LAB_230273f2;
    case 0xb:
      iVar15 = 1;
LAB_23027664:
      DAT_23007769 = 1;
      DAT_23007768 = (undefined1)(1 << ((byte)(&DAT_23006666)[uVar12 * 0x10 + iVar15] - 1 & 0xff));
      DAT_23007767 = 0;
      ram_candidate_23027290();
      return;
    case 0xc:
ram_candidate_230275ce:
      DAT_230076ba = DAT_230076ba | uVar4;
      DAT_2300776b = 1;
      ram_candidate_23027290();
      return;
    case 0xd:
      iVar15 = 1;
LAB_230275e2:
      uVar9 = 0;
      bVar1 = (&DAT_23006666)[uVar12 * 0x10 + iVar15];
      iVar16 = (uVar12 + 0x18) * 2;
      pcVar10 = &DAT_23006754;
      DAT_230065a0 = uVar3;
      (&DAT_230065a2)[iVar16] = 0;
      do {
        if (((int)(uint)bVar1 >> (uVar9 & 0xff)) << 0x1f < 0) {
          bVar2 = (&DAT_230065a2)[iVar16];
          *pcVar10 = *pcVar10 + '\x01';
          (&DAT_230065a2)[iVar16] = (byte)(1 << (uVar9 & 0xff)) | bVar2;
        }
        uVar9 = uVar9 + 1;
        pcVar10 = pcVar10 + 1;
      } while (uVar9 != 8);
      iVar15 = iVar15 + uVar12 * 0x10;
      uVar3 = (&DAT_23006660)[iVar15 + 8];
      uVar5 = CONCAT11((&DAT_23006660)[iVar15 + 10],(&DAT_23006660)[iVar15 + 0xc]);
      *(undefined2 *)(&DAT_230065b1 + uVar12 * 2) = uVar5;
      (&DAT_230065c1)[uVar12] = uVar5;
      (&DAT_230065d3)[uVar12 * 2] = uVar3;
      (&DAT_230065a9)[uVar12] = 1;
      ram_candidate_23027290();
      return;
    case 0xe:
      iVar15 = 1;
LAB_2302769c:
      cVar11 = (&DAT_23006666)[uVar12 * 0x10 + iVar15];
      DAT_230065eb = uVar3;
      if (cVar11 == '\t') {
        (&DAT_2300662e)[uVar12] = 1;
      }
      else if (cVar11 == '\n') {
        (&DAT_2300662e)[uVar12] = 0xff;
      }
      else {
        DAT_2300662d = (byte)(1 << (uint)(byte)(cVar11 - 1)) | DAT_2300662d;
      }
      iVar15 = iVar15 + uVar12 * 0x10;
      uVar5 = CONCAT11((&DAT_23006660)[iVar15 + 8],(&DAT_23006660)[iVar15 + 10]);
      *(undefined2 *)(&DAT_230065fc + uVar12 * 2) = uVar5;
      DAT_2300661c = DAT_2300661c + '\x01';
      (&DAT_2300660c)[uVar12] = uVar5;
      (&DAT_230065f4)[uVar12] = 1;
      ram_candidate_23027290();
      return;
    }
  }
switchD_230271ee_caseD_6:
  iVar15 = uVar12 * 0x10;
  switch((&DAT_23006666)[iVar15 + iVar16]) {
  case 1:
    if (param_1 == 1) {
      iVar15 = DAT_23004a60._1_1_ - 1;
      if ((int)(DAT_23004a60._2_1_ + 1) <= (int)(DAT_23004a60._1_1_ - 1)) {
        iVar15 = DAT_23004a60._2_1_ + 1;
      }
      DAT_23004a60._2_1_ = (byte)iVar15;
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
      thunk_FUN_0e080328();
      thunk_FUN_0e07f0c4();
      return;
    }
    break;
  case 3:
    if (param_1 == 1) {
      DAT_23004a60._2_1_ = (&DAT_23006668)[iVar15 + iVar16] - 1;
      thunk_FUN_0e07f0c4();
      if (DAT_23004a60._2_1_ < 5) {
        thunk_FUN_0e080328();
        return;
      }
    }
    break;
  case 4:
    if (param_1 == 1) {
      DAT_23007765 = (char)param_1;
      ram_candidate_23027290();
      return;
    }
    DAT_23007765 = 0;
    ram_candidate_23027290();
    return;
  case 5:
    if (param_1 == 1) {
      iVar16 = iVar16 + iVar15;
      DAT_23004a8a = CONCAT11((&DAT_23006660)[iVar16 + 0xc],(&DAT_23006660)[iVar16 + 0xe]);
      DAT_23004a88 = CONCAT11((&DAT_23006660)[iVar16 + 8],(&DAT_23006660)[iVar16 + 10]);
      DAT_23007766 = (char)param_1;
      thunk_FUN_0e080454(DAT_23004a88);
      thunk_FUN_0e0803e4(2,0);
      return;
    }
    DAT_23007766 = 0;
    thunk_FUN_0e08042c((ushort)DAT_23004a8c,DAT_23004a8c._2_2_);
    thunk_FUN_0e0803e4(2,0);
    return;
  case 6:
    if ((&DAT_23006660)[iVar15] == '`') {
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
      uVar12 = (uint)DAT_23004a60._2_1_;
      DAT_23004a60._2_1_ = 0;
      if (uVar12 + 1 < (uint)DAT_23004a60._1_1_) {
        DAT_23004a60._2_1_ = (byte)(uVar12 + 1);
      }
      thunk_FUN_0e080328();
      thunk_FUN_0e07f0c4();
      return;
    }
    if (param_1 != 1) {
      DAT_230076c8 = 0;
      return;
    }
    uVar12 = DAT_23004a60._2_1_ + 1;
    if (DAT_23004a60._1_1_ <= uVar12) {
      DAT_23004a60._2_1_ = 0;
      goto LAB_230277f0;
    }
    goto LAB_230277ee;
  case 7:
    if (param_1 != 1) {
      DAT_230076c8 = 0;
      return;
    }
    uVar12 = (uint)DAT_23004a60._2_1_;
    if (uVar12 == 0) {
      uVar12 = (uint)DAT_23004a60._1_1_;
    }
    uVar12 = uVar12 - 1;
LAB_230277ee:
    DAT_23004a60._2_1_ = (byte)uVar12;
LAB_230277f0:
    thunk_FUN_0e080328();
    thunk_FUN_0e07f0c4();
    return;
  }
code_r0x23027290:
  return;
}


