/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302770a. Types and names are inferred; NOT original source. */

void ram_candidate_2302770a(undefined4 param_1,undefined1 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  undefined2 uVar2;
  int unaff_r4;
  int in_r12;
  
  cVar1 = *(char *)(unaff_r4 + in_r12 + 7);
  DAT_230065eb = param_2;
  if (cVar1 == '\t') {
    (&DAT_2300662e)[param_4] = 1;
  }
  else if (cVar1 == '\n') {
    (&DAT_2300662e)[param_4] = 0xff;
  }
  else {
    DAT_2300662d = (byte)(1 << (uint)(byte)(cVar1 - 1)) | DAT_2300662d;
  }
  uVar2 = CONCAT11(*(undefined1 *)(in_r12 + unaff_r4 + 9),*(undefined1 *)(in_r12 + unaff_r4 + 0xb));
  *(undefined2 *)(&DAT_230065fc + param_4 * 2) = uVar2;
  DAT_2300661c = DAT_2300661c + '\x01';
  (&DAT_2300660c)[param_4] = uVar2;
  (&DAT_230065f4)[param_4] = 1;
  ram_candidate_23027290();
  return;
}


