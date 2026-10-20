/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08e5a8. Types and names are inferred; NOT original source. */

int FUN_0e08e5a8(int param_1)

{
  short sVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  bool bVar12;
  
  iVar8 = *(int *)(param_1 + 0x10);
  puVar5 = *(uint **)(param_1 + 4);
  iVar6 = *(int *)(iVar8 + 0xac);
  FUN_0e094d74(iVar8 + 0x84);
  FUN_0e096d4c(iVar6 + 0x90);
  FUN_0e096d4c(iVar6 + 0x9c);
  FUN_0e096d4c(iVar6 + 0xa8);
  *(byte *)(iVar8 + 0x80) = *(byte *)(iVar8 + 0x80) & 0x95 | 0x6a;
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x18);
  if ((iVar6 != 0) && (pcVar3 = *(code **)(iVar6 + 0x18), pcVar3 != (code *)0x0)) {
    (*pcVar3)(param_1);
  }
  uVar10 = 0;
  uVar4 = puVar5[0xc];
  uVar9 = 0;
  uVar2 = puVar5[10];
  sVar1 = (*(byte *)(iVar8 + 0x80) & 1) + 0x3ff;
  uVar7 = (puVar5[0xb] & 0x3fff) >> 10;
  do {
    if (((3 << (uVar10 << 1 & 0xff) & uVar2) >> (uVar10 << 1 & 0xff) & 0xfffffffd) == 0) {
      iVar11 = uVar9 * 0x20;
      iVar6 = puVar5[3] + iVar11;
      if (uVar10 == 0) {
        *(byte *)(iVar6 + 0x12) = *(byte *)(iVar6 + 0x12) | 1;
        *(undefined2 *)(puVar5[3] + iVar11 + 0x10) = 0x40;
      }
      else {
        *(byte *)(iVar6 + 0x12) = *(byte *)(iVar6 + 0x12) | 4;
        *(byte *)(puVar5[3] + iVar11 + 0x12) = *(byte *)(puVar5[3] + iVar11 + 0x12) | 2;
        *(byte *)(puVar5[3] + iVar11 + 0x12) = *(byte *)(puVar5[3] + iVar11 + 0x12) | 8;
        *(byte *)(puVar5[3] + iVar11 + 0x12) =
             *(byte *)(puVar5[3] + iVar11 + 0x12) & 0xef | (*(byte *)(iVar8 + 0x80) & 1) << 4;
        *(short *)(puVar5[3] + iVar11 + 0x10) = sVar1;
      }
      uVar9 = uVar9 + 1;
      *(byte *)(puVar5[3] + iVar11 + 0x12) = *(byte *)(puVar5[3] + iVar11 + 0x12) | 0x40;
      *(char *)(puVar5[3] + iVar11 + 0x18) = (char)uVar10;
      iVar6 = FUN_0e08d2c4(param_1,puVar5[3] + iVar11);
      if (iVar6 != 0) {
        return iVar6;
      }
      uVar2 = puVar5[10];
      if (puVar5[1] <= uVar9) break;
    }
    bVar12 = uVar7 != uVar10;
    uVar10 = uVar10 + 1;
  } while (bVar12);
  uVar4 = ((uVar4 & 0x3fffffff) >> 0x1a) + 1;
  uVar10 = 0;
  uVar9 = 0;
  do {
    if ((3 << (uVar10 << 1 & 0xff) & uVar2) >> (uVar10 << 1 & 0xff) < 2) {
      iVar11 = uVar9 * 0x20;
      iVar6 = puVar5[2] + iVar11;
      if (uVar10 == 0) {
        *(byte *)(iVar6 + 0x12) = *(byte *)(iVar6 + 0x12) | 1;
        *(undefined2 *)(puVar5[2] + iVar11 + 0x10) = 0x40;
      }
      else {
        *(byte *)(iVar6 + 0x12) = *(byte *)(iVar6 + 0x12) | 4;
        *(byte *)(puVar5[2] + iVar11 + 0x12) = *(byte *)(puVar5[2] + iVar11 + 0x12) | 2;
        *(byte *)(puVar5[2] + iVar11 + 0x12) = *(byte *)(puVar5[2] + iVar11 + 0x12) | 8;
        *(byte *)(puVar5[2] + iVar11 + 0x12) =
             *(byte *)(puVar5[2] + iVar11 + 0x12) & 0xef | (*(byte *)(iVar8 + 0x80) & 1) << 4;
        *(short *)(puVar5[2] + iVar11 + 0x10) = sVar1;
      }
      uVar9 = uVar9 + 1;
      *(byte *)(puVar5[2] + iVar11 + 0x12) = *(byte *)(puVar5[2] + iVar11 + 0x12) | 0x20;
      *(byte *)(puVar5[2] + iVar11 + 0x18) = (byte)uVar10 | 0x80;
      iVar6 = FUN_0e08d2c4(param_1,puVar5[2] + iVar11);
      if (iVar6 != 0) {
        return iVar6;
      }
      uVar2 = *puVar5;
      if (uVar4 <= *puVar5) {
        uVar2 = uVar4;
      }
      if (uVar2 <= uVar9) {
LAB_0e08e790:
        (*(code *)puVar5[7])(param_1);
        return 0;
      }
    }
    bVar12 = uVar7 == uVar10;
    uVar10 = uVar10 + 1;
    if (bVar12) goto LAB_0e08e790;
    uVar2 = puVar5[10];
  } while( true );
}


