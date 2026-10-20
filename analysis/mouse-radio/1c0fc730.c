/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0fc730. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0fc730(int param_1,uint param_2,uint param_3,uint param_4,ushort param_5)

{
  code *pcVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  uint *puVar10;
  bool bVar11;
  
  piVar9 = *(int **)(param_1 + 4);
  puVar10 = *(uint **)(param_1 + 0x10);
  if (3 < param_2) {
    return 0xffffffea;
  }
  bVar11 = *(char *)((int)piVar9 + 0x1e) == '\x01';
  uVar8 = param_4;
  if (bVar11) {
    uVar8 = param_4 >> 1;
  }
  if (bVar11) {
    param_3 = param_3 >> 1;
  }
  piVar4 = piVar9;
  if (uVar8 == 0) {
    uVar6 = 0;
    bVar11 = false;
  }
  else if (uVar8 < param_3) {
    if (param_3 != *puVar10) {
      if (((uint)(byte)puVar10[1] & ~(1 << (param_2 & 0xff))) != 0) {
        return 0xffffffea;
      }
      iVar3 = 0;
      uVar7 = param_3;
      while (0x7fff < uVar7) {
        iVar3 = iVar3 + 1;
        uVar7 = uVar7 >> 1;
        if (iVar3 == 8) {
          return 0xffffffea;
        }
      }
      *puVar10 = param_3;
      *(char *)((int)puVar10 + 5) = (char)iVar3;
      iVar5 = *piVar9;
      bVar2 = *(byte *)((int)piVar9 + 0x1e);
      *(int *)(iVar5 + 0x50c) = iVar3;
      *(uint *)(iVar5 + 0x504) = (uint)bVar2;
      *(uint *)(iVar5 + 0x508) = uVar7;
      piVar4 = *(int **)(param_1 + 4);
    }
    bVar11 = true;
    uVar6 = (ushort)(uVar8 >> *(sbyte *)((int)puVar10 + 5));
  }
  else {
    bVar11 = false;
    uVar6 = 0x7fff;
  }
  iVar3 = piVar4[10];
  *(ushort *)(iVar3 + param_2 * 2) = uVar6 | (param_5 & 1 ^ 1) << 0xf;
  if (piVar9[0x10] << 0x1f < 0) {
    FUN_1c103638(*(undefined4 *)(*(int *)(param_1 + 4) + 0x28),(short)piVar9[0xb],iVar3,
                 *(int *)(param_1 + 4),param_4);
  }
  if (bVar11) {
    *(byte *)(puVar10 + 1) = (byte)puVar10[1] | (byte)(1 << (param_2 & 0xff));
    goto LAB_1c0fc7f6;
  }
  uVar7 = *(uint *)(*piVar9 + (param_2 + 0x158) * 4);
  if (-1 < (int)uVar7) {
    if ((param_5 & 1) == 0) {
      if (uVar8 == 0) goto LAB_1c0fc81c;
    }
    else if (uVar8 != 0) {
LAB_1c0fc81c:
      if (0x13f < uVar7) {
        uRam00000008 = 0;
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0x1c0fc898);
        (*pcVar1)();
      }
      *(int *)(*(int *)(DAT_1c0fc89c + (uVar7 >> 5) * 4) + 8) = 1 << (uVar7 & 0x1f);
      goto LAB_1c0fc7b6;
    }
    if (0x13f < uVar7) {
      uRam00000004 = 0;
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0x1c0fc892);
      (*pcVar1)();
    }
    *(int *)(*(int *)(DAT_1c0fc89c + (uVar7 >> 5) * 4) + 4) = 1 << (uVar7 & 0x1f);
  }
LAB_1c0fc7b6:
  uVar8 = (uint)(byte)puVar10[1] & ~(1 << (param_2 & 0xff));
  *(char *)(puVar10 + 1) = (char)uVar8;
  if (uVar8 == 0) {
    FUN_1c0fd330(piVar9);
    *(undefined1 *)((int)puVar10 + 6) = 1;
    return 0;
  }
LAB_1c0fc7f6:
  if (*(char *)((int)puVar10 + 6) != '\0') {
    *(undefined1 *)((int)puVar10 + 6) = 0;
    do {
      iVar3 = FUN_1c0fd3d8(piVar9);
    } while (iVar3 == 0);
  }
  FUN_1c0fd260(piVar9,piVar9 + 10,1,0x10);
  return 0;
}


