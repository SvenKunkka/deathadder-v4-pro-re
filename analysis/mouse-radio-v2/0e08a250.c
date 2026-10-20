/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08a250. Types and names are inferred; NOT original source. */

uint FUN_0e08a250(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  if (param_2 != 0) {
    iVar6 = 0;
    iVar5 = param_1;
    do {
      uVar4 = *(uint *)(iVar5 + 4);
      if (uVar4 != 0) {
        if (uVar4 < 0x20) {
          return 0xffffffea;
        }
        if ((uVar4 & 0x1f) != 0) {
          return 0xffffffea;
        }
        uVar7 = *(uint *)(param_1 + iVar6 * 4);
        if ((uVar7 & 0x1f) != 0) {
          return 0xffffffea;
        }
        uVar1 = FUN_0e08a1ac(uVar7);
        uVar4 = FUN_0e08a1ac((uVar7 - 1) + uVar4);
        iVar3 = DAT_0e08a3ac;
        if (uVar1 != uVar4) {
          return 0xffffffea;
        }
        if (uVar1 == 0xffffffea) {
          return 0xffffffea;
        }
        if ((int)param_3 <= (int)uVar1) {
          return 0xffffffea;
        }
        *(uint *)(DAT_0e08a3ac + 0x98) = uVar1;
        *(uint *)(iVar3 + 0x98) = uVar1;
        uVar4 = *(uint *)(param_1 + iVar6 * 4);
        uVar7 = *(int *)(iVar5 + 4) + uVar4;
        uVar8 = *(uint *)(iVar3 + 0xa0) | 0x1f;
        uVar9 = uVar7 - 1;
        if ((*(uint *)(iVar3 + 0x9c) & 0xffffffe0) == uVar4) {
          if (uVar8 == uVar9) {
            FUN_0e08a1fc(uVar1 & 0xff,iVar5,uVar7,iVar3,param_4);
          }
          else {
            *(uint *)(iVar3 + 0x98) = uVar1;
            uVar4 = uVar7 & 0xffffffe0 | *(uint *)(iVar3 + 0x9c) & 0x1f;
            *(uint *)(iVar3 + 0x9c) = uVar4;
            iVar3 = FUN_0e08a1fc(param_3 & 0xff,iVar5,uVar4,iVar3,param_4);
joined_r0x0e08a370:
            if (iVar3 == -0x16) {
              return 0xffffffea;
            }
            param_3 = iVar3 + 1;
          }
        }
        else {
          *(uint *)(iVar3 + 0x98) = uVar1;
          uVar4 = *(uint *)(iVar3 + 0xa0) & 0x1f | uVar4 - 1 & 0xffffffe0;
          *(uint *)(iVar3 + 0xa0) = uVar4;
          if (uVar8 == uVar9) {
            iVar3 = FUN_0e08a1fc(param_3 & 0xff,iVar5,uVar4,iVar3,param_4);
            goto joined_r0x0e08a370;
          }
          iVar2 = FUN_0e08a1fc(param_3 & 0xff,iVar5,uVar4,iVar3,param_4);
          iVar3 = DAT_0e08a3ac;
          if (iVar2 == -0x16) {
            return 0xffffffea;
          }
          *(uint *)(DAT_0e08a3ac + 0x98) = uVar1;
          uVar4 = *(int *)(param_1 + iVar6 * 4) + *(int *)(iVar5 + 4) & 0xffffffe0;
          param_3 = iVar2 + 1U & 0xff;
          if (((*(uint *)(iVar3 + 0x90) & 0xffff) >> 8) - 1 < param_3) {
            return 0xffffffea;
          }
          *(uint *)(iVar3 + 0x98) = param_3;
          *(uint *)(iVar3 + 0x9c) = *(uint *)(iVar3 + 0x9c) & 0x1f | uVar4;
          param_3 = param_3 + 1;
          *(uint *)(iVar3 + 0xa0) =
               *(uint *)(iVar3 + 0xa0) & 0xe | ((uVar8 - 1) + uVar4) - uVar9 & 0xffffffe0 | 1;
        }
      }
      iVar6 = iVar6 + 3;
      iVar5 = iVar5 + 0xc;
    } while (iVar6 != param_2 * 3);
  }
  return param_3;
}


