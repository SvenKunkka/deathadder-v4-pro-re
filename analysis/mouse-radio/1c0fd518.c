/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0fd518. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0fd518(int param_1,int param_2)

{
  switch(*(undefined1 *)(param_2 + 0x20)) {
  case 0:
    if (*(int *)(param_2 + 0x10) != *(int *)(param_1 + 0x744)) {
LAB_1c0fd540:
      *(undefined4 *)(param_1 + 0x500) = 0;
      *(undefined4 *)(param_1 + 0x500) = 6;
      return 0;
    }
    break;
  case 1:
    if (*(int *)(param_2 + 0x10) != *(int *)(param_1 + 0x70c)) goto LAB_1c0fd540;
    break;
  case 2:
    if ((*(int *)(param_2 + 0x10) != *(int *)(param_1 + 0x744)) ||
       (*(int *)(param_2 + 0x18) != *(int *)(param_1 + 0x70c))) goto LAB_1c0fd540;
    break;
  case 3:
    if (((*(int *)(param_2 + 8) << 0x15 < 0) &&
        (*(int *)(param_2 + 0x10) != *(int *)(param_1 + 0x744))) ||
       ((-1 < *(int *)(param_2 + 8) << 0x15 &&
        (*(int *)(param_2 + 0x18) != *(int *)(param_1 + 0x744))))) goto LAB_1c0fd540;
  }
  return 1;
}


