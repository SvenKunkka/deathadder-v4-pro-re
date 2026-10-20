/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0958d0. Types and names are inferred; NOT original source. */

int FUN_0e0958d0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined1 param_8,undefined1 param_9,
                undefined4 param_10,int param_11,int param_12)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = param_3 + 7U & 0xfffffff8;
  *(undefined1 *)(param_1 + 0xc) = param_9;
  *(undefined1 *)(param_1 + 0xe) = param_8;
  *(int *)(param_1 + 0x58) = param_1 + 0x58;
  *(int *)(param_1 + 0x5c) = param_1 + 0x58;
  iVar2 = param_2 + uVar3;
  *(undefined1 *)(param_1 + 0xd) = 4;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  iVar1 = FUN_0e089a50(param_1,iVar2);
  *(uint *)(param_1 + 0x78) = uVar3;
  *(int *)(param_1 + 0x74) = param_2;
  uVar3 = iVar1 + 7U & 0xfffffff8;
  *(uint *)(param_1 + 0x7c) = uVar3;
  FUN_0e08a088(param_1,param_2,iVar2 - uVar3,param_4,param_5,param_6,param_7);
  iVar1 = DAT_0e09599c;
  *(undefined4 *)(param_1 + 0x54) = 0;
  iVar1 = *(int *)(iVar1 + 8);
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined1 *)(param_1 + 0x6c) = 0;
  uVar4 = 0;
  if (iVar1 != 0) {
    uVar4 = *(undefined4 *)(iVar1 + 0x80);
  }
  *(undefined4 *)(param_1 + 0x80) = uVar4;
  if (param_12 == -1 && param_11 == -1) {
    return param_1;
  }
  if (param_12 == 0 && param_11 == 0) {
    FUN_0e095d1c(param_1);
    return param_1;
  }
  FUN_0e09659c(param_1 + 0x18,DAT_0e0959a0,param_11,param_12);
  return param_1;
}


