/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068910. Types and names are inferred; NOT original source. */

undefined4 FUN_0e068910(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined8 uVar7;
  longlong lVar8;
  
  puVar5 = *(undefined4 **)(param_1 + 4);
  if (*(char *)(puVar5 + 0x12) == '\0') {
    if (param_2 == 0) {
      return 0xffffffea;
    }
    iVar3 = FUN_0e05ee80(*puVar5);
    uVar1 = DAT_0e068a54;
    if ((iVar3 == 0) || (iVar3 == -0x78)) {
      puVar5[4] = DAT_0e068a50;
      uVar2 = DAT_0e068a58;
      puVar5[0x10] = param_2;
      puVar5[5] = uVar1;
      puVar5[6] = uVar2;
      puVar5[0x11] = param_3;
      puVar5[7] = param_1;
      FUN_0e06ee50(puVar5 + 10);
      iVar3 = FUN_0e05ee9c(*puVar5,puVar5 + 8,puVar5 + 2);
      if (iVar3 == 0) {
        uVar7 = FUN_0e06ea3c();
        lVar8 = FUN_0e05bbd8((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0,param_4);
        uVar4 = (uint)(lVar8 + 500);
        iVar3 = (int)((ulonglong)(lVar8 + 500) >> 0x20);
        if ((iVar3 + ((((iVar3 * 0x20 | uVar4 >> 0x1b) - iVar3) - (uint)(uVar4 * 0x20 < uVar4)) * 4
                     | uVar4 * 0x1f >> 0x1e) + (uint)CARRY4(uVar4 * 0x7c,uVar4) & 0x1fffffff) == 0
            && (uVar4 * 0x7d >> 0x1d == 0 && uVar4 * 1000 == 0)) {
          iVar6 = -2;
          iVar3 = -1;
        }
        else {
          uVar7 = FUN_0e06ea3c();
          lVar8 = FUN_0e05bbd8((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
          uVar4 = (uint)(lVar8 + 500);
          iVar3 = (int)((ulonglong)(lVar8 + 500) >> 0x20);
          iVar6 = uVar4 * -1000 + -2;
          iVar3 = (-1 - ((iVar3 + ((((iVar3 * 0x20 | uVar4 >> 0x1b) - iVar3) -
                                   (uint)(uVar4 * 0x20 < uVar4)) * 4 | uVar4 * 0x1f >> 0x1e) +
                                  (uint)CARRY4(uVar4 * 0x7c,uVar4)) * 8 | uVar4 * 0x7d >> 0x1d)) -
                  (uint)(0xfffffffe < uVar4 * 1000);
        }
        puVar5[0xe] = iVar6;
        puVar5[0xf] = iVar3;
        *(undefined1 *)(puVar5 + 0x12) = 1;
        return 0;
      }
      *(undefined1 *)(puVar5 + 0x12) = 3;
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
      *(undefined1 *)(puVar5 + 0x12) = 3;
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


