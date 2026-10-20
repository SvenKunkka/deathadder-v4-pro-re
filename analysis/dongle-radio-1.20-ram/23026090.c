/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026090. Types and names are inferred; NOT original source. */

void FUN_23026090(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte bVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  
  if (DAT_230071bb != '\0') {
    pbVar5 = &DAT_23002d1d;
    pbVar3 = &DAT_23002d1d;
    bVar1 = 0;
    do {
      bVar4 = bVar1;
      pbVar3 = pbVar3 + 1;
      bVar1 = bVar4 ^ *pbVar3;
    } while (pbVar3 != &DAT_23002d74);
    if (*pbVar3 == bVar4) {
      bVar1 = DAT_23002d1d >> 5;
      if (bVar1 == 0) {
        iVar6 = 1;
      }
      else if (bVar1 == 4) {
        iVar6 = 2;
      }
      else if (bVar1 == 7) {
        iVar6 = 0;
      }
      else {
        iVar6 = 0xff;
      }
      FUN_2302604c();
      if (DAT_23002d1c == '\x01') {
        iVar2 = FUN_230204ac();
        if ((iVar2 >> iVar6 & 1U) == 0) {
          DAT_23002d1c = '\x04';
          DAT_23002d74 = 0;
          do {
            pbVar5 = pbVar5 + 1;
            DAT_23002d74 = DAT_23002d74 ^ *pbVar5;
          } while (pbVar5 != (byte *)0x23002d73);
        }
        else if (iVar6 - 1U < 2) {
          uVar7 = (uint)DAT_23002d21;
          DAT_23002cb9 = DAT_23002d74;
          DAT_23002cb8 = 0x5a;
          thunk_FUN_0e06f35c(&DAT_23002cba,&DAT_23002d1c,uVar7 + 8);
          FUN_230205c8(iVar6,&DAT_23002cb8,uVar7 + 10);
        }
        else {
          DAT_23002d74 = 0;
          DAT_23002d1c = '\x03';
          do {
            pbVar5 = pbVar5 + 1;
            DAT_23002d74 = DAT_23002d74 ^ *pbVar5;
          } while (pbVar5 != (byte *)0x23002d73);
        }
      }
      else {
        DAT_23002d74 = 0;
        do {
          pbVar5 = pbVar5 + 1;
          DAT_23002d74 = DAT_23002d74 ^ *pbVar5;
        } while (pbVar5 != (byte *)0x23002d73);
      }
    }
    else {
      DAT_23002d1c = '\x03';
    }
    DAT_230071bb = '\0';
  }
  return;
}


