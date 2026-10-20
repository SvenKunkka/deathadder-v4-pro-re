/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302996c. Types and names are inferred; NOT original source. */

undefined4 FUN_2302996c(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  undefined1 *puVar6;
  byte bVar7;
  
  if (DAT_23001454 != '\0') {
    return 0xbad000c;
  }
  iVar3 = 0x10;
  uVar2 = 0xe080;
  uVar5 = 0;
  do {
    iVar3 = iVar3 + -1;
    uVar5 = uVar5 + (uVar2 & 1) & 0xff;
    uVar2 = uVar2 >> 1;
  } while (iVar3 != 0);
  if (uVar5 == 4) {
    bVar7 = 0;
    puVar6 = &DAT_23001454;
    do {
      while (bVar7 == 0) {
        puVar6[0x14] = 7;
        puVar6 = puVar6 + 0xc;
        bVar7 = 1;
      }
      while (1 < bVar7) {
        iVar3 = 0xd;
        bVar4 = 1;
        uVar5 = 0xe000;
        do {
          uVar5 = uVar5 & ~(1 << iVar3);
          bVar1 = (byte)(uVar5 >> 8);
          bVar4 = bVar4 + 1;
          iVar3 = LZCOUNT((uint)(byte)(((bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7)
                          << 0x10);
        } while (bVar7 != bVar4);
        puVar6[0x14] = (char)iVar3;
        if (bVar7 == 3) {
          uVar5 = 0;
          do {
            uVar2 = 1 << (uVar5 >> 2 & 0xff);
            if ((uVar2 & 0xe080) != 0) {
              *(undefined4 *)(uVar5 + 0x5f99c100) = 0;
              uVar2 = *(uint *)(uVar5 + 0x5f99c100);
            }
            uVar5 = uVar5 + 4;
          } while (uVar5 != 0x40);
          thunk_FUN_0e089e2c(0x6d,0x5f99c100,0x40,uVar2);
          DAT_23001454 = 1;
          return 0xbad0000;
        }
        puVar6 = puVar6 + 0xc;
        bVar7 = 3;
      }
      bVar7 = 2;
      puVar6[0x14] = 0xd;
      puVar6 = puVar6 + 0xc;
    } while( true );
  }
  return 0xbad0001;
}


