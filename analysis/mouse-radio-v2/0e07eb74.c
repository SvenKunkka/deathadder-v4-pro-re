/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07eb74. Types and names are inferred; NOT original source. */

void FUN_0e07eb74(int param_1,int param_2,int param_3,int param_4,byte param_5)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = 0;
  if (*(uint *)(param_3 + 9) != 0) {
    uVar7 = (((uint)*(byte *)(param_1 + 5) * *(int *)(param_3 + 5)) / *(uint *)(param_3 + 9) + 1) *
            0xff >> 8;
  }
  if (param_5 != 0) {
    uVar7 = (uVar7 + 1) * 0xff >> 8;
    iVar5 = param_4;
    do {
      iVar6 = iVar5 + 6;
      *(char *)(iVar5 + 3) = (char)(uVar7 * *(byte *)(param_2 + 4) + 0xff >> 8);
      *(char *)(iVar5 + 4) = (char)(uVar7 * *(byte *)(param_2 + 5) + 0xff >> 8);
      *(char *)(iVar5 + 5) = (char)(uVar7 * *(byte *)(param_2 + 6) + 0xff >> 8);
      iVar5 = iVar6;
      param_2 = param_2 + 0xc;
    } while (iVar6 != (short)(ushort)param_5 * 6 + param_4);
  }
  puVar4 = DAT_0e07ec64;
  puVar3 = DAT_0e07ec60;
  if ((((*DAT_0e07ec3c == '\0') && (*DAT_0e07ec40 == '\0')) && (*DAT_0e07ec44 == '\0')) &&
     (((*DAT_0e07ec48 == '\0' && (*DAT_0e07ec4c == '\0')) &&
      ((*DAT_0e07ec50 == '\0' && (*DAT_0e07ec54 == '\0')))))) {
    if (*DAT_0e07ec58 == '\0') {
      *DAT_0e07ec5c = 0;
      *puVar3 = 0;
      *puVar4 = 0;
      return;
    }
    uVar1 = *(undefined1 *)(param_4 + 4);
    uVar2 = *(undefined1 *)(param_4 + 5);
    *DAT_0e07ec5c = *(undefined1 *)(param_4 + 3);
    *puVar3 = uVar1;
    *puVar4 = uVar2;
  }
  return;
}


