/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078be4. Types and names are inferred; NOT original source. */

void FUN_0e078be4(void)

{
  byte bVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_23007715 == '\0') goto LAB_0e07d1ca;
  pbVar4 = (byte *)0x23003efd;
  pbVar2 = (byte *)0x23003efd;
  bVar1 = 0;
  do {
    bVar3 = bVar1;
    pbVar2 = pbVar2 + 1;
    bVar1 = bVar3 ^ *pbVar2;
  } while (pbVar2 != &DAT_23003f54);
  if (*pbVar2 == bVar3) {
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
    } while (pbVar4 != (byte *)0x23003f53);
    if (DAT_23003efc == '\x01') {
      DAT_23003efc = '\x02';
    }
  }
  else {
    DAT_23003efc = '\x03';
  }
  DAT_23007715 = '\0';
  if (DAT_23007723 == '\x01') {
    (*(code *)0x230211dd)();
    return;
  }
LAB_0e07d1ca:
                    /* WARNING: Could not recover jumptable at 0x0e07d1ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


