/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06e088. Types and names are inferred; NOT original source. */

void FUN_0e06e088(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  undefined4 extraout_r1;
  
  thunk_FUN_0e089fd4(0x2c);
  uVar2 = DAT_0e06e178;
  iVar1 = DAT_0e06e174;
  *(undefined4 *)(DAT_0e06e174 + 0x10) = 1;
  *(undefined4 *)(iVar1 + 0x704) = 1;
  *(undefined4 *)(iVar1 + 0xe3c) = 1;
  *(undefined4 *)(iVar1 + 0xe40) = 10;
  *(undefined4 *)(iVar1 + 0xe34) = DAT_0e06e17c;
  *(undefined4 *)(iVar1 + 0xe38) = uVar2;
  *(undefined4 *)(iVar1 + 0xe2c) = DAT_0e06e180;
  *(undefined4 *)(iVar1 + 0xe30) = *(undefined4 *)(param_1 + 4);
  *(uint *)(iVar1 + 0x500) = (uint)*(byte *)(param_1 + 0x20);
  puVar3 = DAT_0e06e184;
  *(undefined4 *)(iVar1 + 0x710) = 0x18;
  *(undefined2 *)((int)puVar3 + 0xb) = 0x101;
  *puVar3 = 0;
  puVar3[1] = 0;
  *(undefined2 *)(puVar3 + 2) = 0;
  *(undefined1 *)((int)puVar3 + 10) = 3;
  *(undefined1 *)puVar3 = 5;
  *(undefined1 *)(puVar3 + 2) = 0x1f;
  *(undefined1 *)((int)puVar3 + 5) = 1;
  puVar4 = DAT_0e06e18c;
  uVar2 = DAT_0e06e188;
  *(undefined1 *)((int)DAT_0e06e18c + 5) = 1;
  *(undefined1 *)(puVar4 + 6) = 1;
  *(undefined4 *)(iVar1 + 0xe20) = uVar2;
  *(undefined4 *)(iVar1 + 0xe28) = DAT_0e06e190;
  *puVar4 = 5;
  uVar2 = DAT_0e06e194;
  *(undefined1 *)(puVar4 + 1) = 0;
  *(undefined4 *)(iVar1 + 0xe44) = 0x102;
  *(undefined4 *)(iVar1 + 0xe48) = uVar2;
  *(undefined4 *)(iVar1 + 0xe4c) = 0xffff;
  *(uint *)(iVar1 + 0x400) = *(uint *)(iVar1 + 0x400) | 0x80001;
  *(undefined4 *)(puVar4 + 4) = DAT_0e06e198;
  *(undefined4 *)(iVar1 + 0x488) = 0x108;
  *(undefined4 *)(iVar1 + 0x20c) = 0;
  *(undefined4 *)(iVar1 + 0x200) = 0;
  *(undefined4 *)(iVar1 + 0x218) = 0;
  *(undefined4 *)(iVar1 + 0x220) = 0;
  thunk_FUN_0e089ffc(0x2c,1,0);
  iVar1 = DAT_0e06e19c;
  *(undefined1 *)(DAT_0e06e19c + 0x32c) = 0;
  *(undefined4 *)(iVar1 + 0x184) = 0x1000;
  thunk_FUN_0e089fb8(0x2c,extraout_r1,0x1000,param_4);
  return;
}


