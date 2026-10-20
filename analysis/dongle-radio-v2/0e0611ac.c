/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0611ac. Types and names are inferred; NOT original source. */

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
  FUN_0e068ae0(0);
  *puRam0e061200 = 0;
  DataSynchronizationBarrier(0xf);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setMainStackPointer(uRam0e061204);
  }
  FUN_0e061230(uRam0e061204);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(0x40);
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setProcessStackPointer(iRam0e061208 + 0x800);
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
  uVar5 = FUN_0e06142c((cVar1 != '\x01') << 1 | cVar3 != '\x01' | 2);
  vcx3(5,2,unaff_d14,extraout_d4,CONCAT44(extraout_s1,uVar5),0,0x40,0);
  DataSynchronizationBarrier(0xf);
  *(uint *)(DAT_0e061228 + 0xc) = DAT_0e06122c | *(uint *)(DAT_0e061228 + 0xc) & 0x700;
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


