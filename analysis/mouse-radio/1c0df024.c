/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0df024. Types and names are inferred; NOT original source. */

void FUN_1c0df024(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = DAT_1c0df0a8;
  uVar5 = 0;
  uVar1 = *DAT_1c0df0a4;
  do {
    iVar3 = uVar5 * 5 + iVar2;
    uVar4 = (int)(uint)uVar1 >> (uVar5 & 0xff) & 1;
    if (((*(byte *)(iVar2 + uVar5 * 5) & 2) == 0) || (*(char *)(iVar3 + 2) == '\0')) {
      iVar3 = uVar5 * 5;
      if (uVar4 == 0) {
        if ((*(char *)(iVar2 + iVar3 + 1) != '\x01') &&
           ((int)((uint)*(byte *)(iVar2 + iVar3) << 0x1f) < 0)) goto LAB_1c0df040;
      }
      else if ((*(char *)(iVar2 + iVar3 + 1) != '\0') &&
              (-1 < (int)((uint)*(byte *)(iVar2 + iVar3) << 0x1f))) {
LAB_1c0df040:
        *(char *)(iVar2 + iVar3 + 2) = *(char *)(iVar2 + iVar3 + 2) + '\x01';
      }
    }
    else if (*(byte *)(iVar3 + 1) == uVar4) {
      *(char *)(iVar3 + 3) = *(char *)(iVar3 + 3) + '\x01';
    }
    else {
      *(char *)(iVar3 + 2) = *(char *)(iVar3 + 2) + -1;
    }
    uVar5 = uVar5 + 1;
    if (uVar5 == 6) {
      return;
    }
  } while( true );
}


