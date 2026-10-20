/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08c994. Types and names are inferred; NOT original source. */

int FUN_0e08c994(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = *(int *)(param_3 + 4);
  uVar1 = *(undefined1 *)(iVar4 + 5);
  if (*(char *)(iVar4 + 4) != '\0') {
    uVar3 = 0;
    do {
      uVar5 = uVar3 & 0xff;
      iVar2 = FUN_0e08c718(param_1,param_2,uVar1,uVar5);
      uVar3 = uVar3 + 1;
      if (iVar2 == 0) {
        return -0x3d;
      }
      iVar2 = FUN_0e08c884(param_1,iVar2,1,uVar5,0);
      if (iVar2 != 0) {
        return iVar2;
      }
    } while ((int)uVar3 < (int)(uint)*(byte *)(iVar4 + 4));
  }
  return 0;
}


