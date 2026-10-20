/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230276f8. Types and names are inferred; NOT original source. */

void ram_candidate_230276f8(undefined4 param_1,undefined1 param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  char *pcVar5;
  uint uVar6;
  int unaff_r4;
  int iVar7;
  int in_r12;
  
  uVar6 = 0;
  bVar1 = *(byte *)(unaff_r4 + in_r12 + 6);
  iVar7 = (param_4 + 0x18) * 2;
  pcVar5 = &DAT_23006754;
  DAT_230065a0 = param_2;
  (&DAT_230065a2)[iVar7] = 0;
  do {
    if (((int)(uint)bVar1 >> (uVar6 & 0xff)) << 0x1f < 0) {
      bVar2 = (&DAT_230065a2)[iVar7];
      *pcVar5 = *pcVar5 + '\x01';
      (&DAT_230065a2)[iVar7] = (byte)(1 << (uVar6 & 0xff)) | bVar2;
    }
    uVar6 = uVar6 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar6 != 8);
  iVar7 = in_r12 + unaff_r4;
  uVar3 = *(undefined1 *)(iVar7 + 8);
  uVar4 = CONCAT11(*(undefined1 *)(iVar7 + 10),*(undefined1 *)(iVar7 + 0xc));
  *(undefined2 *)(&DAT_230065b1 + param_4 * 2) = uVar4;
  (&DAT_230065c1)[param_4] = uVar4;
  (&DAT_230065d3)[param_4 * 2] = uVar3;
  (&DAT_230065a9)[param_4] = 1;
  ram_candidate_23027290();
  return;
}


