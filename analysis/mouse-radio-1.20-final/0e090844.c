/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e090844. Types and names are inferred; NOT original source. */

undefined4 FUN_0e090844(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(*(int *)(param_1 + 0x10) + 0x24);
  if (uVar2 <= param_2) {
    return 0xffffffea;
  }
  cVar1 = *(char *)(*(int *)(param_1 + 0x10) + 0x25);
  if (cVar1 != '\0') {
    FUN_0e091e08(*(undefined4 *)(param_1 + 4),param_2 & 0xff,uVar2,cVar1,param_4);
    return 0;
  }
  return 0xfffffff5;
}


