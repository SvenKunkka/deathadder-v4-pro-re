/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0db5c4. Types and names are inferred; NOT original source. */

void FUN_1c0db5c4(uint *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_3c [4];
  undefined4 local_38;
  undefined4 local_1c;
  
  FUN_1c0dad68();
  iVar1 = DAT_1c0db6e8;
  FUN_1c0d9f9c();
  FUN_1c0d9f78();
  *(uint *)(iVar1 + 0x18) = *param_1;
  iVar2 = DAT_1c0db6ec;
  *(short *)(iVar1 + 8) = (short)param_1[1];
  iVar3 = DAT_1c0db6f0;
  *(uint *)(iVar1 + 0x20) = ~*param_1;
  *(uint *)(iVar2 + 6) =
       (uint)(ushort)((ushort)param_1[2] >> 8) | ((ushort)param_1[2] & 0xff) << 8 |
       (uint)(*(ushort *)((int)param_1 + 10) >> 8) << 0x10 |
       (uint)*(ushort *)((int)param_1 + 10) << 0x18;
  FUN_1c0d9f3c();
  local_38 = *(undefined4 *)(iVar1 + 0x18);
  local_1c = 4;
  FUN_1c0da088(auStack_3c);
  FUN_1c0da408(0,(short)param_1[3]);
  thunk_EXT_FUN_0e089fd4(0x28);
  iVar1 = DAT_1c0db6f4;
  *(undefined4 *)(DAT_1c0db6f4 + 4) = 1;
  *(undefined4 *)(iVar1 + 0xc) = 1;
  *(undefined4 *)(iVar1 + 0x510) = 5;
  *(uint *)(iVar1 + 0x504) = *(uint *)(iVar1 + 0x504) & 0xfffffffc;
  *(uint *)(iVar1 + 0x508) = *(uint *)(iVar1 + 0x508) & 0xfffffffc | 2;
  *(undefined4 *)(iVar1 + 0x540) = 0;
  *(undefined4 *)(iVar1 + 0x544) = 0;
  *(undefined4 *)(iVar1 + 0x548) = 0;
  *(undefined4 *)(iVar1 + 0x54c) = 0;
  *(undefined4 *)(iVar1 + 0x550) = 0;
  *(undefined4 *)(iVar1 + 0x554) = 0;
  *(undefined4 *)(iVar1 + 0x558) = 0;
  *(undefined4 *)(iVar1 + 0x55c) = 0;
  *(undefined4 *)(iVar1 + 0x308) = 0xff0000;
  thunk_EXT_FUN_0e089ffc(0x28,1,0);
  *(undefined1 *)(iVar3 + 0x328) = 0x20;
  *(undefined4 *)(iVar3 + 0x184) = 0x100;
  thunk_EXT_FUN_0e089fb8(0x28);
  thunk_EXT_FUN_0e089ffc(0x5c,2,0);
  *(undefined1 *)(iVar3 + 0x35c) = 0x40;
  *(undefined4 *)(iVar3 + 0x188) = 0x10000000;
  thunk_EXT_FUN_0e089fb8(0x5c);
  thunk_EXT_FUN_0e089ffc(0x5b,2,0);
  *(undefined1 *)(iVar3 + 0x35b) = 0x40;
  *(undefined4 *)(iVar3 + 0x188) = 0x8000000;
  thunk_EXT_FUN_0e089fb8(0x5b);
  return;
}


