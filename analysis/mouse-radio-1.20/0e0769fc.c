/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0769fc. Types and names are inferred; NOT original source. */

bool FUN_0e0769fc(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined *local_1c;
  undefined4 uStack_18;
  undefined2 *puStack_14;
  undefined4 uStack_10;
  undefined4 local_c;
  
  local_1c = &DAT_0e099208;
  uStack_18 = 3;
  puStack_14 = &DAT_23004cd8;
  uStack_10 = 4;
  local_c = 10;
  iVar3 = FUN_23020504(&DAT_0e097980,&local_1c);
  FUN_0e075b54(&DAT_0e0991b0,0x29);
  if (iVar3 == 0) {
    bVar1 = 0x168 < DAT_23004cd8 - 0x10e;
    if (bVar1) {
      DAT_23001507 = 0x10d < DAT_23004cd8;
    }
    bVar2 = 0x168 < DAT_23004cda - 0x10e;
    if (bVar2) {
      DAT_23001506 = 0x10d < DAT_23004cda;
    }
    return bVar2 || bVar1;
  }
  return false;
}


