/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08c500. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e08c538) */

undefined * FUN_0e08c500(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  
  if (param_2 == 0) {
    puVar2 = &DAT_230017e8;
    do {
      iVar1 = FUN_0e07960c(param_1,**(undefined4 **)(puVar2 + 4));
      if (iVar1 == 0) {
        return puVar2;
      }
      puVar2 = puVar2 + 0x18;
    } while (puVar2 < &DAT_23001830);
  }
  else if (param_2 == 1) {
    puVar2 = &DAT_23001830;
    do {
      iVar1 = FUN_0e07960c(param_1,**(undefined4 **)(puVar2 + 4));
      if (iVar1 == 0) {
        return puVar2;
      }
      puVar2 = puVar2 + 0x18;
    } while (puVar2 < &DAT_23001878);
  }
  return (undefined *)0x0;
}


