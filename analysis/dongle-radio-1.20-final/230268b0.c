/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230268b0. Types and names are inferred; NOT original source. */

char FUN_230268b0(int param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  cVar1 = DAT_230071e4;
  if (DAT_230071e4 != '\0') {
    uVar4 = (uint)(byte)(&DAT_2300048c)[param_1];
    uVar2 = (uint)*(byte *)((int)&DAT_23006838 + uVar4);
    uVar3 = uVar2 + 1 & 0xff;
    if (uVar3 == 4) {
      if (*(byte *)((int)&DAT_23006834 + uVar4) != 0) {
        thunk_FUN_0e06f35c(&DAT_2300683c +
                           ((short)(ushort)(byte)(&DAT_2300048c)[param_1] * 4 + 3) * 0x10);
        *(undefined1 *)((int)&DAT_23006838 + uVar4) = 0;
        return cVar1;
      }
    }
    else if (uVar3 != *(byte *)((int)&DAT_23006834 + uVar4)) {
      if (uVar2 < 4) {
        thunk_FUN_0e06f35c(&DAT_2300683c + (uVar2 + uVar4 * 4) * 0x10);
        *(char *)((int)&DAT_23006838 + uVar4) = (char)(uVar2 + 1);
        return cVar1;
      }
      DAT_23006838 = 0;
      DAT_2300683a = 0;
      DAT_23006834 = 0;
      DAT_23006836 = 0;
    }
  }
  return '\0';
}


