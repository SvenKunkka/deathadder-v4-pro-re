/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e4da4. Types and names are inferred; NOT original source. */

int FUN_0e0e4da4(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined1 auStack_38 [36];
  
  iVar1 = FUN_0e0e712a();
  if ((iVar1 == 0) && (iVar1 = FUN_0e0e4d90(), iVar1 != 0)) {
    iVar1 = FUN_0e0e68fe(0x2f011278,param_1,param_2);
    uVar2 = (uint)(iVar1 == 0);
LAB_0e0e4dcc:
    iVar1 = uVar2 << 1;
  }
  else {
    if (param_2 < 0x21) {
      local_3c = 0x5c;
      local_3a = (undefined2)param_2;
      FUN_0e0e74b6(auStack_38,param_1,param_2);
      iVar1 = FUN_0e0e5164(0x2f0112e8,&local_3c,param_3,param_4);
      if (iVar1 == 0) {
        iVar1 = FUN_0e0e4d90();
        if (iVar1 == 0) {
          return 0;
        }
        uVar2 = FUN_0e0e56ac(0x2f0118c0);
        uVar2 = uVar2 >> 0x1f;
        goto LAB_0e0e4dcc;
      }
    }
    iVar1 = 2;
  }
  return iVar1;
}


