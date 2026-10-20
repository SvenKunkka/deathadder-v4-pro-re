/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e073808. Types and names are inferred; NOT original source. */

void FUN_0e073808(void)

{
  char *pcVar1;
  char *pcVar2;
  short *psVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined2 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  short sVar11;
  char cVar12;
  char *pcVar13;
  int *piVar14;
  uint *puVar15;
  uint local_1c [2];
  
  pcVar2 = DAT_0e073a38;
  piVar14 = DAT_0e073a1c;
  pcVar1 = DAT_0e073a10;
  if (*DAT_0e073a0c == '\0') {
    iVar8 = *DAT_0e073a1c;
    iVar10 = DAT_0e073a1c[1];
    puVar15 = *(uint **)(iVar8 + 0x10);
    iVar8 = (**(code **)(*(int *)(iVar8 + 8) + 4))(iVar8,local_1c);
    pcVar2 = DAT_0e073a38;
    pcVar13 = DAT_0e073a18;
    pcVar1 = DAT_0e073a10;
    if ((iVar8 == 0) && (((local_1c[0] ^ *puVar15) & 1 << (sbyte)iVar10) == 0)) {
      if (*DAT_0e073a20 == '\0') {
        *DAT_0e073a20 = '\x01';
        psVar3 = DAT_0e073a28;
        pcVar13 = DAT_0e073a18;
        if (*pcVar1 == '\0') {
          sVar11 = 500;
        }
        else {
          sVar11 = 2000;
        }
        *DAT_0e073a24 = '\0';
        cVar12 = *pcVar13;
        *psVar3 = sVar11;
        piVar14 = DAT_0e073a1c;
      }
      else if ((*DAT_0e073a28 == 0) && (*DAT_0e073a24 == '\0')) {
        *DAT_0e073a24 = '\x01';
        pcVar13 = DAT_0e073a18;
        if (*pcVar1 == '\0') {
          *pcVar1 = '\x01';
          pcVar1 = DAT_0e073a3c;
          *DAT_0e073a38 = '\0';
          puVar6 = DAT_0e073a44;
          puVar5 = DAT_0e073a40;
          *pcVar1 = '\0';
          puVar7 = DAT_0e073a48;
          *puVar5 = 0;
          *puVar6 = 0;
          puVar6 = DAT_0e073a50;
          puVar5 = DAT_0e073a4c;
          *puVar7 = 0;
          pcVar13 = DAT_0e073a18;
          *puVar6 = 0;
          *puVar5 = 0xff;
          thunk_FUN_0e07ee28();
          thunk_FUN_0e07d848(0x5a5a5a5a);
          cVar12 = *pcVar13;
          piVar14 = DAT_0e073a1c;
        }
        else {
          if (*DAT_0e073a3c != '\0') goto LAB_0e073822;
          *DAT_0e073a54 = 0;
          thunk_FUN_0e07f380();
          cVar12 = *pcVar13;
          piVar14 = DAT_0e073a1c;
        }
      }
      else {
LAB_0e073822:
        cVar12 = *DAT_0e073a18;
        pcVar13 = DAT_0e073a18;
        piVar14 = DAT_0e073a1c;
      }
    }
    else {
      cVar12 = *DAT_0e073a18;
      if (*DAT_0e073a10 == '\0') {
        if (cVar12 != '\0') {
          *DAT_0e073a20 = '\0';
          goto LAB_0e073886;
        }
        if (*DAT_0e073a38 != '\0') {
          *DAT_0e073a20 = '\0';
          return;
        }
        thunk_FUN_0e085324(2);
        cVar12 = *pcVar13;
        *pcVar2 = '\x01';
      }
      *DAT_0e073a20 = '\0';
      piVar14 = DAT_0e073a1c;
    }
  }
  else {
    if ((*DAT_0e073a10 != '\0') || (*DAT_0e073a14 != '\0')) goto LAB_0e073822;
    *DAT_0e073a3c = '\0';
    pcVar13 = DAT_0e073a18;
    *pcVar2 = '\0';
    *pcVar1 = '\x01';
    thunk_FUN_0e07d848(0x5a5a5a5a);
    cVar12 = *pcVar13;
    piVar14 = DAT_0e073a1c;
  }
  DAT_0e073a1c = piVar14;
  if (cVar12 == '\0') {
    return;
  }
LAB_0e073886:
  iVar8 = *piVar14;
  iVar10 = piVar14[1];
  puVar15 = *(uint **)(iVar8 + 0x10);
  uVar9 = (**(code **)(*(int *)(iVar8 + 8) + 4))(iVar8,local_1c);
  if (uVar9 == 0) {
    uVar9 = (uint)(((local_1c[0] ^ *puVar15) & 1 << (sbyte)iVar10) != 0);
  }
  if (((uVar9 == 1) || ((*pcVar13 != '\0' && (*DAT_0e073a14 != '\0')))) && (499 < *DAT_0e073a2c)) {
    *DAT_0e073a2c = 0;
    thunk_FUN_0e07d848(0);
    cVar12 = *DAT_0e073a30;
    *DAT_0e073a34 = 0;
    if (cVar12 != '\0') {
      FUN_0e06dad8();
    }
    FUN_0e0780e8();
    FUN_0e0781e8();
    FUN_0e077e1c();
    FUN_0e078008();
    pcVar1 = DAT_0e073a14;
    thunk_FUN_0e09628c(0xc35,0);
    if (*pcVar1 == '\0') {
      FUN_0e078d7c();
    }
    else {
      FUN_0e078d04(2);
      thunk_FUN_0e079b78();
      thunk_FUN_0e085788();
    }
    pcVar4 = DAT_0e073a3c;
    pcVar2 = DAT_0e073a10;
    *DAT_0e073a38 = '\0';
    *pcVar13 = '\0';
    *pcVar2 = '\0';
    *pcVar4 = '\0';
    iVar10 = thunk_FUN_0e085324(2);
    if (iVar10 == 0) {
      do {
        do {
          thunk_FUN_0e09628c(0x20,0);
          thunk_FUN_0e07e228();
        } while (*pcVar1 != '\0');
        iVar10 = thunk_FUN_0e084ec8();
      } while (iVar10 == 0);
                    /* WARNING: Subroutine does not return */
      thunk_FUN_0e08605c(0);
    }
  }
  return;
}


