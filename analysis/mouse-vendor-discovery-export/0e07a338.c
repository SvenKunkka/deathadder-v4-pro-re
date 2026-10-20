
undefined4 vendor_rom_e07a338(void)

{
  byte bVar1;
  uint uVar2;
  uint extraout_r2;
  undefined4 in_r3;
  undefined1 *puVar3;
  undefined1 *extraout_r3;
  
  bVar1 = DAT_2300770e;
  if (DAT_2300770f == '\x01') {
    puVar3 = &DAT_2300770e;
    if (DAT_2300770e == 1) {
      DAT_2300770e = 0;
      uVar2 = (uint)DAT_230076f9;
      if (uVar2 == 0) {
        ram_candidate_23022b80();
        FUN_0e07ad70(&DAT_23003868);
        DAT_230076f9 = bVar1;
        uVar2 = extraout_r2;
        puVar3 = extraout_r3;
      }
      FUN_0e079dd8(1,0,uVar2,puVar3,in_r3);
    }
  }
  if ((DAT_23007703 == '\x01') && (DAT_23007702 == '\x01')) {
    DAT_23007702 = '\0';
    DAT_23007688 = 0;
    DAT_23007686 = 0;
    DAT_23007684 = 0;
    FUN_0e079cac();
  }
  return 0;
}


