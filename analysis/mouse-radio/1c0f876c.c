/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f876c. Types and names are inferred; NOT original source. */

int FUN_1c0f876c(int param_1,uint param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  uVar5 = param_2 & 0x7f;
  if ((int)(param_2 << 0x18) < 0) {
    uVar5 = uVar5 + 0x10;
  }
  if (*(char *)(param_1 + 0x2c) == '\x02') {
    uVar1 = *(undefined1 *)(param_1 + 0x34);
    uVar2 = FUN_1c0f6f1c();
    iVar3 = FUN_1c0f8400(param_1,uVar2,uVar1);
    if (iVar3 != 0) {
      for (piVar4 = *(int **)(iVar3 + 0xc); piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
        if ((1 << uVar5 & piVar4[2]) != 0) {
          return (int)piVar4;
        }
      }
    }
  }
  return 0;
}


