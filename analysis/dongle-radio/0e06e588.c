/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e588. Types and names are inferred; NOT original source. */

void FUN_0e06e588(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = *(byte *)(DAT_0e06e5dc + 0x10);
  iVar3 = DAT_0e06e5e0 + (uint)bVar1 * 0x18;
  FUN_0e06e804(iVar3);
  *(undefined1 *)(DAT_0e06e5e4 + (uint)bVar1) = 0;
  if ((((*(ushort *)(param_1 + 0xe) < 0x80) && (*DAT_0e06e5e8 != 0)) &&
      (*DAT_0e06e5ec <= (int)*(char *)(param_1 + 0xe))) &&
     (((*(byte *)(param_1 + 0xd) & 0x1f) == 0 && (param_1 != DAT_0e06e5f0)))) {
    iVar2 = *DAT_0e06e5e8 + -1;
    FUN_0e06e6e4(iVar3,DAT_0e06e5f4,iVar2,iVar2 >> 0x1f);
    return;
  }
  return;
}


