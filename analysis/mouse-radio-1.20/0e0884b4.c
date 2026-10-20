/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0884b4. Types and names are inferred; NOT original source. */

uint FUN_0e0884b4(int *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffea;
  }
  FUN_0e097680(*(undefined4 *)(*param_1 + 4),4,param_3,*param_1,param_4);
  DataMemoryBarrier(0x1b);
  iVar1 = *param_1;
  iVar5 = *(int *)(iVar1 + 0x10);
  uVar3 = **(uint **)(iVar1 + 4);
  uVar4 = *(uint *)(iVar1 + 0xc);
  uVar6 = param_1[2];
  if ((uVar3 & 3) != 0) {
    return 0xffffffea;
  }
  uVar2 = 0;
  if (uVar3 != uVar6) {
    FUN_0e097680(iVar5 + uVar6,4,*(uint **)(iVar1 + 4),iVar1,param_4);
    uVar2 = (*(ushort *)(iVar5 + uVar6) & 0xff) << 8 | (uint)(*(ushort *)(iVar5 + uVar6) >> 8);
    if (param_2 != 0) {
      if (param_3 < uVar2) {
        return 0xfffffff4;
      }
      if (uVar3 < uVar6) {
        iVar1 = uVar4 - uVar6;
      }
      else {
        iVar1 = -uVar6;
      }
      if (uVar2 + 4 <= uVar3 + iVar1) {
        uVar6 = uVar6 + 4;
        if (uVar4 <= uVar6) {
          uVar6 = uVar6 - uVar4 * (uVar6 / uVar4);
        }
        uVar3 = uVar4 - uVar6;
        if (uVar2 <= uVar4 - uVar6) {
          uVar3 = uVar2;
        }
        FUN_0e097680(iVar5 + uVar6,uVar3);
        FUN_0e09739c(param_2,iVar5 + uVar6,uVar3);
        if (uVar3 < uVar2) {
          FUN_0e097680(iVar5,uVar2 - uVar3);
          FUN_0e09739c(param_2 + uVar3,*(undefined4 *)(*param_1 + 0x10),uVar2 - uVar3);
        }
        uVar3 = uVar2 + 3 + uVar6 & 0xfffffffc;
        if (uVar4 <= uVar3) {
          uVar3 = uVar3 - uVar4 * (uVar3 / uVar4);
        }
        param_1[2] = uVar3;
        **(uint **)*param_1 = uVar3;
        DataMemoryBarrier(0x1b);
        FUN_0e097600(*(undefined4 *)*param_1,4);
        return uVar2;
      }
      return 0xfffffff5;
    }
  }
  return uVar2;
}


