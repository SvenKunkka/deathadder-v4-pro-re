/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e084a1c. Types and names are inferred; NOT original source. */

void FUN_0e084a1c(void)

{
  int iVar1;
  undefined1 *puVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  undefined4 extraout_r1;
  int iVar6;
  int iVar7;
  
  FUN_0e097512(DAT_0e084acc,0,0x510);
  FUN_0e094d84(DAT_0e084ad0,extraout_r1,0x9d,0);
  FUN_0e0977f8(0x7f,0);
  bVar3 = FUN_0e0977a8(0x40);
  FUN_0e0977f8(0x55,4);
  FUN_0e0977f8(0x40,0x80);
  uVar4 = FUN_0e0977a8(2);
  if ((uVar4 & 3) == 0) {
    FUN_0e0977f8(0x1a,0x81);
    while (iVar5 = FUN_0e0977a8(0x1a), puVar2 = DAT_0e084ad4, iVar1 = DAT_0e084acc, iVar5 != 0x81) {
      FUN_0e09628c(0x20,0);
    }
    iVar7 = DAT_0e084acc + 0x510;
    *DAT_0e084ad4 = 0;
    iVar5 = iVar1;
    do {
      iVar6 = iVar5 + 0x24;
      FUN_0e097630((0x1b - iVar1) + iVar5 & 0xff,iVar5);
      iVar5 = iVar6;
    } while (iVar6 != iVar7);
    *puVar2 = 0;
  }
  FUN_0e0977f8(0x40,bVar3 | 0x80);
  FUN_0e0977f8(0x55,0);
  FUN_0e094e80(DAT_0e084ad0);
  return;
}


