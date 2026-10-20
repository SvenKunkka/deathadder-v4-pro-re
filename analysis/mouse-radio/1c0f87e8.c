/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f87e8. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0f87e8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint *puVar5;
  undefined8 uVar6;
  
  uVar6 = FUN_1c0f868c(param_2,param_3);
  puVar1 = (undefined4 *)uVar6;
  if (puVar1 == (undefined4 *)0x0) {
    return 0xffffffed;
  }
  FUN_1c100d84(param_1 + 4,(int)((ulonglong)uVar6 >> 0x20),0xffffffff,0xffffffff);
  if (-1 < (int)((uint)*(byte *)(param_1 + 0x60) << 0x1f)) {
    iVar4 = puVar1[1];
    puVar5 = puVar1 + 5;
    if ((-1 < (int)(*puVar5 << 0x1f)) &&
       ((iVar2 = *(int *)(iVar4 + 4), iVar2 == 0 || (param_1 == iVar2)))) {
      iVar2 = FUN_1c0f8400(param_1,param_3,param_4);
      if (iVar2 == 0) {
        uVar3 = 0xffffffc3;
      }
      else {
        *puVar1 = 0;
        if (*(undefined4 **)(iVar2 + 0x10) == (undefined4 *)0x0) {
          *(undefined4 **)(iVar2 + 0xc) = puVar1;
          *(undefined4 **)(iVar2 + 0x10) = puVar1;
        }
        else {
          **(undefined4 **)(iVar2 + 0x10) = puVar1;
          *(undefined4 **)(iVar2 + 0x10) = puVar1;
        }
        *puVar5 = *puVar5 | 1;
        uVar3 = 0;
        *(int *)(iVar4 + 4) = param_1;
      }
      goto LAB_1c0f881c;
    }
  }
  uVar3 = 0xfffffff0;
LAB_1c0f881c:
  FUN_1c100e80(param_1 + 4);
  return uVar3;
}


