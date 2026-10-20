/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23022e28. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23022e28(uint *param_1)

{
  dword dVar1;
  undefined1 auStack_3c [4];
  uint local_38;
  undefined4 local_1c;
  
  FUN_230225cc();
  FUN_23021800();
  FUN_230217dc();
  DAT_230027ac = *param_1;
  DAT_2300279c = (undefined2)param_1[1];
  DAT_230027b4 = ~*param_1;
  DAT_2300297e = (uint)(ushort)((ushort)param_1[2] >> 8) | ((ushort)param_1[2] & 0xff) << 8 |
                 (uint)(*(ushort *)((int)param_1 + 10) >> 8) << 0x10 |
                 (uint)*(ushort *)((int)param_1 + 10) << 0x18;
  FUN_230217a0();
  local_38 = DAT_230027ac;
  local_1c = 4;
  FUN_230218ec(auStack_3c);
  FUN_23021c6c(0,(short)param_1[3]);
  thunk_FUN_0e089e48(0x28);
  TIMER020_S_TASKS_STOP = 1;
  TIMER020_S_TASKS_CLEAR = 1;
  TIMER020_S_PRESCALER = 5;
  dVar1 = TIMER020_S_MODE;
  TIMER020_S_MODE = dVar1 & 0xfffffffc;
  dVar1 = TIMER020_S_BITMODE;
  TIMER020_S_BITMODE = dVar1 & 0xfffffffc | 2;
  TIMER020_S_CC_0 = 0;
  TIMER020_S_CC_1 = 0;
  TIMER020_S_CC_2 = 0;
  TIMER020_S_CC_3 = 0;
  TIMER020_S_CC_4 = 0;
  TIMER020_S_CC_5 = 0;
  TIMER020_S_CC_6 = 0;
  TIMER020_S_CC_7 = 0;
  TIMER020_S_INTENCLR = 0xff0000;
  thunk_FUN_0e089e70(0x28,1,0);
  DAT_e000e428 = 0x20;
  _DAT_e000e284 = 0x100;
  thunk_FUN_0e089e2c(0x28);
  thunk_FUN_0e089e70(0x5c,2,0);
  DAT_e000e45c = 0x40;
  _DAT_e000e288 = 0x10000000;
  thunk_FUN_0e089e2c(0x5c);
  thunk_FUN_0e089e70(0x5b,2,0);
  DAT_e000e45b = 0x40;
  _DAT_e000e288 = 0x8000000;
  thunk_FUN_0e089e2c(0x5b);
  return;
}


