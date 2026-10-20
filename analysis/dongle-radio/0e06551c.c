/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06551c. Types and names are inferred; NOT original source. */

void FUN_0e06551c(int param_1,uint param_2,int param_3,int param_4)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint unaff_r10;
  uint uVar10;
  bool bVar11;
  
  iVar8 = *(int *)(param_1 + 0x10);
  uVar6 = *(byte *)(param_4 + 0x18) & 0x7f;
  bVar11 = (*(byte *)(param_4 + 0x18) & 0x7f) != 0;
  iVar7 = *(int *)(param_2 + 0xac);
  iVar9 = iVar8 + uVar6 * 0x20;
  uVar1 = *(ushort *)(param_4 + 0x1a);
  if (bVar11) {
    param_2 = *(uint *)(iVar7 + 0x2b4);
    unaff_r10 = *(uint *)(iVar7 + 0x2b8);
  }
  uVar5 = *(uint *)(iVar9 + 0xb00);
  if (!bVar11) {
    param_2 = 0x7f;
    unaff_r10 = 1;
  }
  uVar10 = (uVar1 & 0x1fff) >> 0xb;
  if ((*(byte *)(param_4 + 0x19) & 3) == 1) {
    uVar4 = FUN_0e061cfc(param_3 + 0xc);
    uVar2 = uVar1 & 0x7ff;
    uVar2 = uVar10 * uVar2 + uVar2;
    uVar3 = uVar10 + 1;
    if (uVar4 < uVar2) {
      return;
    }
    if ((int)((uint)*(ushort *)(iVar7 + 0x360) << 0x1f) < 0) {
      uVar5 = uVar5 | 0x94000000;
    }
    else {
      uVar5 = uVar5 | 0xa4000000;
    }
  }
  else {
    uVar2 = FUN_0e061cfc(param_3 + 0xc);
    if (param_2 < uVar2) {
      uVar3 = *(ushort *)(param_4 + 0x1a) & 0x7ff;
      uVar2 = ((*(ushort *)(param_4 + 0x1a) & 0x1fff) >> 0xb) * uVar3 + uVar3;
      uVar2 = (param_2 / uVar2) * uVar2;
    }
    else {
      uVar3 = *(ushort *)(param_4 + 0x1a) & 0x7ff;
    }
    uVar3 = ((uVar2 + uVar3) - 1) / uVar3;
    uVar5 = uVar5 | 0x84000000;
  }
  if (unaff_r10 < uVar3) {
    uVar3 = (uVar10 + 1) * (unaff_r10 / (uVar10 + 1));
    uVar2 = uVar3 * (*(ushort *)(param_4 + 0x1a) & 0x7ff);
  }
  uVar10 = uVar2 & 0x7ffff | DAT_0e065608 & uVar3 << 0x13;
  if (*(char *)(param_4 + 0x18) == '\0') {
    uVar10 = uVar10 | 0x60000000;
  }
  *(uint *)(iVar7 + uVar6 * 4 + 0x2fc) = uVar10;
  *(uint *)(iVar8 + uVar6 * 0x20 + 0xb10) = uVar10;
  *(uint *)(iVar9 + 0xb00) = uVar5;
  return;
}


