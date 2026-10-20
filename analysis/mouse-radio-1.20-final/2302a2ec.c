/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302a2ec. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x2302a39a) */
/* WARNING: Removing unreachable block (ram,0x2302a346) */
/* WARNING: Removing unreachable block (ram,0x2302a370) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2302a2ec(void)

{
  int iVar1;
  
  iVar1 = thunk_FUN_0e094560(&DAT_0e097840);
  if (iVar1 != 0) {
    DAT_23007088 = DAT_23007088 & 0xfffffdff;
    FUN_23026030(&DAT_0e097840,9,0x60000);
  }
  _DAT_5f982500 = 0;
  iVar1 = thunk_FUN_0e094560(&DAT_0e097840);
  if (iVar1 != 0) {
    DAT_23007088 = DAT_23007088 & 0xffffff7f;
    FUN_23026030(&DAT_0e097840,7,0x10000);
  }
  iVar1 = thunk_FUN_0e094560(&DAT_0e097840);
  if (iVar1 != 0) {
    DAT_23007088 = DAT_23007088 & 0xffffffbf;
    FUN_23026030(&DAT_0e097840,6,0x10000);
  }
  _DAT_5f982500 = 1;
  _DAT_23006774 = 0;
  return;
}


