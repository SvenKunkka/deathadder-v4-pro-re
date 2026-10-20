/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b15bc. Types and names are inferred; NOT original source. */

uint FUN_0e0b15bc(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  char cVar3;
  uint local_20;
  uint local_1c;
  
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  local_20 = param_4;
  local_1c = param_4;
  uVar1 = FUN_0e0b1326(uVar2,&local_20,&local_1c,0,0,0);
  cVar3 = '\x01';
  if (-1 < (int)uVar1) {
    FUN_0e0b280e(local_1c,param_3,param_4);
    uVar1 = FUN_0e0b1532(uVar2,0,*(undefined1 *)(param_2 + 0xc),uVar1,param_4);
    uVar1 = uVar1 & (int)uVar1 >> 0x20;
    if (cVar3 == '\0') {
      uVar1 = param_4;
    }
  }
  return uVar1;
}


