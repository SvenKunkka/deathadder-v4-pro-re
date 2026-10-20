/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0fc340. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0fc340(int param_1)

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
  FUN_1c0fd8f8(piVar3);
  iVar1 = FUN_1c0fdff8(uVar4,uVar5);
  puVar6 = (undefined4 *)piVar3[9];
  iVar2 = FUN_1c1037c0(puVar6,0,&local_14);
  if (-1 < iVar2) {
    FUN_1c103658(*local_14,*(undefined1 *)(local_14 + 1),*puVar6);
  }
  FUN_1c0fd8d4(piVar3);
  if (iVar1 == DAT_1c0fc394) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0xfffffff0;
  }
  return uVar4;
}


