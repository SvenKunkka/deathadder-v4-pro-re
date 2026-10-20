/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230203fc. Types and names are inferred; NOT original source. */

void FUN_230203fc(int param_1,undefined1 *param_2,char param_3)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = 0;
  uStack_14 = 0;
  local_10 = 0;
  uStack_c = 0;
  if (param_1 == 2) {
    if ((DAT_23002c80 != 0) && (DAT_23002c82 == 1)) {
      DAT_230071b3 = *param_2;
      FUN_23025b40(0xe0);
      local_18 = CONCAT22(CONCAT11(local_18._3_1_,DAT_230071b3),0x5605);
      FUN_230268b0(4,&local_18,0x10);
    }
  }
  else {
    if (param_1 == 99) {
      FUN_230268b0(4,param_2,param_3);
      return;
    }
    if (param_1 == 1) {
      local_18 = 0x72fe05;
      thunk_FUN_0e06f35c((int)&local_18 + 3);
      FUN_230268b0(4,&local_18,param_3 + '\x03');
      return;
    }
  }
  return;
}


