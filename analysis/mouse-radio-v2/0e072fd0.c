/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e072fd0. Types and names are inferred; NOT original source. */

void FUN_0e072fd0(int param_1)

{
  int iVar1;
  
  iVar1 = *DAT_0e072fdc +
          (uint)(*(ushort *)
                  (DAT_0e075c38 +
                  ((uint)*(byte *)(DAT_0e072fdc + 1) * 0x52 +
                   (*(byte *)(DAT_0e075c34 + 1) + 2 & 0xff) + 8) * 2) >> 0xd) * 4;
  *(uint *)(iVar1 + 0x510) = *(uint *)(iVar1 + 0x510) & 0xffefffff | (uint)(param_1 != 0) << 0x14;
  return;
}


