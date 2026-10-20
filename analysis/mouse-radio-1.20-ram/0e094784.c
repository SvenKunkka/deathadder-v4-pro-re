/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e094784. Types and names are inferred; NOT original source. */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e094784(void)

{
  bool bVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_0e0945a8(0);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(0x230134e0);
  }
  setMainStackPointerLimit(0x23012ae0);
  DAT_e000ed22 = 0xe0;
  DAT_e000ed1f = 0;
  DAT_e000ed18 = 0;
  DAT_e000ed19 = 0;
  DAT_e000ed1a = 0;
  _DAT_e000ed24 = _DAT_e000ed24 | 0x70000;
  DAT_e000ed23 = 0;
  FUN_0e089bf8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),&DAT_230134e0);
  FUN_0e089f9c();
  _DAT_e000ed28 = 0xffffffff;
  _DAT_e000ed2c = 0xffffffff;
  FUN_0e08a2ec();
  FUN_0e08a034();
  DAT_2300255c = 0x101;
  DAT_230025c4 = 0;
  DAT_230025c8 = 0;
  FUN_0e096c98(&DAT_23002550);
  DAT_23007654 = &DAT_23002550;
  FUN_0e09455c();
  FUN_0e0945a8(1);
  FUN_0e0945a8(2);
  FUN_0e095ffc();
  DAT_23007664 = &DAT_23002408;
  uVar2 = FUN_0e095710(&DAT_23002408,&DAT_230136e0,0x400,&LAB_0e0945fc_1,0,0,0,0,1,&DAT_0e09b850);
  DAT_23002415 = DAT_23002415 & 0xfb;
  FUN_0e095bd4(&DAT_23002408);
  FUN_0e094700(0);
  FUN_0e089f44(&DAT_23002408,uVar2,&LAB_0e0945fc_1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


