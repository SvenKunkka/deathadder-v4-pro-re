/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302a56c. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x230260e2) */
/* WARNING: Removing unreachable block (ram,0x2302613a) */
/* WARNING: Removing unreachable block (ram,0x23026090) */
/* WARNING: Removing unreachable block (ram,0x23026212) */
/* WARNING: Removing unreachable block (ram,0x23026038) */
/* WARNING: Removing unreachable block (ram,0x230260fa) */
/* WARNING: Removing unreachable block (ram,0x230261b2) */
/* WARNING: Removing unreachable block (ram,0x23026102) */
/* WARNING: Removing unreachable block (ram,0x23026108) */
/* WARNING: Removing unreachable block (ram,0x2302610a) */
/* WARNING: Removing unreachable block (ram,0x2302610c) */
/* WARNING: Removing unreachable block (ram,0x23026112) */
/* WARNING: Removing unreachable block (ram,0x23026216) */
/* WARNING: Removing unreachable block (ram,0x2302609a) */
/* WARNING: Removing unreachable block (ram,0x230260c2) */
/* WARNING: Removing unreachable block (ram,0x230260ea) */
/* WARNING: Removing unreachable block (ram,0x23026076) */
/* WARNING: Removing unreachable block (ram,0x230261a0) */
/* WARNING: Removing unreachable block (ram,0x2302606e) */
/* WARNING: Removing unreachable block (ram,0x230261a6) */
/* WARNING: Removing unreachable block (ram,0x230261e0) */
/* WARNING: Removing unreachable block (ram,0x230260de) */
/* WARNING: Removing unreachable block (ram,0x23026124) */
/* WARNING: Removing unreachable block (ram,0x2302612e) */
/* WARNING: Removing unreachable block (ram,0x23026152) */
/* WARNING: Removing unreachable block (ram,0x23026160) */
/* WARNING: Removing unreachable block (ram,0x2302623c) */
/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_2302a56c(void)

{
  int iVar1;
  int iVar2;
  undefined1 uStack_3e;
  undefined1 uStack_3d;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined4 *puStack_30;
  undefined4 uStack_2c;
  
  iVar2 = thunk_FUN_0e094560(&DAT_0e09782c);
  if (iVar2 == 0) {
    iVar2 = thunk_FUN_0e094560(&DAT_0e09782c);
  }
  else {
    DAT_2300707c = DAT_2300707c & 0xfffffff7;
    FUN_23026030(&DAT_0e09782c,3,0xa0300);
    iVar2 = thunk_FUN_0e094560(&DAT_0e09782c);
  }
  if (iVar2 == 0) {
    iVar2 = thunk_FUN_0e094560(&DAT_0e09782c);
  }
  else {
    DAT_2300707c = DAT_2300707c & 0xffffffbf;
    FUN_23026030(&DAT_0e09782c,6,0xa0300);
    iVar2 = thunk_FUN_0e094560(&DAT_0e09782c);
  }
  if (iVar2 == 0) {
    iVar2 = thunk_FUN_0e094560(&DAT_0e09782c);
  }
  else {
    DAT_2300707c = DAT_2300707c & 0xffffffdf;
    FUN_23026030(&DAT_0e09782c,5,0x10000);
    iVar2 = thunk_FUN_0e094560(&DAT_0e09782c);
  }
  if (iVar2 == 0) {
    iVar2 = thunk_FUN_0e094560(&DAT_0e09782c);
  }
  else {
    DAT_2300707c = DAT_2300707c & 0xffffff7f;
    FUN_23026030(&DAT_0e09782c,7,0xa0000);
    iVar2 = thunk_FUN_0e094560(&DAT_0e09782c);
  }
  if (iVar2 == 0) {
    iVar2 = thunk_FUN_0e094560(&DAT_0e09782c);
  }
  else {
    DAT_2300707c = DAT_2300707c & 0xffffffef;
    FUN_23026030(&DAT_0e09782c,4,0x10000);
    iVar2 = thunk_FUN_0e094560(&DAT_0e09782c);
  }
  if (iVar2 == 0) {
    iVar2 = thunk_FUN_0e094560(&DAT_0e09782c);
  }
  else {
    DAT_2300707c = DAT_2300707c & 0xfffffffd;
    FUN_23026030(&DAT_0e09782c,1,0xa0000);
    iVar2 = thunk_FUN_0e094560(&DAT_0e09782c);
  }
  if (iVar2 != 0) {
    DAT_2300707c = DAT_2300707c & 0xfffffffb;
    uStack_3d = 0;
    iVar2 = FUN_2302907c(&UNK_0e09b364,0x42,&uStack_3e);
    puStack_30 = &uStack_3c;
    uStack_3c = 0;
    uStack_38 = 0;
    puStack_34 = (undefined1 *)0x0;
    uStack_2c = 0;
    iVar1 = FUN_23029184(&UNK_0e09b364,0x42,&puStack_34);
    if (iVar1 == 0xbad0000) {
      puStack_30 = (undefined4 *)0x0;
      uStack_2c = 0;
      puStack_34 = &uStack_3d;
      iVar1 = FUN_23029184(&UNK_0e09b364,0x42,&puStack_34);
      if (iVar1 == 0xbad0000) {
        if (iVar2 == 0xbad0000) {
          FUN_23029064(&UNK_0e09b364,uStack_3e);
        }
        return 0;
      }
    }
    return 0xffffffea;
  }
  return 0;
}


