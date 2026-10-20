/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e090340. Types and names are inferred; NOT original source. */

undefined4 FUN_0e090340(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *local_14;
  
  piVar3 = *(int **)(param_1 + 4);
  uVar4 = *(undefined4 *)(*piVar3 + 0x600);
  uVar5 = *(undefined4 *)(*piVar3 + 0x604);
  FUN_0e0918f8(piVar3);
  iVar1 = FUN_0e091ff8(uVar4,uVar5);
  puVar6 = (undefined4 *)piVar3[9];
  iVar2 = FUN_0e0977c0(puVar6,0,&local_14);
  if (-1 < iVar2) {
    FUN_0e097658(*local_14,*(undefined1 *)(local_14 + 1),*puVar6);
  }
  FUN_0e0918d4(piVar3);
  if (iVar1 == DAT_0e090394) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0xfffffff0;
  }
  return uVar4;
}


