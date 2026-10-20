/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05f5c4. Types and names are inferred; NOT original source. */

uint FUN_0e05f5c4(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  char cVar3;
  uint local_20;
  undefined4 local_1c;
  
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  local_20 = param_4;
  uVar1 = FUN_0e05eee4(uVar2,&local_20,&local_1c,param_4,0,0);
  cVar3 = '\x01';
  if (-1 < (int)uVar1) {
    FUN_0e06f35c(local_1c,param_3,param_4);
    uVar1 = FUN_0e05f4e8(uVar2,0,*(undefined1 *)(param_2 + 0xc),uVar1,param_4);
    uVar1 = uVar1 & (int)uVar1 >> 0x20;
    if (cVar3 == '\0') {
      uVar1 = param_4;
    }
  }
  return uVar1;
}


