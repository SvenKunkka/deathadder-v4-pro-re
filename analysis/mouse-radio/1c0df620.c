/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0df620. Types and names are inferred; NOT original source. */

void FUN_1c0df620(int param_1,uint param_2)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  int iVar7;
  
  piVar1 = DAT_1c0df6b0;
  iVar7 = DAT_1c0df6ac;
  if (param_1 == 4) {
    if (*(byte *)(DAT_1c0df6ac + 1) != param_2) {
      FUN_1c0e4308();
      piVar1 = DAT_1c0df6cc;
      *(char *)(iVar7 + 1) = (char)param_2;
      puVar2 = DAT_1c0df6b4;
      iVar7 = *piVar1;
      *(undefined4 *)(iVar7 + 4) = 1;
      *(undefined4 *)(iVar7 + 0xc) = 1;
      FUN_1c0e3c8c();
      FUN_1c0df510();
      puVar5 = DAT_1c0df6c4;
      *DAT_1c0df6b8 = 0;
      puVar6 = DAT_1c0df6c8;
      puVar4 = DAT_1c0df6c0;
      puVar3 = DAT_1c0df6bc;
      *puVar5 = 0;
      *puVar2 = 0;
      *puVar3 = 0;
      *puVar4 = 0;
      *puVar6 = 0;
      FUN_1c0e433c();
      return;
    }
  }
  else if ((param_1 == 1) && (*(byte *)(DAT_1c0df6ac + 3) != param_2)) {
    *(char *)(DAT_1c0df6ac + 3) = (char)param_2;
    puVar2 = DAT_1c0df6b4;
    iVar7 = *piVar1;
    *(undefined4 *)(iVar7 + 4) = 1;
    *(undefined4 *)(iVar7 + 0xc) = 1;
    FUN_1c0e40d8();
    FUN_1c0e3c8c();
    FUN_1c0df510();
    puVar3 = DAT_1c0df6bc;
    *DAT_1c0df6b8 = 0;
    puVar5 = DAT_1c0df6c8;
    puVar4 = DAT_1c0df6c0;
    *DAT_1c0df6c4 = 0;
    *puVar2 = 0;
    *puVar3 = 0;
    *puVar4 = 0;
    *puVar5 = 0;
    return;
  }
  return;
}


