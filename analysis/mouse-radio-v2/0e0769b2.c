/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0769b2. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0769b2(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  iVar1 = DAT_0e0769f0;
  puVar3 = *(undefined4 **)(DAT_0e0769f0 + 8);
  iVar2 = (*(code *)*puVar3)(DAT_0e0769f0,DAT_0e0769f4);
  if ((iVar2 == 0) && (iVar2 = (*(code *)*puVar3)(iVar1,DAT_0e0769f8), iVar2 == 0)) {
    local_24 = *DAT_0e0769fc;
    uStack_20 = DAT_0e0769fc[1];
    uStack_1c = DAT_0e0769fc[2];
    uStack_18 = DAT_0e0769fc[3];
    local_14 = DAT_0e0769fc[4];
    (*(code *)puVar3[1])(iVar1,&local_24);
  }
  return 0;
}


