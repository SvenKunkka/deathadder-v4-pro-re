/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c878. Types and names are inferred; NOT original source. */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e06c878(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  FUN_0e06c720(0);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(0x23013100);
  }
  setMainStackPointerLimit(0x23012900);
  DAT_e000ed22 = 0xe0;
  DAT_e000ed1f = 0x20;
  DAT_e000ed18 = 0;
  DAT_e000ed19 = 0;
  DAT_e000ed1a = 0;
  _DAT_e000ed24 = _DAT_e000ed24 | 0x70000;
  DAT_e000ed23 = 0;
  FUN_0e061078();
  FUN_0e061404();
  _DAT_e000ed28 = 0xffffffff;
  _DAT_e000ed2c = 0xffffffff;
  FUN_0e06173c();
  FUN_0e061484();
  DAT_23002bdc = 0x101;
  DAT_23002c44 = 0;
  DAT_23002c48 = 0;
  FUN_0e06ee28(&DAT_23002bd0);
  DAT_23007170 = &DAT_23002bd0;
  FUN_0e06c6bc();
  FUN_0e06c720(1);
  FUN_0e06c720(2);
  FUN_0e06e1cc();
  DAT_2300717c = &DAT_23002a88;
  uVar2 = FUN_0e06d860(&DAT_23002a88,&DAT_23013240,0x400,&LAB_0e06c774_1,0,0,0,0,1,&DAT_0e07081c);
  DAT_23002a95 = DAT_23002a95 & 0xfb;
  FUN_0e06dd24(&DAT_23002a88);
  FUN_0e06d860(&DAT_230029f8,&DAT_23013100,0x140,&LAB_0e06cba0_1,&DAT_23007168,0,0,0xf,1,0);
  DAT_23002a05 = DAT_23002a05 & 0xfb;
  DAT_23007178 = 0;
  DAT_2300716c = &DAT_23013100;
  DAT_23007174 = &DAT_230029f8;
  FUN_0e0613ac(&DAT_23002a88,uVar2,&LAB_0e06c774_1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


