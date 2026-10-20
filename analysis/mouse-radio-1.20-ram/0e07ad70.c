/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07ad70. Types and names are inferred; NOT original source. */

undefined4 FUN_0e07ad70(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_1c = 1000000;
  local_18 = 0x200;
  uStack_14 = param_1;
  iVar1 = thunk_FUN_23029d04(&DAT_0e098b6c,&local_1c,&LAB_0e07a8c8_1);
  if (iVar1 != 0xbad0000) {
    FUN_0e085e6c("nrfx_timer_init failed with: %d\n",iVar1);
  }
  FUN_0e089e70(0x29,6,0);
  DAT_2300389c = param_1;
  iVar1 = FUN_0e092520(&DAT_23007711);
  if (iVar1 == 0xbad0000) {
    FUN_0e085e6c("ppi_radio_start = %d\n",DAT_23007711);
    uVar2 = 0;
  }
  else {
    FUN_0e085e6c("Failed to allocate gppi channel.\n");
    uVar2 = 0xfffffff2;
  }
  return uVar2;
}


