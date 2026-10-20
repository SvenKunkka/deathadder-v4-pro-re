/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c720. Types and names are inferred; NOT original source. */

void FUN_0e06c720(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar3 = (undefined4 *)(&PTR_DAT_0e070824)[param_1];
  puVar5 = (undefined4 *)(&PTR_DAT_0e070824)[param_1 + 1];
  do {
    if (puVar5 <= puVar3) {
      return;
    }
    while( true ) {
      pcVar2 = (code *)*puVar3;
      iVar4 = puVar3[1];
      if (iVar4 != 0) break;
      puVar3 = puVar3 + 2;
      (*pcVar2)();
      if (puVar5 <= puVar3) {
        return;
      }
    }
    if ((pcVar2 != (code *)0x0) && (iVar1 = (*pcVar2)(iVar4), iVar1 != 0)) {
      if (iVar1 < 0) {
        iVar1 = -iVar1;
      }
      if (0xfe < iVar1) {
        iVar1 = 0xff;
      }
      **(undefined1 **)(iVar4 + 0xc) = (char)iVar1;
    }
    puVar3 = puVar3 + 2;
    *(byte *)(*(int *)(iVar4 + 0xc) + 1) = *(byte *)(*(int *)(iVar4 + 0xc) + 1) | 1;
  } while( true );
}


