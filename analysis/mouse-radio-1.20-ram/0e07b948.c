/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07b948. Types and names are inferred; NOT original source. */

void FUN_0e07b948(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  ushort uVar8;
  ushort uVar9;
  undefined2 uVar10;
  short sVar11;
  byte bVar12;
  uint uVar13;
  int iVar14;
  undefined4 uVar15;
  uint *puVar16;
  uint uVar17;
  int iVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  undefined1 *puVar24;
  uint uVar25;
  undefined4 *puVar26;
  uint uVar27;
  undefined4 *puVar28;
  uint uVar29;
  bool bVar30;
  
  bVar12 = (byte)DAT_23003f06;
  if (DAT_23003f03 < 7) {
    switch(DAT_23003f03) {
    case 0:
      if ((DAT_23003f04 != 0) && (DAT_23003f04 <= DAT_23004a60._1_1_)) {
        DAT_23004a60._2_1_ = DAT_23003f04 - 1;
        (&DAT_230044d4)[(uint)DAT_23004477 * 0xf4] = DAT_23004a60._2_1_;
        FUN_0e07f0c4();
        uVar25 = *(uint *)((int)&DAT_23004a60 + (uint)DAT_23004a60._2_1_ * 6 + 3);
        DAT_23004a8c = uVar25;
        *(uint *)(&DAT_230044ca + (uint)DAT_23004477 * 0xf4) = uVar25;
        FUN_0e08042c(uVar25 & 0xffff,uVar25 >> 0x10);
        uVar17 = (uint)DAT_23004477;
        goto LAB_0e07bd38;
      }
      break;
    case 2:
      if (DAT_23003f04 == 0) {
        if ((DAT_23003f05 != 0) && (DAT_23003f05 <= DAT_23004a60._1_1_)) {
          sVar11 = CONCAT11(DAT_23003f08._1_1_,(byte)DAT_23003f08);
          iVar23 = (uint)(byte)(DAT_23003f05 - 1) * 6;
          uVar8 = (ushort)DAT_23003f08._1_1_;
          *(ushort *)((int)&DAT_23004a60 + iVar23 + 3) =
               CONCAT11(DAT_23003f06._1_1_,(byte)DAT_23003f06) << 8 | (ushort)DAT_23003f06._1_1_;
          *(ushort *)((int)&DAT_23004a64 + iVar23 + 1) = sVar11 << 8 | uVar8;
          return;
        }
      }
      else if (DAT_23003f05 != 0) {
        uVar17 = (uint)(byte)(DAT_23003f04 - 1);
        if (DAT_23003f05 <= (byte)(&DAT_230044d3)[uVar17 * 0xf4]) {
          bVar12 = DAT_23003f05 - 1;
          iVar23 = uVar17 * 0xf4 + (uint)bVar12 * 6;
          uVar8 = CONCAT11(DAT_23003f06._1_1_,(byte)DAT_23003f06) << 8 | (ushort)DAT_23003f06._1_1_;
          uVar9 = CONCAT11(DAT_23003f08._1_1_,(byte)DAT_23003f08) << 8 | (ushort)DAT_23003f08._1_1_;
          bVar30 = DAT_23004476 == DAT_23003f04;
          *(ushort *)(&DAT_230044d5 + iVar23) = uVar8;
          *(ushort *)(&DAT_230044d7 + iVar23) = uVar9;
          if (bVar30) {
            *(uint *)((int)&DAT_23004a60 + (uint)bVar12 * 6 + 3) = CONCAT22(uVar9,uVar8);
          }
          goto LAB_0e07bd38;
        }
      }
      break;
    case 3:
      uVar25 = DAT_23003f05 - 1;
      if ((uVar25 & 0xff) < 5) {
        uVar17 = (uint)DAT_23003f04;
        if (uVar17 == 0) {
          puVar24 = &DAT_23003efc;
          iVar23 = 0;
          do {
            iVar18 = iVar23 * 6;
            *(ushort *)((int)&DAT_23004a60 + iVar18 + 3) = CONCAT11(puVar24[0xc],puVar24[0xd]);
            iVar23 = iVar23 + 1;
            *(ushort *)((int)&DAT_23004a64 + iVar18 + 1) = CONCAT11(puVar24[0xe],puVar24[0xf]);
            *(ushort *)((int)&DAT_23004a64 + iVar18 + 3) = CONCAT11(puVar24[0x10],puVar24[0x11]);
            puVar24 = puVar24 + 7;
          } while (iVar23 != 5);
          DAT_23004a60._2_1_ = (byte)uVar25;
          FUN_0e07f0c4();
          DAT_23004a8c = *(uint *)((int)&DAT_23004a60 + (uint)DAT_23004a60._2_1_ * 6 + 3);
          FUN_0e08042c(DAT_23004a8c & 0xffff,DAT_23004a8c >> 0x10);
          return;
        }
        if (DAT_23004476 == uVar17) {
          uVar25 = (uint)DAT_23004477;
          iVar23 = 0;
          puVar24 = &DAT_23003efc;
          puVar26 = (undefined4 *)(&DAT_230044d5 + uVar25 * 0xf4);
          puVar28 = (undefined4 *)((int)&DAT_23004a60 + 3);
          do {
            uVar15 = CONCAT22(CONCAT11(puVar24[0xe],puVar24[0xf]),
                              CONCAT11(puVar24[0xc],puVar24[0xd]));
            *puVar26 = uVar15;
            *puVar28 = uVar15;
            uVar4 = puVar24[0x10];
            uVar3 = puVar24[0x11];
            iVar18 = iVar23 + 1;
            *(ushort *)(&DAT_230044d9 + uVar25 * 0xf4 + iVar23 * 6) = CONCAT11(uVar4,uVar3);
            *(ushort *)((int)&DAT_23004a64 + iVar23 * 6 + 3) = CONCAT11(uVar4,uVar3);
            iVar23 = iVar18;
            puVar24 = puVar24 + 7;
            puVar26 = (undefined4 *)((int)puVar26 + 6);
            puVar28 = (undefined4 *)((int)puVar28 + 6);
          } while (iVar18 != 5);
          FUN_0e07f0c4();
          uVar17 = (uint)DAT_23004477;
          DAT_23004a60._2_1_ = DAT_23003f05 - 1;
          (&DAT_230044d4)[uVar17 * 0xf4] = DAT_23004a60._2_1_;
          uVar25 = *(uint *)((int)&DAT_23004a60 + (uint)DAT_23004a60._2_1_ * 6 + 3);
          DAT_23004a8c = uVar25;
          *(uint *)(&DAT_230044ca + uVar17 * 0xf4) = uVar25;
          FUN_0e08042c(uVar25 & 0xffff,uVar25 >> 0x10);
          uVar17 = (uint)DAT_23004477;
        }
        else {
          iVar23 = 0;
          iVar18 = (uVar17 - 1) * 0xf4;
          puVar24 = &DAT_23003efc;
          do {
            puVar2 = puVar24 + 0xc;
            puVar1 = puVar24 + 0xd;
            uVar6 = puVar24[0xf];
            uVar3 = puVar24[0xe];
            uVar4 = puVar24[0x11];
            uVar5 = puVar24[0x10];
            puVar24 = puVar24 + 7;
            iVar14 = iVar18 + iVar23 * 6;
            iVar23 = iVar23 + 1;
            *(ushort *)(&DAT_230044d5 + iVar14) = CONCAT11(*puVar2,*puVar1);
            *(ushort *)(&DAT_230044d7 + iVar14) = CONCAT11(uVar3,uVar6);
            *(ushort *)(&DAT_230044d9 + iVar14) = CONCAT11(uVar5,uVar4);
          } while (iVar23 != 5);
          (&DAT_230044d4)[iVar18] = (byte)uVar25;
          uVar17 = uVar17 - 1 & 0xff;
          *(undefined4 *)(&DAT_230044ca + iVar18) =
               *(undefined4 *)(&DAT_230044d5 + iVar18 + uVar25 * 6);
        }
        goto LAB_0e07bd38;
      }
      break;
    case 4:
      uVar25 = (uint)DAT_23003f04;
      uVar17 = (uint)DAT_23003f05;
      if (uVar25 == 0) {
        if ((uVar17 != 0) && (uVar17 <= DAT_23004a60._1_1_)) {
          DAT_23004a60._2_1_ = (byte)(uVar17 - 1);
          DAT_23004a8c = *(uint *)((int)&DAT_23004a60 + (uVar17 - 1 & 0xff) * 6 + 3);
          FUN_0e08042c(DAT_23004a8c & 0xffff,DAT_23004a8c >> 0x10);
LAB_0e07bcec:
          if ((DAT_23004476 != DAT_23003f04) && (DAT_23003f04 != 0)) {
            return;
          }
          goto LAB_0e07bcfa;
        }
      }
      else {
        if (DAT_23004476 != uVar25) {
          if (uVar17 != 0) {
            iVar23 = (uVar25 - 1) * 0xf4;
            if (uVar17 <= (byte)(&DAT_230044d3)[iVar23]) {
              (&DAT_230044d4)[iVar23] = (char)(uVar17 - 1);
              *(undefined4 *)(&DAT_230044ca + iVar23) =
                   *(undefined4 *)(&DAT_230044d5 + iVar23 + (uVar17 - 1) * 6);
              FUN_0e07d4ac(8,uVar25 - 1 & 0xff);
              goto LAB_0e07bcec;
            }
          }
          break;
        }
        if ((uVar17 != 0) &&
           (iVar23 = (uint)DAT_23004477 * 0xf4, uVar17 <= (byte)(&DAT_230044d3)[iVar23])) {
          DAT_23004a60._2_1_ = (byte)(uVar17 - 1);
          (&DAT_230044d4)[iVar23] = DAT_23004a60._2_1_;
          DAT_23004a8c = *(uint *)((int)&DAT_23004a60 + (uVar17 - 1 & 0xff) * 6 + 3);
          *(uint *)(&DAT_230044ca + iVar23) = DAT_23004a8c;
          FUN_0e08042c(DAT_23004a8c >> 0x10);
          FUN_0e07d4ac(8,DAT_23004477);
          goto LAB_0e07bcec;
        }
      }
      DAT_23003efc = 3;
LAB_0e07bcfa:
      FUN_0e07f0c4();
      return;
    case 5:
      uVar25 = (uint)DAT_23003f04;
      uVar8 = CONCAT11((byte)DAT_23003f06,DAT_23003f05) << 8 | (ushort)(byte)DAT_23003f06;
      uVar9 = CONCAT11((byte)DAT_23003f08,DAT_23003f06._1_1_) << 8 | (ushort)(byte)DAT_23003f08;
      if (uVar25 == 0) {
LAB_0e07bd42:
        DAT_23004a8c = CONCAT22(uVar9,uVar8);
        FUN_0e08042c();
        uVar17 = DAT_23003f04 - 1;
        if (DAT_23003f04 == 0) {
          return;
        }
      }
      else {
        uVar17 = uVar25 - 1;
        uVar21 = (uint)DAT_23004476;
        *(ushort *)(&DAT_230044ca + uVar17 * 0xf4) = uVar8;
        *(ushort *)(&DAT_230044cc + uVar17 * 0xf4) = uVar9;
        if (uVar21 == uVar25) goto LAB_0e07bd42;
      }
      uVar17 = uVar17 & 0xff;
LAB_0e07bd38:
      FUN_0e07d4ac(8,uVar17);
      return;
    case 6:
      uVar17 = (uint)DAT_23003f05;
      uVar21 = uVar17 - 1;
      uVar25 = uVar21 & 0xff;
      if (uVar25 < 5) {
        uVar27 = (uint)(byte)DAT_23003f06;
        uVar13 = uVar27 - 1 & 0xff;
        if (uVar13 < 5) {
          uVar22 = (uint)DAT_23003f04;
          if (uVar22 == 0) {
            puVar24 = &DAT_23003efc;
            DAT_23004a60._1_1_ = (byte)DAT_23003f06;
            uVar22 = 0;
            do {
              puVar2 = puVar24 + 0xc;
              puVar1 = puVar24 + 0xd;
              uVar6 = puVar24[0xf];
              uVar3 = puVar24[0xe];
              uVar4 = puVar24[0x11];
              uVar5 = puVar24[0x10];
              puVar24 = puVar24 + 7;
              uVar29 = uVar22 + 1;
              iVar23 = uVar22 * 6;
              *(ushort *)((int)&DAT_23004a60 + iVar23 + 3) = CONCAT11(*puVar2,*puVar1);
              *(ushort *)((int)&DAT_23004a64 + iVar23 + 1) = CONCAT11(uVar3,uVar6);
              *(ushort *)((int)&DAT_23004a64 + iVar23 + 3) = CONCAT11(uVar5,uVar4);
              uVar22 = uVar29;
            } while (uVar27 != uVar29);
            DAT_23004a60._2_1_ = (byte)uVar21;
            if (uVar27 < uVar17) {
              DAT_23004a60._2_1_ = (byte)(uVar27 - 1);
              DAT_23003f05 = bVar12;
              uVar25 = uVar13;
            }
            DAT_23004a8c = *(uint *)((int)&DAT_23004a60 + uVar25 * 6 + 3);
            FUN_0e08042c(DAT_23004a8c & 0xffff,DAT_23004a8c >> 0x10);
          }
          else if (DAT_23004476 == uVar22) {
            uVar25 = 0;
            uVar21 = (uint)DAT_23004477;
            puVar24 = &DAT_23003efc;
            (&DAT_230044d3)[uVar21 * 0xf4] = (byte)DAT_23003f06;
            do {
              puVar2 = puVar24 + 0xc;
              puVar1 = puVar24 + 0xd;
              uVar3 = puVar24[0xf];
              uVar4 = puVar24[0xe];
              uVar5 = puVar24[0x11];
              uVar6 = puVar24[0x10];
              puVar24 = puVar24 + 7;
              iVar23 = uVar21 * 0xf4 + uVar25 * 6;
              uVar25 = uVar25 + 1;
              *(ushort *)(&DAT_230044d5 + iVar23) = CONCAT11(*puVar2,*puVar1);
              *(ushort *)(&DAT_230044d7 + iVar23) = CONCAT11(uVar4,uVar3);
              *(ushort *)(&DAT_230044d9 + iVar23) = CONCAT11(uVar6,uVar5);
            } while (uVar27 != uVar25);
            if (uVar27 < uVar17) {
              DAT_23003f05 = bVar12;
            }
            iVar23 = uVar21 * 0xf4;
            bVar12 = DAT_23003f05 - 1;
            (&DAT_230044d4)[iVar23] = bVar12;
            puVar26 = (undefined4 *)&DAT_23004a5c;
            puVar28 = (undefined4 *)(&DAT_230044ce + iVar23);
            do {
              puVar20 = puVar28;
              puVar19 = puVar26;
              puVar28 = puVar20 + 4;
              *puVar19 = *puVar20;
              puVar19[1] = puVar20[1];
              puVar19[2] = puVar20[2];
              puVar19[3] = puVar20[3];
              puVar26 = puVar19 + 4;
            } while (puVar28 != (undefined4 *)(&DAT_230044ee + iVar23));
            puVar19[4] = *puVar28;
            puVar19[5] = puVar20[5];
            puVar19[6] = puVar20[6];
            uVar25 = *(uint *)((int)&DAT_23004a60 + (uint)bVar12 * 6 + 3);
            DAT_23004a8c = uVar25;
            *(uint *)(&DAT_230044ca + uVar21 * 0xf4) = uVar25;
            FUN_0e08042c(uVar25 & 0xffff,uVar25 >> 0x10);
            FUN_0e07d4ac(8,DAT_23004477);
          }
          else {
            uVar29 = 0;
            uVar22 = uVar22 - 1;
            puVar24 = &DAT_23003efc;
            (&DAT_230044d3)[uVar22 * 0xf4] = (byte)DAT_23003f06;
            do {
              puVar1 = puVar24 + 0xc;
              puVar2 = puVar24 + 0xd;
              uVar3 = puVar24[0xf];
              uVar4 = puVar24[0xe];
              uVar5 = puVar24[0x11];
              uVar6 = puVar24[0x10];
              puVar24 = puVar24 + 7;
              iVar23 = uVar22 * 0xf4 + uVar29 * 6;
              uVar29 = uVar29 + 1;
              *(ushort *)(&DAT_230044d5 + iVar23) = CONCAT11(*puVar1,*puVar2);
              *(ushort *)(&DAT_230044d7 + iVar23) = CONCAT11(uVar4,uVar3);
              *(ushort *)(&DAT_230044d9 + iVar23) = CONCAT11(uVar6,uVar5);
            } while (uVar27 != uVar29);
            if (uVar27 < uVar17) {
              DAT_23003f05 = bVar12;
              uVar21 = uVar27 - 1;
              uVar25 = uVar13;
            }
            iVar23 = uVar22 * 0xf4;
            (&DAT_230044d4)[iVar23] = (char)uVar25;
            *(undefined4 *)(&DAT_230044ca + iVar23) =
                 *(undefined4 *)(&DAT_230044d5 + iVar23 + uVar21 * 6);
            FUN_0e07d4ac(8,uVar22 & 0xff);
          }
          if ((DAT_23004476 != DAT_23003f04) && (DAT_23003f04 != 0)) {
            return;
          }
          FUN_0e07f0c4();
          if (DAT_23007723 != '\x01') {
            return;
          }
          if (DAT_2300777f == '\0') {
            return;
          }
          ram_candidate_23021278();
          return;
        }
      }
    }
    goto switchD_0e07b966_caseD_81;
  }
  if (6 < (DAT_23003f03 ^ 0x80)) goto switchD_0e07b966_caseD_81;
  switch(DAT_23003f03) {
  case 0x80:
    DAT_23003f04 = DAT_23004a60._2_1_ + 1;
    break;
  case 0x82:
    if (DAT_23003f04 == 0) {
      uVar25 = 0;
    }
    else {
      uVar25 = (uint)(byte)(DAT_23003f04 - 1);
    }
    if ((DAT_23003f05 != 0) && (DAT_23003f05 <= DAT_23004a60._1_1_)) {
      if (DAT_23003f04 == 0) {
        iVar23 = (uint)(byte)(DAT_23003f05 - 1) * 6;
        uVar10 = *(undefined2 *)((int)&DAT_23004a60 + iVar23 + 3);
        uVar7 = *(undefined2 *)((int)&DAT_23004a64 + iVar23 + 1);
      }
      else {
        iVar23 = uVar25 * 0xf4 + (uint)(byte)(DAT_23003f05 - 1) * 6;
        uVar10 = *(undefined2 *)(&DAT_230044d5 + iVar23);
        uVar7 = *(undefined2 *)(&DAT_230044d7 + iVar23);
      }
      DAT_23003f06._0_1_ = (char)((ushort)uVar10 >> 8);
      DAT_23003f06._1_1_ = (char)uVar10;
      DAT_23003f08._0_1_ = (char)((ushort)uVar7 >> 8);
      DAT_23003f08._1_1_ = (char)uVar7;
      DAT_23003f08._2_2_ = 0;
      return;
    }
  default:
switchD_0e07b966_caseD_81:
    DAT_23003efc = 3;
    break;
  case 0x83:
    if (DAT_23003f04 == 0) {
      uVar25 = 1;
      DAT_23003f06._0_1_ = 5;
      DAT_23003f05 = DAT_23004a60._2_1_ + 1;
      puVar16 = (uint *)((int)&DAT_23003f06 + 1);
      do {
        iVar23 = (uVar25 - 1) * 6;
        uVar8 = *(ushort *)((int)&DAT_23004a60 + iVar23 + 3);
        uVar9 = *(ushort *)((int)&DAT_23004a64 + iVar23 + 1);
        uVar10 = *(undefined2 *)((int)&DAT_23004a64 + iVar23 + 3);
        *(char *)((int)puVar16 + 6) = (char)uVar10;
        *(char *)((int)puVar16 + 5) = (char)((ushort)uVar10 >> 8);
        uVar17 = uVar25 & 0xff;
        *(char *)(puVar16 + 1) = (char)uVar9;
        uVar25 = uVar25 + 1;
        *puVar16 = uVar17 | (uint)(uVar8 >> 8) << 8 | (uVar8 & 0xff) << 0x10 |
                   (uint)(uVar9 >> 8) << 0x18;
        puVar16 = (uint *)((int)puVar16 + 7);
      } while (uVar25 != 6);
    }
    else {
      iVar23 = 1;
      DAT_23003f05 = (&DAT_230044d4)[(DAT_23003f04 - 1) * 0xf4] + 1;
      DAT_23003f06._0_1_ = 5;
      puVar24 = &DAT_23003efc;
      do {
        puVar24[0xb] = (char)iVar23;
        iVar18 = iVar23 + -1;
        iVar23 = iVar23 + 1;
        puVar24[0xc] = (char)((ushort)*(undefined2 *)
                                       (&DAT_230044d5 + (DAT_23003f04 - 1) * 0xf4 + iVar18 * 6) >> 8
                             );
        puVar24[0xd] = (char)*(undefined2 *)(&DAT_230044d5 + (DAT_23003f04 - 1) * 0xf4 + iVar18 * 6)
        ;
        puVar24[0xe] = (char)((ushort)*(undefined2 *)
                                       (&DAT_230044d7 + (DAT_23003f04 - 1) * 0xf4 + iVar18 * 6) >> 8
                             );
        puVar24[0xf] = (char)*(undefined2 *)(&DAT_230044d7 + (DAT_23003f04 - 1) * 0xf4 + iVar18 * 6)
        ;
        puVar24[0x10] =
             (char)((ushort)*(undefined2 *)(&DAT_230044d9 + (DAT_23003f04 - 1) * 0xf4 + iVar18 * 6)
                   >> 8);
        puVar24[0x11] =
             (char)*(undefined2 *)(&DAT_230044d9 + (DAT_23003f04 - 1) * 0xf4 + iVar18 * 6);
        puVar24 = puVar24 + 7;
      } while (iVar23 != 6);
    }
    break;
  case 0x84:
    if (DAT_23003f04 == 0) {
      DAT_23003f05 = DAT_23004a60._2_1_ + 1;
    }
    else {
      DAT_23003f05 = (&DAT_230044d4)[(DAT_23003f04 - 1) * 0xf4] + 1;
    }
    break;
  case 0x85:
    if (DAT_23003f04 == 0) {
      DAT_23003f06._0_1_ = (byte)DAT_23004a8c;
      DAT_23003f05 = (byte)(DAT_23004a8c >> 8);
      DAT_23003f06._1_1_ = (byte)(DAT_23004a8c >> 0x18);
      DAT_23003f08._0_1_ = (byte)(DAT_23004a8c >> 0x10);
    }
    else {
      iVar23 = (DAT_23003f04 - 1) * 0xf4;
      DAT_23003f06._0_1_ = (byte)*(undefined2 *)(&DAT_230044ca + iVar23);
      DAT_23003f05 = (byte)((ushort)*(undefined2 *)(&DAT_230044ca + iVar23) >> 8);
      DAT_23003f06._1_1_ = (byte)((ushort)*(undefined2 *)(&DAT_230044cc + iVar23) >> 8);
      DAT_23003f08._0_1_ = (byte)*(undefined2 *)(&DAT_230044cc + iVar23);
    }
    break;
  case 0x86:
    if (DAT_23003f04 == 0) {
      DAT_23003f06._0_1_ = DAT_23004a60._1_1_;
      uVar25 = (uint)DAT_23004a60._1_1_;
      DAT_23003f05 = DAT_23004a60._2_1_ + 1;
      if (uVar25 != 0) {
        puVar16 = (uint *)((int)&DAT_23003f06 + 1);
        uVar17 = 0;
        do {
          uVar21 = uVar17 + 1;
          iVar23 = uVar17 * 6;
          uVar8 = *(ushort *)((int)&DAT_23004a60 + iVar23 + 3);
          uVar9 = *(ushort *)((int)&DAT_23004a64 + iVar23 + 1);
          uVar10 = *(undefined2 *)((int)&DAT_23004a64 + iVar23 + 3);
          *(char *)(puVar16 + 1) = (char)uVar9;
          *(char *)((int)puVar16 + 6) = (char)uVar10;
          *(char *)((int)puVar16 + 5) = (char)((ushort)uVar10 >> 8);
          *puVar16 = uVar21 & 0xff | (uint)(uVar8 >> 8) << 8 | (uVar8 & 0xff) << 0x10 |
                     (uint)(uVar9 >> 8) << 0x18;
          puVar16 = (uint *)((int)puVar16 + 7);
          uVar17 = uVar21;
        } while (uVar25 != uVar21);
      }
    }
    else {
      iVar23 = (DAT_23003f04 - 1) * 0xf4;
      DAT_23003f06._0_1_ = (&DAT_230044d3)[iVar23];
      DAT_23003f05 = (&DAT_230044d4)[iVar23] + 1;
      if ((byte)DAT_23003f06 != 0) {
        uVar17 = 3;
        uVar25 = 0;
        do {
          uVar21 = uVar25 + 1 & 0xff;
          (&DAT_23003f04)[uVar17] = (char)(uVar25 + 1);
          (&DAT_23003f04)[uVar17 + 1 & 0xff] =
               (char)((ushort)*(undefined2 *)
                               (&DAT_230044d5 + (DAT_23003f04 - 1) * 0xf4 + uVar25 * 6) >> 8);
          (&DAT_23003f04)[uVar17 + 2 & 0xff] =
               (char)*(undefined2 *)(&DAT_230044d5 + (DAT_23003f04 - 1) * 0xf4 + uVar25 * 6);
          (&DAT_23003f04)[uVar17 + 3 & 0xff] =
               (char)((ushort)*(undefined2 *)
                               (&DAT_230044d7 + (DAT_23003f04 - 1) * 0xf4 + uVar25 * 6) >> 8);
          (&DAT_23003f04)[uVar21 * 7 & 0xff] =
               (char)*(undefined2 *)(&DAT_230044d7 + (DAT_23003f04 - 1) * 0xf4 + uVar25 * 6);
          (&DAT_23003f04)[uVar17 + 5 & 0xff] =
               (char)((ushort)*(undefined2 *)
                               (&DAT_230044d9 + (DAT_23003f04 - 1) * 0xf4 + uVar25 * 6) >> 8);
          (&DAT_23003f04)[uVar17 + 6 & 0xff] =
               (char)*(undefined2 *)(&DAT_230044d9 + (DAT_23003f04 - 1) * 0xf4 + uVar25 * 6);
          uVar17 = uVar17 + 7 & 0xff;
          uVar25 = uVar21;
        } while (uVar21 < (byte)(&DAT_230044d3)[(DAT_23003f04 - 1) * 0xf4]);
      }
    }
  }
  return;
}


