/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078cac. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0e08567c(void)

{
  char cVar1;
  short sVar2;
  longlong lVar3;
  ushort uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  byte bVar9;
  uint uVar10;
  code *pcVar11;
  char cVar12;
  char cVar13;
  
  cVar1 = (&DAT_230049e0)[(uint)DAT_23000e09 * 0xe];
  if (cVar1 == '\0') {
    return;
  }
  if (DAT_23006c2a == '\f') {
    DAT_23006c14 = 0;
    DAT_23006c10 = 0;
    if ((DAT_230077be != '\0') && (DAT_23006bee != '\0')) {
      FUN_0e084fa8(1);
      DAT_230077be = '\0';
    }
LAB_0e0856b4:
    if (9 < DAT_23006c24) {
      bVar9 = DAT_23006c25 + 1;
      _DAT_23006c24 = (ushort)bVar9 << 8;
      if ((bVar9 < 5) && (DAT_23006c29 == DAT_23000e08)) {
        DAT_23006c1c = 1;
        DAT_23006c20 = 0;
        DAT_23006c2d = 0;
        return;
      }
      if (DAT_230077c0 != '\0') {
        _DAT_23006c18 = 0;
        DAT_23006c1c = 500;
        DAT_23006c20 = 0;
        _DAT_23006c24 = 0;
        DAT_23006c2a = 0;
        DAT_23006c2d = 0;
        return;
      }
      _DAT_23006c18 = CONCAT11(DAT_23006c19,2);
      DAT_23006c1c = 0xffffffff;
      DAT_23006c20 = 0;
      _DAT_23006c24 = 0;
      DAT_23006c2a = 0;
      DAT_23006c2d = 0;
      return;
    }
    if (DAT_23006c20 + 1 < DAT_23006c1c) {
      DAT_23006c20 = DAT_23006c20 + 1;
      return;
    }
  }
  else {
    if (DAT_23006c14 < 180000) {
      DAT_23006c14 = DAT_23006c14 + 1;
      if (DAT_23006c14 == 180000) {
        _DAT_23006c18 = CONCAT11(DAT_23006c19,2);
        DAT_23006c1c = 0xffffffff;
        DAT_230077c0 = '\0';
        FUN_0e084fa8();
        DAT_230077be = '\x01';
        if ((1 << (uint)DAT_23000e20 & **(uint **)(DAT_23000e1c + 0x10)) == 0) {
          pcVar11 = *(code **)(*(int *)(DAT_23000e1c + 8) + 0xc);
        }
        else {
          pcVar11 = *(code **)(*(int *)(DAT_23000e1c + 8) + 0x10);
        }
        (*pcVar11)();
        DAT_23006c10 = 0;
      }
      goto LAB_0e0856b4;
    }
    if (DAT_23006c10 != 0x9c4) {
      if (DAT_23006c10 < 0x2134) {
        DAT_23006c10 = DAT_23006c10 + 1;
      }
      else {
        FUN_0e084fa8(1);
        _DAT_23006c18 = CONCAT11(DAT_23006c19,2);
        DAT_23006c10 = 0;
        DAT_23006c14 = 0;
        DAT_23006c1c = 0xffffffff;
        DAT_230077c0 = '\0';
      }
      goto LAB_0e0856b4;
    }
    if ((1 << (uint)DAT_23000e20 & **(uint **)(DAT_23000e1c + 0x10)) == 0) {
      pcVar11 = *(code **)(*(int *)(DAT_23000e1c + 8) + 0x10);
    }
    else {
      pcVar11 = *(code **)(*(int *)(DAT_23000e1c + 8) + 0xc);
    }
    (*pcVar11)();
    _DAT_23006c24 = 0;
    DAT_23006c10 = DAT_23006c10 + 1;
    _DAT_23006c18 = 0;
    DAT_230077c0 = '\x01';
  }
  DAT_23006c1c = 1;
  DAT_23006c20 = 0;
  if (DAT_23006c18 == '\0') {
    uVar10 = (uint)DAT_23006c19;
    iVar6 = FUN_0e0852cc(&DAT_230007a8 + uVar10 * 0x30,
                         *(undefined4 *)(&DAT_230007ac + uVar10 * 0x60));
    if (iVar6 == 0) {
      return;
    }
    cVar1 = *(char *)((int)&DAT_230007a8 + uVar10 * 0x60 + 1);
    if (*(char *)(&DAT_230007a8 + uVar10 * 0x30) == '\x01') {
      if (cVar1 == '\b') {
        if (DAT_23006c2b != '\0') {
LAB_0e085a16:
          iVar6 = 0;
          psVar8 = &DAT_230007a8;
          do {
            sVar2 = *psVar8;
            psVar8 = psVar8 + 0x30;
            if (sVar2 == 0x802) {
              _DAT_23006c18 = CONCAT11((char)iVar6,DAT_23006c18);
              return;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 != 0x11);
          return;
        }
      }
      else if (cVar1 == '\v') {
        if (-1 < DAT_23006c2c) goto LAB_0e085a16;
      }
      else if ((cVar1 == '\0') && (DAT_23006c29 != DAT_23000e08)) {
        _DAT_23006c18 = _DAT_23006c18 & 0xff;
        DAT_23006c1c = 1000;
        return;
      }
    }
    if (DAT_23006c2a == '\f') {
      if (DAT_23007736 != '\0') {
        _DAT_23006c18 = 1;
        return;
      }
      _DAT_23006c18 = 1;
      DAT_23006c38 = 0x960;
      return;
    }
    bVar9 = DAT_23006c19 + 1;
    _DAT_23006c18 = CONCAT11(bVar9,DAT_23006c18);
    if (bVar9 < 0x11) {
      return;
    }
    bVar9 = 0xf;
    DAT_23006c1c = 200;
    goto LAB_0e0858a2;
  }
  if (DAT_23006c18 != '\x01') {
    DAT_23006c1c = 1;
    DAT_23006c20 = 0;
    return;
  }
  if (DAT_23006c2a == '\f') {
    if (DAT_23006c3c == '\0') {
      if (DAT_23006c38 + 1 < 0x9c5) {
        DAT_23006c1c = 1;
        DAT_23006c20 = 0;
        DAT_23006c38 = DAT_23006c38 + 1;
        return;
      }
      psVar8 = &DAT_23000688;
      cVar13 = '\0';
      cVar12 = '\0';
      do {
        sVar2 = *psVar8;
        if (sVar2 == 1) {
          *(undefined1 *)((int)psVar8 + 0x5f) = 1;
          DAT_23006c3c = cVar1;
          cVar13 = cVar1;
        }
        else if (sVar2 == 0x401) {
          *(undefined1 *)((int)psVar8 + 0x5f) = 1;
          DAT_23006c3c = cVar1;
          cVar12 = cVar1;
        }
        else if (sVar2 == 0x201) {
          *(undefined1 *)((int)psVar8 + 0x5f) = 1;
          DAT_23006c3c = cVar1;
        }
        psVar8 = psVar8 + 0x30;
      } while (psVar8 != &DAT_230007a8);
      if (cVar12 != '\0') {
        DAT_23006c2d = '\0';
      }
      if (cVar13 != '\0') {
        DAT_23006c29 = '\0';
      }
      DAT_23006c38 = 0;
      goto LAB_0e085798;
    }
  }
  else {
LAB_0e085798:
    if (DAT_23006c3c == '\0') {
      return;
    }
  }
  uVar10 = (uint)DAT_23006c19;
  iVar6 = uVar10 * 0x60;
  if (((&DAT_230006e7)[iVar6] != '\0') &&
     (iVar7 = FUN_0e0852cc(&DAT_23000688 + uVar10 * 0x30,*(undefined4 *)(&DAT_2300068c + iVar6)),
     iVar7 == 0)) {
    return;
  }
  (&DAT_230006e7)[iVar6] = 0;
  uVar4 = DAT_23006c34;
  if ((&DAT_23000688)[uVar10 * 0x30] == 0x401) {
    DAT_23006c2d = DAT_23006c2d + '\x01';
    if (DAT_23006c2d == '\x01') {
      (&DAT_230006e7)[iVar6] = 1;
      DAT_23006c1c = 5;
      DAT_230076ec = uVar4;
      DAT_230077bf = 0;
      return;
    }
    if (DAT_23006c2d == '\x02') {
      if (DAT_230076ec != DAT_23006c34) {
        (&DAT_230006e7)[iVar6] = 1;
        DAT_23006c1c = 5;
        return;
      }
      _DAT_23006c30 = DAT_230076ec;
      DAT_230077bf = '\x01';
    }
    else {
      DAT_230077bf = '\x01';
      _DAT_23006c30 = DAT_23006c34;
    }
  }
  bVar9 = DAT_23006c19 + 1;
  if (2 < bVar9) {
    _DAT_23006c18 = _DAT_23006c18 & 0xff;
    DAT_23006c3c = 0;
    if (DAT_230077bf == '\0') {
      DAT_23006c3c = 0;
      return;
    }
    DAT_23006c2e = 100;
    lVar3 = (ulonglong)((uint)_DAT_23006c30 * 100 >> 8) * 0x2b1da48;
    uVar5 = (undefined4)lVar3;
    bVar9 = (byte)((ulonglong)lVar3 >> 0x20);
    if ((bVar9 < 100) && (DAT_23006c2e = bVar9, bVar9 == 0)) {
      uVar5 = 0x5f00;
      DAT_23006c2e = 0;
      if ((((uint)_DAT_23006c30 * 10000) / 0x5f00) % 100 != 0) {
        DAT_23006c2e = 1;
      }
    }
    DAT_23006c32 = (undefined2)((int)((uint)DAT_23006c36 * 5) >> 4);
    DAT_23006c28 = 1;
    FUN_0e097510(uVar5);
    DAT_230077bf = 0;
    return;
  }
LAB_0e0858a2:
  _DAT_23006c18 = CONCAT11(bVar9,DAT_23006c18);
  return;
}


