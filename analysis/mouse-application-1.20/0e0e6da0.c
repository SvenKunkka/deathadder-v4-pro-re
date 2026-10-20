/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e6da0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0e6da0(int param_1,int param_2,uint param_3,int param_4,char param_5)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x404) << 0x1f < 0) {
    if (param_5 == '\0') {
      if (param_2 == 1) {
        return 0xffffff7a;
      }
      do {
      } while (*(int *)(param_1 + 0x400) << 0x1f < 0);
      if (param_2 == 0) {
        *(undefined4 *)(param_1 + 0xc) = 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x10) = 1;
      }
      do {
      } while (*(int *)(param_1 + 0x400) << 0x1f < 0);
    }
    else {
      if ((param_3 == 0) || (param_4 == 0)) {
        return 0xffffffea;
      }
      uVar2 = param_3 & 0xffffffe0 | 0x10000000;
      do {
        do {
        } while (*(int *)(param_1 + 0x400) << 0x1f < 0);
        *(uint *)(param_1 + 0x410) = uVar2;
        if (param_2 == 1) {
          *(undefined4 *)(param_1 + 0x14) = 1;
        }
        else if (param_2 == 2) {
          *(undefined4 *)(param_1 + 0x1c) = 1;
        }
        else {
          *(undefined4 *)(param_1 + 0x18) = 1;
        }
      } while ((uVar2 != *(uint *)(param_1 + 0x410)) ||
              (uVar2 = uVar2 + 0x20, uVar2 < param_4 + (param_3 | 0x10000000)));
      do {
      } while (*(int *)(param_1 + 0x400) << 0x1f < 0);
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffff5;
  }
  return uVar1;
}


