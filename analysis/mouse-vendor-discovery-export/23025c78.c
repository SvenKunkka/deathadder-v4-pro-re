
void vendor_rom_23025c78(int param_1,int param_2,uint param_3)

{
  DAT_230029fc = param_1 != 0;
  DAT_230029fd = param_2 != 0;
  if (param_1 != 0) {
    DAT_23002a00 = 0xb;
    return;
  }
  if (param_2 == 0) {
    param_3 = 0x18;
  }
  else if (0x1f < param_3) {
    return;
  }
  DAT_23002a00 = param_3;
  return;
}


