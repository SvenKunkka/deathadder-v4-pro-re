/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06af94. Types and names are inferred; NOT original source. */

int FUN_0e06af94(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined1 auStack_38 [36];
  
  iVar1 = FUN_0e06d830();
  if ((iVar1 == 0) && (DAT_23000b28 == 1)) {
    iVar1 = FUN_0e05edcc(&DAT_23000b20,param_1,param_2);
    iVar1 = (uint)(iVar1 == 0) << 1;
  }
  else {
    if (param_2 < 0x21) {
      local_3a = (undefined2)param_2;
      local_3c = 0x5c;
      FUN_0e06f35c(auStack_38,param_1,param_2);
      iVar1 = FUN_0e06cbdc(&DAT_23001c04,&local_3c,param_3,param_4);
      if (iVar1 == 0) {
        if (DAT_23000b28 != 1) {
          return 0;
        }
        uVar2 = FUN_0e06d43c(&DAT_23007000);
        return (uVar2 >> 0x1f) << 1;
      }
    }
    iVar1 = 2;
  }
  return iVar1;
}


