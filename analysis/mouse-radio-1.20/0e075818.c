/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e075818. Types and names are inferred; NOT original source. */

undefined4 FUN_0e075818(int param_1,uint param_2,byte *param_3)

{
  undefined4 uVar1;
  
  if ((int)((uint)*(ushort *)
                   (&DAT_2300130c +
                   ((uint)*(byte *)(param_1 + 4) * 0x52 +
                    ((uint)(byte)(&DAT_0e09b6b0)[param_2 >> 5] + (param_2 & 0x1f) & 0xff) + 8) * 2)
           << 0x1a) < 0) {
    uVar1 = 0xbad0000;
    *param_3 = (byte)(*(ushort *)
                       (&DAT_2300130c +
                       ((uint)*(byte *)(param_1 + 4) * 0x52 +
                        ((uint)(byte)(&DAT_0e09b6b0)[param_2 >> 5] + (param_2 & 0x1f) & 0xff) + 8) *
                       2) >> 0xd);
  }
  else {
    uVar1 = 0xbad0004;
  }
  return uVar1;
}


