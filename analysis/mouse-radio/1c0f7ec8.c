/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f7ec8. Types and names are inferred; NOT original source. */

void FUN_1c0f7ec8(undefined4 param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  
  iVar2 = FUN_1c0f842c();
  if (iVar2 == 0) {
    return;
  }
  piVar4 = *(int **)(iVar2 + 0xc);
joined_r0x1c0f7ed4:
  if (piVar4 == (int *)0x0) {
    return;
  }
  do {
    cVar1 = *param_2;
    if (cVar1 == '\x03') {
      pcVar3 = *(code **)(*(int *)(piVar4[1] + 8) + 0x14);
    }
    else if (cVar1 == '\x05') {
      pcVar3 = *(code **)(*(int *)(piVar4[1] + 8) + 0x1c);
    }
    else {
      if (cVar1 != '\x02') break;
      pcVar3 = *(code **)(*(int *)(piVar4[1] + 8) + 0x18);
    }
    if (pcVar3 == (code *)0x0) break;
    (*pcVar3)();
    piVar4 = (int *)*piVar4;
    if (piVar4 == (int *)0x0) {
      return;
    }
  } while( true );
  piVar4 = (int *)*piVar4;
  goto joined_r0x1c0f7ed4;
}


