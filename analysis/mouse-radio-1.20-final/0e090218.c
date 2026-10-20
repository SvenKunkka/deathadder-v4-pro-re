/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e090218. Types and names are inferred; NOT original source. */

undefined4 FUN_0e090218(int param_1)

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
  FUN_0e0917d0(piVar3);
  iVar1 = FUN_0e091ed0(uVar4,uVar5);
  puVar6 = (undefined4 *)piVar3[9];
  iVar2 = ram_candidate_23020cfc(puVar6,0,&local_14);
  if (-1 < iVar2) {
    thunk_FUN_23029f6c(*local_14,*(undefined1 *)(local_14 + 1),*puVar6);
  }
  FUN_0e0917ac(piVar3);
  if (iVar1 == 0xbad0000) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0xfffffff0;
  }
  return uVar4;
}


