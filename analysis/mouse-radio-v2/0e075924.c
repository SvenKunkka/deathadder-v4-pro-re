/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e075924. Types and names are inferred; NOT original source. */

int FUN_0e075924(int *param_1,uint param_2,undefined4 *param_3)

{
  code *pcVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  byte *pbVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  byte local_19;
  
  iVar4 = DAT_0e075b48;
  uVar5 = param_2 >> 5;
  uVar12 = (uint)*(byte *)(DAT_0e075b44 + uVar5) + (param_2 & 0x1f) & 0xff;
  if ((byte *)*param_3 != (byte *)0x0) {
    if ((*(ushort *)(DAT_0e075b48 + ((uint)*(byte *)(param_1 + 1) * 0x52 + uVar12 + 8) * 2) & 0x22)
        == 0x22) {
      return DAT_0e075b54;
    }
    if (9 < uVar5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0xe075b40);
      (*pcVar1)();
    }
    iVar6 = *(int *)(DAT_0e075b4c + uVar5 * 4) + (param_2 & 0x1f) * 4;
    *(uint *)(iVar6 + 0x80) = *(uint *)(iVar6 + 0x80) & 0xfffffff0 | (uint)*(byte *)*param_3 << 2;
    iVar6 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar12 + 8;
    *(ushort *)(iVar4 + iVar6 * 2) = *(ushort *)(iVar4 + iVar6 * 2) & 0xfffd;
    iVar6 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar12 + 8;
    *(ushort *)(iVar4 + iVar6 * 2) = *(ushort *)(iVar4 + iVar6 * 2) | 1;
  }
  iVar4 = DAT_0e075b48;
  pbVar10 = (byte *)param_3[1];
  if (pbVar10 == (byte *)0x0) goto LAB_0e0759fc;
  uVar5 = (uint)*(byte *)(param_1 + 1);
  iVar14 = uVar5 * 0x52 + uVar12 + 8;
  bVar2 = *pbVar10;
  uVar13 = (uint)bVar2;
  iVar6 = *(int *)(pbVar10 + 4);
  uVar9 = *(ushort *)(DAT_0e075b48 + iVar14 * 2);
  if ((uVar9 & 2) == 0) {
    *(ushort *)(DAT_0e075b48 + iVar14 * 2) = uVar9 & 0x1fdf;
    if (iVar6 != 0) {
      if (3 < uVar13) {
        return DAT_0e075b54;
      }
      bVar3 = **(byte **)(param_3[1] + 4);
      iVar6 = *param_1 + (uint)bVar3 * 4;
      if (uVar13 == 0) {
        *(undefined4 *)(iVar6 + 0x510) = 0;
        *(undefined4 *)(iVar6 + 0x510) = 0;
        uVar5 = (uint)*(byte *)(param_1 + 1);
        uVar9 = *(ushort *)(iVar4 + (uVar5 * 0x52 + uVar12 + 8) * 2);
        goto LAB_0e0759d6;
      }
      *(uint *)(iVar6 + 0x510) = *(uint *)(iVar6 + 0x510) & 0xfffffffc;
      iVar6 = *param_1 + (uint)bVar3 * 4;
      *(uint *)(iVar6 + 0x510) = *(uint *)(iVar6 + 0x510) & 0xfffce00f;
      *(uint *)(iVar6 + 0x510) = (param_2 & 0x1ff) << 4 | uVar13 << 0x10 | *(uint *)(iVar6 + 0x510);
      iVar6 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar12 + 8;
      *(ushort *)(iVar4 + iVar6 * 2) = *(ushort *)(iVar4 + iVar6 * 2) | (ushort)bVar3 << 0xd | 0x20;
    }
    uVar5 = (uint)*(byte *)(param_1 + 1);
    uVar9 = *(ushort *)(iVar4 + (uVar5 * 0x52 + uVar12 + 8) * 2);
  }
  else if (iVar6 != 0) {
    return DAT_0e075b54;
  }
LAB_0e0759d6:
  *(ushort *)(iVar4 + (uVar5 * 0x52 + uVar12 + 8) * 2) = uVar9 & 0xffe3;
  iVar6 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar12 + 8;
  *(ushort *)(iVar4 + iVar6 * 2) = *(ushort *)(iVar4 + iVar6 * 2) | (ushort)bVar2 << 2;
LAB_0e0759fc:
  piVar11 = (int *)param_3[2];
  if (piVar11 != (int *)0x0) {
    iVar14 = *piVar11;
    iVar6 = piVar11[1];
    FUN_0e075ffc(param_1);
    iVar4 = DAT_0e075b48;
    if (iVar14 != 0) {
      uVar5 = (uint)*(byte *)(param_1 + 1);
      if ((iVar14 == *(int *)(DAT_0e075b48 + uVar5 * 0xa4)) &&
         (iVar6 == *(int *)(uVar5 * 0xa4 + DAT_0e075b48 + 4))) {
        uVar8 = 0;
        uVar13 = uVar8;
      }
      else {
        iVar7 = FUN_0e0753f4(uVar5 * 0xa4 + DAT_0e075b48 + 0x98,&local_19);
        if (iVar7 != DAT_0e075b50) {
          return iVar7;
        }
        uVar5 = (uint)*(byte *)(param_1 + 1);
        uVar8 = (local_19 & 0x7f) << 9;
        uVar13 = (uint)local_19;
      }
      *(int *)(iVar4 + uVar5 * 0xa4 + uVar13 * 8) = iVar14;
      *(int *)((uint)*(byte *)(param_1 + 1) * 0xa4 + uVar13 * 8 + iVar4 + 4) = iVar6;
      iVar6 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar12 + 8;
      *(ushort *)(iVar4 + iVar6 * 2) = (ushort)uVar8 | *(ushort *)(iVar4 + iVar6 * 2) | 0x100;
    }
  }
  return DAT_0e075b50;
}


