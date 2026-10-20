/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d1ac. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05d1ac(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_1c = 1000000;
  local_18 = 0x200;
  uStack_14 = param_1;
  iVar1 = FUN_0e069ee8(&DAT_0e06fd14,&local_1c,&LAB_0e05cd04_1);
  if (iVar1 != 0xbad0000) {
    FUN_0e05d634("nrfx_timer_init failed with: %d\n",iVar1);
  }
  FUN_0e0612f0(0x29,5,0);
  DAT_2300661c = param_1;
  iVar1 = FUN_0e06a658(&DAT_230071df);
  if (iVar1 == 0xbad0000) {
    FUN_0e05d634("ppi_radio_start = %d\n",DAT_230071df);
    uVar2 = 0;
  }
  else {
    FUN_0e05d634("Failed to allocate gppi channel.\n");
    uVar2 = 0xfffffff2;
  }
  return uVar2;
}


