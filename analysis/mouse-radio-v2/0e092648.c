/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e092648. Types and names are inferred; NOT original source. */

void FUN_0e092648(byte *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_0e097628(DAT_0e092684,param_1);
  iVar1 = DAT_0e09268c;
  if (iVar2 != DAT_0e092688) {
    return;
  }
  iVar3 = DAT_0e09268c + (uint)*param_1 * 0xc;
  iVar2 = (uint)*param_1 * 0xc;
  *(undefined4 *)(DAT_0e09268c + iVar2) = 0;
  *(undefined4 *)(iVar3 + 4) = 0;
  *(undefined4 *)(iVar3 + 8) = 0;
  *(undefined2 *)(iVar1 + iVar2 + 8) = 0xffff;
  *(undefined1 *)(iVar3 + 10) = 0xff;
  return;
}


