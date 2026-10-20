/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e086c98. Types and names are inferred; NOT original source. */

uint FUN_0e086c98(int param_1)

{
  uint uVar1;
  uint uVar2;
  byte *in_stack_00000000;
  byte *in_stack_00000004;
  byte *pbVar3;
  byte *pbVar4;
  
  pbVar3 = in_stack_00000000;
  pbVar4 = in_stack_00000004;
  uVar1 = FUN_0e086c44();
  if (((((uVar1 == 0) &&
        (uVar2 = FUN_0e085c00(0xff,in_stack_00000000 + 1,0xf), *in_stack_00000000 == uVar2)) &&
       (*(short *)(in_stack_00000000 + 2) == -1)) &&
      ((*(int *)(in_stack_00000000 + 4) == -1 &&
       (uVar2 = FUN_0e085c00(0xff,in_stack_00000004 + 1,0xf,0,pbVar3,pbVar4),
       *in_stack_00000004 == uVar2)))) &&
     ((*(short *)(in_stack_00000004 + 2) == 0 &&
      ((*(int *)(in_stack_00000004 + 4) == -1 &&
       (uVar2 = *(int *)(param_1 + 0x18) - *(int *)(in_stack_00000004 + 8),
       uVar2 == *(uint *)(param_1 + 0x40) * (uVar2 / *(uint *)(param_1 + 0x40)))))))) {
    uVar1 = (uint)(in_stack_00000000[1] == in_stack_00000004[1]);
  }
  return uVar1;
}


