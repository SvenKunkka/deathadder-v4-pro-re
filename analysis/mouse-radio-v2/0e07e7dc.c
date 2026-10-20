/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07e7dc. Types and names are inferred; NOT original source. */

void FUN_0e07e7dc(void)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined2 uVar6;
  byte *pbVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  uint uVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  
  iVar10 = DAT_0e07e80c;
  bVar5 = *(byte *)(DAT_0e07e80c + 3);
  *DAT_0e07e814 = *(undefined4 *)(DAT_0e07e810 + 0x23);
  iVar10 = (uint)bVar5 * 0xf4 + iVar10;
  *(undefined1 *)(DAT_0e07e818 + 3) = 0;
  iVar8 = DAT_0e07e62c;
  puVar18 = *(undefined4 **)(DAT_0e07e628 + (uint)*(byte *)(iVar10 + 0x2a) * 4);
  iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d;
  puVar19 = (undefined4 *)(DAT_0e07e62c + iVar13);
  uVar9 = *(undefined4 *)((int)puVar19 + 0x11);
  uVar12 = *(undefined4 *)((int)puVar19 + 0x19);
  uVar15 = *(undefined4 *)((int)puVar19 + 0x1d);
  uVar11 = *(undefined4 *)((int)puVar19 + 0x15);
  uVar1 = *(undefined1 *)((int)puVar19 + 3);
  uVar6 = *(undefined2 *)((int)puVar19 + 0x21);
  iVar13 = DAT_0e07e630 + (uint)*(byte *)(DAT_0e07e630 + 3) * 0xf4 + iVar13;
  uVar4 = *(undefined1 *)((int)puVar19 + 0x23);
  puVar14 = (undefined4 *)(iVar13 + 0x29);
  do {
    puVar20 = puVar19;
    puVar16 = puVar14;
    puVar14 = puVar16 + 4;
    *puVar20 = *puVar16;
    puVar20[1] = puVar16[1];
    puVar20[2] = puVar16[2];
    puVar20[3] = puVar16[3];
    puVar19 = puVar20 + 4;
  } while (puVar14 != (undefined4 *)(iVar13 + 0x49));
  puVar20[4] = *puVar14;
  puVar20[5] = puVar16[5];
  puVar20[6] = puVar16[6];
  *(undefined1 *)(puVar20 + 7) = *(undefined1 *)(puVar16 + 7);
  *(undefined1 *)((uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8 + 3) = uVar1;
  iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
  *(undefined4 *)(iVar13 + 0x1d) = uVar15;
  *(undefined4 *)(iVar13 + 0x11) = uVar9;
  *(undefined2 *)(iVar13 + 0x21) = uVar6;
  *(undefined4 *)(iVar13 + 0x15) = uVar11;
  *(undefined4 *)(iVar13 + 0x19) = uVar12;
  *(undefined1 *)(iVar13 + 0x23) = uVar4;
  uVar17 = (uint)*(byte *)(iVar10 + 0x2a);
  bVar5 = *(byte *)(DAT_0e07e634 + uVar17);
  if (bVar5 != 0) {
    puVar14 = puVar18;
    do {
      puVar19 = puVar14 + 3;
      puVar14[2] = puVar14[1];
      uVar17 = (uint)*(byte *)(iVar10 + 0x2a);
      puVar14 = puVar19;
    } while (puVar18 + (short)(ushort)bVar5 * 3 != puVar19);
  }
  iVar13 = uVar17 * 0x2d + iVar8;
  bVar2 = *(byte *)(iVar13 + 4);
  switch(*(undefined1 *)(DAT_0e07e638 + (uint)*(byte *)(iVar13 + 3) * 10 + (uint)bVar2)) {
  case 0:
    *(byte *)(uVar17 * 0x2d + iVar8 + 3) = bVar2;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x1c) = 0;
    *(undefined1 *)(iVar13 + 0x1a) = 0xd0;
    *(undefined1 *)(iVar13 + 0x1b) = 7;
    *(undefined1 *)(iVar13 + 0x1d) = 0;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x16) = 0xd0;
    *(undefined1 *)(iVar13 + 0x17) = 7;
    *(undefined1 *)(iVar13 + 0x18) = 0;
    *(undefined1 *)(iVar13 + 0x19) = 0;
    uVar17 = (uint)*(byte *)(iVar10 + 0x2a);
    break;
  case 1:
    *(undefined1 *)(uVar17 * 0x2d + iVar8 + 0x11) = 1;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x1e) = 0;
    *(undefined1 *)(iVar13 + 0x1f) = 0;
    *(undefined1 *)(iVar13 + 0x20) = 0;
    *(undefined1 *)(iVar13 + 0x21) = 0;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x12) = 10;
    *(undefined1 *)(iVar13 + 0x13) = 0;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x14) = 1;
    *(undefined1 *)(iVar13 + 0x15) = 0;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x1a) = 0xd0;
    *(undefined1 *)(iVar13 + 0x1b) = 7;
    *(undefined1 *)(iVar13 + 0x1c) = 0;
    *(undefined1 *)(iVar13 + 0x1d) = 0;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x16) = 0xd0;
    *(undefined1 *)(iVar13 + 0x17) = 7;
    *(undefined1 *)(iVar13 + 0x18) = 0;
    *(undefined1 *)(iVar13 + 0x19) = 0;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x22) = 0;
    *(undefined1 *)(iVar13 + 0x23) = 0;
    *(undefined1 *)((uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8 + 3) = 9;
    uVar17 = (uint)*(byte *)(iVar10 + 0x2a);
    break;
  case 2:
  case 3:
    *(undefined1 *)(uVar17 * 0x2d + iVar8 + 0x11) = 3;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x1c) = 0;
    *(undefined1 *)(iVar13 + 0x1a) = 0xdc;
    *(undefined1 *)(iVar13 + 0x1b) = 5;
    *(undefined1 *)(iVar13 + 0x1d) = 0;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x16) = 0xdc;
    *(undefined1 *)(iVar13 + 0x17) = 5;
    *(undefined1 *)(iVar13 + 0x18) = 0;
    *(undefined1 *)(iVar13 + 0x19) = 0;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x12) = 10;
    *(undefined1 *)(iVar13 + 0x13) = 0;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x14) = 10;
    *(undefined1 *)(iVar13 + 0x15) = 0;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x22) = 0;
    *(undefined1 *)(iVar13 + 0x23) = 0;
    if (*(char *)(iVar10 + 0x2c) == '\x02') {
      uVar17 = (uint)*(byte *)(iVar10 + 0x2a);
      *(undefined1 *)(iVar10 + 0x2c) = 9;
      break;
    }
    goto LAB_0e07e504;
  case 4:
    *(undefined1 *)(uVar17 * 0x2d + iVar8 + 0x11) = 2;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x1a) = 0xd0;
    *(undefined1 *)(iVar13 + 0x1b) = 7;
    *(undefined1 *)(iVar13 + 0x1c) = 0;
    *(undefined1 *)(iVar13 + 0x1d) = 0;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x16) = 0;
    *(undefined1 *)(iVar13 + 0x17) = 0;
    *(undefined1 *)(iVar13 + 0x18) = 0;
    *(undefined1 *)(iVar13 + 0x19) = 0;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x13) = 0;
    *(undefined1 *)(iVar13 + 0x12) = 10;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x15) = 0;
    *(undefined1 *)(iVar13 + 0x14) = 1;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 0x22) = 0;
    *(undefined1 *)(iVar13 + 0x23) = 0;
    iVar13 = (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8;
    *(undefined1 *)(iVar13 + 3) = *(undefined1 *)(iVar13 + 4);
LAB_0e07e504:
    uVar17 = (uint)*(byte *)(iVar10 + 0x2a);
  }
  pbVar7 = DAT_0e07e63c;
  iVar13 = DAT_0e07e630;
  cVar3 = *(char *)(uVar17 * 0x2d + iVar8 + 4);
  if (cVar3 == '\x01') {
    if (bVar5 != 0) {
      puVar14 = puVar18;
      do {
        puVar19 = puVar14 + 3;
        *puVar14 = *(undefined4 *)(uVar17 * 0x2d + iVar8 + 7);
        uVar17 = (uint)*(byte *)(iVar10 + 0x2a);
        puVar14 = puVar19;
      } while (puVar19 != puVar18 + (short)(ushort)bVar5 * 3);
      return;
    }
  }
  else if (cVar3 == '\x02') {
    uVar6 = *(undefined2 *)(DAT_0e07e630 + 9);
    *(undefined2 *)(DAT_0e07e63c + 2) = uVar6;
    *(undefined2 *)(pbVar7 + 6) = uVar6;
    pbVar7[0x23] = 0;
    pbVar7[0x24] = 0;
    pbVar7[0x25] = 0;
    pbVar7[0x26] = 0;
    pbVar7[0x27] = 0;
    pbVar7[1] = 1;
    *(undefined2 *)(pbVar7 + 4) = *(undefined2 *)(iVar13 + 7);
    *(undefined2 *)(pbVar7 + 8) = *(undefined2 *)(iVar13 + 0xb);
    *(undefined2 *)(pbVar7 + 10) = *(undefined2 *)(iVar13 + 0xd);
    *(undefined2 *)(pbVar7 + 0xc) = *(undefined2 *)(iVar13 + 0xf);
    *(undefined2 *)(pbVar7 + 0xe) = *(undefined2 *)(iVar13 + 0x11);
    *(undefined2 *)(pbVar7 + 0x10) = *(undefined2 *)(iVar13 + 0x13);
    *(undefined2 *)(pbVar7 + 0x12) = *(undefined2 *)(iVar13 + 0x15);
    *(undefined2 *)(pbVar7 + 0x14) = *(undefined2 *)(iVar13 + 0x17);
    *(undefined4 *)(pbVar7 + (uint)*(byte *)(iVar10 + 0x2a) * 8 + 0x16) =
         *(undefined4 *)((uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8 + 7);
    *(undefined4 *)(pbVar7 + (uint)*(byte *)(iVar10 + 0x2a) * 8 + 0x1a) =
         *(undefined4 *)((uint)*(byte *)(iVar10 + 0x2a) * 0x2d + iVar8 + 0xb);
    pbVar7[*(byte *)(iVar10 + 0x2a) + 0x22] =
         *(byte *)(iVar8 + (uint)*(byte *)(iVar10 + 0x2a) * 0x2d + 6);
    iVar13 = FUN_0e07fb38(0,0xf);
    uVar9 = *(undefined4 *)(DAT_0e07e640 + iVar13 * 4);
    *pbVar7 = *pbVar7 | 2;
    *(undefined4 *)(pbVar7 + 0x1e) = uVar9;
    return;
  }
  return;
}


