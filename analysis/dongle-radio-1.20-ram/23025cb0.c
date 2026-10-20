/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025cb0. Types and names are inferred; NOT original source. */

void FUN_23025cb0(void)

{
  undefined4 in_r3;
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = &DAT_23002ca8;
  do {
    if (*(char *)((int)puVar1 + 3) != '\0') {
      FUN_23025ce0(uVar2 & 0xff,*(undefined1 *)puVar1,*(undefined1 *)((int)puVar1 + 1),
                   *(undefined1 *)((int)puVar1 + 2),in_r3);
      *(undefined1 *)((int)puVar1 + 3) = 0;
    }
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 != 3);
  return;
}


