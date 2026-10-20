/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068bdc. Types and names are inferred; NOT original source. */

void FUN_0e068bdc(int param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  
  iVar2 = DAT_0e068c60;
  iVar4 = (uint)*(byte *)(param_1 + 4) * 0x52 +
          ((uint)*(byte *)(DAT_0e068c5c + (param_2 >> 5)) + (param_2 & 0x1f) & 0xff) + 8;
  uVar1 = *(ushort *)(DAT_0e068c60 + iVar4 * 2);
  if ((int)((uint)uVar1 << 0x17) < 0) {
    uVar3 = (uVar1 & 0x1fff) >> 9;
    *(ushort *)(DAT_0e068c60 + iVar4 * 2) = uVar1 & 0xe0ff;
    iVar4 = (uint)*(byte *)(param_1 + 4) * 0xa4;
    puVar5 = (ushort *)(iVar4 + 0xe + iVar2);
    while( true ) {
      puVar5 = puVar5 + 1;
      if (((int)((uint)*puVar5 << 0x17) < 0) && (uVar3 == (*puVar5 & 0x1fff) >> 9)) break;
      if (puVar5 == (ushort *)(iVar2 + 0x8e + iVar4)) {
        *(undefined4 *)(iVar2 + (uint)*(byte *)(param_1 + 4) * 0xa4 + uVar3 * 8) = 0;
        FUN_0e068b38((uint)*(byte *)(param_1 + 4) * 0xa4 + iVar2 + 0x98);
        return;
      }
    }
  }
  return;
}


