/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23028b9c. Types and names are inferred; NOT original source. */

void FUN_23028b9c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint local_18;
  int iStack_14;
  
  if (param_1 == 0xffffffff) {
    param_1 = 0xffffffe0;
    uVar2 = 0xf;
  }
  else {
    param_1 = param_1 & ~((int)param_1 >> 0x1f);
    uVar2 = ((int)param_1 >> 0x1f) << 5 | param_1 >> 0x1b;
    param_1 = param_1 << 5;
  }
  FUN_23029b84(&local_18);
  uVar1 = (local_18 - DAT_230021c0) + param_1;
  uVar2 = uVar2 + ((iStack_14 - DAT_230021c4) - (uint)(local_18 < DAT_230021c0)) +
                  (uint)CARRY4(local_18 - DAT_230021c0,param_1);
  if (uVar2 == 0 && (0x3f < uVar1) <= uVar2) {
    uVar1 = 0x20;
    uVar2 = 0;
  }
  else {
    uVar1 = uVar1 & 0xffffffe0;
  }
  FUN_23029adc(&DAT_230012fc,uVar1,DAT_230021c0 + uVar1,
               DAT_230021c4 + uVar2 + CARRY4(DAT_230021c0,uVar1),1);
  return;
}


