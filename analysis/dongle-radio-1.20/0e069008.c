/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069008. Types and names are inferred; NOT original source. */

int FUN_0e069008(int *param_1,uint param_2,undefined4 *param_3)

{
  code *pcVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ushort uVar8;
  byte *pbVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  byte local_19;
  
  uVar4 = param_2 >> 5;
  uVar11 = (uint)(byte)(&DAT_0e070704)[uVar4] + (param_2 & 0x1f) & 0xff;
  if ((byte *)*param_3 != (byte *)0x0) {
    if ((*(ushort *)(&DAT_23000968 + ((uint)*(byte *)(param_1 + 1) * 0x52 + uVar11 + 8) * 2) & 0x22)
        == 0x22) {
      return 0xbad0004;
    }
    if (9 < uVar4) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0xe069224);
      (*pcVar1)();
    }
    iVar5 = *(int *)(&DAT_0e0706dc + uVar4 * 4) + (param_2 & 0x1f) * 4;
    *(uint *)(iVar5 + 0x80) = *(uint *)(iVar5 + 0x80) & 0xfffffff0 | (uint)*(byte *)*param_3 << 2;
    iVar5 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar11 + 8;
    *(ushort *)(&DAT_23000968 + iVar5 * 2) = *(ushort *)(&DAT_23000968 + iVar5 * 2) & 0xfffd;
    iVar5 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar11 + 8;
    *(ushort *)(&DAT_23000968 + iVar5 * 2) = *(ushort *)(&DAT_23000968 + iVar5 * 2) | 1;
  }
  pbVar9 = (byte *)param_3[1];
  if (pbVar9 == (byte *)0x0) goto LAB_0e0690e0;
  uVar4 = (uint)*(byte *)(param_1 + 1);
  iVar13 = uVar4 * 0x52 + uVar11 + 8;
  bVar2 = *pbVar9;
  uVar12 = (uint)bVar2;
  iVar5 = *(int *)(pbVar9 + 4);
  uVar8 = *(ushort *)(&DAT_23000968 + iVar13 * 2);
  if ((uVar8 & 2) == 0) {
    *(ushort *)(&DAT_23000968 + iVar13 * 2) = uVar8 & 0x1fdf;
    if (iVar5 != 0) {
      if (3 < uVar12) {
        return 0xbad0004;
      }
      bVar3 = **(byte **)(param_3[1] + 4);
      iVar5 = *param_1 + (uint)bVar3 * 4;
      if (uVar12 == 0) {
        *(undefined4 *)(iVar5 + 0x510) = 0;
        *(undefined4 *)(iVar5 + 0x510) = 0;
        uVar4 = (uint)*(byte *)(param_1 + 1);
        uVar8 = *(ushort *)(&DAT_23000968 + (uVar4 * 0x52 + uVar11 + 8) * 2);
        goto LAB_0e0690ba;
      }
      *(uint *)(iVar5 + 0x510) = *(uint *)(iVar5 + 0x510) & 0xfffffffc;
      iVar5 = *param_1 + (uint)bVar3 * 4;
      *(uint *)(iVar5 + 0x510) = *(uint *)(iVar5 + 0x510) & 0xfffce00f;
      *(uint *)(iVar5 + 0x510) = (param_2 & 0x1ff) << 4 | uVar12 << 0x10 | *(uint *)(iVar5 + 0x510);
      iVar5 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar11 + 8;
      *(ushort *)(&DAT_23000968 + iVar5 * 2) =
           *(ushort *)(&DAT_23000968 + iVar5 * 2) | (ushort)bVar3 << 0xd | 0x20;
    }
    uVar4 = (uint)*(byte *)(param_1 + 1);
    uVar8 = *(ushort *)(&DAT_23000968 + (uVar4 * 0x52 + uVar11 + 8) * 2);
  }
  else if (iVar5 != 0) {
    return 0xbad0004;
  }
LAB_0e0690ba:
  *(ushort *)(&DAT_23000968 + (uVar4 * 0x52 + uVar11 + 8) * 2) = uVar8 & 0xffe3;
  iVar5 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar11 + 8;
  *(ushort *)(&DAT_23000968 + iVar5 * 2) =
       *(ushort *)(&DAT_23000968 + iVar5 * 2) | (ushort)bVar2 << 2;
LAB_0e0690e0:
  piVar10 = (int *)param_3[2];
  if (piVar10 != (int *)0x0) {
    iVar13 = *piVar10;
    iVar5 = piVar10[1];
    FUN_0e068b40(param_1);
    if (iVar13 != 0) {
      uVar4 = (uint)*(byte *)(param_1 + 1);
      if ((iVar13 == *(int *)(&DAT_23000968 + uVar4 * 0xa4)) &&
         (iVar5 == *(int *)(&DAT_2300096c + uVar4 * 0xa4))) {
        uVar7 = 0;
        uVar12 = uVar7;
      }
      else {
        iVar6 = FUN_0e068a5c(&DAT_23000a00 + uVar4 * 0xa4,&local_19);
        if (iVar6 != 0xbad0000) {
          return iVar6;
        }
        uVar4 = (uint)*(byte *)(param_1 + 1);
        uVar7 = (local_19 & 0x7f) << 9;
        uVar12 = (uint)local_19;
      }
      *(int *)(&DAT_23000968 + uVar4 * 0xa4 + uVar12 * 8) = iVar13;
      *(int *)(&DAT_2300096c + (uint)*(byte *)(param_1 + 1) * 0xa4 + uVar12 * 8) = iVar5;
      iVar5 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar11 + 8;
      *(ushort *)(&DAT_23000968 + iVar5 * 2) =
           (ushort)uVar7 | *(ushort *)(&DAT_23000968 + iVar5 * 2) | 0x100;
    }
  }
  return 0xbad0000;
}


