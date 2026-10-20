/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07ed0c. Types and names are inferred; NOT original source. */

void FUN_0e07ed0c(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *puVar4;
  
  iVar1 = DAT_0e07eddc;
  iVar2 = FUN_0e094688(DAT_0e07eddc);
  if (iVar2 == 0) {
    iVar2 = FUN_0e094688(DAT_0e07eddc);
  }
  else {
    puVar3 = *(undefined4 **)(iVar1 + 8);
    **(uint **)(iVar1 + 0x10) = **(uint **)(iVar1 + 0x10) & 0xffffffdf;
    (*(code *)*puVar3)(iVar1,5,0x60000);
    iVar2 = FUN_0e094688(DAT_0e07eddc);
  }
  if (iVar2 == 0) {
    iVar2 = FUN_0e094688(DAT_0e07eddc);
  }
  else {
    puVar3 = *(undefined4 **)(iVar1 + 8);
    **(uint **)(iVar1 + 0x10) = **(uint **)(iVar1 + 0x10) & 0xfffffffb;
    (*(code *)*puVar3)(DAT_0e07eddc,2,0x60000);
    iVar2 = FUN_0e094688(DAT_0e07eddc);
  }
  if (iVar2 == 0) {
    iVar2 = FUN_0e094688(DAT_0e07eddc);
  }
  else {
    puVar3 = *(undefined4 **)(iVar1 + 8);
    **(uint **)(iVar1 + 0x10) = **(uint **)(iVar1 + 0x10) & 0xfffffff7;
    (*(code *)*puVar3)(DAT_0e07eddc,3,0x60000);
    iVar2 = FUN_0e094688(DAT_0e07eddc);
  }
  if (iVar2 == 0) {
    puVar4 = *(uint **)(iVar1 + 0x10);
  }
  else {
    puVar4 = *(uint **)(iVar1 + 0x10);
    puVar3 = *(undefined4 **)(iVar1 + 8);
    *puVar4 = *puVar4 & 0xffffffef;
    (*(code *)*puVar3)(DAT_0e07eddc,4,0x60000);
  }
  if ((int)(*puVar4 << 0x1a) < 0) {
    (**(code **)(*(int *)(iVar1 + 8) + 0x10))(DAT_0e07eddc,0x20);
    return;
  }
  (**(code **)(*(int *)(iVar1 + 8) + 0xc))(DAT_0e07eddc,0x20);
  return;
}


