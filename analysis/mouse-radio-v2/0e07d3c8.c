/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07d3c8. Types and names are inferred; NOT original source. */

void FUN_0e07d3c8(void)

{
  ushort uVar1;
  short *psVar2;
  byte *pbVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  short *psVar8;
  short *psVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  
  *DAT_0e07d5cc = 1;
  psVar2 = DAT_0e07d5d4;
  *DAT_0e07d5d0 = 0xff;
  pbVar3 = DAT_0e07d5dc;
  *DAT_0e07d5d8 = 0;
  puVar4 = DAT_0e07d5e4;
  *DAT_0e07d5e0 = 0;
  puVar5 = DAT_0e07d5ec;
  *DAT_0e07d5e8 = 0;
  *DAT_0e07d5f0 = 0;
  *DAT_0e07d5f4 = 0;
  puVar6 = DAT_0e07d5f8;
  *puVar5 = 0;
  *puVar6 = 0;
  *pbVar3 = 0;
  *puVar4 = 0;
  FUN_0e07dfb8(0,0xa001,psVar2,0x29);
  puVar7 = DAT_0e07d5fc;
  if (*psVar2 != 0x29) {
    uVar12 = DAT_0e07d5fc[1];
    uVar13 = DAT_0e07d5fc[2];
    uVar14 = DAT_0e07d5fc[3];
    puVar15 = DAT_0e07d5fc + 4;
    *(undefined4 *)psVar2 = *DAT_0e07d5fc;
    *(undefined4 *)(psVar2 + 2) = uVar12;
    *(undefined4 *)(psVar2 + 4) = uVar13;
    *(undefined4 *)(psVar2 + 6) = uVar14;
    uVar12 = puVar7[5];
    uVar13 = puVar7[6];
    uVar14 = puVar7[7];
    *(undefined4 *)(psVar2 + 8) = *puVar15;
    *(undefined4 *)(psVar2 + 10) = uVar12;
    *(undefined4 *)(psVar2 + 0xc) = uVar13;
    *(undefined4 *)(psVar2 + 0xe) = uVar14;
    uVar12 = puVar7[9];
    uVar13 = puVar7[10];
    *(undefined4 *)(psVar2 + 0x10) = puVar7[8];
    *(undefined4 *)(psVar2 + 0x12) = uVar12;
    *(char *)(psVar2 + 0x14) = (char)uVar13;
  }
  psVar8 = DAT_0e07d600;
  FUN_0e07dfb8(1,0xa002,DAT_0e07d600,0x54);
  if ((*psVar8 != 0x54) ||
     (uVar1 = psVar8[0x29], uVar11 = FUN_0e07fad0(psVar8,0x52), uVar1 != uVar11)) {
    FUN_0e0974c4(DAT_0e07d600,DAT_0e07d604,0x54);
  }
  psVar9 = DAT_0e07d608;
  FUN_0e07dfb8(2,0xa003,DAT_0e07d608,0x4e4);
  if ((*psVar9 != 0x4e4) ||
     (uVar1 = psVar9[0x271], uVar11 = FUN_0e07fad0(psVar9,0x4e2), uVar1 != uVar11)) {
    FUN_0e0974c4(DAT_0e07d608,DAT_0e07d60c,0x4e4);
    *pbVar3 = *pbVar3 | 4;
    *puVar4 = 0;
  }
  FUN_0e0974c4(DAT_0e07d614,DAT_0e07d610,0x5de);
  iVar10 = DAT_0e07d618;
  FUN_0e0974c4(DAT_0e07d620,DAT_0e07d61c,0x5de);
  FUN_0e0974c4(DAT_0e07d628,DAT_0e07d624,0x5de);
  FUN_0e07dfb8(4,0xa006,iVar10,0x5de);
  uVar1 = *(ushort *)(iVar10 + 0x5dc);
  uVar11 = FUN_0e07fad0(iVar10,0x5dc);
  if (uVar1 != uVar11) {
    FUN_0e0974c4(iVar10,DAT_0e07d62c,0x5de);
  }
  *DAT_0e07d630 = 0;
  FUN_0e07e7dc();
  FUN_0e097800(0);
  FUN_0e07ee28();
  iVar10 = DAT_0e07d634;
  if (*(char *)((int)psVar2 + 0x1f) == -1) {
    if ((*(byte *)(psVar2 + 0x10) & *(byte *)((int)psVar2 + 0x21) & *(byte *)(psVar2 + 0x11)) ==
        0xff) goto LAB_0e07d564;
  }
  else if (((*(char *)((int)psVar2 + 0x1f) == '\0' && (char)psVar2[0x10] == '\0') &&
           *(char *)((int)psVar2 + 0x21) == '\0') && (char)psVar2[0x11] == '\0') {
LAB_0e07d564:
    uVar12 = *(undefined4 *)(DAT_0e07d634 + 0x10);
    *(char *)((int)psVar2 + 0x1f) = (char)((uint)*(undefined4 *)(DAT_0e07d634 + 0x10) >> 0x18);
    *(char *)(psVar2 + 0x10) = (char)((uint)uVar12 >> 0x10);
    uVar12 = *(undefined4 *)(iVar10 + 0x10);
    *(char *)((int)psVar2 + 0x21) = (char)((uint)*(undefined4 *)(iVar10 + 0x10) >> 8);
    *(char *)(psVar2 + 0x11) = (char)uVar12;
  }
  if (*(char *)((int)psVar8 + 0x23) == -1) {
    if ((*(byte *)(psVar8 + 0x13) & *(byte *)(psVar8 + 0x12) & *(byte *)((int)psVar8 + 0x25)) !=
        0xff) goto LAB_0e07d528;
  }
  else if (*(byte *)(psVar8 + 0x13) != 0 ||
           (*(byte *)((int)psVar8 + 0x25) != 0 ||
           (*(char *)((int)psVar8 + 0x23) != '\0' || *(byte *)(psVar8 + 0x12) != 0)))
  goto LAB_0e07d528;
  *(undefined4 *)((int)psVar8 + 0x23) = *(undefined4 *)((int)psVar2 + 0x1f);
LAB_0e07d528:
  if (*(char *)((int)psVar8 + 0x27) == -1) {
    if ((*(byte *)(psVar8 + 0x15) & *(byte *)(psVar8 + 0x14) & *(byte *)((int)psVar8 + 0x29)) !=
        0xff) {
      return;
    }
  }
  else if (*(byte *)(psVar8 + 0x15) != 0 ||
           (*(byte *)((int)psVar8 + 0x29) != 0 ||
           (*(char *)((int)psVar8 + 0x27) != '\0' || *(byte *)(psVar8 + 0x14) != 0))) {
    return;
  }
  *(undefined4 *)((int)psVar8 + 0x27) = *(undefined4 *)((int)psVar2 + 0x1f);
  return;
}


