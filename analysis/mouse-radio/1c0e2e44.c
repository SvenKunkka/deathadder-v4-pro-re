/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e2e44. Types and names are inferred; NOT original source. */

void FUN_1c0e2e44(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  code *pcVar4;
  
  iVar1 = DAT_1c0e2eb0;
  if (**(int **)(DAT_1c0e2eb0 + 0x10) << 0x18 < 0) {
    pcVar4 = *(code **)(*(int *)(DAT_1c0e2eb0 + 8) + 0x10);
  }
  else {
    pcVar4 = *(code **)(*(int *)(DAT_1c0e2eb0 + 8) + 0xc);
  }
  (*pcVar4)(DAT_1c0e2eb0,0x80);
  if (**(int **)(iVar1 + 0x10) << 0x1c < 0) {
    pcVar4 = *(code **)(*(int *)(iVar1 + 8) + 0x10);
  }
  else {
    pcVar4 = *(code **)(*(int *)(iVar1 + 8) + 0xc);
  }
  (*pcVar4)(DAT_1c0e2eb0,8);
  if (**(int **)(iVar1 + 0x10) << 0x19 < 0) {
    pcVar4 = *(code **)(*(int *)(iVar1 + 8) + 0x10);
  }
  else {
    pcVar4 = *(code **)(*(int *)(iVar1 + 8) + 0xc);
  }
  (*pcVar4)(DAT_1c0e2eb0,0x40);
  iVar2 = thunk_EXT_FUN_0e094688(DAT_1c0e2eb0);
  if (iVar2 != 0) {
    puVar3 = *(undefined4 **)(iVar1 + 8);
    **(uint **)(iVar1 + 0x10) = **(uint **)(iVar1 + 0x10) & 0xffffffdf;
                    /* WARNING: Could not recover jumptable at 0x1c0e2eac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*puVar3)(DAT_1c0e2eb0,5,DAT_1c0e2eb4);
    return;
  }
  return;
}


