/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07d590. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e07d590(void)

{
  int iVar1;
  undefined4 in_r3;
  uint uVar2;
  
  uVar2 = (uint)DAT_23007726;
  if ((uVar2 != 0) && (DAT_2300768e == 0)) {
    if ((int)(uVar2 << 0x1e) < 0) {
      _DAT_230049ac = 0x29;
      DAT_230049d3 = FUN_0e07f970(&DAT_230049ac,0x27,0,uVar2,in_r3);
      iVar1 = FUN_0e07ddfc(0,0xa001,&DAT_230049ac,0x29);
      uVar2 = (uint)DAT_23007726;
      if (iVar1 != 0) {
        uVar2 = uVar2 & 0xfd;
        DAT_23007726 = (byte)uVar2;
      }
    }
    if ((int)(uVar2 << 0x1f) < 0) {
      DAT_23004958 = 0x54;
      DAT_230049aa = FUN_0e07f970(&DAT_23004958,0x52,0,uVar2,in_r3);
      iVar1 = FUN_0e07ddfc(1,0xa002,&DAT_23004958,0x54);
      uVar2 = (uint)DAT_23007726;
      if (iVar1 != 0) {
        uVar2 = uVar2 & 0xfe;
        DAT_23007726 = (byte)uVar2;
      }
    }
    if ((int)(uVar2 << 0x1d) < 0) {
      DAT_23004474 = 0x4e4;
      DAT_23004956 = FUN_0e07f970(&DAT_23004474,0x4e2,0,uVar2,in_r3);
      iVar1 = FUN_0e07ddfc(2,0xa003,&DAT_23004474,0x4e4);
      if (iVar1 != 0) {
        DAT_23007726 = DAT_23007726 & 0xfb;
      }
    }
  }
  uVar2 = (uint)DAT_23007725;
  if ((int)(uVar2 << 0x1f) < 0) {
    uVar2 = uVar2 & 0xfe;
    DAT_23007725 = (byte)uVar2;
  }
  if ((int)(uVar2 << 0x1e) < 0) {
    uVar2 = uVar2 & 0xfd;
    DAT_23007725 = (byte)uVar2;
  }
  if ((int)(uVar2 << 0x1d) < 0) {
    uVar2 = uVar2 & 0xfb;
    DAT_23007725 = (byte)uVar2;
  }
  if ((int)(uVar2 << 0x1c) < 0) {
    DAT_230053fc = FUN_0e07f970(&DAT_23004e20,0x5dc,0,uVar2 << 0x1c,in_r3);
    iVar1 = FUN_0e07ddfc(4,0xa006,&DAT_23004e20,0x5de);
    if (iVar1 != 0) {
      DAT_23007725 = DAT_23007725 & 0xf7;
      return;
    }
  }
  return;
}


