/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e074654. Types and names are inferred; NOT original source. */

void FUN_0e074654(void)

{
  ushort uVar1;
  char *pcVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  uint local_1c;
  
  iVar8 = *DAT_0e074794;
  uVar1 = *DAT_0e074798;
  iVar12 = DAT_0e074794[1];
  puVar13 = *(uint **)(iVar8 + 0x10);
  uVar9 = (**(code **)(*(int *)(iVar8 + 8) + 4))(iVar8,&local_1c);
  if (uVar9 == 0) {
    if (((*puVar13 ^ local_1c) & 1 << (sbyte)iVar12) == 0) {
      uVar9 = 0;
    }
    else {
      uVar9 = 1;
    }
  }
  iVar8 = *DAT_0e07479c;
  iVar12 = DAT_0e07479c[1];
  puVar13 = *(uint **)(iVar8 + 0x10);
  iVar8 = (**(code **)(*(int *)(iVar8 + 8) + 4))(iVar8,&local_1c);
  if (iVar8 == 0) {
    if (((local_1c ^ *puVar13) & 1 << (sbyte)iVar12) == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = 1;
    }
  }
  iVar10 = *DAT_0e0747a0;
  iVar12 = DAT_0e0747a0[1];
  puVar13 = *(uint **)(iVar10 + 0x10);
  iVar11 = (**(code **)(*(int *)(iVar10 + 8) + 4))(iVar10,&local_1c);
  uVar5 = DAT_0e0747b8;
  uVar4 = DAT_0e0747b4;
  puVar3 = DAT_0e0747b0;
  iVar10 = DAT_0e0747ac;
  pcVar2 = DAT_0e0747a8;
  if (iVar11 == 0) {
    if (((*puVar13 ^ local_1c) & 1 << (sbyte)iVar12) == 0) {
      iVar11 = 0;
    }
    else {
      iVar11 = 1;
    }
  }
  if (((uVar9 | iVar8 << 2 | iVar11 << 4) & (uint)uVar1) != 0) {
    *DAT_0e0747a4 = 5000;
    *pcVar2 = '\0';
    return;
  }
  if ((*DAT_0e0747a4 == 0) && (*DAT_0e0747a8 == '\0')) {
    *DAT_0e0747a8 = '\x01';
    *puVar3 = 1;
    thunk_FUN_0e0974c4(uVar5,uVar4,0x54);
    thunk_FUN_0e0974c4(iVar10,DAT_0e0747bc,0x4e4);
    FUN_0e073120();
    iVar12 = (uint)*(byte *)(iVar10 + 3) * 0xf4 + iVar10;
    thunk_FUN_0e0974c4(DAT_0e0747c0,(uint)*(byte *)(iVar10 + 3) * 0xf4 + iVar10 + 0x91,0x80);
    thunk_FUN_0e0805b8(*(undefined2 *)(iVar12 + 0x56),*(undefined2 *)(iVar12 + 0x58));
    thunk_FUN_0e07d638(2,0);
    thunk_FUN_0e07d638(8,*(undefined1 *)(iVar10 + 3));
    puVar3 = DAT_0e0747c8;
    *DAT_0e0747c4 = 1;
    puVar6 = DAT_0e0747cc;
    *puVar3 = 0x8f;
    *puVar6 = 0xc;
    puVar3 = DAT_0e0747d4;
    *DAT_0e0747d0 = 0xb;
    puVar7 = DAT_0e0747dc;
    puVar6 = DAT_0e0747d8;
    *puVar3 = 0;
    *puVar6 = 0;
    *puVar7 = 0;
    thunk_FUN_0e0806c4();
    FUN_0e078fcc();
    FUN_0e078ed4(0);
    thunk_FUN_0e080570(10,3);
    return;
  }
  return;
}


