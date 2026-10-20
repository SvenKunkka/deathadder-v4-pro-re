/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ae158. Types and names are inferred; NOT original source. */

void FUN_0e0ae158(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  
  iVar2 = FUN_0e0ae054();
  uVar1 = *(ushort *)(&DAT_2f01137c + (iVar2 + 8) * 2);
  if ((int)((uint)uVar1 << 0x17) < 0) {
    uVar3 = (uVar1 & 0x1fff) >> 9;
    *(ushort *)(&DAT_2f01137c + (iVar2 + 8) * 2) = uVar1 & 0xe0ff;
    iVar2 = 0;
    puVar4 = (ushort *)0x2f01138a;
    while( true ) {
      puVar4 = puVar4 + 1;
      if (((*puVar4 & 0x100) != 0) && (uVar3 == (*puVar4 & 0x1fff) >> 9)) break;
      iVar2 = iVar2 + 1;
      if (iVar2 == 0x40) {
        *(undefined4 *)(&DAT_2f01137c + uVar3 * 8) = 0;
        FUN_0e0adffc(&DAT_2f011414);
        return;
      }
    }
  }
  return;
}


