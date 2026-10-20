/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b207a. Types and names are inferred; NOT original source. */

void FUN_0e0b207a(int param_1,undefined4 param_2,byte *param_3,byte *param_4,byte *param_5,
                 byte *param_6)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined8 uVar11;
  int local_1c;
  byte *pbStack_18;
  
  local_1c = param_1;
  pbStack_18 = param_3;
  uVar11 = FUN_0e0ae034(&local_1c);
  pbVar2 = (byte *)((ulonglong)uVar11 >> 0x20);
  iVar1 = (int)uVar11 + local_1c * 4;
  if (param_4 == (byte *)0x0) {
    uVar8 = 0;
  }
  else {
    uVar8 = 0xc;
  }
  if (param_5 == (byte *)0x0) {
    uVar9 = 0;
  }
  else {
    uVar9 = 0xf00;
  }
  if (param_6 == (byte *)0x0) {
    uVar10 = 0;
  }
  else {
    uVar10 = 0x30000;
  }
  uVar3 = 0;
  if (pbVar2 != (byte *)0x0) {
    uVar3 = (uint)*pbVar2;
  }
  uVar6 = 0;
  if (param_3 != (byte *)0x0) {
    uVar6 = (uint)*param_3 << 1;
  }
  uVar5 = 0;
  if (param_4 != (byte *)0x0) {
    uVar5 = (uint)*param_4 << 2;
  }
  uVar4 = 0;
  if (param_5 != (byte *)0x0) {
    uVar4 = (uint)*param_5 << 8;
  }
  uVar7 = 0;
  if (param_6 != (byte *)0x0) {
    uVar7 = (uint)*param_6 << 0x10;
  }
  *(uint *)(iVar1 + 0x80) =
       uVar4 | uVar3 | *(uint *)(iVar1 + 0x80) &
                       ~((uint)(pbVar2 != (byte *)0x0) | (uint)(param_3 != (byte *)0x0) << 1 | uVar8
                         | uVar9 | uVar10) | uVar6 | uVar5 | uVar7;
  return;
}


