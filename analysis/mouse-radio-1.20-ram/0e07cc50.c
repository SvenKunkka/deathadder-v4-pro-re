/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07cc50. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e07cc50(void)

{
  undefined1 *puVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  code *pcVar8;
  uint local_14;
  
  cVar2 = DAT_23003f04;
  if (0x7e < DAT_23003f03) {
    if (DAT_23003f03 < 0xc3) {
      switch(DAT_23003f03) {
      case 0xa9:
        goto switchD_0e07cd14_caseD_a9;
      default:
        DAT_23003efc = 3;
        return;
      case 0xb1:
        DAT_23003f14 = CONCAT31(CONCAT21(DAT_23003f14._2_2_,DAT_230077ac),DAT_230077ad);
        DAT_23003f08 = DAT_23006bd4 << 0x18 | (DAT_23006bd4 >> 8 & 0xff) << 0x10 |
                       (DAT_23006bd4 >> 0x10 & 0xff) << 8 | DAT_23006bd4 >> 0x18;
        DAT_23003f0c = DAT_23006bd8 << 0x18 | (DAT_23006bd8 >> 8 & 0xff) << 0x10 |
                       (DAT_23006bd8 >> 0x10 & 0xff) << 8 | DAT_23006bd8 >> 0x18;
        DAT_23003f10 = CONCAT13(DAT_230077ae,
                                CONCAT12(DAT_230077af,CONCAT11(DAT_230077b0,DAT_230077b3)));
        return;
      case 0xb6:
        _DAT_23003f04 = CONCAT11(DAT_230077a5,DAT_230077a9);
        _DAT_23003f04 = CONCAT12(DAT_230077a8,_DAT_23003f04);
        DAT_23003f08 = CONCAT13(DAT_230077a6,(undefined3)DAT_23003f08);
        uVar3 = thunk_FUN_2302aa40(0x40);
        DAT_23003f0c = CONCAT31(DAT_23003f0c._1_3_,uVar3);
        return;
      case 0xc2:
        if ((DAT_23007088 & 4) == 0) {
          pcVar8 = (code *)0x23026369;
        }
        else {
          pcVar8 = (code *)0x230263bd;
        }
        (*pcVar8)(&DAT_0e097840,4);
        FUN_0e096164(0x20,0);
        if ((DAT_23007088 & 4) == 0) {
          pcVar8 = (code *)0x230263bd;
        }
        else {
          pcVar8 = (code *)0x23026369;
        }
        (*pcVar8)(&DAT_0e097840,4);
        _DAT_23003f04 = CONCAT31(_DAT_23003f05,2);
        iVar4 = FUN_230263ac(&DAT_0e097840,&local_14);
        if (iVar4 == 0) {
          if (((DAT_23007088 ^ local_14) & 0x20) == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = 1;
          }
        }
        _DAT_23003f04 = CONCAT11((char)iVar4,DAT_23003f04);
        iVar4 = FUN_230263ac(&DAT_0e097840,&local_14);
        if (iVar4 == 0) {
          if (((local_14 ^ DAT_23007088) & 0x10) == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = 1;
          }
        }
        _DAT_23003f04 = CONCAT12((char)(iVar4 << 1),_DAT_23003f04);
        return;
      }
    }
    if (DAT_23003f03 == 0xf3) {
      _DAT_23003f04 = DAT_23004994;
      DAT_23003f08 = DAT_23004998;
      DAT_23003f0c = DAT_2300499c;
      DAT_23003f10 = DAT_230049a0;
      DAT_23003f14 = DAT_230049a4;
      DAT_23003f18 = DAT_230049a8;
      return;
    }
    if (DAT_23003f03 == 0xfe) {
      return;
    }
    if (DAT_23003f03 == 0xf1) {
      thunk_FUN_0e07a298(&DAT_23003f04);
      return;
    }
    DAT_23003efc = 3;
    return;
  }
  if (DAT_23003f03 < 0x31) {
    DAT_23003efc = 3;
    return;
  }
  switch(DAT_23003f03) {
  case 0x31:
    DAT_230077a7 = DAT_23003f04;
    if (DAT_23003f04 != '\x01') {
      DAT_230077a7 = '\0';
    }
    break;
  case 0x32:
    if ((_DAT_23003f04 & 0xff) == 1) {
      thunk_FUN_2302ab40(0x7f,5);
      thunk_FUN_2302ab40(0x44,0x45);
      thunk_FUN_2302ab40(0x7f,0xd);
      thunk_FUN_2302ab40(0x48,0xcc);
      thunk_FUN_2302ab40(0x7f,5);
      thunk_FUN_2302ab40(0x46,0xfb);
      thunk_FUN_2302ab40(0x7f,0);
      thunk_FUN_2302ab40(0x54,0);
      thunk_FUN_2302ab40(0x7f,6);
      thunk_FUN_2302ab40(0x71,0x95);
      thunk_FUN_2302ab40(0x7f,0);
      thunk_FUN_2302ab40(0x40,0x83);
      DAT_23007714 = cVar2;
    }
    else {
      if ((_DAT_23003f04 & 0xff) != 2) {
        DAT_23007714 = 0;
        FUN_0e07d6d8(0);
        FUN_0e07ae4c(200);
                    /* WARNING: Subroutine does not return */
        FUN_0e085ed0(0);
      }
      thunk_FUN_2302ab40(0x7f,5);
      thunk_FUN_2302ab40(0x44,0x45);
      thunk_FUN_2302ab40(0x7f,0xd);
      thunk_FUN_2302ab40(0x48,0xcc);
      thunk_FUN_2302ab40(0x7f,5);
      thunk_FUN_2302ab40(0x46,0xfb);
      thunk_FUN_2302ab40(0x7f,0);
      thunk_FUN_2302ab40(0x54,0);
      thunk_FUN_2302ab40(0x7f,6);
      thunk_FUN_2302ab40(0x71,0x95);
      thunk_FUN_2302ab40(0x7f,0);
      thunk_FUN_2302ab40(0x40,0x80);
      DAT_23007714 = '\x01';
    }
    break;
  case 0x33:
    if (DAT_23007724 != '\x02') {
      DAT_23003efc = 3;
      return;
    }
    uVar6 = 1;
    uVar5 = (uint)DAT_23003f05;
    DAT_2300775f = 1;
    if (DAT_23003f04 != '\0') {
      if (100 < uVar5) {
        return;
      }
      DAT_23007743 = (&DAT_0e099278)[uVar5 * 4];
      DAT_23007742 = (&DAT_0e099279)[uVar5 * 4];
      DAT_23007741 = (&DAT_0e09927a)[uVar5 * 4];
      return;
    }
    if (uVar5 == 0xff) {
      if ((byte)DAT_23003f06 == 0) {
        if (DAT_23003f06._1_1_ == 0) {
          uVar6 = 2;
          goto LAB_0e07cf96;
        }
      }
      else if (((byte)DAT_23003f06 & DAT_23003f06._1_1_) == 0xff) goto LAB_0e07cf96;
    }
    else if (uVar5 == 0) {
      if ((byte)DAT_23003f06 == 0xff) {
        if (DAT_23003f06._1_1_ == 0) {
          uVar6 = 3;
          goto LAB_0e07cf96;
        }
      }
      else if (((byte)DAT_23003f06 == 0) && (DAT_23003f06._1_1_ == 0xff)) {
        uVar6 = 4;
        goto LAB_0e07cf96;
      }
    }
    uVar6 = 0;
LAB_0e07cf96:
    switch(uVar6) {
    case 0:
      DAT_23007741 = 0;
      DAT_23007742 = 0;
      DAT_23007743 = 0;
      DAT_2300775f = 1;
      return;
    case 1:
      DAT_23007743 = 0xff;
      DAT_23007742 = 0xff;
      DAT_23007741 = 0xff;
      return;
    case 2:
      DAT_23007741 = 0;
      DAT_23007743 = 0xff;
      DAT_23007742 = DAT_23007741;
      break;
    case 3:
      DAT_23007741 = 0;
      DAT_23007742 = 0xff;
      DAT_23007743 = 0;
      DAT_2300775f = 1;
      return;
    case 4:
      DAT_23007741 = 0xff;
      DAT_23007742 = 0;
      DAT_23007743 = 0;
      DAT_2300775f = 1;
      return;
    case 5:
      DAT_23007741 = 0xff;
      DAT_23007743 = 0;
      DAT_23007742 = DAT_23007741;
      break;
    case 6:
      DAT_23007743 = 0xff;
      DAT_23007742 = 0xff;
      DAT_23007741 = 0;
      return;
    case 7:
      DAT_23007743 = 0xff;
      DAT_23007742 = 0;
      DAT_23007741 = 0xff;
      return;
    }
    return;
  default:
    DAT_23003efc = 3;
    return;
  case 0x35:
    if (DAT_23007724 != '\x02') {
      DAT_23003efc = 3;
      return;
    }
    if (((_DAT_23003f04 & 0xff) != 1) && ((_DAT_23003f04 & 0xff) != 0)) {
      DAT_23003efc = 3;
      return;
    }
    DAT_23004962 = DAT_23003f04;
    FUN_0e07d4ac(2,0);
    return;
  case 0x36:
    DAT_230077a9 = DAT_23003f04;
    if (DAT_23003f04 == '\x01') {
      DAT_230077a8 = 0;
    }
    else {
      DAT_230077a9 = '\0';
      DAT_230077a8 = 0;
    }
    break;
  case 0x37:
    if (DAT_23007724 != '\x02') {
      DAT_23003efc = 3;
      return;
    }
    if ((_DAT_23003f04 & 0xff) != 1) {
      if ((_DAT_23003f04 & 0xff) != 2) {
        DAT_23003efc = 3;
        return;
      }
      DAT_23007728 = 1;
      return;
    }
    FUN_0e07e048();
    DAT_23007779 = cVar2;
    thunk_FUN_23026b2c();
    return;
  case 0x70:
    ram_candidate_2302111c(&DAT_23003f04);
    return;
  case 0x71:
    ram_candidate_2302118c(&DAT_23003f04);
    return;
  case 0x73:
    DAT_23004994 = _DAT_23003f04;
    DAT_23004998 = DAT_23003f08;
    DAT_230049a4 = DAT_23003f14;
    DAT_2300499c = DAT_23003f0c;
    DAT_230049a0 = DAT_23003f10;
    DAT_230049a8 = DAT_23003f18;
    FUN_0e07d4ac(2,0);
    FUN_0e07d590();
    return;
  case 0x7e:
    ram_candidate_230212e8(_DAT_23003f04 & 0xff,DAT_23003f05);
    return;
  }
  return;
switchD_0e07cd14_caseD_a9:
  if (DAT_23003f04 != '$') {
    return;
  }
  if (DAT_23003f05 == 0x24) {
    uVar5 = (uint)(byte)DAT_23003f06;
    if (uVar5 == 0) {
      FUN_0e084890();
      uVar5 = _DAT_23003f04 >> 0x10 & 0xff;
    }
    _DAT_23003f04 = CONCAT13((&DAT_23003f64)[uVar5 * 0x24],_DAT_23003f04);
    puVar7 = (undefined1 *)((int)&DAT_23003f06 + 1);
    do {
      puVar1 = puVar7 + (short)(ushort)(byte)DAT_23003f06 * 0x24 + 0x5e;
      puVar7 = puVar7 + 1;
      *puVar7 = *puVar1;
    } while (puVar7 != (undefined1 *)0x23003f2a);
    return;
  }
  return;
}


