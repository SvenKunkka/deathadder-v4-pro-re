/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e085724. Types and names are inferred; NOT original source. */

void FUN_0e085724(char param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int local_1c [2];
  undefined1 local_14;
  
  iVar1 = DAT_0e08577c;
  local_1c[0] = DAT_0e08577c + 0x28;
  local_1c[1] = 2;
  *(undefined1 *)(DAT_0e08577c + 0x28) = 10;
  *(char *)(iVar1 + 0x29) = param_1 << 6;
  local_14 = 2;
  iVar3 = (**(code **)(*(int *)(DAT_0e085780 + 8) + 8))(DAT_0e085780,local_1c,1,100);
  pcVar2 = DAT_0e085784;
  if (iVar3 == 0) {
    *(undefined2 *)(iVar1 + 0xc) = 0;
    *pcVar2 = param_1;
    return;
  }
  *(char *)(iVar1 + 0xc) = *(char *)(iVar1 + 0xc) + '\x01';
  *DAT_0e085784 = '\0';
  return;
}


