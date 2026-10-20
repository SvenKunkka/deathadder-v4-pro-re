/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0931fc. Types and names are inferred; NOT original source. */

undefined8 FUN_0e0931fc(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  uint local_18;
  uint uStack_14;
  
  local_18 = 0;
  uStack_14 = 0;
  if (param_2 < 9) {
    FUN_0e09739c(&local_18,param_1,param_2);
    if (uStack_14 == 0 && (0x17 < local_18) <= uStack_14) {
      return CONCAT44(uStack_14 - (0x17 >= local_18),1);
    }
    param_2 = uStack_14 - (0xff >= local_18);
    if (uStack_14 == 0 && (0xff < local_18) <= uStack_14) {
      uVar1 = 2;
    }
    else {
      if (uStack_14 != 0 || uStack_14 < (0xffff < local_18)) {
        if (uStack_14 == 0) {
          uVar1 = 5;
        }
        else {
          uVar1 = 9;
        }
        return CONCAT44(param_2,uVar1);
      }
      uVar1 = 3;
    }
  }
  else {
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}


