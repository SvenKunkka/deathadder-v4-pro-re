/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07e81c. Types and names are inferred; NOT original source. */

void FUN_0e07e81c(void)

{
  char *pcVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  
  iVar4 = DAT_0e07e8bc;
  if (*(ushort *)(DAT_0e07e8bc + 2) <= *(ushort *)(DAT_0e07e8bc + 0x24)) {
    pcVar1 = (char *)(DAT_0e07e8bc + 1);
    *(undefined2 *)(DAT_0e07e8bc + 0x24) = 0;
    if (*pcVar1 == '\x01') {
      uVar3 = *(ushort *)(iVar4 + 0x26);
      if ((uint)uVar3 < (uint)*(ushort *)(iVar4 + 0x14)) {
        uVar6 = *(ushort *)(iVar4 + 10);
      }
      else {
        uVar6 = *(ushort *)(iVar4 + 0xc);
      }
      if ((int)(0xffff - (uint)uVar3) <= (int)(uint)uVar6) {
        *(undefined2 *)(iVar4 + 0x26) = 0xffff;
        *(undefined2 *)(iVar4 + 2) = *(undefined2 *)(iVar4 + 4);
        *(undefined1 *)(iVar4 + 1) = 3;
        return;
      }
      *(ushort *)(iVar4 + 0x26) = uVar3 + uVar6;
      *(undefined2 *)(iVar4 + 2) = *(undefined2 *)(iVar4 + 8);
      return;
    }
    if (*pcVar1 == '\x03') {
      uVar3 = *(ushort *)(iVar4 + 0x26);
      if (uVar3 < *(ushort *)(iVar4 + 0x14)) {
        uVar6 = *(ushort *)(iVar4 + 0x10);
      }
      else {
        uVar6 = *(ushort *)(iVar4 + 0x12);
      }
      if (uVar3 <= uVar6) {
        *(undefined2 *)(iVar4 + 2) = *(undefined2 *)(iVar4 + 6);
        *(undefined1 *)(iVar4 + 1) = 1;
        *(undefined2 *)(iVar4 + 0x26) = 0;
        iVar5 = FUN_0e07fb38(0,0xf);
        cVar2 = *DAT_0e07e8c4;
        *(undefined4 *)(iVar4 + 0x1e) = *(undefined4 *)(DAT_0e07e8c0 + iVar5 * 4);
        if (cVar2 != '\0') {
          FUN_0e07f3c0();
        }
        if (*(char *)(iVar4 + 0x23) == '\0') {
          *(undefined1 *)(iVar4 + 0x23) = 1;
          return;
        }
        *(undefined1 *)(iVar4 + 0x23) = 0;
        return;
      }
      *(ushort *)(iVar4 + 0x26) = uVar3 - uVar6;
      *(undefined2 *)(iVar4 + 2) = *(undefined2 *)(iVar4 + 0xe);
    }
  }
  return;
}


