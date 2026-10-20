/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e096ca4. Types and names are inferred; NOT original source. */

undefined4 * FUN_0e096ca4(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int extraout_r3;
  undefined *puVar3;
  
  iVar1 = FUN_0e0956e0();
  if (iVar1 == 0) {
    puVar3 = *(undefined **)(DAT_23007654 + 0x80);
    iVar1 = DAT_23007654;
    if (puVar3 == (undefined *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  else {
    puVar3 = &DAT_23001604;
    iVar1 = extraout_r3;
  }
  if ((param_2 < 0xfffffffc) &&
     (puVar2 = (undefined4 *)FUN_0e09489c(puVar3,param_1 | 4,param_2 + 4,iVar1,0,0),
     puVar2 != (undefined4 *)0x0)) {
    *puVar2 = puVar3;
    return puVar2 + 1;
  }
  return (undefined4 *)0x0;
}


