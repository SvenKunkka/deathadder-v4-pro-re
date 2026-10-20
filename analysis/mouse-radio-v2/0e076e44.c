/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e076e44. Types and names are inferred; NOT original source. */

void FUN_0e076e44(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  code *pcVar4;
  
  iVar1 = DAT_0e076eb0;
  if (**(int **)(DAT_0e076eb0 + 0x10) << 0x18 < 0) {
    pcVar4 = *(code **)(*(int *)(DAT_0e076eb0 + 8) + 0x10);
  }
  else {
    pcVar4 = *(code **)(*(int *)(DAT_0e076eb0 + 8) + 0xc);
  }
  (*pcVar4)(DAT_0e076eb0,0x80);
  if (**(int **)(iVar1 + 0x10) << 0x1c < 0) {
    pcVar4 = *(code **)(*(int *)(iVar1 + 8) + 0x10);
  }
  else {
    pcVar4 = *(code **)(*(int *)(iVar1 + 8) + 0xc);
  }
  (*pcVar4)(DAT_0e076eb0,8);
  if (**(int **)(iVar1 + 0x10) << 0x19 < 0) {
    pcVar4 = *(code **)(*(int *)(iVar1 + 8) + 0x10);
  }
  else {
    pcVar4 = *(code **)(*(int *)(iVar1 + 8) + 0xc);
  }
  (*pcVar4)(DAT_0e076eb0,0x40);
  iVar2 = thunk_FUN_0e094688(DAT_0e076eb0);
  if (iVar2 != 0) {
    puVar3 = *(undefined4 **)(iVar1 + 8);
    **(uint **)(iVar1 + 0x10) = **(uint **)(iVar1 + 0x10) & 0xffffffdf;
    (*(code *)*puVar3)(DAT_0e076eb0,5,DAT_0e076eb4);
    return;
  }
  return;
}


