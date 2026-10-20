/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068874. Types and names are inferred; NOT original source. */

undefined4 FUN_0e068874(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  
  puVar3 = *(undefined4 **)(param_1 + 4);
  if (*(char *)(puVar3 + 0x12) == '\0') {
    if (param_2 == 0) {
      return 0xffffffea;
    }
    iVar1 = FUN_0e05ed80(*puVar3);
    if ((iVar1 == 0) || (iVar1 == -0x78)) {
      puVar3[4] = &DAT_0e0687a5;
      puVar3[0x10] = param_2;
      puVar3[5] = &LAB_0e068778_1;
      puVar3[6] = &DAT_0e068791;
      puVar3[0x11] = param_3;
      puVar3[7] = param_1;
      FUN_0e06edb4(puVar3 + 10);
      iVar1 = FUN_0e05ed9c(*puVar3,puVar3 + 8,puVar3 + 2);
      if (iVar1 == 0) {
        uVar5 = FUN_0e06e9a0();
        lVar6 = FUN_0e05ba10((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0,param_4);
        uVar2 = (uint)(lVar6 + 500);
        iVar1 = (int)((ulonglong)(lVar6 + 500) >> 0x20);
        if ((iVar1 + ((((iVar1 * 0x20 | uVar2 >> 0x1b) - iVar1) - (uint)(uVar2 * 0x20 < uVar2)) * 4
                     | uVar2 * 0x1f >> 0x1e) + (uint)CARRY4(uVar2 * 0x7c,uVar2) & 0x1fffffff) == 0
            && (uVar2 * 0x7d >> 0x1d == 0 && uVar2 * 1000 == 0)) {
          iVar4 = -2;
          iVar1 = -1;
        }
        else {
          uVar5 = FUN_0e06e9a0();
          lVar6 = FUN_0e05ba10((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
          uVar2 = (uint)(lVar6 + 500);
          iVar1 = (int)((ulonglong)(lVar6 + 500) >> 0x20);
          iVar4 = uVar2 * -1000 + -2;
          iVar1 = (-1 - ((iVar1 + ((((iVar1 * 0x20 | uVar2 >> 0x1b) - iVar1) -
                                   (uint)(uVar2 * 0x20 < uVar2)) * 4 | uVar2 * 0x1f >> 0x1e) +
                                  (uint)CARRY4(uVar2 * 0x7c,uVar2)) * 8 | uVar2 * 0x7d >> 0x1d)) -
                  (uint)(0xfffffffe < uVar2 * 1000);
        }
        puVar3[0xe] = iVar4;
        puVar3[0xf] = iVar1;
        *(undefined1 *)(puVar3 + 0x12) = 1;
        return 0;
      }
      *(undefined1 *)(puVar3 + 0x12) = 3;
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
      *(undefined1 *)(puVar3 + 0x12) = 3;
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


