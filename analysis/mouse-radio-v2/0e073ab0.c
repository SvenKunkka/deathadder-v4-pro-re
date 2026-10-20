/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e073ab0. Types and names are inferred; NOT original source. */

void FUN_0e073ab0(int param_1,byte param_2)

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
  
  pcVar24 = DAT_0e073d64;
  uVar27 = 0;
  cVar26 = *(char *)(DAT_0e073d5c + 0xe);
  uVar23 = (uint)param_2;
  *DAT_0e073d60 = 0;
  puVar9 = DAT_0e073d84;
  puVar8 = DAT_0e073d6c;
  pcVar7 = DAT_0e073d68;
  cVar1 = *pcVar24;
  if (cVar26 == '\x01') {
    if (uVar23 == 0) {
      if (cVar1 == '\x03') {
        uVar27 = 1;
        goto LAB_0e073b6a;
      }
      uVar23 = 2;
      uVar27 = 1;
    }
    else {
      if (uVar23 != 1) goto LAB_0e073aca;
      if (cVar1 == '\x03') goto LAB_0e073b6a;
      uVar23 = 1;
    }
  }
  else {
LAB_0e073aca:
    uVar27 = uVar23;
    if (cVar1 == '\x03') {
      if (4 < uVar23) {
        if (uVar23 != 5) {
          return;
        }
        if (*(char *)(DAT_0e073d74 + 0x50) != '`') {
          return;
        }
        if (*DAT_0e073d88 != '\0') {
          return;
        }
        if (param_1 != 0) {
          return;
        }
        if (*DAT_0e073d8c == '\0') {
          if ((*DAT_0e073d90 == '\0') && (*DAT_0e073d94 == '\0')) {
            return;
          }
          if (*DAT_0e073d98 != '\0') {
            return;
          }
        }
        uVar20 = *DAT_0e073d84;
        *DAT_0e073d9c = 0x5204;
        *puVar9 = uVar20 | 0x40;
        *DAT_0e073da0 = 5;
        return;
      }
LAB_0e073b6a:
      uVar20 = (ushort)(1 << (*(byte *)(DAT_0e073d7c + uVar27 * 0x10 + 6) - 1 & 0xff));
      if (param_1 == 1) {
        *DAT_0e0740e4 = uVar20 | *DAT_0e0740e4;
      }
      else {
        *DAT_0e073d80 = *DAT_0e073d80 & ~uVar20;
      }
      *DAT_0e073d84 = *DAT_0e073d84 | 1;
      return;
    }
    uVar23 = 1 << uVar23;
  }
  uVar20 = *DAT_0e073d6c;
  uVar22 = (ushort)uVar23;
  if (*DAT_0e073d68 == '\0') {
    if (param_1 == 1) {
      uVar25 = *DAT_0e073d70 | uVar22;
    }
    else {
      uVar25 = *DAT_0e073d70 & ~uVar22;
    }
LAB_0e073af0:
    iVar32 = 0;
    *DAT_0e073d70 = uVar25;
  }
  else {
    if (param_1 == 1) {
      *DAT_0e073d78 = *DAT_0e073d78 | uVar22;
    }
    else {
      *DAT_0e073d78 = ~uVar22 & *DAT_0e073d78;
      if (((uVar20 != 0) && (param_1 == 0)) && (((int)(uint)*DAT_0e073d70 >> uVar27 & 1U) != 0)) {
        uVar25 = ~uVar22 & *DAT_0e073d70;
        goto LAB_0e073af0;
      }
    }
    iVar32 = 1;
  }
  puVar19 = DAT_0e0742d4;
  iVar18 = DAT_0e0742b4;
  puVar17 = DAT_0e0742b0;
  puVar30 = DAT_0e0742a4;
  iVar16 = DAT_0e0740fc;
  puVar28 = DAT_0e0740f4;
  iVar34 = DAT_0e0740f0;
  puVar15 = DAT_0e0740e8;
  puVar14 = DAT_0e0740e4;
  pbVar13 = DAT_0e0740d8;
  puVar12 = DAT_0e073dbc;
  puVar11 = DAT_0e073db8;
  puVar10 = DAT_0e073da4;
  puVar9 = DAT_0e073d84;
  iVar29 = DAT_0e073d74;
  iVar33 = uVar27 * 0x10;
  if ((*(char *)(DAT_0e073d74 + iVar33) == '`') && (*DAT_0e073d88 != '\0')) {
    return;
  }
  switch(*(undefined1 *)(DAT_0e073d74 + iVar33 + iVar32 + 2)) {
  case 1:
    cVar26 = *(char *)(DAT_0e073d74 + iVar33 + iVar32 + 6);
    if (param_1 == 1) {
      if (cVar26 == '\t') {
        if (*DAT_0e0742ac != '\0') {
          uVar20 = *DAT_0e0742b0;
          uVar22 = DAT_0e0742b0[1];
          if (0xaf63 < uVar20) {
            uVar20 = 0xaf64;
          }
          if (0xaf63 < uVar22) {
            uVar22 = 0xaf64;
          }
          uVar20 = uVar20 + 100;
          uVar22 = uVar22 + 100;
          iVar32 = (uint)*(byte *)(DAT_0e0742b4 + 3) * 0xf4 + DAT_0e0742b4;
          *DAT_0e0742b0 = uVar20;
          puVar17[1] = uVar22;
          *(ushort *)(iVar32 + 0x56) = uVar20;
          *(ushort *)(iVar32 + 0x58) = uVar22;
LAB_0e0741a8:
          thunk_FUN_0e0805b8(uVar20,uVar22);
          thunk_FUN_0e07d638(8,*(undefined1 *)(iVar18 + 3));
          return;
        }
        *DAT_0e0742b8 = *DAT_0e0742b8 + '\x01';
      }
      else if (cVar26 == '\n') {
        if (*DAT_0e0742ac != '\0') {
          uVar20 = *DAT_0e0742b0;
          uVar22 = DAT_0e0742b0[1];
          if (uVar20 < 100) {
            uVar20 = 100;
          }
          if (uVar22 < 100) {
            uVar22 = 100;
          }
          uVar20 = uVar20 - 100;
          uVar22 = uVar22 - 100;
          iVar32 = (uint)*(byte *)(DAT_0e0742b4 + 3) * 0xf4 + DAT_0e0742b4;
          *DAT_0e0742b0 = uVar20;
          puVar17[1] = uVar22;
          *(ushort *)(iVar32 + 0x56) = uVar20;
          *(ushort *)(iVar32 + 0x58) = uVar22;
          goto LAB_0e0741a8;
        }
        *DAT_0e0742b8 = *DAT_0e0742b8 + -1;
      }
      else {
        uVar20 = *DAT_0e0740e8;
        *DAT_0e0740e4 = (ushort)(1 << (uint)(byte)(cVar26 - 1)) | *DAT_0e0740e4;
        *puVar15 = uVar20 | 1;
      }
    }
    else if ((cVar26 != '\t') && (*(char *)(DAT_0e0740e0 + iVar33 + iVar32 + 0x97) != '\n')) {
      uVar20 = *DAT_0e0740e4;
      *DAT_0e0740e8 = *DAT_0e0740e8 | 1;
      *puVar14 = uVar20 & ~(ushort)(1 << (uint)(byte)(cVar26 - 1));
    }
    break;
  case 2:
    uVar23 = (uint)*(byte *)(DAT_0e073d74 + iVar33 + iVar32 + 6);
    uVar31 = (uint)*DAT_0e0740d8;
    uVar27 = 0;
    if (param_1 == 1) {
      bVar6 = false;
      pcVar24 = DAT_0e0740dc;
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
      puVar8 = DAT_0e0742a8;
      iVar34 = 2;
      pcVar24 = DAT_0e0740f8;
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
      pcVar24 = DAT_0e0740dc;
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
      puVar8 = DAT_0e0742a8;
      iVar34 = 2;
      pcVar24 = DAT_0e0742a0;
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
    switch(*(undefined1 *)(DAT_0e073d74 + iVar33 + iVar32 + 6)) {
    case 1:
      if (param_1 == 1) {
        iVar29 = *(byte *)(DAT_0e0740fc + 6) + 1;
        iVar32 = *(byte *)(DAT_0e0740fc + 5) - 1;
        if (iVar29 <= iVar32) {
          iVar32 = iVar29;
        }
        *(char *)(DAT_0e0740fc + 6) = (char)iVar32;
        thunk_FUN_0e0804b4();
        thunk_FUN_0e07f250();
        return;
      }
      break;
    case 2:
      if (param_1 == 1) {
        cVar26 = *(char *)(DAT_0e0740fc + 6);
        if (cVar26 == '\0') {
          cVar26 = '\x01';
        }
        *(char *)(DAT_0e0740fc + 6) = cVar26 + -1;
        thunk_FUN_0e0804b4();
        thunk_FUN_0e07f250();
        return;
      }
      break;
    case 3:
      if (param_1 == 1) {
        *(char *)(DAT_0e0740fc + 6) = *(char *)(DAT_0e073d74 + iVar33 + iVar32 + 8) + -1;
        thunk_FUN_0e07f250();
        if (*(byte *)(iVar16 + 6) < 5) {
          thunk_FUN_0e0804b4();
          return;
        }
      }
      break;
    case 4:
      if (param_1 == 1) {
        *DAT_0e0742ac = '\x01';
      }
      else {
        *DAT_0e074108 = 0;
      }
      break;
    case 5:
      if (param_1 != 1) {
        uVar3 = DAT_0e074100[1];
        uVar4 = *DAT_0e074100;
        *DAT_0e074104 = 0;
        thunk_FUN_0e0805b8(uVar4,uVar3);
        thunk_FUN_0e080570(2,0);
        return;
      }
      iVar32 = DAT_0e073d74 + iVar33 + iVar32;
      uVar21 = *(undefined1 *)(iVar32 + 0xc);
      uVar2 = *(undefined1 *)(iVar32 + 0xe);
      uVar3 = CONCAT11(*(undefined1 *)(iVar32 + 8),*(undefined1 *)(iVar32 + 10));
      *DAT_0e0742d0 = 1;
      puVar19[1] = CONCAT11(uVar21,uVar2);
      *puVar19 = uVar3;
      thunk_FUN_0e0805e0(uVar3);
      thunk_FUN_0e080570(2,0);
      return;
    case 6:
      if (*(char *)(DAT_0e073d74 + iVar33) == '`') {
        if (param_1 != 0) {
          return;
        }
        if (*DAT_0e0742bc == '\0') {
          if ((*DAT_0e0742c0 == '\0') && (*DAT_0e0742c4 == '\0')) {
            return;
          }
          if (*DAT_0e0742c8 != '\0') {
            return;
          }
        }
        uVar27 = *(byte *)(DAT_0e0742cc + 6) + 1;
        uVar21 = 0;
        if (uVar27 < *(byte *)(DAT_0e0742cc + 5)) {
          uVar21 = (undefined1)uVar27;
        }
        *(undefined1 *)(DAT_0e0742cc + 6) = uVar21;
        thunk_FUN_0e0804b4();
        thunk_FUN_0e07f250();
        return;
      }
      if (param_1 != 1) {
        return;
      }
      uVar27 = *(byte *)(DAT_0e0740fc + 6) + 1;
      if (*(byte *)(DAT_0e0740fc + 5) <= uVar27) {
        uVar21 = 0;
        goto LAB_0e074010;
      }
      goto LAB_0e07400e;
    case 7:
      if (param_1 != 1) {
        return;
      }
      uVar27 = (uint)*(byte *)(DAT_0e0740fc + 6);
      if (uVar27 == 0) {
        uVar27 = (uint)*(byte *)(DAT_0e0740fc + 5);
      }
      uVar27 = uVar27 - 1;
LAB_0e07400e:
      uVar21 = (undefined1)uVar27;
LAB_0e074010:
      *(undefined1 *)(DAT_0e0740fc + 6) = uVar21;
      thunk_FUN_0e0804b4();
      thunk_FUN_0e07f250();
      return;
    }
    break;
  case 9:
    if (param_1 != 1) {
      iVar29 = 0;
    }
    else {
      iVar33 = iVar33 + DAT_0e073d74;
    }
    uVar21 = (undefined1)iVar29;
    uVar20 = *DAT_0e073d84;
    if (param_1 == 1) {
      uVar21 = *(undefined1 *)(iVar33 + iVar32 + 6);
    }
    DAT_0e073dbc[1] = uVar21;
    *puVar9 = uVar20 | 0x20;
    *puVar12 = 3;
    break;
  case 10:
    if (param_1 == 1) {
      iVar32 = iVar33 + DAT_0e073d74 + iVar32;
      uVar21 = *(undefined1 *)(iVar32 + 6);
      *(undefined1 *)((int)DAT_0e0740f4 + 1) = *(undefined1 *)(iVar32 + 8);
      *(undefined1 *)puVar28 = 2;
    }
    else {
      uVar21 = 0;
      *DAT_0e073db8 = 2;
      puVar28 = puVar11;
    }
    puVar8 = DAT_0e073d84;
    *(undefined1 *)(puVar28 + 1) = uVar21;
    *puVar8 = *puVar8 | 0x10;
    break;
  case 0xb:
    if (param_1 == 1) {
      *DAT_0e073dac = (char)(1 << (*(byte *)(iVar33 + DAT_0e073d74 + iVar32 + 6) - 1 & 0xff));
      puVar10 = DAT_0e073db0;
      *DAT_0e073db4 = 1;
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
      puVar8 = DAT_0e073d78;
      if (uVar27 == 0) {
        uVar27 = 0;
        do {
          if (((int)(uint)*puVar8 >> (uVar27 & 0xff)) << 0x1f < 0) {
            FUN_0e073ab0(0,uVar27);
          }
          uVar27 = uVar27 + 1;
        } while (uVar27 != 8);
        *puVar8 = 0;
        *pcVar7 = '\0';
      }
    }
    break;
  case 0xd:
    uVar31 = (uint)*(byte *)(DAT_0e073d74 + iVar33 + iVar32 + 6);
    uVar23 = 0;
    if (param_1 == 1) {
      iVar34 = uVar27 + 0x18;
      *DAT_0e073da4 = (char)uVar27;
      pcVar24 = DAT_0e0740ec;
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
      pcVar24 = DAT_0e073da8;
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
    uVar23 = (uint)*(byte *)(DAT_0e073d74 + iVar33 + iVar32 + 6);
    if (param_1 == 1) {
      *(char *)(DAT_0e0740f0 + 0x4b) = (char)uVar27;
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
        DAT_0e0742a4[uVar27 + 0x8e] = 0;
      }
      else {
        DAT_0e073da4[0x8d] = DAT_0e073da4[0x8d] & ~(byte)(1 << (uVar23 - 1 & 0xff));
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


