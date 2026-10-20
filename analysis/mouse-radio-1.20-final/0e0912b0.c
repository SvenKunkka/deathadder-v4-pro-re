/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0912b0. Types and names are inferred; NOT original source. */

bool FUN_0e0912b0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 1);
  if (((&DAT_2300727c)[uVar1 * 5] == 0) && (*(int *)(*param_1 + 0x104) != 0)) {
    *(undefined4 *)(*param_1 + 0x104) = 0;
    (&DAT_23007284)[uVar1 * 0x14] = 1;
  }
  return (&DAT_23007284)[uVar1 * 0x14] != '\x02';
}


