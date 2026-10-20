/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0abb44. Types and names are inferred; NOT original source. */

void FUN_0e0abb44(undefined4 *param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  code *pcVar2;
  int iVar3;
  ushort uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  code *pcVar10;
  uint uVar11;
  undefined6 uVar12;
  
  uVar4 = *(ushort *)(param_1 + 6);
  if ((int)((uint)uVar4 << 0x1c) < 0) {
    if (param_2 == 1) {
      uVar4 = uVar4 | 0x10;
    }
    else {
      uVar4 = uVar4 | 0x20;
    }
    *(ushort *)(param_1 + 6) = uVar4;
LAB_0e0abb84:
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(param_3);
    }
    InstructionSynchronizationBarrier(0xf);
    return;
  }
  uVar6 = uVar4 & 7;
  if (param_2 != 2) goto switchD_0e0abb6c_caseD_1;
LAB_0e0abb5c:
  iVar3 = FUN_0e0b0fb2(param_1);
  if (iVar3 != 0) {
    uVar4 = *(ushort *)(param_1 + 6);
    switch(iVar3) {
    case 1:
      goto switchD_0e0abb6c_caseD_1;
    default:
      uVar11 = uVar4 & 7;
      if (uVar11 == uVar6) goto LAB_0e0abce4;
      pcVar10 = (code *)0x0;
      puVar8 = (undefined4 *)0x0;
      puVar9 = (undefined4 *)0x0;
      goto LAB_0e0abba0;
    case 3:
      uVar4 = uVar4 & 0xfff8 | 6;
      pcVar10 = *(code **)param_1[4];
      *(ushort *)(param_1 + 6) = uVar4;
      if (uVar6 == 6) goto LAB_0e0abc5e;
      puVar9 = (undefined4 *)0x0;
      uVar11 = 6;
      puVar8 = (undefined4 *)0x0;
      goto LAB_0e0abba0;
    case 4:
      uVar4 = uVar4 & 0xfff8 | 4;
      pcVar10 = *(code **)(param_1[4] + 4);
      *(ushort *)(param_1 + 6) = uVar4;
      if (uVar6 == 4) goto LAB_0e0abc5e;
      puVar9 = (undefined4 *)0x0;
      uVar11 = 4;
      puVar8 = (undefined4 *)0x0;
      goto LAB_0e0abba0;
    case 5:
      uVar4 = uVar4 & 0xfff8 | 5;
      pcVar10 = *(code **)(param_1[4] + 8);
      *(ushort *)(param_1 + 6) = uVar4;
      if (uVar6 == 5) goto LAB_0e0abc5e;
      puVar8 = (undefined4 *)0x0;
      uVar11 = 5;
      puVar9 = puVar8;
      goto LAB_0e0abba0;
    }
  }
  goto LAB_0e0abb84;
switchD_0e0abb6c_caseD_1:
  puVar8 = (undefined4 *)param_1[5];
  uVar4 = *(ushort *)(param_1 + 6);
  if ((int)puVar8 < 0) {
    puVar9 = (undefined4 *)*param_1;
    *param_1 = 0;
    param_1[1] = 0;
    uVar4 = uVar4 & 0xfff8 | 1;
LAB_0e0abd0e:
    *(ushort *)(param_1 + 6) = uVar4;
LAB_0e0abd10:
    uVar4 = *(ushort *)(param_1 + 6);
    pcVar10 = (code *)0x0;
    uVar11 = uVar4 & 7;
    pcVar2 = (code *)0x0;
    if (uVar11 == uVar6) {
LAB_0e0abd20:
      pcVar10 = pcVar2;
      if (puVar9 != (undefined4 *)0x0) {
        *(ushort *)(param_1 + 6) = uVar4 | 8;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(param_3);
        }
        InstructionSynchronizationBarrier(0xf);
        goto LAB_0e0abd32;
      }
LAB_0e0abc5e:
      if (pcVar10 == (code *)0x0) goto LAB_0e0abce4;
      *(ushort *)(param_1 + 6) = uVar4 | 8;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(param_3);
      }
      InstructionSynchronizationBarrier(0xf);
LAB_0e0abc72:
      (*pcVar10)(param_1,0xe0b1037);
    }
    else {
LAB_0e0abba0:
      pcVar2 = pcVar10;
      if (param_1[2] == 0) goto LAB_0e0abd20;
      *(ushort *)(param_1 + 6) = uVar4 | 8;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(param_3);
      }
      InstructionSynchronizationBarrier(0xf);
      puVar5 = (undefined4 *)param_1[2];
      if (puVar5 != (undefined4 *)0x0) {
        puVar7 = (undefined4 *)*puVar5;
        while (puVar5 != (undefined4 *)0x0) {
          (*(code *)puVar5[1])(param_1,puVar5,uVar11,puVar8);
          puVar5 = puVar7;
          if (puVar7 != (undefined4 *)0x0) {
            puVar7 = (undefined4 *)*puVar7;
          }
        }
      }
LAB_0e0abd32:
      while (puVar9 != (undefined4 *)0x0) {
        puVar5 = (undefined4 *)*puVar9;
        FUN_0e0b100a(param_1,puVar9,uVar11,puVar8);
        puVar9 = puVar5;
      }
      if (pcVar10 != (code *)0x0) goto LAB_0e0abc72;
    }
    param_3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      param_3 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x20 < uVar6)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) & 0xfff7;
  }
  else {
    uVar11 = uVar4 & 7;
    if (uVar11 - 5 < 2) {
      uVar4 = uVar4 & 0xfff8;
      puVar9 = (undefined4 *)*param_1;
      *param_1 = 0;
      param_1[1] = 0;
      puVar5 = puVar9;
      if (uVar11 == 6) {
        for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
          *(short *)((int)param_1 + 0x1a) = *(short *)((int)param_1 + 0x1a) + 1;
        }
        uVar4 = uVar4 | 2;
      }
      *(ushort *)(param_1 + 6) = uVar4;
      uVar12 = FUN_0e0b0fb2(param_1);
      if ((int)uVar12 != 0) {
        uVar4 = (ushort)((uint6)uVar12 >> 0x20) | 0x20;
        goto LAB_0e0abd0e;
      }
      goto LAB_0e0abd10;
    }
    if (uVar11 == 4) {
      *(ushort *)(param_1 + 6) = uVar4 & 0xfff8;
      uVar12 = FUN_0e0b0fb2(param_1);
      if ((int)uVar12 != 0) {
        *(ushort *)(param_1 + 6) = (ushort)((uint6)uVar12 >> 0x20) | 0x20;
      }
    }
    uVar4 = *(ushort *)(param_1 + 6);
    uVar11 = uVar4 & 7;
    if (uVar11 != uVar6) {
      pcVar10 = (code *)0x0;
      puVar9 = (undefined4 *)0x0;
      goto LAB_0e0abba0;
    }
  }
LAB_0e0abce4:
  uVar4 = *(ushort *)(param_1 + 6);
  uVar6 = (uint)uVar4;
  if (-1 < (int)(uVar6 << 0x1b)) goto LAB_0e0abd48;
  *(ushort *)(param_1 + 6) = uVar4 & 0xffef;
  uVar6 = uVar6 & 7;
  goto switchD_0e0abb6c_caseD_1;
LAB_0e0abd48:
  if (-1 < (int)(uVar6 << 0x1a)) goto LAB_0e0abb84;
  *(ushort *)(param_1 + 6) = uVar4 & 0xffdf;
  uVar6 = uVar6 & 7;
  goto LAB_0e0abb5c;
}


