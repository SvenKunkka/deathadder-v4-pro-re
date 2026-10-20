/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ae290. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0e0ae290(int *param_1,undefined4 param_2,int *param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined8 uVar14;
  undefined1 local_22;
  byte local_21 [5];
  
  uVar14 = FUN_0e0ae054(param_2);
  uVar8 = (uint)((ulonglong)uVar14 >> 0x20);
  iVar4 = (int)uVar14;
  if (*param_3 == 0) {
LAB_0e0ae2ec:
    pbVar9 = (byte *)param_3[1];
    if (pbVar9 != (byte *)0x0) {
      bVar1 = *pbVar9;
      uVar12 = (uint)bVar1;
      uVar14 = FUN_0e0ae0c0(uVar8,*(undefined4 *)(pbVar9 + 4));
      iVar11 = (int)((ulonglong)uVar14 >> 0x20);
      if ((int)uVar14 == 0) {
        iVar13 = iVar4 + 8;
        uVar3 = *(ushort *)(&DAT_2f01137c + iVar13 * 2);
        *(ushort *)(&DAT_2f01137c + iVar13 * 2) = uVar3 & 0x1fdf;
        if (iVar11 != 0) {
          if (3 < uVar12) goto LAB_0e0ae2fe;
          bVar2 = **(byte **)(param_3[1] + 4);
          iVar11 = *param_1 + (uint)bVar2 * 4;
          if (uVar12 == 0) {
            *(undefined4 *)(iVar11 + 0x510) = 0;
            *(undefined4 *)(iVar11 + 0x510) = 0;
          }
          else {
            *(uint *)(iVar11 + 0x510) = *(uint *)(iVar11 + 0x510) & 0xfffffffc;
            iVar11 = *param_1 + (uint)bVar2 * 4;
            uVar7 = *(uint *)(iVar11 + 0x510);
            *(ushort *)(&DAT_2f01137c + iVar13 * 2) = uVar3 & 0x1fdf | (ushort)bVar2 << 0xd | 0x20;
            *(uint *)(iVar11 + 0x510) = uVar7 & 0xfffce00f;
            *(uint *)(iVar11 + 0x510) =
                 (uVar8 & 0x1ff) << 4 | uVar12 << 0x10 | *(uint *)(iVar11 + 0x510);
          }
        }
      }
      else if (iVar11 != 0) goto LAB_0e0ae2fe;
      *(ushort *)(&DAT_2f01137c + (iVar4 + 8) * 2) =
           *(ushort *)(&DAT_2f01137c + (iVar4 + 8) * 2) & 0xffe3 | (ushort)bVar1 << 2;
    }
    piVar10 = (int *)param_3[2];
    if (piVar10 != (int *)0x0) {
      iVar11 = *piVar10;
      iVar13 = piVar10[1];
      FUN_0e0ae158(uVar8);
      if (iVar11 != 0) {
        if ((iVar11 == _DAT_2f01137c) && (iVar13 == _DAT_2f011380)) {
          uVar8 = 0;
        }
        else {
          iVar5 = FUN_0e0adfbc(&DAT_2f011414,local_21);
          if (iVar5 != 0xbad0000) {
            return iVar5;
          }
          uVar8 = (uint)local_21[0];
        }
        *(int *)(&DAT_2f011380 + uVar8 * 8) = iVar13;
        uVar3 = *(ushort *)(&DAT_2f01137c + (iVar4 + 8) * 2);
        *(int *)(&DAT_2f01137c + uVar8 * 8) = iVar11;
        *(ushort *)(&DAT_2f01137c + (iVar4 + 8) * 2) = uVar3 | (ushort)(uVar8 << 9) | 0x100;
      }
    }
    iVar4 = 0xbad0000;
  }
  else {
    uVar14 = FUN_0e0ae0c0(uVar8);
    uVar6 = (undefined4)((ulonglong)uVar14 >> 0x20);
    if ((int)uVar14 == 0) {
LAB_0e0ae2b8:
      local_22 = 0;
      local_21[0] = 0;
      FUN_0e0b207a(uVar8,&local_22,local_21,uVar6,0,0);
      *(ushort *)(&DAT_2f01137c + (iVar4 + 8) * 2) =
           *(ushort *)(&DAT_2f01137c + (iVar4 + 8) * 2) & 0xfffd | 1;
      goto LAB_0e0ae2ec;
    }
    uVar14 = FUN_0e0ae0d8(uVar8);
    uVar6 = (undefined4)((ulonglong)uVar14 >> 0x20);
    if ((int)uVar14 == 0) goto LAB_0e0ae2b8;
LAB_0e0ae2fe:
    iVar4 = 0xbad0004;
  }
  return iVar4;
}


