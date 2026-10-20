/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0dfab0. Types and names are inferred; NOT original source. */

void FUN_1c0dfab0(int param_1,byte param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  byte bVar5;
  bool bVar6;
  char *pcVar7;
  ushort *puVar8;
  ushort *puVar9;
  undefined1 *puVar10;
  undefined2 *puVar11;
  undefined1 *puVar12;
  byte *pbVar13;
  ushort *puVar14;
  ushort *puVar15;
  int iVar16;
  ushort *puVar17;
  int iVar18;
  undefined2 *puVar19;
  ushort uVar20;
  undefined1 uVar21;
  ushort uVar22;
  uint uVar23;
  char *pcVar24;
  ushort uVar25;
  char cVar26;
  uint uVar27;
  undefined2 *puVar28;
  int iVar29;
  undefined1 *puVar30;
  uint uVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  
  pcVar24 = DAT_1c0dfd64;
  uVar27 = 0;
  cVar26 = *(char *)(DAT_1c0dfd5c + 0xe);
  uVar23 = (uint)param_2;
  *DAT_1c0dfd60 = 0;
  puVar9 = DAT_1c0dfd84;
  puVar8 = DAT_1c0dfd6c;
  pcVar7 = DAT_1c0dfd68;
  cVar1 = *pcVar24;
  if (cVar26 == '\x01') {
    if (uVar23 == 0) {
      if (cVar1 == '\x03') {
        uVar27 = 1;
        goto LAB_1c0dfb6a;
      }
      uVar23 = 2;
      uVar27 = 1;
    }
    else {
      if (uVar23 != 1) goto LAB_1c0dfaca;
      if (cVar1 == '\x03') goto LAB_1c0dfb6a;
      uVar23 = 1;
    }
  }
  else {
LAB_1c0dfaca:
    uVar27 = uVar23;
    if (cVar1 == '\x03') {
      if (4 < uVar23) {
        if (uVar23 != 5) {
          return;
        }
        if (*(char *)(DAT_1c0dfd74 + 0x50) != '`') {
          return;
        }
        if (*DAT_1c0dfd88 != '\0') {
          return;
        }
        if (param_1 != 0) {
          return;
        }
        if (*DAT_1c0dfd8c == '\0') {
          if ((*DAT_1c0dfd90 == '\0') && (*DAT_1c0dfd94 == '\0')) {
            return;
          }
          if (*DAT_1c0dfd98 != '\0') {
            return;
          }
        }
        uVar20 = *DAT_1c0dfd84;
        *DAT_1c0dfd9c = 0x5204;
        *puVar9 = uVar20 | 0x40;
        *DAT_1c0dfda0 = 5;
        return;
      }
LAB_1c0dfb6a:
      uVar20 = (ushort)(1 << (*(byte *)(DAT_1c0dfd7c + uVar27 * 0x10 + 6) - 1 & 0xff));
      if (param_1 == 1) {
        *DAT_1c0e00e4 = uVar20 | *DAT_1c0e00e4;
      }
      else {
        *DAT_1c0dfd80 = *DAT_1c0dfd80 & ~uVar20;
      }
      *DAT_1c0dfd84 = *DAT_1c0dfd84 | 1;
      return;
    }
    uVar23 = 1 << uVar23;
  }
  uVar20 = *DAT_1c0dfd6c;
  uVar22 = (ushort)uVar23;
  if (*DAT_1c0dfd68 == '\0') {
    if (param_1 == 1) {
      uVar25 = *DAT_1c0dfd70 | uVar22;
    }
    else {
      uVar25 = *DAT_1c0dfd70 & ~uVar22;
    }
LAB_1c0dfaf0:
    iVar32 = 0;
    *DAT_1c0dfd70 = uVar25;
  }
  else {
    if (param_1 == 1) {
      *DAT_1c0dfd78 = *DAT_1c0dfd78 | uVar22;
    }
    else {
      *DAT_1c0dfd78 = ~uVar22 & *DAT_1c0dfd78;
      if (((uVar20 != 0) && (param_1 == 0)) && (((int)(uint)*DAT_1c0dfd70 >> uVar27 & 1U) != 0)) {
        uVar25 = ~uVar22 & *DAT_1c0dfd70;
        goto LAB_1c0dfaf0;
      }
    }
    iVar32 = 1;
  }
  puVar19 = DAT_1c0e02d4;
  iVar18 = DAT_1c0e02b4;
  puVar17 = DAT_1c0e02b0;
  puVar30 = DAT_1c0e02a4;
  iVar16 = DAT_1c0e00fc;
  puVar28 = DAT_1c0e00f4;
  iVar34 = DAT_1c0e00f0;
  puVar15 = DAT_1c0e00e8;
  puVar14 = DAT_1c0e00e4;
  pbVar13 = DAT_1c0e00d8;
  puVar12 = DAT_1c0dfdbc;
  puVar11 = DAT_1c0dfdb8;
  puVar10 = DAT_1c0dfda4;
  puVar9 = DAT_1c0dfd84;
  iVar29 = DAT_1c0dfd74;
  iVar33 = uVar27 * 0x10;
  if ((*(char *)(DAT_1c0dfd74 + iVar33) == '`') && (*DAT_1c0dfd88 != '\0')) {
    return;
  }
  switch(*(undefined1 *)(DAT_1c0dfd74 + iVar33 + iVar32 + 2)) {
  case 1:
    cVar26 = *(char *)(DAT_1c0dfd74 + iVar33 + iVar32 + 6);
    if (param_1 == 1) {
      if (cVar26 == '\t') {
        if (*DAT_1c0e02ac != '\0') {
          uVar20 = *DAT_1c0e02b0;
          uVar22 = DAT_1c0e02b0[1];
          if (0xaf63 < uVar20) {
            uVar20 = 0xaf64;
          }
          if (0xaf63 < uVar22) {
            uVar22 = 0xaf64;
          }
          uVar20 = uVar20 + 100;
          uVar22 = uVar22 + 100;
          iVar32 = (uint)*(byte *)(DAT_1c0e02b4 + 3) * 0xf4 + DAT_1c0e02b4;
          *DAT_1c0e02b0 = uVar20;
          puVar17[1] = uVar22;
          *(ushort *)(iVar32 + 0x56) = uVar20;
          *(ushort *)(iVar32 + 0x58) = uVar22;
LAB_1c0e01a8:
          thunk_EXT_FUN_0e0805b8(uVar20,uVar22);
          thunk_EXT_FUN_0e07d638(8,*(undefined1 *)(iVar18 + 3));
          return;
        }
        *DAT_1c0e02b8 = *DAT_1c0e02b8 + '\x01';
      }
      else if (cVar26 == '\n') {
        if (*DAT_1c0e02ac != '\0') {
          uVar20 = *DAT_1c0e02b0;
          uVar22 = DAT_1c0e02b0[1];
          if (uVar20 < 100) {
            uVar20 = 100;
          }
          if (uVar22 < 100) {
            uVar22 = 100;
          }
          uVar20 = uVar20 - 100;
          uVar22 = uVar22 - 100;
          iVar32 = (uint)*(byte *)(DAT_1c0e02b4 + 3) * 0xf4 + DAT_1c0e02b4;
          *DAT_1c0e02b0 = uVar20;
          puVar17[1] = uVar22;
          *(ushort *)(iVar32 + 0x56) = uVar20;
          *(ushort *)(iVar32 + 0x58) = uVar22;
          goto LAB_1c0e01a8;
        }
        *DAT_1c0e02b8 = *DAT_1c0e02b8 + -1;
      }
      else {
        uVar20 = *DAT_1c0e00e8;
        *DAT_1c0e00e4 = (ushort)(1 << (uint)(byte)(cVar26 - 1)) | *DAT_1c0e00e4;
        *puVar15 = uVar20 | 1;
      }
    }
    else if ((cVar26 != '\t') && (*(char *)(DAT_1c0e00e0 + iVar33 + iVar32 + 0x97) != '\n')) {
      uVar20 = *DAT_1c0e00e4;
      *DAT_1c0e00e8 = *DAT_1c0e00e8 | 1;
      *puVar14 = uVar20 & ~(ushort)(1 << (uint)(byte)(cVar26 - 1));
    }
    break;
  case 2:
    uVar23 = (uint)*(byte *)(DAT_1c0dfd74 + iVar33 + iVar32 + 6);
    uVar31 = (uint)*DAT_1c0e00d8;
    uVar27 = 0;
    if (param_1 == 1) {
      bVar6 = false;
      pcVar24 = DAT_1c0e00dc;
      do {
        if (((int)uVar23 >> (uVar27 & 0xff)) << 0x1f < 0) {
          bVar6 = true;
          *pcVar24 = *pcVar24 + '\x01';
          uVar31 = 1 << (uVar27 & 0xff) & 0xffU | uVar31;
        }
        uVar27 = uVar27 + 1;
        pcVar24 = pcVar24 + 1;
      } while (uVar27 != 8);
      if (bVar6) {
        *pbVar13 = (byte)uVar31;
      }
      puVar8 = DAT_1c0e02a8;
      iVar34 = 2;
      pcVar24 = DAT_1c0e00f8;
      do {
        pcVar24 = pcVar24 + 1;
        if (*pcVar24 == '\0') {
          pbVar13[iVar34] = *(byte *)(iVar29 + iVar33 + iVar32 + 8);
          *puVar8 = *puVar8 | 8;
          return;
        }
        iVar34 = iVar34 + 1;
      } while (iVar34 != 8);
    }
    else {
      bVar6 = false;
      pcVar24 = DAT_1c0e00dc;
      do {
        if (((int)uVar23 >> (uVar27 & 0xff)) << 0x1f < 0) {
          cVar26 = *pcVar24;
          if ((cVar26 == '\0') || (*pcVar24 = cVar26 + -1, cVar26 == '\x01')) {
            bVar6 = true;
            uVar31 = uVar31 & ~(1 << (uVar27 & 0xff));
          }
        }
        uVar27 = uVar27 + 1;
        pcVar24 = pcVar24 + 1;
      } while (uVar27 != 8);
      if (bVar6) {
        *pbVar13 = (byte)uVar31;
      }
      puVar8 = DAT_1c0e02a8;
      iVar34 = 2;
      pcVar24 = DAT_1c0e02a0;
      do {
        pcVar24 = pcVar24 + 1;
        if (*pcVar24 == *(char *)(iVar33 + iVar29 + iVar32 + 8)) {
          pbVar13[iVar34] = 0;
          *puVar8 = *puVar8 | 8;
          return;
        }
        iVar34 = iVar34 + 1;
      } while (iVar34 != 8);
    }
    break;
  case 6:
    switch(*(undefined1 *)(DAT_1c0dfd74 + iVar33 + iVar32 + 6)) {
    case 1:
      if (param_1 == 1) {
        iVar29 = *(byte *)(DAT_1c0e00fc + 6) + 1;
        iVar32 = *(byte *)(DAT_1c0e00fc + 5) - 1;
        if (iVar29 <= iVar32) {
          iVar32 = iVar29;
        }
        *(char *)(DAT_1c0e00fc + 6) = (char)iVar32;
        thunk_EXT_FUN_0e0804b4();
        thunk_EXT_FUN_0e07f250();
        return;
      }
      break;
    case 2:
      if (param_1 == 1) {
        cVar26 = *(char *)(DAT_1c0e00fc + 6);
        if (cVar26 == '\0') {
          cVar26 = '\x01';
        }
        *(char *)(DAT_1c0e00fc + 6) = cVar26 + -1;
        thunk_EXT_FUN_0e0804b4();
        thunk_EXT_FUN_0e07f250();
        return;
      }
      break;
    case 3:
      if (param_1 == 1) {
        *(char *)(DAT_1c0e00fc + 6) = *(char *)(DAT_1c0dfd74 + iVar33 + iVar32 + 8) + -1;
        thunk_EXT_FUN_0e07f250();
        if (*(byte *)(iVar16 + 6) < 5) {
          thunk_EXT_FUN_0e0804b4();
          return;
        }
      }
      break;
    case 4:
      if (param_1 == 1) {
        *DAT_1c0e02ac = '\x01';
      }
      else {
        *DAT_1c0e0108 = 0;
      }
      break;
    case 5:
      if (param_1 != 1) {
        uVar3 = DAT_1c0e0100[1];
        uVar4 = *DAT_1c0e0100;
        *DAT_1c0e0104 = 0;
        thunk_EXT_FUN_0e0805b8(uVar4,uVar3);
        thunk_EXT_FUN_0e080570(2,0);
        return;
      }
      iVar32 = DAT_1c0dfd74 + iVar33 + iVar32;
      uVar21 = *(undefined1 *)(iVar32 + 0xc);
      uVar2 = *(undefined1 *)(iVar32 + 0xe);
      uVar3 = CONCAT11(*(undefined1 *)(iVar32 + 8),*(undefined1 *)(iVar32 + 10));
      *DAT_1c0e02d0 = 1;
      puVar19[1] = CONCAT11(uVar21,uVar2);
      *puVar19 = uVar3;
      thunk_EXT_FUN_0e0805e0(uVar3);
      thunk_EXT_FUN_0e080570(2,0);
      return;
    case 6:
      if (*(char *)(DAT_1c0dfd74 + iVar33) == '`') {
        if (param_1 != 0) {
          return;
        }
        if (*DAT_1c0e02bc == '\0') {
          if ((*DAT_1c0e02c0 == '\0') && (*DAT_1c0e02c4 == '\0')) {
            return;
          }
          if (*DAT_1c0e02c8 != '\0') {
            return;
          }
        }
        uVar27 = *(byte *)(DAT_1c0e02cc + 6) + 1;
        uVar21 = 0;
        if (uVar27 < *(byte *)(DAT_1c0e02cc + 5)) {
          uVar21 = (undefined1)uVar27;
        }
        *(undefined1 *)(DAT_1c0e02cc + 6) = uVar21;
        thunk_EXT_FUN_0e0804b4();
        thunk_EXT_FUN_0e07f250();
        return;
      }
      if (param_1 != 1) {
        return;
      }
      uVar27 = *(byte *)(DAT_1c0e00fc + 6) + 1;
      if (*(byte *)(DAT_1c0e00fc + 5) <= uVar27) {
        uVar21 = 0;
        goto LAB_1c0e0010;
      }
      goto LAB_1c0e000e;
    case 7:
      if (param_1 != 1) {
        return;
      }
      uVar27 = (uint)*(byte *)(DAT_1c0e00fc + 6);
      if (uVar27 == 0) {
        uVar27 = (uint)*(byte *)(DAT_1c0e00fc + 5);
      }
      uVar27 = uVar27 - 1;
LAB_1c0e000e:
      uVar21 = (undefined1)uVar27;
LAB_1c0e0010:
      *(undefined1 *)(DAT_1c0e00fc + 6) = uVar21;
      thunk_EXT_FUN_0e0804b4();
      thunk_EXT_FUN_0e07f250();
      return;
    }
    break;
  case 9:
    if (param_1 != 1) {
      iVar29 = 0;
    }
    else {
      iVar33 = iVar33 + DAT_1c0dfd74;
    }
    uVar21 = (undefined1)iVar29;
    uVar20 = *DAT_1c0dfd84;
    if (param_1 == 1) {
      uVar21 = *(undefined1 *)(iVar33 + iVar32 + 6);
    }
    DAT_1c0dfdbc[1] = uVar21;
    *puVar9 = uVar20 | 0x20;
    *puVar12 = 3;
    break;
  case 10:
    if (param_1 == 1) {
      iVar32 = iVar33 + DAT_1c0dfd74 + iVar32;
      uVar21 = *(undefined1 *)(iVar32 + 6);
      *(undefined1 *)((int)DAT_1c0e00f4 + 1) = *(undefined1 *)(iVar32 + 8);
      *(undefined1 *)puVar28 = 2;
    }
    else {
      uVar21 = 0;
      *DAT_1c0dfdb8 = 2;
      puVar28 = puVar11;
    }
    puVar8 = DAT_1c0dfd84;
    *(undefined1 *)(puVar28 + 1) = uVar21;
    *puVar8 = *puVar8 | 0x10;
    break;
  case 0xb:
    if (param_1 == 1) {
      *DAT_1c0dfdac = (char)(1 << (*(byte *)(iVar33 + DAT_1c0dfd74 + iVar32 + 6) - 1 & 0xff));
      puVar10 = DAT_1c0dfdb0;
      *DAT_1c0dfdb4 = 1;
      *puVar10 = 0;
    }
    break;
  case 0xc:
    if (param_1 == 1) {
      *puVar8 = uVar20 | uVar22;
      *pcVar7 = '\x01';
    }
    else {
      uVar27 = (uint)uVar20 & ~uVar23;
      *puVar8 = (ushort)uVar27;
      puVar8 = DAT_1c0dfd78;
      if (uVar27 == 0) {
        uVar27 = 0;
        do {
          if (((int)(uint)*puVar8 >> (uVar27 & 0xff)) << 0x1f < 0) {
            FUN_1c0dfab0(0,uVar27);
          }
          uVar27 = uVar27 + 1;
        } while (uVar27 != 8);
        *puVar8 = 0;
        *pcVar7 = '\0';
      }
    }
    break;
  case 0xd:
    uVar31 = (uint)*(byte *)(DAT_1c0dfd74 + iVar33 + iVar32 + 6);
    uVar23 = 0;
    if (param_1 == 1) {
      iVar34 = uVar27 + 0x18;
      *DAT_1c0dfda4 = (char)uVar27;
      pcVar24 = DAT_1c0e00ec;
      puVar10[iVar34 * 2 + 2] = 0;
      do {
        if (((int)uVar31 >> (uVar23 & 0xff)) << 0x1f < 0) {
          bVar5 = puVar10[iVar34 * 2 + 2];
          *pcVar24 = *pcVar24 + '\x01';
          puVar10[iVar34 * 2 + 2] = (byte)(1 << (uVar23 & 0xff)) | bVar5;
        }
        uVar23 = uVar23 + 1;
        pcVar24 = pcVar24 + 1;
      } while (uVar23 != 8);
      iVar32 = iVar33 + iVar29 + iVar32;
      uVar21 = *(undefined1 *)(iVar32 + 8);
      uVar3 = CONCAT11(*(undefined1 *)(iVar32 + 10),*(undefined1 *)(iVar32 + 0xc));
      *(undefined2 *)(puVar10 + uVar27 * 2 + 0x11) = uVar3;
      *(undefined2 *)(puVar10 + uVar27 * 2 + 0x21) = uVar3;
      puVar10[uVar27 * 2 + 0x33] = uVar21;
      puVar10[uVar27 + 9] = 1;
    }
    else {
      pcVar24 = DAT_1c0dfda8;
      do {
        if (((int)uVar31 >> (uVar23 & 0xff)) << 0x1f < 0) {
          cVar26 = *pcVar24;
          if ((cVar26 == '\0') || (*pcVar24 = cVar26 + -1, cVar26 == '\x01')) {
            puVar10[(uVar27 + 0x18) * 2 + 2] =
                 puVar10[(uVar27 + 0x18) * 2 + 2] & ~(byte)(1 << (uVar23 & 0xff));
          }
        }
        uVar23 = uVar23 + 1;
        pcVar24 = pcVar24 + 1;
      } while (uVar23 != 8);
      puVar10[uVar27 * 2 + 0x33] = 0;
      puVar10[(uVar27 + 8) * 2 + 1] = 0;
      puVar10[(uVar27 + 8) * 2 + 2] = 0;
      puVar10[uVar27 + 9] = 3;
    }
    break;
  case 0xe:
    uVar23 = (uint)*(byte *)(DAT_1c0dfd74 + iVar33 + iVar32 + 6);
    if (param_1 == 1) {
      *(char *)(DAT_1c0e00f0 + 0x4b) = (char)uVar27;
      if (uVar23 == 9) {
        *(undefined1 *)(iVar34 + uVar27 + 0x8e) = 1;
      }
      else if (uVar23 == 10) {
        *(undefined1 *)(iVar34 + uVar27 + 0x8e) = 0xff;
      }
      else {
        *(byte *)(iVar34 + 0x8d) = (byte)(1 << (uVar23 - 1 & 0xff)) | *(byte *)(iVar34 + 0x8d);
      }
      iVar32 = iVar29 + iVar33 + iVar32;
      iVar29 = iVar34 + uVar27 * 2;
      uVar3 = CONCAT11(*(undefined1 *)(iVar32 + 8),*(undefined1 *)(iVar32 + 10));
      cVar26 = *(char *)(iVar34 + 0x7c);
      *(undefined2 *)(iVar29 + 0x5c) = uVar3;
      *(char *)(iVar34 + 0x7c) = cVar26 + '\x01';
      *(undefined2 *)(iVar29 + 0x6c) = uVar3;
      *(undefined1 *)(iVar34 + uVar27 + 0x54) = 1;
    }
    else {
      if (uVar23 - 9 < 2) {
        DAT_1c0e02a4[uVar27 + 0x8e] = 0;
      }
      else {
        DAT_1c0dfda4[0x8d] = DAT_1c0dfda4[0x8d] & ~(byte)(1 << (uVar23 - 1 & 0xff));
        puVar30 = puVar10;
      }
      cVar26 = puVar30[0x7c];
      puVar30[(uVar27 + 0x2c) * 2 + 4] = 0;
      puVar30[(uVar27 + 0x2c) * 2 + 5] = 0;
      if ((cVar26 == '\0') || (puVar30[0x7c] = cVar26 + -1, cVar26 == '\x01')) {
        puVar30[uVar27 + 0x54] = 3;
      }
    }
  }
  return;
}


