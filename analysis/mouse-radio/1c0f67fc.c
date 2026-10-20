/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f67fc. Types and names are inferred; NOT original source. */

void FUN_1c0f67fc(int param_1)

{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = DAT_1c0f6864;
  if (param_1 == 0) {
    return;
  }
  do {
    while( true ) {
      iVar6 = *(int *)(param_1 + 4);
      cVar4 = *(char *)(param_1 + 8) + -1;
      *(char *)(param_1 + 8) = cVar4;
      if (cVar4 != '\0') {
        return;
      }
      bVar1 = *(byte *)(param_1 + 10);
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 4) = 0;
      iVar5 = iVar2 + (uint)bVar1 * 0x24;
      pcVar3 = *(code **)(iVar5 + 0x18);
      if (pcVar3 == (code *)0x0) break;
      (*pcVar3)();
      param_1 = iVar6;
      if (iVar6 == 0) {
        return;
      }
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      if (-1 < (int)((uint)*(byte *)(param_1 + 9) << 0x1f)) {
        (**(code **)(**(int **)(iVar5 + 0x1c) + 8))();
      }
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    FUN_1c100ff8(iVar2 + (uint)bVar1 * 0x24,param_1);
    param_1 = iVar6;
  } while (iVar6 != 0);
  return;
}


