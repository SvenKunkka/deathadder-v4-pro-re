/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23020954. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23020954(void)

{
  sbyte sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint local_1c;
  
  thunk_FUN_0e08567c();
  thunk_FUN_0e085008();
  sVar1 = DAT_23000674;
  if (DAT_23006c28 == '\0') {
    uVar5 = (uint)DAT_23007733;
  }
  else {
    uVar4 = (uint)DAT_23006c2e;
    uVar5 = (uint)DAT_23007733;
    if (DAT_23007735 != uVar4) {
      DAT_23007735 = DAT_23006c2e;
      if (uVar4 == 100) {
        uVar4 = 0xff;
        DAT_23007732 = 0xff;
        if (DAT_230077a2 != '\0') {
          DAT_23007731 = 1;
          goto LAB_23020ada;
        }
      }
      else {
        uVar4 = ((uint)((ulonglong)(uVar4 * 0xff) * 0x51eb851f >> 0x20) & 0x1fff) >> 5;
        uVar3 = uVar4 - 1 & 0xff;
        if (uVar3 < 0xfe) {
          uVar4 = uVar4 + 1;
        }
        DAT_23007731 = 0;
        if (uVar3 < 0xfe) {
          uVar4 = uVar4 & 0xff;
        }
        DAT_23007732 = (undefined1)uVar4;
        if (DAT_230077a2 == '\0') {
          if (uVar5 <= uVar4) goto LAB_23020ac4;
        }
        else {
LAB_23020ada:
          if (uVar4 <= uVar5) goto LAB_23020ac4;
        }
        DAT_23007733 = (byte)uVar4;
        uVar5 = uVar4;
        if ((DAT_23007723 != '\x04') || (DAT_230077a0 == '\0')) {
          DAT_23007730 = '\x01';
        }
      }
    }
LAB_23020ac4:
    DAT_23006c28 = '\0';
  }
  if (((DAT_23007736 == '\0') || (DAT_2300772d == '\0')) || (DAT_23007690 < 500)) {
    if (DAT_23007730 != '\0') goto LAB_23020a22;
  }
  else {
    DAT_2300772d = '\0';
LAB_23020a22:
    DAT_23004aa2 = (undefined1)uVar5;
    _DAT_23004aa0 = 0x3105;
    DAT_23004aa3 = 0;
    DAT_23004aa7 = 0;
    DAT_23004aab = 0;
    DAT_23004aaf = 0;
    DAT_23007730 = '\0';
    if (DAT_230077a2 != '\0') {
      puVar6 = *(uint **)(DAT_23000670 + 0x10);
      iVar2 = (**(code **)(*(int *)(DAT_23000670 + 8) + 4))(DAT_23000670,&local_1c);
      if ((iVar2 == 0) && (uVar5 = (uint)DAT_23007733, ((*puVar6 ^ local_1c) & 1 << sVar1) == 0)) {
        DAT_23004aa3 = CONCAT31(DAT_23004aa3._1_3_,1);
      }
      else {
        uVar5 = (uint)DAT_23007733;
        DAT_23004aa3 = (uint)DAT_23004aa3._1_3_ << 8;
      }
    }
    iVar2 = DAT_23004aa3;
    uVar4 = (uint)DAT_2300771c;
    DAT_2300771c = (byte)(uVar4 + 1);
    if (7 < (uVar4 + 1 & 0xff)) {
      DAT_2300771c = 0;
    }
    DAT_23004aa3._3_1_ = SUB41(iVar2,3);
    DAT_23004aa3._0_3_ = CONCAT12(1,CONCAT11(DAT_230077a2,(undefined1)DAT_23004aa3));
    DAT_2300771e = 0x31;
    DAT_230076d2 = DAT_230076d2 | 0x80;
    *(undefined1 *)((int)&DAT_23004a98 + uVar4) = 0x31;
    *(undefined1 *)((int)&DAT_23004a90 + uVar4) = 0xff;
  }
  if ((uVar5 < 0x10) && (DAT_230077a2 == '\0')) {
    DAT_2300772f = DAT_23007723 == '\x01';
    if (((uVar5 == 0) && (DAT_2300775e == '\0')) && (DAT_2300775d == '\0')) {
      if (2 < DAT_2300772e) {
        thunk_FUN_0e07d6bc(0);
        thunk_FUN_0e0804dc();
        FUN_23028730();
        thunk_FUN_0e07d6d8(0);
        thunk_FUN_0e096164(0x186a,0);
        thunk_FUN_0e07eda0();
        thunk_FUN_0e0855fc();
        iVar2 = thunk_FUN_0e085198(2);
        if (iVar2 == 0) {
          thunk_FUN_0e0908ec();
          do {
            thunk_FUN_0e089fa8();
          } while( true );
        }
      }
      goto LAB_2302099c;
    }
  }
  else {
    DAT_2300772f = false;
  }
  DAT_2300772e = 0;
LAB_2302099c:
  (*(code *)0xe084635)((undefined2)DAT_23004a8c,DAT_23004a8c._2_2_);
  return;
}


