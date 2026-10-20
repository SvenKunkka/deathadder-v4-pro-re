/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e085360. Types and names are inferred; NOT original source. */

undefined4 FUN_0e085360(undefined1 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_1c;
  int iStack_18;
  undefined1 local_14;
  
  iVar1 = DAT_0e0853c0;
  *(undefined1 *)(DAT_0e0853c0 + 0x28) = param_1;
  if (param_3 != 0) {
    FUN_0e0974c4(iVar1 + 0x29);
  }
  iStack_18 = param_3 + 1;
  local_1c = DAT_0e0853c4;
  local_14 = 2;
  iVar2 = (**(code **)(*(int *)(DAT_0e0853c8 + 8) + 8))(DAT_0e0853c8,&local_1c,1,100);
  if (iVar2 == 0) {
    *(undefined1 *)(iVar1 + 0xd) = 0;
    *(undefined1 *)(iVar1 + 0xc) = 0;
    return 1;
  }
  *(char *)(iVar1 + 0xc) = *(char *)(iVar1 + 0xc) + '\x01';
  return 0;
}


