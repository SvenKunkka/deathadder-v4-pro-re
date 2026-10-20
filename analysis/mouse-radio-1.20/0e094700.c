/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e094700. Types and names are inferred; NOT original source. */

void FUN_0e094700(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 * 0x90;
  iVar2 = param_1 * 0x14;
  FUN_0e095710(&DAT_23002378 + iVar1,&DAT_230134e0 + param_1 * 0x200,0x200,&LAB_0e094a6c_1,
               &DAT_2300764c + iVar2,0,0,0xb,1,0);
  (&DAT_23002385)[iVar1] = (&DAT_23002385)[iVar1] & 0xfb;
  (&DAT_23007658)[param_1 * 5] = &DAT_23002378 + iVar1;
  (&DAT_2300765c)[iVar2] = (char)param_1;
  *(int *)(&DAT_23007650 + iVar2) = (param_1 + 1) * 0xa00 + 0x23012ae0;
  DAT_23007648 = DAT_23007648 + 1;
  return;
}


