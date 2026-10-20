/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07b5e4. Types and names are inferred; NOT original source. */

void FUN_0e07b5e4(void)

{
  undefined1 *puVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined4 uVar12;
  undefined2 *puVar13;
  uint uVar14;
  undefined4 *puVar15;
  int iVar16;
  undefined4 uVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  
  uVar7 = DAT_23003f0c._1_1_;
  uVar6 = (undefined1)DAT_23003f08;
  uVar5 = DAT_23003f06._1_1_;
  cVar4 = (char)DAT_23003f06;
  cVar3 = DAT_23003f05;
  if (DAT_23003f03 < 0x99) {
    if (DAT_23003f03 < 0x82) {
      if (DAT_23003f03 == 0xc) {
        if (DAT_23004505 == DAT_23003f05) {
          iVar18 = 0;
        }
        else {
          puVar13 = &DAT_23004474;
          iVar22 = 1;
          do {
            iVar18 = iVar22;
            pcVar2 = (char *)((int)puVar13 + 0xa1);
            puVar13 = puVar13 + 8;
            iVar22 = iVar18 + 1;
          } while (*pcVar2 != DAT_23003f05);
        }
        uVar19 = (uint)((char)DAT_23003f06 != '\0');
        if (DAT_23003f04 == '\0') {
          (&DAT_23006660)[iVar18 * 0x10] = DAT_23003f05;
          uVar6 = (undefined1)DAT_23003f08;
          uVar7 = DAT_23003f08._1_1_;
          (&DAT_23006661)[iVar18 * 0x10] = cVar4;
          iVar18 = uVar19 + iVar18 * 0x10;
          uVar8 = DAT_23003f08._3_1_;
          (&DAT_23006660)[iVar18 + 2] = uVar5;
          (&DAT_23006660)[iVar18 + 4] = uVar6;
          uVar5 = DAT_23003f08._2_1_;
          uVar6 = (undefined1)DAT_23003f0c;
          (&DAT_23006660)[iVar18 + 6] = uVar7;
          uVar7 = DAT_23003f0c._1_1_;
          (&DAT_23006660)[iVar18 + 8] = uVar5;
          (&DAT_23006660)[iVar18 + 10] = uVar8;
          (&DAT_23006660)[iVar18 + 0xc] = uVar6;
          (&DAT_23006660)[iVar18 + 0xe] = uVar7;
          return;
        }
        uVar14 = (uint)(byte)(DAT_23003f04 - 1);
        uVar8 = DAT_23003f08._1_1_;
        if (DAT_23004476 == DAT_23003f04) {
          uVar8 = DAT_23003f08._2_1_;
          uVar10 = (undefined1)DAT_23003f0c;
          uVar9 = DAT_23003f08._3_1_;
          iVar20 = uVar14 * 0xf4 + iVar18 * 0x10;
          iVar22 = iVar18 * 0x10;
          iVar21 = uVar14 * 0xf4 + (iVar18 + 7) * 0x10;
          iVar16 = uVar19 + iVar20;
          *(undefined1 *)((int)&DAT_23004474 + iVar16 + 0x97) = DAT_23003f08._1_1_;
          *(undefined1 *)((int)&DAT_23004474 + iVar16 + 0x93) = uVar5;
          *(undefined1 *)((int)&DAT_23004474 + iVar16 + 0x99) = uVar8;
          *(undefined1 *)((int)&DAT_23004474 + iVar16 + 0x95) = uVar6;
          *(undefined1 *)((int)&DAT_23004474 + iVar16 + 0x9b) = uVar9;
          (&DAT_23004495)[iVar21] = cVar3;
          *(undefined1 *)((int)&DAT_23004474 + iVar16 + 0x9d) = uVar10;
          *(char *)(iVar21 + 0x23004496) = cVar4;
          *(undefined1 *)((int)&DAT_23004474 + iVar16 + 0x9f) = uVar7;
          *(undefined4 *)(&DAT_23006660 + iVar18 * 0x10) = *(undefined4 *)(&DAT_23004505 + iVar20);
          uVar12 = 8;
          *(undefined4 *)(iVar22 + 0x23006664) = *(undefined4 *)(iVar20 + 0x23004509);
          uVar17 = *(undefined4 *)(iVar20 + 0x23004511);
          *(undefined4 *)(iVar22 + 0x23006668) = *(undefined4 *)(iVar20 + 0x2300450d);
          *(undefined4 *)(iVar22 + 0x2300666c) = uVar17;
        }
        else {
          iVar22 = uVar14 * 0xf4 + (iVar18 + 7) * 0x10;
          (&DAT_23004495)[iVar22] = DAT_23003f05;
          uVar11 = DAT_23003f0c._1_1_;
          uVar6 = (undefined1)DAT_23003f08;
          iVar18 = uVar19 + uVar14 * 0xf4 + iVar18 * 0x10;
          uVar9 = DAT_23003f08._3_1_;
          uVar7 = DAT_23003f08._2_1_;
          uVar10 = (undefined1)DAT_23003f0c;
          *(undefined1 *)((int)&DAT_23004474 + iVar18 + 0x93) = uVar5;
          *(undefined1 *)((int)&DAT_23004474 + iVar18 + 0x9b) = uVar9;
          *(char *)(iVar22 + 0x23004496) = cVar4;
          uVar12 = 8;
          *(undefined1 *)((int)&DAT_23004474 + iVar18 + 0x95) = uVar6;
          *(undefined1 *)((int)&DAT_23004474 + iVar18 + 0x97) = uVar8;
          *(undefined1 *)((int)&DAT_23004474 + iVar18 + 0x99) = uVar7;
          *(undefined1 *)((int)&DAT_23004474 + iVar18 + 0x9d) = uVar10;
          *(undefined1 *)((int)&DAT_23004474 + iVar18 + 0x9f) = uVar11;
        }
      }
      else {
        if (DAT_23003f03 != 0x18) {
          if (DAT_23003f03 != 2) {
            DAT_23003efc = 5;
            return;
          }
          DAT_2300495b = CONCAT13(DAT_23003f06._1_1_,
                                  CONCAT12((char)DAT_23003f06,CONCAT11(DAT_23003f05,DAT_23003f04)));
          if (DAT_23003f01 == 2) {
            DAT_2300495b = CONCAT22(CONCAT11(DAT_23003f05,DAT_23003f04),
                                    CONCAT11(DAT_23003f05,DAT_23003f04));
          }
          FUN_0e07d4ac(2,DAT_23004477);
          return;
        }
        uVar12 = 2;
        uVar14 = (uint)DAT_23004477;
        DAT_2300495f = DAT_23003f04;
      }
      FUN_0e07d4ac(uVar12,uVar14);
      return;
    }
    switch(DAT_23003f03) {
    case 0x82:
      DAT_23003f04 = (char)DAT_2300495b;
      DAT_23003f05 = (char)((uint)DAT_2300495b >> 8);
      DAT_23003f06._0_1_ = (char)((uint)DAT_2300495b >> 0x10);
      DAT_23003f06._1_1_ = (undefined1)((uint)DAT_2300495b >> 0x18);
      return;
    case 0x84:
      puVar15 = (undefined4 *)&DAT_23003f04;
      puVar13 = &DAT_23004474;
      DAT_23003f04 = 8;
      do {
        puVar1 = (undefined1 *)((int)puVar13 + 0x91);
        puVar13 = puVar13 + 8;
        puVar15 = (undefined4 *)((int)puVar15 + 1);
        *(undefined1 *)puVar15 = *puVar1;
      } while (puVar15 != &DAT_23003f0c);
      return;
    case 0x8c:
      if (DAT_23004505 == DAT_23003f05) {
        iVar18 = 0;
      }
      else {
        puVar13 = &DAT_23004474;
        iVar22 = 1;
        do {
          iVar18 = iVar22;
          pcVar2 = (char *)((int)puVar13 + 0xa1);
          puVar13 = puVar13 + 8;
          iVar22 = iVar18 + 1;
        } while (*pcVar2 != DAT_23003f05);
      }
      if (DAT_23003f04 != '\0') {
        iVar16 = (uint)(byte)(DAT_23003f04 - 1) * 0xf4;
        iVar22 = (uint)((char)DAT_23003f06 != '\0') + iVar16 + iVar18 * 0x10;
        DAT_23003f05 = (char)*(undefined2 *)(&DAT_23004495 + iVar16 + (iVar18 + 7) * 0x10);
        DAT_23003f06._0_1_ =
             (char)((ushort)*(undefined2 *)(&DAT_23004495 + iVar16 + (iVar18 + 7) * 0x10) >> 8);
        DAT_23003f01 = 10;
        DAT_23003f06._1_1_ = *(undefined1 *)((int)&DAT_23004474 + iVar22 + 0x93);
        DAT_23003f08._0_1_ = *(undefined1 *)((int)&DAT_23004474 + iVar22 + 0x95);
        ram0x23003f09 =
             CONCAT13(*(undefined1 *)((int)&DAT_23004474 + iVar22 + 0x9d),
                      CONCAT12(*(undefined1 *)((int)&DAT_23004474 + iVar22 + 0x9b),
                               CONCAT11(*(undefined1 *)((int)&DAT_23004474 + iVar22 + 0x99),
                                        *(undefined1 *)((int)&DAT_23004474 + iVar22 + 0x97))));
        DAT_23003f0c._1_1_ = *(undefined1 *)((int)&DAT_23004474 + iVar22 + 0x9f);
        return;
      }
      iVar22 = (uint)((char)DAT_23003f06 != '\0') + iVar18 * 0x10;
      DAT_23003f01 = 10;
      DAT_23003f05 = (&DAT_23006660)[iVar18 * 0x10];
      DAT_23003f06._0_1_ = (&DAT_23006661)[iVar18 * 0x10];
      DAT_23003f06._1_1_ = (&DAT_23006660)[iVar22 + 2];
      DAT_23003f08._0_1_ = (&DAT_23006660)[iVar22 + 4];
      ram0x23003f09 =
           CONCAT13((&DAT_23006660)[iVar22 + 0xc],
                    CONCAT12((&DAT_23006660)[iVar22 + 10],
                             CONCAT11((&DAT_23006660)[iVar22 + 8],(&DAT_23006660)[iVar22 + 6])));
      DAT_23003f0c._1_1_ = (&DAT_23006660)[iVar22 + 0xe];
      return;
    case 0x8e:
      if (DAT_23003f04 != '\0') {
        uVar19 = DAT_23003f01 - 3;
        if ((int)uVar19 < 0) {
          uVar19 = DAT_23003f01 + 4;
        }
        FUN_0e07f810(DAT_23003f04,DAT_23003f05,(char)DAT_23003f06,0x23003f07,(uVar19 & 0x7ff) >> 3);
        return;
      }
      DAT_23003efc = 3;
      return;
    case 0x98:
      DAT_23003f04 = DAT_2300495f;
      return;
    }
  }
  DAT_23003efc = 5;
  return;
}


