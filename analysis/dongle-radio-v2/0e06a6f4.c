/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a6f4. Types and names are inferred; NOT original source. */

void FUN_0e06a6f4(byte *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_0e068af8(DAT_0e06a730,param_1);
  iVar1 = DAT_0e06a738;
  if (iVar2 != DAT_0e06a734) {
    return;
  }
  iVar3 = DAT_0e06a738 + (uint)*param_1 * 0xc;
  iVar2 = (uint)*param_1 * 0xc;
  *(undefined4 *)(DAT_0e06a738 + iVar2) = 0;
  *(undefined4 *)(iVar3 + 4) = 0;
  *(undefined4 *)(iVar3 + 8) = 0;
  *(undefined2 *)(iVar1 + iVar2 + 8) = 0xffff;
  *(undefined1 *)(iVar3 + 10) = 0xff;
  return;
}


