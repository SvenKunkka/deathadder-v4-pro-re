/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0856d8. Types and names are inferred; NOT original source. */

void FUN_0e0856d8(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  
  iVar3 = FUN_0e094688(DAT_0e085718);
  iVar2 = DAT_0e08571c;
  if (iVar3 != 0) {
    iVar3 = *(int *)(*(int *)(DAT_0e08571c + 4) + 8);
    if ((1 << (uint)*(byte *)(DAT_0e08571c + 8) & **(uint **)(*(int *)(DAT_0e08571c + 4) + 0x10)) ==
        0) {
      pcVar4 = *(code **)(iVar3 + 0xc);
    }
    else {
      pcVar4 = *(code **)(iVar3 + 0x10);
    }
    (*pcVar4)();
    iVar3 = DAT_0e085720 + (uint)*(byte *)(iVar2 + 1) * 0xe;
    cVar1 = *(char *)(iVar3 + 10);
    *(undefined1 *)(iVar3 + 8) = 1;
    *(char *)(iVar3 + 10) = cVar1 + '\x01';
    *(char *)(iVar2 + 2) = cVar1;
    return;
  }
  return;
}


