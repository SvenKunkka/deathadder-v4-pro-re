/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e456c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0e456c(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  
  uVar4 = 0x10;
  bVar3 = 0;
  while( true ) {
    uVar2 = LZCOUNT((uint)(byte)(((byte)uVar4 >> 4) << 3) << 0x18);
    if (uVar2 == *(byte *)(param_1 + 2)) break;
    uVar4 = uVar4 & ~(1 << uVar2);
    bVar3 = bVar3 + 1;
  }
  *(undefined4 *)((uint)*(byte *)(param_1 + 2) * 0x10 + 0x5f99c52c) = 0;
  iVar1 = (uint)bVar3 * 0xc;
  *(undefined4 *)(&DAT_2f011258 + iVar1) = *param_1;
  *(undefined4 *)(&DAT_2f01125c + iVar1) = param_1[1];
  bVar3 = *(byte *)(param_1 + 2);
  (&DAT_2f011260)[iVar1] = bVar3;
  _DAT_2f011254 = _DAT_2f011254 | 1 << (uint)bVar3;
  return;
}


