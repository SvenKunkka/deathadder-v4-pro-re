/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078d24. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e07f7a6) */
/* WARNING: Removing unreachable block (ram,0x0e07f736) */
/* WARNING: Removing unreachable block (ram,0x0e07f6ca) */
/* WARNING: Removing unreachable block (ram,0x0e07f694) */
/* WARNING: Removing unreachable block (ram,0x0e07f700) */
/* WARNING: Removing unreachable block (ram,0x0e07f76e) */
/* WARNING: Removing unreachable block (ram,0x0e07f7de) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0e07f608(void)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_lr;
  
  iVar2 = FUN_0e094560(&DAT_0e097840);
  if (iVar2 == 0) {
    iVar2 = FUN_0e094560(&DAT_0e097840);
  }
  else {
    DAT_23007088 = DAT_23007088 & 0xfffffffb;
    FUN_23026030(&DAT_0e097840,2,0x60000);
    iVar2 = FUN_0e094560(&DAT_0e097840);
  }
  if (iVar2 == 0) {
    iVar2 = FUN_0e094560(&DAT_0e097840);
  }
  else {
    DAT_23007088 = DAT_23007088 & 0xffffffdf;
    FUN_23026030(&DAT_0e097840,5,0x10000);
    iVar2 = FUN_0e094560(&DAT_0e097840);
  }
  if (iVar2 == 0) {
    iVar2 = FUN_0e094560(&DAT_0e097840);
  }
  else {
    DAT_23007088 = DAT_23007088 & 0xffffffef;
    FUN_23026030(&DAT_0e097840,4,0x10000);
    iVar2 = FUN_0e094560(&DAT_0e097840);
  }
  if (iVar2 == 0) {
    iVar2 = FUN_0e094560(&DAT_0e09782c);
  }
  else {
    DAT_23007088 = DAT_23007088 & 0xfffffbff;
    FUN_23026030(&DAT_0e097840,10,0x10000);
    iVar2 = FUN_0e094560(&DAT_0e09782c);
  }
  if (iVar2 == 0) {
    iVar2 = FUN_0e094560(&DAT_0e09782c);
  }
  else {
    DAT_2300707c = DAT_2300707c & 0xfffffbff;
    FUN_23026030(&DAT_0e09782c,10,0x10000);
    iVar2 = FUN_0e094560(&DAT_0e09782c);
  }
  if (iVar2 == 0) {
    iVar2 = FUN_0e094560(&DAT_0e097840);
  }
  else {
    DAT_2300707c = DAT_2300707c & 0xfffff7ff;
    FUN_23026030(&DAT_0e09782c,0xb,0x10000);
    iVar2 = FUN_0e094560(&DAT_0e097840);
  }
  if (iVar2 != 0) {
    DAT_23007088 = DAT_23007088 & 0xfffffff7;
    FUN_23026030(&DAT_0e097840,3,0x10000);
  }
  _DAT_23006710 = 0;
  DAT_23006714 = 0;
  DAT_23006718 = 0;
  DAT_2300671c = 0;
  DAT_23006730 = 0;
  DAT_23006734 = 0;
  _DAT_23006700 = 0;
  DAT_23006704 = 0;
  DAT_23006708 = 0;
  DAT_2300670c = 0;
  DAT_230066f0 = 0;
  DAT_230066f4 = 0;
  DAT_230066f8 = 0;
  DAT_230066fc = 0;
  _DAT_23006720 = 0;
  DAT_23006724 = 0;
  DAT_23006728 = 0;
  DAT_2300672c = 0;
  DAT_230076b8 = 0;
  FUN_0e09739c(&DAT_23006660,&DAT_23004505 + (uint)DAT_23004477 * 0xf4,0x80,&DAT_23006720,unaff_r4,
               unaff_r5,unaff_r6,unaff_lr);
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 5;
    iVar2 = iVar2 + 1;
    (&DAT_23006638)[iVar1] = 0;
    (&DAT_23006639)[iVar1] = 0;
    (&DAT_2300663a)[iVar1] = 0;
    (&DAT_2300663b)[iVar1] = 0;
    (&DAT_2300663c)[iVar1] = 0;
  } while (iVar2 != 8);
  return;
}


