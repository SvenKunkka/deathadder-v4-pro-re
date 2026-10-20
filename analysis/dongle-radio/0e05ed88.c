/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ed88. Types and names are inferred; NOT original source. */

uint FUN_0e05ed88(int *param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_40;
  int local_3c;
  undefined1 auStack_38 [2];
  ushort local_36;
  int local_34;
  int local_30 [3];
  
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    uVar1 = 0xfffffff3;
  }
  else {
    iVar2 = param_1[2];
    local_3c = param_1[3];
    uVar3 = 0;
    local_40 = iVar2;
    iVar4 = local_3c;
    while( true ) {
      uVar1 = FUN_0e05e4b0(param_1,param_2,local_40,local_3c,iVar2,iVar4,auStack_38,&local_40);
      iVar4 = local_3c;
      uVar3 = uVar3 + 1;
      if ((int)uVar1 < 0) break;
      if (uVar1 == 0) {
        return 0xfffffffe;
      }
      uVar1 = FUN_0e05e450(param_1,&local_40);
      if (uVar1 != 0) {
        return uVar1;
      }
      if (param_5 < uVar3) {
        if (local_34 != param_2) {
          return 0xfffffffe;
        }
        uVar1 = (uint)local_36;
        if (uVar1 == 0) {
          return 0xfffffffe;
        }
        if (uVar1 < 9) {
          if (param_3 != 0) {
            if (uVar1 <= param_4) {
              param_4 = uVar1;
            }
            FUN_0e06f3f8(param_3,local_30,param_4);
          }
        }
        else if (param_3 != 0) {
          if (uVar1 <= param_4) {
            param_4 = uVar1;
          }
          uVar3 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                            (param_1[0xe],iVar4 * param_1[6] + *param_1 + local_30[0],param_3,
                             param_4);
          if (uVar3 != 0) {
            return uVar3;
          }
        }
        return uVar1;
      }
      iVar2 = param_1[2];
      iVar4 = param_1[3];
    }
  }
  return uVar1;
}


