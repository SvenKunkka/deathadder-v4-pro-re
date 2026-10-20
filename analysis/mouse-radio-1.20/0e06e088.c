/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06e088. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e06e088(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  dword dVar1;
  undefined4 extraout_r1;
  
  thunk_FUN_0e089e48(0x2c);
  RADIO_S_TASKS_DISABLE = 1;
  RADIO_S_TIMING = 1;
  RADIO_S_TXADDRESS = 1;
  RADIO_S_RXADDRESSES = 10;
  RADIO_S_PREFIX0 = 0xc3c2c1e7;
  RADIO_S_PREFIX1 = 0xc7c6c5c4;
  RADIO_S_BASE0 = 0xeb8a542c;
  RADIO_S_BASE1 = *(dword *)(param_1 + 4);
  RADIO_S_MODE = (uint)*(byte *)(param_1 + 0x20);
  RADIO_S_TXPOWER = 0x18;
  DAT_2300261b = 0x101;
  DAT_2300261a = 3;
  DAT_23002610 = 5;
  DAT_23002618 = 0x1f;
  DAT_23002614 = 0x100;
  DAT_23002625 = 1;
  DAT_2300262c = 1;
  RADIO_S_PCNF0 = 0x1000005;
  RADIO_S_PCNF1 = 0x303001f;
  DAT_23002620 = 5;
  DAT_23002622 = 0;
  RADIO_S_CRCCNF = 0x102;
  RADIO_S_CRCPOLY = 0x11021;
  RADIO_S_CRCINIT = 0xffff;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 | 0x80001;
  DAT_23002628 = 0x102001f;
  RADIO_S_INTENSET00 = 0x108;
  RADIO_S_EVENTS_ADDRESS = 0;
  RADIO_S_EVENTS_READY = 0;
  RADIO_S_EVENTS_END = 0;
  RADIO_S_EVENTS_DISABLED = 0;
  thunk_FUN_0e089e70(0x2c,1,0);
  DAT_e000e42c = 0;
  _DAT_e000e284 = 0x1000;
  FUN_0e078e0c(0x2c,extraout_r1,0x1000,param_4);
  return;
}


