/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0fab94. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0fab94(int param_1,int param_2)

{
  ushort uVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  
  uVar5 = (uint)*(byte *)(param_2 + 0x18);
  uVar8 = uVar5 & 0x7f;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  iVar12 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  cVar2 = *(char *)(param_2 + 0x18);
  if ((*(byte *)(param_2 + 0x18) & 0x7f) != 0) {
    if (cVar2 < '\0') {
      if ((*(byte *)(iVar12 + 0x365) != 0) && (*(byte *)(iVar12 + 0x365) - 1 < uVar8)) {
        return 0xffffffea;
      }
      iVar9 = uVar8 + 0x48;
    }
    else {
      iVar9 = uVar8 + 0x58;
    }
    puVar10 = (uint *)(iVar4 + iVar9 * 0x20);
    uVar1 = *(ushort *)(param_2 + 0x1a);
    uVar11 = uVar1 & 0x7ff;
    bVar3 = *(byte *)(param_2 + 0x19) & 3;
    uVar6 = DAT_1c0fae74 & *puVar10 | uVar11;
    if (bVar3 == 2) {
      uVar6 = uVar6 | 0x10080000;
    }
    else if (bVar3 == 3) {
      uVar6 = uVar6 | 0x100c0000;
    }
    else {
      if (bVar3 != 1) {
        return 0xffffffea;
      }
      uVar6 = uVar6 | 0x40000;
    }
    if (cVar2 < '\0') {
      if ((uVar1 & 0x7ff) == 0) {
        uVar6 = uVar6 | 0x8000;
        goto LAB_1c0facb6;
      }
      uVar11 = uVar11 + 3 >> 2;
      uVar11 = ((uVar1 & 0x1fff) >> 0xb) * uVar11 + uVar11;
      if ((int)((uint)*(byte *)(iVar12 + 0x362) << 0x1f) < 0) {
        if ((-(1 << uVar8) & *(uint *)(iVar12 + 0x2b0)) != 0) {
          bVar3 = *(char *)(iVar12 + 0x365) - 1;
          if (bVar3 == 0) {
            return 0xfffffffb;
          }
          do {
            iVar4 = FUN_1c0f927c(param_1,bVar3 | 0x80);
            uVar7 = *(uint *)(iVar12 + 0x2b0);
            if ((*(byte *)(iVar4 + 0x14) & 1) == 0) {
              if ((int)((uVar7 >> (uint)bVar3) << 0x1f) < 0) {
                *(uint *)(iVar12 + 0x2b0) = uVar7 & ~(1 << (uint)bVar3);
              }
            }
            else if ((int)((uVar7 >> (uint)bVar3) << 0x1f) < 0) goto LAB_1c0fae4e;
            bVar3 = bVar3 - 1;
          } while (bVar3 != 0);
          uVar7 = *(uint *)(iVar12 + 0x2b0);
LAB_1c0fae4e:
          if ((-(1 << uVar8) & uVar7) != 0) {
            return 0xfffffffb;
          }
        }
        if (uVar8 == 1) {
          if (*(ushort *)(iVar12 + 0x340) < 0x21) {
            uVar7 = (uint)*(ushort *)(iVar12 + 0x33e) + (uint)*(ushort *)(iVar12 + 0x340);
          }
          else {
            uVar7 = *(ushort *)(iVar12 + 0x33e) + 0x20;
          }
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10) + uVar8 * 4;
          uVar7 = (*(uint *)(iVar4 + 0xfc) & 0xffff) + (*(uint *)(iVar4 + 0xfc) >> 0x10);
        }
        if ((*(ushort *)(iVar12 + (uVar8 + 0x1a0) * 2) < uVar11) ||
           ((uint)*(ushort *)(iVar12 + 0x33c) < uVar11 + uVar7)) {
          return 0xfffffff4;
        }
        *(uint *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + (uVar8 + 0x3f) * 4 + 4) =
             uVar7 | uVar11 * 0x10000;
      }
      else if (*(uint *)(iVar4 + uVar8 * 4 + 0x100) >> 0x10 < uVar11) {
        return 0xfffffff4;
      }
      *(uint *)(iVar12 + 0x2b0) = *(uint *)(iVar12 + 0x2b0) | 1 << uVar8;
      iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
      *(uint *)(iVar4 + 0x10) = (uVar5 & 0x1f) << 6 | 0x20;
      do {
      } while (*(int *)(iVar4 + 0x10) << 0x1a < 0);
      uVar8 = *(byte *)(param_2 + 0x18) & 0x7f;
      iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
      uVar6 = (uVar5 & 0xf) << 0x16 | uVar6 & 0xfc3fffff | 0x8000;
      if ((int)((uint)*(byte *)(param_2 + 0x18) << 0x18) < 0) goto LAB_1c0facb6;
    }
    else {
      uVar6 = uVar6 | 0x8000;
    }
    uVar8 = uVar8 + 0x10;
LAB_1c0facb6:
    *(uint *)(iVar4 + 0x81c) = *(uint *)(iVar4 + 0x81c) | 1 << uVar8;
    *puVar10 = uVar6;
    return 0;
  }
  uVar1 = *(ushort *)(param_2 + 0x1a);
  if (cVar2 < '\0') {
    puVar10 = (uint *)(iVar4 + 0x900);
    uVar8 = *(uint *)(iVar4 + 0x900) & 0xfffffffc;
    if (uVar1 == 0x20) {
      uVar8 = uVar8 | 0x8001;
    }
    else if (uVar1 < 0x21) {
      if (uVar1 == 8) {
        uVar8 = uVar8 | 0x8003;
      }
      else {
        if (uVar1 != 0x10) {
          return 0xffffffea;
        }
        uVar8 = uVar8 | 0x8002;
      }
    }
    else {
      if (uVar1 != 0x40) {
        return 0xffffffea;
      }
      uVar8 = uVar8 | 0x8000;
    }
  }
  else {
    uVar8 = *(uint *)(iVar4 + 0xb00) & 0xfffffffc;
    if (uVar1 == 0x20) {
      uVar8 = uVar8 | 1;
    }
    else if (uVar1 < 0x21) {
      if (uVar1 == 8) {
        uVar8 = uVar8 | 3;
      }
      else {
        if (uVar1 != 0x10) {
          return 0xffffffea;
        }
        uVar8 = uVar8 | 2;
      }
    }
    else if (uVar1 != 0x40) {
      return 0xffffffea;
    }
    uVar8 = uVar8 | 0x8000;
    puVar10 = (uint *)(iVar4 + 0xb00);
    if (uVar5 == 0) {
      *(undefined4 *)(iVar4 + 0x10) = 0x10;
      do {
      } while (*(int *)(iVar4 + 0x10) << 0x1b < 0);
      goto LAB_1c0fac40;
    }
  }
  *(undefined4 *)(iVar4 + 0x10) = 0x20;
  do {
  } while (*(int *)(iVar4 + 0x10) << 0x1a < 0);
LAB_1c0fac40:
  *puVar10 = uVar8;
  uVar8 = *(byte *)(param_2 + 0x18) & 0x7f;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(byte *)(param_2 + 0x18) & 0x80) == 0) {
    uVar8 = uVar8 + 0x10;
  }
  *(uint *)(iVar4 + 0x81c) = *(uint *)(iVar4 + 0x81c) | 1 << uVar8;
  return 0;
}


