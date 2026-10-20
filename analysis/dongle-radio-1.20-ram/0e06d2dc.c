/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d2dc. Types and names are inferred; NOT original source. */

uint FUN_0e06d2dc(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

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
LAB_0e06d30e:
    uVar5 = 0xfffffff0;
  }
  else {
    if ((int)(uVar2 << 0x1d) < 0) goto LAB_0e06d2ee;
    iVar6 = *param_2;
    if (iVar6 == 0) {
      iVar6 = param_1[2];
      *param_2 = iVar6;
      if ((int)(param_1[3] << 0x1f) < 0) goto LAB_0e06d376;
      uVar2 = 1;
      if (iVar6 != 0) goto LAB_0e06d320;
LAB_0e06d380:
      uVar5 = 0xffffffea;
      goto LAB_0e06d2ee;
    }
    if ((int)(uVar2 << 0x1f) < 0) {
LAB_0e06d376:
      iVar6 = param_1[2];
      uVar2 = 2;
      *param_2 = iVar6;
      if (iVar6 == 0) goto LAB_0e06d380;
    }
    else {
      uVar2 = 1;
    }
LAB_0e06d320:
    if (DAT_23007170 == iVar6) {
      iVar1 = FUN_0e06d830();
      iVar3 = *(int *)(iVar6 + 0xa8);
      if (iVar1 != 0) goto LAB_0e06d32c;
      if (iVar3 << 0x1f < 0) {
        if ((-1 < iVar3 << 0x1c) || (iVar3 << 0x1d < 0)) goto LAB_0e06d340;
        goto LAB_0e06d30e;
      }
    }
    else {
      iVar3 = *(int *)(iVar6 + 0xa8);
LAB_0e06d32c:
      if (iVar3 << 0x1f < 0) {
        if ((-1 < iVar3 << 0x1d) && (-1 < iVar3 << 0x1c)) {
LAB_0e06d340:
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
          FUN_0e06e3f4(iVar6 + 0x98,0,0,puVar4,param_4);
          param_1[3] = param_1[3] | 4;
          param_1[2] = *param_2;
          return uVar2;
        }
        goto LAB_0e06d30e;
      }
    }
    uVar5 = 0xffffffed;
  }
LAB_0e06d2ee:
  *param_2 = 0;
  return uVar5;
}


