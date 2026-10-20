/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06beb4. Types and names are inferred; NOT original source. */

int FUN_0e06beb4(undefined4 param_1)

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
  
  uVar2 = DAT_0e06bfe4;
  uVar11 = DAT_0e06bfe0;
  pcVar1 = DAT_0e06bfdc;
  if (*DAT_0e06bfdc == '\0') {
    bVar14 = DAT_0e06bfe0 < DAT_0e06bfe4;
    *DAT_0e06bfe8 = param_1;
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
    pcVar4 = DAT_0e06bff0;
    *DAT_0e06bfec = cVar9;
    *pcVar4 = cVar6;
    FUN_0e06f446(DAT_0e06bff4,0,0x120);
    iVar5 = FUN_0e0686a4(DAT_0e06bff8);
    if (iVar5 < 0) {
      return iVar5;
    }
    iVar5 = FUN_0e06d150(DAT_0e06bffc,0,1);
    if (iVar5 < 0) {
      return iVar5;
    }
    iVar5 = FUN_0e06d150(DAT_0e06c000,0,1);
    if (iVar5 < 0) {
      return iVar5;
    }
    iVar13 = 0;
    iVar5 = DAT_0e06c004;
    do {
      *(char *)(iVar5 + -0xc) = (char)iVar13;
      uVar15 = FUN_0e06d150(iVar5,0,1);
      uVar3 = DAT_0e06c008;
      uVar7 = (undefined4)((ulonglong)uVar15 >> 0x20);
      iVar13 = iVar13 + 1;
      iVar5 = iVar5 + 0x24;
      if ((int)uVar15 < 0) {
        return (int)uVar15;
      }
      uVar8 = DAT_0e06bfe0;
    } while (iVar13 != 8);
    while (uVar11 < uVar2) {
      piVar12 = *(int **)(uVar8 + 0xc);
      puVar10 = (undefined4 *)*piVar12;
      if (puVar10[4] == 0) {
        uVar15 = FUN_0e06d150(*(int *)(uVar8 + 8) + 4,0,1);
        uVar7 = (undefined4)((ulonglong)uVar15 >> 0x20);
        if (-1 < (int)uVar15) {
          puVar10 = (undefined4 *)*piVar12;
          goto LAB_0e06bf78;
        }
      }
      else {
LAB_0e06bf78:
        uVar15 = (*(code *)*puVar10)(piVar12,uVar3,0);
        uVar7 = (undefined4)((ulonglong)uVar15 >> 0x20);
        if (((int)uVar15 == 0) &&
           (*(undefined1 *)(*(int *)(uVar8 + 8) + 0x14) = 1, *(int *)(uVar8 + 0x24) << 0x1e < 0)) {
          FUN_0e06be44(uVar8);
          uVar7 = extraout_r1;
        }
      }
      uVar11 = uVar8 + 0x28;
      uVar8 = uVar11;
    }
    if ((*pcVar4 != '\0') &&
       (iVar5 = FUN_0e06d1b4(DAT_0e06bffc,uVar7,DAT_0e06c00c,0), iVar5 == -0xb)) {
      return -0x23;
    }
    *pcVar1 = '\x01';
  }
  return 0;
}


