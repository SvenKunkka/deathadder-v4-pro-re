/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089db8. Types and names are inferred; NOT original source. */

void Reset_Handler(void)

{
  char cVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 extraout_s1;
  undefined8 extraout_d4;
  undefined8 unaff_d14;
  
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setThreadModePrivileged(1);
    bVar2 = (bool)isThreadMode();
    if (bVar2) {
      cVar3 = isUsingMainStack();
      setStackMode(cVar3 == '\x01');
    }
  }
  InstructionSynchronizationBarrier(0xf);
  setMainStackPointerLimit(0);
  setProcStackPointerLimit(0);
  FUN_0e0910c8(0);
  *puRam0e089e0c = 0;
  DataSynchronizationBarrier(0xf);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setMainStackPointer(uRam0e089e10);
  }
  FUN_0e089e3c(uRam0e089e10);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(0x20);
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setProcessStackPointer(iRam0e089e14 + 0xa00);
  }
  cVar3 = isThreadModePrivileged();
  cVar1 = isUsingMainStack();
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setThreadModePrivileged(cVar3 == '\x01');
    bVar2 = (bool)isThreadMode();
    if (bVar2) {
      cVar4 = isUsingMainStack();
      setStackMode(cVar4 == '\x01');
    }
  }
  InstructionSynchronizationBarrier(0xf);
  uVar5 = FUN_0e08a050((cVar1 != '\x01') << 1 | cVar3 != '\x01' | 2);
  vcx3(5,2,unaff_d14,extraout_d4,CONCAT44(extraout_s1,uVar5),0,0x40,0);
  DataSynchronizationBarrier(0xf);
  *(uint *)(DAT_0e089e34 + 0xc) = DAT_0e089e38 | *(uint *)(DAT_0e089e34 + 0xc) & 0x700;
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


