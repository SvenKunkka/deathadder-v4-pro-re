/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e67ac. Types and names are inferred; NOT original source. */

void FUN_0e0e67ac(void)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int extraout_r3;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  
  uVar9 = FUN_0e0e67a2();
  iVar4 = (int)((ulonglong)uVar9 >> 0x20);
  uVar3 = 0x1f - LZCOUNT((int)uVar9);
  iVar8 = extraout_r3 + uVar3 * 4;
  iVar6 = *(int *)(iVar8 + 0x10);
  iVar5 = iVar4 * 8;
  iVar7 = iVar5 + 4;
  iVar5 = iVar5 + 6;
  uVar2 = (undefined2)((ulonglong)uVar9 >> 0x20);
  if (iVar6 == 0) {
    *(uint *)(extraout_r3 + 0xc) = *(uint *)(extraout_r3 + 0xc) | 1 << (uVar3 & 0xff);
    *(int *)(iVar8 + 0x10) = iVar4;
    *(undefined2 *)(extraout_r3 + iVar7) = uVar2;
    *(undefined2 *)(extraout_r3 + iVar5) = uVar2;
  }
  else {
    iVar4 = iVar6 * 8 + 4;
    uVar1 = *(ushort *)(extraout_r3 + iVar4);
    *(ushort *)(extraout_r3 + iVar7) = uVar1;
    *(short *)(extraout_r3 + iVar5) = (short)iVar6;
    *(undefined2 *)(extraout_r3 + (uint)uVar1 * 8 + 6) = uVar2;
    *(undefined2 *)(extraout_r3 + iVar4) = uVar2;
  }
  return;
}


