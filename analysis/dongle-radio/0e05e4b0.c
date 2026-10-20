/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05e4b0. Types and names are inferred; NOT original source. */

int FUN_0e05e4b0(int *param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,
                uint *param_7,int *param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  byte local_41;
  int local_40;
  int iStack_3c;
  undefined4 local_38;
  uint local_34;
  uint uStack_30;
  uint uStack_2c;
  
  iVar4 = -1;
  local_40 = param_3;
  iStack_3c = param_4;
  do {
    while( true ) {
      iVar2 = iStack_3c;
      iVar1 = local_40;
      iVar3 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                        (param_1[0xe],iStack_3c * param_1[6] + *param_1 + local_40,&local_38,0x10);
      if (iVar3 != 0) {
        return iVar3;
      }
      uVar6 = FUN_0e05e450(param_1,&local_40);
      if ((int)uVar6 != 0) {
        return (int)uVar6;
      }
      if (local_34 == param_2) break;
      if (iStack_3c == param_6 && local_40 == param_5) goto LAB_0e05e552;
    }
    if (iVar4 < 0 || iVar2 != iVar4) {
      iVar4 = FUN_0e05e1d4(param_1,(int)((ulonglong)uVar6 >> 0x20),iVar1,iVar2,&local_41);
      if (iVar4 != -2) {
        if (iVar4 != 0) {
          return iVar4;
        }
        goto LAB_0e05e538;
      }
      local_41 = 0;
      uVar5 = 0;
    }
    else {
LAB_0e05e538:
      uVar5 = (uint)local_41;
    }
    if (((local_38 >> 8 & 0xff) == uVar5) &&
       (uVar5 = FUN_0e05d33c(0xff,(int)&local_38 + 1,0xf), (local_38 & 0xff) == uVar5)) {
      iVar4 = 1;
      goto LAB_0e05e556;
    }
    iVar4 = iVar2;
  } while (iStack_3c != param_6 || local_40 != param_5);
LAB_0e05e552:
  iVar4 = 0;
LAB_0e05e556:
  *param_7 = local_38;
  param_7[3] = uStack_2c;
  param_7[1] = local_34;
  param_7[2] = uStack_30;
  *param_8 = iVar1;
  param_8[1] = iVar2;
  return iVar4;
}


