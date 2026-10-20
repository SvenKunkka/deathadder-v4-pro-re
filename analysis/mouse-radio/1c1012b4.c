/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c1012b4. Types and names are inferred; NOT original source. */

uint FUN_1c1012b4(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = param_1[3];
  uVar5 = (uVar2 & 3) >> 1;
  if ((int)(uVar2 << 0x1e) < 0) {
LAB_1c1012e6:
    uVar5 = 0xfffffff0;
  }
  else {
    if ((int)(uVar2 << 0x1d) < 0) goto LAB_1c1012c6;
    iVar6 = *param_2;
    if (iVar6 == 0) {
      iVar6 = param_1[2];
      *param_2 = iVar6;
      if ((int)(param_1[3] << 0x1f) < 0) goto LAB_1c10134e;
      uVar2 = 1;
      if (iVar6 != 0) goto LAB_1c1012f8;
LAB_1c101358:
      uVar5 = 0xffffffea;
      goto LAB_1c1012c6;
    }
    if ((int)(uVar2 << 0x1f) < 0) {
LAB_1c10134e:
      iVar6 = param_1[2];
      uVar2 = 2;
      *param_2 = iVar6;
      if (iVar6 == 0) goto LAB_1c101358;
    }
    else {
      uVar2 = 1;
    }
LAB_1c1012f8:
    if (*(int *)(DAT_1c101378 + 8) == iVar6) {
      iVar1 = FUN_1c101808();
      iVar3 = *(int *)(iVar6 + 0xa8);
      if (iVar1 != 0) goto LAB_1c101304;
      if (iVar3 << 0x1f < 0) {
        if ((-1 < iVar3 << 0x1c) || (iVar3 << 0x1d < 0)) goto LAB_1c101318;
        goto LAB_1c1012e6;
      }
    }
    else {
      iVar3 = *(int *)(iVar6 + 0xa8);
LAB_1c101304:
      if (iVar3 << 0x1f < 0) {
        if ((-1 < iVar3 << 0x1d) && (-1 < iVar3 << 0x1c)) {
LAB_1c101318:
          *param_1 = 0;
          puVar4 = *(undefined4 **)(iVar6 + 0x94);
          if (puVar4 == (undefined4 *)0x0) {
            *(undefined4 **)(iVar6 + 0x90) = param_1;
            *(undefined4 **)(iVar6 + 0x94) = param_1;
          }
          else {
            *puVar4 = param_1;
            *(undefined4 **)(iVar6 + 0x94) = param_1;
          }
          FUN_1c102348(iVar6 + 0x98,0,0,puVar4,param_4);
          param_1[3] = param_1[3] | 4;
          param_1[2] = *param_2;
          return uVar2;
        }
        goto LAB_1c1012e6;
      }
    }
    uVar5 = 0xffffffed;
  }
LAB_1c1012c6:
  *param_2 = 0;
  return uVar5;
}


