/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063bac. Types and names are inferred; NOT original source. */

int FUN_0e063bac(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  
  if (param_2 == 1) {
    puVar2 = &DAT_23001dc0;
    do {
      if ((undefined *)0x23001e07 < puVar2) {
        return 0;
      }
      iVar1 = FUN_0e063b10(param_1,**(undefined4 **)(puVar2 + 4),1,param_3,param_4);
      puVar2 = puVar2 + 0x18;
    } while (iVar1 == 0);
  }
  else {
    if (param_2 != 0) {
      return -0x86;
    }
    puVar2 = &DAT_23001d78;
    do {
      if ((undefined *)0x23001dbf < puVar2) {
        return 0;
      }
      iVar1 = FUN_0e063b10(param_1,**(undefined4 **)(puVar2 + 4),0,param_3,param_4);
      puVar2 = puVar2 + 0x18;
    } while (iVar1 == 0);
  }
  return iVar1;
}


