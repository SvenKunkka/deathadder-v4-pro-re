/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08a94c. Types and names are inferred; NOT original source. */

uint FUN_0e08a94c(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  FUN_0e097688();
  FUN_0e0976e0();
  FUN_0e097650(DAT_0e08aa38,0x10);
  iVar1 = DAT_0e08aa40;
  *(uint *)(DAT_0e08aa3c + 0x490) = *(uint *)(DAT_0e08aa3c + 0x490) & 0xfffffffe;
  *(uint *)(iVar1 + 0x508) = *(uint *)(iVar1 + 0x508) & 0xffffffbf;
  *(uint *)(iVar1 + 0x508) = *(uint *)(iVar1 + 0x508) & 0xffffff7f;
  iVar2 = DAT_0e08aa44;
  *(uint *)(iVar1 + 0x518) = *(uint *)(iVar1 + 0x518) & 0xffffffbf;
  *(uint *)(iVar1 + 0x518) = *(uint *)(iVar1 + 0x518) & 0xffffff7f;
  *(uint *)(iVar1 + 0x50c) = *(uint *)(iVar1 + 0x50c) & 0xffffffbf;
  *(uint *)(iVar1 + 0x51c) = *(uint *)(iVar1 + 0x51c) & 0xffffffbf;
  *(uint *)(iVar1 + 0x50c) = *(uint *)(iVar1 + 0x50c) & 0xffffff7f;
  *(uint *)(iVar1 + 0x51c) = *(uint *)(iVar1 + 0x51c) & 0xffffff7f;
  *(uint *)(iVar1 + 0x508) = *(uint *)(iVar1 + 0x508) | 0x13f;
  *(uint *)(iVar1 + 0x518) = *(uint *)(iVar1 + 0x518) | 0x13f;
  *(undefined4 *)(iVar1 + 0x50c) = 0x13f;
  *(undefined4 *)(iVar1 + 0x51c) = 0x13f;
  uVar3 = *(uint *)(iVar2 + 0x418);
  uVar4 = *(uint *)(iVar2 + 0x430);
  uVar5 = *(uint *)(iVar2 + 0x410);
  *(undefined4 *)(iVar1 + -0x4b98) = 0x10;
  *(undefined4 *)(iVar1 + -0x4b80) = 1;
  *(uint *)(iVar1 + -0x4bc0) = uVar5 & 0xff;
  *(uint *)(iVar1 + -0x4bbc) = uVar3 & 0xffff;
  *(uint *)(iVar1 + -0x4bb8) = uVar4 & 0xffff;
  *(undefined4 *)(iVar1 + -0x4bb0) = 0;
  *(undefined4 *)(iVar1 + -0x4b80) = 0;
  *(undefined4 *)(iVar1 + -0x4fec) = 1;
  *(undefined4 *)(iVar1 + -0x4fec) = 1;
  uVar3 = FUN_0e097808();
  return uVar3 & (int)uVar3 >> 0x1f;
}


