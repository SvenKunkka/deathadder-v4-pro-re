/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23027a4e. Types and names are inferred; NOT original source. */

void ram_candidate_23027a4e(void)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int in_r3;
  int unaff_r4;
  int in_r12;
  
  uVar3 = (uint)*(byte *)(in_r12 + unaff_r4 + 7);
  if (uVar3 - 9 < 2) {
    (&DAT_2300662e)[in_r3] = 0;
  }
  else {
    DAT_2300662d = DAT_2300662d & ~(byte)(1 << (uVar3 - 1 & 0xff));
  }
  cVar2 = DAT_2300661c;
  iVar1 = (in_r3 + 0x2c) * 2;
  (&DAT_230065a4)[iVar1] = 0;
  (&DAT_230065a5)[iVar1] = 0;
  if (cVar2 != '\0') {
    DAT_2300661c = cVar2 + -1;
    if (cVar2 != '\x01') {
      return;
    }
    DAT_2300661c = '\0';
  }
  (&DAT_230065f4)[in_r3] = 3;
  ram_candidate_23027290();
  return;
}


