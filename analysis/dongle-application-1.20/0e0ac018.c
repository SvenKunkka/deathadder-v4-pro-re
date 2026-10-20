/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ac018. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e0ac0a2) */

void FUN_0e0ac018(int param_1)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  undefined1 auStack_90 [128];
  
  iVar4 = *(int *)(param_1 + 0x10);
  iVar1 = FUN_0e0b1ad6(*(undefined4 *)(param_1 + -0x54),0);
  if (iVar1 - 1U < 0x80) {
    uVar2 = FUN_0e0b1ad6(*(undefined4 *)(param_1 + -0x54),auStack_90,0x80);
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
      iVar1 = FUN_0e0b2838("Em1l1K0rn3li4memory@c000",auStack_90,0xd);
      if (iVar1 != 0) {
        return;
      }
      if ((code *)**(undefined4 **)(param_1 + -0x3c) != (code *)0x0) {
        (*(code *)**(undefined4 **)(param_1 + -0x3c))(*(undefined4 *)(param_1 + -0x38));
      }
      *(int *)(param_1 + 0x10) = 2;
    }
    iVar1 = FUN_0e0b1ad6(*(undefined4 *)(param_1 + -0x54),0);
    if (iVar1 != 0) {
      FUN_0e0b23ba(0x2f0115d0,param_1);
    }
  }
  return;
}


