/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302b224. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * ram_candidate_2302b224(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint local_1c [2];
  
  if (_DAT_5f9b2144 != 0) {
    _DAT_5f9b2144 = 0;
    iVar1 = FUN_230263ac(&DAT_0e097840,local_1c);
    if (iVar1 == 0) {
      if (((local_1c[0] ^ DAT_23007088) & 0x20) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
      }
    }
    iVar2 = FUN_230263ac(&DAT_0e097840,local_1c);
    if (iVar2 == 0) {
      if (((DAT_23007088 ^ local_1c[0]) & 0x10) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = 1;
      }
    }
    iVar3 = FUN_230263ac(&DAT_0e097840,local_1c);
    if (iVar3 == 0) {
      if (((DAT_23007088 ^ local_1c[0]) & 0x400) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = 1;
      }
    }
    iVar4 = FUN_230263ac(&DAT_0e09782c,local_1c);
    if (iVar4 == 0) {
      if (((DAT_2300707c ^ local_1c[0]) & 0x400) == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = 1;
      }
    }
    iVar5 = FUN_230263ac(&DAT_0e09782c,local_1c);
    if (iVar5 == 0) {
      if (((DAT_2300707c ^ local_1c[0]) & 0x800) == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = 1;
      }
    }
    iVar6 = FUN_230263ac(&DAT_0e097840,local_1c);
    if (iVar6 == 0) {
      if (((local_1c[0] ^ DAT_23007088) & 8) == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = 1;
      }
    }
    DAT_23001502 = (ushort)iVar1 | (ushort)(iVar2 << 1) | (ushort)(iVar3 << 2) |
                   (ushort)(iVar4 << 3) | (ushort)(iVar5 << 4) | (ushort)(iVar6 << 5);
    DAT_230076d0 = DAT_23001502;
    FUN_2302944c(&DAT_0e0991b0,0x22,0);
    thunk_FUN_0e0952ec(&DAT_23006764);
  }
  thunk_FUN_0e089ea4();
  thunk_FUN_0e089908();
  return &stack0x00000000;
}


