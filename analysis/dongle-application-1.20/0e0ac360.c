/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ac360. Types and names are inferred; NOT original source. */

bool FUN_0e0ac360(uint param_1,uint param_2)

{
  int iVar1;
  bool bVar2;
  
  if (DAT_2f0111c0 == param_1) {
    if ((DAT_2f0111c1 == param_2) || (param_2 == 0xff)) {
      iVar1 = 0;
      goto LAB_0e0ac394;
    }
    if ((uint)DAT_2f0111c8 != (uint)DAT_2f0111c0) {
      return false;
    }
    bVar2 = DAT_2f0111c9 == param_2;
LAB_0e0ac37c:
    if (!bVar2) {
      return false;
    }
  }
  else {
    if (DAT_2f0111c8 != param_1) {
      return false;
    }
    if (DAT_2f0111c9 != param_2) {
      bVar2 = param_2 == 0xff;
      goto LAB_0e0ac37c;
    }
  }
  iVar1 = 1;
LAB_0e0ac394:
  return *(int *)(iVar1 * 8 + 0x2f0111c4) != 0;
}


