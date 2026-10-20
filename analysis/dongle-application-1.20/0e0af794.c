/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0af794. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0af794(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  
  do {
    while( true ) {
      uVar10 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar10 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar8 = getBasePriority(), uVar8 == 0 || 0x20 < uVar8)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      puVar9 = *(undefined4 **)(param_1 + 0x90);
      if (puVar9 != (undefined4 *)0x0) break;
      iVar3 = FUN_0e0b229e(param_1 + 0xa8,2);
      if (iVar3 != 0) {
        do {
          iVar3 = FUN_0e0b2610(param_1 + 0xa0,1,0);
        } while (iVar3 != 0);
      }
      FUN_0e0b00fc(0x2f011bda,uVar10,param_1 + 0x98,0,0xffffffff,0xffffffff,0);
    }
    uVar7 = *puVar9;
    *(undefined4 *)(param_1 + 0x90) = uVar7;
    if (puVar9 == *(undefined4 **)(param_1 + 0x94)) {
      *(undefined4 *)(param_1 + 0x94) = uVar7;
    }
    *(uint *)(param_1 + 0xa8) = *(uint *)(param_1 + 0xa8) | 2;
    puVar9[3] = puVar9[3] & 0xfffffffb | 1;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar10);
    }
    InstructionSynchronizationBarrier(0xf);
    (*(code *)puVar9[1])(puVar9);
    uVar10 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar10 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar8 = getBasePriority(), uVar8 == 0 || 0x20 < uVar8)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    uVar8 = puVar9[3];
    if ((int)(uVar8 << 0x1b) < 0) {
      puVar9[3] = uVar8 & 0xffffffee;
      FUN_0e0af700(puVar9 + 4);
    }
    else {
      puVar9[3] = uVar8 & 0xfffffffe;
    }
    puVar2 = _DAT_2f011bbc;
    if (((int)(puVar9[3] << 0x1e) < 0) &&
       (puVar9[3] = puVar9[3] & 0xfffffffd, puVar2 != (undefined4 *)0x0)) {
      puVar5 = (undefined4 *)0x0;
      puVar6 = (undefined4 *)*puVar2;
      while (puVar4 = puVar2, puVar4 != (undefined4 *)0x0) {
        if (puVar9 == (undefined4 *)puVar4[1]) {
          puVar9 = (undefined4 *)*puVar4;
          if (puVar5 == (undefined4 *)0x0) {
            _DAT_2f011bbc = puVar9;
            if (_DAT_2f011bc0 == puVar4) {
              _DAT_2f011bc0 = puVar9;
            }
          }
          else {
            *puVar5 = puVar9;
            if (_DAT_2f011bc0 == puVar4) {
              _DAT_2f011bc0 = puVar5;
            }
          }
          *puVar4 = 0;
          FUN_0e0af700(puVar4 + 2);
          break;
        }
        puVar2 = puVar6;
        puVar5 = puVar4;
        if (puVar6 != (undefined4 *)0x0) {
          puVar6 = (undefined4 *)*puVar6;
        }
      }
    }
    uVar8 = *(uint *)(param_1 + 0xa8) & 0xfffffffd;
    *(uint *)(param_1 + 0xa8) = uVar8;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar10);
    }
    InstructionSynchronizationBarrier(0xf);
    if (-1 < (int)(uVar8 << 0x17)) {
      FUN_0e0affac();
    }
  } while( true );
}


