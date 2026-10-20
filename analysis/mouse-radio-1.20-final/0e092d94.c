/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e092d94. Types and names are inferred; NOT original source. */

/* WARNING: Switch with 1 destination removed at 0x0e092db8 */
/* WARNING: Exceeded maximum restarts with more pending */

void FUN_0e092d94(ushort *param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined1 uStack_c;
  ushort uStack_b;
  
  if ((*param_1 & 0x8000) == 0) {
    uVar2 = (*param_1 & 0x3fff) >> 8;
    if ((uVar2 < 10) && (*(int *)(&DAT_0e09b810 + uVar2 * 4) != 0)) {
      if ((pcRam230074b8 == (code *)0x0) || (cRam230074bc == '\0')) {
        return;
      }
      uVar1 = *param_1;
      if ((uVar1 & 0x4000) != 0) {
        uStack_c = 1;
        (*pcRam230074b8)(&uStack_c,*(undefined4 *)(param_1 + 1));
        return;
      }
      uStack_b = param_1[3];
      if (uVar1 == 1) {
        uStack_c = 2;
        (*pcRam230074b8)(&uStack_c,*(undefined4 *)(param_1 + 1));
        return;
      }
      if (uVar1 - 3 < 2) {
        uStack_c = 0;
        (*pcRam230074b8)(&uStack_c,*(undefined4 *)(param_1 + 1));
      }
      return;
    }
  }
  else {
    FUN_0e092d90(param_1 + 3,param_2 + -6);
  }
  return;
}


