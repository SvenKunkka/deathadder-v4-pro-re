/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05cbc4. Types and names are inferred; NOT original source. */

void FUN_0e05cbc4(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  
  FUN_0e05caec();
  puVar1 = DAT_0e05cc3c;
  if (param_1 == 0xf) {
    uVar2 = 0x7e;
  }
  else {
    if (param_3 == 0) {
      *DAT_0e05cc3c = 0xff;
      goto joined_r0x0e05cc00;
    }
    uVar2 = (undefined1)param_3;
  }
  *DAT_0e05cc3c = uVar2;
joined_r0x0e05cc00:
  if (param_2 == 1) {
    FUN_0e06f446(puVar1 + 1,0xf0,0xff);
    *(undefined1 **)(DAT_0e05cc40 + 0xed0) = puVar1;
    return;
  }
  if (param_2 != 2) {
    if (param_2 == 0) {
      FUN_0e0622b8(puVar1 + 1,0xff);
      *(undefined1 **)(DAT_0e05cc40 + 0xed0) = puVar1;
      return;
    }
    FUN_0e06f446(puVar1 + 1,param_2,0xff);
    *(undefined1 **)(DAT_0e05cc40 + 0xed0) = puVar1;
    return;
  }
  FUN_0e06f446(puVar1 + 1,0xcc,0xff);
  *(undefined1 **)(DAT_0e05cc40 + 0xed0) = puVar1;
  return;
}


