/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07b76c. Types and names are inferred; NOT original source. */

void FUN_0e07b76c(void)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  char cVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 *puVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  undefined4 uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  
  iVar13 = DAT_0e07bac8;
  iVar20 = DAT_0e07b9fc;
  iVar17 = DAT_0e07b9f8;
  puVar12 = DAT_0e07b9f4;
  uVar18 = (uint)(byte)DAT_0e07b9f4[7];
  if (uVar18 < 0x99) {
    if (uVar18 < 0x82) {
      if (uVar18 == 0xc) {
        cVar2 = DAT_0e07b9f4[9];
        if (*(char *)(DAT_0e07b9f8 + 0x91) == cVar2) {
          iVar20 = 0;
        }
        else {
          iVar15 = DAT_0e07b9f8;
          iVar21 = 1;
          do {
            iVar20 = iVar21;
            pcVar1 = (char *)(iVar15 + 0xa1);
            iVar15 = iVar15 + 0x10;
            iVar21 = iVar20 + 1;
          } while (*pcVar1 != cVar2);
        }
        cVar9 = DAT_0e07b9f4[10];
        cVar3 = DAT_0e07b9f4[8];
        uVar18 = (uint)(cVar9 != '\0');
        if (cVar3 == '\0') {
          uVar4 = DAT_0e07b9f4[0xb];
          iVar17 = DAT_0e07ba04 + iVar20 * 0x10;
          *(char *)(DAT_0e07ba04 + iVar20 * 0x10) = cVar2;
          uVar5 = puVar12[0xc];
          uVar6 = puVar12[0xd];
          *(char *)(iVar17 + 1) = cVar9;
          iVar17 = iVar17 + uVar18;
          uVar7 = puVar12[0xf];
          *(undefined1 *)(iVar17 + 2) = uVar4;
          *(undefined1 *)(iVar17 + 4) = uVar5;
          uVar4 = puVar12[0xe];
          uVar5 = puVar12[0x10];
          *(undefined1 *)(iVar17 + 6) = uVar6;
          uVar6 = puVar12[0x11];
          *(undefined1 *)(iVar17 + 8) = uVar4;
          *(undefined1 *)(iVar17 + 10) = uVar7;
          *(undefined1 *)(iVar17 + 0xc) = uVar5;
          *(undefined1 *)(iVar17 + 0xe) = uVar6;
          return;
        }
        uVar16 = (uint)(byte)(cVar3 - 1);
        if (*(char *)(DAT_0e07b9f8 + 2) == cVar3) {
          uVar7 = DAT_0e07b9f4[0xe];
          uVar4 = DAT_0e07b9f4[0x10];
          uVar8 = DAT_0e07b9f4[0xb];
          uVar10 = DAT_0e07b9f4[0xc];
          uVar5 = DAT_0e07b9f4[0xf];
          uVar6 = DAT_0e07b9f4[0x11];
          iVar21 = uVar16 * 0xf4 + iVar20 * 0x10;
          iVar23 = DAT_0e07bac8 + iVar20 * 0x10;
          iVar15 = iVar21 + DAT_0e07b9f8 + uVar18;
          iVar22 = uVar16 * 0xf4 + (iVar20 + 7) * 0x10 + DAT_0e07b9f8;
          *(undefined1 *)(iVar15 + 0x97) = DAT_0e07b9f4[0xd];
          *(undefined1 *)(iVar15 + 0x93) = uVar8;
          *(undefined1 *)(iVar15 + 0x99) = uVar7;
          *(undefined1 *)(iVar15 + 0x95) = uVar10;
          *(undefined1 *)(iVar15 + 0x9b) = uVar5;
          *(char *)(iVar22 + 0x21) = cVar2;
          *(undefined1 *)(iVar15 + 0x9d) = uVar4;
          *(char *)(iVar22 + 0x22) = cVar9;
          *(undefined1 *)(iVar15 + 0x9f) = uVar6;
          iVar21 = iVar21 + 0x91;
          iVar15 = iVar17 + iVar21;
          *(undefined4 *)(iVar13 + iVar20 * 0x10) = *(undefined4 *)(iVar17 + iVar21);
          uVar14 = 8;
          *(undefined4 *)(iVar23 + 4) = *(undefined4 *)(iVar15 + 4);
          uVar19 = *(undefined4 *)(iVar15 + 0xc);
          *(undefined4 *)(iVar23 + 8) = *(undefined4 *)(iVar15 + 8);
          *(undefined4 *)(iVar23 + 0xc) = uVar19;
        }
        else {
          uVar4 = DAT_0e07b9f4[0xb];
          uVar5 = DAT_0e07b9f4[0xd];
          iVar17 = uVar16 * 0xf4 + iVar20 * 0x10 + DAT_0e07b9f8;
          iVar20 = DAT_0e07b9f8 + uVar16 * 0xf4 + (iVar20 + 7) * 0x10;
          *(char *)(iVar20 + 0x21) = cVar2;
          iVar17 = iVar17 + uVar18;
          uVar6 = puVar12[0xf];
          uVar10 = puVar12[0xc];
          uVar7 = puVar12[0xe];
          uVar8 = puVar12[0x10];
          uVar11 = puVar12[0x11];
          *(undefined1 *)(iVar17 + 0x93) = uVar4;
          *(undefined1 *)(iVar17 + 0x9b) = uVar6;
          *(char *)(iVar20 + 0x22) = cVar9;
          uVar14 = 8;
          *(undefined1 *)(iVar17 + 0x95) = uVar10;
          *(undefined1 *)(iVar17 + 0x97) = uVar5;
          *(undefined1 *)(iVar17 + 0x99) = uVar7;
          *(undefined1 *)(iVar17 + 0x9d) = uVar8;
          *(undefined1 *)(iVar17 + 0x9f) = uVar11;
        }
      }
      else {
        if (uVar18 != 0x18) {
          if (uVar18 == 2) {
            cVar2 = DAT_0e07b9f4[5];
            *(undefined4 *)(DAT_0e07b9fc + 3) = *(undefined4 *)(DAT_0e07b9f4 + 8);
            if (cVar2 == '\x02') {
              *(undefined2 *)(iVar20 + 5) = *(undefined2 *)(puVar12 + 8);
            }
            FUN_0e07d638(2,*(undefined1 *)(DAT_0e07b9f8 + 3));
            return;
          }
          goto switchD_0e07b784_caseD_83;
        }
        uVar14 = 2;
        uVar16 = (uint)*(byte *)(DAT_0e07b9f8 + 3);
        *(undefined1 *)(DAT_0e07b9fc + 7) = DAT_0e07b9f4[8];
      }
      FUN_0e07d638(uVar14,uVar16);
      return;
    }
    if (uVar18 - 0x82 < 0x17) {
                    /* WARNING: Could not recover jumptable at 0x0e07b784. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0e07b784::switchdataD_0e07b788 + (uint)*(byte *)(uVar18 + 0xe07b706) * 2))
                ();
      return;
    }
  }
switchD_0e07b784_caseD_83:
  *DAT_0e07b9f4 = 5;
  return;
}


