/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06d0f0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e06d0f0(void)

{
  sbyte sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  uint uVar7;
  uint *puVar8;
  uint local_1c;
  
  thunk_FUN_0e08567c();
  thunk_FUN_0e085008();
  sVar1 = DAT_23000674;
  if (DAT_23006c28 == '\0') {
    uVar7 = (uint)DAT_23007733;
  }
  else {
    uVar5 = (uint)DAT_23006c2e;
    uVar7 = (uint)DAT_23007733;
    if (DAT_23007735 != uVar5) {
      DAT_23007735 = DAT_23006c2e;
      if (uVar5 == 100) {
        uVar5 = 0xff;
        DAT_23007732 = 0xff;
        if (DAT_230077a2 != '\0') {
          DAT_23007731 = 1;
          goto LAB_0e06d276;
        }
      }
      else {
        uVar5 = ((uint)((ulonglong)(uVar5 * 0xff) * 0x51eb851f >> 0x20) & 0x1fff) >> 5;
        uVar4 = uVar5 - 1 & 0xff;
        if (uVar4 < 0xfe) {
          uVar5 = uVar5 + 1;
        }
        DAT_23007731 = 0;
        if (uVar4 < 0xfe) {
          uVar5 = uVar5 & 0xff;
        }
        DAT_23007732 = (undefined1)uVar5;
        if (DAT_230077a2 == '\0') {
          if (uVar7 <= uVar5) goto LAB_0e06d260;
        }
        else {
LAB_0e06d276:
          if (uVar5 <= uVar7) goto LAB_0e06d260;
        }
        DAT_23007733 = (byte)uVar5;
        uVar7 = uVar5;
        if ((DAT_23007723 != '\x04') || (DAT_230077a0 == '\0')) {
          DAT_23007730 = '\x01';
        }
      }
    }
LAB_0e06d260:
    DAT_23006c28 = '\0';
  }
  if (((DAT_23007736 == '\0') || (DAT_2300772d == '\0')) || (DAT_23007690 < 500)) {
    if (DAT_23007730 != '\0') goto LAB_0e06d1be;
  }
  else {
    DAT_2300772d = '\0';
LAB_0e06d1be:
    DAT_23004aa2 = (undefined1)uVar7;
    _DAT_23004aa0 = 0x3105;
    DAT_23004aa3 = 0;
    DAT_23004aa7 = 0;
    DAT_23004aab = 0;
    DAT_23004aaf = 0;
    DAT_23007730 = '\0';
    if (DAT_230077a2 != '\0') {
      puVar8 = *(uint **)(DAT_23000670 + 0x10);
      iVar2 = (**(code **)(*(int *)(DAT_23000670 + 8) + 4))(DAT_23000670,&local_1c);
      if ((iVar2 == 0) && (uVar7 = (uint)DAT_23007733, ((*puVar8 ^ local_1c) & 1 << sVar1) == 0)) {
        DAT_23004aa3 = CONCAT31(DAT_23004aa3._1_3_,1);
      }
      else {
        uVar7 = (uint)DAT_23007733;
        DAT_23004aa3 = (uint)DAT_23004aa3._1_3_ << 8;
      }
    }
    iVar2 = DAT_23004aa3;
    uVar5 = (uint)DAT_2300771c;
    DAT_2300771c = (byte)(uVar5 + 1);
    if (7 < (uVar5 + 1 & 0xff)) {
      DAT_2300771c = 0;
    }
    DAT_23004aa3._3_1_ = SUB41(iVar2,3);
    DAT_23004aa3._0_3_ = CONCAT12(1,CONCAT11(DAT_230077a2,(undefined1)DAT_23004aa3));
    DAT_2300771e = 0x31;
    DAT_230076d2 = DAT_230076d2 | 0x80;
    (&DAT_23004a98)[uVar5] = 0x31;
    (&DAT_23004a90)[uVar5] = 0xff;
  }
  if ((uVar7 < 0x10) && (DAT_230077a2 == '\0')) {
    DAT_2300772f = DAT_23007723 == '\x01';
    if (((uVar7 != 0) || (DAT_2300775e != '\0')) || (DAT_2300775d != '\0')) goto LAB_0e06d132;
    if (2 < DAT_2300772e) {
      thunk_FUN_0e07d6bc(0);
      thunk_FUN_0e0804dc();
      FUN_0e074ecc();
      thunk_FUN_0e07d6d8(0);
      thunk_FUN_0e096164(0x186a,0);
      FUN_0e078c24();
      thunk_FUN_0e0855fc();
      iVar2 = thunk_FUN_0e085198(2);
      if (iVar2 == 0) {
        thunk_FUN_0e07e08c();
        do {
          thunk_FUN_0e089fa8();
        } while( true );
      }
    }
  }
  else {
    DAT_2300772f = false;
LAB_0e06d132:
    DAT_2300772e = 0;
  }
  if (DAT_230077aa == '\0') {
    return;
  }
  if (DAT_23007723 == '\x04') {
joined_r0x0e084654:
    if (((ushort)DAT_23004a8c < 0x2711) && (DAT_23004a8c._2_2_ < 0x2711)) {
      if (((ushort)DAT_23004a8c < 0xfa1) && (DAT_23004a8c._2_2_ < 0xfa1)) {
        if (DAT_230077bc != '\v') {
          FUN_0e083794();
          DAT_230077bc = 0xb;
          return;
        }
      }
      else if (DAT_230077bc != '\f') {
        FUN_0e083bf8();
        DAT_230077bc = 0xc;
        return;
      }
    }
    else if (DAT_230077bc != '\r') {
      FUN_0e08405c();
      DAT_230077bc = 0xd;
      return;
    }
    return;
  }
  if (DAT_23007723 != '\x01') {
    return;
  }
  if (DAT_23004a5f < 2) goto joined_r0x0e084654;
  if (DAT_23004a5f == 2) {
    if ((10000 < (ushort)DAT_23004a8c) || (10000 < DAT_23004a8c._2_2_)) {
      if (DAT_230077bc == '\n') {
        return;
      }
      FUN_0e082a48();
      DAT_230077bc = 10;
      return;
    }
    if (((ushort)DAT_23004a8c < 0xfa1) && (DAT_23004a8c._2_2_ < 0xfa1)) {
      if (DAT_230077bc == '\b') {
        return;
      }
      FUN_0e082170();
      DAT_230077bc = 8;
      return;
    }
    if (DAT_230077bc == '\t') {
      return;
    }
    FUN_0e0825dc();
    DAT_230077bc = 9;
    return;
  }
  if (DAT_23004a5f < 5) {
    if ((10000 < (ushort)DAT_23004a8c) || (10000 < DAT_23004a8c._2_2_)) {
      if (DAT_230077bc == '\a') {
        return;
      }
      FUN_0e081d04();
      DAT_230077bc = 7;
      return;
    }
    if (((ushort)DAT_23004a8c < 0xfa1) && (DAT_23004a8c._2_2_ < 0xfa1)) {
      if (DAT_230077bc == '\x05') {
        return;
      }
      FUN_0e08142c();
      DAT_230077bc = 5;
      return;
    }
    if (DAT_230077bc == '\x06') {
      return;
    }
    FUN_0e081898();
    DAT_230077bc = 6;
    return;
  }
  if (DAT_23004963 == 0xff) {
LAB_0e08474a:
    if (((ushort)DAT_23004a8c < 0xfa1) && (DAT_23004a8c._2_2_ < 0xfa1)) {
      if (DAT_230077bc == '\0') {
        return;
      }
      FUN_0e082eb4();
      DAT_230077bc = 0;
      uVar3 = 1;
    }
    else {
      if (DAT_230077bc == '\x01') {
        return;
      }
      FUN_0e083324();
      DAT_230077bc = 1;
      uVar3 = 0;
    }
    (*(code *)0x230212d5)(uVar3);
    return;
  }
  if (DAT_23004963 == 0) {
    uVar6 = 10000;
    if (10000 < (ushort)DAT_23004a8c) goto LAB_0e084798;
  }
  else {
    if (DAT_23007733 < DAT_23004963) goto LAB_0e08474a;
    uVar6 = 9999;
    if (9999 < (ushort)DAT_23004a8c) goto LAB_0e084798;
  }
  if (DAT_23004a8c._2_2_ <= uVar6) {
    if (((ushort)DAT_23004a8c < 0xfa1) && (DAT_23004a8c._2_2_ < 0xfa1)) {
      if (DAT_230077bc == '\x02') {
        return;
      }
      FUN_0e0806e8();
      DAT_230077bc = 2;
      return;
    }
    if (DAT_230077bc == '\x03') {
      return;
    }
    FUN_0e080b54();
    DAT_230077bc = 3;
    return;
  }
LAB_0e084798:
  if (DAT_230077bc == '\x04') {
    return;
  }
  FUN_0e080fc0();
  DAT_230077bc = 4;
  return;
}


