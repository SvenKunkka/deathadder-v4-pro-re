/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302a1c4. Types and names are inferred; NOT original source. */

void FUN_2302a1c4(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_1c [2];
  
  iVar1 = ram_candidate_230213a4(&DAT_0e097868,param_1,param_2 & 0xffff);
  if ((iVar1 < 0) && (param_2 != 0)) {
    uVar2 = 0;
    do {
      uVar3 = param_2 - uVar2;
      if (3 < uVar3) {
        uVar3 = 4;
      }
      local_1c[0] = FUN_23028b00();
      iVar1 = param_1 + uVar2;
      uVar2 = uVar2 + uVar3;
      thunk_FUN_0e09739c(iVar1,local_1c,uVar3);
    } while (uVar2 < param_2);
  }
  return;
}


