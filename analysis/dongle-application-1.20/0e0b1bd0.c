/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1bd0. Types and names are inferred; NOT original source. */

int FUN_0e0b1bd0(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = *(int **)(param_1 + 0x14);
  iVar4 = *piVar3;
  if (iVar4 << 0x1a < 0) {
    if (piVar3[3] == 0) {
      return -0x78;
    }
    iVar2 = piVar3[3] + -1;
    piVar3[3] = iVar2;
    if (iVar2 == 0) {
      iVar2 = (*(code *)piVar3[2])(param_1,0);
      if (iVar2 < 0) {
        return iVar2;
      }
      *(undefined1 *)(piVar3 + 1) = 1;
      if (-1 < iVar4 << 0x1d) {
        return iVar2;
      }
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0xe0b1bf8);
      (*pcVar1)();
    }
  }
  return 0;
}


