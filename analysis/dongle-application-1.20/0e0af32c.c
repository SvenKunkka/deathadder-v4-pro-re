/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0af32c. Types and names are inferred; NOT original source. */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0af32c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_0e0af1a8(0);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(0x2f012ce0);
  }
  setMainStackPointerLimit(0x2f0124e0);
  DAT_e000ed22 = 0xe0;
  DAT_e000ed1f = 0;
  DAT_e000ed18 = 0;
  DAT_e000ed19 = 0;
  DAT_e000ed1a = 0;
  _DAT_e000ed24 = _DAT_e000ed24 | 0x70000;
  DAT_e000ed23 = 0;
  FUN_0e0ac8dc((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0x2f012ce0,_DAT_e000ed24,param_1,param_2,
               param_3,param_4);
  FUN_0e0acc0c();
  _DAT_e000ed28 = 0xffffffff;
  _DAT_e000ed2c = 0xffffffff;
  FUN_0e0acf40();
  FUN_0e0acc70();
  _DAT_2f011844 = 0x101;
  _DAT_2f011ba0 = 0x2f011838;
  _DAT_2f0118a8 = 0;
  _DAT_2f0118ac = 0;
  _DAT_2f0118b4 = 0;
  FUN_0e0b21fe();
  FUN_0e0af1a8(1);
  FUN_0e0af1a8(2);
  FUN_0e0aff9c();
  _DAT_2f011bb0 = 0x2f0117a8;
  uVar2 = FUN_0e0afad0(0x2f0117a8,0x2f012e20,0x400,&LAB_0e0af1d4_1,0,0,0,0,1,&DAT_0e0b3ebf);
  DAT_2f0117b5 = DAT_2f0117b5 & 0xfb;
  FUN_0e0b24cc(0x2f0117a8);
  FUN_0e0af2b0(0);
  FUN_0e0acbc4(0x2f0117a8,uVar2,&LAB_0e0af1d4_1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


