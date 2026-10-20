/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08cdb4. Types and names are inferred; NOT original source. */

void FUN_0e08cdb4(int param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = *(int *)(param_1 + 0x10);
  iVar4 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(iVar2 + 0x10);
  iVar5 = *(int *)(iVar3 + 4);
  if ((*(char *)(**(int **)(iVar2 + 4) + 0x22) == *(char *)(param_2 + 0x18)) &&
     (pcVar1 = *(code **)(iVar5 + 0x1c), pcVar1 != (code *)0x0)) {
    if (param_3 == 0) {
      (*pcVar1)(iVar2,*(undefined2 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0xc));
    }
    FUN_0e095414(iVar3 + 0x24);
    if (*(char *)(**(int **)(*(int *)(param_1 + 0x10) + 4) + 0x14) != *(char *)(param_2 + 0x18))
    goto LAB_0e08cb84;
  }
  else if (*(char *)(**(int **)(iVar2 + 4) + 0x14) != *(char *)(param_2 + 0x18)) goto LAB_0e08cb84;
  pcVar1 = *(code **)(iVar5 + 0x18);
  if (pcVar1 == (code *)0x0) {
    FUN_0e0950a8(iVar3 + 0x14);
  }
  else {
    (*pcVar1)(iVar2);
  }
LAB_0e08cb84:
  FUN_0e08d7c0(*(undefined4 *)(iVar4 + 0x18),param_2);
  return;
}


