/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e075ba8. Types and names are inferred; NOT original source. */

void FUN_0e075ba8(int *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *param_1 +
          (uint)(*(ushort *)
                  (DAT_0e075be8 +
                  ((uint)*(byte *)(param_1 + 1) * 0x52 +
                   ((uint)*(byte *)(DAT_0e075be4 + (param_2 >> 5)) + (param_2 & 0x1f) & 0xff) + 8) *
                  2) >> 0xd) * 4;
  *(uint *)(iVar1 + 0x510) = *(uint *)(iVar1 + 0x510) | 3;
  return;
}


