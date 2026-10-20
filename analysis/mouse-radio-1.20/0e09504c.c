/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e09504c. Types and names are inferred; NOT original source. */

void FUN_0e09504c(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  
  do {
    while( true ) {
      uVar12 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar12 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x20 < uVar6)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      puVar11 = *(undefined4 **)(param_1 + 0x90);
      if (puVar11 != (undefined4 *)0x0) break;
      uVar6 = *(uint *)(param_1 + 0xa8);
      *(uint *)(param_1 + 0xa8) = uVar6 & 0xfffffffb;
      if ((int)(uVar6 << 0x1d) < 0) {
        do {
          iVar7 = FUN_0e096220(param_1 + 0xa0,1,0);
        } while (iVar7 != 0);
      }
      FUN_0e09628c(&DAT_23007670,uVar12,param_1 + 0x98,0,0xffffffff,0xffffffff,0);
    }
    uVar8 = *puVar11;
    *(undefined4 *)(param_1 + 0x90) = uVar8;
    if (puVar11 == *(undefined4 **)(param_1 + 0x94)) {
      *(undefined4 *)(param_1 + 0x94) = uVar8;
    }
    *(uint *)(param_1 + 0xa8) = *(uint *)(param_1 + 0xa8) | 2;
    puVar11[3] = puVar11[3] & 0xfffffffb | 1;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar12);
    }
    InstructionSynchronizationBarrier(0xf);
    (*(code *)puVar11[1])(puVar11);
    uVar12 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar12 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x20 < uVar6)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    uVar6 = puVar11[3];
    uVar10 = uVar6 & 0xfffffffe;
    if ((int)(uVar6 << 0x1b) < 0) {
      puVar11[3] = uVar6 & 0xffffffee;
      FUN_0e094f80(puVar11 + 4);
      uVar10 = puVar11[3];
    }
    else {
      puVar11[3] = uVar10;
    }
    puVar4 = DAT_23002548;
    if (((int)(uVar10 << 0x1e) < 0) &&
       (puVar11[3] = uVar10 & 0xfffffffd, puVar4 != (undefined4 *)0x0)) {
      puVar9 = (undefined4 *)puVar4[1];
      puVar2 = (undefined4 *)0x0;
      puVar5 = (undefined4 *)*puVar4;
      while (puVar3 = puVar5, puVar11 != puVar9) {
        if (puVar3 == (undefined4 *)0x0) goto LAB_0e0950d2;
        puVar2 = puVar4;
        puVar5 = (undefined4 *)*puVar3;
        puVar4 = puVar3;
        puVar9 = (undefined4 *)puVar3[1];
      }
      puVar11 = (undefined4 *)*puVar4;
      if (puVar2 == (undefined4 *)0x0) {
        DAT_23002548 = puVar11;
        if (DAT_2300254c == puVar4) {
          DAT_2300254c = puVar11;
        }
      }
      else {
        *puVar2 = puVar11;
        if (DAT_2300254c == puVar4) {
          DAT_2300254c = puVar2;
        }
      }
      *puVar4 = 0;
      FUN_0e094f80(puVar4 + 2);
    }
LAB_0e0950d2:
    uVar6 = *(uint *)(param_1 + 0xa8) & 0xfffffffd;
    *(uint *)(param_1 + 0xa8) = uVar6;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar12);
    }
    InstructionSynchronizationBarrier(0xf);
    if (-1 < (int)(uVar6 << 0x17)) {
      FUN_0e09600c();
    }
  } while( true );
}


