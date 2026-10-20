/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0af8d8. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0e0af8d8(undefined4 *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  uVar2 = param_1[3];
  uVar5 = (uVar2 & 3) >> 1;
  if ((int)(uVar2 << 0x1e) < 0) {
LAB_0e0af942:
    uVar5 = 0xfffffff0;
  }
  else {
    if ((int)(uVar2 << 0x1d) < 0) goto LAB_0e0af922;
    if (*param_2 == 0) {
      *param_2 = param_1[2];
    }
    bVar6 = (int)(param_1[3] << 0x1f) < 0;
    if (bVar6) {
      uVar5 = 2;
      *param_2 = param_1[2];
    }
    iVar4 = *param_2;
    if (!bVar6) {
      uVar5 = 1;
    }
    if (iVar4 == 0) {
      uVar5 = 0xffffffea;
      goto LAB_0e0af922;
    }
    if (_DAT_2f011ba0 == iVar4) {
      iVar1 = FUN_0e0b2442();
      iVar3 = *(int *)(iVar4 + 0xa8);
      if (iVar1 != 0) goto LAB_0e0af916;
      if (iVar3 << 0x1f < 0) {
        if ((-1 < iVar3 << 0x1c) || (iVar3 << 0x1d < 0)) goto LAB_0e0af954;
        goto LAB_0e0af942;
      }
    }
    else {
      iVar3 = *(int *)(iVar4 + 0xa8);
LAB_0e0af916:
      if (iVar3 << 0x1f < 0) {
        if ((-1 < iVar3 << 0x1d) && (-1 < iVar3 << 0x1c)) {
LAB_0e0af954:
          *param_1 = 0;
          if (*(undefined4 **)(iVar4 + 0x94) == (undefined4 *)0x0) {
            *(undefined4 **)(iVar4 + 0x90) = param_1;
            *(undefined4 **)(iVar4 + 0x94) = param_1;
          }
          else {
            **(undefined4 **)(iVar4 + 0x94) = param_1;
            *(undefined4 **)(iVar4 + 0x94) = param_1;
          }
          FUN_0e0b22d2(iVar4);
          param_1[3] = param_1[3] | 4;
          param_1[2] = *param_2;
          return uVar5;
        }
        goto LAB_0e0af942;
      }
    }
    uVar5 = 0xffffffed;
  }
LAB_0e0af922:
  *param_2 = 0;
  return uVar5;
}


