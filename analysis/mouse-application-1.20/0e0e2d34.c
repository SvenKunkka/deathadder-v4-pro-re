/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e2d34. Types and names are inferred; NOT original source. */

void FUN_0e0e2d34(void)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = (uint)DAT_2f0118e4;
  uVar2 = 1 << (uVar4 & 0x1f);
  puVar3 = (uint *)((uint)(DAT_2f0118e4 >> 5) * 4 + 0x2f011728);
  uVar1 = *puVar3;
  *puVar3 = uVar1 & ~uVar2;
  if ((uVar2 & uVar1) != 0) {
    iVar5 = uVar4 * 0xc;
    FUN_0e0e6d58(*(undefined1 *)(iVar5 + 0x2f011714),*(undefined1 *)(iVar5 + 0x2f011715));
    FUN_0e0e2cdc(0);
    FUN_0e0e6e74();
    *(undefined4 *)(iVar5 + 0x2f011714) = 0;
    *(undefined4 *)(iVar5 + 0x2f011718) = 0;
    *(undefined4 *)(iVar5 + 0x2f01171c) = 0;
  }
  return;
}


