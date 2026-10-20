/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e2ec0. Types and names are inferred; NOT original source. */

bool FUN_0e0e2ec0(uint param_1,uint param_2)

{
  int iVar1;
  bool bVar2;
  
  if (DAT_2f011090 == param_1) {
    if ((DAT_2f011091 == param_2) || (param_2 == 0xff)) {
      iVar1 = 0;
      goto LAB_0e0e2ef4;
    }
    if ((uint)DAT_2f011098 != (uint)DAT_2f011090) {
      return false;
    }
    bVar2 = DAT_2f011099 == param_2;
LAB_0e0e2edc:
    if (!bVar2) {
      return false;
    }
  }
  else {
    if (DAT_2f011098 != param_1) {
      return false;
    }
    if (DAT_2f011099 != param_2) {
      bVar2 = param_2 == 0xff;
      goto LAB_0e0e2edc;
    }
  }
  iVar1 = 1;
LAB_0e0e2ef4:
  return *(int *)(iVar1 * 8 + 0x2f011094) != 0;
}


