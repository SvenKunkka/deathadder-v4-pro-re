/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06d618. Types and names are inferred; NOT original source. */

void FUN_0e06d618(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  
  *DAT_0e06d680 = (short)param_2;
  puVar2 = DAT_0e06d68c;
  if (param_2 == 1) {
    *DAT_0e06d68c = 1;
    FUN_0e077ef0();
    puVar2 = DAT_0e06d688;
    *DAT_0e06d694 = 2;
    *puVar2 = 1;
    thunk_FUN_0e07f138();
    puVar2 = DAT_0e06d69c;
    cVar1 = *DAT_0e06d698;
    *DAT_0e06d69c = 1;
    puVar3 = DAT_0e06d6a4;
    if (cVar1 != '\0') {
      *DAT_0e06d6a0 = 1;
      *puVar3 = 0;
      *puVar2 = 0;
      return;
    }
  }
  else {
    iVar4 = *DAT_0e06d684;
    *DAT_0e06d688 = 0;
    *(undefined4 *)(iVar4 + 4) = 1;
    *(undefined4 *)(iVar4 + 0xc) = 1;
    *puVar2 = 0;
    FUN_0e077eb0();
    if (*DAT_0e06d690 == '\x01') {
      thunk_FUN_0e07f074();
      return;
    }
  }
  return;
}


