/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026d28. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23026d28(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  
  bVar1 = (byte)DAT_23006904;
  iVar6 = 0x15;
  do {
    _DAT_5f9a2048 = 1;
    if ((0x44 < _DAT_5f9a2548 - 1U) || ((byte)DAT_23006838 != (byte)DAT_23006834)) break;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  puVar5 = (undefined4 *)0x23001e80;
  if ((DAT_23006830 & 1) == 0) {
    puVar5 = &DAT_23001e60;
  }
  bVar2 = DAT_23006902;
  bVar3 = DAT_2300690a;
  if (DAT_230071e4 != '\0') {
    if (((byte)DAT_23006904 < 2) && (uVar8 = (uint)(byte)DAT_23006834, (byte)DAT_23006838 != uVar8))
    {
      if (uVar8 < 4) {
        uVar4 = *(undefined4 *)(&DAT_23006840 + uVar8 * 0x10);
        *puVar5 = *(undefined4 *)(&DAT_2300683c + uVar8 * 0x10);
        puVar5[1] = uVar4;
        if (bVar1 < 2) {
          DAT_23006904._0_1_ = (byte)DAT_23006904 + 1;
        }
        iVar6 = thunk_FUN_0e064504(&PTR_s_hid_dev_0_0e06f6a4,8);
        if (iVar6 == 0) {
          cVar7 = (byte)DAT_23006834 + '\x01';
          if (cVar7 == '\x04') {
            cVar7 = '\0';
          }
          DAT_23006830 = 1 - DAT_23006830;
          DAT_23006834 = CONCAT11(DAT_23006834._1_1_,cVar7);
        }
        else if ((byte)DAT_23006904 != 0) {
          DAT_23006904._0_1_ = (byte)DAT_23006904 - 1;
        }
      }
      else {
        DAT_23006838 = 0;
        DAT_2300683a = 0;
        DAT_23006834 = 0;
        DAT_23006836 = 0;
      }
    }
    bVar1 = DAT_23006900._1_1_;
    bVar2 = DAT_23006908._1_1_;
    if (DAT_23006900._1_1_ == 0) {
      uVar8 = (uint)DAT_23006834._1_1_;
      if (DAT_23006838._1_1_ != uVar8) {
        if (uVar8 < 4) {
          DAT_23006900._1_1_ = 1;
          iVar6 = (uVar8 + 4) * 0x10;
          DAT_23006908._1_1_ = 3;
          DAT_23001e40 = *(undefined4 *)(&DAT_2300683c + iVar6);
          DAT_23001e44 = *(undefined4 *)(&DAT_23006840 + iVar6);
          DAT_23001e48 = *(undefined4 *)(&DAT_23006844 + iVar6);
          DAT_23001e4c = *(undefined4 *)(&DAT_23006848 + iVar6);
          iVar6 = thunk_FUN_0e064504(&PTR_s_hid_dev_1_0e06f690,0x10,&DAT_23001e40);
          bVar2 = bVar1;
          if (iVar6 == 0) {
            bVar1 = DAT_23006900._1_1_;
            bVar2 = DAT_23006908._1_1_;
            if ((byte)(DAT_23006834._1_1_ + '\x01') == '\x04') {
              DAT_23006834 = DAT_23006834 & 0xff;
            }
            else {
              DAT_23006834 = CONCAT11(DAT_23006834._1_1_ + '\x01',(byte)DAT_23006834);
            }
          }
        }
        else {
          DAT_23006834 = 0;
          DAT_23006836 = bVar1;
          DAT_23006838 = DAT_23006834;
          DAT_2300683a = bVar1;
        }
      }
    }
    DAT_23006908._1_1_ = bVar2;
    DAT_23006900._1_1_ = bVar1;
    bVar2 = DAT_23006902;
    bVar1 = DAT_23006902;
    bVar3 = DAT_2300690a;
    if ((DAT_23006902 == 0) && (uVar8 = (uint)DAT_23006836, DAT_2300683a != uVar8)) {
      if (uVar8 < 4) {
        DAT_23006902 = 1;
        iVar6 = (uVar8 + 8) * 0x10;
        DAT_2300690a = 3;
        DAT_23001e20 = *(undefined4 *)(&DAT_2300683c + iVar6);
        DAT_23001e24 = *(undefined4 *)(&DAT_23006840 + iVar6);
        iVar6 = thunk_FUN_0e064504(&PTR_s_hid_dev_2_0e06f67c,8);
        bVar3 = bVar1;
        if ((iVar6 == 0) &&
           (DAT_23006836 = DAT_23006836 + 1, bVar2 = DAT_23006902, bVar3 = DAT_2300690a,
           DAT_23006836 == 4)) {
          DAT_23006836 = 0;
        }
      }
      else {
        DAT_23006834 = 0;
        DAT_23006836 = bVar1;
        DAT_23006838 = DAT_23006834;
        DAT_2300683a = bVar1;
      }
    }
  }
  DAT_2300690a = bVar3;
  DAT_23006902 = bVar2;
  return;
}


