/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c102440. Types and names are inferred; NOT original source. */

void FUN_1c102440(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = *(byte *)(DAT_1c102494 + 0x10);
  iVar3 = DAT_1c102498 + (uint)bVar1 * 0x18;
  FUN_1c1026bc(iVar3);
  *(undefined1 *)(DAT_1c10249c + (uint)bVar1) = 0;
  if ((((*(ushort *)(param_1 + 0xe) < 0x80) && (*DAT_1c1024a0 != 0)) &&
      (*DAT_1c1024a4 <= (int)*(char *)(param_1 + 0xe))) &&
     (((*(byte *)(param_1 + 0xd) & 0x1f) == 0 && (param_1 != DAT_1c1024a8)))) {
    iVar2 = *DAT_1c1024a0 + -1;
    FUN_1c10259c(iVar3,DAT_1c1024ac,iVar2,iVar2 >> 0x1f);
    return;
  }
  return;
}


