/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f810. Types and names are inferred; NOT original source. */

void FUN_0e07f810(int param_1,int param_2,uint param_3,int param_4,byte param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  if (((int)param_3 < (int)(param_5 + param_3)) && (param_3 < 8)) {
    iVar6 = (param_1 + -1) * 0xf4;
    uVar2 = param_3;
    iVar3 = param_4 + 8;
    uVar5 = param_3 + 1 & 0xff;
    do {
      *(undefined *)(iVar3 + -8) = (&DAT_23004495)[iVar6 + (uVar2 + 7) * 0x10];
      iVar1 = param_2 + iVar6 + uVar2 * 0x10;
      *(undefined1 *)(iVar3 + -7) = *(undefined1 *)((int)&DAT_23004474 + iVar1 + 0x93);
      iVar4 = iVar3 + 8;
      *(undefined1 *)(iVar3 + -6) = *(undefined1 *)((int)&DAT_23004474 + iVar1 + 0x95);
      *(undefined1 *)(iVar3 + -5) = *(undefined1 *)((int)&DAT_23004474 + iVar1 + 0x97);
      *(undefined1 *)(iVar3 + -4) = *(undefined1 *)((int)&DAT_23004474 + iVar1 + 0x99);
      *(undefined1 *)(iVar3 + -3) = *(undefined1 *)((int)&DAT_23004474 + iVar1 + 0x9b);
      *(undefined1 *)(iVar3 + -2) = *(undefined1 *)((int)&DAT_23004474 + iVar1 + 0x9d);
      *(undefined1 *)(iVar3 + -1) = *(undefined1 *)((int)&DAT_23004474 + iVar1 + 0x9f);
      if ((int)(param_5 + param_3) <= (int)uVar5) {
        return;
      }
      uVar2 = uVar5;
      iVar3 = iVar4;
      uVar5 = uVar5 + 1;
    } while (iVar4 != param_4 + 0x10 + (7 - param_3 & 0xff) * 8);
  }
  return;
}


