/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08a050. Types and names are inferred; NOT original source. */

/* WARNING: Control flow encountered bad instruction data */

void FUN_0e08a050(void)

{
  int iVar1;
  
  iVar1 = DAT_0e08a084;
  *(uint *)(DAT_0e08a084 + 8) = uRam0e08a080 & 0xffffff80;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  *(uint *)(iVar1 + 0x88) = *(uint *)(iVar1 + 0x88) & 0xff0fffff;
  FUN_0e094808();
  FUN_0e09652c();
  FUN_0e08a150();
  FUN_0e0948ac();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


