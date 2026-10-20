/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e2b78. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e0e2c02) */

void FUN_0e0e2b78(int param_1)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  undefined1 auStack_90 [128];
  
  iVar4 = *(int *)(param_1 + 0x10);
  iVar1 = FUN_0e0e6bce(*(undefined4 *)(param_1 + -0x54),0);
  if (iVar1 - 1U < 0x80) {
    uVar2 = FUN_0e0e6bce(*(undefined4 *)(param_1 + -0x54),auStack_90,0x80);
    if (iVar4 == 2) {
      pcVar3 = *(code **)(*(int *)(param_1 + -0x3c) + 4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(auStack_90,uVar2,*(undefined4 *)(param_1 + -0x38));
      }
    }
    else {
      if (uVar2 < 0xd) {
        return;
      }
      iVar1 = FUN_0e0e74e0(&DAT_0e0e8802,auStack_90,0xd);
      if (iVar1 != 0) {
        return;
      }
      if ((code *)**(undefined4 **)(param_1 + -0x3c) != (code *)0x0) {
        (*(code *)**(undefined4 **)(param_1 + -0x3c))(*(undefined4 *)(param_1 + -0x38));
      }
      *(int *)(param_1 + 0x10) = 2;
    }
    iVar1 = FUN_0e0e6bce(*(undefined4 *)(param_1 + -0x54),0);
    if (iVar1 != 0) {
      FUN_0e0e70ae(0x2f011340,param_1);
    }
  }
  return;
}


