/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302206c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2302206c(uint *param_1)

{
  dword dVar1;
  undefined1 auStack_44 [4];
  uint local_40;
  
  _DAT_5300e040 = 1;
  _DAT_5301e040 = 1;
  _DAT_5302e040 = 1;
  FUN_23021d38();
  FUN_23020b1c();
  FUN_23020a30();
  DAT_23003244 = *param_1;
  DAT_23003238 = (undefined2)param_1[1];
  DAT_2300324c = ~*param_1;
  FUN_23020a2c();
  local_40 = DAT_23003244;
  FUN_23020c44(auStack_44);
  DAT_23003234 = 2;
  DAT_2300323e = 3;
  FUN_230211c8(0);
  FUN_23021114(&DAT_230030d9);
  FUN_23021700();
  FUN_230215c4();
  thunk_FUN_0e0612c8(0x28);
  TIMER020_S_TASKS_STOP = 1;
  TIMER020_S_TASKS_CLEAR = 1;
  TIMER020_S_PRESCALER = 0;
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
  thunk_FUN_0e0612f0(0x28,1,0);
  DAT_e000e428 = 0x20;
  _DAT_e000e284 = 0x100;
  thunk_FUN_0e0612ac(0x28);
  thunk_FUN_0e0612f0(0x5c,1,0);
  DAT_e000e45c = 0x60;
  _DAT_e000e288 = 0x10000000;
  thunk_FUN_0e0612ac(0x5c);
  thunk_FUN_0e0612f0(0x5b,1,0);
  DAT_e000e45b = 0x60;
  _DAT_e000e288 = 0x8000000;
  thunk_FUN_0e0612ac(0x5b);
  return;
}


