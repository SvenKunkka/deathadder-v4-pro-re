/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0df808. Types and names are inferred; NOT original source. */

void FUN_1c0df808(void)

{
  char *pcVar1;
  short *psVar2;
  char *pcVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  short sVar10;
  char cVar11;
  char *pcVar12;
  int *piVar13;
  char *pcVar14;
  uint *puVar15;
  uint local_1c [2];
  
  pcVar1 = DAT_1c0dfa38;
  piVar13 = DAT_1c0dfa1c;
  pcVar14 = DAT_1c0dfa10;
  if (*DAT_1c0dfa0c == '\0') {
    iVar7 = *DAT_1c0dfa1c;
    iVar8 = DAT_1c0dfa1c[1];
    puVar15 = *(uint **)(iVar7 + 0x10);
    iVar7 = (**(code **)(*(int *)(iVar7 + 8) + 4))(iVar7,local_1c);
    pcVar1 = DAT_1c0dfa38;
    pcVar12 = DAT_1c0dfa18;
    pcVar14 = DAT_1c0dfa10;
    if ((iVar7 == 0) && (((local_1c[0] ^ *puVar15) & 1 << (sbyte)iVar8) == 0)) {
      if (*DAT_1c0dfa20 == '\0') {
        *DAT_1c0dfa20 = '\x01';
        psVar2 = DAT_1c0dfa28;
        pcVar12 = DAT_1c0dfa18;
        if (*pcVar14 == '\0') {
          sVar10 = 500;
        }
        else {
          sVar10 = 2000;
        }
        *DAT_1c0dfa24 = '\0';
        cVar11 = *pcVar12;
        *psVar2 = sVar10;
        piVar13 = DAT_1c0dfa1c;
      }
      else if ((*DAT_1c0dfa28 == 0) && (*DAT_1c0dfa24 == '\0')) {
        *DAT_1c0dfa24 = '\x01';
        pcVar12 = DAT_1c0dfa18;
        if (*pcVar14 == '\0') {
          *pcVar14 = '\x01';
          pcVar14 = DAT_1c0dfa3c;
          *DAT_1c0dfa38 = '\0';
          puVar5 = DAT_1c0dfa44;
          puVar4 = DAT_1c0dfa40;
          *pcVar14 = '\0';
          puVar6 = DAT_1c0dfa48;
          *puVar4 = 0;
          *puVar5 = 0;
          puVar5 = DAT_1c0dfa50;
          puVar4 = DAT_1c0dfa4c;
          *puVar6 = 0;
          pcVar12 = DAT_1c0dfa18;
          *puVar5 = 0;
          *puVar4 = 0xff;
          thunk_EXT_FUN_0e07ee28();
          thunk_EXT_FUN_0e07d848(0x5a5a5a5a);
          cVar11 = *pcVar12;
          piVar13 = DAT_1c0dfa1c;
        }
        else {
          if (*DAT_1c0dfa3c != '\0') goto LAB_1c0df822;
          *DAT_1c0dfa54 = 0;
          thunk_EXT_FUN_0e07f380();
          cVar11 = *pcVar12;
          piVar13 = DAT_1c0dfa1c;
        }
      }
      else {
LAB_1c0df822:
        cVar11 = *DAT_1c0dfa18;
        pcVar12 = DAT_1c0dfa18;
        piVar13 = DAT_1c0dfa1c;
      }
    }
    else {
      cVar11 = *DAT_1c0dfa18;
      if (*DAT_1c0dfa10 == '\0') {
        if (cVar11 != '\0') {
          *DAT_1c0dfa20 = '\0';
          goto LAB_1c0df886;
        }
        if (*DAT_1c0dfa38 != '\0') {
          *DAT_1c0dfa20 = '\0';
          return;
        }
        thunk_EXT_FUN_0e085324(2);
        cVar11 = *pcVar12;
        *pcVar1 = '\x01';
      }
      *DAT_1c0dfa20 = '\0';
      piVar13 = DAT_1c0dfa1c;
    }
  }
  else {
    if ((*DAT_1c0dfa10 != '\0') || (*DAT_1c0dfa14 != '\0')) goto LAB_1c0df822;
    *DAT_1c0dfa3c = '\0';
    pcVar12 = DAT_1c0dfa18;
    *pcVar1 = '\0';
    *pcVar14 = '\x01';
    thunk_EXT_FUN_0e07d848(0x5a5a5a5a);
    cVar11 = *pcVar12;
    piVar13 = DAT_1c0dfa1c;
  }
  DAT_1c0dfa1c = piVar13;
  if (cVar11 == '\0') {
    return;
  }
LAB_1c0df886:
  iVar8 = *piVar13;
  pcVar14 = (char *)(uint)*(byte *)(piVar13 + 1);
  puVar15 = *(uint **)(iVar8 + 0x10);
  uVar9 = (**(code **)(*(int *)(iVar8 + 8) + 4))(iVar8,local_1c);
  if (uVar9 == 0) goto LAB_1c0df936;
  while( true ) {
    if (((uVar9 != 1) && ((*pcVar12 == '\0' || (*DAT_1c0dfa14 == '\0')))) || (*DAT_1c0dfa2c < 500))
    {
      return;
    }
    *DAT_1c0dfa2c = 0;
    thunk_EXT_FUN_0e07d848(0);
    cVar11 = *DAT_1c0dfa30;
    *DAT_1c0dfa34 = 0;
    if (cVar11 != '\0') {
      FUN_1c0d9ad8();
    }
    FUN_1c0e40e8();
    FUN_1c0e41e8();
    FUN_1c0e3e1c();
    FUN_1c0e4008();
    pcVar14 = DAT_1c0dfa14;
    thunk_EXT_FUN_0e09628c(0xc35,0);
    if (*pcVar14 == '\0') {
      thunk_EXT_FUN_0e07ef2c();
    }
    else {
      thunk_EXT_FUN_0e07ee84(2);
      thunk_EXT_FUN_0e079b78();
      thunk_EXT_FUN_0e085788();
    }
    pcVar3 = DAT_1c0dfa3c;
    pcVar1 = DAT_1c0dfa10;
    *DAT_1c0dfa38 = '\0';
    *pcVar12 = '\0';
    *pcVar1 = '\0';
    *pcVar3 = '\0';
    iVar8 = thunk_EXT_FUN_0e085324(2);
    if (iVar8 != 0) break;
    do {
      do {
        thunk_EXT_FUN_0e09628c(0x20,0);
        thunk_EXT_FUN_0e07e228();
      } while (*pcVar14 != '\0');
      iVar8 = thunk_EXT_FUN_0e084ec8();
    } while (iVar8 == 0);
    thunk_EXT_FUN_0e08605c(0);
    pcVar12 = (char *)0x0;
LAB_1c0df936:
    uVar9 = (uint)(((local_1c[0] ^ *puVar15) & 1 << ((uint)pcVar14 & 0xff)) != 0);
  }
  return;
}


