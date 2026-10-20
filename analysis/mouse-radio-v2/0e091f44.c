/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091f44. Types and names are inferred; NOT original source. */

undefined4 FUN_0e091f44(int *param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(DAT_0e091f74 + (uint)*(byte *)(param_1 + 1) * 0x10 + 0xc) != '\0') {
    *(undefined4 *)(*param_1 + 0x520) = DAT_0e091f78;
    uVar1 = DAT_0e091f7c;
    *(undefined4 *)(*param_1 + 4) = 1;
    *(undefined4 *)(*param_1 + 0x520) = 0;
    return uVar1;
  }
  return DAT_0e091f80;
}


