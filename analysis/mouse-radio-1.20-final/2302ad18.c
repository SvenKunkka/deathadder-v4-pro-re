/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302ad18. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2302ad18(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_230004d8;
  _DAT_5f938404 = 8;
  _DAT_5f93848c = _DAT_5f93848c & 0xfffcf0f0 | 0x80000003;
  _DAT_5f938408 = 0x40;
  _DAT_5f938498 = _DAT_5f938498 & 0xfffcf0f0 | 0x80000003;
  _DAT_5f938494 = _DAT_5f938494 & 0xfffcf0f0;
  if (DAT_230004d8 == 0x5f8e6000) {
    uVar2 = 0x28;
  }
  else if (DAT_230004d8 == 0x5f8e7000) {
    uVar2 = 0x28;
  }
  else {
    uVar2 = 2;
  }
  *(undefined4 *)(DAT_230004d8 + 0x600) = 0x43;
  *(undefined4 *)(iVar1 + 0x604) = 0x46;
  *(undefined4 *)(iVar1 + 0x608) = 0x45;
  *(undefined4 *)(iVar1 + 0x60c) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x610) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x5b8) = 0;
  *(undefined4 *)(iVar1 + 0x5b0) = 2;
  *(undefined4 *)(iVar1 + 0x5c0) = 0;
  *(undefined4 *)(iVar1 + 0x52c) = uVar2;
  *(undefined4 *)(iVar1 + 0x554) = 6;
  *(undefined4 *)(iVar1 + 0x5ac) = 1;
  *(undefined4 *)(iVar1 + 0x108) = 0;
  DAT_23007746 = 1;
  *(undefined4 *)(iVar1 + 0x500) = 7;
  *(undefined4 *)(iVar1 + 0x308) = 4;
  return;
}


