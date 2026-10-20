/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06c79c. Types and names are inferred; NOT original source. */

void FUN_0e06c79c(int param_1,int param_2)

{
  char cVar1;
  ushort uVar2;
  short *psVar3;
  short *psVar4;
  short *psVar5;
  short *psVar6;
  ushort *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  ushort uVar10;
  short sVar11;
  short sVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint uVar16;
  byte bVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  
  cVar1 = *DAT_0e06ca68;
  uVar10 = (ushort)(param_1 >> 0x1f);
  *DAT_0e06ca6c = (ushort)param_2;
  psVar6 = DAT_0e06ca80;
  psVar5 = DAT_0e06ca7c;
  psVar4 = DAT_0e06ca78;
  psVar3 = DAT_0e06ca74;
  uVar2 = (ushort)(param_2 >> 0x1f);
  sVar12 = ((ushort)param_1 ^ uVar10) - uVar10;
  sVar11 = ((ushort)param_2 ^ uVar2) - uVar2;
  iVar19 = (int)sVar12;
  iVar20 = (int)sVar11;
  *DAT_0e06ca70 = (ushort)param_1;
  *psVar3 = sVar12;
  *psVar4 = sVar12;
  *psVar5 = sVar11;
  *psVar6 = sVar11;
  iVar13 = iVar19;
  iVar18 = iVar20;
  if (cVar1 == '\x01') {
    bVar17 = DAT_0e06cabc[3];
    if (bVar17 < 2) {
LAB_0e06ca3c:
      sVar12 = (short)(iVar19 << 3);
      sVar11 = (short)(iVar20 << 3);
      *psVar4 = sVar12;
      *psVar6 = sVar11;
      iVar13 = (int)sVar12;
      iVar18 = (int)sVar11;
      goto LAB_0e06c7f6;
    }
LAB_0e06c9dc:
    if (bVar17 == 2) {
      sVar12 = (short)(iVar19 << 2);
      sVar11 = (short)(iVar20 << 2);
      *psVar4 = sVar12;
      *psVar6 = sVar11;
      iVar13 = (int)sVar12;
      iVar18 = (int)sVar11;
      goto LAB_0e06c7f6;
    }
    if (bVar17 < 5) {
      sVar12 = (short)(iVar19 << 1);
      sVar11 = (short)(iVar20 << 1);
      *psVar4 = sVar12;
      *psVar6 = sVar11;
      iVar13 = (int)sVar12;
      iVar18 = (int)sVar11;
      goto LAB_0e06c7f6;
    }
    if (bVar17 < 9) goto LAB_0e06c7f6;
    if (bVar17 < 0x11) goto LAB_0e06ca5c;
    if (bVar17 < 0x21) goto LAB_0e06cadc;
  }
  else {
    if (cVar1 != '\x04') goto LAB_0e06c7f6;
    if (*DAT_0e06cab8 != '\0') {
      bVar17 = DAT_0e06cabc[1];
      if (1 < bVar17) goto LAB_0e06c9dc;
      goto LAB_0e06ca3c;
    }
    bVar17 = *DAT_0e06cabc;
    if (bVar17 == 1) goto LAB_0e06c7f6;
    if (bVar17 < 3) {
LAB_0e06ca5c:
      *psVar4 = (short)(iVar19 >> 1);
      *psVar6 = (short)(iVar20 >> 1);
      iVar13 = iVar19 >> 1;
      iVar18 = iVar20 >> 1;
      goto LAB_0e06c7f6;
    }
    if (bVar17 < 5) {
LAB_0e06cadc:
      *psVar4 = (short)(iVar19 >> 2);
      *psVar6 = (short)(iVar20 >> 2);
      iVar13 = iVar19 >> 2;
      iVar18 = iVar20 >> 2;
      goto LAB_0e06c7f6;
    }
  }
  *psVar4 = (short)(iVar19 >> 3);
  *psVar6 = (short)(iVar20 >> 3);
  iVar13 = iVar19 >> 3;
  iVar18 = iVar20 >> 3;
LAB_0e06c7f6:
  thunk_FUN_0e079444(iVar13 * iVar13 + iVar18 * iVar18);
  thunk_FUN_0e0972f8();
  uVar10 = thunk_FUN_0e079518();
  iVar13 = DAT_0e06ca84;
  if (uVar10 < 0xfa) {
    if (uVar10 == 0) {
      uVar10 = 0;
    }
    else {
      uVar10 = uVar10 - 1;
    }
  }
  else {
    uVar10 = 0xf9;
  }
  *DAT_0e06ca88 = uVar10;
  uVar16 = (uint)*(byte *)(iVar13 + 1);
  bVar17 = *(byte *)(iVar13 + uVar16 + 5);
  *DAT_0e06ca8c = 0x3f800000;
  puVar7 = DAT_0e06ca94;
  if ((bVar17 <= uVar10) && (uVar16 < 4)) {
                    /* WARNING: Could not recover jumptable at 0x0e06c842. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_0e06c842::switchdataD_0e06c846 +
              (&switchD_0e06c842::switchdataD_0e06c846)[uVar16]))();
    return;
  }
  uVar14 = thunk_FUN_0e0796cc(iVar19);
  uVar16 = (uint)*puVar7;
  uVar14 = thunk_FUN_0e079038(uVar14,0x3f800000);
  puVar8 = DAT_0e06ca98;
  if (uVar16 != 0) {
    uVar14 = FUN_0e078f54(uVar14,DAT_0e06ca98[uVar16 - 1]);
    sVar11 = thunk_FUN_0e079774();
    uVar15 = thunk_FUN_0e0796cc((int)sVar11);
    uVar15 = thunk_FUN_0e079560(uVar14,uVar15);
    puVar9 = DAT_0e06ca9c;
    sVar12 = sVar11;
    if (param_1 < 0) {
      sVar12 = -sVar11;
    }
    puVar8[uVar16] = uVar15;
    *puVar9 = uVar14;
    *DAT_0e06caa0 = sVar11;
    *DAT_0e06caa4 = sVar12;
    uVar14 = thunk_FUN_0e0796cc(iVar20);
    uVar14 = thunk_FUN_0e079038(uVar14,0x3f800000);
    puVar8 = DAT_0e06caa8;
    uVar14 = FUN_0e078f54(uVar14,DAT_0e06caa8[uVar16 - 1]);
    *DAT_0e06caac = uVar14;
    sVar12 = thunk_FUN_0e079774();
    *DAT_0e06cab0 = sVar12;
    uVar15 = thunk_FUN_0e0796cc((int)sVar12);
    uVar14 = thunk_FUN_0e079560(uVar14,uVar15);
    puVar8[uVar16] = uVar14;
    psVar3 = DAT_0e06cab4;
    if (param_2 < 0) {
      sVar12 = -sVar12;
    }
    uVar10 = (ushort)(uVar16 + 1);
    if (0x13 < (uVar16 + 1 & 0xffff)) {
      uVar10 = 0;
    }
    *puVar7 = uVar10;
    *psVar3 = sVar12;
    return;
  }
  uVar14 = FUN_0e078f54(uVar14,DAT_0e06ca98[0x13]);
  sVar11 = thunk_FUN_0e079774();
  uVar15 = thunk_FUN_0e0796cc((int)sVar11);
  uVar15 = thunk_FUN_0e079560(uVar14,uVar15);
  puVar9 = DAT_0e06ca9c;
  sVar12 = sVar11;
  if (param_1 < 0) {
    sVar12 = -sVar11;
  }
  *puVar8 = uVar15;
  *puVar9 = uVar14;
  *DAT_0e06caa0 = sVar11;
  puVar8 = DAT_0e06caa8;
  *DAT_0e06caa4 = sVar12;
  uVar14 = thunk_FUN_0e0796cc(iVar20);
  uVar14 = thunk_FUN_0e079038(uVar14,0x3f800000);
  uVar14 = FUN_0e078f54(uVar14,puVar8[0x13]);
  *DAT_0e06caac = uVar14;
  sVar12 = thunk_FUN_0e079774();
  *DAT_0e06cab0 = sVar12;
  uVar15 = thunk_FUN_0e0796cc((int)sVar12);
  uVar14 = thunk_FUN_0e079560(uVar14,uVar15);
  psVar3 = DAT_0e06cab4;
  *puVar8 = uVar14;
  if (-1 < param_2) {
    *psVar3 = sVar12;
    *puVar7 = 1;
    return;
  }
  *psVar3 = -sVar12;
  *puVar7 = 1;
  return;
}


