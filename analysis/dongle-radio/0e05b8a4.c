/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05b8a4. Types and names are inferred; NOT original source. */

void FUN_0e05b8a4(void)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  undefined2 *puVar4;
  short *psVar5;
  short *psVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined2 uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  uint uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  uint uVar21;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_lr;
  undefined4 *puVar22;
  undefined4 *puVar23;
  
  psVar5 = DAT_0e05ba00;
  FUN_0e05a098(0,0xa001,DAT_0e05ba00,0x46);
  if ((*psVar5 != 0x46) ||
     (uVar2 = psVar5[0x22], uVar21 = FUN_0e05479c(psVar5,0x44,0), uVar2 != uVar21)) {
    thunk_FUN_0e06f3f8(DAT_0e05ba00,DAT_0e05ba04,0x46);
  }
  psVar6 = DAT_0e05ba08;
  FUN_0e05a098(1,0xa002,DAT_0e05ba08,0x2f);
  if ((*psVar6 != 0x2f) ||
     (uVar2 = *(ushort *)((int)psVar6 + 0x2d), uVar21 = FUN_0e05479c(psVar6,0x2d,0), uVar2 != uVar21
     )) {
    puVar8 = DAT_0e05ba10;
    puVar7 = DAT_0e05ba0c;
    uVar11 = *DAT_0e05ba0c;
    uVar13 = DAT_0e05ba0c[1];
    uVar16 = DAT_0e05ba0c[2];
    uVar19 = DAT_0e05ba0c[3];
    puVar22 = DAT_0e05ba0c + 4;
    uVar12 = *puVar22;
    uVar14 = DAT_0e05ba0c[5];
    uVar15 = DAT_0e05ba10[1];
    uVar17 = DAT_0e05ba10[2];
    uVar20 = DAT_0e05ba10[3];
    puVar23 = DAT_0e05ba10 + 4;
    DAT_0e05ba0c[-5] = *DAT_0e05ba10;
    puVar7[-4] = uVar15;
    puVar7[-3] = uVar17;
    puVar7[-2] = uVar20;
    uVar15 = puVar8[5];
    uVar17 = puVar8[6];
    uVar20 = puVar8[7];
    puVar7[-1] = *puVar23;
    *puVar7 = uVar15;
    puVar7[1] = uVar17;
    puVar7[2] = uVar20;
    uVar15 = puVar8[9];
    uVar17 = puVar8[10];
    uVar20 = puVar8[0xb];
    puVar7[3] = puVar8[8];
    *puVar22 = uVar15;
    puVar7[5] = uVar17;
    *(short *)(puVar7 + 6) = (short)uVar20;
    *(char *)((int)puVar7 + 0x1a) = (char)((uint)uVar20 >> 0x10);
    *puVar7 = uVar11;
    puVar7[1] = uVar13;
    puVar7[2] = uVar16;
    puVar7[3] = uVar19;
    *puVar22 = uVar12;
    *(short *)(puVar7 + 5) = (short)uVar14;
  }
  pbVar3 = DAT_0e05ba18;
  uVar21 = DAT_0e05ba14;
  if (0xfffffffd < *(int *)((int)psVar5 + 0x1f) - 1U) {
    *(char *)((int)psVar5 + 0x1f) = (char)((uint)*(undefined4 *)(DAT_0e05ba14 + 0x10) >> 0x18);
    *(char *)(psVar5 + 0x10) = (char)((uint)*(undefined4 *)(uVar21 + 0x10) >> 0x10);
    uVar11 = *(undefined4 *)(uVar21 + 0x10);
    *(char *)((int)psVar5 + 0x21) = (char)((uint)*(undefined4 *)(uVar21 + 0x10) >> 8);
    bVar1 = *pbVar3;
    *(char *)(psVar5 + 0x11) = (char)uVar11;
    *pbVar3 = bVar1 | 2;
    *DAT_0e05ba1c = 0;
  }
  puVar4 = DAT_0e05ba1c;
  pbVar3 = DAT_0e05ba18;
  if (0xfffffffd < *(int *)((int)psVar6 + 0xb) - 1U) {
    *(undefined4 *)((int)psVar6 + 0xb) = *(undefined4 *)((int)psVar5 + 0x1f);
    bVar1 = *pbVar3;
    *puVar4 = 0;
    *pbVar3 = bVar1 | 1;
  }
  uVar21 = DAT_0e05ba14;
  if (((*(int *)(DAT_0e05ba14 + 0x14) == 0xc000) &&
      (uVar21 = *(uint *)(DAT_0e05ba14 + 0x10), uVar21 == 0x80000000)) &&
     (uVar21 = *(uint *)((int)psVar5 + 0x1f), uVar21 == 0x80)) {
    thunk_FUN_0e0622b8(DAT_0e05ba20,4);
    pbVar3 = DAT_0e05ba18;
    bVar1 = *DAT_0e05ba18;
    *DAT_0e05ba1c = 0;
    uVar21 = bVar1 | 2;
    *pbVar3 = (byte)uVar21;
  }
  puVar4 = DAT_0e05b864;
  pbVar3 = DAT_0e05b858;
  uVar18 = (uint)*DAT_0e05b858;
  if ((uVar18 != 0) && (*DAT_0e05b85c == 0)) {
    if ((int)(uVar18 << 0x1e) < 0) {
      *DAT_0e05b864 = 0x46;
      uVar9 = FUN_0e05479c(puVar4,0x44,0,uVar18,uVar21,unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_lr)
      ;
      puVar4[0x22] = uVar9;
      iVar10 = FUN_0e05a0c0(0,0xa001,puVar4,0x46);
      uVar18 = (uint)*pbVar3;
      if (iVar10 != 0) {
        uVar18 = uVar18 & 0xfd;
        *pbVar3 = (byte)uVar18;
      }
    }
    puVar4 = DAT_0e05b860;
    if ((int)(uVar18 << 0x1f) < 0) {
      *DAT_0e05b860 = 0x2f;
      uVar9 = FUN_0e05479c(puVar4,0x2d,0,uVar18 << 0x1f,uVar21,unaff_r4,unaff_r5,unaff_r6,unaff_r7,
                           unaff_lr);
      *(undefined2 *)((int)puVar4 + 0x2d) = uVar9;
      iVar10 = FUN_0e05a0c0(1,0xa002,puVar4,0x2f);
      if (iVar10 != 0) {
        *pbVar3 = *pbVar3 & 0xfe;
        return;
      }
    }
  }
  return;
}


