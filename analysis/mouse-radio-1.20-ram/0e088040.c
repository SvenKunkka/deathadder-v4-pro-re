/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e088040. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e0880ea) */

void FUN_0e088040(int param_1)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  int local_90;
  int local_8c;
  int local_88;
  char local_84;
  
  iVar4 = *(int *)(param_1 + 0x10);
  iVar1 = FUN_0e0884b4(*(undefined4 *)(param_1 + -0x54),0);
  if (iVar1 - 1U < 0x80) {
    uVar2 = FUN_0e0884b4(*(undefined4 *)(param_1 + -0x54),&local_90,0x80);
    if (iVar4 == 2) {
      pcVar3 = *(code **)(*(int *)(param_1 + -0x3c) + 4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(&local_90,uVar2,*(undefined4 *)(param_1 + -0x38));
      }
    }
    else {
      if (uVar2 < 0xd) {
        return;
      }
      if (local_90 != 0x6c316d45) {
        return;
      }
      if (local_8c != 0x72304b31) {
        return;
      }
      if (local_88 != 0x696c336e) {
        return;
      }
      if (local_84 != '4') {
        return;
      }
      if ((code *)**(undefined4 **)(param_1 + -0x3c) != (code *)0x0) {
        (*(code *)**(undefined4 **)(param_1 + -0x3c))(*(undefined4 *)(param_1 + -0x38));
      }
      *(int *)(param_1 + 0x10) = 2;
    }
    iVar1 = FUN_0e0884b4(*(undefined4 *)(param_1 + -0x54),0);
    if (iVar1 != 0) {
      FUN_0e0952ac(&DAT_23001cf8,param_1);
    }
  }
  return;
}


