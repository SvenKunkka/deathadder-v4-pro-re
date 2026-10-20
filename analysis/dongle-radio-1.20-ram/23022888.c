/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23022888. Types and names are inferred; NOT original source. */

void FUN_23022888(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  char cVar5;
  ushort uVar6;
  ushort uVar7;
  
  switch((&DAT_23003468)[param_1 * 0x3e1]) {
  case 7:
    if (param_2 != 1) {
      return;
    }
    iVar4 = param_1 * 0xf84;
    RADIO_S_PACKETPTR = (dword)(&DAT_230034bc + iVar4);
    sVar1 = (&DAT_230034b6)[param_1 * 0x7c2];
    if ((sVar1 == 0) || ((&DAT_230034b6)[param_1 * 0x7c2] = sVar1 + -1, sVar1 != 1)) {
      if ((&DAT_230034b0)[param_1 * 0x7c2] == 0) goto LAB_2302291e;
    }
    else {
      (&DAT_230034b0)[param_1 * 0x7c2] = 0;
LAB_2302291e:
      iVar2 = param_1 * 0xf84;
      if ((DAT_23005376 & 1) == 0) {
        uVar6 = DAT_23005376 & 3;
        uVar7 = DAT_23005376 & 3;
        (&DAT_230034b4)[param_1 * 0x7c2] = (&DAT_230034b4)[param_1 * 0x7c2] + 1;
        if (uVar6 == 0) {
          if (*(int *)(&DAT_23003410 + iVar2) == 0) {
            if ((&DAT_230033fc)[param_1 * 0x3e1] == 0) goto LAB_230229c8;
            FUN_23022360(param_1);
          }
          else {
            (&DAT_230034bc)[iVar4] = 7;
            uVar3 = FUN_23020978(uVar7,param_1 & 0xff,1);
            (&DAT_230034bd)[iVar4] = uVar3;
            uVar3 = FUN_230209dc(uVar7,(&DAT_2300348f)[iVar2]);
            (&DAT_230034be)[iVar4] = uVar3;
            (&DAT_230034bf)[iVar4] = 0x24;
            cVar5 = (&DAT_2300348f)[iVar2] + '\x01';
            if (cVar5 == '\b') {
              cVar5 = '\x01';
            }
            (&DAT_2300348f)[iVar2] = cVar5;
          }
        }
        else {
LAB_230229c8:
          FUN_23022360(param_1);
        }
      }
      else if ((ushort)(&DAT_230034b4)[param_1 * 0x7c2] < 0x14) {
        thunk_FUN_0e06f3aa(&DAT_230034bc + iVar4,0,0x20);
      }
      else {
        uVar6 = (&DAT_230034b2)[param_1 * 0x7c2] + 1;
        if (3 < uVar6) {
          uVar6 = 0;
        }
        (&DAT_230034b2)[param_1 * 0x7c2] = uVar6;
        (&DAT_230034b4)[param_1 * 0x7c2] = 0;
        FUN_23020f1c(&DAT_23003468 + param_1 * 0x3e1,&RADIO_S_TASKS_DISABLE,7,uVar6,param_4);
        RADIO_S_SUBSCRIBE_DISABLE = 0;
        RADIO_S_SUBSCRIBE_DISABLE = 0;
      }
    }
    if ((DAT_23005376 & 1) == 0) {
      (&DAT_23003468)[param_1 * 0x3e1] = 8;
    }
    else {
      (&DAT_23003468)[param_1 * 0x3e1] = 9;
      (&DAT_230034bc)[param_1 * 0xf84] = 0;
    }
    break;
  case 8:
    if (param_2 == 1) {
      FUN_23020f1c(&DAT_23003468 + param_1 * 0x3e1,&RADIO_S_TASKS_DISABLE,7,0xf84,param_4);
      (&DAT_230034b0)[param_1 * 0x7c2] = 0;
    }
    break;
  case 9:
    if (param_2 == 2) {
      (&DAT_23003468)[param_1 * 0x3e1] = 7;
      (&DAT_230034b0)[param_1 * 0x7c2] = 0;
    }
    break;
  case 0xb:
    if (param_2 == 1) {
      RADIO_S_PACKETPTR = 0x23003050;
      DAT_23003050._0_1_ = 0;
      (&DAT_23003468)[param_1 * 0x3e1] = 0xc;
    }
  }
  return;
}


