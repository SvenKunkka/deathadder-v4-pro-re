/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0aed58. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0aed58(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  int iVar4;
  
  if (param_1 < 3) {
    iVar1 = FUN_0e0aeac0();
    bVar3 = (byte)*(undefined4 *)(iVar1 + 0x14);
    if (param_1 == 1) {
      bVar3 = 2;
    }
    _DAT_5200d440 = _DAT_0fffe3c8 & 0xff;
    _DAT_5200d444 = *(uint *)(&DAT_0fffe3cc + (uint)bVar3 * 4) & 0xffff;
    _DAT_5200d448 = *(uint *)(&DAT_0fffe3e4 + (uint)bVar3 * 4) & 0xffff;
    _DAT_5200d450 = 0;
    _DAT_5200d480 = 0;
    iVar1 = FUN_0e0aeac0(param_1);
    iVar4 = 50000;
    _DAT_5200d468 = *(uint *)(iVar1 + 0x10) & 0x1f;
    _DAT_5200d014 = 1;
    do {
      if (_DAT_5200d110 != 0) {
        return 0;
      }
      thunk_FUN_0e0b21f6(10);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    uVar2 = 0xffffff8c;
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}


