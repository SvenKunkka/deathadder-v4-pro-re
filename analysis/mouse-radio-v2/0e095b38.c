/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e095b38. Types and names are inferred; NOT original source. */

void FUN_0e095b38(int *param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  byte bVar7;
  bool bVar8;
  
  if (param_3 == 0) {
    bVar7 = 0x10;
  }
  else {
    bVar7 = 8;
  }
  bVar1 = *(byte *)((int)param_1 + 0xd);
  if ((bVar7 & bVar1) != 0) {
    piVar3 = *(int **)(DAT_0e095c74 + 8);
    goto joined_r0x0e095bac;
  }
  if ((char)bVar1 < '\0') {
    *(byte *)((int)param_1 + 0xd) = bVar7 | bVar1 & 0x7f;
    iVar5 = *param_1;
    piVar3 = (int *)param_1[1];
    *piVar3 = iVar5;
    *(int **)(iVar5 + 4) = piVar3;
    *param_1 = 0;
    param_1[1] = 0;
    if (bVar7 == 8) goto LAB_0e095bd6;
LAB_0e095b72:
    bVar8 = false;
    piVar3 = *(int **)(DAT_0e095c74 + 8);
  }
  else {
    *(byte *)((int)param_1 + 0xd) = bVar7 | bVar1;
    if (bVar7 != 8) goto LAB_0e095b72;
LAB_0e095bd6:
    if (param_1[2] != 0) {
      iVar5 = *param_1;
      piVar3 = (int *)param_1[1];
      *piVar3 = iVar5;
      *(int **)(iVar5 + 4) = piVar3;
      *param_1 = 0;
      param_1[1] = 0;
      *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xfd;
      param_1[2] = 0;
    }
    FUN_0e0966bc(param_1 + 6);
    piVar3 = (int *)param_1[0x16];
    while ((param_1 + 0x16 != piVar3 && (piVar3 != (int *)0x0))) {
      iVar5 = *piVar3;
      piVar6 = (int *)piVar3[1];
      *piVar6 = iVar5;
      *(int **)(iVar5 + 4) = piVar6;
      *(byte *)((int)piVar3 + 0xd) = *(byte *)((int)piVar3 + 0xd) & 0xfd;
      *piVar3 = 0;
      piVar3[1] = 0;
      piVar3[2] = 0;
      FUN_0e0966bc(piVar3 + 6);
      piVar3[0x23] = 0;
      FUN_0e0959e4(piVar3);
      piVar3 = (int *)param_1[0x16];
    }
    piVar3 = *(int **)(DAT_0e095c74 + 8);
    if (param_1 == piVar3) {
      uVar4 = 0;
      bVar8 = (bool)isCurrentModePrivileged();
      if (bVar8) {
        uVar4 = getCurrentExceptionNumber();
        uVar4 = uVar4 & 0x1ff;
      }
      bVar8 = uVar4 != 0;
    }
    else {
      bVar8 = false;
    }
  }
  iVar5 = DAT_0e095c74;
  piVar6 = *(int **)(DAT_0e095c74 + 0x1c);
  if ((piVar6 == DAT_0e095c78) || (piVar6 == (int *)0x0)) {
    piVar6 = *(int **)(DAT_0e095c74 + 0xc);
  }
  if (piVar6 != piVar3) {
    FUN_0e096440(piVar6);
  }
  *(int **)(iVar5 + 0x18) = piVar6;
  iVar2 = DAT_0e095c7c;
  if ((bVar7 != 0x10) && (bVar8)) {
    *(undefined4 *)(DAT_0e095c7c + 0x74) = 0;
    *(undefined4 *)(iVar2 + 0x78) = 0;
    *(undefined2 *)(iVar2 + 0xc) = 0x101;
    FUN_0e096dc0(iVar2);
    *(int *)(iVar5 + 8) = iVar2;
  }
  DataMemoryBarrier(0x1f);
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0x9f;
  piVar3 = *(int **)(iVar5 + 8);
joined_r0x0e095bac:
  if (piVar3 == param_1) {
    uVar4 = 0;
    bVar8 = (bool)isCurrentModePrivileged();
    if (bVar8) {
      uVar4 = getCurrentExceptionNumber();
      uVar4 = uVar4 & 0x1ff;
    }
    if (uVar4 == 0) {
      FUN_0e089ed8(param_2);
      return;
    }
  }
  bVar8 = (bool)isCurrentModePrivileged();
  if (bVar8) {
    setBasePriority(param_2);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


