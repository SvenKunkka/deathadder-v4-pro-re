/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e075b7c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e075b7c(undefined4 param_1,uint param_2)

{
  code *pcVar1;
  
  if (param_2 < 0x140) {
    *(int *)(*(int *)(&DAT_0e09b688 + (param_2 >> 5) * 4) + 4) = 1 << (param_2 & 0x1f);
    return;
  }
  _Reset = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0xe075b9c);
  (*pcVar1)();
}


