/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06be18. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e06bf24) */

int FUN_0e06be18(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 extraout_r1;
  char cVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  int *piVar9;
  undefined8 uVar10;
  
  if (DAT_230071ec == '\0') {
    pcVar1 = &DAT_230004fc;
    cVar6 = '\0';
    cVar4 = '\0';
    puVar8 = &DAT_0e07267c;
    DAT_23007034 = param_1;
    while( true ) {
      *pcVar1 = cVar6;
      if (*(int *)(puVar8 + 0x24) << 0x1f < 0) {
        cVar4 = cVar4 + '\x01';
      }
      cVar6 = cVar6 + '\x01';
      if ((undefined *)0xe0726a3 < puVar8 + 0x28) break;
      pcVar1 = *(char **)(puVar8 + 0x30);
      puVar8 = puVar8 + 0x28;
      if (cVar6 == -1) {
        return -0xc;
      }
    }
    DAT_230071ee = cVar4;
    DAT_230071ef = cVar6;
    FUN_0e06f3aa(&DAT_23007048,0,0x120);
    iVar2 = FUN_0e068608(&LAB_0e06c604_1);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_0e06d0b4(&DAT_23007038,0,1);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_0e06d0b4(&DAT_23007010,0,1);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = 0;
    puVar8 = &DAT_23007054;
    do {
      puVar8[-0xc] = (char)iVar2;
      iVar3 = FUN_0e06d0b4(puVar8,0,1);
      iVar2 = iVar2 + 1;
      puVar8 = puVar8 + 0x24;
      if (iVar3 < 0) {
        return iVar3;
      }
    } while (iVar2 != 8);
    puVar8 = &DAT_0e07267c;
    do {
      piVar9 = *(int **)(puVar8 + 0xc);
      puVar7 = (undefined4 *)*piVar9;
      if (puVar7[4] == 0) {
        uVar10 = FUN_0e06d0b4(*(int *)(puVar8 + 8) + 4,0,1);
        uVar5 = (undefined4)((ulonglong)uVar10 >> 0x20);
        if (-1 < (int)uVar10) {
          puVar7 = (undefined4 *)*piVar9;
          goto LAB_0e06bedc;
        }
      }
      else {
LAB_0e06bedc:
        uVar10 = (*(code *)*puVar7)(piVar9,0xe06c079,0);
        uVar5 = (undefined4)((ulonglong)uVar10 >> 0x20);
        if (((int)uVar10 == 0) &&
           (*(undefined1 *)(*(int *)(puVar8 + 8) + 0x14) = 1, *(int *)(puVar8 + 0x24) << 0x1e < 0))
        {
          FUN_0e06bda8(puVar8);
          uVar5 = extraout_r1;
        }
      }
      puVar8 = puVar8 + 0x28;
    } while (puVar8 < &UNK_0e0726a4);
    if ((DAT_230071ee != '\0') &&
       (iVar2 = FUN_0e06d118(&DAT_23007038,uVar5,1000000,0), iVar2 == -0xb)) {
      return -0x23;
    }
    DAT_230071ec = '\x01';
  }
  return 0;
}


