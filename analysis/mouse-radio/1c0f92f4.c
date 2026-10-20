/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f92f4. Types and names are inferred; NOT original source. */

void FUN_1c0f92f4(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2 & 0xf;
  if ((int)(param_2 << 0x18) < 0) {
    uVar2 = uVar2 + 0x10;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + uVar2 * 4);
  if (iVar1 != 0) {
    FUN_1c101010(iVar1,param_2 << 0x18,0,0);
    return;
  }
  return;
}


