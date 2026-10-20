/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ac3b4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0e0ac3b4(undefined4 param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  uint local_24;
  undefined4 uStack_20;
  
  uVar6 = param_2;
  uVar1 = param_2;
  if (param_2 + 1 != 0) {
    uVar6 = 0;
    uVar1 = param_2 << 5;
  }
  local_24 = param_2;
  uStack_20 = param_3;
  uVar2 = FUN_0e0ac31c(param_1,&local_24,param_3,param_2 + 1,param_1);
  if (_DAT_2f0119c4 != 0) {
    uVar3 = FUN_0e0b2050();
    uVar8 = 0;
    uVar5 = *(uint *)(_DAT_2f0119c4 + 4) - uVar3;
    if (uVar3 < *(uint *)(_DAT_2f0119c4 + 4)) {
      if (uVar5 == 0) goto LAB_0e0ac422;
    }
    else {
      bVar10 = uVar5 != 0;
      uVar5 = uVar5 - 1;
      uVar8 = (uint)bVar10;
    }
    if ((uVar6 == 0xffffffff && uVar1 == 0xffffffff) ||
       ((int)((uVar6 - uVar8) - (uint)(uVar1 < uVar5)) < 0 ==
        (SBORROW4(uVar6,uVar8) != SBORROW4(uVar6 - uVar8,(uint)(uVar1 < uVar5)))))
    goto LAB_0e0ac400;
  }
LAB_0e0ac422:
  uVar5 = uVar1;
  uVar8 = uVar6;
LAB_0e0ac400:
  iVar7 = (short)((short)uVar2 + -1) * 0xc;
  do {
    if (uVar2 == 0) {
      return 0;
    }
    iVar9 = local_24 + iVar7;
    iVar4 = FUN_0e0ac360(*(undefined1 *)(local_24 + iVar7),*(undefined1 *)(iVar9 + 1));
    if ((iVar4 == 0) && (((int)_DAT_2f0111bc < 0 || (*(uint *)(iVar9 + 8) < _DAT_2f0111bc)))) {
      if (uVar8 == 0xffffffff && uVar5 == 0xffffffff) {
        return iVar9;
      }
      if ((int)(uint)(uVar5 < *(uint *)(iVar9 + 8) + *(int *)(iVar9 + 4)) <= (int)uVar8) {
        return iVar9;
      }
    }
    uVar2 = uVar2 - 1 & 0xffff;
    iVar7 = iVar7 + -0xc;
  } while( true );
}


