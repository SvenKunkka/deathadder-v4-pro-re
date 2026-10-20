/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e085640. Types and names are inferred; NOT original source. */

void FUN_0e085640(void)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  iVar3 = DAT_0e0856d4;
  iVar4 = *(int *)(*(int *)(DAT_0e0856d4 + 4) + 8);
  if ((1 << (uint)*(byte *)(DAT_0e0856d4 + 8) & **(uint **)(*(int *)(DAT_0e0856d4 + 4) + 0x10)) == 0
     ) {
    pcVar5 = *(code **)(iVar4 + 0xc);
  }
  else {
    pcVar5 = *(code **)(iVar4 + 0x10);
  }
  (*pcVar5)();
  iVar4 = FUN_0e094688(*(undefined4 *)(iVar3 + 0xc));
  if (iVar4 == 0) {
    iVar4 = FUN_0e094688(*(undefined4 *)(iVar3 + 0x14));
  }
  else {
    uVar2 = *(ushort *)(iVar3 + 0x12);
    iVar4 = *(int *)(iVar3 + 0xc);
    bVar1 = *(byte *)(iVar3 + 0x10);
    uVar6 = 1 << (uint)bVar1;
    uVar8 = **(uint **)(iVar4 + 0x10);
    if ((uVar2 & 1) == 0) {
      uVar6 = uVar8 & ~uVar6;
    }
    else {
      uVar6 = uVar6 | uVar8;
    }
    puVar7 = *(undefined4 **)(iVar4 + 8);
    **(uint **)(iVar4 + 0x10) = uVar6;
    (*(code *)*puVar7)(iVar4,(uint)bVar1,uVar2 | 0x10010);
    iVar4 = FUN_0e094688(*(undefined4 *)(iVar3 + 0x14));
  }
  if (iVar4 == 0) {
    return;
  }
  uVar2 = *(ushort *)(iVar3 + 0x1a);
  iVar4 = *(int *)(iVar3 + 0x14);
  bVar1 = *(byte *)(iVar3 + 0x18);
  uVar6 = 1 << (uint)bVar1;
  uVar8 = **(uint **)(iVar4 + 0x10);
  puVar7 = *(undefined4 **)(iVar4 + 8);
  if ((uVar2 & 1) == 0) {
    uVar6 = uVar8 & ~uVar6;
  }
  else {
    uVar6 = uVar6 | uVar8;
  }
  **(uint **)(iVar4 + 0x10) = uVar6;
                    /* WARNING: Could not recover jumptable at 0x0e0856d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar7)(iVar4,(uint)bVar1,uVar2 | 0x60000);
  return;
}


