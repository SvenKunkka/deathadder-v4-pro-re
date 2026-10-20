/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06e408. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e06e408(int param_1,int param_2)

{
  undefined2 uVar1;
  char cVar2;
  uint uVar3;
  undefined1 local_20;
  char local_1f;
  ushort local_1e;
  
  cVar2 = DAT_230076ee;
  if (param_2 - 1U < 0x40) {
    uVar1 = (undefined2)param_2;
    local_1f = (char)param_2;
    if (DAT_23002794 < 3) {
      (&DAT_230029ac)[param_1 * 0x770] = uVar1;
      if (param_2 == 1) {
        if (DAT_230076ee == '\0') {
          DAT_230076ee = local_1f;
          _DAT_5302e040 = param_2;
        }
      }
      else if (DAT_230076ee != '\0') {
        _DAT_5302e044 = 1;
        DAT_230076ee = '\0';
      }
    }
    else if ((&DAT_230029ac)[param_1 * 0x770] == 0) {
      (&DAT_230029ac)[param_1 * 0x770] = uVar1;
      if (param_2 == 1) {
        if (cVar2 == '\0') {
          DAT_230076ee = local_1f;
          _DAT_5302e040 = param_2;
        }
      }
      else if (cVar2 != '\0') {
        _DAT_5302e044 = 1;
        DAT_230076ee = '\0';
      }
    }
    else {
      uVar3 = DAT_23002a0a + 100;
      local_1e = (ushort)((uVar3 & 0xff) << 8) | (ushort)(uVar3 >> 8) & 0xff;
      local_20 = 0x2f;
      FUN_0e06dd48(param_1,0,&local_20,4,0xff);
      *(undefined2 *)(&DAT_230029ae + param_1 * 0xee0) = uVar1;
      *(short *)(&DAT_230029b0 + param_1 * 0xee0) = (short)uVar3;
    }
    return;
  }
  return;
}


