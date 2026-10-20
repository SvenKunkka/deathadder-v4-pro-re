/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302985c. Types and names are inferred; NOT original source. */

void FUN_2302985c(int param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  
  iVar3 = (uint)*(byte *)(param_1 + 4) * 0x52 +
          ((uint)(byte)(&DAT_0e09b6b0)[param_2 >> 5] + (param_2 & 0x1f) & 0xff) + 8;
  uVar1 = *(ushort *)(&DAT_2300130c + iVar3 * 2);
  if ((int)((uint)uVar1 << 0x17) < 0) {
    uVar2 = (uVar1 & 0x1fff) >> 9;
    *(ushort *)(&DAT_2300130c + iVar3 * 2) = uVar1 & 0xe0ff;
    iVar3 = (uint)*(byte *)(param_1 + 4) * 0xa4;
    puVar4 = (ushort *)(iVar3 + 0x2300131a);
    while( true ) {
      puVar4 = puVar4 + 1;
      if (((int)((uint)*puVar4 << 0x17) < 0) && (uVar2 == (*puVar4 & 0x1fff) >> 9)) break;
      if (puVar4 == (ushort *)(iVar3 + 0x2300139a)) {
        *(undefined4 *)(&DAT_2300130c + (uint)*(byte *)(param_1 + 4) * 0xa4 + uVar2 * 8) = 0;
        ram_candidate_23028c94(&DAT_230013a4 + (uint)*(byte *)(param_1 + 4) * 0xa4);
        return;
      }
    }
  }
  return;
}


