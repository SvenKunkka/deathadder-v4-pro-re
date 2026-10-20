/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e076e40. Types and names are inferred; NOT original source. */

void FUN_0e076e40(void)

{
  int iVar1;
  code *pcVar2;
  
  if ((int)(DAT_2300707c << 0x18) < 0) {
    pcVar2 = (code *)&DAT_23026369;
  }
  else {
    pcVar2 = (code *)&DAT_230263bd;
  }
  (*pcVar2)(&DAT_0e09782c,0x80);
  if ((int)(DAT_2300707c << 0x1c) < 0) {
    pcVar2 = (code *)&DAT_23026369;
  }
  else {
    pcVar2 = (code *)&DAT_230263bd;
  }
  (*pcVar2)(&DAT_0e09782c,8);
  if ((int)(DAT_2300707c << 0x19) < 0) {
    pcVar2 = (code *)&DAT_23026369;
  }
  else {
    pcVar2 = (code *)&DAT_230263bd;
  }
  (*pcVar2)(&DAT_0e09782c,0x40);
  iVar1 = thunk_FUN_0e094560(&DAT_0e09782c);
  if (iVar1 != 0) {
    DAT_2300707c = DAT_2300707c & 0xffffffdf;
    FUN_23026030(&DAT_0e09782c,5,0x10010);
    return;
  }
  return;
}


