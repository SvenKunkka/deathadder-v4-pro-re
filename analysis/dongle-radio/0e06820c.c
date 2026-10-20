/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06820c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e06820c(int param_1,uint param_2,uint param_3,uint param_4,ushort param_5)

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
    FUN_0e0673b4(*(undefined4 *)(*(int *)(param_1 + 4) + 0x28),(short)piVar9[0xb],iVar3,
                 *(int *)(param_1 + 4),param_4);
  }
  if (bVar11) {
    *(byte *)(puVar10 + 1) = (byte)puVar10[1] | (byte)(1 << (param_2 & 0xff));
    goto LAB_0e0682d2;
  }
  uVar7 = *(uint *)(*piVar9 + (param_2 + 0x158) * 4);
  if (-1 < (int)uVar7) {
    if ((param_5 & 1) == 0) {
      if (uVar8 == 0) goto LAB_0e0682f8;
    }
    else if (uVar8 != 0) {
LAB_0e0682f8:
      if (0x13f < uVar7) {
        _NMI = 0;
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0xe068374);
        (*pcVar1)();
      }
      *(int *)(*(int *)(DAT_0e068378 + (uVar7 >> 5) * 4) + 8) = 1 << (uVar7 & 0x1f);
      goto LAB_0e068292;
    }
    if (0x13f < uVar7) {
      _Reset = 0;
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0xe06836e);
      (*pcVar1)();
    }
    *(int *)(*(int *)(DAT_0e068378 + (uVar7 >> 5) * 4) + 4) = 1 << (uVar7 & 0x1f);
  }
LAB_0e068292:
  uVar8 = (uint)(byte)puVar10[1] & ~(1 << (param_2 & 0xff));
  *(char *)(puVar10 + 1) = (char)uVar8;
  if (uVar8 == 0) {
    FUN_0e069d14(piVar9);
    *(undefined1 *)((int)puVar10 + 6) = 1;
    return 0;
  }
LAB_0e0682d2:
  if (*(char *)((int)puVar10 + 6) != '\0') {
    *(undefined1 *)((int)puVar10 + 6) = 0;
    do {
      iVar3 = FUN_0e069dbc(piVar9);
    } while (iVar3 == 0);
  }
  FUN_0e069c44(piVar9,piVar9 + 10,1,0x10);
  return 0;
}


