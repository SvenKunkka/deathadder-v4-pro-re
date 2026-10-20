/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302bbd4. Types and names are inferred; NOT original source. */

void ram_candidate_2302bbd4(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  
  switch(*param_2) {
  case 0:
    if ((DAT_230077a4 != '\0') && (iVar1 = thunk_FUN_0e08afa8(), iVar1 != 0)) {
      thunk_FUN_0e08aef8(param_1);
    }
    DAT_230077a2 = 1;
    if (DAT_2300772a != '\0') {
      DAT_2300773f = DAT_2300773f | 2;
      thunk_FUN_0e094f80(&DAT_230016c4);
    }
    DAT_2300779d = 0;
    return;
  case 1:
    if ((DAT_230077a4 != '\0') && (iVar1 = thunk_FUN_0e08afa8(), iVar1 != 0)) {
      thunk_FUN_0e08af60(param_1);
    }
    if (DAT_230077a1 != '\0') {
      DAT_23007724 = 0;
    }
    DAT_230077a2 = 0;
    DAT_230077a1 = '\0';
    DAT_230077a0 = 0;
    DAT_2300779d = 0;
    break;
  case 2:
    DAT_230077a0 = 0;
    if (DAT_2300772a != '\0') {
      thunk_FUN_0e094f80(&DAT_230016c4);
      return;
    }
    break;
  case 3:
    DAT_230077a0 = 1;
    return;
  case 4:
    DAT_230077a1 = 0;
    DAT_230077a0 = 0;
    return;
  case 5:
    DAT_230077a1 = '\x01';
    DAT_2300772c = 1;
    if (DAT_23007736 != '\0') {
      DAT_2300772d = 1;
      DAT_23007690 = 0;
      DAT_2300772c = 0;
      return;
    }
  }
  return;
}


