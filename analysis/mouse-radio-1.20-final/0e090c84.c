/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e090c84. Types and names are inferred; NOT original source. */

undefined4 FUN_0e090c84(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  bool bVar6;
  undefined8 uVar7;
  longlong lVar8;
  
  puVar4 = *(undefined4 **)(param_1 + 4);
  if (*(char *)(puVar4 + 0x12) == '\0') {
    if (param_2 == 0) {
      return 0xffffffea;
    }
    iVar1 = FUN_0e0875b8(*puVar4);
    if ((iVar1 == 0) || (iVar1 == -0x78)) {
      puVar4[4] = &DAT_0e090bb5;
      puVar4[0x10] = param_2;
      puVar4[5] = &LAB_0e090b88_1;
      puVar4[6] = &DAT_0e090ba1;
      puVar4[0x11] = param_3;
      puVar4[7] = param_1;
      FUN_0e096c24(puVar4 + 10);
      iVar1 = FUN_0e0875d4(*puVar4,puVar4 + 8,puVar4 + 2);
      if (iVar1 == 0) {
        uVar7 = FUN_0e0967f0();
        iVar1 = (int)((ulonglong)uVar7 >> 0x20);
        uVar2 = (uint)uVar7;
        lVar8 = FUN_0e0795d8(uVar2 * 1000,
                             (iVar1 + ((((iVar1 << 5 | uVar2 >> 0x1b) - iVar1) -
                                       (uint)(uVar2 * 0x20 < uVar2)) * 4 | uVar2 * 0x1f >> 0x1e) +
                                      (uint)CARRY4(uVar2 * 0x7c,uVar2)) * 8 | uVar2 * 0x7d >> 0x1d,
                             0x7a12,0,param_4);
        uVar2 = (uint)(lVar8 + 500);
        iVar1 = (int)((ulonglong)(lVar8 + 500) >> 0x20);
        iVar5 = ((iVar1 * 0x20 | uVar2 >> 0x1b) - iVar1) - (uint)(uVar2 * 0x20 < uVar2);
        uVar3 = (iVar1 + ((((iVar5 * 0x40 | uVar2 * 0x1f >> 0x1a) - iVar5) -
                          (uint)(uVar2 * 0x7c0 < uVar2 * 0x1f)) * 8 | uVar2 * 0x7a1 >> 0x1d) +
                         (uint)CARRY4(uVar2 * 0x3d08,uVar2)) * 2 +
                (uint)CARRY4(uVar2 * 0x3d09,uVar2 * 0x3d09) + (uint)(0xfffffc18 < uVar2 * 0x7a12);
        bVar6 = 999 < uVar2 * 0x7a12 + 999;
        if (uVar3 == 0 && bVar6 <= uVar3) {
          iVar1 = -2;
          iVar5 = -1;
        }
        else {
          uVar7 = FUN_0e0967f0(uVar2,uVar3 - !bVar6);
          iVar1 = (int)((ulonglong)uVar7 >> 0x20);
          uVar2 = (uint)uVar7;
          lVar8 = FUN_0e0795d8(uVar2 * 1000,
                               (iVar1 + ((((iVar1 << 5 | uVar2 >> 0x1b) - iVar1) -
                                         (uint)(uVar2 * 0x20 < uVar2)) * 4 | uVar2 * 0x1f >> 0x1e) +
                                        (uint)CARRY4(uVar2 * 0x7c,uVar2)) * 8 | uVar2 * 0x7d >> 0x1d
                               ,0x7a12,0);
          uVar2 = (uint)(lVar8 + 500);
          iVar1 = (int)((ulonglong)(lVar8 + 500) >> 0x20);
          iVar5 = ((iVar1 * 0x20 | uVar2 >> 0x1b) - iVar1) - (uint)(uVar2 * 0x20 < uVar2);
          uVar7 = FUN_0e0795d8(uVar2 * 0x7a12 + 999,
                               (iVar1 + ((((iVar5 * 0x40 | uVar2 * 0x1f >> 0x1a) - iVar5) -
                                         (uint)(uVar2 * 0x7c0 < uVar2 * 0x1f)) * 8 |
                                        uVar2 * 0x7a1 >> 0x1d) + (uint)CARRY4(uVar2 * 0x3d08,uVar2))
                               * 2 + (uint)CARRY4(uVar2 * 0x3d09,uVar2 * 0x3d09) +
                               (uint)(0xfffffc18 < uVar2 * 0x7a12),1000,0);
          iVar1 = -2 - (uint)uVar7;
          iVar5 = (-1 - (int)((ulonglong)uVar7 >> 0x20)) - (uint)(0xfffffffe < (uint)uVar7);
        }
        puVar4[0xe] = iVar1;
        puVar4[0xf] = iVar5;
        *(undefined1 *)(puVar4 + 0x12) = 1;
        return 0;
      }
      *(undefined1 *)(puVar4 + 0x12) = 3;
      if (iVar1 == -0x16) {
        return 0xffffffea;
      }
      if (iVar1 < -0x15) {
        if (iVar1 == -0x78) {
          return 0xffffff8e;
        }
        if (iVar1 != -0x4d) {
          return 0xfffffffb;
        }
        return 0xffffffb3;
      }
      if (iVar1 == -5) {
        return 0xfffffffb;
      }
    }
    else {
      *(undefined1 *)(puVar4 + 0x12) = 3;
      if (iVar1 == -0x16) {
        return 0xffffffea;
      }
      if (iVar1 == -5) {
        return 0xfffffffb;
      }
      if (iVar1 == -0x4d) {
        return 0xffffffb3;
      }
    }
    if (iVar1 < 0) {
      return 0xfffffffb;
    }
  }
  return 0;
}


