/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ac474. Types and names are inferred; NOT original source. */

int FUN_0e0ac474(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined8 uVar3;
  
  iVar1 = FUN_0e0b1c04(param_1,5,param_3,param_4,param_4);
  iVar2 = 0;
  if (iVar1 != 0) {
    if (DAT_2f011bd9 == '\0') {
      param_2 = 0;
      iVar2 = 0;
    }
    else {
      uVar3 = FUN_0e0b2442();
      iVar2 = thunk_FUN_0e0af748(param_1 + 0x14,(int)((ulonglong)uVar3 >> 0x20),(int)uVar3 + -1,
                                 ((int)uVar3 != 0) - 1);
      if (iVar2 < 0) {
        return -0x10;
      }
    }
    if (*(int *)(param_1 + 0xc) == 0) {
      iVar2 = -0x78;
    }
    else {
      iVar1 = *(int *)(param_1 + 0xc) + -1;
      *(int *)(param_1 + 0xc) = iVar1;
      if (iVar1 == 0) {
        if (param_2 == 0) {
          iVar2 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0x10));
          if (iVar2 < 0) {
            *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          }
          else {
            *(undefined1 *)(param_1 + 4) = 1;
          }
        }
        else {
          *(undefined1 *)(param_1 + 4) = 2;
          FUN_0e0afa68(param_1 + 0x30,param_2,extraout_r2,extraout_r3);
        }
      }
    }
    if (DAT_2f011bd9 != '\0') {
      thunk_FUN_0e0af700(param_1 + 0x14);
    }
  }
  return iVar2;
}


