/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b294c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0b294c(code *param_1)

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
  
  _DAT_2f013620 = getMainStackPointer();
  _DAT_2f013624 = getMainStackPointerLimit();
  _DAT_2f013628 = getProcessStackPointer();
  _DAT_2f01362c = getProcessStackPointerLimit();
  _DAT_2f013630 = (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b;
  _DAT_2f013634 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    _DAT_2f013634 = getCurrentExceptionNumber();
    _DAT_2f013634 = _DAT_2f013634 & 0x1ff;
  }
  _DAT_2f013638 = 0;
  _DAT_2f01363c = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    _DAT_2f01363c = isIRQinterruptsEnabled();
  }
  _DAT_2f013640 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    _DAT_2f013640 = isFIQinterruptsEnabled();
  }
  _DAT_2f013644 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    _DAT_2f013644 = getBasePriority();
  }
  cVar2 = isThreadModePrivileged();
  cVar3 = isUsingMainStack();
  _DAT_2f013648 = (uint)(byte)((cVar3 != '\x01') << 1 | cVar2 != '\x01');
  FUN_0e0b1da2();
  uVar4 = (*param_1)();
  FUN_0e0ad450(uVar4,0xe0b29a1);
  return uVar4;
}


