/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07d90c. Types and names are inferred; NOT original source. */

void FUN_0e07d90c(void)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  short sVar4;
  short sVar5;
  ushort uVar6;
  short *psVar7;
  char *pcVar8;
  int iVar9;
  short *psVar10;
  short *psVar11;
  undefined1 *puVar12;
  ushort *puVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  char *pcVar17;
  uint *puVar18;
  char *pcVar19;
  uint local_1c [2];
  
  psVar10 = DAT_0e07db24;
  psVar7 = DAT_0e07db20;
  *DAT_0e07db1c = *DAT_0e07db1c + 1;
  psVar11 = DAT_0e07db28;
  *psVar7 = *psVar7 + 1;
  psVar7 = DAT_0e07db2c;
  *psVar10 = *psVar10 + 1;
  psVar10 = DAT_0e07db30;
  *psVar11 = *psVar11 + 1;
  pcVar8 = DAT_0e07db34;
  *psVar7 = *psVar7 + 1;
  psVar7 = DAT_0e07db38;
  *psVar10 = *psVar10 + 1;
  psVar10 = DAT_0e07db3c;
  sVar4 = *psVar7;
  *pcVar8 = *pcVar8 + '\x01';
  sVar5 = *psVar10;
  *psVar7 = sVar4 + 1;
  if (sVar5 != 0) {
    *psVar10 = sVar5 + -1;
  }
  if (*DAT_0e07db40 != 0) {
    *DAT_0e07db40 = *DAT_0e07db40 + -1;
  }
  cVar2 = *DAT_0e07db44;
  if ((cVar2 == '\0') || (*DAT_0e07db44 = cVar2 + -1, puVar13 = DAT_0e07db84, cVar2 != '\x01')) {
    cVar2 = *DAT_0e07db48;
    psVar7 = DAT_0e07db90;
    pcVar8 = DAT_0e07db94;
  }
  else {
    uVar6 = *DAT_0e07db84;
    *DAT_0e07db88 = 4;
    *puVar13 = uVar6 | 0x40;
    cVar2 = *DAT_0e07db48;
    psVar7 = DAT_0e07db90;
    pcVar8 = DAT_0e07db94;
  }
  DAT_0e07db90 = psVar7;
  DAT_0e07db94 = pcVar8;
  if (cVar2 == '\x01') {
    *DAT_0e07db8c = *DAT_0e07db8c + 1;
    cVar2 = *pcVar8;
    *psVar7 = *psVar7 + 1;
    if (cVar2 == '\0') {
      if ((*DAT_0e07db98 == '\0') && (*DAT_0e07db9c != '\0')) {
        if ((ushort)(*DAT_0e07dba0 + 1) < 6000) {
          *DAT_0e07dba0 = *DAT_0e07dba0 + 1;
        }
        else {
          *DAT_0e07dba0 = 0;
          FUN_0e0976a8();
          *DAT_0e07db7c = 1;
        }
      }
      else {
        *DAT_0e07dba0 = 1;
      }
    }
    else {
      *DAT_0e07dba0 = 0;
    }
  }
  iVar14 = *DAT_0e07db4c;
  uVar6 = *DAT_0e07db50;
  iVar9 = DAT_0e07db4c[1];
  puVar18 = *(uint **)(iVar14 + 0x10);
  uVar15 = (**(code **)(*(int *)(iVar14 + 8) + 4))(iVar14,local_1c);
  if (uVar15 == 0) {
    if (((*puVar18 ^ local_1c[0]) & 1 << (sbyte)iVar9) == 0) {
      uVar15 = 0;
    }
    else {
      uVar15 = 1;
    }
  }
  iVar14 = *DAT_0e07db54;
  iVar9 = DAT_0e07db54[1];
  puVar18 = *(uint **)(iVar14 + 0x10);
  iVar14 = (**(code **)(*(int *)(iVar14 + 8) + 4))(iVar14,local_1c);
  if (iVar14 == 0) {
    if (((local_1c[0] ^ *puVar18) & 1 << (sbyte)iVar9) == 0) {
      iVar14 = 0;
    }
    else {
      iVar14 = 1;
    }
  }
  iVar16 = *DAT_0e07db58;
  iVar9 = DAT_0e07db58[1];
  puVar18 = *(uint **)(iVar16 + 0x10);
  iVar16 = (**(code **)(*(int *)(iVar16 + 8) + 4))(iVar16,local_1c);
  if (iVar16 == 0) {
    if (((*puVar18 ^ local_1c[0]) & 1 << (sbyte)iVar9) == 0) {
      iVar16 = 0;
    }
    else {
      iVar16 = 1;
    }
  }
  if (((uVar15 | iVar14 << 1 | iVar16 << 2) & (uint)uVar6) == 0) {
    *DAT_0e07db5c = *DAT_0e07db5c + 1;
  }
  if (*DAT_0e07db60 != 0) {
    *DAT_0e07db60 = *DAT_0e07db60 + -1;
  }
  pcVar8 = DAT_0e07db64;
  pcVar19 = DAT_0e07db64 + 8;
  pcVar17 = DAT_0e07db64;
  do {
    pcVar1 = pcVar17 + 1;
    if (*pcVar1 != '\0') {
      *(short *)(pcVar8 + (int)(pcVar17 + (0x10 - (int)pcVar8)) * 2 + -7) =
           *(short *)(pcVar8 + (int)(pcVar17 + (0x10 - (int)pcVar8)) * 2 + -7) + 1;
    }
    if (pcVar17[0x4c] != '\0') {
      *(short *)(pcVar8 + (int)(pcVar17 + (0x34 - (int)pcVar8)) * 2 + -4) =
           *(short *)(pcVar8 + (int)(pcVar17 + (0x34 - (int)pcVar8)) * 2 + -4) + 1;
    }
    pcVar17 = pcVar1;
  } while (pcVar1 != pcVar19);
  FUN_0e097718();
  FUN_0e097720();
  FUN_0e07ece0();
  pcVar8 = DAT_0e07db68;
  if (*DAT_0e07db68 != '\0') {
    *DAT_0e07db68 = *DAT_0e07db68 + -1;
  }
  cVar2 = pcVar8[2];
  if (cVar2 != '\0') {
    pcVar8[2] = cVar2 + -1;
  }
  pcVar8 = DAT_0e07db6c;
  if ((*DAT_0e07db6c != '\0') &&
     (bVar3 = *DAT_0e07db70, *DAT_0e07db70 = bVar3 + 1, puVar12 = DAT_0e07db80,
     199 < (byte)(bVar3 + 1))) {
    *pcVar8 = '\0';
    *puVar12 = 1;
  }
  puVar12 = DAT_0e07db7c;
  if (*DAT_0e07db74 != '\0') {
    if (*DAT_0e07db78 == 0) {
      *DAT_0e07db74 = '\0';
      *puVar12 = 1;
      return;
    }
    *DAT_0e07db78 = *DAT_0e07db78 + -1;
  }
  return;
}


