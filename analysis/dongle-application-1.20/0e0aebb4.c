/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0aebb4. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0aebb4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 uStack_c;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  uStack_a = (undefined2)((uint)param_2 >> 0x10);
  if (DAT_2f011b54 == '\0') {
    uVar1 = 1;
  }
  else {
    local_e = (undefined2)param_1;
    uStack_c = (undefined2)((uint)param_1 >> 0x10);
    local_10 = 0x204;
    uStack_8 = param_3;
    uVar1 = FUN_0e0b2190(&local_10,6);
  }
  return uVar1;
}


