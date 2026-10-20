/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091518. Types and names are inferred; NOT original source. */

undefined4 FUN_0e091518(int param_1,int param_2)

{
  switch(*(undefined1 *)(param_2 + 0x20)) {
  case 0:
    if (*(int *)(param_2 + 0x10) != *(int *)(param_1 + 0x744)) {
LAB_0e091540:
      *(undefined4 *)(param_1 + 0x500) = 0;
      *(undefined4 *)(param_1 + 0x500) = 6;
      return 0;
    }
    break;
  case 1:
    if (*(int *)(param_2 + 0x10) != *(int *)(param_1 + 0x70c)) goto LAB_0e091540;
    break;
  case 2:
    if ((*(int *)(param_2 + 0x10) != *(int *)(param_1 + 0x744)) ||
       (*(int *)(param_2 + 0x18) != *(int *)(param_1 + 0x70c))) goto LAB_0e091540;
    break;
  case 3:
    if (((*(int *)(param_2 + 8) << 0x15 < 0) &&
        (*(int *)(param_2 + 0x10) != *(int *)(param_1 + 0x744))) ||
       ((-1 < *(int *)(param_2 + 8) << 0x15 &&
        (*(int *)(param_2 + 0x18) != *(int *)(param_1 + 0x744))))) goto LAB_0e091540;
  }
  return 1;
}


