/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23022204. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23022204(void)

{
  dword dVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = DAT_23003256;
  if (DAT_23003230 != 5) {
    if (DAT_23003250 != '\0') {
      DAT_23003250 = 0;
      DAT_23003256 = 1;
      thunk_FUN_0e06d0d0(&DAT_23001c54);
      return;
    }
    uVar3 = (uint)DAT_23003256;
    if (uVar3 == 0) {
      if (DAT_23003258 != '\0') {
        if ((char)DAT_2300325a != '\0') {
          thunk_FUN_0e0612c8(0x28);
          _DAT_e000e284 = 0x100;
          TIMER020_S_TASKS_CLEAR = 1;
          TIMER020_S_TASKS_START = 1;
          thunk_FUN_0e0612ac(0x28);
          _DAT_2300325a = CONCAT12(bVar2,0x100);
          DAT_23003264 = uVar3;
          return;
        }
        if (DAT_2300325a._1_1_ == '\0') {
          if (DAT_2300325c != '\0') {
            dVar1 = TIMER020_S_CC_7;
            if (dVar1 - 0x6e1 < 0x63f) {
              DAT_23003278 = DAT_23003278 + 1;
              DAT_23003270 = DAT_23003270 + dVar1;
            }
            if (0x1f < DAT_23003278) {
              uVar3 = DAT_23003270 >> 5;
              if (uVar3 < 0xa01) {
                if ((uVar3 != 0xa00) && (0x1f < 0xa00 - uVar3)) {
                  dVar1 = TIMER020_S_CC_0;
                  TIMER020_S_CC_0 = dVar1 - 0x20;
                }
              }
              else if (0x1f < uVar3 - 0xa00) {
                dVar1 = TIMER020_S_CC_0;
                TIMER020_S_CC_0 = dVar1 + 0x20;
              }
              DAT_23003270 = 0;
              DAT_23003278 = 0;
              return;
            }
          }
        }
        else {
          DAT_23003264 = DAT_23003264 + 1;
          if (0x20 < (int)DAT_23003264) {
            _DAT_2300325a = 0x10000;
            return;
          }
        }
      }
    }
    else {
      DAT_23003264 = DAT_23003264 + 1;
      if (0x40 < (int)DAT_23003264) {
        DAT_23003256 = DAT_23003250;
        DAT_23003258 = 1;
        thunk_FUN_0e06d0d0(&DAT_23001c54);
        return;
      }
    }
  }
  return;
}


