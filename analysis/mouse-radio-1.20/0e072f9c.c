/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e072f9c. Types and names are inferred; NOT original source. */

void FUN_0e072f9c(void)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  
  uVar3 = (uint)DAT_23004477;
  iVar7 = uVar3 * 0xf4;
  puVar2 = (undefined4 *)&DAT_23004a5c;
  puVar6 = (undefined4 *)(&DAT_230044ce + iVar7);
  do {
    puVar5 = puVar6;
    puVar4 = puVar2;
    puVar6 = puVar5 + 4;
    *puVar4 = *puVar5;
    puVar4[1] = puVar5[1];
    puVar4[2] = puVar5[2];
    puVar4[3] = puVar5[3];
    puVar2 = puVar4 + 4;
  } while (puVar6 != (undefined4 *)(&DAT_230044ee + iVar7));
  puVar4[4] = *puVar6;
  puVar4[5] = puVar5[5];
  puVar4[6] = puVar5[6];
  iVar7 = uVar3 * 0xf4;
  DAT_23004a8c = *(undefined4 *)(&DAT_230044ca + iVar7);
  DAT_23004a54 = *(undefined4 *)(&DAT_230044fe + iVar7);
  DAT_23004a50._2_1_ = (undefined1)((uint)*(undefined4 *)(&DAT_230044fa + iVar7) >> 0x10);
  uVar1 = DAT_23004a50._2_1_;
  DAT_23004a58 = *(undefined2 *)(&DAT_23004502 + iVar7);
  DAT_23004a5a = (&DAT_23004504)[iVar7];
  DAT_23004a50 = *(undefined4 *)(&DAT_230044fa + iVar7);
  FUN_0e078bfc(uVar1);
  iVar7 = (uint)DAT_23004477 * 0xf4;
  DAT_23007716 = (&DAT_230044f3)[iVar7];
  DAT_23003f5c = *(undefined2 *)(&DAT_230044f6 + iVar7);
  DAT_23003f60 = *(undefined2 *)(&DAT_230044f4 + iVar7);
  DAT_23003f58 = *(undefined2 *)(&DAT_230044f8 + iVar7);
  return;
}


