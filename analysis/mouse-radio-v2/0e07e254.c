/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07e254. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e07e362) */
/* WARNING: Removing unreachable block (ram,0x0e07e3b0) */
/* WARNING: Removing unreachable block (ram,0x0e07e3d8) */

void FUN_0e07e254(void)

{
  byte bVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  byte *pbVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  uint uVar13;
  int iVar14;
  undefined4 *puVar15;
  
  if (*DAT_0e07e2fc == '\0') {
    return;
  }
  bVar1 = *DAT_0e07e304;
  uVar13 = (uint)bVar1;
  if (*DAT_0e07e300 == '\0') {
    if (uVar13 == *DAT_0e07e308) {
      return;
    }
    *DAT_0e07e308 = bVar1;
    iVar8 = DAT_0e07e310;
    iVar14 = DAT_0e07e30c + uVar13 * 4;
    uVar5 = *(undefined1 *)(DAT_0e07e30c + uVar13 * 4);
    *(undefined1 *)(DAT_0e07e310 + 10) = 0xff;
    *(undefined1 *)(iVar8 + 7) = uVar5;
    *(undefined1 *)(iVar8 + 0xb) = uVar5;
    *(undefined1 *)(iVar8 + 0xe) = 0xff;
    uVar5 = *(undefined1 *)(iVar14 + 2);
    uVar2 = *(undefined1 *)(iVar14 + 1);
    *(undefined1 *)(iVar8 + 0x10) = 0;
    *(undefined1 *)(iVar8 + 0xf) = 0;
    *(undefined1 *)(iVar8 + 4) = 2;
    *(undefined1 *)(iVar8 + 6) = 1;
    *(undefined1 *)(iVar8 + 8) = uVar2;
    *(undefined1 *)(iVar8 + 0xc) = uVar2;
    *(undefined1 *)(iVar8 + 9) = uVar5;
    *(undefined1 *)(iVar8 + 0xd) = uVar5;
  }
  else {
    if (uVar13 == *DAT_0e07e308) {
      return;
    }
    *DAT_0e07e308 = bVar1;
    iVar8 = DAT_0e07e310;
    iVar14 = DAT_0e07e30c + uVar13 * 4;
    uVar5 = *(undefined1 *)(DAT_0e07e30c + uVar13 * 4);
    uVar2 = *(undefined1 *)(iVar14 + 1);
    *(undefined1 *)(DAT_0e07e310 + 7) = uVar5;
    *(undefined1 *)(iVar8 + 0xb) = uVar5;
    uVar5 = *(undefined1 *)(iVar14 + 2);
    *(undefined1 *)(iVar8 + 8) = uVar2;
    *(undefined1 *)(iVar8 + 0xc) = uVar2;
    *(undefined1 *)(iVar8 + 9) = uVar5;
    *(undefined1 *)(iVar8 + 0xd) = uVar5;
    *(undefined1 *)(iVar8 + 4) = 1;
    *(undefined1 *)(iVar8 + 0x10) = 0;
    *(undefined1 *)(iVar8 + 0xf) = 0;
    *(undefined1 *)(iVar8 + 6) = 1;
    *(undefined1 *)(iVar8 + 10) = 0xff;
    *(undefined1 *)(iVar8 + 0xe) = 0xff;
  }
  iVar14 = DAT_0e07e62c;
  uVar13 = (uint)*(byte *)(iVar8 + 1);
  puVar15 = *(undefined4 **)(DAT_0e07e628 + uVar13 * 4);
  bVar1 = *(byte *)(DAT_0e07e634 + uVar13);
  if (bVar1 != 0) {
    puVar12 = puVar15;
    do {
      puVar10 = puVar12 + 3;
      puVar12[2] = puVar12[1];
      uVar13 = (uint)*(byte *)(iVar8 + 1);
      puVar12 = puVar10;
    } while (puVar15 + (short)(ushort)bVar1 * 3 != puVar10);
  }
  iVar11 = uVar13 * 0x2d + iVar14;
  bVar3 = *(byte *)(iVar11 + 4);
  switch(*(undefined1 *)(DAT_0e07e638 + (uint)*(byte *)(iVar11 + 3) * 10 + (uint)bVar3)) {
  case 0:
    *(byte *)(uVar13 * 0x2d + iVar14 + 3) = bVar3;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x1c) = 0;
    *(undefined1 *)(iVar11 + 0x1a) = 0xd0;
    *(undefined1 *)(iVar11 + 0x1b) = 7;
    *(undefined1 *)(iVar11 + 0x1d) = 0;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x16) = 0xd0;
    *(undefined1 *)(iVar11 + 0x17) = 7;
    *(undefined1 *)(iVar11 + 0x18) = 0;
    *(undefined1 *)(iVar11 + 0x19) = 0;
    uVar13 = (uint)*(byte *)(iVar8 + 1);
    break;
  case 1:
    *(undefined1 *)(uVar13 * 0x2d + iVar14 + 0x11) = 1;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x1e) = 0;
    *(undefined1 *)(iVar11 + 0x1f) = 0;
    *(undefined1 *)(iVar11 + 0x20) = 0;
    *(undefined1 *)(iVar11 + 0x21) = 0;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x12) = 10;
    *(undefined1 *)(iVar11 + 0x13) = 0;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x14) = 1;
    *(undefined1 *)(iVar11 + 0x15) = 0;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x1a) = 0xd0;
    *(undefined1 *)(iVar11 + 0x1b) = 7;
    *(undefined1 *)(iVar11 + 0x1c) = 0;
    *(undefined1 *)(iVar11 + 0x1d) = 0;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x16) = 0xd0;
    *(undefined1 *)(iVar11 + 0x17) = 7;
    *(undefined1 *)(iVar11 + 0x18) = 0;
    *(undefined1 *)(iVar11 + 0x19) = 0;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x22) = 0;
    *(undefined1 *)(iVar11 + 0x23) = 0;
    *(undefined1 *)((uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14 + 3) = 9;
    uVar13 = (uint)*(byte *)(iVar8 + 1);
    break;
  case 2:
  case 3:
    *(undefined1 *)(uVar13 * 0x2d + iVar14 + 0x11) = 3;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x1c) = 0;
    *(undefined1 *)(iVar11 + 0x1a) = 0xdc;
    *(undefined1 *)(iVar11 + 0x1b) = 5;
    *(undefined1 *)(iVar11 + 0x1d) = 0;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x16) = 0xdc;
    *(undefined1 *)(iVar11 + 0x17) = 5;
    *(undefined1 *)(iVar11 + 0x18) = 0;
    *(undefined1 *)(iVar11 + 0x19) = 0;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x12) = 10;
    *(undefined1 *)(iVar11 + 0x13) = 0;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x14) = 10;
    *(undefined1 *)(iVar11 + 0x15) = 0;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x22) = 0;
    *(undefined1 *)(iVar11 + 0x23) = 0;
    if (*(char *)(iVar8 + 3) == '\x02') {
      uVar13 = (uint)*(byte *)(iVar8 + 1);
      *(undefined1 *)(iVar8 + 3) = 9;
      break;
    }
    goto LAB_0e07e504;
  case 4:
    *(undefined1 *)(uVar13 * 0x2d + iVar14 + 0x11) = 2;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x1a) = 0xd0;
    *(undefined1 *)(iVar11 + 0x1b) = 7;
    *(undefined1 *)(iVar11 + 0x1c) = 0;
    *(undefined1 *)(iVar11 + 0x1d) = 0;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x16) = 0;
    *(undefined1 *)(iVar11 + 0x17) = 0;
    *(undefined1 *)(iVar11 + 0x18) = 0;
    *(undefined1 *)(iVar11 + 0x19) = 0;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x13) = 0;
    *(undefined1 *)(iVar11 + 0x12) = 10;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x15) = 0;
    *(undefined1 *)(iVar11 + 0x14) = 1;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 0x22) = 0;
    *(undefined1 *)(iVar11 + 0x23) = 0;
    iVar11 = (uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14;
    *(undefined1 *)(iVar11 + 3) = *(undefined1 *)(iVar11 + 4);
LAB_0e07e504:
    uVar13 = (uint)*(byte *)(iVar8 + 1);
  }
  pbVar7 = DAT_0e07e63c;
  iVar11 = DAT_0e07e630;
  cVar4 = *(char *)(uVar13 * 0x2d + iVar14 + 4);
  if (cVar4 == '\x01') {
    if (bVar1 != 0) {
      puVar12 = puVar15;
      do {
        puVar10 = puVar12 + 3;
        *puVar12 = *(undefined4 *)(uVar13 * 0x2d + iVar14 + 7);
        uVar13 = (uint)*(byte *)(iVar8 + 1);
        puVar12 = puVar10;
      } while (puVar10 != puVar15 + (short)(ushort)bVar1 * 3);
      return;
    }
  }
  else if (cVar4 == '\x02') {
    uVar6 = *(undefined2 *)(DAT_0e07e630 + 9);
    *(undefined2 *)(DAT_0e07e63c + 2) = uVar6;
    *(undefined2 *)(pbVar7 + 6) = uVar6;
    pbVar7[0x23] = 0;
    pbVar7[0x24] = 0;
    pbVar7[0x25] = 0;
    pbVar7[0x26] = 0;
    pbVar7[0x27] = 0;
    pbVar7[1] = 1;
    *(undefined2 *)(pbVar7 + 4) = *(undefined2 *)(iVar11 + 7);
    *(undefined2 *)(pbVar7 + 8) = *(undefined2 *)(iVar11 + 0xb);
    *(undefined2 *)(pbVar7 + 10) = *(undefined2 *)(iVar11 + 0xd);
    *(undefined2 *)(pbVar7 + 0xc) = *(undefined2 *)(iVar11 + 0xf);
    *(undefined2 *)(pbVar7 + 0xe) = *(undefined2 *)(iVar11 + 0x11);
    *(undefined2 *)(pbVar7 + 0x10) = *(undefined2 *)(iVar11 + 0x13);
    *(undefined2 *)(pbVar7 + 0x12) = *(undefined2 *)(iVar11 + 0x15);
    *(undefined2 *)(pbVar7 + 0x14) = *(undefined2 *)(iVar11 + 0x17);
    *(undefined4 *)(pbVar7 + (uint)*(byte *)(iVar8 + 1) * 8 + 0x16) =
         *(undefined4 *)((uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14 + 7);
    *(undefined4 *)(pbVar7 + (uint)*(byte *)(iVar8 + 1) * 8 + 0x1a) =
         *(undefined4 *)((uint)*(byte *)(iVar8 + 1) * 0x2d + iVar14 + 0xb);
    pbVar7[*(byte *)(iVar8 + 1) + 0x22] = *(byte *)(iVar14 + (uint)*(byte *)(iVar8 + 1) * 0x2d + 6);
    iVar8 = FUN_0e07fb38(0,0xf);
    uVar9 = *(undefined4 *)(DAT_0e07e640 + iVar8 * 4);
    *pbVar7 = *pbVar7 | 2;
    *(undefined4 *)(pbVar7 + 0x1e) = uVar9;
    return;
  }
  return;
}


