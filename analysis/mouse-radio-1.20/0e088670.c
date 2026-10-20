/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e088670. Types and names are inferred; NOT original source. */

undefined1 FUN_0e088670(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  undefined4 uVar13;
  
  bVar2 = DAT_2300765c;
  uVar11 = (uint)DAT_2300765c;
  iVar4 = FUN_0e0887d4();
  iVar9 = iVar4;
  if (((param_1 != -1) && (iVar9 = param_1, iVar4 != -1)) && (iVar9 = iVar4, param_1 <= iVar4)) {
    iVar9 = param_1;
  }
  uVar13 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar13 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar8 = getBasePriority(), uVar8 == 0 || 0x20 < uVar8)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar12 = uVar11 * 0xc;
  iVar4 = uVar11 * 0xc;
  if ((&DAT_23006cf8)[uVar11 * 0xc] == '\0') {
    puVar6 = (undefined4 *)FUN_0e088850(uVar11,iVar9,0,&DAT_23006cf8 + iVar4,param_4);
    if (puVar6 == (undefined4 *)0x0) {
      (&DAT_23006d04)[iVar12] = 0;
    }
    else {
      uVar5 = puVar6[1];
      uVar7 = puVar6[2];
      *(undefined4 *)(&DAT_23006d04 + iVar12) = *puVar6;
      *(undefined4 *)(&DAT_23006d08 + iVar12) = uVar5;
      *(undefined4 *)(&DAT_23006d0c + iVar12) = uVar7;
    }
  }
  else {
    uVar5 = *(undefined4 *)(&DAT_23006cf8 + iVar4);
    (&DAT_23006cf8)[iVar12] = 0;
    *(undefined4 *)(&DAT_23006d04 + iVar12) = uVar5;
    *(undefined4 *)(&DAT_23006d08 + iVar12) = *(undefined4 *)(&DAT_23006cfc + iVar4);
    *(undefined4 *)(&DAT_23006d0c + iVar12) = *(undefined4 *)(&DAT_23006d00 + iVar4);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar13);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar3 = 0;
  if ((&DAT_23006d04)[uVar11 * 0xc] != '\0') {
    uVar8 = *(uint *)(&DAT_23006d0c + uVar11 * 0xc);
    if ((uVar8 != 0) && (iVar9 != -1)) {
      if (uVar8 < 0xffffffe1) {
        uVar8 = uVar8 + 0x1f >> 5;
      }
      else {
        uVar8 = 0x8000000;
      }
      FUN_0e097588(iVar9 - uVar8,1);
    }
    FUN_0e095ef4();
    uVar13 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar13 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar8 = getBasePriority(), uVar8 == 0 || 0x20 < uVar8)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    for (piVar10 = (int *)DAT_23001da8; piVar10 != (int *)0x0; piVar10 = (int *)*piVar10) {
      if ((code *)piVar10[1] != (code *)0x0) {
        (*(code *)piVar10[1])((&DAT_23006d04)[(uint)DAT_2300765c * 0xc]);
      }
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar13);
    }
    InstructionSynchronizationBarrier(0xf);
    *(uint *)(&DAT_23006d10 + (uint)(bVar2 >> 5) * 4) =
         *(uint *)(&DAT_23006d10 + (uint)(bVar2 >> 5) * 4) | 1 << (uVar11 & 0x1f);
    FUN_0e08a8e4((&DAT_23006d04)[uVar11 * 0xc],(&DAT_23006d05)[uVar11 * 0xc]);
    FUN_0e0885c8();
    FUN_0e095f1c();
    uVar3 = 1;
  }
  return uVar3;
}


