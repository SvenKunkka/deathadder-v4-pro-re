/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0913d8. Types and names are inferred; NOT original source. */

bool FUN_0e0913d8(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = DAT_0e09141c;
  uVar3 = (uint)*(byte *)(param_1 + 1);
  iVar2 = DAT_0e09141c + uVar3 * 0x14;
  if ((*(int *)(DAT_0e09141c + uVar3 * 0x14) == 0) && (*(int *)(*param_1 + 0x104) != 0)) {
    *(undefined4 *)(*param_1 + 0x104) = 0;
    *(undefined1 *)(iVar2 + 8) = 1;
  }
  return *(char *)(iVar1 + uVar3 * 0x14 + 8) != '\x02';
}


