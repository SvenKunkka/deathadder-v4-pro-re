/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08e7a0. Types and names are inferred; NOT original source. */

int FUN_0e08e7a0(int param_1)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  undefined2 *puVar5;
  ushort uVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  
  iVar13 = *(int *)(param_1 + 4);
  iVar14 = *(int *)(iVar13 + 0x10);
  iVar4 = iVar14;
  if ((*(int *)(iVar13 + 0x18) != 0) &&
     (pcVar7 = *(code **)(*(int *)(iVar13 + 0x18) + 4), pcVar7 != (code *)0x0)) {
    iVar4 = (*pcVar7)();
    if (iVar4 != 0) {
      return iVar4;
    }
    iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  }
  iVar10 = 0x2711;
  iVar12 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  iVar8 = *(int *)(iVar4 + 0x10);
  while (-1 < iVar8) {
    FUN_0e09467c(1);
    iVar10 = iVar10 + -1;
    if (iVar10 == 0) {
      return -5;
    }
    iVar8 = *(int *)(iVar4 + 0x10);
  }
  iVar10 = 0x2711;
  *(undefined4 *)(iVar4 + 0x10) = 1;
  do {
    iVar10 = iVar10 + -1;
    if (iVar10 == 0) {
      return -5;
    }
    FUN_0e09467c(1);
    uVar11 = DAT_0e08ea9c;
  } while ((*(int *)(iVar4 + 0x10) << 0x1f < 0) && (-1 < *(int *)(iVar4 + 0x10) << 2));
  *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) & 0xdffffffe;
  *(byte *)(iVar12 + 0x362) =
       *(byte *)(iVar12 + 0x362) & 0xf7 | (*(uint *)(iVar4 + 0x40) <= uVar11) << 3;
  *(undefined4 *)(iVar12 + 0x2ac) = *(undefined4 *)(iVar4 + 0x44);
  uVar11 = *(uint *)(iVar4 + 0x48);
  uVar16 = *(uint *)(iVar4 + 0x4c);
  uVar15 = *(uint *)(iVar4 + 0x50);
  if ((uVar15 & 0x2000000) == 0) {
    iVar4 = -0x86;
  }
  else {
    *(undefined4 *)(iVar4 + 0xc) = 0x40000000;
    FUN_0e09628c(0x30e,0);
    bVar2 = *(byte *)(iVar12 + 0x362) & 0xfd;
    *(byte *)(iVar12 + 0x362) = bVar2;
    if ((int)(uVar11 << 0xc) < 0) {
      *(byte *)(iVar12 + 0x362) = bVar2 | 1;
    }
    *(byte *)(iVar12 + 0x364) = (byte)((uVar11 << 0x12) >> 0x1c) + 1;
    *(byte *)(iVar12 + 0x365) = (byte)((uVar15 << 2) >> 0x1c) + 1;
    *(int *)(iVar12 + 0x2b4) = (1 << (uVar16 & 0xf) + 0xb) + -1;
    *(byte *)(iVar12 + 0x363) = (byte)((uVar15 << 0x19) >> 0x1f);
    *(int *)(iVar12 + 0x2b8) = (1 << ((uVar16 & 0x7f) >> 4) + 4) + -1;
    *(short *)(iVar12 + 0x33c) = (short)(uVar16 >> 0x10);
    if ((uVar16 & 0x800) != 0) {
      *(byte *)(iVar12 + 0x362) = *(byte *)(iVar12 + 0x362) | 4;
    }
    if ((int)((uint)*(byte *)(iVar12 + 0x362) << 0x1e) < 0) {
      uVar16 = *(uint *)(iVar4 + 8) | 0x20;
    }
    else {
      uVar16 = *(uint *)(iVar4 + 8) & 0xffffffdf;
    }
    *(uint *)(iVar4 + 8) = uVar16;
    uVar16 = (uVar11 & 0xff) >> 6;
    uVar9 = *(uint *)(iVar4 + 0x800) & 0xff7ffffc;
    if (uVar16 == 1) {
      uVar16 = 0x40000000;
      bVar3 = true;
    }
    else if (uVar16 - 2 < 2) {
      bVar3 = true;
      uVar16 = DAT_0e08eaa0;
    }
    else {
      bVar3 = false;
      uVar16 = DAT_0e08eaa8;
      if ((uVar11 & 0x300) == 0) {
        uVar16 = 0x40000000;
      }
      uVar9 = uVar9 | 3;
    }
    if ((uVar15 & 0xc000) != 0) {
      uVar16 = uVar16 | 8;
    }
    *(uint *)(iVar4 + 0xc) = uVar16;
    uVar11 = 0;
    *(uint *)(iVar4 + 0x800) = uVar9;
    uVar15 = (uint)*(byte *)(iVar12 + 0x364);
    *(undefined1 *)(iVar12 + 0x366) = 0;
    if (uVar15 != 0) {
      uVar16 = 0;
      do {
        if (((3 << (uVar16 << 1 & 0xff) & *(uint *)(iVar12 + 0x2ac)) >> (uVar16 << 1 & 0xff) &
            0xfffffffd) == 0) {
          iVar10 = (uVar11 & 0x7f) + 0x58;
          if ((uVar11 & 0x80) != 0) {
            iVar10 = (uVar11 & 0x7f) + 0x48;
          }
          *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + iVar10 * 0x20) = 0x8000000;
          uVar15 = (uint)*(byte *)(iVar12 + 0x364);
          *(char *)(iVar12 + 0x366) = *(char *)(iVar12 + 0x366) + '\x01';
        }
        uVar11 = uVar11 + 1;
        uVar16 = uVar11 & 0xff;
      } while (uVar16 < uVar15);
    }
    bVar2 = *(byte *)(iVar12 + 0x365);
    bVar1 = *(byte *)(iVar12 + 0x362);
    *(short *)(iVar12 + 0x340) = (short)((uint)*(undefined4 *)(iVar4 + 0x28) >> 0x10);
    if (1 < bVar2) {
      uVar11 = 0;
      puVar5 = (undefined2 *)(iVar12 + 0x340);
      do {
        iVar10 = uVar11 + 0x40;
        uVar11 = uVar11 + 1;
        puVar5 = puVar5 + 1;
        *puVar5 = (short)((uint)*(undefined4 *)
                                 (*(int *)(*(int *)(param_1 + 4) + 0x10) + iVar10 * 4 + 4) >> 0x10);
      } while (uVar11 != (byte)(bVar2 - 1));
    }
    uVar11 = *(uint *)(iVar4 + 0x24);
    *(short *)(iVar12 + 0x33e) = (short)uVar11;
    if ((bVar1 & 1) != 0) {
      if (bVar3) {
        iVar10 = 0x314;
      }
      else {
        iVar10 = 0x8f;
      }
      uVar11 = uVar11 & 0xffff;
      uVar15 = iVar10 + (uint)*(byte *)(iVar12 + 0x366) * 2;
      if (uVar15 <= uVar11) {
        uVar11 = uVar15;
      }
      *(short *)(iVar12 + 0x33e) = (short)uVar11;
      *(uint *)(iVar4 + 0x24) = uVar11;
      uVar6 = *(ushort *)(iVar12 + 0x340);
      if (0x1f < uVar6) {
        uVar6 = 0x20;
      }
      *(uint *)(iVar4 + 0x28) = CONCAT22(uVar6,*(undefined2 *)(iVar12 + 0x33e));
    }
    iVar10 = FUN_0e08d4a8(param_1,0,0,0x40,0);
    if ((iVar10 != 0) || (iVar10 = FUN_0e08d4a8(param_1,0x80,0,0x40,0), iVar10 != 0)) {
      return -5;
    }
    *(undefined4 *)(iVar4 + 0x18) = DAT_0e08eaa4;
    iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x18);
    if (((iVar4 == 0) || (pcVar7 = *(code **)(iVar4 + 8), pcVar7 == (code *)0x0)) ||
       (iVar4 = (*pcVar7)(param_1), iVar4 == 0)) {
      *(uint *)(iVar14 + 8) = *(uint *)(iVar14 + 8) | 1;
      (**(code **)(iVar13 + 0x20))(param_1);
      *(uint *)(iVar14 + 0x804) = *(uint *)(iVar14 + 0x804) & 0xfffffffd;
      return 0;
    }
  }
  return iVar4;
}


