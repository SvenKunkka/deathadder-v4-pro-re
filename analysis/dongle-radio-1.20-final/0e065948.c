/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e065948. Types and names are inferred; NOT original source. */

int FUN_0e065948(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  undefined4 *local_c;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((*(undefined4 **)(iVar1 + 0x18) != (undefined4 *)0x0) &&
     (pcVar2 = (code *)**(undefined4 **)(iVar1 + 0x18), pcVar2 != (code *)0x0)) {
    iVar1 = (*pcVar2)();
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = *(int *)(param_1 + 4);
  }
  puVar3 = *(undefined4 **)(iVar1 + 0x14);
  if (puVar3 != (undefined4 *)0x0) {
    iVar1 = FUN_0e067d30(puVar3,0,&local_c);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_0e067d84(*local_c,*(undefined1 *)(local_c + 1),*puVar3);
    return iVar1;
  }
  return 0;
}


