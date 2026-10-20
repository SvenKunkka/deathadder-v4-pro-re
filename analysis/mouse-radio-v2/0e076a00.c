/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e076a00. Types and names are inferred; NOT original source. */

bool FUN_0e076a00(void)

{
  bool bVar1;
  bool bVar2;
  ushort *puVar3;
  int iVar4;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 local_c;
  
  local_1c = *DAT_0e076a74;
  uStack_18 = DAT_0e076a74[1];
  uStack_14 = DAT_0e076a74[2];
  uStack_10 = DAT_0e076a74[3];
  local_c = DAT_0e076a74[4];
  iVar4 = (**(code **)(*(int *)(DAT_0e076a78 + 8) + 4))(DAT_0e076a78,&local_1c);
  FUN_0e075b58(DAT_0e076a7c,0x29);
  puVar3 = DAT_0e076a80;
  if (iVar4 == 0) {
    bVar1 = 0x168 < *DAT_0e076a80 - 0x10e;
    if (bVar1) {
      *(bool *)DAT_0e076a88 = 0x10d < *DAT_0e076a80;
    }
    bVar2 = 0x168 < puVar3[1] - 0x10e;
    if (bVar2) {
      *(bool *)DAT_0e076a84 = 0x10d < puVar3[1];
    }
    return bVar2 || bVar1;
  }
  return false;
}


