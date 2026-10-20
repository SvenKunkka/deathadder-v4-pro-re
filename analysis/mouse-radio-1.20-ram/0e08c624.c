/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08c624. Types and names are inferred; NOT original source. */

void FUN_0e08c624(undefined4 param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  iVar1 = FUN_0e08c2a0();
  if ((iVar1 != 0) && (piVar2 = *(int **)(iVar1 + 0xc), piVar2 != (int *)0x0)) {
    do {
      puVar3 = *(undefined4 **)(piVar2[1] + 0xc);
      if ((puVar3 != (undefined4 *)0x0) && (*(byte *)(puVar3 + 1) != 0)) {
        pbVar5 = (byte *)*puVar3;
        do {
          pbVar4 = pbVar5 + 1;
          if (*pbVar5 == param_2) {
            return;
          }
          pbVar5 = pbVar4;
        } while (pbVar4 != (byte *)*puVar3 + *(byte *)(puVar3 + 1));
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
    return;
  }
  return;
}


