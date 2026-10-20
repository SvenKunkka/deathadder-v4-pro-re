/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f8a70. Types and names are inferred; NOT original source. */

void FUN_1c0f8a70(undefined4 param_1,int param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = FUN_1c0f9534(param_1,*(undefined1 *)(param_2 + 2),*(undefined1 *)(param_2 + 3),
                       *(undefined2 *)(param_2 + 4),*(undefined1 *)(param_2 + 6));
  if (iVar1 != 0) {
    return;
  }
  uVar2 = (uint)*(byte *)(param_2 + 2);
  bVar3 = *(char *)(param_2 + 2) < '\0';
  if (bVar3) {
    uVar2 = uVar2 & 0xffffff7f;
  }
  if (bVar3) {
    uVar2 = uVar2 + 0x10;
  }
  *param_3 = 1 << (uVar2 & 0xff) | *param_3;
  return;
}


