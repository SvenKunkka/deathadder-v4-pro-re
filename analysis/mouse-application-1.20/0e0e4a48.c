/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e4a48. Types and names are inferred; NOT original source. */

/* WARNING: Switch with 1 destination removed at 0x0e0e4a72 */
/* WARNING: Exceeded maximum restarts with more pending */

void FUN_0e0e4a48(ushort *param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  
  if ((int)((uint)*param_1 << 0x10) < 0) {
    FUN_0e0e6ea0(param_1 + 3,param_2 + -6);
  }
  else {
    uVar2 = (*param_1 & 0x3fff) >> 8;
    if ((uVar2 < 10) && (*(int *)(&DAT_0e0e8784 + uVar2 * 4) != 0)) {
      if ((pcRam2f011884 != (code *)0x0) && (cRam2f011888 != '\0')) {
        uVar1 = *param_1;
        if ((uVar1 & 0x4000) == 0) {
          if (uVar1 == 1) {
            uVar2 = 2;
          }
          else {
            uVar2 = uVar1 - 3;
            if (1 < uVar2) {
              return;
            }
          }
        }
        else {
          uVar2 = 1;
        }
        (*pcRam2f011884)(&stack0xfffffff4,*(undefined4 *)(param_1 + 1),pcRam2f011884,uVar2,param_1);
      }
      return;
    }
  }
  return;
}


