/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e2d90. Types and names are inferred; NOT original source. */

undefined1 FUN_0e0e2d90(int param_1)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  
  bVar2 = DAT_2f0118e4;
  uVar10 = (uint)DAT_2f0118e4;
  iVar4 = FUN_0e0e2e9c();
  iVar11 = iVar4;
  if (((param_1 != -1) && (iVar11 = param_1, iVar4 != -1)) && (iVar11 = iVar4, param_1 <= iVar4)) {
    iVar11 = param_1;
  }
  uVar12 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar12 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x20 < uVar5)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar4 = uVar10 * 0xc;
  if (*(char *)(iVar4 + 0x2f011708) == '\0') {
    puVar6 = (undefined4 *)FUN_0e0e2f14(uVar10,iVar11);
    if (puVar6 == (undefined4 *)0x0) {
      *(undefined1 *)(iVar4 + 0x2f011714) = 0;
    }
    else {
      uVar7 = puVar6[1];
      uVar8 = puVar6[2];
      *(undefined4 *)(iVar4 + 0x2f011714) = *puVar6;
      *(undefined4 *)(iVar4 + 0x2f011718) = uVar7;
      *(undefined4 *)(iVar4 + 0x2f01171c) = uVar8;
    }
  }
  else {
    *(undefined4 *)(iVar4 + 0x2f011714) = *(undefined4 *)(iVar4 + 0x2f011708);
    *(undefined4 *)(iVar4 + 0x2f011718) = *(undefined4 *)(iVar4 + 0x2f01170c);
    *(undefined4 *)(iVar4 + 0x2f01171c) = *(undefined4 *)(iVar4 + 0x2f011710);
    *(undefined1 *)(iVar4 + 0x2f011708) = 0;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar12);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar3 = 0;
  if (*(char *)(uVar10 * 0xc + 0x2f011714) != '\0') {
    uVar5 = *(uint *)(uVar10 * 0xc + 0x2f01171c);
    if ((uVar5 != 0) && (iVar11 != -1)) {
      if (uVar5 < 0xffffffe1) {
        uVar5 = uVar5 + 0x1f >> 5;
      }
      else {
        uVar5 = 0x8000000;
      }
      FUN_0e0e44bc(iVar11 - uVar5,1);
    }
    FUN_0e0e5c48();
    FUN_0e0e2cdc(1);
    puVar9 = (uint *)((uint)(bVar2 >> 5) * 4 + 0x2f011728);
    *puVar9 = *puVar9 | 1 << (uVar10 & 0x1f);
    FUN_0e0e3be4(*(undefined1 *)(uVar10 * 0xc + 0x2f011714),
                 *(undefined1 *)(uVar10 * 0xc + 0x2f011715));
    FUN_0e0e2d34();
    FUN_0e0e5c70();
    uVar3 = 1;
  }
  return uVar3;
}


