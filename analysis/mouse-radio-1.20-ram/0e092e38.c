/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e092e38. Types and names are inferred; NOT original source. */

int FUN_0e092e38(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined1 auStack_38 [36];
  
  iVar1 = FUN_0e0956e0();
  if ((iVar1 == 0) && (DAT_230014d4 == 1)) {
    iVar1 = FUN_0e087604(&DAT_230014cc,param_1,param_2);
    iVar1 = (uint)(iVar1 == 0) << 1;
  }
  else {
    if (param_2 < 0x21) {
      local_3a = (undefined2)param_2;
      local_3c = 0x5c;
      FUN_0e09739c(auStack_38,param_1,param_2);
      iVar1 = FUN_0e094ad4(&DAT_23001654,&local_3c,param_3,param_4);
      if (iVar1 == 0) {
        if (DAT_230014d4 != 1) {
          return 0;
        }
        uVar2 = FUN_0e0952ec(&DAT_230074e0);
        return (uVar2 >> 0x1f) << 1;
      }
    }
    iVar1 = 2;
  }
  return iVar1;
}


