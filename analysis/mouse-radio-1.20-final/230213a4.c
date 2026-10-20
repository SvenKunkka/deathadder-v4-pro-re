/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230213a4. Types and names are inferred; NOT original source. */

undefined4 ram_candidate_230213a4(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int local_24;
  
  if (param_3 == 0) {
    return 0;
  }
  do {
    uVar1 = param_3;
    if (3 < param_3) {
      uVar1 = 4;
    }
    uVar3 = DAT_230021bc ^ DAT_230021b4;
    uVar2 = DAT_230021b0 ^ DAT_230021b8;
    DAT_230021b8 = uVar2 ^ DAT_230021b4 << 9;
    local_24 = DAT_230021b0 +
               (DAT_230021bc + DAT_230021b0 >> 0x19 | (DAT_230021bc + DAT_230021b0) * 0x80);
    param_3 = param_3 - uVar1 & 0xffff;
    DAT_230021b0 = DAT_230021b0 ^ uVar3;
    DAT_230021b4 = DAT_230021b4 ^ uVar2;
    DAT_230021bc = uVar3 >> 0x15 | uVar3 << 0xb;
    thunk_FUN_0e09739c(param_2,&local_24,uVar1);
    param_2 = param_2 + uVar1;
  } while (param_3 != 0);
  return 0;
}


