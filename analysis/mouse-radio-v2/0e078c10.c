/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078c10. Types and names are inferred; NOT original source. */

void FUN_0e078c10(void)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  ushort *puVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  
  if ((ushort)(*DAT_0e078c80 + 1) < 0x12d) {
    *DAT_0e078c80 = *DAT_0e078c80 + 1;
  }
  else {
    *DAT_0e078c80 = 0;
    iVar7 = thunk_FUN_0e084ec8();
    piVar3 = DAT_0e078c94;
    iVar5 = *DAT_0e078c94;
    *DAT_0e078c8c = iVar7;
    if (iVar7 != iVar5) {
      *piVar3 = iVar7;
      puVar4 = DAT_0e078c88;
      uVar6 = 1;
      *DAT_0e078c84 = '\x01';
      goto LAB_0e078c76;
    }
  }
  pcVar2 = DAT_0e078c84;
  if (*DAT_0e078c84 == '\0') {
    return;
  }
  uVar6 = *DAT_0e078c88 + 1;
  puVar4 = DAT_0e078c88;
  if (3000 < uVar6) {
    iVar7 = *DAT_0e078c8c;
    cVar1 = *DAT_0e078c90;
    *DAT_0e078c88 = 0;
    *pcVar2 = '\0';
    if (iVar7 == 1) {
      if (cVar1 != '\0') {
        return;
      }
    }
    else if (cVar1 == '\0') {
      return;
    }
                    /* WARNING: Subroutine does not return */
    thunk_FUN_0e08605c(0);
  }
LAB_0e078c76:
  *puVar4 = uVar6;
  return;
}


