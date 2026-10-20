/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23028c94. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x23028cde) */

undefined4 ram_candidate_23028c94(uint *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *param_1;
  if (-1 < (int)((uVar3 >> (param_2 & 0xff)) << 0x1f)) {
    uVar2 = 1 << (param_2 & 0xff);
    bVar1 = false;
    if (*param_1 == uVar3) {
      *param_1 = uVar3 | uVar2;
      bVar1 = true;
    }
    while (!bVar1) {
      bVar1 = false;
      if (*param_1 == *param_1) {
        *param_1 = uVar2 | *param_1;
        bVar1 = true;
      }
    }
    return 0xbad0000;
  }
  return 0xbad0004;
}


