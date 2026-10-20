/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1ad6. Types and names are inferred; NOT original source. */

uint FUN_0e0b1ad6(int *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  if (param_1 != (int *)0x0) {
    FUN_0e0ad960(*(undefined4 *)(*param_1 + 4),4,param_3,*param_1,param_4);
    DataMemoryBarrier(0x1b);
    iVar1 = *param_1;
    uVar5 = *(uint *)(iVar1 + 0xc);
    iVar6 = *(int *)(iVar1 + 0x10);
    uVar4 = **(uint **)(iVar1 + 4);
    uVar3 = param_1[2];
    if ((uVar4 & 3) == 0) {
      if (uVar4 == uVar3) {
        return 0;
      }
      FUN_0e0ad960(iVar6 + uVar3,4);
      uVar2 = (*(ushort *)(iVar6 + uVar3) & 0xff) << 8 | (uint)(*(ushort *)(iVar6 + uVar3) >> 8);
      if (param_2 == 0) {
        return uVar2;
      }
      if (param_3 < uVar2) {
        return 0xfffffff4;
      }
      if (uVar4 < uVar3) {
        iVar1 = uVar5 - uVar3;
      }
      else {
        iVar1 = -uVar3;
      }
      if (uVar2 + 4 <= uVar4 + iVar1) {
        uVar3 = uVar3 + 4;
        if (uVar5 <= uVar3) {
          uVar3 = uVar3 - uVar5 * (uVar3 / uVar5);
        }
        uVar4 = uVar5 - uVar3;
        if (uVar2 <= uVar5 - uVar3) {
          uVar4 = uVar2;
        }
        FUN_0e0ad960(iVar6 + uVar3,uVar4);
        FUN_0e0b280e(param_2,iVar6 + uVar3,uVar4);
        if (uVar4 < uVar2) {
          FUN_0e0ad960(iVar6,uVar2 - uVar4);
          FUN_0e0b280e(param_2 + uVar4,*(undefined4 *)(*param_1 + 0x10),uVar2 - uVar4);
        }
        uVar3 = uVar2 + 3 + uVar3 & 0xfffffffc;
        if (uVar5 <= uVar3) {
          uVar3 = uVar3 - uVar5 * (uVar3 / uVar5);
        }
        param_1[2] = uVar3;
        **(uint **)*param_1 = uVar3;
        DataMemoryBarrier(0x1b);
        FUN_0e0ad944(*(undefined4 *)*param_1,4);
        return uVar2;
      }
      return 0xfffffff5;
    }
  }
  return 0xffffffea;
}


