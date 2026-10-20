/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0902b4. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0902b4(int param_1,uint param_2,undefined4 param_3,uint param_4,undefined1 param_5)

{
  int iVar1;
  undefined4 uVar2;
  byte local_1c;
  undefined1 local_1b;
  undefined2 local_1a;
  undefined2 uStack_18;
  undefined2 local_16;
  undefined2 uStack_14;
  undefined2 local_12;
  undefined2 uStack_10;
  undefined2 local_e;
  undefined2 uStack_c;
  undefined2 local_a;
  
  local_1b = param_5;
  local_12 = 0;
  uStack_c = 0;
  uStack_10 = (undefined2)param_3;
  local_e = (undefined2)((uint)param_3 >> 0x10);
  local_1c = (byte)param_2 & 1;
  local_1a = 0;
  uStack_14 = 0;
  local_a = 0;
  uStack_18 = (undefined2)param_4;
  local_16 = (undefined2)(param_4 >> 0x10);
  if (*(ushort *)(*(int *)(param_1 + 4) + 0x2c) < param_4) {
    uVar2 = 0xffffffe4;
  }
  else {
    iVar1 = FUN_0e091818(*(int *)(param_1 + 4),&local_1c,(((param_2 ^ 2) & 3) >> 1) << 5);
    if (iVar1 == 0xbad0000) {
      return 0;
    }
    if (iVar1 == 0xbad000b) {
      uVar2 = 0xfffffff0;
    }
    else {
      uVar2 = 0xfffffffb;
    }
  }
  return uVar2;
}


