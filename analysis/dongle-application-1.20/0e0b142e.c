/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b142e. Types and names are inferred; NOT original source. */

undefined4
FUN_0e0b142e(undefined4 *param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined4 uVar1;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 uStack_11;
  
  uVar1 = *param_1;
  uStack_11 = (undefined1)((uint)param_2 >> 0x18);
  _local_14 = CONCAT12(param_4,CONCAT11(param_3,(char)param_2));
  FUN_0e0af598(param_1 + 0x1e,param_2,0xffffffff,0xffffffff,param_1);
  uVar1 = FUN_0e0b18be(uVar1,param_1 + 2,&local_14,3);
  thunk_FUN_0e0af688(param_1 + 0x1e);
  return uVar1;
}


