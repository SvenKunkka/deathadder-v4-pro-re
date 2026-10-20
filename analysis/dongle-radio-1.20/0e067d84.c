/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e067d84. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0e067d84(uint *param_1,int param_2,int param_3,uint param_4)

{
  code *pcVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint extraout_r3;
  uint uVar8;
  uint *puVar9;
  undefined *unaff_lr;
  uint *puVar10;
  
  if (param_2 == 0) {
    return 0;
  }
  puVar9 = param_1;
  do {
    puVar10 = puVar9 + 1;
    uVar8 = *puVar9;
    uVar5 = (uVar8 & 0x7fff) >> 0xb;
    uVar6 = uVar8 & 0x1ff;
    if (8 < uVar5) {
      return -0x16;
    }
    bVar2 = (&DAT_0e07052c)[uVar5];
    if (uVar6 == 0x1ff) {
      switch(uVar8 >> 0x18) {
      case 0:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x604) = 0xffffffff;
        break;
      case 1:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x60c) = 0xffffffff;
        break;
      case 2:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x610) = 0xffffffff;
        break;
      case 3:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x608) = 0xffffffff;
        break;
      default:
        goto LAB_0e067e00;
      case 0x16:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x560) = 0xffffffff;
        break;
      case 0x17:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x564) = 0xffffffff;
        break;
      case 0x18:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x568) = 0xffffffff;
        break;
      case 0x19:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x56c) = 0xffffffff;
      }
      goto LAB_0e067ec8;
    }
    switch(uVar8 >> 0x18) {
    case 0:
      *(uint *)(param_3 + 0x604) = uVar6;
      param_4 = *puVar9 << 0xd;
      uVar5 = param_4;
      break;
    case 1:
      *(uint *)(param_3 + 0x60c) = uVar6;
      param_4 = *puVar9;
      if ((param_4 & 0x40000) != 0) goto LAB_0e067f6a;
LAB_0e067f80:
      uVar6 = 0;
      goto LAB_0e067e52;
    case 2:
      *(uint *)(param_3 + 0x610) = uVar6;
      uVar5 = *puVar9 << 0xd;
      break;
    case 3:
      *(uint *)(param_3 + 0x608) = uVar6;
      param_4 = *puVar9;
      if ((param_4 & 0x40000) == 0) goto LAB_0e067f80;
LAB_0e067f6a:
      uVar5 = 0;
      uVar3 = 0xffffffff;
      goto LAB_0e067e18;
    default:
LAB_0e067e00:
      return -0x86;
    case 0x16:
      *(uint *)(param_3 + 0x560) = uVar6;
      uVar3 = *puVar9;
      param_4 = uVar3 << 0xd;
      uVar5 = param_4;
      goto joined_r0x0e067e14;
    case 0x17:
      *(uint *)(param_3 + 0x564) = uVar6;
      uVar3 = (*puVar9 & 0x1ffff) >> 0x10;
      if (-1 < (int)(*puVar9 << 0xd)) {
        uVar5 = 1;
        goto LAB_0e067ef0;
      }
      goto LAB_0e067e16;
    case 0x18:
      *(uint *)(param_3 + 0x568) = uVar6;
      param_4 = *puVar9 << 0xd;
      uVar3 = (*puVar9 & 0x1ffff) >> 0x10;
      if ((int)param_4 < 0) goto LAB_0e067e16;
      uVar5 = 1;
      goto LAB_0e067ef0;
    case 0x19:
      *(uint *)(param_3 + 0x56c) = uVar6;
      uVar3 = *puVar9;
      uVar5 = uVar3 << 0xd;
joined_r0x0e067e14:
      uVar3 = (uVar3 & 0x1ffff) >> 0x10;
      if ((int)uVar5 < 0) {
LAB_0e067e16:
        uVar5 = 1;
        goto LAB_0e067e18;
      }
      uVar5 = 1;
      goto LAB_0e067ef0;
    }
    if ((int)uVar5 < 0) {
      uVar5 = 1;
      uVar3 = 1;
LAB_0e067e18:
      if (0x13f < uVar6) {
        param_4 = 0;
      }
      else {
        unaff_lr = &DAT_0e070504;
      }
      if (0x13f >= uVar6) {
        param_4 = *(uint *)(unaff_lr + ((uVar8 & 0x1ff) >> 5) * 4);
      }
      iVar4 = FUN_0e061f9c(3);
      if (iVar4 < 0) {
        return iVar4;
      }
      *(int *)(param_4 + 0x48) = 1 << (uVar8 & 0x1f);
      if (uVar3 != 0xffffffff) {
LAB_0e067ef0:
        uVar6 = (uVar8 & 0x1ff) >> 5;
        if (uVar3 != 0) goto LAB_0e068016;
        if (9 < uVar6) {
          _NMI = 0;
                    /* WARNING: Does not return */
          pcVar1 = (code *)software_udf(0xff,0xe0680a4);
          (*pcVar1)();
        }
        *(int *)(*(int *)(&DAT_0e070504 + uVar6 * 4) + 8) = 1 << (uVar8 & 0x1f);
        goto LAB_0e067f0c;
      }
      param_4 = *puVar9;
      uVar6 = uVar5;
LAB_0e067e52:
      uVar5 = uVar6;
      if ((param_4 & 0x8000) != 0) {
        uVar6 = 0;
        uVar5 = 1;
      }
      if (9 < (uVar8 & 0x1ff) >> 5) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0xe0680b8);
        (*pcVar1)();
      }
    }
    else {
      uVar5 = 1;
LAB_0e068016:
      uVar6 = (uVar8 & 0x1ff) >> 5;
      if (9 < uVar6) {
        _Reset = 0;
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0xe0680a0);
        (*pcVar1)();
      }
      *(int *)(*(int *)(&DAT_0e070504 + uVar6 * 4) + 4) = 1 << (uVar8 & 0x1f);
LAB_0e067f0c:
      param_4 = *puVar9;
      uVar6 = uVar5;
      if ((param_4 & 0x8000) != 0) {
        uVar5 = 1;
        uVar6 = 0;
      }
    }
    unaff_lr = &DAT_0e070504;
    iVar4 = *(int *)(&DAT_0e070504 + ((uVar8 & 0x1ff) >> 5) * 4);
    iVar7 = iVar4 + (uVar8 & 0x1f) * 4;
    *(uint *)(iVar7 + 0x80) =
         *(uint *)(iVar7 + 0x80) & 0xfffcf0f0 | (uint)bVar2 << 8 | ((param_4 & 0x7ff) >> 9) << 2 |
         uVar6 | uVar5 << 1;
    *(uint *)(iVar7 + 0x80) = *(uint *)(iVar7 + 0x80) & 0x7fffffff | (*puVar9 >> 0x11) << 0x1f;
    param_4 = *puVar9;
    if ((int)(param_4 << 0xd) < 0) {
      *(int *)(iVar4 + 0x44) = 1 << (uVar8 & 0x1f);
      unaff_lr = (undefined *)0xe067ec5;
      iVar4 = FUN_0e06204c(3);
      param_4 = extraout_r3;
      if (iVar4 < 0) {
        return iVar4;
      }
    }
LAB_0e067ec8:
    puVar9 = puVar10;
    if (puVar10 == param_1 + param_2) {
      return 0;
    }
  } while( true );
}


