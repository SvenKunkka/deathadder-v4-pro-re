/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302944c. Types and names are inferred; NOT original source. */

void FUN_2302944c(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *param_1 +
          (uint)(*(ushort *)
                  (&DAT_2300130c +
                  ((uint)*(byte *)(param_1 + 1) * 0x52 +
                   ((uint)(byte)(&DAT_0e09b6b0)[param_2 >> 5] + (param_2 & 0x1f) & 0xff) + 8) * 2)
                >> 0xd) * 4;
  *(uint *)(iVar1 + 0x510) = *(uint *)(iVar1 + 0x510) & 0xffefffff | (uint)(param_3 != 0) << 0x14;
  return;
}


