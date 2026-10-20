/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230201b4. Types and names are inferred; NOT original source. */

void FUN_230201b4(uint param_1,int param_2)

{
  ushort uVar1;
  undefined2 local_20;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  local_1c = 0;
  uStack_18 = 0;
  local_14 = 0;
  uVar1 = (ushort)(1 << (param_1 & 0xff));
  local_1d = (undefined1)param_1;
  if (param_2 == 1) {
    if (param_1 == 1) {
      local_20 = 0x905;
      local_1d = 1;
    }
    else {
      local_20 = 0x3509;
    }
    DAT_23002c80 = DAT_23002c80 | uVar1;
    local_1e = 3;
    FUN_230268b0(4,&local_20,0x10);
    FUN_2302060c(param_1 & 0xff);
    return;
  }
  if (param_1 == 1) {
    local_20 = 0x905;
    local_1d = 1;
  }
  else {
    local_20 = 0x3509;
  }
  DAT_23002c80 = DAT_23002c80 & ~uVar1;
  local_1e = 2;
  FUN_230268b0(4,&local_20,0x10);
  FUN_23025b40(0xff,0);
  thunk_FUN_230207a4(0);
  return;
}


