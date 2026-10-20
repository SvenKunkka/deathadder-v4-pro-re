/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026de0. Types and names are inferred; NOT original source. */

void ram_candidate_23026de0(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 *puVar7;
  char cVar8;
  uint uVar9;
  undefined4 *puVar10;
  char *pcVar11;
  undefined4 unaff_r4;
  char *pcVar12;
  
  if (DAT_230071e4 == '\0') {
    return;
  }
  TIMER020_S_TASKS_CAPTURE_7 = 1;
  FUN_23022204();
  pcVar6 = (char *)&DAT_23006908;
  DAT_230071e2 = 1;
  pcVar12 = (char *)&DAT_23006900;
  do {
    pcVar11 = pcVar12 + 1;
    if ((*pcVar12 != '\0') && (cVar8 = *pcVar6, *pcVar6 = cVar8 + -1, (char)(cVar8 + -1) == '\0')) {
      *pcVar12 = '\0';
    }
    bVar1 = (byte)DAT_23006904;
    pcVar6 = pcVar6 + 1;
    pcVar12 = pcVar11;
  } while (pcVar11 != &DAT_23006903);
  if (DAT_230071e6 != '\x03') {
    if ((byte)DAT_23006838 != (byte)DAT_23006834) {
      puVar7 = (undefined4 *)0x23001e80;
      if ((DAT_23006830 & 1) == 0) {
        puVar7 = &DAT_23001e60;
      }
      bVar2 = DAT_23006902;
      bVar3 = DAT_2300690a;
      if (DAT_230071e4 != '\0') {
        if (((byte)DAT_23006904 < 2) &&
           (uVar9 = (uint)(byte)DAT_23006834, (byte)DAT_23006838 != uVar9)) {
          if (uVar9 < 4) {
            puVar10 = (undefined4 *)(&DAT_2300683c + uVar9 * 0x10);
            uVar5 = *(undefined4 *)(&DAT_23006840 + uVar9 * 0x10);
            *puVar7 = *puVar10;
            puVar7[1] = uVar5;
            if (bVar1 < 2) {
              DAT_23006904._0_1_ = (byte)DAT_23006904 + 1;
              puVar10 = (undefined4 *)(uint)(byte)DAT_23006904;
            }
            iVar4 = thunk_FUN_0e064504(&PTR_s_hid_dev_0_0e06f6a4,8,puVar7,puVar10,unaff_r4);
            if (iVar4 == 0) {
              cVar8 = (byte)DAT_23006834 + '\x01';
              if (cVar8 == '\x04') {
                cVar8 = '\0';
              }
              DAT_23006830 = 1 - DAT_23006830;
              DAT_23006834 = CONCAT11(DAT_23006834._1_1_,cVar8);
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
          uVar9 = (uint)DAT_23006834._1_1_;
          if (DAT_23006838._1_1_ != uVar9) {
            if (uVar9 < 4) {
              DAT_23006900._1_1_ = 1;
              iVar4 = (uVar9 + 4) * 0x10;
              DAT_23006908._1_1_ = 3;
              DAT_23001e40 = *(undefined4 *)(&DAT_2300683c + iVar4);
              DAT_23001e44 = *(undefined4 *)(&DAT_23006840 + iVar4);
              DAT_23001e48 = *(undefined4 *)(&DAT_23006844 + iVar4);
              DAT_23001e4c = *(undefined4 *)(&DAT_23006848 + iVar4);
              iVar4 = thunk_FUN_0e064504(&PTR_s_hid_dev_1_0e06f690,0x10,&DAT_23001e40,DAT_23001e4c,
                                         unaff_r4);
              bVar2 = bVar1;
              if (iVar4 == 0) {
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
        if ((DAT_23006902 == 0) && (uVar9 = (uint)DAT_23006836, DAT_2300683a != uVar9)) {
          if (uVar9 < 4) {
            DAT_23006902 = 1;
            iVar4 = (uVar9 + 8) * 0x10;
            DAT_2300690a = 3;
            DAT_23001e20 = *(undefined4 *)(&DAT_2300683c + iVar4);
            DAT_23001e24 = *(undefined4 *)(&DAT_23006840 + iVar4);
            iVar4 = thunk_FUN_0e064504(&PTR_s_hid_dev_2_0e06f67c,8,&DAT_23001e20,
                                       &DAT_2300683c + iVar4,unaff_r4);
            bVar3 = bVar1;
            if ((iVar4 == 0) &&
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
    FUN_0e06d5c8(&DAT_23002170,&DAT_23002220,0x32,0);
    return;
  }
  return;
}


