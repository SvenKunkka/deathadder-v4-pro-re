/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e079b78. Types and names are inferred; NOT original source. */

void FUN_0e079b78(void)

{
  byte bVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uStack_30;
  int iStack_2c;
  
  iVar7 = DAT_0e079da0;
  if (*DAT_0e079d98 == '\0') {
    return;
  }
  bVar1 = *DAT_0e079d9c;
  puVar9 = *(undefined4 **)(DAT_0e079da0 + 8);
  iVar4 = (*(code *)puVar9[1])(DAT_0e079da0,0,&uStack_30);
  iVar3 = iStack_2c;
  uVar6 = uStack_30;
  if (-1 < iVar4) {
    uVar10 = (iStack_2c +
             ((((iStack_2c << 5 | uStack_30 >> 0x1b) - iStack_2c) -
              (uint)(uStack_30 * 0x20 < uStack_30)) * 4 | uStack_30 * 0x1f >> 0x1e) +
             (uint)CARRY4(uStack_30 * 0x7c,uStack_30)) * 0x4000 | uStack_30 * 0x7d >> 0x12;
    uVar5 = FUN_0e0797c0(uStack_30 * 0x1f4000,uVar10,DAT_0e079d90,DAT_0e079d94);
    uVar8 = DAT_0e079da4;
    if (((uVar10 <= DAT_0e079da4) &&
        (uVar10 = (uint)((ulonglong)DAT_0e079da8 * (ulonglong)((uint)bVar1 * 0x1f4000) >> 0x27),
        lVar2 = (ulonglong)uVar10 * (ulonglong)uVar6,
        uVar10 = uVar10 * iVar3 + (int)((ulonglong)lVar2 >> 0x20),
        uVar6 = FUN_0e0797c0((int)lVar2,uVar10,DAT_0e079d90,DAT_0e079d94), uVar10 <= uVar8)) &&
       (uVar6 <= uVar5)) {
      (*(code *)*puVar9)(iVar7,0,uVar5,uVar6,0);
    }
  }
  bVar1 = *DAT_0e079dac;
  puVar9 = *(undefined4 **)(iVar7 + 8);
  iVar4 = (*(code *)puVar9[1])(DAT_0e079da0,1,&uStack_30);
  iVar3 = iStack_2c;
  uVar6 = uStack_30;
  if (-1 < iVar4) {
    uVar10 = (iStack_2c +
             ((((iStack_2c << 5 | uStack_30 >> 0x1b) - iStack_2c) -
              (uint)(uStack_30 * 0x20 < uStack_30)) * 4 | uStack_30 * 0x1f >> 0x1e) +
             (uint)CARRY4(uStack_30 * 0x7c,uStack_30)) * 0x4000 | uStack_30 * 0x7d >> 0x12;
    uVar5 = FUN_0e0797c0(uStack_30 * 0x1f4000,uVar10,DAT_0e079d90,DAT_0e079d94);
    uVar8 = DAT_0e079da4;
    if (((uVar10 <= DAT_0e079da4) &&
        (uVar10 = (uint)((ulonglong)DAT_0e079da8 * (ulonglong)((uint)bVar1 * 0x1f4000) >> 0x27),
        lVar2 = (ulonglong)uVar10 * (ulonglong)uVar6,
        uVar10 = uVar10 * iVar3 + (int)((ulonglong)lVar2 >> 0x20),
        uVar6 = FUN_0e0797c0((int)lVar2,uVar10,DAT_0e079d90,DAT_0e079d94), uVar10 <= uVar8)) &&
       (uVar6 <= uVar5)) {
      (*(code *)*puVar9)(DAT_0e079da0,1,uVar5,uVar6,0);
    }
  }
  bVar1 = *DAT_0e079db0;
  puVar9 = *(undefined4 **)(iVar7 + 8);
  iVar7 = (*(code *)puVar9[1])(DAT_0e079da0,2,&uStack_30);
  if (-1 < iVar7) {
    uVar5 = (iStack_2c +
            ((((iStack_2c << 5 | uStack_30 >> 0x1b) - iStack_2c) -
             (uint)(uStack_30 * 0x20 < uStack_30)) * 4 | uStack_30 * 0x1f >> 0x1e) +
            (uint)CARRY4(uStack_30 * 0x7c,uStack_30)) * 0x4000 | uStack_30 * 0x7d >> 0x12;
    uVar8 = FUN_0e0797c0(uStack_30 * 0x1f4000,uVar5,DAT_0e079d90,DAT_0e079d94);
    uVar6 = DAT_0e079da4;
    if (((uVar5 <= DAT_0e079da4) &&
        (uVar5 = (uint)((ulonglong)DAT_0e079da8 * (ulonglong)((uint)bVar1 * 0x1f4000) >> 0x27),
        lVar2 = (ulonglong)uVar5 * (ulonglong)uStack_30,
        uVar10 = uVar5 * iStack_2c + (int)((ulonglong)lVar2 >> 0x20),
        uVar5 = FUN_0e0797c0((int)lVar2,uVar10,DAT_0e079d90,DAT_0e079d94), uVar10 <= uVar6)) &&
       (uVar5 <= uVar8)) {
      (*(code *)*puVar9)(DAT_0e079da0,2,uVar8,uVar5,0);
    }
  }
  return;
}


