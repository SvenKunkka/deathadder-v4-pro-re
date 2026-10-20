/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08504c. Types and names are inferred; NOT original source. */

void FUN_0e08504c(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  code *pcVar4;
  
  iVar3 = *(int *)(*(int *)(DAT_0e0850bc + 4) + 8);
  if ((1 << (uint)*(byte *)(DAT_0e0850bc + 8) & **(uint **)(*(int *)(DAT_0e0850bc + 4) + 0x10)) == 0
     ) {
    pcVar4 = *(code **)(iVar3 + 0x10);
  }
  else {
    pcVar4 = *(code **)(iVar3 + 0xc);
  }
  (*pcVar4)();
  iVar3 = DAT_0e0850c0;
  iVar1 = FUN_0e094688(DAT_0e0850c0);
  if (iVar1 == 0) {
    iVar1 = FUN_0e094688(DAT_0e0850c0);
  }
  else {
    puVar2 = *(undefined4 **)(iVar3 + 8);
    **(uint **)(iVar3 + 0x10) = **(uint **)(iVar3 + 0x10) & 0xffffffef;
    (*(code *)*puVar2)(iVar3,4,0x10000);
    iVar1 = FUN_0e094688(DAT_0e0850c0);
  }
  if (iVar1 == 0) {
    return;
  }
  puVar2 = *(undefined4 **)(iVar3 + 8);
  **(uint **)(iVar3 + 0x10) = **(uint **)(iVar3 + 0x10) & 0xfffffffe;
  (*(code *)*puVar2)(DAT_0e0850c0,0,0x10000);
  return;
}


