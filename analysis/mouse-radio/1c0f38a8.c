/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f38a8. Types and names are inferred; NOT original source. */

int FUN_1c0f38a8(int *param_1,int *param_2,int *param_3,undefined4 param_4,int param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  int local_30;
  int local_2c [2];
  
  iVar5 = *param_1;
  bVar1 = false;
  uVar3 = (*param_2 + 3 + *(uint *)(iVar5 + 0x20)) / *(uint *)(iVar5 + 0x20);
  while (uVar6 = FUN_1c0f234c(*(undefined4 *)(iVar5 + 0x28),uVar3,&local_30), iVar2 = (int)uVar6,
        iVar2 == -0x1c) {
    if (param_5 == 0 && param_6 == 0) {
      if (bVar1) {
        FUN_1c1010a8(param_1 + 0x27);
      }
      goto LAB_1c0f396a;
    }
    iVar2 = FUN_1c1010f0(param_1 + 0x27,(int)((ulonglong)uVar6 >> 0x20),param_5,param_6);
    if (iVar2 < 0) {
      if (bVar1) {
        FUN_1c1010a8(param_1 + 0x27);
      }
      if (iVar2 != -0x1c) goto LAB_1c0f397c;
      goto LAB_1c0f396a;
    }
    bVar1 = true;
  }
  if (bVar1) {
    FUN_1c1010a8(param_1 + 0x27);
  }
  if (iVar2 < 0) {
LAB_1c0f397c:
    if (iVar2 != -0x16) {
      return iVar2;
    }
LAB_1c0f396a:
    local_30 = -0xc;
  }
  else {
    if (*param_2 == 0) {
      uVar3 = local_30 + 1;
      local_2c[0] = 0;
      if (uVar3 < *(uint *)(iVar5 + 0x24)) {
        do {
          FUN_1c0f22f8(*(undefined4 *)(iVar5 + 0x28),uVar3,local_2c);
          if (local_2c[0] != 0) break;
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint *)(iVar5 + 0x24));
        uVar3 = uVar3 - local_30;
      }
      else {
        uVar3 = 1;
      }
    }
    iVar4 = *(int *)(iVar5 + 0x20) * uVar3 + -4;
    *param_2 = iVar4;
    iVar2 = *(int *)(iVar5 + 0x1c);
    iVar5 = *(int *)(iVar5 + 0x20) * local_30;
    *(int *)(iVar2 + iVar5) = iVar4;
    *param_3 = iVar2 + iVar5 + 4;
  }
  return local_30;
}


