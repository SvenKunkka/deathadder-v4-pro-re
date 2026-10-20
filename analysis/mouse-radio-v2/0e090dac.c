/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e090dac. Types and names are inferred; NOT original source. */

undefined4 FUN_0e090dac(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  bool bVar8;
  undefined8 uVar9;
  longlong lVar10;
  
  puVar6 = *(undefined4 **)(param_1 + 4);
  if (*(char *)(puVar6 + 0x12) == '\0') {
    if (param_2 == 0) {
      return 0xffffffea;
    }
    iVar3 = FUN_0e087744(*puVar6);
    uVar1 = DAT_0e090f78;
    if ((iVar3 == 0) || (iVar3 == -0x78)) {
      puVar6[4] = DAT_0e090f74;
      uVar2 = DAT_0e090f7c;
      puVar6[0x10] = param_2;
      puVar6[5] = uVar1;
      puVar6[6] = uVar2;
      puVar6[0x11] = param_3;
      puVar6[7] = param_1;
      FUN_0e096d4c(puVar6 + 10);
      iVar3 = FUN_0e087760(*puVar6,puVar6 + 8,puVar6 + 2);
      if (iVar3 == 0) {
        uVar9 = FUN_0e096918();
        iVar3 = (int)((ulonglong)uVar9 >> 0x20);
        uVar4 = (uint)uVar9;
        lVar10 = FUN_0e0797c0(uVar4 * 1000,
                              (iVar3 + ((((iVar3 << 5 | uVar4 >> 0x1b) - iVar3) -
                                        (uint)(uVar4 * 0x20 < uVar4)) * 4 | uVar4 * 0x1f >> 0x1e) +
                                       (uint)CARRY4(uVar4 * 0x7c,uVar4)) * 8 | uVar4 * 0x7d >> 0x1d,
                              0x7a12,0,param_4);
        uVar4 = (uint)(lVar10 + 500);
        iVar3 = (int)((ulonglong)(lVar10 + 500) >> 0x20);
        iVar7 = ((iVar3 * 0x20 | uVar4 >> 0x1b) - iVar3) - (uint)(uVar4 * 0x20 < uVar4);
        uVar5 = (iVar3 + ((((iVar7 * 0x40 | uVar4 * 0x1f >> 0x1a) - iVar7) -
                          (uint)(uVar4 * 0x7c0 < uVar4 * 0x1f)) * 8 | uVar4 * 0x7a1 >> 0x1d) +
                         (uint)CARRY4(uVar4 * 0x3d08,uVar4)) * 2 +
                (uint)CARRY4(uVar4 * 0x3d09,uVar4 * 0x3d09) + (uint)(0xfffffc18 < uVar4 * 0x7a12);
        bVar8 = 999 < uVar4 * 0x7a12 + 999;
        if (uVar5 == 0 && bVar8 <= uVar5) {
          iVar3 = -2;
          iVar7 = -1;
        }
        else {
          uVar9 = FUN_0e096918(uVar4,uVar5 - !bVar8);
          iVar3 = (int)((ulonglong)uVar9 >> 0x20);
          uVar4 = (uint)uVar9;
          lVar10 = FUN_0e0797c0(uVar4 * 1000,
                                (iVar3 + ((((iVar3 << 5 | uVar4 >> 0x1b) - iVar3) -
                                          (uint)(uVar4 * 0x20 < uVar4)) * 4 | uVar4 * 0x1f >> 0x1e)
                                         + (uint)CARRY4(uVar4 * 0x7c,uVar4)) * 8 |
                                uVar4 * 0x7d >> 0x1d,0x7a12,0);
          uVar4 = (uint)(lVar10 + 500);
          iVar3 = (int)((ulonglong)(lVar10 + 500) >> 0x20);
          iVar7 = ((iVar3 * 0x20 | uVar4 >> 0x1b) - iVar3) - (uint)(uVar4 * 0x20 < uVar4);
          uVar9 = FUN_0e0797c0(uVar4 * 0x7a12 + 999,
                               (iVar3 + ((((iVar7 * 0x40 | uVar4 * 0x1f >> 0x1a) - iVar7) -
                                         (uint)(uVar4 * 0x7c0 < uVar4 * 0x1f)) * 8 |
                                        uVar4 * 0x7a1 >> 0x1d) + (uint)CARRY4(uVar4 * 0x3d08,uVar4))
                               * 2 + (uint)CARRY4(uVar4 * 0x3d09,uVar4 * 0x3d09) +
                               (uint)(0xfffffc18 < uVar4 * 0x7a12),1000,0);
          iVar3 = -2 - (uint)uVar9;
          iVar7 = (-1 - (int)((ulonglong)uVar9 >> 0x20)) - (uint)(0xfffffffe < (uint)uVar9);
        }
        puVar6[0xe] = iVar3;
        puVar6[0xf] = iVar7;
        *(undefined1 *)(puVar6 + 0x12) = 1;
        return 0;
      }
      *(undefined1 *)(puVar6 + 0x12) = 3;
      if (iVar3 == -0x16) {
        return 0xffffffea;
      }
      if (iVar3 < -0x15) {
        if (iVar3 == -0x78) {
          return 0xffffff8e;
        }
        if (iVar3 != -0x4d) {
          return 0xfffffffb;
        }
        return 0xffffffb3;
      }
      if (iVar3 == -5) {
        return 0xfffffffb;
      }
    }
    else {
      *(undefined1 *)(puVar6 + 0x12) = 3;
      if (iVar3 == -0x16) {
        return 0xffffffea;
      }
      if (iVar3 == -5) {
        return 0xfffffffb;
      }
      if (iVar3 == -0x4d) {
        return 0xffffffb3;
      }
    }
    if (iVar3 < 0) {
      return 0xfffffffb;
    }
  }
  return 0;
}


