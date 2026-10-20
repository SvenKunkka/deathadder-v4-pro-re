/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0855c8. Types and names are inferred; NOT original source. */

void FUN_0e0855c8(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  code *pcVar4;
  
  iVar3 = *(int *)(*(int *)(DAT_0e085638 + 4) + 8);
  if ((1 << (uint)*(byte *)(DAT_0e085638 + 8) & **(uint **)(*(int *)(DAT_0e085638 + 4) + 0x10)) == 0
     ) {
    pcVar4 = *(code **)(iVar3 + 0x10);
  }
  else {
    pcVar4 = *(code **)(iVar3 + 0xc);
  }
  (*pcVar4)();
  iVar3 = DAT_0e08563c;
  iVar1 = FUN_0e094688(DAT_0e08563c);
  if (iVar1 == 0) {
    iVar1 = FUN_0e094688(DAT_0e08563c);
  }
  else {
    puVar2 = *(undefined4 **)(iVar3 + 8);
    **(uint **)(iVar3 + 0x10) = **(uint **)(iVar3 + 0x10) & 0xffffffbf;
    (*(code *)*puVar2)(iVar3,6,0x10000);
    iVar1 = FUN_0e094688(DAT_0e08563c);
  }
  if (iVar1 == 0) {
    return;
  }
  puVar2 = *(undefined4 **)(iVar3 + 8);
  **(uint **)(iVar3 + 0x10) = **(uint **)(iVar3 + 0x10) & 0xfffffffb;
  (*(code *)*puVar2)(DAT_0e08563c,2,0x10000);
  return;
}


