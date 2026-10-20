/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07e0c8. Types and names are inferred; NOT original source. */

void FUN_0e07e0c8(void)

{
  undefined1 uVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  int iVar15;
  undefined4 *puVar16;
  
  if (DAT_230077a2 == '\0') {
    return;
  }
  uVar11 = (uint)DAT_23007735;
  if (DAT_23007731 == '\0') {
    if (uVar11 == DAT_23007734) {
      return;
    }
    DAT_23004cf7 = (&DAT_0e099278)[uVar11 * 4];
    DAT_23004cf9 = (&DAT_0e09927a)[uVar11 * 4];
    DAT_23004cf8 = (&DAT_0e099279)[uVar11 * 4];
    DAT_23004cfc = DAT_23007731;
    DAT_23004cf0 = 2;
  }
  else {
    if (uVar11 == DAT_23007734) {
      return;
    }
    DAT_23004cf7 = (&DAT_0e099278)[uVar11 * 4];
    DAT_23004cf8 = (&DAT_0e099279)[uVar11 * 4];
    DAT_23004cf9 = (&DAT_0e09927a)[uVar11 * 4];
    DAT_23004cf0 = 1;
    DAT_23004cfc = '\0';
  }
  DAT_23007734 = DAT_23007735;
  DAT_23004cfa = 0xff;
  DAT_23004cf6 = 0xff;
  DAT_23004cf2 = 1;
  uVar11 = (uint)DAT_23004ced;
  puVar14 = *(undefined4 **)(&DAT_230004e8 + uVar11 * 4);
  DAT_23004cf3 = DAT_23004cf7;
  DAT_23004cf4 = DAT_23004cf8;
  DAT_23004cf5 = DAT_23004cf9;
  DAT_23004cfb = DAT_23004cfc;
  if (DAT_23004cfc != '\0') {
    iVar6 = uVar11 * 0x2d;
    uVar5 = *(undefined4 *)(&DAT_23004cfd + iVar6);
    uVar8 = *(undefined4 *)(&DAT_23004d05 + iVar6);
    uVar12 = *(undefined4 *)(&DAT_23004d09 + iVar6);
    uVar7 = *(undefined4 *)(&DAT_23004d01 + iVar6);
    uVar1 = (&DAT_23004cef)[iVar6];
    iVar15 = (uint)DAT_23004477 * 0xf4 + iVar6;
    uVar4 = *(undefined2 *)(&DAT_23004d0d + iVar6);
    uVar3 = *(undefined1 *)((int)&DAT_23004d0e + iVar6 + 1);
    puVar10 = (undefined4 *)(&DAT_2300449d + iVar15);
    puVar9 = (undefined4 *)(&DAT_23004cec + iVar6);
    do {
      puVar16 = puVar9;
      puVar13 = puVar10;
      puVar10 = puVar13 + 4;
      *puVar16 = *puVar13;
      puVar16[1] = puVar13[1];
      puVar16[2] = puVar13[2];
      puVar16[3] = puVar13[3];
      puVar9 = puVar16 + 4;
    } while (puVar10 != (undefined4 *)(&DAT_230044bd + iVar15));
    puVar16[4] = *puVar10;
    puVar16[5] = puVar13[5];
    puVar16[6] = puVar13[6];
    *(undefined1 *)(puVar16 + 7) = *(undefined1 *)(puVar13 + 7);
    (&DAT_23004cef)[(uint)DAT_23004ced * 0x2d] = uVar1;
    iVar6 = (uint)DAT_23004ced * 0x2d;
    *(undefined4 *)(&DAT_23004d09 + iVar6) = uVar12;
    *(undefined4 *)(&DAT_23004cfd + iVar6) = uVar5;
    *(undefined2 *)(&DAT_23004d0d + iVar6) = uVar4;
    *(undefined4 *)(&DAT_23004d01 + iVar6) = uVar7;
    *(undefined4 *)(&DAT_23004d05 + iVar6) = uVar8;
    *(undefined1 *)((int)&DAT_23004d0e + iVar6 + 1) = uVar3;
    uVar11 = (uint)DAT_23004ced;
  }
  bVar2 = (&DAT_230004e4)[uVar11];
  if (bVar2 != 0) {
    puVar10 = puVar14;
    do {
      puVar9 = puVar10 + 3;
      puVar10[2] = puVar10[1];
      uVar11 = (uint)DAT_23004ced;
      puVar10 = puVar9;
    } while (puVar14 + (short)(ushort)bVar2 * 3 != puVar9);
  }
  switch((&UNK_0e09940c)
         [(uint)(byte)(&DAT_23004cf0)[uVar11 * 0x2d] +
          (uint)(byte)(&DAT_23004cef)[uVar11 * 0x2d] * 10]) {
  case 0:
    (&DAT_23004cef)[uVar11 * 0x2d] = (&DAT_23004cf0)[uVar11 * 0x2d];
    iVar6 = (uint)DAT_23004ced * 0x2d;
    (&DAT_23004d08)[iVar6] = 0;
    (&DAT_23004d06)[iVar6] = 0xd0;
    (&DAT_23004d07)[iVar6] = 7;
    (&DAT_23004d09)[iVar6] = 0;
    iVar6 = (uint)DAT_23004ced * 0x2d;
    (&DAT_23004d02)[iVar6] = 0xd0;
    (&DAT_23004d03)[iVar6] = 7;
    (&DAT_23004d04)[iVar6] = 0;
    (&DAT_23004d05)[iVar6] = 0;
    uVar11 = (uint)DAT_23004ced;
    break;
  case 1:
    (&DAT_23004cfd)[uVar11 * 0x2d] = 1;
    iVar6 = (uint)DAT_23004ced * 0x2d;
    (&DAT_23004d0a)[iVar6] = 0;
    (&DAT_23004d0b)[iVar6] = 0;
    (&DAT_23004d0c)[iVar6] = 0;
    (&DAT_23004d0d)[iVar6] = 0;
    uVar11 = (uint)DAT_23004ced;
    (&DAT_23004cfe)[uVar11 * 0x2d] = 10;
    (&DAT_23004cff)[uVar11 * 0x2d] = 0;
    uVar11 = (uint)DAT_23004ced;
    (&DAT_23004d00)[uVar11 * 0x2d] = 1;
    (&DAT_23004d01)[uVar11 * 0x2d] = 0;
    iVar6 = (uint)DAT_23004ced * 0x2d;
    (&DAT_23004d06)[iVar6] = 0xd0;
    (&DAT_23004d07)[iVar6] = 7;
    (&DAT_23004d08)[iVar6] = 0;
    (&DAT_23004d09)[iVar6] = 0;
    iVar6 = (uint)DAT_23004ced * 0x2d;
    (&DAT_23004d02)[iVar6] = 0xd0;
    (&DAT_23004d03)[iVar6] = 7;
    (&DAT_23004d04)[iVar6] = 0;
    (&DAT_23004d05)[iVar6] = 0;
    uVar11 = (uint)DAT_23004ced;
    *(undefined1 *)((int)&DAT_23004d0e + uVar11 * 0x2d) = 0;
    *(undefined1 *)((int)&DAT_23004d0e + uVar11 * 0x2d + 1) = 0;
    (&DAT_23004cef)[(uint)DAT_23004ced * 0x2d] = 9;
    uVar11 = (uint)DAT_23004ced;
    break;
  case 2:
  case 3:
    (&DAT_23004cfd)[uVar11 * 0x2d] = 3;
    iVar6 = (uint)DAT_23004ced * 0x2d;
    (&DAT_23004d08)[iVar6] = 0;
    (&DAT_23004d06)[iVar6] = 0xdc;
    (&DAT_23004d07)[iVar6] = 5;
    (&DAT_23004d09)[iVar6] = 0;
    iVar6 = (uint)DAT_23004ced * 0x2d;
    (&DAT_23004d02)[iVar6] = 0xdc;
    (&DAT_23004d03)[iVar6] = 5;
    (&DAT_23004d04)[iVar6] = 0;
    (&DAT_23004d05)[iVar6] = 0;
    uVar11 = (uint)DAT_23004ced;
    (&DAT_23004cfe)[uVar11 * 0x2d] = 10;
    (&DAT_23004cff)[uVar11 * 0x2d] = 0;
    uVar11 = (uint)DAT_23004ced;
    (&DAT_23004d00)[uVar11 * 0x2d] = 10;
    (&DAT_23004d01)[uVar11 * 0x2d] = 0;
    uVar11 = (uint)DAT_23004ced;
    *(undefined1 *)((int)&DAT_23004d0e + uVar11 * 0x2d) = 0;
    *(undefined1 *)((int)&DAT_23004d0e + uVar11 * 0x2d + 1) = 0;
    if (DAT_23004cef == '\x02') {
      uVar11 = (uint)DAT_23004ced;
      DAT_23004cef = '\t';
      break;
    }
    goto LAB_0e07e378;
  case 4:
    (&DAT_23004cfd)[uVar11 * 0x2d] = 2;
    iVar6 = (uint)DAT_23004ced * 0x2d;
    (&DAT_23004d06)[iVar6] = 0xd0;
    (&DAT_23004d07)[iVar6] = 7;
    (&DAT_23004d08)[iVar6] = 0;
    (&DAT_23004d09)[iVar6] = 0;
    iVar6 = (uint)DAT_23004ced * 0x2d;
    (&DAT_23004d02)[iVar6] = 0;
    (&DAT_23004d03)[iVar6] = 0;
    (&DAT_23004d04)[iVar6] = 0;
    (&DAT_23004d05)[iVar6] = 0;
    uVar11 = (uint)DAT_23004ced;
    (&DAT_23004cff)[uVar11 * 0x2d] = 0;
    (&DAT_23004cfe)[uVar11 * 0x2d] = 10;
    uVar11 = (uint)DAT_23004ced;
    (&DAT_23004d01)[uVar11 * 0x2d] = 0;
    (&DAT_23004d00)[uVar11 * 0x2d] = 1;
    uVar11 = (uint)DAT_23004ced;
    *(undefined1 *)((int)&DAT_23004d0e + uVar11 * 0x2d) = 0;
    *(undefined1 *)((int)&DAT_23004d0e + uVar11 * 0x2d + 1) = 0;
    (&DAT_23004cef)[(uint)DAT_23004ced * 0x2d] = (&DAT_23004cf0)[(uint)DAT_23004ced * 0x2d];
LAB_0e07e378:
    uVar11 = (uint)DAT_23004ced;
  }
  if ((&DAT_23004cf0)[uVar11 * 0x2d] == '\x01') {
    if (bVar2 != 0) {
      puVar10 = puVar14;
      do {
        puVar9 = puVar10 + 3;
        *puVar10 = *(undefined4 *)(&DAT_23004cf3 + uVar11 * 0x2d);
        uVar11 = (uint)DAT_23004ced;
        puVar10 = puVar9;
      } while (puVar9 != puVar14 + (short)(ushort)bVar2 * 3);
      return;
    }
  }
  else if ((&DAT_23004cf0)[uVar11 * 0x2d] == '\x02') {
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
    *(undefined4 *)(&DAT_23004d36 + (uint)DAT_23004ced * 8) =
         *(undefined4 *)(&DAT_23004cf3 + (uint)DAT_23004ced * 0x2d);
    *(undefined4 *)(&DAT_23004d3a + (uint)DAT_23004ced * 8) =
         *(undefined4 *)(&DAT_23004cf7 + (uint)DAT_23004ced * 0x2d);
    (&DAT_23004d42)[DAT_23004ced] = (&DAT_23004cf2)[(uint)DAT_23004ced * 0x2d];
    iVar6 = FUN_0e07f9ac(0,0xf);
    DAT_23004d20 = DAT_23004d20 | 2;
    DAT_23004d3e = *(undefined4 *)(&DAT_0e099470 + iVar6 * 4);
    return;
  }
  return;
}


