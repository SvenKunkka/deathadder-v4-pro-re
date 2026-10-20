/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091420. Types and names are inferred; NOT original source. */

void FUN_0e091420(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(DAT_0e091510 + 0x110) == 0) {
    iVar2 = *(int *)(DAT_0e091510 + 0x114);
    uVar3 = 0;
  }
  else {
    *(undefined4 *)(DAT_0e091510 + 0x110) = 0;
    uVar3 = 0x10;
    iVar2 = *(int *)(DAT_0e091510 + 0x114);
  }
  if (iVar2 == 0) {
    iVar2 = *(int *)(DAT_0e091510 + 0x11c);
  }
  else {
    *(undefined4 *)(DAT_0e091510 + 0x114) = 0;
    uVar3 = uVar3 | 0x20;
    iVar2 = *(int *)(DAT_0e091510 + 0x11c);
  }
  if (iVar2 == 0) {
    iVar2 = *(int *)(DAT_0e091510 + 0x104);
  }
  else {
    *(undefined4 *)(DAT_0e091510 + 0x11c) = 0;
    uVar3 = uVar3 | 0x80;
    iVar2 = *(int *)(DAT_0e091510 + 0x104);
  }
  if (iVar2 != 0) {
    *(undefined4 *)(DAT_0e091510 + 0x104) = 0;
    uVar3 = uVar3 | 2;
  }
  if ((((int)(uVar3 << 0x1b) < 0) && ((int)(DAT_0e091514[3] << 0x1d) < 0)) &&
     ((code *)*DAT_0e091514 != (code *)0x0)) {
    (*(code *)*DAT_0e091514)(1,DAT_0e091514[1]);
  }
  if ((((int)(uVar3 << 0x1a) < 0) && ((int)(DAT_0e091514[3] << 0x1c) < 0)) &&
     ((code *)*DAT_0e091514 != (code *)0x0)) {
    (*(code *)*DAT_0e091514)(2,DAT_0e091514[1]);
  }
  if ((((int)(uVar3 << 0x18) < 0) && ((DAT_0e091514[3] & 0x10) == 0)) &&
     ((code *)*DAT_0e091514 != (code *)0x0)) {
    (*(code *)*DAT_0e091514)(0,DAT_0e091514[1]);
  }
  puVar1 = DAT_0e091514;
  if (iVar2 != 0) {
    *(undefined4 *)(DAT_0e091510 + 0x500) = 0;
    *(undefined1 *)(puVar1 + 2) = 1;
    if ((code *)*puVar1 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e09148c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puVar1)(3,puVar1[1]);
      return;
    }
  }
  return;
}


