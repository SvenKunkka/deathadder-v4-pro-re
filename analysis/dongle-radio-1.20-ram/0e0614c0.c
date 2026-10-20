/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0614c0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0e0614c0(uint param_1,uint *param_2)

{
  if (param_1 <= ((_DAT_e000ed90 & 0xffff) >> 8) - 1) {
    _DAT_e000ed98 = param_1;
    _DAT_e000ed9c = (ushort)param_2[2] & 0x1f | *param_2 & 0xffffffe0;
    _DAT_e000eda0 =
         (param_2[1] - 1) + (*param_2 & 0xffffffe0) & 0xffffffe0 |
         (*(ushort *)((int)param_2 + 10) & 7) << 1 | 1;
    return param_1;
  }
  return 0xffffffea;
}


