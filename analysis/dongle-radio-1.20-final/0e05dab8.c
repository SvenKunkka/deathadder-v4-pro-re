/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05dab8. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e05dafa) */

void FUN_0e05dab8(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  code *pcVar2;
  code *pcVar3;
  short sVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  code *pcVar9;
  int *piVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  
  uVar11 = *(ushort *)(param_1 + 6);
  uVar12 = (uint)uVar11;
  if ((uVar11 & 8) != 0) {
    if (param_2 == 1) {
      uVar11 = uVar11 | 0x10;
    }
    else {
      uVar11 = uVar11 | 0x20;
    }
    *(ushort *)(param_1 + 6) = uVar11;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(param_3);
    }
    InstructionSynchronizationBarrier(0xf);
    return;
  }
  do {
    pcVar2 = (code *)(uVar12 & 7);
    if (param_2 == 2) {
      if (pcVar2 == (code *)0x0) {
        if (*param_1 == 0) goto LAB_0e05dc06;
        uVar12 = uVar12 & 0xfffffff8 | 6;
        pcVar2 = *(code **)param_1[4];
        *(short *)(param_1 + 6) = (short)uVar12;
        pcVar9 = (code *)0x6;
        iVar8 = 0;
      }
      else if (pcVar2 == (code *)0x2) {
        if (*(short *)((int)param_1 + 0x1a) != 0) goto LAB_0e05dc06;
        uVar12 = uVar12 & 0xfffffff8 | 4;
        pcVar2 = *(code **)(param_1[4] + 4);
        *(short *)(param_1 + 6) = (short)uVar12;
        pcVar9 = (code *)&Reset;
        iVar8 = 0;
      }
      else {
        if ((pcVar2 != (code *)0x1) || (*param_1 == 0)) {
LAB_0e05dc06:
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(param_3);
          }
          InstructionSynchronizationBarrier(0xf);
          return;
        }
        uVar12 = uVar12 & 0xfffffff8 | 5;
        pcVar2 = *(code **)(param_1[4] + 8);
        *(short *)(param_1 + 6) = (short)uVar12;
        pcVar9 = (code *)0x5;
        iVar8 = 0;
      }
LAB_0e05db2c:
      uVar11 = (ushort)uVar12;
      piVar10 = (int *)0x0;
      if (param_1[2] != 0) {
LAB_0e05db38:
        *(ushort *)(param_1 + 6) = uVar11 | 8;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(param_3);
        }
        InstructionSynchronizationBarrier(0xf);
        piVar5 = (int *)param_1[2];
        if (piVar5 != (int *)0x0) {
          piVar6 = (int *)*piVar5;
          (*(code *)piVar5[1])(param_1,piVar5,pcVar9,iVar8,param_4);
          while (piVar6 != (int *)0x0) {
            iVar7 = *piVar6;
            (*(code *)piVar6[1])(param_1,piVar6,pcVar9,iVar8);
            piVar6 = (int *)iVar7;
          }
        }
        goto joined_r0x0e05dcb8;
      }
      if (pcVar2 == (code *)0x0) goto LAB_0e05db9e;
      *(ushort *)(param_1 + 6) = uVar11 | 8;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(param_3);
      }
      InstructionSynchronizationBarrier(0xf);
LAB_0e05db7a:
      (*pcVar2)(param_1,&LAB_0e05dd7c_1);
LAB_0e05db80:
      param_3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        param_3 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar12 = getBasePriority(), uVar12 == 0 || 0x40 < uVar12)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar12 = (uint)(*(ushort *)(param_1 + 6) & 0xfff7);
      *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) & 0xfff7;
    }
    else {
      iVar8 = param_1[5];
      if (iVar8 < 0) {
        pcVar9 = (code *)0x1;
        uVar12 = uVar12 & 0xfffffff8 | 1;
        piVar10 = (int *)*param_1;
        *(short *)(param_1 + 6) = (short)uVar12;
        *param_1 = 0;
        param_1[1] = 0;
LAB_0e05dcd8:
        if (pcVar2 != pcVar9) {
LAB_0e05dcde:
          uVar11 = (ushort)uVar12;
          if (param_1[2] != 0) {
            pcVar2 = (code *)0x0;
            goto LAB_0e05db38;
          }
        }
      }
      else {
        if ((code *)0x1 < pcVar2 + -5) {
          if (pcVar2 == (code *)&Reset) {
            uVar12 = uVar12 & 0xfffffff8;
            *(short *)(param_1 + 6) = (short)uVar12;
            if (*param_1 == 0) {
              pcVar9 = (code *)0x0;
              pcVar2 = (code *)0x0;
            }
            else {
              uVar12 = uVar12 | 0x20;
              *(short *)(param_1 + 6) = (short)uVar12;
              pcVar9 = (code *)0x0;
              pcVar2 = pcVar9;
            }
            goto LAB_0e05db2c;
          }
          goto LAB_0e05db9e;
        }
        pcVar9 = (code *)0x0;
        uVar13 = uVar12 & 0xfffffff8;
        piVar10 = (int *)*param_1;
        param_1[1] = 0;
        *param_1 = 0;
        if (pcVar2 == (code *)0x6) {
          if (piVar10 != (int *)0x0) {
            sVar4 = *(short *)((int)param_1 + 0x1a);
            piVar5 = piVar10;
            do {
              sVar4 = sVar4 + 1;
              *(short *)((int)param_1 + 0x1a) = sVar4;
              piVar5 = (int *)*piVar5;
            } while (piVar5 != (int *)0x0);
          }
          uVar12 = uVar13 | 2;
          *(short *)(param_1 + 6) = (short)uVar12;
          if (*(short *)((int)param_1 + 0x1a) == 0) {
            uVar12 = uVar13 | 0x22;
            pcVar9 = (code *)0x2;
            *(short *)(param_1 + 6) = (short)uVar12;
          }
          else {
            pcVar9 = (code *)0x2;
          }
          goto LAB_0e05dcd8;
        }
        *(short *)(param_1 + 6) = (short)uVar13;
        uVar12 = uVar13;
        if (pcVar2 != (code *)0x0) goto LAB_0e05dcde;
      }
      if (piVar10 != (int *)0x0) {
        *(ushort *)(param_1 + 6) = (ushort)uVar12 | 8;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(param_3);
        }
        InstructionSynchronizationBarrier(0xf);
        pcVar2 = (code *)0x0;
joined_r0x0e05dcb8:
        while (piVar5 = piVar10, piVar10 != (int *)0x0) {
          while( true ) {
            piVar10 = (int *)*piVar5;
            pcVar3 = (code *)FUN_0e05df10(piVar5 + 1,iVar8);
            if (pcVar3 == (code *)0x0) break;
            (*pcVar3)(param_1,piVar5,pcVar9,iVar8);
            piVar5 = piVar10;
            if (piVar10 == (int *)0x0) goto LAB_0e05db78;
          }
        }
LAB_0e05db78:
        if (pcVar2 != (code *)0x0) goto LAB_0e05db7a;
        goto LAB_0e05db80;
      }
    }
LAB_0e05db9e:
    if ((uVar12 & 0x10) == 0) {
      if ((uVar12 & 0x20) == 0) goto LAB_0e05dc06;
      uVar12 = uVar12 & 0xffffffdf;
      param_2 = 2;
    }
    else {
      param_2 = 1;
      uVar12 = uVar12 & 0xffffffef;
    }
    *(short *)(param_1 + 6) = (short)uVar12;
  } while( true );
}


