/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0fc11c. Types and names are inferred; NOT original source. */

int FUN_1c0fc11c(int param_1,uint *param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_r1;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  undefined8 uVar15;
  undefined4 *local_2c [2];
  
  uVar11 = *(uint *)(param_1 + 4);
  uVar2 = *(ushort *)(uVar11 + 0x1c);
  iVar14 = *(int *)(param_1 + 0x10);
  uVar13 = *(uint *)(uVar11 + 0x28);
  FUN_1c1010f0(iVar14,param_2,0xffffffff,0xffffffff);
  FUN_1c1010f0(iVar14 + 0x10,extraout_r1,0,0);
  puVar8 = *(undefined4 **)(uVar11 + 0x24);
  iVar3 = FUN_1c1037c0(puVar8,0,local_2c);
  if (-1 < iVar3) {
    FUN_1c103658(*local_2c[0],*(undefined1 *)(local_2c[0] + 1),*puVar8);
  }
  FUN_1c0fd8d4(uVar11);
  if (param_3 != 0) {
    uVar9 = 0;
    uVar7 = 0;
    do {
      bVar1 = (byte)param_2[2];
      uVar5 = (uint)bVar1;
      uVar12 = uVar5 & 8;
      if ((bVar1 & 8) != 0) {
        iVar3 = -0x86;
        goto LAB_1c0fc2d0;
      }
      uVar10 = *param_2;
      uVar9 = uVar9 + 1;
      if ((uVar11 & 0xffffff) >> 0x10 != 0x8e) {
        uVar6 = (uint)((uVar10 & DAT_1c0fc32c) == 0x2fc00000);
        if ((uVar9 < param_3) && (-1 < (int)(uVar5 << 0x1e))) goto LAB_1c0fc1a8;
LAB_1c0fc258:
        if (uVar7 != 0) {
LAB_1c0fc268:
          uVar6 = param_2[1];
          uVar12 = 0;
          goto joined_r0x1c0fc276;
        }
        uVar12 = 0;
        if (uVar6 == 0) goto LAB_1c0fc1bc;
LAB_1c0fc25e:
        uVar6 = (uint)(ushort)param_2[1];
LAB_1c0fc260:
        uVar7 = uVar6;
        uVar12 = 0;
LAB_1c0fc1de:
        uVar15 = FUN_1c0fc3dc(param_1,uVar5,uVar10,uVar7,param_4);
        iVar3 = (int)uVar15;
        if (-1 < iVar3) {
          iVar3 = FUN_1c1010f0(iVar14 + 0x10,(int)((ulonglong)uVar15 >> 0x20),0x3d09,0);
          if (iVar3 == 0) {
            if (*(int *)(iVar14 + 0x20) == DAT_1c0fc330) {
              if ((((int)((uint)(byte)param_2[2] << 0x1f) < 0) && (uVar10 == uVar13)) &&
                 (uVar7 = param_2[1], uVar7 <= uVar12)) {
                iVar3 = 0;
                do {
                  uVar12 = uVar12 - uVar7 & 0xffff;
                  FUN_1c1034c4(*(undefined4 *)((int)param_2 + iVar3),uVar13 + uVar12);
                  uVar7 = *(uint *)((int)param_2 + iVar3 + -8);
                  iVar3 = iVar3 + -0xc;
                } while (uVar7 <= uVar12);
              }
              uVar7 = 0;
              goto LAB_1c0fc21a;
            }
          }
          else {
            FUN_1c0fc340(param_1);
          }
          iVar3 = -5;
        }
        goto LAB_1c0fc2d0;
      }
      if (((DAT_1c0fc334 & uVar10) == 0x2f000000) || ((DAT_1c0fc338 & uVar10) == DAT_1c0fc33c)) {
        if ((uVar9 < param_3) && (-1 < (int)(uVar5 << 0x1e))) {
          uVar6 = 1;
          goto LAB_1c0fc1a8;
        }
        if (uVar7 == 0) goto LAB_1c0fc25e;
        goto LAB_1c0fc268;
      }
      if ((uVar9 < param_3) && (uVar6 = uVar5 & 2, (bVar1 & 2) == 0)) {
LAB_1c0fc1a8:
        if (((bVar1 ^ (byte)param_2[5]) & 1) != 0 || ((byte)param_2[5] & 4) != 0) goto LAB_1c0fc258;
        uVar12 = 1;
      }
LAB_1c0fc1bc:
      uVar6 = param_2[1];
joined_r0x1c0fc276:
      if ((uint)uVar2 < uVar7 + uVar6) {
        iVar3 = -0x1c;
        goto LAB_1c0fc2d0;
      }
      if (-1 < (int)(uVar5 << 0x1f)) {
        FUN_1c1034c4(uVar13 + uVar7,uVar10);
        uVar6 = param_2[1];
      }
      uVar6 = uVar6 & 0xffff;
      uVar7 = uVar7 + uVar6 & 0xffff;
      if (uVar12 == 0) {
        uVar5 = (uint)(byte)param_2[2];
        uVar10 = uVar13;
        uVar12 = uVar7;
        if (uVar7 == 0) {
          uVar10 = *param_2;
          goto LAB_1c0fc260;
        }
        goto LAB_1c0fc1de;
      }
LAB_1c0fc21a:
      param_2 = param_2 + 3;
    } while (param_3 != uVar9);
  }
  iVar3 = 0;
LAB_1c0fc2d0:
  FUN_1c0fd8f8(uVar11);
  puVar8 = *(undefined4 **)(uVar11 + 0x24);
  iVar4 = FUN_1c1037c0(puVar8,1,local_2c);
  if (-1 < iVar4) {
    FUN_1c103658(*local_2c[0],*(undefined1 *)(local_2c[0] + 1),*puVar8);
  }
  FUN_1c1010a8(iVar14);
  return iVar3;
}


