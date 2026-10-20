/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f8934. Types and names are inferred; NOT original source. */

int FUN_1c0f8934(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_2 + 0xc);
  do {
    if (piVar4 == (int *)0x0) {
      return 0;
    }
    uVar3 = 1;
    do {
      uVar2 = piVar4[3];
      if (uVar2 == 0) break;
      if ((int)((uVar2 >> (uVar3 & 0x7f) + 0x10) << 0x1f) < 0) {
        iVar1 = FUN_1c0f8ab0(*(undefined4 *)(param_1 + 0x18),(uVar3 | 0xffffff80) & 0xff,piVar4 + 3,
                             uVar2,param_4);
        if (iVar1 != 0) {
          return iVar1;
        }
        uVar2 = (uint)piVar4[3] >> (uVar3 & 0xff);
      }
      else {
        uVar2 = uVar2 >> (uVar3 & 0xff);
      }
      if (((int)(uVar2 << 0x1f) < 0) &&
         (iVar1 = FUN_1c0f8ab0(*(undefined4 *)(param_1 + 0x18),uVar3 & 0xff,piVar4 + 3,uVar2 << 0x1f
                               ,param_4), iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 0x10);
    piVar4 = (int *)*piVar4;
  } while( true );
}


