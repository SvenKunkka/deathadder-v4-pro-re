/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07e1d8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e07e1d8(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = DAT_0e07e210;
  iVar2 = FUN_0e094688(*DAT_0e07e210);
  if (iVar2 == 0) {
    return 0xffffffed;
  }
  iVar2 = (**(code **)(*(int *)(*piVar1 + 8) + 8))(*piVar1,DAT_0e07e214);
  piVar1[1] = iVar2;
  if (-1 < iVar2) {
                    /* WARNING: Could not recover jumptable at 0x0e07e200. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*(code *)**(undefined4 **)(*piVar1 + 8))(*piVar1,2);
    return uVar3;
  }
  return 0xfffffff2;
}


