/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230264a0. Types and names are inferred; NOT original source. */

void ram_candidate_230264a0(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  if (param_1 < 0x140) {
    puVar3 = (&PTR_DAT_0e09b2b8)[param_1 >> 5];
    if ((puVar3 != (undefined *)0x0) &&
       (puVar1 = *(undefined4 **)(*(int *)(puVar3 + 0x10) + 4), puVar1 != (undefined4 *)0x0)) {
      puVar2 = (undefined4 *)*puVar1;
      while( true ) {
        if ((puVar1[2] & 1 << (param_1 & 0x1f)) != 0) {
          (*(code *)puVar1[1])(puVar3);
        }
        if (puVar2 == (undefined4 *)0x0) break;
        puVar1 = puVar2;
        puVar2 = (undefined4 *)*puVar2;
      }
    }
    return;
  }
  return;
}


