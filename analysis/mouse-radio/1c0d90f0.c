/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0d90f0. Types and names are inferred; NOT original source. */

void FUN_1c0d90f0(void)

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
  
  thunk_EXT_FUN_0e085808();
  thunk_EXT_FUN_0e085194();
  pbVar3 = DAT_1c0d92d8;
  iVar8 = DAT_1c0d92d4;
  pcVar10 = DAT_1c0d92dc;
  if (*(char *)(DAT_1c0d92d4 + 0x10) == '\0') {
    uVar14 = (uint)*DAT_1c0d92d8;
  }
  else {
    uVar11 = (uint)*(byte *)(DAT_1c0d92d4 + 0x16);
    uVar14 = (uint)*DAT_1c0d92d8;
    if (*DAT_1c0d9320 != uVar11) {
      *DAT_1c0d9320 = *(byte *)(DAT_1c0d92d4 + 0x16);
      cVar1 = *DAT_1c0d92e8;
      if (uVar11 == 100) {
        uVar11 = 0xff;
        *DAT_1c0d932c = 0xff;
        pcVar10 = DAT_1c0d92dc;
        if (cVar1 != '\0') {
          *DAT_1c0d9328 = 1;
          goto LAB_1c0d9276;
        }
      }
      else {
        uVar11 = ((uint)((ulonglong)DAT_1c0d9324 * (ulonglong)(uVar11 * 0xff) >> 0x20) & 0x1fff) >>
                 5;
        uVar9 = uVar11 - 1 & 0xff;
        if (uVar9 < 0xfe) {
          uVar11 = uVar11 + 1;
        }
        *DAT_1c0d9328 = 0;
        if (uVar9 < 0xfe) {
          uVar11 = uVar11 & 0xff;
        }
        *DAT_1c0d932c = (char)uVar11;
        if (cVar1 == '\0') {
          pcVar10 = DAT_1c0d92dc;
          if (uVar14 <= uVar11) goto LAB_1c0d9260;
        }
        else {
LAB_1c0d9276:
          pcVar10 = DAT_1c0d92dc;
          if (uVar11 <= uVar14) goto LAB_1c0d9260;
        }
        pcVar4 = DAT_1c0d92f8;
        *pbVar3 = (byte)uVar11;
        pcVar10 = DAT_1c0d92dc;
        uVar14 = uVar11;
        if ((*pcVar4 != '\x04') || (*DAT_1c0d9334 == '\0')) {
          *DAT_1c0d92dc = '\x01';
        }
      }
    }
LAB_1c0d9260:
    *(undefined1 *)(iVar8 + 0x10) = 0;
  }
  if (((*DAT_1c0d92e0 == '\0') || (*DAT_1c0d92e4 == '\0')) || (*DAT_1c0d9304 < 500)) {
    if (*pcVar10 != '\0') goto LAB_1c0d91be;
  }
  else {
    *DAT_1c0d92e4 = '\0';
LAB_1c0d91be:
    puVar5 = DAT_1c0d9308;
    pcVar4 = DAT_1c0d92e8;
    cVar1 = *DAT_1c0d92e8;
    *(char *)((int)DAT_1c0d9308 + -1) = (char)uVar14;
    *(undefined2 *)((int)puVar5 + -3) = 0x3105;
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    *(undefined1 *)(puVar5 + 3) = 0;
    *pcVar10 = '\0';
    cVar12 = '\0';
    if (cVar1 != '\0') {
      iVar8 = *(int *)(DAT_1c0d9330 + 0x14);
      sVar2 = *(sbyte *)(DAT_1c0d9330 + 0x18);
      puVar15 = *(uint **)(iVar8 + 0x10);
      iVar8 = (**(code **)(*(int *)(iVar8 + 8) + 4))(iVar8,&local_1c);
      if (iVar8 == 0) {
        cVar12 = *pcVar4;
        uVar14 = (uint)*pbVar3;
        if (((*puVar15 ^ local_1c) & 1 << sVar2) == 0) {
          *(undefined1 *)puVar5 = 1;
          goto LAB_1c0d91e2;
        }
      }
      cVar12 = *pcVar4;
      uVar14 = (uint)*pbVar3;
      *(undefined1 *)puVar5 = 0;
    }
LAB_1c0d91e2:
    pbVar3 = DAT_1c0d930c;
    *(char *)((int)puVar5 + 1) = cVar12;
    uVar11 = (uint)*pbVar3;
    bVar13 = (byte)(uVar11 + 1);
    if (7 < (uVar11 + 1 & 0xff)) {
      bVar13 = 0;
    }
    *pbVar3 = bVar13;
    puVar7 = DAT_1c0d9314;
    puVar6 = DAT_1c0d9310;
    *(undefined1 *)((int)puVar5 + 2) = 1;
    *puVar7 = 0x31;
    *puVar6 = *puVar6 | 0x80;
    *(undefined1 *)(DAT_1c0d9318 + uVar11) = 0x31;
    *(undefined1 *)(DAT_1c0d931c + uVar11) = 0xff;
  }
  if ((uVar14 < 0x10) && (*DAT_1c0d92e8 == '\0')) {
    *DAT_1c0d92ec = *DAT_1c0d92f8 == '\x01';
    if (((uVar14 == 0) && (*DAT_1c0d92fc == '\0')) && (*DAT_1c0d9300 == '\0')) {
      if (2 < *DAT_1c0d92f0) {
        thunk_EXT_FUN_0e07d848(0);
        thunk_EXT_FUN_0e080668();
        FUN_1c0e0ecc();
        thunk_EXT_FUN_0e07d864(0);
        thunk_EXT_FUN_0e09628c(0x186a,0);
        thunk_EXT_FUN_0e07ef2c();
        thunk_EXT_FUN_0e085788();
        iVar8 = thunk_EXT_FUN_0e085324(2);
        if (iVar8 == 0) {
          thunk_EXT_FUN_0e07e218();
          do {
            thunk_EXT_FUN_0e08a134();
          } while( true );
        }
      }
      goto LAB_1c0d9138;
    }
  }
  else {
    *DAT_1c0d92ec = 0;
  }
  *DAT_1c0d92f0 = 0;
LAB_1c0d9138:
                    /* WARNING: Could not recover jumptable at 0x1c0e4ddc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_1c0e4de0)(*DAT_1c0d92f4,DAT_1c0d92f4[1]);
  return;
}


