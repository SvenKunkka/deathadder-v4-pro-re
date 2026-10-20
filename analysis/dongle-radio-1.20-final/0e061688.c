/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061688. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e061688(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_2 == 0) {
    return;
  }
  iVar5 = 0;
  puVar3 = &DAT_23006938;
  do {
    iVar4 = param_1[1];
    if (iVar4 != 0) {
      iVar6 = *param_1;
      uVar1 = FUN_0e061470(iVar6);
      uVar2 = FUN_0e061470(iVar4 + iVar6 + -1);
      if (uVar1 != uVar2) {
        (&DAT_23006934)[iVar5 * 5] = 0xffffffea;
        return;
      }
      puVar3[-1] = uVar1;
      if (uVar1 == 0xffffffea) {
        return;
      }
      if ((int)(uint)DAT_230071ea <= (int)uVar1) {
        return;
      }
      _DAT_e000ed98 = uVar1;
      *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xe0 | (byte)_DAT_e000ed9c & 0x1f;
      *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0x1f | (byte)((_DAT_e000eda0 >> 1 & 7) << 5);
      *puVar3 = _DAT_e000ed9c & 0xffffffe0;
      puVar3[3] = _DAT_e000eda0 & 0xffffffe0;
    }
    iVar5 = iVar5 + 1;
    param_1 = param_1 + 3;
    puVar3 = puVar3 + 5;
    if (param_2 <= iVar5) {
      return;
    }
  } while( true );
}


