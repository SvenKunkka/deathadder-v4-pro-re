/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0853cc. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0853cc(undefined1 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined1 local_29;
  undefined1 *local_28;
  undefined4 local_24;
  undefined1 local_20;
  int local_1c;
  uint local_18;
  undefined1 local_14;
  
  iVar1 = DAT_0e085450;
  *(undefined1 *)(DAT_0e085450 + 0x28) = param_1;
  if (param_2 < 2) {
    local_28 = (undefined1 *)(iVar1 + 0x28);
  }
  else {
    local_28 = &local_29;
    local_29 = param_1;
  }
  local_1c = iVar1 + 0x80;
  local_24 = 1;
  local_20 = 0;
  local_14 = 7;
  local_18 = param_2;
  iVar2 = (**(code **)(*(int *)(DAT_0e085454 + 8) + 8))(DAT_0e085454,&local_28,2,100);
  if (iVar2 == 0) {
    *(undefined1 *)(iVar1 + 0xd) = 0;
    *(undefined1 *)(iVar1 + 0xc) = 0;
    return 1;
  }
  *(char *)(iVar1 + 0xc) = *(char *)(iVar1 + 0xc) + '\x01';
  return 0;
}


