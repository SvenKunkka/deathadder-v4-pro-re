/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e073120. Types and names are inferred; NOT original source. */

void FUN_0e073120(void)

{
  byte bVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  
  iVar4 = DAT_0e0731d8;
  bVar1 = *(byte *)(DAT_0e0731d8 + 3);
  iVar9 = (uint)bVar1 * 0xf4 + DAT_0e0731d8;
  puVar8 = DAT_0e0731dc;
  puVar14 = (undefined4 *)(iVar9 + 0x5a);
  do {
    puVar13 = puVar14;
    puVar11 = puVar8;
    puVar14 = puVar13 + 4;
    *puVar11 = *puVar13;
    puVar11[1] = puVar13[1];
    puVar11[2] = puVar13[2];
    puVar11[3] = puVar13[3];
    puVar5 = DAT_0e0731e0;
    puVar8 = puVar11 + 4;
  } while (puVar14 != (undefined4 *)(iVar9 + 0x7a));
  puVar11[4] = *puVar14;
  puVar8 = DAT_0e0731e4;
  puVar11[5] = puVar13[5];
  puVar11[6] = puVar13[6];
  iVar9 = (uint)bVar1 * 0xf4 + iVar4;
  *puVar5 = *(undefined4 *)(iVar9 + 0x86);
  *puVar8 = *(undefined4 *)(iVar9 + 0x56);
  puVar5[1] = *(undefined4 *)(iVar9 + 0x8a);
  uVar3 = *(undefined1 *)(iVar9 + 0x90);
  *(undefined2 *)(puVar5 + 2) = *(undefined2 *)(iVar9 + 0x8e);
  *(undefined1 *)((int)puVar5 + 10) = uVar3;
  FUN_0e078ed4(*(undefined1 *)((int)puVar5 + 2));
  puVar6 = DAT_0e0731f0;
  iVar9 = DAT_0e0731e8;
  iVar12 = (uint)*(byte *)(iVar4 + 3) * 0xf4;
  iVar10 = iVar12 + 0x70;
  uVar2 = *(undefined2 *)(DAT_0e0731e8 + iVar10);
  *DAT_0e0731ec = *(undefined1 *)(iVar4 + iVar12 + 0x7f);
  *puVar6 = uVar2;
  puVar6 = DAT_0e0731fc;
  iVar4 = DAT_0e0731f4;
  uVar2 = *(undefined2 *)(iVar9 + 4 + iVar10);
  *DAT_0e0731f8 = *(undefined2 *)(iVar9 + 2 + iVar10);
  *puVar6 = uVar2;
  puVar7 = DAT_0e073204;
  uVar3 = *(undefined1 *)(iVar4 + 0x2e);
  *DAT_0e073200 = *(undefined1 *)(iVar4 + 0x2d);
  *puVar7 = uVar3;
  return;
}


