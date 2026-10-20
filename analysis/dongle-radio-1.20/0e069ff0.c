/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069ff0. Types and names are inferred; NOT original source. */

uint FUN_0e069ff0(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  dword *pdVar2;
  uint uVar3;
  uint uVar4;
  
  pdVar2 = (dword *)*param_1;
  uVar4 = pdVar2[0x144];
  if ((pdVar2 == (dword *)0x5f8e2000) || (pdVar2 == (dword *)0x5f8e3000)) {
    uVar3 = 320000;
  }
  else if ((pdVar2 == &TIMER020_S_TASKS_START) || (pdVar2 == &TIMER021_S_TASKS_START)) {
    uVar3 = 32000;
  }
  else if (pdVar2 == &TIMER022_S_TASKS_START) {
    uVar3 = 32000;
  }
  else {
    uVar3 = 16000;
  }
  uVar1 = (uint)((ulonglong)param_2 * (ulonglong)uVar3 >> 0x20);
  return uVar1 >> (uVar4 - 0x20 & 0xff) |
         (uint)((ulonglong)param_2 * (ulonglong)uVar3) >> (uVar4 & 0xff) |
         uVar1 << (0x20 - uVar4 & 0xff);
}


