/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f8718. Types and names are inferred; NOT original source. */

void FUN_1c0f8718(void)

{
  int iVar1;
  int *piVar2;
  uint in_r3;
  
  iVar1 = FUN_1c0f8400();
  if (iVar1 != 0) {
    for (piVar2 = *(int **)(iVar1 + 0xc);
        (piVar2 != (int *)0x0 && ((1 << (in_r3 & 0xff) & piVar2[4]) == 0)); piVar2 = (int *)*piVar2)
    {
    }
  }
  return;
}


