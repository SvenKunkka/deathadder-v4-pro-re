/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0acaac. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vector_14(void)

{
  bool bVar1;
  int iVar2;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 uVar3;
  
  iVar2 = _DAT_2f011ba0;
  uVar3 = getProcessStackPointer();
  *(undefined4 *)(_DAT_2f011ba0 + 0x30) = unaff_r4;
  *(undefined4 *)(iVar2 + 0x34) = unaff_r5;
  *(undefined4 *)(iVar2 + 0x38) = unaff_r6;
  *(undefined4 *)(iVar2 + 0x3c) = unaff_r7;
  *(undefined4 *)(iVar2 + 0x40) = unaff_r8;
  *(undefined4 *)(iVar2 + 0x44) = unaff_r9;
  *(undefined4 *)(iVar2 + 0x48) = unaff_r10;
  *(undefined4 *)(iVar2 + 0x4c) = unaff_r11;
  *(undefined4 *)(iVar2 + 0x50) = uVar3;
  FUN_0e0aca68();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setProcessStackPointer(*(undefined4 *)(_DAT_2f011ba0 + 0x50));
  }
  FUN_0e0b1d22(_DAT_2f011ba0);
  return;
}


