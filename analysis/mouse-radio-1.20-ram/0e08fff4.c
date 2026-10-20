/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08fff4. Types and names are inferred; NOT original source. */

int FUN_0e08fff4(int param_1,uint *param_2,uint param_3,undefined4 param_4)

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
  FUN_0e094fc8(iVar14,param_2,0xffffffff,0xffffffff);
  FUN_0e094fc8(iVar14 + 0x10,extraout_r1,0,0);
  puVar8 = *(undefined4 **)(uVar11 + 0x24);
  iVar3 = ram_candidate_23020cfc(puVar8,0,local_2c);
  if (-1 < iVar3) {
    thunk_FUN_23029f6c(*local_2c[0],*(undefined1 *)(local_2c[0] + 1),*puVar8);
  }
  FUN_0e0917ac(uVar11);
  if (param_3 != 0) {
    uVar9 = 0;
    uVar7 = 0;
    do {
      bVar1 = (byte)param_2[2];
      uVar5 = (uint)bVar1;
      uVar12 = uVar5 & 8;
      if ((bVar1 & 8) != 0) {
        iVar3 = -0x86;
        goto LAB_0e0901a8;
      }
      uVar10 = *param_2;
      uVar9 = uVar9 + 1;
      if ((uVar11 & 0xffffff) >> 0x10 != 0x8e) {
        uVar6 = (uint)((uVar10 & 0xeffe0000) == 0x2fc00000);
        if ((uVar9 < param_3) && (-1 < (int)(uVar5 << 0x1e))) goto LAB_0e090080;
LAB_0e090130:
        if (uVar7 != 0) {
LAB_0e090140:
          uVar6 = param_2[1];
          uVar12 = 0;
          goto joined_r0x0e09014e;
        }
        uVar12 = 0;
        if (uVar6 == 0) goto LAB_0e090094;
LAB_0e090136:
        uVar6 = (uint)(ushort)param_2[1];
LAB_0e090138:
        uVar7 = uVar6;
        uVar12 = 0;
LAB_0e0900b6:
        uVar15 = FUN_0e0902b4(param_1,uVar5,uVar10,uVar7,param_4);
        iVar3 = (int)uVar15;
        if (-1 < iVar3) {
          iVar3 = FUN_0e094fc8(iVar14 + 0x10,(int)((ulonglong)uVar15 >> 0x20),0x3d09,0);
          if (iVar3 == 0) {
            if (*(int *)(iVar14 + 0x20) == 0xbad0000) {
              if ((((int)((uint)(byte)param_2[2] << 0x1f) < 0) && (uVar10 == uVar13)) &&
                 (uVar7 = param_2[1], uVar7 <= uVar12)) {
                iVar3 = 0;
                do {
                  uVar12 = uVar12 - uVar7 & 0xffff;
                  FUN_0e09739c(*(undefined4 *)((int)param_2 + iVar3),uVar13 + uVar12);
                  uVar7 = *(uint *)((int)param_2 + iVar3 + -8);
                  iVar3 = iVar3 + -0xc;
                } while (uVar7 <= uVar12);
              }
              uVar7 = 0;
              goto LAB_0e0900f2;
            }
          }
          else {
            FUN_0e090218(param_1);
          }
          iVar3 = -5;
        }
        goto LAB_0e0901a8;
      }
      if (((uVar10 & 0xeff00000) == 0x2f000000) || ((uVar10 & 0xeff80000) == 0x2f880000)) {
        if ((uVar9 < param_3) && (-1 < (int)(uVar5 << 0x1e))) {
          uVar6 = 1;
          goto LAB_0e090080;
        }
        if (uVar7 == 0) goto LAB_0e090136;
        goto LAB_0e090140;
      }
      if ((uVar9 < param_3) && (uVar6 = uVar5 & 2, (bVar1 & 2) == 0)) {
LAB_0e090080:
        if (((bVar1 ^ (byte)param_2[5]) & 1) != 0 || ((byte)param_2[5] & 4) != 0) goto LAB_0e090130;
        uVar12 = 1;
      }
LAB_0e090094:
      uVar6 = param_2[1];
joined_r0x0e09014e:
      if ((uint)uVar2 < uVar7 + uVar6) {
        iVar3 = -0x1c;
        goto LAB_0e0901a8;
      }
      if (-1 < (int)(uVar5 << 0x1f)) {
        FUN_0e09739c(uVar13 + uVar7,uVar10);
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
          goto LAB_0e090138;
        }
        goto LAB_0e0900b6;
      }
LAB_0e0900f2:
      param_2 = param_2 + 3;
    } while (param_3 != uVar9);
  }
  iVar3 = 0;
LAB_0e0901a8:
  FUN_0e0917d0(uVar11);
  puVar8 = *(undefined4 **)(uVar11 + 0x24);
  iVar4 = ram_candidate_23020cfc(puVar8,1,local_2c);
  if (-1 < iVar4) {
    thunk_FUN_23029f6c(*local_2c[0],*(undefined1 *)(local_2c[0] + 1),*puVar8);
  }
  FUN_0e094f80(iVar14);
  return iVar3;
}


