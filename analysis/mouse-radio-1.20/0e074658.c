/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e074658. Types and names are inferred; NOT original source. */

void FUN_0e074658(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint local_1c;
  
  uVar5 = (uint)DAT_23001502;
  uVar2 = FUN_230263ac(&DAT_0e097840,&local_1c);
  if (uVar2 == 0) {
    if (((DAT_23007088 ^ local_1c) & 0x20) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  iVar3 = FUN_230263ac(&DAT_0e097840,&local_1c);
  if (iVar3 == 0) {
    if (((local_1c ^ DAT_23007088) & 0x400) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
    }
  }
  iVar4 = FUN_230263ac(&DAT_0e09782c,&local_1c);
  cVar1 = DAT_2300777a;
  if (iVar4 == 0) {
    if (((DAT_2300707c ^ local_1c) & 0x800) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = 1;
    }
  }
  if (((uVar2 | iVar3 << 2 | iVar4 << 4) & uVar5) != 0) {
    DAT_230076ca = 5000;
    DAT_2300777a = 0;
    return;
  }
  if ((DAT_230076ca == 0) && (DAT_2300777a == '\0')) {
    DAT_2300777a = 1;
    DAT_23007729 = 1;
    thunk_FUN_0e09739c(&DAT_23004958,&DAT_0e099058,0x54);
    thunk_FUN_0e09739c(&DAT_23004474,&DAT_0e098b74,0x4e4);
    FUN_0e072f9c();
    iVar3 = (uint)DAT_23004477 * 0xf4;
    thunk_FUN_0e09739c(&DAT_23006660,&DAT_23004505 + (uint)DAT_23004477 * 0xf4,0x80);
    thunk_FUN_0e08042c(*(undefined2 *)(&DAT_230044ca + iVar3),*(undefined2 *)(&DAT_230044cc + iVar3)
                      );
    thunk_FUN_0e07d4ac(2,0);
    thunk_FUN_0e07d4ac(8,DAT_23004477);
    DAT_23007719 = 1;
    DAT_23007717 = 0x8f;
    thunk_FUN_0e080538();
    DAT_230077ba = cVar1;
    DAT_230077bb = cVar1;
    DAT_230077b9 = cVar1;
    DAT_230077b7 = cVar1;
    DAT_230077b8 = cVar1;
    FUN_0e078bcc();
    FUN_0e078bfc(0);
    thunk_FUN_0e0803e4(10,3);
    return;
  }
  return;
}


