/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e504c. Types and names are inferred; NOT original source. */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0e504c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_0e0e4ec8(0);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(0x2f012818);
  }
  setMainStackPointerLimit(0x2f012018);
  DAT_e000ed22 = 0xe0;
  DAT_e000ed1f = 0;
  DAT_e000ed18 = 0;
  DAT_e000ed19 = 0;
  DAT_e000ed1a = 0;
  _DAT_e000ed24 = _DAT_e000ed24 | 0x70000;
  DAT_e000ed23 = 0;
  FUN_0e0e32a8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0x2f012818,_DAT_e000ed24,param_1,param_2,
               param_3,param_4);
  FUN_0e0e35d8();
  _DAT_e000ed28 = 0xffffffff;
  _DAT_e000ed2c = 0xffffffff;
  FUN_0e0e390c();
  FUN_0e0e363c();
  _DAT_2f0115b4 = 0x101;
  _DAT_2f0118dc = 0x2f0115a8;
  _DAT_2f011618 = 0;
  _DAT_2f01161c = 0;
  _DAT_2f011624 = 0;
  FUN_0e0e74a4();
  FUN_0e0e4ec8(1);
  FUN_0e0e4ec8(2);
  FUN_0e0e5cb0();
  _DAT_2f0118ec = 0x2f011518;
  uVar2 = FUN_0e0e57e4(0x2f011518,0x2f012958,0x400,&LAB_0e0e4ef4_1,0,0,0,0,1,&DAT_0e0e8869);
  DAT_2f011525 = DAT_2f011525 & 0xfb;
  FUN_0e0e71b4(0x2f011518);
  FUN_0e0e4fd0(0);
  FUN_0e0e3590(0x2f011518,uVar2,&LAB_0e0e4ef4_1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


