/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06af8c. Types and names are inferred; NOT original source. */

/* WARNING: Switch with 1 destination removed at 0x0e06afb0 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Exceeded maximum restarts with more pending */

void FUN_0e06af8c(ushort *param_1,int param_2)

{
  ushort uVar1;
  code *pcVar2;
  uint uVar3;
  undefined1 uStack_c;
  ushort uStack_b;
  
  if ((*param_1 & 0x8000) == 0) {
    uVar3 = (*param_1 & 0x3fff) >> 8;
    if ((uVar3 < 10) && (*(int *)(DAT_0e06afbc + uVar3 * 4) != 0)) {
      pcVar2 = (code *)*_UNK_0e06ad50;
      if ((pcVar2 == (code *)0x0) || (*(char *)(_UNK_0e06ad50 + 1) == '\0')) {
        return;
      }
      uVar1 = *param_1;
      if ((uVar1 & 0x4000) != 0) {
        uStack_c = 1;
        (*pcVar2)(&uStack_c,*(undefined4 *)(param_1 + 1));
        return;
      }
      uStack_b = param_1[3];
      if (uVar1 == 1) {
        uStack_c = 2;
        (*pcVar2)(&uStack_c,*(undefined4 *)(param_1 + 1));
        return;
      }
      if (uVar1 - 3 < 2) {
        uStack_c = 0;
        (*pcVar2)(&uStack_c,*(undefined4 *)(param_1 + 1));
      }
      return;
    }
  }
  else {
    FUN_0e06af88(param_1 + 3,param_2 + -6);
  }
  return;
}


