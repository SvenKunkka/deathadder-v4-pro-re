/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068fe8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e068fe8(int param_1,uint param_2)

{
  code *pcVar1;
  ushort uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar5 = DAT_0e069090;
  uVar8 = param_2 >> 5;
  uVar7 = (uint)*(byte *)(DAT_0e06908c + uVar8) + (param_2 & 0x1f) & 0xff;
  if (-1 < (int)((uint)*(ushort *)
                        (DAT_0e069090 + ((uint)*(byte *)(param_1 + 4) * 0x52 + uVar7 + 8) * 2) <<
                0x1f)) {
    return DAT_0e069094;
  }
  piVar4 = (int *)FUN_0e068f60();
  uVar2 = *(ushort *)(iVar5 + ((uint)*(byte *)(piVar4 + 1) * 0x52 + uVar7 + 8) * 2);
  if ((int)((uint)uVar2 << 0x1a) < 0) {
    iVar6 = *piVar4 + (uint)(uVar2 >> 0xd) * 4;
    *(undefined4 *)(iVar6 + 0x510) = 0;
    *(undefined4 *)(iVar6 + 0x510) = 0;
  }
  FUN_0e068bdc(piVar4,param_2);
  *(undefined2 *)(iVar5 + ((uint)*(byte *)(piVar4 + 1) * 0x52 + uVar7 + 8) * 2) = 0;
  uVar3 = DAT_0e0690a0;
  if (uVar8 < 10) {
    iVar5 = *(int *)(DAT_0e069098 + uVar8 * 4) + (param_2 & 0x1f) * 4;
    *(uint *)(iVar5 + 0x80) = DAT_0e06909c & *(uint *)(iVar5 + 0x80) | 2;
    return uVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0xe069088);
  (*pcVar1)();
}


