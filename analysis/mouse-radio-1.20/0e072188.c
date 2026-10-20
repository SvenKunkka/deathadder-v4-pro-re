/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e072188. Types and names are inferred; NOT original source. */

void FUN_0e072188(undefined4 param_1,int param_2,byte *param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  
  bVar1 = *param_3;
  iVar3 = param_2 * 0x80 + 0x23006850;
  if ((bVar1 & 0x1f) == 0) {
    (&DAT_23006b50)[param_2] = bVar1 & 0x1f;
    (&DAT_23006b58)[param_2] = (char)param_4 + -1;
    cVar4 = '\x01';
    thunk_FUN_0e09739c(iVar3,param_3 + 1);
  }
  else {
    if ((&DAT_23006b50)[param_2] != (bVar1 & 0x1f)) {
      (&DAT_23006b50)[param_2] = 0;
      (&DAT_23006b58)[param_2] = 0;
      return;
    }
    bVar2 = (&DAT_23006b58)[param_2];
    cVar4 = (&DAT_23006b50)[param_2] + 1;
    thunk_FUN_0e09739c(iVar3 + (uint)bVar2,param_3 + 1,param_4 + -1);
    (&DAT_23006b58)[param_2] = bVar2 + (char)(param_4 + -1);
  }
  (&DAT_23006b50)[param_2] = cVar4;
  if ((int)((uint)bVar1 << 0x18) < 0) {
    return;
  }
  DAT_2300779c = (&DAT_23006b58)[param_2];
  DAT_2300779b = (undefined1)param_2;
  thunk_FUN_0e09739c(&DAT_230067d0,iVar3);
  (&DAT_23006b50)[param_2] = 0;
  (&DAT_23006b58)[param_2] = 0;
  thunk_FUN_0e0952ec(&DAT_230067a0);
  return;
}


