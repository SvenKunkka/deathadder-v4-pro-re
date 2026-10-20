/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06195c. Types and names are inferred; NOT original source. */

int FUN_0e06195c(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined4 local_30;
  undefined4 uStack_2c;
  int local_24 [2];
  
  local_24[0] = param_2;
  uVar4 = FUN_0e06e9e0(&local_30);
  uVar3 = uStack_2c;
  uVar2 = local_30;
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar6 = (uint)*(ushort *)(param_1 + 0x12);
  if (uVar6 == 0) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar8);
    }
    InstructionSynchronizationBarrier(0xf);
    if (param_4 != 0 || param_3 != 0) {
      FUN_0e06f4ac(uVar4,0,param_3,param_4);
    }
    uVar9 = FUN_0e06d038(param_1);
    if ((int)uVar9 != 0) goto joined_r0x0e0619a8;
LAB_0e061a02:
    iVar7 = 0;
  }
  else {
    if (uVar6 < *(ushort *)(param_1 + 0x10)) {
      uVar9 = FUN_0e06d038(param_1,uVar6,0,0);
      if ((int)uVar9 != 0) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar8);
        }
        InstructionSynchronizationBarrier(0xf);
        goto joined_r0x0e0619a8;
      }
      uVar6 = (uint)*(ushort *)(param_1 + 0x12);
    }
    *(short *)(param_1 + 0x12) = (short)uVar6 + -1;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar8);
    }
    InstructionSynchronizationBarrier(0xf);
    iVar7 = *(ushort *)(param_1 + 0x10) - uVar6;
    iVar5 = iVar7 * (*(byte *)(param_1 + 0x14) + 0x1b & 0xfffffffc) + *(int *)(param_1 + 0x20);
    uVar9 = CONCAT44(iVar7,iVar5);
    *(char *)(iVar5 + 10) = (char)(param_1 + -0x23001c7c >> 2) * '9';
    *(undefined1 *)(iVar5 + 0xb) = *(undefined1 *)(param_1 + 0x14);
joined_r0x0e0619a8:
    iVar7 = (int)uVar9;
    if (local_24[0] == 0) {
      *(undefined4 *)(iVar7 + 0x14) = 0;
    }
    else {
      FUN_0e06ea70(&local_30,(int)((ulonglong)uVar9 >> 0x20),uVar2,uVar3);
      iVar5 = (**(code **)**(undefined4 **)(&DAT_23001c98 + (uint)*(byte *)(iVar7 + 10) * 0x24))
                        (iVar7,local_24,local_30,uStack_2c);
      *(int *)(iVar7 + 0x14) = iVar5;
      if (iVar5 == 0) {
        FUN_0e06d020(&DAT_23001c7c + (uint)*(byte *)(iVar7 + 10) * 0x24,iVar7);
        goto LAB_0e061a02;
      }
    }
    *(short *)(iVar7 + 0x12) = (short)local_24[0];
    *(undefined2 *)(iVar7 + 8) = 1;
    *(undefined4 *)(iVar7 + 4) = 0;
    FUN_0e06f3aa(iVar7 + 0x18,0,*(undefined1 *)(iVar7 + 0xb));
    *(undefined2 *)(iVar7 + 0x10) = 0;
    *(undefined4 *)(iVar7 + 0xc) = *(undefined4 *)(iVar7 + 0x14);
  }
  return iVar7;
}


