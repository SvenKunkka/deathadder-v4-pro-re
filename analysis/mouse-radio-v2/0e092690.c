/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e092690. Types and names are inferred; NOT original source. */

void FUN_0e092690(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = FUN_0e092b70(param_2);
  iVar3 = FUN_0e092b60();
  iVar4 = DAT_0e0926f4 + param_1 * 0xc;
  if (iVar3 == 0xf) {
    bVar1 = *(byte *)(iVar4 + 8);
  }
  else {
    bVar1 = *(byte *)(iVar4 + 9);
  }
  if (((*(int *)(DAT_0e0926f4 + param_1 * 0xc + 4) != iVar2) &&
      (*(int *)(DAT_0e0926f4 + param_1 * 0xc) != iVar2)) && (iVar2 = FUN_0e0920c4(), iVar2 != 0)) {
    FUN_0e092b68();
  }
  if (param_2 + 0xacfd4000U < 0x1065) {
    iVar2 = 0x100;
  }
  else {
    iVar2 = 0x80;
  }
  *(uint *)(iVar2 + param_2) = bVar1 | 0x80000000;
  return;
}


