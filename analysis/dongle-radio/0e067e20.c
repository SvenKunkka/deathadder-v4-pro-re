/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e067e20. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0e067e20(uint *param_1,int param_2,int param_3,uint param_4)

{
  code *pcVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint extraout_r3;
  uint uVar9;
  uint *puVar10;
  int unaff_lr;
  uint *puVar11;
  
  iVar3 = DAT_0e068144;
  if (param_2 == 0) {
    return 0;
  }
  puVar10 = param_1;
  do {
    puVar11 = puVar10 + 1;
    uVar9 = *puVar10;
    uVar6 = (uVar9 & 0x7fff) >> 0xb;
    uVar7 = uVar9 & 0x1ff;
    if (8 < uVar6) {
      return -0x16;
    }
    bVar2 = *(byte *)(iVar3 + uVar6);
    if (uVar7 == 0x1ff) {
      switch(uVar9 >> 0x18) {
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
        goto LAB_0e067e9c;
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
      goto LAB_0e067f64;
    }
    switch(uVar9 >> 0x18) {
    case 0:
      *(uint *)(param_3 + 0x604) = uVar7;
      param_4 = *puVar10 << 0xd;
      uVar6 = param_4;
      break;
    case 1:
      *(uint *)(param_3 + 0x60c) = uVar7;
      param_4 = *puVar10;
      if ((param_4 & 0x40000) != 0) goto LAB_0e068006;
LAB_0e06801c:
      uVar7 = 0;
      goto LAB_0e067eee;
    case 2:
      *(uint *)(param_3 + 0x610) = uVar7;
      uVar6 = *puVar10 << 0xd;
      break;
    case 3:
      *(uint *)(param_3 + 0x608) = uVar7;
      param_4 = *puVar10;
      if ((param_4 & 0x40000) == 0) goto LAB_0e06801c;
LAB_0e068006:
      uVar6 = 0;
      uVar4 = 0xffffffff;
      goto LAB_0e067eb4;
    default:
LAB_0e067e9c:
      return -0x86;
    case 0x16:
      *(uint *)(param_3 + 0x560) = uVar7;
      uVar4 = *puVar10;
      param_4 = uVar4 << 0xd;
      uVar6 = param_4;
      goto joined_r0x0e067eb0;
    case 0x17:
      *(uint *)(param_3 + 0x564) = uVar7;
      uVar4 = (*puVar10 & 0x1ffff) >> 0x10;
      if (-1 < (int)(*puVar10 << 0xd)) {
        uVar6 = 1;
        goto LAB_0e067f8c;
      }
      goto LAB_0e067eb2;
    case 0x18:
      *(uint *)(param_3 + 0x568) = uVar7;
      param_4 = *puVar10 << 0xd;
      uVar4 = (*puVar10 & 0x1ffff) >> 0x10;
      if ((int)param_4 < 0) goto LAB_0e067eb2;
      uVar6 = 1;
      goto LAB_0e067f8c;
    case 0x19:
      *(uint *)(param_3 + 0x56c) = uVar7;
      uVar4 = *puVar10;
      uVar6 = uVar4 << 0xd;
joined_r0x0e067eb0:
      uVar4 = (uVar4 & 0x1ffff) >> 0x10;
      if ((int)uVar6 < 0) {
LAB_0e067eb2:
        uVar6 = 1;
        goto LAB_0e067eb4;
      }
      uVar6 = 1;
      goto LAB_0e067f8c;
    }
    if ((int)uVar6 < 0) {
      uVar6 = 1;
      uVar4 = 1;
LAB_0e067eb4:
      iVar5 = DAT_0e068148;
      if (0x13f < uVar7) {
        param_4 = 0;
        iVar5 = unaff_lr;
      }
      if (0x13f >= uVar7) {
        param_4 = *(uint *)(iVar5 + ((uVar9 & 0x1ff) >> 5) * 4);
      }
      iVar5 = FUN_0e06209c(3);
      if (iVar5 < 0) {
        return iVar5;
      }
      *(int *)(param_4 + 0x48) = 1 << (uVar9 & 0x1f);
      if (uVar4 != 0xffffffff) {
LAB_0e067f8c:
        unaff_lr = DAT_0e068148;
        uVar7 = (uVar9 & 0x1ff) >> 5;
        if (uVar4 != 0) goto LAB_0e0680b2;
        if (9 < uVar7) {
          _NMI = 0;
                    /* WARNING: Does not return */
          pcVar1 = (code *)software_udf(0xff,0xe068140);
          (*pcVar1)();
        }
        *(int *)(*(int *)(DAT_0e068148 + uVar7 * 4) + 8) = 1 << (uVar9 & 0x1f);
        goto LAB_0e067fa8;
      }
      param_4 = *puVar10;
      uVar7 = uVar6;
LAB_0e067eee:
      uVar6 = uVar7;
      if ((param_4 & 0x8000) != 0) {
        uVar7 = 0;
        uVar6 = 1;
      }
      unaff_lr = DAT_0e068148;
      if (9 < (uVar9 & 0x1ff) >> 5) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0xe068154);
        (*pcVar1)();
      }
    }
    else {
      uVar6 = 1;
LAB_0e0680b2:
      unaff_lr = DAT_0e068148;
      uVar7 = (uVar9 & 0x1ff) >> 5;
      if (9 < uVar7) {
        _Reset = 0;
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0xe06813c);
        (*pcVar1)();
      }
      *(int *)(*(int *)(DAT_0e068148 + uVar7 * 4) + 4) = 1 << (uVar9 & 0x1f);
LAB_0e067fa8:
      param_4 = *puVar10;
      uVar7 = uVar6;
      if ((param_4 & 0x8000) != 0) {
        uVar6 = 1;
        uVar7 = 0;
      }
    }
    iVar5 = *(int *)(unaff_lr + ((uVar9 & 0x1ff) >> 5) * 4);
    iVar8 = iVar5 + (uVar9 & 0x1f) * 4;
    *(uint *)(iVar8 + 0x80) =
         *(uint *)(iVar8 + 0x80) & 0xfffcf0f0 | (uint)bVar2 << 8 | ((param_4 & 0x7ff) >> 9) << 2 |
         uVar7 | uVar6 << 1;
    *(uint *)(iVar8 + 0x80) = *(uint *)(iVar8 + 0x80) & 0x7fffffff | (*puVar10 >> 0x11) << 0x1f;
    param_4 = *puVar10;
    if ((int)(param_4 << 0xd) < 0) {
      *(int *)(iVar5 + 0x44) = 1 << (uVar9 & 0x1f);
      unaff_lr = 0xe067f61;
      iVar5 = FUN_0e06214c(3);
      param_4 = extraout_r3;
      if (iVar5 < 0) {
        return iVar5;
      }
    }
LAB_0e067f64:
    puVar10 = puVar11;
    if (puVar11 == param_1 + param_2) {
      return 0;
    }
  } while( true );
}


