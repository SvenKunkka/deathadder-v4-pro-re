/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0887fc. Types and names are inferred; NOT original source. */

undefined1 FUN_0e0887fc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  uint uVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  
  iVar3 = DAT_0e08892c;
  bVar1 = *(byte *)(DAT_0e08892c + 0x10);
  uVar15 = (uint)bVar1;
  iVar5 = FUN_0e088960();
  iVar14 = DAT_0e088934;
  iVar12 = iVar5;
  if (((param_1 != -1) && (iVar12 = param_1, iVar5 != -1)) && (iVar12 = iVar5, param_1 <= iVar5)) {
    iVar12 = param_1;
  }
  uVar17 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar17 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar10 = getBasePriority(), uVar10 == 0 || 0x20 < uVar10)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar5 = uVar15 * 0xc;
  puVar9 = (undefined4 *)(DAT_0e088930 + uVar15 * 0xc);
  if (*(char *)(DAT_0e088930 + uVar15 * 0xc) == '\0') {
    puVar9 = (undefined4 *)FUN_0e0889dc(uVar15,iVar12,0,puVar9,param_4);
    iVar14 = DAT_0e088934;
    if (puVar9 == (undefined4 *)0x0) {
      *(undefined1 *)(DAT_0e088934 + iVar5) = 0;
    }
    else {
      uVar6 = puVar9[1];
      uVar7 = puVar9[2];
      puVar16 = (undefined4 *)(iVar5 + DAT_0e088934);
      *puVar16 = *puVar9;
      puVar16[1] = uVar6;
      puVar16[2] = uVar7;
    }
  }
  else {
    uVar6 = *puVar9;
    uVar7 = puVar9[1];
    uVar8 = puVar9[2];
    *(undefined1 *)(DAT_0e088930 + iVar5) = 0;
    puVar9 = (undefined4 *)(iVar14 + iVar5);
    *puVar9 = uVar6;
    puVar9[1] = uVar7;
    puVar9[2] = uVar8;
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar17);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar4 = 0;
  if (*(char *)(iVar14 + uVar15 * 0xc) != '\0') {
    uVar10 = *(uint *)(iVar14 + uVar15 * 0xc + 8);
    if ((uVar10 != 0) && (iVar12 != -1)) {
      if (uVar10 < 0xffffffe1) {
        uVar10 = uVar10 + 0x1f >> 5;
      }
      else {
        uVar10 = 0x8000000;
      }
      FUN_0e097648(iVar12 - uVar10,1);
    }
    FUN_0e09601c();
    uVar17 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar17 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar10 = getBasePriority(), uVar10 == 0 || 0x20 < uVar10)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    for (piVar13 = (int *)*DAT_0e088938; piVar13 != (int *)0x0; piVar13 = (int *)*piVar13) {
      if ((code *)piVar13[1] != (code *)0x0) {
        (*(code *)piVar13[1])(*(undefined1 *)(iVar14 + (uint)*(byte *)(iVar3 + 0x10) * 0xc));
      }
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar17);
    }
    InstructionSynchronizationBarrier(0xf);
    puVar11 = (uint *)(DAT_0e08893c + (uint)(bVar1 >> 5) * 4);
    *puVar11 = *puVar11 | 1 << (uVar15 & 0x1f);
    FUN_0e08aa70(*(undefined1 *)(iVar14 + uVar15 * 0xc),*(undefined1 *)(iVar14 + uVar15 * 0xc + 1));
    FUN_0e088754();
    FUN_0e096044();
    uVar4 = 1;
  }
  return uVar4;
}


