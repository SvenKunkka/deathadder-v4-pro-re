/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e073620. Types and names are inferred; NOT original source. */

void FUN_0e073620(int param_1,uint param_2)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  int iVar7;
  
  piVar1 = DAT_0e0736b0;
  iVar7 = DAT_0e0736ac;
  if (param_1 == 4) {
    if (*(byte *)(DAT_0e0736ac + 1) != param_2) {
      FUN_0e078308();
      piVar1 = DAT_0e0736cc;
      *(char *)(iVar7 + 1) = (char)param_2;
      puVar2 = DAT_0e0736b4;
      iVar7 = *piVar1;
      *(undefined4 *)(iVar7 + 4) = 1;
      *(undefined4 *)(iVar7 + 0xc) = 1;
      FUN_0e077c8c();
      FUN_0e073510();
      puVar5 = DAT_0e0736c4;
      *DAT_0e0736b8 = 0;
      puVar6 = DAT_0e0736c8;
      puVar4 = DAT_0e0736c0;
      puVar3 = DAT_0e0736bc;
      *puVar5 = 0;
      *puVar2 = 0;
      *puVar3 = 0;
      *puVar4 = 0;
      *puVar6 = 0;
      FUN_0e07833c();
      return;
    }
  }
  else if ((param_1 == 1) && (*(byte *)(DAT_0e0736ac + 3) != param_2)) {
    *(char *)(DAT_0e0736ac + 3) = (char)param_2;
    puVar2 = DAT_0e0736b4;
    iVar7 = *piVar1;
    *(undefined4 *)(iVar7 + 4) = 1;
    *(undefined4 *)(iVar7 + 0xc) = 1;
    FUN_0e0780d8();
    FUN_0e077c8c();
    FUN_0e073510();
    puVar3 = DAT_0e0736bc;
    *DAT_0e0736b8 = 0;
    puVar5 = DAT_0e0736c8;
    puVar4 = DAT_0e0736c0;
    *DAT_0e0736c4 = 0;
    *puVar2 = 0;
    *puVar3 = 0;
    *puVar4 = 0;
    *puVar5 = 0;
    return;
  }
  return;
}


