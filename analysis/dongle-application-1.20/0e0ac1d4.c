/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ac1d4. Types and names are inferred; NOT original source. */

void FUN_0e0ac1d4(void)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = (uint)DAT_2f011ba8;
  uVar2 = 1 << (uVar4 & 0x1f);
  puVar3 = (uint *)((uint)(DAT_2f011ba8 >> 5) * 4 + 0x2f0119c0);
  uVar1 = *puVar3;
  *puVar3 = uVar1 & ~uVar2;
  if ((uVar2 & uVar1) != 0) {
    iVar5 = uVar4 * 0xc;
    FUN_0e0b1d96(*(undefined1 *)(iVar5 + 0x2f0119ac),*(undefined1 *)(iVar5 + 0x2f0119ad));
    FUN_0e0ac17c(0);
    FUN_0e0b204e();
    *(undefined4 *)(iVar5 + 0x2f0119ac) = 0;
    *(undefined4 *)(iVar5 + 0x2f0119b0) = 0;
    *(undefined4 *)(iVar5 + 0x2f0119b4) = 0;
  }
  return;
}


