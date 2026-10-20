/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23027400. Types and names are inferred; NOT original source. */

void ram_candidate_23027400(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined1 *unaff_r5;
  undefined2 *unaff_r6;
  uint unaff_r7;
  
  *unaff_r6 = (short)(unaff_r7 & param_3);
  if ((unaff_r7 & param_3) == 0) {
    uVar1 = 0;
    do {
      if (((int)(uint)DAT_230076be >> (uVar1 & 0xff)) << 0x1f < 0) {
        FUN_23027170(0,uVar1);
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 != 8);
    DAT_230076be = 0;
    *unaff_r5 = 0;
    ram_candidate_23027290();
    return;
  }
  return;
}


