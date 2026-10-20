/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ae550. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0ae550(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  if (DAT_2f01141c == '\0') {
    FUN_0e0b2828(&DAT_2f01138c,0,0x80);
    uVar1 = _DAT_2f01140c;
    iVar4 = *param_1;
    for (uVar3 = 0; uVar1 != uVar3; uVar3 = uVar3 + 1) {
      if ((uVar3 & 0xff) == 0x13) {
        *(undefined4 *)(iVar4 + (uVar3 & 0xff) * 4 + 0x100) = 0;
      }
    }
    *(undefined4 *)(iVar4 + 0x14c) = 0;
    FUN_0e0acb0c(0x69,uVar3,0,*(undefined4 *)(iVar4 + 0x14c));
    uVar2 = 0xbad0000;
    DAT_2f01141c = '\x01';
    _DAT_2f011414 = 1;
  }
  else {
    uVar2 = 0xbad000c;
  }
  return uVar2;
}


