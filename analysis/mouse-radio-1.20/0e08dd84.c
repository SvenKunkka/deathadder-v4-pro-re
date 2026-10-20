/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08dd84. Types and names are inferred; NOT original source. */

undefined4 FUN_0e08dd84(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  uVar3 = *(byte *)(param_2 + 0x18) & 0x7f;
  if ((int)((uint)*(byte *)(param_2 + 0x18) << 0x18) < 0) {
    iVar4 = uVar3 + 0x48;
  }
  else {
    iVar4 = uVar3 + 0x58;
  }
  puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + iVar4 * 0x20);
  *puVar1 = *puVar1 & 0xffdfffff | 0x10000000;
  bVar2 = *(byte *)(param_2 + 0x14) & 0xfd;
  *(byte *)(param_2 + 0x14) = bVar2;
  iVar4 = FUN_0e08d230(param_1,*(undefined1 *)(param_2 + 0x18),puVar1,bVar2,param_4);
  if (iVar4 != 0) {
    if (*(char *)(param_2 + 0x18) < '\0') {
      bVar2 = *(byte *)(param_2 + 0x18) & 0x7f;
    }
    else {
      bVar2 = *(byte *)(param_2 + 0x18) + 0x10;
    }
    FUN_0e096c30(iVar5 + 0x9c,1 << bVar2);
    FUN_0e096c30(iVar5 + 0x90,2);
  }
  return 0;
}


