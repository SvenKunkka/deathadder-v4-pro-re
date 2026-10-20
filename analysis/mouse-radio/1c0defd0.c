/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0defd0. Types and names are inferred; NOT original source. */

void FUN_1c0defd0(int param_1)

{
  int iVar1;
  
  iVar1 = *DAT_1c0defdc +
          (uint)(*(ushort *)
                  (DAT_1c0e1c38 +
                  ((uint)*(byte *)(DAT_1c0defdc + 1) * 0x52 +
                   (*(byte *)(DAT_1c0e1c34 + 1) + 2 & 0xff) + 8) * 2) >> 0xd) * 4;
  *(uint *)(iVar1 + 0x510) = *(uint *)(iVar1 + 0x510) & 0xffefffff | (uint)(param_1 != 0) << 0x14;
  return;
}


