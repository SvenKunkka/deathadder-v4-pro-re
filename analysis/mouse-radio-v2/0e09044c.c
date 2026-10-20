/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e09044c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e09044c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *local_14;
  
  iVar3 = *(int *)(param_1 + 4);
  (**(code **)(iVar3 + 0x20))();
  puVar4 = *(undefined4 **)(iVar3 + 0x24);
  iVar1 = FUN_0e0977c0(puVar4,1,&local_14);
  if (-1 < iVar1) {
    FUN_0e097658(*local_14,*(undefined1 *)(local_14 + 1),*puVar4);
  }
  iVar1 = FUN_0e091830(iVar3,iVar3 + 8,*(undefined4 *)(iVar3 + 0x18),param_1);
  if (iVar1 == DAT_0e0904b8) {
    iVar3 = *(int *)(param_1 + 4);
    puVar4 = *(undefined4 **)(iVar3 + 0x24);
    iVar1 = FUN_0e0977c0(puVar4,0,&local_14);
    if (-1 < iVar1) {
      FUN_0e097658(*local_14,*(undefined1 *)(local_14 + 1),*puVar4);
    }
    FUN_0e0918d4(iVar3);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffffb;
  }
  return uVar2;
}


