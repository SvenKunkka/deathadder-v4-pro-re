/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ee90. Types and names are inferred; NOT original source. */

undefined4 * FUN_0e06ee90(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = DAT_0e06eec0;
  if (0xfffffffb < param_1) {
    return (undefined4 *)0x0;
  }
  puVar2 = (undefined4 *)FUN_0e06ca6c(DAT_0e06eec0,4,param_1 + 4,param_4,0,0);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = uVar1;
    return puVar2 + 1;
  }
  return (undefined4 *)0x0;
}


