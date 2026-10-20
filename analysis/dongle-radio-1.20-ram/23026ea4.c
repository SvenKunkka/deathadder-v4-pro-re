/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026ea4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23026ea4(void)

{
  int iVar1;
  undefined4 in_r3;
  uint uVar2;
  
  uVar2 = (uint)DAT_230071ba;
  if ((uVar2 != 0) && (DAT_2300719e == 0)) {
    if ((int)(uVar2 << 0x1e) < 0) {
      DAT_23002db0 = 0x46;
      DAT_23002df4 = ram_candidate_23020000(&DAT_23002db0,0x44,0,uVar2,in_r3);
      iVar1 = FUN_23025924(0,0xa001,&DAT_23002db0,0x46);
      uVar2 = (uint)DAT_230071ba;
      if (iVar1 != 0) {
        uVar2 = uVar2 & 0xfd;
        DAT_230071ba = (byte)uVar2;
      }
    }
    if ((int)(uVar2 << 0x1f) < 0) {
      DAT_23002d80._0_2_ = 0x2f;
      register0x00000020 = ram_candidate_23020000(&DAT_23002d80,0x2d,0,uVar2 << 0x1f,in_r3);
      iVar1 = FUN_23025924(1,0xa002,&DAT_23002d80,0x2f);
      if (iVar1 != 0) {
        DAT_230071ba = DAT_230071ba & 0xfe;
        return;
      }
    }
  }
  return;
}


