/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ae068. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0ae068(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_0e0ae054();
  uVar1 = (undefined4)((ulonglong)uVar3 >> 0x20);
  if ((int)((uint)*(ushort *)(&DAT_2f01137c + ((int)uVar3 + 8) * 2) << 0x17) < 0) {
    uVar2 = (*(ushort *)(&DAT_2f01137c + ((int)uVar3 + 8) * 2) & 0x1fff) >> 9;
    (**(code **)(&DAT_2f01137c + uVar2 * 8))
              (param_1,uVar1,*(undefined4 *)(&DAT_2f011380 + uVar2 * 8));
  }
  if (_DAT_2f011384 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e0ae09e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_DAT_2f011384)(param_1,uVar1,_DAT_2f011388);
    return;
  }
  return;
}


