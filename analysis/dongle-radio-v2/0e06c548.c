/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c548. Types and names are inferred; NOT original source. */

int FUN_0e06c548(int param_1,uint param_2,int param_3,int param_4,int *param_5,int *param_6)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *local_34;
  int local_30;
  int local_2c [2];
  
  if ((param_2 & 0x10000) == 0) {
    local_34 = (int *)0x0;
    piVar6 = param_5;
    param_5 = (int *)0x0;
  }
  else {
    local_34 = param_6;
    *param_5 = 0;
    *param_6 = 0;
    param_6 = (int *)0x0;
    piVar6 = (int *)0x0;
  }
  pbVar2 = (byte *)FUN_0e06d8e4();
  if (pbVar2 == (byte *)0x0) {
    iVar3 = FUN_0e0687ac();
    iVar4 = DAT_0e06c69c + 1;
    pbVar2 = (byte *)(DAT_0e06c69c + iVar3 * 0x24);
    pbVar2[4] = 0;
    pbVar2[5] = 0;
    pbVar2[6] = 0;
    pbVar2[7] = 0;
    *(undefined2 *)(iVar4 + iVar3 * 0x24) = 0x1ff;
    FUN_0e06d8d8(pbVar2);
  }
  else {
    pbVar2[2] = pbVar2[2] + 1;
  }
  bVar1 = (*(byte **)(param_1 + 8))[1];
  *(uint *)(param_3 + -5) =
       *pbVar2 | 0x80 | (param_2 & 0xff) << 8 | (uint)pbVar2[1] << 0x10 |
       (uint)**(byte **)(param_1 + 8) << 0x18;
  *(byte *)(param_3 + -1) = bVar1;
  uVar8 = *(undefined4 *)(pbVar2 + 4);
  *(int **)(pbVar2 + 4) = piVar6;
  uVar7 = *(undefined4 *)(pbVar2 + 8);
  *(int **)(pbVar2 + 8) = param_6;
  if (*(char *)(*(int *)(param_1 + 8) + 0x14) == '\0') {
    iVar3 = -0x13;
  }
  else {
    pcVar5 = *(code **)(**(int **)(param_1 + 0xc) + 4);
    if (pcVar5 == (code *)0x0) {
      iVar3 = -5;
    }
    else {
      iVar3 = (*pcVar5)(*(int **)(param_1 + 0xc),param_3 + -5,param_4 + 5);
      if (-1 < iVar3) {
        do {
          FUN_0e068784(pbVar2 + 0xc,local_2c,&local_30);
          if (local_2c[0] == 1) goto LAB_0e06c5d4;
          iVar4 = FUN_0e06c3f4(pbVar2,local_2c[0],local_30);
        } while (iVar4 != 1);
        if (param_5 == (int *)0x0) {
          if ((*(int *)(**(int **)(param_1 + 0xc) + 0x10) != 0) &&
             (*(code **)(pbVar2 + 4) != (code *)0x0)) {
            (**(code **)(pbVar2 + 4))
                      (param_1,local_2c[0] + 5,local_30 + -5,*(undefined4 *)(pbVar2 + 8));
            FUN_0e06bdf4(param_1,local_2c[0] + 5);
          }
        }
        else {
          *param_5 = local_2c[0] + 5;
          *local_34 = local_30 + -5;
        }
      }
    }
  }
LAB_0e06c5d4:
  bVar1 = pbVar2[2];
  *(undefined4 *)(pbVar2 + 4) = uVar8;
  *(undefined4 *)(pbVar2 + 8) = uVar7;
  pbVar2[2] = bVar1 - 1;
  if ((byte)(bVar1 - 1) != 0) {
    return iVar3;
  }
  FUN_0e06d8d8();
  FUN_0e0687f0(*pbVar2);
  return iVar3;
}


