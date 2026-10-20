/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e75d0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0e75d0(code *param_1)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  undefined4 uVar4;
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  _DAT_2f013158 = getMainStackPointer();
  _DAT_2f01315c = getMainStackPointerLimit();
  _DAT_2f013160 = getProcessStackPointer();
  _DAT_2f013164 = getProcessStackPointerLimit();
  _DAT_2f013168 = (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b;
  _DAT_2f01316c = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    _DAT_2f01316c = getCurrentExceptionNumber();
    _DAT_2f01316c = _DAT_2f01316c & 0x1ff;
  }
  _DAT_2f013170 = 0;
  _DAT_2f013174 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    _DAT_2f013174 = isIRQinterruptsEnabled();
  }
  _DAT_2f013178 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    _DAT_2f013178 = isFIQinterruptsEnabled();
  }
  _DAT_2f01317c = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    _DAT_2f01317c = getBasePriority();
  }
  cVar2 = isThreadModePrivileged();
  cVar3 = isUsingMainStack();
  _DAT_2f013180 = (uint)(byte)((cVar3 != '\x01') << 1 | cVar2 != '\x01');
  FUN_0e0e6d64();
  uVar4 = (*param_1)();
  FUN_0e0e3e1c(uVar4,0xe0e7625);
  return uVar4;
}


