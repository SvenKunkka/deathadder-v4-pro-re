/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f60d0. Types and names are inferred; NOT original source. */

void FUN_1c0f60d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = DAT_1c0f610c;
  uVar3 = *(undefined4 *)(param_1 + 0x84);
  *(int *)(DAT_1c0f6108 + 8) = param_1;
  *puVar2 = uVar3;
  setProcStackPointerLimit(*(undefined4 *)(param_1 + 0x74));
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setProcessStackPointer(param_2);
  }
  (*DAT_1c0f6110)(0);
                    /* WARNING: Could not recover jumptable at 0x1c0f6106. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_1c0f6114)(param_3,0,0,0);
  return;
}


