/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f2c44. Types and names are inferred; NOT original source. */

void FUN_1c0f2c44(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = param_1[6];
  uVar3 = uVar1 + param_1[0x10] * -2;
  param_4 = param_4 - (uint)(uVar1 < (uint)(param_1[0x10] * 2));
  iVar2 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                    (param_1[0xe],param_4 * uVar1 + *param_1 + uVar3,param_6,0x10);
  if (iVar2 != 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x1c0f2c96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)**(undefined4 **)(param_1[0xe] + 8))
            (param_1[0xe],
             (param_4 + (uint)CARRY4(param_1[0x10],uVar3)) * param_1[6] +
             *param_1 + param_1[0x10] + uVar3,param_5,0x10);
  return;
}


