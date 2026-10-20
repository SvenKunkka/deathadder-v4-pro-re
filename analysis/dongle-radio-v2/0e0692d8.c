/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0692d8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0692d8(int *param_1,uint param_2,byte *param_3,byte *param_4)

{
  code *pcVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  iVar6 = DAT_0e069424;
  uVar7 = param_2 >> 5;
  uVar9 = (uint)*(byte *)(DAT_0e069420 + uVar7) + (param_2 & 0x1f) & 0xff;
  if (param_3 != (byte *)0x0) {
    uVar5 = *(ushort *)(DAT_0e069424 + ((uint)*(byte *)(param_1 + 1) * 0x52 + uVar9 + 8) * 2);
    if (((uVar5 & 2) == 0) && ((uVar5 & 0x20) != 0)) {
      return DAT_0e069430;
    }
    if (((uVar5 & 0x1c) != 0) && (param_3[1] == 1)) {
      return DAT_0e069430;
    }
    if (9 < uVar7) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0xe06941e);
      (*pcVar1)();
    }
    iVar8 = *(int *)(DAT_0e069428 + uVar7 * 4) + (param_2 & 0x1f) * 4;
    *(uint *)(iVar8 + 0x80) =
         (uint)param_3[2] << 2 | (uint)param_3[1] << 1 | *(uint *)(iVar8 + 0x80) & 0xfffff0f0 |
         (uint)*param_3 << 8 | 1;
    iVar8 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar9 + 8;
    *(ushort *)(iVar6 + iVar8 * 2) = *(ushort *)(iVar6 + iVar8 * 2) | 3;
  }
  iVar6 = DAT_0e069424;
  if (param_4 != (byte *)0x0) {
    if (-1 < (int)((uint)*(ushort *)
                          (DAT_0e069424 + ((uint)*(byte *)(param_1 + 1) * 0x52 + uVar9 + 8) * 2) <<
                  0x1e)) {
      return DAT_0e069430;
    }
    bVar2 = *param_4;
    iVar8 = *param_1 + (uint)bVar2 * 4;
    *(undefined4 *)(iVar8 + 0x510) = 0;
    *(undefined4 *)(iVar8 + 0x510) = 0;
    iVar8 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar9 + 8;
    *(ushort *)(iVar6 + iVar8 * 2) = *(ushort *)(iVar6 + iVar8 * 2) & 0x1fdf;
    bVar3 = param_4[1];
    if (bVar3 != 0) {
      bVar4 = param_4[2];
      iVar8 = *param_1 + (uint)bVar2 * 4;
      *(uint *)(iVar8 + 0x510) = DAT_0e069434 & *(uint *)(iVar8 + 0x510);
      *(uint *)(iVar8 + 0x510) =
           (param_2 & 0x1ff) << 4 | (bVar3 & 3) << 0x10 | (bVar4 & 1) << 0x14 |
           *(uint *)(iVar8 + 0x510);
      iVar8 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar9 + 8;
      *(ushort *)(iVar6 + iVar8 * 2) = *(ushort *)(iVar6 + iVar8 * 2) | (ushort)bVar2 << 0xd | 0x20;
    }
  }
  return DAT_0e06942c;
}


