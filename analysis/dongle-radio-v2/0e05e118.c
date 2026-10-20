/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05e118. Types and names are inferred; NOT original source. */

int FUN_0e05e118(int *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  byte local_38;
  char local_37;
  ushort local_36;
  int local_30;
  
  uVar6 = 0;
  uVar3 = *param_2 + param_1[0x10] * -2;
  uVar4 = param_2[1] - (uint)(*param_2 < (uint)(param_1[0x10] * 2));
  *param_2 = uVar3;
  param_2[1] = uVar4;
  *param_3 = 0;
  param_3[1] = uVar4;
  uVar5 = uVar4;
  if (uVar3 != 0) {
    do {
      iVar1 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                        (param_1[0xe],uVar5 * param_1[6] + *param_1 + uVar3,&local_38,0x10);
      if (iVar1 != 0) {
        return iVar1;
      }
      if (((char)param_1[8] == local_37) &&
         (uVar2 = FUN_0e05d33c(0xff,&local_37,0xf), local_38 == uVar2)) {
        uVar2 = (uint)local_36;
        uVar6 = 0;
        if (8 < uVar2) {
          uVar6 = *(uint *)param_1[0xf];
          if (1 < uVar6) {
            uVar2 = (uVar2 - 1) + uVar6 & -uVar6;
          }
          uVar6 = local_30 + uVar2;
          *param_3 = uVar6;
          param_3[1] = uVar4;
        }
        *param_2 = uVar3;
        param_2[1] = uVar5;
      }
      bVar7 = uVar3 < (uint)param_1[0x10];
      uVar3 = uVar3 - param_1[0x10];
      uVar5 = uVar5 - bVar7;
    } while (uVar4 <= uVar5 && (uint)(uVar3 <= uVar6) <= uVar4 - uVar5);
  }
  return 0;
}


