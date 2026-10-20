/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e093cbc. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e093dc8) */

int FUN_0e093cbc(undefined4 param_1)

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
  
  if (DAT_230077c6 == '\0') {
    pcVar1 = &DAT_23000ea0;
    cVar6 = '\0';
    cVar4 = '\0';
    puVar8 = &DAT_0e09d120;
    DAT_23007514 = param_1;
    while( true ) {
      *pcVar1 = cVar6;
      if (*(int *)(puVar8 + 0x24) << 0x1f < 0) {
        cVar4 = cVar4 + '\x01';
      }
      cVar6 = cVar6 + '\x01';
      if ((undefined *)0xe09d147 < puVar8 + 0x28) break;
      pcVar1 = *(char **)(puVar8 + 0x30);
      puVar8 = puVar8 + 0x28;
      if (cVar6 == -1) {
        return -0xc;
      }
    }
    DAT_230077c8 = cVar4;
    DAT_230077c9 = cVar6;
    FUN_0e0973ea(&DAT_23007528,0,0x120);
    iVar2 = FUN_0e090a18(&LAB_0e0944a4_1);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_0e094f64(&DAT_23007518,0,1);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_0e094f64(&DAT_230074f0,0,1);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = 0;
    puVar8 = &DAT_23007534;
    do {
      puVar8[-0xc] = (char)iVar2;
      iVar3 = FUN_0e094f64(puVar8,0,1);
      iVar2 = iVar2 + 1;
      puVar8 = puVar8 + 0x24;
      if (iVar3 < 0) {
        return iVar3;
      }
    } while (iVar2 != 8);
    puVar8 = &DAT_0e09d120;
    do {
      piVar9 = *(int **)(puVar8 + 0xc);
      puVar7 = (undefined4 *)*piVar9;
      if (puVar7[4] == 0) {
        uVar10 = FUN_0e094f64(*(int *)(puVar8 + 8) + 4,0,1);
        uVar5 = (undefined4)((ulonglong)uVar10 >> 0x20);
        if (-1 < (int)uVar10) {
          puVar7 = (undefined4 *)*piVar9;
          goto LAB_0e093d80;
        }
      }
      else {
LAB_0e093d80:
        uVar10 = (*(code *)*puVar7)(piVar9,0xe093f19,0);
        uVar5 = (undefined4)((ulonglong)uVar10 >> 0x20);
        if (((int)uVar10 == 0) &&
           (*(undefined1 *)(*(int *)(puVar8 + 8) + 0x14) = 1, *(int *)(puVar8 + 0x24) << 0x1e < 0))
        {
          FUN_0e093c4c(puVar8);
          uVar5 = extraout_r1;
        }
      }
      puVar8 = puVar8 + 0x28;
    } while (puVar8 < &UNK_0e09d148);
    if ((DAT_230077c8 != '\0') &&
       (iVar2 = FUN_0e094fc8(&DAT_23007518,uVar5,0x7a12,0), iVar2 == -0xb)) {
      return -0x23;
    }
    DAT_230077c6 = '\x01';
  }
  return 0;
}


