/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e087eac. Types and names are inferred; NOT original source. */

int FUN_0e087eac(int *param_1,undefined1 param_2,undefined1 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 extraout_r1;
  uint uVar2;
  int iVar3;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  
  iVar1 = *(int *)(*param_1 + 0x1c);
  iVar3 = param_4 * *(int *)(*param_1 + 0x20);
  *(int *)(iVar1 + iVar3) = param_5;
  DataMemoryBarrier(0x1b);
  FUN_0e097638(iVar1 + iVar3,param_5 + 4);
  iVar1 = *param_1;
  local_22 = (undefined1)param_4;
  local_24 = param_2;
  local_23 = param_3;
  FUN_0e094d84(param_1 + 0x1e,extraout_r1,0xffffffff,0xffffffff);
  iVar1 = FUN_0e08840c(iVar1,param_1 + 2,&local_24,3);
  FUN_0e094e80(param_1 + 0x1e);
  if (iVar1 < 0) {
    uVar2 = *(uint *)(*param_1 + 0x20);
    if ((!CARRY4(uVar2,param_5 + 3U)) &&
       (iVar3 = FUN_0e086410(*(undefined4 *)(*param_1 + 0x28),(uVar2 + param_5 + 3U) / uVar2,param_4
                            ), -1 < iVar3)) {
      FUN_0e0950a8(param_1 + 0x27);
    }
  }
  return iVar1;
}


