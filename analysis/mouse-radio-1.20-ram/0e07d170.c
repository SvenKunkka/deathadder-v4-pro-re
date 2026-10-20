/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07d170. Types and names are inferred; NOT original source. */

void FUN_0e07d170(void)

{
  byte bVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  
  if (DAT_23007715 == '\0') {
    return;
  }
  pbVar4 = (byte *)0x23003efd;
  pbVar2 = (byte *)0x23003efd;
  bVar1 = 0;
  do {
    bVar3 = bVar1;
    pbVar2 = pbVar2 + 1;
    bVar1 = bVar3 ^ *pbVar2;
  } while (pbVar2 != &DAT_23003f54);
  if (*pbVar2 != bVar3) {
    DAT_23003efc = '\x03';
    goto LAB_0e07d1be;
  }
  DAT_23003efc = '\x01';
  if (DAT_23003f02 < 0x11) {
    switch(DAT_23003f02) {
    case 0:
      FUN_0e07ae74();
      break;
    default:
switchD_0e07d1a4_caseD_1:
      DAT_23003efc = '\x05';
      break;
    case 2:
      FUN_0e07b5e4();
      break;
    case 4:
      FUN_0e07b948();
      break;
    case 5:
      FUN_0e07c98c();
      break;
    case 7:
      FUN_0e07c9e0();
      break;
    case 0xb:
      FUN_0e07c33c();
      break;
    case 0x10:
      FUN_0e07daec();
    }
  }
  else {
    if (DAT_23003f02 != 0xfe) goto switchD_0e07d1a4_caseD_1;
    FUN_0e07cc50();
  }
  DAT_23003f54 = 0;
  do {
    pbVar4 = pbVar4 + 1;
    DAT_23003f54 = DAT_23003f54 ^ *pbVar4;
  } while (pbVar4 != &DAT_23003f53);
  if (DAT_23003efc == '\x01') {
    DAT_23003efc = '\x02';
  }
LAB_0e07d1be:
  DAT_23007715 = 0;
  if (DAT_23007723 != '\x01') {
    DAT_23007715 = 0;
    return;
  }
  ram_candidate_230211dc();
  return;
}


