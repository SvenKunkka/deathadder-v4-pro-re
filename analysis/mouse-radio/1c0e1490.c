/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e1490. Types and names are inferred; NOT original source. */

void FUN_1c0e1490(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = (uint)*(ushort *)
                 (param_1 +
                 (((uint)*(byte *)(DAT_1c0e14dc + (param_2 >> 5)) + (param_2 & 0x1f) & 0xff) + 8) *
                 2);
  if ((int)(uVar1 << 0x17) < 0) {
    uVar1 = (uVar1 & 0x1fff) >> 9;
    (**(code **)(param_1 + uVar1 * 8))(param_2,param_3,*(undefined4 *)(param_1 + uVar1 * 8 + 4));
  }
  if (*(code **)(param_1 + 8) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x1c0e14d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1 + 8))(param_2,param_3,*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}


