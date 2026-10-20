/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230285ac. Types and names are inferred; NOT original source. */

void FUN_230285ac(void)

{
  int iVar1;
  code *pcVar2;
  
  if (DAT_23007740 == '\0') {
    return;
  }
  FUN_2302a71c();
  iVar1 = thunk_FUN_0e094560(&DAT_0e097840);
  if (iVar1 != 0) {
    FUN_2302624c(&DAT_0e097840,10,0x1400000,0x2000000);
  }
  iVar1 = thunk_FUN_0e094560(&DAT_0e09782c);
  if (iVar1 != 0) {
    FUN_2302624c(&DAT_0e09782c,10,0x1400000,0x2000000);
  }
  iVar1 = thunk_FUN_0e094560(&DAT_0e09782c);
  if (iVar1 != 0) {
    FUN_2302624c(&DAT_0e09782c,0xb,0x1400000,0x2000000);
  }
  iVar1 = thunk_FUN_0e094560(&DAT_0e097840);
  if (iVar1 != 0) {
    FUN_2302624c(&DAT_0e097840,3,0x1400000,0x2000000);
  }
  if (((DAT_230077c1 != '\0') && (iVar1 = thunk_FUN_0e094560(DAT_23000e14), iVar1 != 0)) &&
     (pcVar2 = *(code **)(*(int *)(DAT_23000e14 + 8) + 0x18), pcVar2 != (code *)0x0)) {
    (*pcVar2)(DAT_23000e14,DAT_23000e18,0x1400000,0x2000000);
    return;
  }
  return;
}


