/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230233b0. Types and names are inferred; NOT original source. */

void FUN_230233b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (DAT_23003468 == 0xb) {
    if (DAT_2300341c == 1) {
      if (param_1 != 4) {
        if (param_1 == 1) {
          DAT_23003468 = 0xc;
          FUN_23023268();
          return;
        }
        if (param_1 != 2) {
          return;
        }
        goto LAB_2302345a;
      }
LAB_2302343a:
      RADIO_S_PACKETPTR = 0x23003050;
      DAT_23003050._0_1_ = 0;
      DAT_23003468 = 0xc;
      return;
    }
    if (param_1 == 4) goto LAB_2302343a;
  }
  else {
    if (DAT_23003468 != 0xc) {
      return;
    }
    if (DAT_2300341c != 1) {
      if (param_1 != 1) {
        if (param_1 != 5) {
          return;
        }
        if ((byte)DAT_23003050 - 1 < 0xc) {
          return;
        }
        FUN_23020f1c(&DAT_23003468,&RADIO_S_TASKS_STOP,0xb,(byte)DAT_23003050 - 1,param_4);
        if (DAT_230032d0 < 2) {
          DAT_2300348a = 1;
        }
        else {
          FUN_23023708(1);
        }
        return;
      }
      goto LAB_230233de;
    }
    if (param_1 == 2) {
LAB_2302345a:
      FUN_23020f1c(&DAT_23003468,&RADIO_S_TASKS_STOP,0xb);
      return;
    }
    if (param_1 == 5) {
      if ((byte)DAT_23003050 - 1 < 0xc) {
        return;
      }
      FUN_23020f1c(&DAT_23003468,&RADIO_S_TASKS_STOP,0xb);
      DAT_2300348a = 1;
      return;
    }
  }
  if (param_1 != 1) {
    return;
  }
LAB_230233de:
  FUN_23023268();
  return;
}


