/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e1f40. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0e1f40(int param_1,uint param_2)

{
  code *pcVar1;
  ushort uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar5 = DAT_1c0e1fe8;
  uVar8 = param_2 >> 5;
  uVar7 = (uint)*(byte *)(DAT_1c0e1fe4 + uVar8) + (param_2 & 0x1f) & 0xff;
  if (-1 < (int)((uint)*(ushort *)
                        (DAT_1c0e1fe8 + ((uint)*(byte *)(param_1 + 4) * 0x52 + uVar7 + 8) * 2) <<
                0x1f)) {
    return DAT_1c0e1fec;
  }
  piVar4 = (int *)FUN_1c0e1eb8();
  uVar2 = *(ushort *)(iVar5 + ((uint)*(byte *)(piVar4 + 1) * 0x52 + uVar7 + 8) * 2);
  if ((int)((uint)uVar2 << 0x1a) < 0) {
    iVar6 = *piVar4 + (uint)(uVar2 >> 0xd) * 4;
    *(undefined4 *)(iVar6 + 0x510) = 0;
    *(undefined4 *)(iVar6 + 0x510) = 0;
  }
  FUN_1c0e1ffc(piVar4,param_2);
  *(undefined2 *)(iVar5 + ((uint)*(byte *)(piVar4 + 1) * 0x52 + uVar7 + 8) * 2) = 0;
  uVar3 = DAT_1c0e1ff8;
  if (uVar8 < 10) {
    iVar5 = *(int *)(DAT_1c0e1ff0 + uVar8 * 4) + (param_2 & 0x1f) * 4;
    *(uint *)(iVar5 + 0x80) = DAT_1c0e1ff4 & *(uint *)(iVar5 + 0x80) | 2;
    return uVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0x1c0e1fe0);
  (*pcVar1)();
}


