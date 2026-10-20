/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0eb99c. Types and names are inferred; NOT original source. */

void FUN_1c0eb99c(int param_1,int param_2,uint param_3,int param_4,byte param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar1 = DAT_1c0eba34;
  if (((int)param_3 < (int)(param_5 + param_3)) && (param_3 < 8)) {
    iVar7 = (param_1 + -1) * 0xf4;
    uVar3 = param_3;
    iVar4 = param_4 + 8;
    uVar6 = param_3 + 1 & 0xff;
    do {
      *(undefined1 *)(iVar4 + -8) = *(undefined1 *)(iVar7 + (uVar3 + 7) * 0x10 + iVar1 + 0x21);
      iVar2 = iVar7 + uVar3 * 0x10 + iVar1 + param_2;
      *(undefined1 *)(iVar4 + -7) = *(undefined1 *)(iVar2 + 0x93);
      iVar5 = iVar4 + 8;
      *(undefined1 *)(iVar4 + -6) = *(undefined1 *)(iVar2 + 0x95);
      *(undefined1 *)(iVar4 + -5) = *(undefined1 *)(iVar2 + 0x97);
      *(undefined1 *)(iVar4 + -4) = *(undefined1 *)(iVar2 + 0x99);
      *(undefined1 *)(iVar4 + -3) = *(undefined1 *)(iVar2 + 0x9b);
      *(undefined1 *)(iVar4 + -2) = *(undefined1 *)(iVar2 + 0x9d);
      *(undefined1 *)(iVar4 + -1) = *(undefined1 *)(iVar2 + 0x9f);
      if ((int)(param_5 + param_3) <= (int)uVar6) {
        return;
      }
      uVar3 = uVar6;
      iVar4 = iVar5;
      uVar6 = uVar6 + 1;
    } while (iVar5 != param_4 + 0x10 + (7 - param_3 & 0xff) * 8);
  }
  return;
}


