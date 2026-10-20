/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e079998. Types and names are inferred; NOT original source. */

void FUN_0e079998(void)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_30;
  int iStack_2c;
  
  uVar6 = (uint)DAT_23007743;
  iVar2 = FUN_0e0905f8(&DAT_0e0979d0,0,&local_30);
  iVar5 = iStack_2c;
  uVar4 = local_30;
  if (-1 < iVar2) {
    uVar7 = (iStack_2c +
            ((((iStack_2c << 5 | local_30 >> 0x1b) - iStack_2c) - (uint)(local_30 * 0x20 < local_30)
             ) * 4 | local_30 * 0x1f >> 0x1e) + (uint)CARRY4(local_30 * 0x7c,local_30)) * 0x4000 |
            local_30 * 0x7d >> 0x12;
    uVar3 = FUN_0e0795d8(local_30 * 0x1f4000,uVar7,1000000000,0);
    if (((uVar7 < 1000000000) &&
        (uVar6 = (uVar6 * 0x1f4000) / 0xff, lVar1 = (ulonglong)uVar6 * (ulonglong)uVar4,
        uVar6 = uVar6 * iVar5 + (int)((ulonglong)lVar1 >> 0x20),
        uVar4 = FUN_0e0795d8((int)lVar1,uVar6,1000000000,0), uVar6 < 1000000000)) &&
       (uVar4 <= uVar3)) {
      FUN_0e090608(&DAT_0e0979d0,0,uVar3,uVar4,0);
    }
  }
  uVar6 = (uint)DAT_23007742;
  iVar2 = FUN_0e0905f8(&DAT_0e0979d0,1,&local_30);
  iVar5 = iStack_2c;
  uVar4 = local_30;
  if (-1 < iVar2) {
    uVar7 = (iStack_2c +
            ((((iStack_2c << 5 | local_30 >> 0x1b) - iStack_2c) - (uint)(local_30 * 0x20 < local_30)
             ) * 4 | local_30 * 0x1f >> 0x1e) + (uint)CARRY4(local_30 * 0x7c,local_30)) * 0x4000 |
            local_30 * 0x7d >> 0x12;
    uVar3 = FUN_0e0795d8(local_30 * 0x1f4000,uVar7,1000000000,0);
    if (((uVar7 < 1000000000) &&
        (uVar6 = (uVar6 * 0x1f4000) / 0xff, lVar1 = (ulonglong)uVar6 * (ulonglong)uVar4,
        uVar6 = uVar6 * iVar5 + (int)((ulonglong)lVar1 >> 0x20),
        uVar4 = FUN_0e0795d8((int)lVar1,uVar6,1000000000,0), uVar6 < 1000000000)) &&
       (uVar4 <= uVar3)) {
      FUN_0e090608(&DAT_0e0979d0,1,uVar3,uVar4,0);
    }
  }
  uVar4 = (uint)DAT_23007741;
  iVar5 = FUN_0e0905f8(&DAT_0e0979d0,2,&local_30);
  if (-1 < iVar5) {
    uVar3 = (iStack_2c +
            ((((iStack_2c << 5 | local_30 >> 0x1b) - iStack_2c) - (uint)(local_30 * 0x20 < local_30)
             ) * 4 | local_30 * 0x1f >> 0x1e) + (uint)CARRY4(local_30 * 0x7c,local_30)) * 0x4000 |
            local_30 * 0x7d >> 0x12;
    uVar6 = FUN_0e0795d8(local_30 * 0x1f4000,uVar3,1000000000,0);
    if (((uVar3 < 1000000000) &&
        (uVar4 = (uVar4 * 0x1f4000) / 0xff, lVar1 = (ulonglong)uVar4 * (ulonglong)local_30,
        uVar3 = uVar4 * iStack_2c + (int)((ulonglong)lVar1 >> 0x20),
        uVar4 = FUN_0e0795d8((int)lVar1,uVar3,1000000000,0), uVar3 < 1000000000)) &&
       (uVar4 <= uVar6)) {
      FUN_0e090608(&DAT_0e0979d0,2,uVar6,uVar4,0);
    }
  }
  return;
}


