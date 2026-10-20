/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1326. Types and names are inferred; NOT original source. */

uint FUN_0e0b1326(int *param_1,int *param_2,int *param_3,undefined4 param_4,int param_5,int param_6)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  uint local_30;
  int local_2c [2];
  
  iVar6 = *param_1;
  uVar4 = (*param_2 + 3 + *(uint *)(iVar6 + 0x20)) / *(uint *)(iVar6 + 0x20);
  bVar1 = false;
  while( true ) {
    uVar7 = FUN_0e0b0ea2(*(undefined4 *)(iVar6 + 0x28),uVar4,&local_30);
    uVar2 = (uint)uVar7;
    if (uVar2 != 0xffffffe4) break;
    if (param_5 == 0 && param_6 == 0) {
      if (bVar1) {
        FUN_0e0af700(param_1 + 0x27);
      }
      goto LAB_0e0b13f4;
    }
    uVar2 = FUN_0e0af748(param_1 + 0x27,(int)((ulonglong)uVar7 >> 0x20),param_5,param_6);
    if ((int)uVar2 < 0) {
      if (bVar1) {
        FUN_0e0af700(param_1 + 0x27);
      }
      if (uVar2 != 0xffffffe4) goto LAB_0e0b138c;
      goto LAB_0e0b13f4;
    }
    bVar1 = true;
  }
  if (bVar1) {
    FUN_0e0af700(param_1 + 0x27);
  }
  if ((int)uVar2 < 0) {
LAB_0e0b138c:
    local_30 = uVar2;
    if (local_30 == 0xffffffea) {
LAB_0e0b13f4:
      local_30 = 0xfffffff4;
    }
  }
  else {
    if (*param_2 == 0) {
      local_2c[0] = 0;
      uVar4 = local_30;
      do {
        uVar4 = uVar4 + 1;
        if (*(uint *)(iVar6 + 0x24) <= uVar4) break;
        FUN_0e0b0e54(*(undefined4 *)(iVar6 + 0x28),uVar4,local_2c);
      } while (local_2c[0] == 0);
      uVar4 = uVar4 - local_30;
    }
    iVar5 = *(int *)(iVar6 + 0x20) * uVar4 + -4;
    *param_2 = iVar5;
    iVar3 = *(int *)(iVar6 + 0x1c);
    iVar6 = *(int *)(iVar6 + 0x20) * local_30;
    *(int *)(iVar3 + iVar6) = iVar5;
    *param_3 = iVar3 + iVar6 + 4;
  }
  return local_30;
}


