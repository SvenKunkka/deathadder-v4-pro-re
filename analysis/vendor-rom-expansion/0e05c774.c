
undefined4 vendor_rom_e05c774(void)

{
  byte bVar1;
  uint uVar2;
  uint extraout_r2;
  undefined4 in_r3;
  undefined1 *puVar3;
  undefined1 *extraout_r3;
  
  bVar1 = DAT_230071dc;
  if (DAT_230071dd == '\x01') {
    puVar3 = &DAT_230071dc;
    if (DAT_230071dc == 1) {
      DAT_230071dc = 0;
      uVar2 = (uint)DAT_230071c7;
      if (uVar2 == 0) {
        ram_candidate_23021d9c();
        FUN_0e05d1ac(&DAT_230065e8);
        DAT_230071c7 = bVar1;
        uVar2 = extraout_r2;
        puVar3 = extraout_r3;
      }
      FUN_0e05c214(1,0,uVar2,puVar3,in_r3);
    }
  }
  if ((DAT_230071d1 == '\x01') && (DAT_230071d0 == '\x01')) {
    DAT_230071d0 = '\0';
    DAT_230071aa = 0;
    DAT_230071a8 = 0;
    DAT_230071a6 = 0;
    FUN_0e05c0e8();
  }
  return 0;
}


