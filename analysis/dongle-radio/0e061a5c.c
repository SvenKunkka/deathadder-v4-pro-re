/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061a5c. Types and names are inferred; NOT original source. */

int FUN_0e061a5c(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined4 local_30;
  undefined4 uStack_2c;
  int local_24 [2];
  
  local_24[0] = param_2;
  uVar4 = FUN_0e06ea7c(&local_30);
  uVar3 = uStack_2c;
  uVar2 = local_30;
  uVar9 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar9 = getBasePriority();
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
      setBasePriority(uVar9);
    }
    InstructionSynchronizationBarrier(0xf);
    if (param_4 != 0 || param_3 != 0) {
      FUN_0e06f548(uVar4,0,param_3,param_4);
    }
    uVar10 = FUN_0e06d0d4(param_1);
    if ((int)uVar10 != 0) goto joined_r0x0e061aa8;
LAB_0e061b02:
    iVar7 = 0;
  }
  else {
    if (uVar6 < *(ushort *)(param_1 + 0x10)) {
      uVar10 = FUN_0e06d0d4(param_1,uVar6,0,0);
      if ((int)uVar10 != 0) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar9);
        }
        InstructionSynchronizationBarrier(0xf);
        goto joined_r0x0e061aa8;
      }
      uVar6 = (uint)*(ushort *)(param_1 + 0x12);
    }
    *(short *)(param_1 + 0x12) = (short)uVar6 + -1;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar9);
    }
    InstructionSynchronizationBarrier(0xf);
    iVar7 = *(ushort *)(param_1 + 0x10) - uVar6;
    iVar8 = iVar7 * (*(byte *)(param_1 + 0x14) + 0x1b & 0xfffffffc) + *(int *)(param_1 + 0x20);
    uVar10 = CONCAT44(iVar7,iVar8);
    *(char *)(iVar8 + 10) = (char)DAT_0e061b8c * (char)(param_1 - DAT_0e061b88 >> 2);
    *(undefined1 *)(iVar8 + 0xb) = *(undefined1 *)(param_1 + 0x14);
joined_r0x0e061aa8:
    iVar7 = (int)uVar10;
    if (local_24[0] == 0) {
      *(undefined4 *)(iVar7 + 0x14) = 0;
    }
    else {
      FUN_0e06eb0c(&local_30,(int)((ulonglong)uVar10 >> 0x20),uVar2,uVar3);
      iVar8 = DAT_0e061b88;
      iVar5 = (**(code **)**(undefined4 **)
                            (DAT_0e061b88 + (uint)*(byte *)(iVar7 + 10) * 0x24 + 0x1c))
                        (iVar7,local_24,local_30,uStack_2c);
      *(int *)(iVar7 + 0x14) = iVar5;
      if (iVar5 == 0) {
        FUN_0e06d0bc(iVar8 + (uint)*(byte *)(iVar7 + 10) * 0x24,iVar7);
        goto LAB_0e061b02;
      }
    }
    *(short *)(iVar7 + 0x12) = (short)local_24[0];
    *(undefined2 *)(iVar7 + 8) = 1;
    *(undefined4 *)(iVar7 + 4) = 0;
    FUN_0e06f446(iVar7 + 0x18,0,*(undefined1 *)(iVar7 + 0xb));
    *(undefined2 *)(iVar7 + 0x10) = 0;
    *(undefined4 *)(iVar7 + 0xc) = *(undefined4 *)(iVar7 + 0x14);
  }
  return iVar7;
}


