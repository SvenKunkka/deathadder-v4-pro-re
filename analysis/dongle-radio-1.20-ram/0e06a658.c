/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a658. Types and names are inferred; NOT original source. */

void FUN_0e06a658(byte *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0e068a5c(&DAT_23000af8,param_1);
  if (iVar1 != 0xbad0000) {
    return;
  }
  iVar1 = (uint)*param_1 * 0xc;
  iVar2 = (uint)*param_1 * 0xc;
  *(undefined4 *)(&DAT_23006e58 + iVar2) = 0;
  *(undefined4 *)(&DAT_23006e5c + iVar1) = 0;
  *(undefined4 *)(&DAT_23006e60 + iVar1) = 0;
  *(undefined2 *)(&DAT_23006e60 + iVar2) = 0xffff;
  (&DAT_23006e62)[iVar1] = 0xff;
  return;
}


