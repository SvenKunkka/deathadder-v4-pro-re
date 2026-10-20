/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23027c70. Types and names are inferred; NOT original source. */

void FUN_23027c70(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined1 *puVar5;
  char *pcVar6;
  
  pcVar3 = &DAT_230065a1;
  iVar4 = 0;
  puVar5 = &DAT_230065a0;
  do {
    cVar1 = pcVar3[8];
    if (cVar1 == '\x02') {
      if ((*pcVar3 != '\0') && (DAT_23006bba == '\0')) {
        DAT_23006748 = DAT_23006748 & ~puVar5[0x32];
        pcVar6 = &DAT_23006749;
        iVar2 = 2;
        do {
          pcVar6 = pcVar6 + 1;
          if (*pcVar6 == puVar5[0x33]) {
            (&DAT_23006748)[iVar2] = 0;
            break;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 != 8);
        thunk_FUN_0e07f8ac(&DAT_23006720,3);
        pcVar3[8] = '\x01';
        cVar1 = '\0';
LAB_23027e18:
        *pcVar3 = cVar1;
        DAT_230076d2 = DAT_230076d2 | 8;
      }
    }
    else if (cVar1 == '\x03') {
      if (*pcVar3 == '\0') {
        pcVar3[8] = '\0';
      }
      else if (DAT_23006bba == '\0') {
        iVar2 = 2;
        DAT_23006748 = DAT_23006748 & ~puVar5[0x32];
        pcVar6 = &DAT_23006749;
        do {
          pcVar6 = pcVar6 + 1;
          if (*pcVar6 == puVar5[0x33]) {
            (&DAT_23006748)[iVar2] = 0;
            break;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 != 8);
        thunk_FUN_0e07f8ac(&DAT_23006720,3);
        pcVar3[8] = '\0';
        *pcVar3 = '\0';
        DAT_230076d2 = DAT_230076d2 | 8;
      }
    }
    else if (cVar1 == '\x01') {
      if (((*(ushort *)(&DAT_230065a1 + (iVar4 + 8) * 2) <=
            *(ushort *)(&DAT_230065a1 + (iVar4 + 0x10) * 2)) &&
          (*(ushort *)(&DAT_230065a1 + (iVar4 + 8) * 2) != 0)) && (DAT_23006bba == '\0')) {
        iVar2 = 2;
        DAT_23006748 = DAT_23006748 | puVar5[0x32];
        pcVar6 = &DAT_23006749;
        do {
          pcVar6 = pcVar6 + 1;
          if (*pcVar6 == puVar5[0x33]) break;
          if (*pcVar6 == '\0') {
            (&DAT_23006748)[iVar2] = puVar5[0x33];
            break;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 != 8);
        iVar2 = (iVar4 + 0x10) * 2;
        (&DAT_230065a1)[iVar2] = 0;
        (&DAT_230065a2)[iVar2] = 0;
        thunk_FUN_0e07f8ac(&DAT_23006720,7);
        pcVar3[8] = '\x02';
        cVar1 = '\x01';
        goto LAB_23027e18;
      }
    }
    cVar1 = pcVar3[0x53];
    if (cVar1 == '\x02') {
      if ((pcVar3[0x4b] != '\0') && (DAT_23006bb4 < 2)) {
        pcVar3[0x53] = '\x01';
        pcVar3[0x4b] = '\0';
        DAT_23006730._0_1_ = 0;
        DAT_230076d2 = DAT_230076d2 | 1;
      }
    }
    else if (cVar1 == '\x03') {
      if ((pcVar3[0x4b] != '\0') && (DAT_23006bb4 < 2)) {
        pcVar3[0x53] = '\0';
        DAT_23006730._0_1_ = 0;
        DAT_230076d2 = DAT_230076d2 | 1;
      }
    }
    else if (cVar1 == '\x01') {
      iVar2 = (iVar4 + 0x34) * 2;
      if (((*(ushort *)(&DAT_230065a4 + (iVar4 + 0x2c) * 2) <= *(ushort *)(&DAT_230065a4 + iVar2))
          && (*(ushort *)(&DAT_230065a4 + (iVar4 + 0x2c) * 2) != 0)) && (DAT_23006bb4 < 2)) {
        (&DAT_230065a4)[iVar2] = 0;
        (&DAT_230065a5)[iVar2] = 0;
        DAT_23006730._0_1_ = DAT_2300662d;
        DAT_230076d2 = DAT_230076d2 | 1;
        pcVar3[0x4b] = '\x01';
        DAT_23006730._1_1_ = pcVar3[0x8d];
        pcVar3[0x53] = '\x02';
      }
    }
    puVar5 = puVar5 + 2;
    pcVar3 = pcVar3 + 1;
    iVar4 = iVar4 + 1;
    if (iVar4 == 8) {
      return;
    }
  } while( true );
}


