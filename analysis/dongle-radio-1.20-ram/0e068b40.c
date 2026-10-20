/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068b40. Types and names are inferred; NOT original source. */

void FUN_0e068b40(int param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  
  iVar3 = (uint)*(byte *)(param_1 + 4) * 0x52 +
          ((uint)(byte)(&DAT_0e070704)[param_2 >> 5] + (param_2 & 0x1f) & 0xff) + 8;
  uVar1 = *(ushort *)(&DAT_23000968 + iVar3 * 2);
  if ((int)((uint)uVar1 << 0x17) < 0) {
    uVar2 = (uVar1 & 0x1fff) >> 9;
    *(ushort *)(&DAT_23000968 + iVar3 * 2) = uVar1 & 0xe0ff;
    iVar3 = (uint)*(byte *)(param_1 + 4) * 0xa4;
    puVar4 = (ushort *)(iVar3 + 0x23000976);
    while( true ) {
      puVar4 = puVar4 + 1;
      if (((int)((uint)*puVar4 << 0x17) < 0) && (uVar2 == (*puVar4 & 0x1fff) >> 9)) break;
      if (puVar4 == (ushort *)(iVar3 + 0x230009f6)) {
        *(undefined4 *)(&DAT_23000968 + (uint)*(byte *)(param_1 + 4) * 0xa4 + uVar2 * 8) = 0;
        FUN_0e068a9c(&DAT_23000a00 + (uint)*(byte *)(param_1 + 4) * 0xa4);
        return;
      }
    }
  }
  return;
}


