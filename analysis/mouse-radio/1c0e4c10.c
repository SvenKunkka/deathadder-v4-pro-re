/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e4c10. Types and names are inferred; NOT original source. */

void FUN_1c0e4c10(void)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  ushort *puVar4;
  ushort *extraout_r2;
  int iVar5;
  ushort uVar6;
  int iVar7;
  
  puVar4 = DAT_1c0e4c80;
  if (300 < (ushort)(*DAT_1c0e4c80 + 1)) goto LAB_1c0e4c56;
  *DAT_1c0e4c80 = *DAT_1c0e4c80 + 1;
  do {
    pcVar2 = DAT_1c0e4c84;
    if (*DAT_1c0e4c84 == '\0') {
      return;
    }
    uVar6 = *DAT_1c0e4c88 + 1;
    puVar4 = DAT_1c0e4c88;
    if (uVar6 < 0xbb9) goto LAB_1c0e4c76;
    iVar7 = *DAT_1c0e4c8c;
    cVar1 = *DAT_1c0e4c90;
    *DAT_1c0e4c88 = 0;
    *pcVar2 = '\0';
    if (iVar7 == 1) {
      if (cVar1 != '\0') {
        return;
      }
    }
    else if (cVar1 == '\0') {
      return;
    }
    thunk_EXT_FUN_0e08605c(0);
    puVar4 = extraout_r2;
LAB_1c0e4c56:
    *puVar4 = 0;
    iVar7 = thunk_EXT_FUN_0e084ec8();
    piVar3 = DAT_1c0e4c94;
    iVar5 = *DAT_1c0e4c94;
    *DAT_1c0e4c8c = iVar7;
  } while (iVar7 == iVar5);
  *piVar3 = iVar7;
  puVar4 = DAT_1c0e4c88;
  uVar6 = 1;
  *DAT_1c0e4c84 = '\x01';
LAB_1c0e4c76:
  *puVar4 = uVar6;
  return;
}


