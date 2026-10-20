/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e077048. Types and names are inferred; NOT original source. */

char FUN_0e077048(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  
  cVar1 = *DAT_0e0770d4;
  if (cVar1 != '\0') {
    if (*DAT_0e0770d8 == '\0') {
      FUN_0e0773e0(param_1,param_3);
    }
    piVar2 = DAT_0e0770e0;
    iVar6 = DAT_0e0770dc;
    iVar3 = *(int *)(*(int *)(DAT_0e0770dc + 4) + 8);
    if ((1 << (uint)*(byte *)(DAT_0e0770dc + 8) & **(uint **)(*(int *)(DAT_0e0770dc + 4) + 0x10)) ==
        0) {
      pcVar4 = *(code **)(iVar3 + 0x10);
    }
    else {
      pcVar4 = *(code **)(iVar3 + 0xc);
    }
    (*pcVar4)();
    *(undefined4 *)*piVar2 = 1;
    do {
    } while (*(int *)(*piVar2 + 0x108) == 0);
    iVar3 = *(int *)(iVar6 + 4);
    iVar5 = *(int *)(iVar3 + 8);
    if ((1 << *(sbyte *)(iVar6 + 8) & **(uint **)(iVar3 + 0x10)) == 0) {
      pcVar4 = *(code **)(iVar5 + 0xc);
    }
    else {
      pcVar4 = *(code **)(iVar5 + 0x10);
    }
    (*pcVar4)();
    iVar6 = *piVar2;
    *(undefined4 *)(iVar6 + 0x108) = 0;
    thunk_FUN_0e0974c4(param_2,DAT_0e0770e4,param_3,*(undefined4 *)(iVar6 + 0x108));
  }
  return cVar1;
}


