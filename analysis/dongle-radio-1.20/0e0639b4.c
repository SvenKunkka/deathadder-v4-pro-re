/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0639b4. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e0639ec) */

undefined * FUN_0e0639b4(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  
  if (param_2 == 0) {
    puVar2 = &DAT_23001d78;
    do {
      iVar1 = FUN_0e05ba44(param_1,**(undefined4 **)(puVar2 + 4));
      if (iVar1 == 0) {
        return puVar2;
      }
      puVar2 = puVar2 + 0x18;
    } while (puVar2 < &DAT_23001dc0);
  }
  else if (param_2 == 1) {
    puVar2 = &DAT_23001dc0;
    do {
      iVar1 = FUN_0e05ba44(param_1,**(undefined4 **)(puVar2 + 4));
      if (iVar1 == 0) {
        return puVar2;
      }
      puVar2 = puVar2 + 0x18;
    } while (puVar2 < &DAT_23001e08);
  }
  return (undefined *)0x0;
}


