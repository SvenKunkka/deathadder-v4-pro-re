/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e087dfc. Types and names are inferred; NOT original source. */

uint FUN_0e087dfc(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  char cVar3;
  uint local_20;
  undefined4 local_1c;
  
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  local_20 = param_4;
  uVar1 = FUN_0e08771c(uVar2,&local_20,&local_1c,param_4,0,0);
  cVar3 = '\x01';
  if (-1 < (int)uVar1) {
    FUN_0e09739c(local_1c,param_3,param_4);
    uVar1 = FUN_0e087d20(uVar2,0,*(undefined1 *)(param_2 + 0xc),uVar1,param_4);
    uVar1 = uVar1 & (int)uVar1 >> 0x20;
    if (cVar3 == '\0') {
      uVar1 = param_4;
    }
  }
  return uVar1;
}


