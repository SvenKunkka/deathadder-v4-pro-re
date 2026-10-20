/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06d0f0. Types and names are inferred; NOT original source. */

void FUN_0e06d0f0(void)

{
  char cVar1;
  sbyte sVar2;
  byte *pbVar3;
  char *pcVar4;
  undefined4 *puVar5;
  ushort *puVar6;
  undefined1 *puVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  uint uVar11;
  char cVar12;
  byte bVar13;
  uint uVar14;
  uint *puVar15;
  uint local_1c;
  
  thunk_FUN_0e085808();
  thunk_FUN_0e085194();
  pbVar3 = DAT_0e06d2d8;
  iVar8 = DAT_0e06d2d4;
  pcVar10 = DAT_0e06d2dc;
  if (*(char *)(DAT_0e06d2d4 + 0x10) == '\0') {
    uVar14 = (uint)*DAT_0e06d2d8;
  }
  else {
    uVar11 = (uint)*(byte *)(DAT_0e06d2d4 + 0x16);
    uVar14 = (uint)*DAT_0e06d2d8;
    if (*DAT_0e06d320 != uVar11) {
      *DAT_0e06d320 = *(byte *)(DAT_0e06d2d4 + 0x16);
      cVar1 = *DAT_0e06d2e8;
      if (uVar11 == 100) {
        uVar11 = 0xff;
        *DAT_0e06d32c = 0xff;
        pcVar10 = DAT_0e06d2dc;
        if (cVar1 != '\0') {
          *DAT_0e06d328 = 1;
          goto LAB_0e06d276;
        }
      }
      else {
        uVar11 = ((uint)((ulonglong)DAT_0e06d324 * (ulonglong)(uVar11 * 0xff) >> 0x20) & 0x1fff) >>
                 5;
        uVar9 = uVar11 - 1 & 0xff;
        if (uVar9 < 0xfe) {
          uVar11 = uVar11 + 1;
        }
        *DAT_0e06d328 = 0;
        if (uVar9 < 0xfe) {
          uVar11 = uVar11 & 0xff;
        }
        *DAT_0e06d32c = (char)uVar11;
        if (cVar1 == '\0') {
          pcVar10 = DAT_0e06d2dc;
          if (uVar14 <= uVar11) goto LAB_0e06d260;
        }
        else {
LAB_0e06d276:
          pcVar10 = DAT_0e06d2dc;
          if (uVar11 <= uVar14) goto LAB_0e06d260;
        }
        pcVar4 = DAT_0e06d2f8;
        *pbVar3 = (byte)uVar11;
        pcVar10 = DAT_0e06d2dc;
        uVar14 = uVar11;
        if ((*pcVar4 != '\x04') || (*DAT_0e06d334 == '\0')) {
          *DAT_0e06d2dc = '\x01';
        }
      }
    }
LAB_0e06d260:
    *(undefined1 *)(iVar8 + 0x10) = 0;
  }
  if (((*DAT_0e06d2e0 == '\0') || (*DAT_0e06d2e4 == '\0')) || (*DAT_0e06d304 < 500)) {
    if (*pcVar10 != '\0') goto LAB_0e06d1be;
  }
  else {
    *DAT_0e06d2e4 = '\0';
LAB_0e06d1be:
    puVar5 = DAT_0e06d308;
    pcVar4 = DAT_0e06d2e8;
    cVar1 = *DAT_0e06d2e8;
    *(char *)((int)DAT_0e06d308 + -1) = (char)uVar14;
    *(undefined2 *)((int)puVar5 + -3) = 0x3105;
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    *(undefined1 *)(puVar5 + 3) = 0;
    *pcVar10 = '\0';
    cVar12 = '\0';
    if (cVar1 != '\0') {
      iVar8 = *(int *)(DAT_0e06d330 + 0x14);
      sVar2 = *(sbyte *)(DAT_0e06d330 + 0x18);
      puVar15 = *(uint **)(iVar8 + 0x10);
      iVar8 = (**(code **)(*(int *)(iVar8 + 8) + 4))(iVar8,&local_1c);
      if (iVar8 == 0) {
        cVar12 = *pcVar4;
        uVar14 = (uint)*pbVar3;
        if (((*puVar15 ^ local_1c) & 1 << sVar2) == 0) {
          *(undefined1 *)puVar5 = 1;
          goto LAB_0e06d1e2;
        }
      }
      cVar12 = *pcVar4;
      uVar14 = (uint)*pbVar3;
      *(undefined1 *)puVar5 = 0;
    }
LAB_0e06d1e2:
    pbVar3 = DAT_0e06d30c;
    *(char *)((int)puVar5 + 1) = cVar12;
    uVar11 = (uint)*pbVar3;
    bVar13 = (byte)(uVar11 + 1);
    if (7 < (uVar11 + 1 & 0xff)) {
      bVar13 = 0;
    }
    *pbVar3 = bVar13;
    puVar7 = DAT_0e06d314;
    puVar6 = DAT_0e06d310;
    *(undefined1 *)((int)puVar5 + 2) = 1;
    *puVar7 = 0x31;
    *puVar6 = *puVar6 | 0x80;
    *(undefined1 *)(DAT_0e06d318 + uVar11) = 0x31;
    *(undefined1 *)(DAT_0e06d31c + uVar11) = 0xff;
  }
  if ((uVar14 < 0x10) && (*DAT_0e06d2e8 == '\0')) {
    *DAT_0e06d2ec = *DAT_0e06d2f8 == '\x01';
    if (((uVar14 == 0) && (*DAT_0e06d2fc == '\0')) && (*DAT_0e06d300 == '\0')) {
      if (2 < *DAT_0e06d2f0) {
        thunk_FUN_0e07d848(0);
        thunk_FUN_0e080668();
        FUN_0e074ecc();
        thunk_FUN_0e07d864(0);
        thunk_FUN_0e09628c(0x186a,0);
        FUN_0e078d7c();
        thunk_FUN_0e085788();
        iVar8 = thunk_FUN_0e085324(2);
        if (iVar8 == 0) {
          thunk_FUN_0e07e218();
          do {
            thunk_FUN_0e08a134();
          } while( true );
        }
      }
      goto LAB_0e06d138;
    }
  }
  else {
    *DAT_0e06d2ec = 0;
  }
  *DAT_0e06d2f0 = 0;
LAB_0e06d138:
                    /* WARNING: Could not recover jumptable at 0x0e078ddc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0e078de0)(*DAT_0e06d2f4,DAT_0e06d2f4[1]);
  return;
}


