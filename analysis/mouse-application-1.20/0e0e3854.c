/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e3854. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0e3854(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  piVar3 = (int *)&DAT_2f011734;
  iVar4 = 0;
  do {
    if (param_2 <= iVar4) {
      return;
    }
    iVar5 = param_1[1];
    if (iVar5 != 0) {
      iVar2 = *param_1;
      iVar1 = FUN_0e0e6d14(iVar2);
      iVar5 = FUN_0e0e6d14(iVar5 + iVar2 + -1);
      if (iVar1 != iVar5) {
        *(undefined4 *)(&DAT_2f011734 + iVar4 * 0x14) = 0xffffffea;
        return;
      }
      *piVar3 = iVar1;
      if (iVar1 == -0x16) {
        return;
      }
      if ((int)(uint)DAT_2f011910 <= iVar1) {
        return;
      }
      iVar5 = iVar4 * 0x14;
      _DAT_e000ed98 = iVar1;
      (&DAT_2f011740)[iVar5] = (&DAT_2f011740)[iVar5] & 0xe0 | (byte)_DAT_e000ed9c & 0x1f;
      (&DAT_2f011740)[iVar5] = (&DAT_2f011740)[iVar5] & 0x1f | (byte)((_DAT_e000eda0 >> 1 & 7) << 5)
      ;
      piVar3[1] = _DAT_e000ed9c & 0xffffffe0;
      piVar3[4] = _DAT_e000eda0 & 0xffffffe0;
    }
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 5;
    param_1 = param_1 + 3;
  } while( true );
}


