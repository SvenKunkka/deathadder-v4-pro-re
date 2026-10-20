/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08a670. Types and names are inferred; NOT original source. */

void FUN_0e08a670(int param_1)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return;
  }
  do {
    while( true ) {
      iVar4 = *(int *)(param_1 + 4);
      cVar3 = *(char *)(param_1 + 8) + -1;
      *(char *)(param_1 + 8) = cVar3;
      if (cVar3 != '\0') {
        return;
      }
      bVar2 = *(byte *)(param_1 + 10);
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 4) = 0;
      iVar1 = (uint)bVar2 * 0x24;
      if (*(code **)(&DAT_23001704 + iVar1) == (code *)0x0) break;
      (**(code **)(&DAT_23001704 + iVar1))();
      param_1 = iVar4;
      if (iVar4 == 0) {
        return;
      }
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      if (-1 < (int)((uint)*(byte *)(param_1 + 9) << 0x1f)) {
        (**(code **)(**(int **)(&DAT_23001708 + iVar1) + 8))();
      }
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    FUN_0e094ed0(&DAT_230016ec + (uint)bVar2 * 0x24,param_1);
    param_1 = iVar4;
  } while (iVar4 != 0);
  return;
}


