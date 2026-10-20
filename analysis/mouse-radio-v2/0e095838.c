/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e095838. Types and names are inferred; NOT original source. */

int FUN_0e095838(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined1 param_8,undefined1 param_9)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  *(undefined1 *)(param_1 + 0xc) = param_9;
  uVar3 = param_3 + 7U & 0xfffffff8;
  *(undefined1 *)(param_1 + 0xe) = param_8;
  iVar4 = param_2 + uVar3;
  *(int *)(param_1 + 0x58) = param_1 + 0x58;
  *(int *)(param_1 + 0x5c) = param_1 + 0x58;
  *(undefined1 *)(param_1 + 0xd) = 4;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  iVar1 = FUN_0e089a50(param_1,iVar4);
  *(uint *)(param_1 + 0x78) = uVar3;
  *(int *)(param_1 + 0x74) = param_2;
  uVar3 = iVar1 + 7U & 0xfffffff8;
  iVar4 = iVar4 - uVar3;
  *(uint *)(param_1 + 0x7c) = uVar3;
  FUN_0e08a088(param_1,param_2,iVar4,param_4,param_5,param_6,param_7);
  iVar1 = DAT_0e0958cc;
  *(undefined4 *)(param_1 + 0x54) = 0;
  iVar1 = *(int *)(iVar1 + 8);
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined1 *)(param_1 + 0x6c) = 0;
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x80);
  }
  *(undefined4 *)(param_1 + 0x80) = uVar2;
  return iVar4;
}


