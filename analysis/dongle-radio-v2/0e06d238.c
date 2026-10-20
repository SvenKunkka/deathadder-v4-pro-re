/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d238. Types and names are inferred; NOT original source. */

void FUN_0e06d238(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  
  puVar5 = DAT_0e06d370;
  do {
    while( true ) {
      uVar13 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar13 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      puVar12 = *(undefined4 **)(param_1 + 0x90);
      if (puVar12 != (undefined4 *)0x0) break;
      uVar6 = *(uint *)(param_1 + 0xa8);
      *(uint *)(param_1 + 0xa8) = uVar6 & 0xfffffffb;
      if ((int)(uVar6 << 0x1d) < 0) {
        do {
          iVar8 = FUN_0e06e490(param_1 + 0xa0,1,0);
        } while (iVar8 != 0);
      }
      FUN_0e06e4fc(DAT_0e06d374,uVar13,param_1 + 0x98,0,0xffffffff,0xffffffff,0);
    }
    uVar9 = *puVar12;
    *(undefined4 *)(param_1 + 0x90) = uVar9;
    if (puVar12 == *(undefined4 **)(param_1 + 0x94)) {
      *(undefined4 *)(param_1 + 0x94) = uVar9;
    }
    *(uint *)(param_1 + 0xa8) = *(uint *)(param_1 + 0xa8) | 2;
    puVar12[3] = puVar12[3] & 0xfffffffb | 1;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar13);
    }
    InstructionSynchronizationBarrier(0xf);
    (*(code *)puVar12[1])(puVar12);
    uVar13 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar13 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    uVar6 = puVar12[3];
    uVar11 = uVar6 & 0xfffffffe;
    if ((int)(uVar6 << 0x1b) < 0) {
      puVar12[3] = uVar6 & 0xffffffee;
      FUN_0e06d16c(puVar12 + 4);
      uVar11 = puVar12[3];
    }
    else {
      puVar12[3] = uVar11;
    }
    if ((int)(uVar11 << 0x1e) < 0) {
      puVar7 = (undefined4 *)*puVar5;
      puVar12[3] = uVar11 & 0xfffffffd;
      if (puVar7 != (undefined4 *)0x0) {
        puVar10 = (undefined4 *)puVar7[1];
        puVar3 = (undefined4 *)0x0;
        puVar4 = (undefined4 *)*puVar7;
        while (puVar2 = puVar7, puVar12 != puVar10) {
          if (puVar4 == (undefined4 *)0x0) goto LAB_0e06d2be;
          puVar10 = (undefined4 *)puVar4[1];
          puVar7 = puVar4;
          puVar3 = puVar2;
          puVar4 = (undefined4 *)*puVar4;
        }
        uVar9 = *puVar2;
        if (puVar3 == (undefined4 *)0x0) {
          *puVar5 = uVar9;
          if ((undefined4 *)puVar5[1] == puVar2) {
            puVar5[1] = uVar9;
          }
        }
        else {
          *puVar3 = uVar9;
          if ((undefined4 *)puVar5[1] == puVar2) {
            puVar5[1] = puVar3;
          }
        }
        *puVar2 = 0;
        FUN_0e06d16c(puVar2 + 2);
      }
    }
LAB_0e06d2be:
    uVar6 = *(uint *)(param_1 + 0xa8) & 0xfffffffd;
    *(uint *)(param_1 + 0xa8) = uVar6;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar13);
    }
    InstructionSynchronizationBarrier(0xf);
    if (-1 < (int)(uVar6 << 0x17)) {
      FUN_0e06e278();
    }
  } while( true );
}


