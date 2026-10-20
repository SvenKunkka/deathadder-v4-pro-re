/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e077ca0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e077ca0(void)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (DAT_23007723 == '\x04') {
    bVar1 = DAT_23004a5d;
    if (DAT_2300779e != '\0') goto joined_r0x0e077d3e;
  }
  else {
    bVar1 = DAT_23004a5f;
    if (DAT_23007723 != '\x01') {
      iVar3 = 0;
      goto LAB_0e077cb2;
    }
joined_r0x0e077d3e:
    if (bVar1 < 8) {
      iVar3 = (short)(ushort)bVar1 * 0x7d + -0x5f;
      goto LAB_0e077cb2;
    }
  }
  iVar3 = 700;
LAB_0e077cb2:
  if (DAT_23004ce4 != iVar3) {
    _DAT_5f9b2540 = 0;
    _DAT_5f9b2544 = 0;
    _DAT_5f9b2548 = 0;
    _DAT_5f9b254c = 0;
    _DAT_5f9b2550 = 0;
    _DAT_5f9b2554 = 0;
    _DAT_5f9b2200 = _DAT_5f9b2200 & 0xff00ff00;
    _DAT_5f9b2308 = 0xff0000;
    DAT_23004ce4 = iVar3;
    uVar2 = FUN_0e0765b8(&DAT_0e099250,iVar3);
    FUN_0e076440(&DAT_0e099250,0,uVar2,0x20000,0);
    uVar2 = FUN_0e0765b8(&DAT_0e099250,iVar3 + 0x1e);
    FUN_0e076440(&DAT_0e099250,1,uVar2,0x20000,1);
  }
  return;
}


