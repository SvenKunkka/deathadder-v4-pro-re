/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e092520. Types and names are inferred; NOT original source. */

void FUN_0e092520(byte *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = thunk_FUN_23028c54(&DAT_2300149c,param_1);
  if (iVar1 != 0xbad0000) {
    return;
  }
  iVar1 = (uint)*param_1 * 0xc;
  iVar2 = (uint)*param_1 * 0xc;
  *(undefined4 *)(&DAT_23007338 + iVar2) = 0;
  *(undefined4 *)(&DAT_2300733c + iVar1) = 0;
  *(undefined4 *)(&DAT_23007340 + iVar1) = 0;
  *(undefined2 *)(&DAT_23007340 + iVar2) = 0xffff;
  (&DAT_23007342)[iVar1] = 0xff;
  return;
}


