/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f3c0. Types and names are inferred; NOT original source. */

void FUN_0e07f3c0(void)

{
  undefined2 *puVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  
  if (DAT_0e07f3f4[4] != '\x01') {
    return;
  }
  if (*DAT_0e07f3f4 == '\x01') {
    uVar3 = 4;
  }
  else {
    if (*DAT_0e07f3f4 != '\0') {
      uVar2 = 0;
      goto LAB_0e07f3d4;
    }
    uVar2 = 0;
    if (DAT_0e07f3f4[2] != '\x01') goto LAB_0e07f3d4;
    uVar3 = 2;
  }
  uVar2 = 1;
  *DAT_0e07f400 = uVar3;
LAB_0e07f3d4:
  puVar1 = DAT_0e07f3fc;
  *DAT_0e07f3f8 = uVar2;
  *puVar1 = 0;
  return;
}


