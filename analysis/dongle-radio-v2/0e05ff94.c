/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ff94. Types and names are inferred; NOT original source. */

int FUN_0e05ff94(undefined2 *param_1,int *param_2,int *param_3,int *param_4,char param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84 [18];
  undefined1 auStack_3c [36];
  
  iVar1 = FUN_0e060d1c(&local_98,*(undefined4 *)(param_1 + 6));
  if (iVar1 != 0) {
    return iVar1;
  }
  FUN_0e06bddc(local_84,3,local_98,*(undefined4 *)(param_1 + 6),1);
  iVar1 = FUN_0e06bcd0(local_84,3);
  if (iVar1 != 0) {
    iVar1 = FUN_0e06bca4(local_84,3);
    if (((iVar1 == 0) || (iVar1 = FUN_0e06bca4(local_84,*param_1), iVar1 == 0)) ||
       (iVar1 = FUN_0e06bca4(local_84,param_1[1]), iVar1 == 0)) {
      FUN_0e06bd18(local_84);
    }
    else {
      iVar1 = FUN_0e06bd10(local_84,3);
      if (iVar1 != 0) {
        iVar1 = local_84[0] - local_98;
        if (param_5 == '\0') {
          iVar2 = (**(code **)(param_1 + 2))
                            (local_84[0],*(int *)(param_1 + 6) - iVar1,param_2,&local_9c);
          if (iVar2 != 0) {
LAB_0e060126:
            FUN_0e060d54(local_98);
            return -0x47;
          }
        }
        else {
          uVar3 = param_2[1];
          if ((((uint)(*(int *)(param_1 + 6) - iVar1) < uVar3) || (local_84[0] == 0)) ||
             (*param_2 == 0)) goto LAB_0e060126;
          FUN_0e06f3f8(local_84[0],*param_2,uVar3);
          local_9c = uVar3;
        }
        local_94 = local_9c + iVar1;
        iVar1 = FUN_0e060d84(local_98,local_94,&local_90,&local_8c);
        if (iVar1 != 0) {
          if (iVar1 != -0x7a) {
            iVar1 = -5;
          }
          return iVar1;
        }
        thunk_FUN_0e06b39c(local_84,3,local_90,local_8c,1,auStack_3c,0);
        iVar1 = FUN_0e06b8e0(local_84);
        if (iVar1 != 0) {
          iVar1 = FUN_0e06b744(local_84,&local_88);
          if (iVar1 == 0) {
            FUN_0e06b9dc(local_84);
          }
          else {
            iVar1 = FUN_0e06b978(local_84);
            if (iVar1 != 0) {
              if (local_88 != 0) {
                FUN_0e060d6c(local_90);
                return local_88;
              }
              uVar3 = local_8c - (local_84[0] - local_90);
              if (param_5 == '\0') {
                iVar1 = (**(code **)(param_1 + 4))(local_84[0],uVar3,param_3,0);
                if (iVar1 == 0) {
LAB_0e0600e2:
                  if (param_4 != (int *)0x0) {
                    *param_4 = local_90;
                    return 0;
                  }
                  FUN_0e060d6c();
                  return 0;
                }
              }
              else if (((uVar3 <= (uint)param_3[1]) && (*param_3 != 0)) && (local_84[0] != 0)) {
                FUN_0e06f3f8(*param_3,local_84[0],uVar3);
                param_3[1] = uVar3;
                goto LAB_0e0600e2;
              }
              FUN_0e060d6c(local_90);
              return -0x47;
            }
          }
        }
        FUN_0e060d6c(local_90);
        return -0x47;
      }
    }
  }
  FUN_0e060d54(local_98);
  return -0x47;
}


