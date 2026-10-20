/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ac230. Types and names are inferred; NOT original source. */

undefined1 FUN_0e0ac230(int param_1)

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
  
  bVar2 = DAT_2f011ba8;
  uVar10 = (uint)DAT_2f011ba8;
  iVar4 = FUN_0e0ac33c();
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
  if (*(char *)(iVar4 + 0x2f0119a0) == '\0') {
    puVar6 = (undefined4 *)FUN_0e0ac3b4(uVar10,iVar11);
    if (puVar6 == (undefined4 *)0x0) {
      *(undefined1 *)(iVar4 + 0x2f0119ac) = 0;
    }
    else {
      uVar7 = puVar6[1];
      uVar8 = puVar6[2];
      *(undefined4 *)(iVar4 + 0x2f0119ac) = *puVar6;
      *(undefined4 *)(iVar4 + 0x2f0119b0) = uVar7;
      *(undefined4 *)(iVar4 + 0x2f0119b4) = uVar8;
    }
  }
  else {
    *(undefined4 *)(iVar4 + 0x2f0119ac) = *(undefined4 *)(iVar4 + 0x2f0119a0);
    *(undefined4 *)(iVar4 + 0x2f0119b0) = *(undefined4 *)(iVar4 + 0x2f0119a4);
    *(undefined4 *)(iVar4 + 0x2f0119b4) = *(undefined4 *)(iVar4 + 0x2f0119a8);
    *(undefined1 *)(iVar4 + 0x2f0119a0) = 0;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar12);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar3 = 0;
  if (*(char *)(uVar10 * 0xc + 0x2f0119ac) != '\0') {
    uVar5 = *(uint *)(uVar10 * 0xc + 0x2f0119b4);
    if ((uVar5 != 0) && (iVar11 != -1)) {
      if (uVar5 < 0xffffffe1) {
        uVar5 = uVar5 + 0x1f >> 5;
      }
      else {
        uVar5 = 0x8000000;
      }
      FUN_0e0adf4c(iVar11 - uVar5,1);
    }
    FUN_0e0aff34();
    FUN_0e0ac17c(1);
    puVar9 = (uint *)((uint)(bVar2 >> 5) * 4 + 0x2f0119c0);
    *puVar9 = *puVar9 | 1 << (uVar10 & 0x1f);
    FUN_0e0ad218(*(undefined1 *)(uVar10 * 0xc + 0x2f0119ac),
                 *(undefined1 *)(uVar10 * 0xc + 0x2f0119ad));
    FUN_0e0ac1d4();
    FUN_0e0aff5c();
    uVar3 = 1;
  }
  return uVar3;
}


