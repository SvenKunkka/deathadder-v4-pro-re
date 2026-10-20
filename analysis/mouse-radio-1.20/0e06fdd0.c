/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06fdd0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e06fdd0(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  
  uVar2 = DAT_23002a98;
  cVar1 = DAT_23002a96;
  if ('\0' < DAT_23002a96) {
    iVar3 = FUN_0e06de44(DAT_23002a98);
    uVar4 = FUN_0e06de3c(uVar2);
    if (iVar3 == 0) {
      if (DAT_230029e0 != '\0') {
        uVar6 = (uint)(ushort)(DAT_23006b8a + 1);
        uVar4 = uVar6;
        if (30000 < uVar6) {
          uVar4 = 0;
        }
        sVar5 = (ushort)DAT_230029e5 + _DAT_23006b88;
        _DAT_23006b88 = uVar4;
        if (uVar6 < 0x7531) {
          _DAT_23006b88 = CONCAT22((short)uVar4,sVar5);
        }
        return;
      }
    }
    else if (*(byte *)((int)&DAT_23002a3a + iVar3) != uVar4) {
      *(char *)((int)&DAT_23002a3a + iVar3) = (char)uVar4;
      FUN_0e0725a0(0,iVar3,&DAT_23002a99,(short)(char)(cVar1 + -2),0);
      DAT_23002a10 = 0;
      DAT_230029d0 = 2;
      return;
    }
  }
  return;
}


