/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06923c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06923c(int *param_1,uint param_2,byte *param_3,byte *param_4)

{
  code *pcVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar6 = param_2 >> 5;
  uVar8 = (uint)(byte)(&DAT_0e070704)[uVar6] + (param_2 & 0x1f) & 0xff;
  if (param_3 != (byte *)0x0) {
    uVar5 = *(ushort *)(&DAT_23000968 + ((uint)*(byte *)(param_1 + 1) * 0x52 + uVar8 + 8) * 2);
    if (((uVar5 & 2) == 0) && ((uVar5 & 0x20) != 0)) {
      return 0xbad0004;
    }
    if (((uVar5 & 0x1c) != 0) && (param_3[1] == 1)) {
      return 0xbad0004;
    }
    if (9 < uVar6) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0xe069382);
      (*pcVar1)();
    }
    iVar7 = *(int *)(&DAT_0e0706dc + uVar6 * 4) + (param_2 & 0x1f) * 4;
    *(uint *)(iVar7 + 0x80) =
         (uint)param_3[2] << 2 | (uint)param_3[1] << 1 | *(uint *)(iVar7 + 0x80) & 0xfffff0f0 |
         (uint)*param_3 << 8 | 1;
    iVar7 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar8 + 8;
    *(ushort *)(&DAT_23000968 + iVar7 * 2) = *(ushort *)(&DAT_23000968 + iVar7 * 2) | 3;
  }
  if (param_4 != (byte *)0x0) {
    if (-1 < (int)((uint)*(ushort *)
                          (&DAT_23000968 + ((uint)*(byte *)(param_1 + 1) * 0x52 + uVar8 + 8) * 2) <<
                  0x1e)) {
      return 0xbad0004;
    }
    bVar2 = *param_4;
    iVar7 = *param_1 + (uint)bVar2 * 4;
    *(undefined4 *)(iVar7 + 0x510) = 0;
    *(undefined4 *)(iVar7 + 0x510) = 0;
    iVar7 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar8 + 8;
    *(ushort *)(&DAT_23000968 + iVar7 * 2) = *(ushort *)(&DAT_23000968 + iVar7 * 2) & 0x1fdf;
    bVar3 = param_4[1];
    if (bVar3 != 0) {
      bVar4 = param_4[2];
      iVar7 = *param_1 + (uint)bVar2 * 4;
      *(uint *)(iVar7 + 0x510) = *(uint *)(iVar7 + 0x510) & 0xffece00f;
      *(uint *)(iVar7 + 0x510) =
           (param_2 & 0x1ff) << 4 | (bVar3 & 3) << 0x10 | (bVar4 & 1) << 0x14 |
           *(uint *)(iVar7 + 0x510);
      iVar7 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar8 + 8;
      *(ushort *)(&DAT_23000968 + iVar7 * 2) =
           *(ushort *)(&DAT_23000968 + iVar7 * 2) | (ushort)bVar2 << 0xd | 0x20;
    }
  }
  return 0xbad0000;
}


