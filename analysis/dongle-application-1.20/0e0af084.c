/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0af084. Types and names are inferred; NOT original source. */

int FUN_0e0af084(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined1 auStack_38 [36];
  
  iVar1 = FUN_0e0b2442();
  if ((iVar1 == 0) && (iVar1 = FUN_0e0af070(), iVar1 != 0)) {
    iVar1 = FUN_0e0b11ee(0x2f01144c,param_1,param_2);
    uVar2 = (uint)(iVar1 == 0);
LAB_0e0af0ac:
    iVar1 = uVar2 << 1;
  }
  else {
    if (param_2 < 0x21) {
      local_3c = 0x5c;
      local_3a = (undefined2)param_2;
      FUN_0e0b280e(auStack_38,param_1,param_2);
      iVar1 = FUN_0e0af444(0x2f0114c8,&local_3c,param_3,param_4);
      if (iVar1 == 0) {
        iVar1 = FUN_0e0af070();
        if (iVar1 == 0) {
          return 0;
        }
        uVar2 = FUN_0e0af98c(0x2f011b84);
        uVar2 = uVar2 >> 0x1f;
        goto LAB_0e0af0ac;
      }
    }
    iVar1 = 2;
  }
  return iVar1;
}


