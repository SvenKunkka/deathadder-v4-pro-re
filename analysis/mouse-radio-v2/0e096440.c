/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e096440. Types and names are inferred; NOT original source. */

void FUN_0e096440(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = *(byte *)(DAT_0e096494 + 0x10);
  iVar3 = DAT_0e096498 + (uint)bVar1 * 0x18;
  FUN_0e0966bc(iVar3);
  *(undefined1 *)(DAT_0e09649c + (uint)bVar1) = 0;
  if ((((*(ushort *)(param_1 + 0xe) < 0x80) && (*DAT_0e0964a0 != 0)) &&
      (*DAT_0e0964a4 <= (int)*(char *)(param_1 + 0xe))) &&
     (((*(byte *)(param_1 + 0xd) & 0x1f) == 0 && (param_1 != DAT_0e0964a8)))) {
    iVar2 = *DAT_0e0964a0 + -1;
    FUN_0e09659c(iVar3,DAT_0e0964ac,iVar2,iVar2 >> 0x1f);
    return;
  }
  return;
}


