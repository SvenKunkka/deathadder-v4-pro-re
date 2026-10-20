/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230293b8. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_230293b8(undefined4 param_1,uint param_2)

{
  code *pcVar1;
  
  if (param_2 < 0x140) {
    *(int *)(*(int *)(&DAT_0e09b688 + (param_2 >> 5) * 4) + 8) = 1 << (param_2 & 0x1f);
    return;
  }
  _NMI = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0x230293d8);
  (*pcVar1)();
}


