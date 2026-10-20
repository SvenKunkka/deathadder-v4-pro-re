/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08cb94. Types and names are inferred; NOT original source. */

void FUN_0e08cb94(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = FUN_0e08d608(*(undefined4 *)(param_1 + 0x18));
  if (iVar1 != 0) {
    return;
  }
  uVar2 = param_2 << 0x18;
  bVar3 = (int)uVar2 < 0;
  if (bVar3) {
    uVar2 = param_2 & 0xffffff7f;
  }
  if (bVar3) {
    param_2 = uVar2 + 0x10;
  }
  *(uint *)(param_1 + 0x30) = 1 << (param_2 & 0xff) | *(uint *)(param_1 + 0x30);
  return;
}


