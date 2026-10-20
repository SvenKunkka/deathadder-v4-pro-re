/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e093d74. Types and names are inferred; NOT original source. */

void FUN_0e093d74(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar4;
  undefined1 *local_1c;
  
  uVar1 = **(undefined2 **)(param_1 + 8);
  iVar2 = FUN_0e079818(*(undefined4 *)(param_1 + 0x18));
  FUN_0e093d44(param_1,&local_1c,iVar2 + 1);
  if (local_1c != (undefined1 *)0x0) {
    *(undefined2 *)(local_1c + -2) = uVar1;
    *(undefined2 *)(local_1c + -5) = 4;
    local_1c[-3] = 0xff;
    *local_1c = 0;
    uVar4 = *(undefined4 *)(param_1 + 0x18);
    uVar3 = FUN_0e079818(uVar4);
    FUN_0e0974c4(local_1c + 1,uVar4,uVar3);
    if (*(char *)(*(int *)(param_1 + 8) + 0x14) != '\0') {
      UNRECOVERED_JUMPTABLE = *(code **)(**(int **)(param_1 + 0xc) + 4);
      if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e093ddc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(*(int **)(param_1 + 0xc),local_1c + -5,iVar2 + 6);
        return;
      }
    }
  }
  return;
}


