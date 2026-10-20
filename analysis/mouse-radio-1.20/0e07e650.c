/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07e650. Types and names are inferred; NOT original source. */

void FUN_0e07e650(void)

{
  undefined1 uVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  uint uVar14;
  undefined4 *puVar15;
  int iVar16;
  undefined4 *puVar17;
  
  DAT_23004d1c = DAT_230049cf;
  iVar7 = (uint)DAT_23004477 * 0xf4;
  DAT_23004cef = 0;
  puVar15 = *(undefined4 **)(&DAT_230004e8 + (uint)*(byte *)(iVar7 + 0x2300449e) * 4);
  iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
  uVar6 = *(undefined4 *)(&DAT_23004cfd + iVar5);
  uVar9 = *(undefined4 *)(&DAT_23004d05 + iVar5);
  uVar12 = *(undefined4 *)(&DAT_23004d09 + iVar5);
  uVar8 = *(undefined4 *)(&DAT_23004d01 + iVar5);
  uVar1 = (&DAT_23004cef)[iVar5];
  iVar16 = (uint)DAT_23004477 * 0xf4 + iVar5;
  uVar4 = *(undefined2 *)(&DAT_23004d0d + iVar5);
  uVar3 = *(undefined1 *)((int)&DAT_23004d0e + iVar5 + 1);
  puVar11 = (undefined4 *)(&DAT_2300449d + iVar16);
  puVar10 = (undefined4 *)(&DAT_23004cec + iVar5);
  do {
    puVar17 = puVar10;
    puVar13 = puVar11;
    puVar11 = puVar13 + 4;
    *puVar17 = *puVar13;
    puVar17[1] = puVar13[1];
    puVar17[2] = puVar13[2];
    puVar17[3] = puVar13[3];
    puVar10 = puVar17 + 4;
  } while (puVar11 != (undefined4 *)(&DAT_230044bd + iVar16));
  puVar17[4] = *puVar11;
  puVar17[5] = puVar13[5];
  puVar17[6] = puVar13[6];
  *(undefined1 *)(puVar17 + 7) = *(undefined1 *)(puVar13 + 7);
  (&DAT_23004cef)[(uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d] = uVar1;
  iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
  *(undefined4 *)(&DAT_23004d09 + iVar5) = uVar12;
  *(undefined4 *)(&DAT_23004cfd + iVar5) = uVar6;
  *(undefined2 *)(&DAT_23004d0d + iVar5) = uVar4;
  *(undefined4 *)(&DAT_23004d01 + iVar5) = uVar8;
  *(undefined4 *)(&DAT_23004d05 + iVar5) = uVar9;
  *(undefined1 *)((int)&DAT_23004d0e + iVar5 + 1) = uVar3;
  uVar14 = (uint)*(byte *)(iVar7 + 0x2300449e);
  bVar2 = (&DAT_230004e4)[uVar14];
  if (bVar2 != 0) {
    puVar11 = puVar15;
    do {
      puVar10 = puVar11 + 3;
      puVar11[2] = puVar11[1];
      uVar14 = (uint)*(byte *)(iVar7 + 0x2300449e);
      puVar11 = puVar10;
    } while (puVar15 + (short)(ushort)bVar2 * 3 != puVar10);
  }
  switch((&UNK_0e09940c)
         [(uint)(byte)(&DAT_23004cf0)[uVar14 * 0x2d] +
          (uint)(byte)(&DAT_23004cef)[uVar14 * 0x2d] * 10]) {
  case 0:
    (&DAT_23004cef)[uVar14 * 0x2d] = (&DAT_23004cf0)[uVar14 * 0x2d];
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004d08)[iVar5] = 0;
    (&DAT_23004d06)[iVar5] = 0xd0;
    (&DAT_23004d07)[iVar5] = 7;
    (&DAT_23004d09)[iVar5] = 0;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004d02)[iVar5] = 0xd0;
    (&DAT_23004d03)[iVar5] = 7;
    (&DAT_23004d04)[iVar5] = 0;
    (&DAT_23004d05)[iVar5] = 0;
    uVar14 = (uint)*(byte *)(iVar7 + 0x2300449e);
    break;
  case 1:
    (&DAT_23004cfd)[uVar14 * 0x2d] = 1;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004d0a)[iVar5] = 0;
    (&DAT_23004d0b)[iVar5] = 0;
    (&DAT_23004d0c)[iVar5] = 0;
    (&DAT_23004d0d)[iVar5] = 0;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004cfe)[iVar5] = 10;
    (&DAT_23004cff)[iVar5] = 0;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004d00)[iVar5] = 1;
    (&DAT_23004d01)[iVar5] = 0;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004d06)[iVar5] = 0xd0;
    (&DAT_23004d07)[iVar5] = 7;
    (&DAT_23004d08)[iVar5] = 0;
    (&DAT_23004d09)[iVar5] = 0;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004d02)[iVar5] = 0xd0;
    (&DAT_23004d03)[iVar5] = 7;
    (&DAT_23004d04)[iVar5] = 0;
    (&DAT_23004d05)[iVar5] = 0;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    *(undefined1 *)((int)&DAT_23004d0e + iVar5) = 0;
    *(undefined1 *)((int)&DAT_23004d0e + iVar5 + 1) = 0;
    (&DAT_23004cef)[(uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d] = 9;
    uVar14 = (uint)*(byte *)(iVar7 + 0x2300449e);
    break;
  case 2:
  case 3:
    (&DAT_23004cfd)[uVar14 * 0x2d] = 3;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004d08)[iVar5] = 0;
    (&DAT_23004d06)[iVar5] = 0xdc;
    (&DAT_23004d07)[iVar5] = 5;
    (&DAT_23004d09)[iVar5] = 0;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004d02)[iVar5] = 0xdc;
    (&DAT_23004d03)[iVar5] = 5;
    (&DAT_23004d04)[iVar5] = 0;
    (&DAT_23004d05)[iVar5] = 0;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004cfe)[iVar5] = 10;
    (&DAT_23004cff)[iVar5] = 0;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004d00)[iVar5] = 10;
    (&DAT_23004d01)[iVar5] = 0;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    *(undefined1 *)((int)&DAT_23004d0e + iVar5) = 0;
    *(undefined1 *)((int)&DAT_23004d0e + iVar5 + 1) = 0;
    if (*(char *)(iVar7 + 0x230044a0) == '\x02') {
      uVar14 = (uint)*(byte *)(iVar7 + 0x2300449e);
      *(undefined1 *)(iVar7 + 0x230044a0) = 9;
      break;
    }
    goto LAB_0e07e378;
  case 4:
    (&DAT_23004cfd)[uVar14 * 0x2d] = 2;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004d06)[iVar5] = 0xd0;
    (&DAT_23004d07)[iVar5] = 7;
    (&DAT_23004d08)[iVar5] = 0;
    (&DAT_23004d09)[iVar5] = 0;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004d02)[iVar5] = 0;
    (&DAT_23004d03)[iVar5] = 0;
    (&DAT_23004d04)[iVar5] = 0;
    (&DAT_23004d05)[iVar5] = 0;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004cff)[iVar5] = 0;
    (&DAT_23004cfe)[iVar5] = 10;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004d01)[iVar5] = 0;
    (&DAT_23004d00)[iVar5] = 1;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    *(undefined1 *)((int)&DAT_23004d0e + iVar5) = 0;
    *(undefined1 *)((int)&DAT_23004d0e + iVar5 + 1) = 0;
    iVar5 = (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d;
    (&DAT_23004cef)[iVar5] = (&DAT_23004cf0)[iVar5];
LAB_0e07e378:
    uVar14 = (uint)*(byte *)(iVar7 + 0x2300449e);
  }
  if ((&DAT_23004cf0)[uVar14 * 0x2d] == '\x01') {
    if (bVar2 != 0) {
      puVar11 = puVar15;
      do {
        puVar10 = puVar11 + 3;
        *puVar11 = *(undefined4 *)(&DAT_23004cf3 + uVar14 * 0x2d);
        uVar14 = (uint)*(byte *)(iVar7 + 0x2300449e);
        puVar11 = puVar10;
      } while (puVar10 != puVar15 + (short)(ushort)bVar2 * 3);
      return;
    }
  }
  else if ((&DAT_23004cf0)[uVar14 * 0x2d] == '\x02') {
    DAT_23004d22 = DAT_2300447d;
    DAT_23004d26 = DAT_2300447d;
    DAT_23004d43 = 0;
    DAT_23004d44 = 0;
    DAT_23004d21 = 1;
    DAT_23004d24 = CONCAT11(DAT_2300447c,DAT_2300447b);
    DAT_23004d28 = CONCAT11(DAT_23004480,DAT_2300447f);
    DAT_23004d2a = CONCAT11(DAT_23004482,DAT_23004481);
    DAT_23004d2c = CONCAT11(DAT_23004484,DAT_23004483);
    DAT_23004d2e = CONCAT11(DAT_23004486,DAT_23004485);
    DAT_23004d30 = CONCAT11(DAT_23004488,DAT_23004487);
    DAT_23004d32 = CONCAT11(DAT_2300448a,DAT_23004489);
    DAT_23004d34 = CONCAT11(DAT_2300448c,DAT_2300448b);
    *(undefined4 *)(&DAT_23004d36 + (uint)*(byte *)(iVar7 + 0x2300449e) * 8) =
         *(undefined4 *)(&DAT_23004cf3 + (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d);
    *(undefined4 *)(&DAT_23004d3a + (uint)*(byte *)(iVar7 + 0x2300449e) * 8) =
         *(undefined4 *)(&DAT_23004cf7 + (uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d);
    (&DAT_23004d42)[*(byte *)(iVar7 + 0x2300449e)] =
         (&DAT_23004cf2)[(uint)*(byte *)(iVar7 + 0x2300449e) * 0x2d];
    iVar7 = FUN_0e07f9ac(0,0xf);
    DAT_23004d20 = DAT_23004d20 | 2;
    DAT_23004d3e = *(undefined4 *)(&DAT_0e099470 + iVar7 * 4);
    return;
  }
  return;
}


