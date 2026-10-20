/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0fd8f8. Types and names are inferred; NOT original source. */

void FUN_1c0fd8f8(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_1c0fd938 + (uint)*(byte *)(param_1 + 1) * 0x28;
  *(undefined4 *)(iVar3 + 8) = 0;
  uVar1 = DAT_1c0fd93c;
  iVar2 = *param_1;
  *(undefined1 *)(iVar3 + 0x22) = 1;
  *(undefined4 *)(iVar2 + 0x308) = uVar1;
  *(uint *)(iVar2 + 0x200) = *(uint *)(iVar2 + 0x200) & 0xe01fe87f;
  *(undefined4 *)(iVar2 + 0x500) = 0;
  *(undefined1 *)(iVar3 + 0x24) = 0;
  return;
}


