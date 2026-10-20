/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0af1a8. Types and names are inferred; NOT original source. */

void FUN_0e0af1a8(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(&PTR_DAT_0e0b3d40)[param_1 + 1];
  for (puVar1 = (undefined4 *)(&PTR_DAT_0e0b3d40)[param_1]; puVar1 < puVar2; puVar1 = puVar1 + 2) {
    if (puVar1[1] == 0) {
      (*(code *)*puVar1)();
    }
    else {
      FUN_0e0b2216(puVar1);
    }
  }
  return;
}


