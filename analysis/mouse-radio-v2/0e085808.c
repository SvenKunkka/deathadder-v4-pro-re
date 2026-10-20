/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e085808. Types and names are inferred; NOT original source. */

void FUN_0e085808(void)

{
  short sVar1;
  longlong lVar2;
  char *pcVar3;
  char *pcVar4;
  uint *puVar5;
  uint *puVar6;
  char *pcVar7;
  undefined1 *puVar8;
  char cVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  short *psVar13;
  byte bVar14;
  byte bVar15;
  char cVar16;
  uint uVar17;
  code *pcVar18;
  short *psVar19;
  int iVar20;
  char cVar21;
  char cVar22;
  bool bVar23;
  
  pcVar7 = DAT_0e085ad8;
  puVar6 = DAT_0e085ad4;
  puVar5 = DAT_0e085ac8;
  pcVar3 = DAT_0e085ac4;
  pcVar4 = DAT_0e085abc;
  cVar16 = *(char *)(DAT_0e085ac0 + (uint)(byte)DAT_0e085abc[1] * 0xe + 8);
  if (cVar16 == '\0') {
    return;
  }
  if (DAT_0e085ac4[0x12] == '\f') {
    *DAT_0e085ac8 = 0;
    cVar9 = *pcVar7;
    *puVar6 = 0;
    if ((cVar9 != '\0') && (*(char *)(DAT_0e085adc + 0x12) != '\0')) {
      FUN_0e085134(1);
      *pcVar7 = '\0';
    }
LAB_0e085840:
    if (9 < (byte)pcVar3[0xc]) {
      cVar16 = pcVar3[0xd];
      pcVar3[4] = '\x01';
      pcVar3[5] = '\0';
      pcVar3[6] = '\0';
      pcVar3[7] = '\0';
      pcVar3[8] = '\0';
      pcVar3[9] = '\0';
      pcVar3[10] = '\0';
      pcVar3[0xb] = '\0';
      pcVar3[0xd] = cVar16 + 1U;
      pcVar3[0xc] = '\0';
      pcVar3[0x15] = '\0';
      pcVar7 = DAT_0e085ae0;
      if (((byte)(cVar16 + 1U) < 5) && (pcVar3[0x11] == *pcVar4)) {
        return;
      }
      pcVar3[0xd] = '\0';
      cVar16 = *pcVar7;
      pcVar3[0x12] = '\0';
      if (cVar16 != '\0') {
        pcVar3[0] = '\0';
        pcVar3[1] = '\0';
        pcVar3[4] = -0xc;
        pcVar3[5] = '\x01';
        pcVar3[6] = '\0';
        pcVar3[7] = '\0';
        return;
      }
      *pcVar7 = '\0';
      *pcVar3 = '\x02';
      pcVar3[4] = -1;
      pcVar3[5] = -1;
      pcVar3[6] = -1;
      pcVar3[7] = -1;
      return;
    }
    if (*(int *)(pcVar3 + 8) + 1U < *(uint *)(pcVar3 + 4)) {
      *(uint *)(pcVar3 + 8) = *(int *)(pcVar3 + 8) + 1U;
      return;
    }
  }
  else {
    if (*DAT_0e085ac8 <= DAT_0e085acc) {
      uVar17 = *DAT_0e085ac8 + 1;
      bVar23 = uVar17 == DAT_0e085ad0;
      *DAT_0e085ac8 = uVar17;
      if (bVar23) {
        *pcVar3 = '\x02';
        pcVar7 = DAT_0e085ae0;
        pcVar3[4] = -1;
        pcVar3[5] = -1;
        pcVar3[6] = -1;
        pcVar3[7] = -1;
        *pcVar7 = '\0';
        FUN_0e085134();
        iVar12 = *(int *)(pcVar4 + 0x14);
        bVar14 = pcVar4[0x18];
        *DAT_0e085ad8 = '\x01';
        iVar20 = *(int *)(iVar12 + 8);
        if ((1 << (uint)bVar14 & **(uint **)(iVar12 + 0x10)) == 0) {
          pcVar18 = *(code **)(iVar20 + 0xc);
        }
        else {
          pcVar18 = *(code **)(iVar20 + 0x10);
        }
        (*pcVar18)();
        *DAT_0e085ad4 = 0;
      }
      goto LAB_0e085840;
    }
    uVar17 = *DAT_0e085ad4;
    if (uVar17 != 0x9c4) {
      if (uVar17 < 0x2134) {
        *DAT_0e085ad4 = uVar17 + 1;
      }
      else {
        FUN_0e085134(1);
        *pcVar3 = '\x02';
        pcVar7 = DAT_0e085ae0;
        *puVar6 = 0;
        *puVar5 = 0;
        pcVar3[4] = -1;
        pcVar3[5] = -1;
        pcVar3[6] = -1;
        pcVar3[7] = -1;
        *pcVar7 = '\0';
      }
      goto LAB_0e085840;
    }
    iVar12 = *(int *)(*(int *)(DAT_0e085abc + 0x14) + 8);
    if ((1 << (uint)(byte)DAT_0e085abc[0x18] & **(uint **)(*(int *)(DAT_0e085abc + 0x14) + 0x10)) ==
        0) {
      pcVar18 = *(code **)(iVar12 + 0x10);
    }
    else {
      pcVar18 = *(code **)(iVar12 + 0xc);
    }
    (*pcVar18)();
    uVar17 = *puVar6;
    pcVar3[0xc] = '\0';
    pcVar3[0xd] = '\0';
    *puVar6 = uVar17 + 1;
    pcVar7 = DAT_0e085ae0;
    pcVar3[0] = '\0';
    pcVar3[1] = '\0';
    *pcVar7 = '\x01';
  }
  cVar9 = *pcVar3;
  pcVar3[4] = '\x01';
  pcVar3[5] = '\0';
  pcVar3[6] = '\0';
  pcVar3[7] = '\0';
  pcVar3[8] = '\0';
  iVar12 = DAT_0e085af0;
  pcVar3[9] = '\0';
  pcVar3[10] = '\0';
  pcVar3[0xb] = '\0';
  if (cVar9 == '\0') {
    bVar14 = pcVar3[1];
    iVar11 = DAT_0e085af0 + (uint)bVar14 * 0x60;
    iVar20 = FUN_0e085458(iVar11,*(undefined4 *)(iVar11 + 4));
    pcVar7 = DAT_0e085bf4;
    if (iVar20 == 0) {
      return;
    }
    cVar16 = *(char *)(iVar11 + 1);
    if (*(char *)(iVar12 + (uint)bVar14 * 0x60) == '\x01') {
      if (cVar16 == '\b') {
        if (pcVar3[0x13] != '\0') {
LAB_0e085ba2:
          iVar12 = 0;
          psVar13 = DAT_0e085bfc;
          do {
            sVar1 = *psVar13;
            psVar13 = psVar13 + 0x30;
            if (sVar1 == 0x802) {
              pcVar3[1] = (char)iVar12;
              return;
            }
            iVar12 = iVar12 + 1;
          } while (iVar12 != 0x11);
          return;
        }
      }
      else if (cVar16 == '\v') {
        if (-1 < pcVar3[0x14]) goto LAB_0e085ba2;
      }
      else if ((cVar16 == '\0') && (pcVar3[0x11] != *pcVar4)) {
        pcVar3[1] = '\0';
        pcVar3[4] = -0x18;
        pcVar3[5] = '\x03';
        pcVar3[6] = '\0';
        pcVar3[7] = '\0';
        return;
      }
    }
    if (pcVar3[0x12] == '\f') {
      pcVar3[0] = '\x01';
      pcVar3[1] = '\0';
      if (*pcVar7 != '\0') {
        return;
      }
      pcVar3[0x20] = '`';
      pcVar3[0x21] = '\t';
      pcVar3[0x22] = '\0';
      pcVar3[0x23] = '\0';
      return;
    }
    cVar16 = pcVar3[1];
    pcVar3[1] = cVar16 + 1U;
    if ((byte)(cVar16 + 1U) < 0x11) {
      return;
    }
    bVar14 = 0xf;
    pcVar3[4] = -0x38;
    pcVar3[5] = '\0';
    pcVar3[6] = '\0';
    pcVar3[7] = '\0';
    goto LAB_0e085a2e;
  }
  if (cVar9 != '\x01') {
    return;
  }
  cVar9 = pcVar3[0x24];
  if (pcVar3[0x12] == '\f') {
    if (cVar9 == '\0') {
      iVar12 = *(int *)(pcVar3 + 0x20);
      *(uint *)(pcVar3 + 0x20) = iVar12 + 1U;
      if (iVar12 + 1U < 0x9c5) {
        pcVar3[0x24] = '\0';
        return;
      }
      psVar19 = DAT_0e085bec + 0x90;
      cVar22 = '\0';
      cVar21 = '\0';
      psVar13 = DAT_0e085bec;
      do {
        sVar1 = *psVar13;
        if (sVar1 == 1) {
          *(undefined1 *)((int)psVar13 + 0x5f) = 1;
          cVar9 = cVar16;
          cVar22 = cVar16;
        }
        else if (sVar1 == 0x401) {
          *(undefined1 *)((int)psVar13 + 0x5f) = 1;
          cVar9 = cVar16;
          cVar21 = cVar16;
        }
        else if (sVar1 == 0x201) {
          *(undefined1 *)((int)psVar13 + 0x5f) = 1;
          cVar9 = cVar16;
        }
        psVar13 = psVar13 + 0x30;
      } while (psVar13 != psVar19);
      if (cVar21 != '\0') {
        pcVar3[0x15] = '\0';
      }
      if (cVar22 != '\0') {
        pcVar3[0x11] = '\0';
      }
      pcVar3[0x24] = cVar9;
      pcVar3[0x20] = '\0';
      pcVar3[0x21] = '\0';
      pcVar3[0x22] = '\0';
      pcVar3[0x23] = '\0';
      goto LAB_0e085924;
    }
  }
  else {
LAB_0e085924:
    if (cVar9 == '\0') {
      return;
    }
  }
  iVar12 = DAT_0e085ae4;
  bVar14 = pcVar3[1];
  iVar20 = DAT_0e085ae4 + (uint)bVar14 * 0x60;
  if ((*(char *)(iVar20 + 0x5f) != '\0') &&
     (iVar11 = FUN_0e085458(iVar20,*(undefined4 *)(iVar20 + 4)), iVar11 == 0)) {
    return;
  }
  *(undefined1 *)(iVar20 + 0x5f) = 0;
  if (*(short *)(iVar12 + (uint)bVar14 * 0x60) == 0x401) {
    sVar1 = *(short *)(pcVar3 + 0x1c);
    cVar16 = pcVar3[0x15] + '\x01';
    pcVar3[0x15] = cVar16;
    puVar8 = DAT_0e085bf0;
    if (cVar16 == '\x01') {
      *(undefined1 *)(iVar20 + 0x5f) = 1;
      psVar13 = DAT_0e085bf8;
      pcVar3[4] = '\x05';
      pcVar3[5] = '\0';
      pcVar3[6] = '\0';
      pcVar3[7] = '\0';
      *psVar13 = sVar1;
      *DAT_0e085bf0 = 0;
      return;
    }
    if (cVar16 == '\x02') {
      if (*DAT_0e085bf8 != sVar1) {
        *(undefined1 *)(iVar20 + 0x5f) = 1;
        pcVar3[4] = '\x05';
        pcVar3[5] = '\0';
        pcVar3[6] = '\0';
        pcVar3[7] = '\0';
        return;
      }
      *(short *)(pcVar3 + 0x18) = *DAT_0e085bf8;
      *puVar8 = 1;
    }
    else {
      *(short *)(pcVar3 + 0x18) = sVar1;
      *puVar8 = 1;
    }
  }
  pcVar4 = DAT_0e085ae8;
  bVar14 = pcVar3[1] + 1;
  if (2 < bVar14) {
    pcVar3[1] = '\0';
    cVar16 = *pcVar4;
    pcVar3[0x24] = '\0';
    if (cVar16 == '\0') {
      return;
    }
    bVar15 = 100;
    lVar2 = (ulonglong)DAT_0e085aec * (ulonglong)((uint)*(ushort *)(pcVar3 + 0x18) * 100 >> 8);
    uVar10 = (undefined4)lVar2;
    bVar14 = (byte)((ulonglong)lVar2 >> 0x20);
    if ((bVar14 < 100) && (bVar15 = bVar14, bVar14 == 0)) {
      uVar10 = 0x5f00;
      bVar15 = 0;
      if ((((uint)*(ushort *)(pcVar3 + 0x18) * 10000) / 0x5f00) % 100 != 0) {
        bVar15 = 1;
      }
    }
    pcVar3[0x16] = bVar15;
    *(short *)(pcVar3 + 0x1a) = (short)((int)((uint)*(ushort *)(pcVar3 + 0x1e) * 5) >> 4);
    pcVar3[0x10] = '\x01';
    FUN_0e097670(uVar10);
    *pcVar4 = '\0';
    return;
  }
LAB_0e085a2e:
  pcVar3[1] = bVar14;
  return;
}


