/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08d2c4. Types and names are inferred; NOT original source. */

undefined4 FUN_0e08d2c4(int param_1,uint param_2,uint param_3,ushort *param_4)

{
  int iVar1;
  ushort uVar2;
  int extraout_r2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  ushort *puVar7;
  
  iVar5 = *(int *)(param_1 + 8);
  puVar7 = param_4;
  if ((int)(param_2 << 0x18) < 0) {
    iVar4 = *(int *)(*(int *)(param_1 + 0x10) + ((param_2 & 0xf) + 0x10) * 4);
    if (iVar4 == 0) {
      return 0xffffffed;
    }
    (**(code **)(iVar5 + 0x3c))();
    uVar3 = *param_4;
    iVar1 = (uint)*(byte *)(iVar4 + 0x12) << 0x1a;
  }
  else {
    iVar4 = *(int *)(*(int *)(param_1 + 0x10) + (param_2 & 0xf) * 4);
    if (iVar4 == 0) {
      return 0xffffffed;
    }
    (**(code **)(iVar5 + 0x3c))();
    uVar3 = *param_4;
    iVar1 = (uint)*(byte *)(iVar4 + 0x12) << 0x19;
  }
  if (iVar1 < 0) {
    uVar6 = *(ushort *)(iVar4 + 0x10);
    if (((uVar3 & 0x7ff) <= (uVar6 & 0x7ff)) &&
       (iVar4 = FUN_0e08d0e0(*(undefined4 *)(iVar4 + 0x10),param_3,uVar3,uVar3 & 0x7ff,puVar7),
       iVar4 != 0)) {
      if (extraout_r2 == 0) {
        if (*(int *)(*(int *)(param_1 + 0x10) + 0x80) << 0x1f < 0) {
          uVar3 = 0x400;
          uVar2 = 0x200;
        }
        else {
          uVar3 = 0x40;
          uVar2 = uVar3;
        }
        if ((param_3 & 3) == 2) {
          if (uVar2 <= uVar6) {
            uVar6 = uVar2;
          }
        }
        else {
          if ((param_3 & 3) != 3) goto LAB_0e08d30e;
          if (uVar3 <= uVar6) {
            uVar6 = uVar3;
          }
        }
        *param_4 = uVar6;
      }
LAB_0e08d30e:
      (**(code **)(iVar5 + 0x40))(param_1);
      return 0;
    }
  }
  (**(code **)(iVar5 + 0x40))(param_1);
  return 0xffffff7a;
}


