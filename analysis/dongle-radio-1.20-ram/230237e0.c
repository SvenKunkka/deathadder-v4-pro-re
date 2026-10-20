/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230237e0. Types and names are inferred; NOT original source. */

undefined4 FUN_230237e0(void)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  do {
    puVar2 = (undefined4 *)FUN_230207ec(0,uVar3 & 0xffff);
    uVar4 = uVar3 + 1;
    if (puVar2 != (undefined4 *)0x0) {
      DAT_2300347e._0_2_ = (undefined2)uVar3;
      DAT_23003488 = 1;
      goto LAB_23023852;
    }
    uVar3 = uVar4;
  } while (uVar4 != 6);
  DAT_230053e4 = 5;
  DAT_230053e6 = FUN_230209dc(0,DAT_23005397);
  DAT_23005397 = DAT_23005397 + '\x01';
  DAT_230053e8._0_1_ = DAT_23005349 & 0xf | DAT_2300534a << 4;
  DAT_230053e7 = 0x1f;
  if (DAT_23005397 == '\b') {
    puVar2 = (undefined4 *)&DAT_230053e4;
    DAT_23005397 = '\x01';
  }
  else {
    puVar2 = (undefined4 *)&DAT_230053e4;
  }
LAB_23023852:
  uVar1 = FUN_230209bc(1,DAT_23003488,
                       *(undefined1 *)((int)&DAT_230033e8 + (DAT_230032ca + 0xfcc) * 2));
  *(undefined1 *)((int)puVar2 + 1) = uVar1;
  DAT_23003070 = *puVar2;
  DAT_23003074 = puVar2[1];
  DAT_23003078 = puVar2[2];
  DAT_2300307c = puVar2[3];
  RADIO_S_PACKETPTR = 0x23003070;
  return 1;
}


