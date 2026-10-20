/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06256c. Types and names are inferred; NOT original source. */

int FUN_0e06256c(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)(param_1 + 0x48)) {
    while( true ) {
      if (piVar1 == (int *)0x0) {
        return 0;
      }
      if (*(byte *)((int)piVar1 + 0x11) == param_2) {
        if (param_2 == 3) {
          if (*(byte *)(piVar1 + 2) == param_3) {
            return (int)piVar1;
          }
        }
        else if (param_2 == 0xf) {
          return (int)piVar1;
        }
      }
      if (piVar1 == (int *)*(int *)(param_1 + 0x4c)) break;
      piVar1 = (int *)*piVar1;
    }
  }
  return 0;
}


