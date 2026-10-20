/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e084ce8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e084ce8(undefined1 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_1c;
  int iStack_18;
  undefined1 local_14;
  
  iVar1 = DAT_0e084d40;
  *(undefined1 *)(DAT_0e084d40 + 0x14) = param_1;
  if (param_3 != 0) {
    FUN_0e0974c4(iVar1 + 0x15);
  }
  iStack_18 = param_3 + 1;
  local_1c = DAT_0e084d44;
  local_14 = 2;
  iVar2 = (**(code **)(*(int *)(DAT_0e084d48 + 8) + 8))(DAT_0e084d48,&local_1c,1,0x6a);
  if (iVar2 == 0) {
    *(undefined1 *)(iVar1 + 6) = 0;
    return 1;
  }
  *(char *)(iVar1 + 6) = *(char *)(iVar1 + 6) + '\x01';
  return 0;
}


