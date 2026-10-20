/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0ffde4. Types and names are inferred; NOT original source. */

int FUN_1c0ffde4(undefined4 param_1)

{
  char *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  char cVar6;
  undefined4 uVar7;
  undefined4 extraout_r1;
  uint uVar8;
  char cVar9;
  undefined4 *puVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  bool bVar14;
  undefined8 uVar15;
  
  uVar2 = DAT_1c0fff14;
  uVar11 = DAT_1c0fff10;
  pcVar1 = DAT_1c0fff0c;
  if (*DAT_1c0fff0c == '\0') {
    bVar14 = DAT_1c0fff10 < DAT_1c0fff14;
    *DAT_1c0fff18 = param_1;
    cVar6 = '\0';
    if (bVar14) {
      pcVar4 = *(char **)(uVar11 + 8);
      cVar9 = '\0';
      uVar8 = uVar11;
      while( true ) {
        *pcVar4 = cVar9;
        if (*(int *)(uVar8 + 0x24) << 0x1f < 0) {
          cVar6 = cVar6 + '\x01';
        }
        cVar9 = cVar9 + '\x01';
        if (uVar2 <= uVar8 + 0x28) break;
        pcVar4 = *(char **)(uVar8 + 0x30);
        uVar8 = uVar8 + 0x28;
        if (cVar9 == -1) {
          return -0xc;
        }
      }
    }
    else {
      cVar9 = '\0';
    }
    pcVar4 = DAT_1c0fff20;
    *DAT_1c0fff1c = cVar9;
    *pcVar4 = cVar6;
    FUN_1c103512(DAT_1c0fff24,0,0x120);
    iVar5 = FUN_1c0fcb40(DAT_1c0fff28);
    if (iVar5 < 0) {
      return iVar5;
    }
    iVar5 = FUN_1c10108c(DAT_1c0fff2c,0,1);
    if (iVar5 < 0) {
      return iVar5;
    }
    iVar5 = FUN_1c10108c(DAT_1c0fff30,0,1);
    if (iVar5 < 0) {
      return iVar5;
    }
    iVar13 = 0;
    iVar5 = DAT_1c0fff34;
    do {
      *(char *)(iVar5 + -0xc) = (char)iVar13;
      uVar15 = FUN_1c10108c(iVar5,0,1);
      uVar3 = DAT_1c0fff38;
      uVar7 = (undefined4)((ulonglong)uVar15 >> 0x20);
      iVar13 = iVar13 + 1;
      iVar5 = iVar5 + 0x24;
      if ((int)uVar15 < 0) {
        return (int)uVar15;
      }
      uVar8 = DAT_1c0fff10;
    } while (iVar13 != 8);
    while (uVar11 < uVar2) {
      piVar12 = *(int **)(uVar8 + 0xc);
      puVar10 = (undefined4 *)*piVar12;
      if (puVar10[4] == 0) {
        uVar15 = FUN_1c10108c(*(int *)(uVar8 + 8) + 4,0,1);
        uVar7 = (undefined4)((ulonglong)uVar15 >> 0x20);
        if (-1 < (int)uVar15) {
          puVar10 = (undefined4 *)*piVar12;
          goto LAB_1c0ffea8;
        }
      }
      else {
LAB_1c0ffea8:
        uVar15 = (*(code *)*puVar10)(piVar12,uVar3,0);
        uVar7 = (undefined4)((ulonglong)uVar15 >> 0x20);
        if (((int)uVar15 == 0) &&
           (*(undefined1 *)(*(int *)(uVar8 + 8) + 0x14) = 1, *(int *)(uVar8 + 0x24) << 0x1e < 0)) {
          FUN_1c0ffd74(uVar8);
          uVar7 = extraout_r1;
        }
      }
      uVar11 = uVar8 + 0x28;
      uVar8 = uVar11;
    }
    if ((*pcVar4 != '\0') && (iVar5 = FUN_1c1010f0(DAT_1c0fff2c,uVar7,0x7a12,0), iVar5 == -0xb)) {
      return -0x23;
    }
    *pcVar1 = '\x01';
  }
  return 0;
}


