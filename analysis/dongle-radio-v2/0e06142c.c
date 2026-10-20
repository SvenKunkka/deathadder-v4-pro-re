/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06142c. Types and names are inferred; NOT original source. */

/* WARNING: Control flow encountered bad instruction data */

void FUN_0e06142c(void)

{
  int iVar1;
  
  iVar1 = DAT_0e061460;
  *(uint *)(DAT_0e061460 + 8) = uRam0e06145c & 0xffffff80;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  *(uint *)(iVar1 + 0x88) = *(uint *)(iVar1 + 0x88) & 0xff0fffff;
  FUN_0e06c8f4();
  FUN_0e06e674();
  FUN_0e06152c();
  FUN_0e06c914();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


