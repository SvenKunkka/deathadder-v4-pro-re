/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e256c. Types and names are inferred; NOT original source. */

void FUN_1c0e256c(uint *param_1)

{
  int iVar1;
  
  thunk_EXT_FUN_0e089fd4((*param_1 & 0x1fffff) >> 0xc);
  *(undefined4 *)(*param_1 + 0x200) = 0;
  iVar1 = DAT_1c0e25b8;
  *(undefined4 *)(*param_1 + 0x308) = 0xffffffff;
  *(undefined4 *)(*param_1 + 4) = 1;
  *(undefined4 *)(*param_1 + 0xc) = 1;
  *(undefined1 *)(iVar1 + (uint)(byte)param_1[1] * 0xc + 8) = 1;
  *(undefined1 *)(iVar1 + (uint)(byte)param_1[1] * 0xc + 8) = 0;
  return;
}


