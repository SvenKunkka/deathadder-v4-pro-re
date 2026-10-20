/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020a00. Types and names are inferred; NOT original source. */

void ram_candidate_23020a00(void)

{
  short sVar1;
  dword dVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  ushort uVar6;
  undefined2 uVar7;
  uint uVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint local_28;
  
  uVar6 = DAT_230032d0;
  uVar5 = DAT_2300305c;
  uVar4 = DAT_23003058;
  uVar3 = DAT_23003054;
  uVar8 = DAT_23003050;
  if (DAT_23003230 == 5) {
    (*(code *)0xe05d099)();
    return;
  }
  uVar10 = (uint)DAT_23003234;
  if (uVar10 == 4) {
    dVar2 = RADIO_S_EVENTS_TXREADY;
    if (dVar2 == 1) {
      RADIO_S_EVENTS_TXREADY = 0;
    }
    dVar2 = RADIO_S_EVENTS_RXREADY;
    if ((dVar2 == 1) && (RADIO_S_EVENTS_RXREADY = 0, 1 < DAT_23003230)) {
      FUN_23024190(0xe);
    }
    dVar2 = RADIO_S_EVENTS_ADDRESS;
    if (dVar2 == 1) {
      RADIO_S_EVENTS_ADDRESS = 0;
    }
    dVar2 = RADIO_S_EVENTS_END;
    if ((dVar2 == 0) || (RADIO_S_EVENTS_END = 0, DAT_23003230 < 2)) {
      dVar2 = RADIO_S_EVENTS_DISABLED;
    }
    else {
      FUN_23024190(4);
      dVar2 = RADIO_S_EVENTS_DISABLED;
    }
    if (dVar2 == 1) {
      RADIO_S_EVENTS_DISABLED = 0;
      if (1 < DAT_23003230) {
        FUN_23024190(5);
        FUN_23020c30();
        return;
      }
      FUN_23020c30();
      return;
    }
    return;
  }
  if (uVar10 == 1) {
    dVar2 = RADIO_S_EVENTS_TXREADY;
    if (dVar2 == 1) {
      RADIO_S_EVENTS_TXREADY = 0;
    }
    dVar2 = RADIO_S_EVENTS_RXREADY;
    if (dVar2 == 1) {
      RADIO_S_EVENTS_RXREADY = 0;
    }
    dVar2 = RADIO_S_EVENTS_ADDRESS;
    if (dVar2 == 1) {
      RADIO_S_EVENTS_ADDRESS = 0;
    }
    dVar2 = RADIO_S_EVENTS_END;
    local_28 = uVar10;
    if ((dVar2 == 1) && (RADIO_S_EVENTS_END = 0, 1 < DAT_23003230)) {
      uVar10 = DAT_23006274 & 0xffff;
      iVar12 = uVar10 * 0xf84;
      if ((&DAT_23003468)[uVar10 * 0x3e1] == 0xc) {
        dVar2 = RADIO_S_EVENTS_CRCOK;
        if ((dVar2 == 1) && ((char)DAT_23003050 != '\0')) {
          RADIO_S_EVENTS_CRCOK = 0;
          DAT_23003050 = (uint)DAT_23003050._1_3_ << 8;
          uVar13 = DAT_23006274 & 0xffff;
          *(uint *)(&DAT_230034fc + iVar12) = uVar8;
          *(undefined4 *)(&DAT_23003500 + iVar12) = uVar3;
          *(undefined4 *)(&DAT_23003504 + iVar12) = uVar4;
          *(undefined4 *)(&DAT_23003508 + iVar12) = uVar5;
          (&DAT_23003487)[iVar12] = 1;
          uVar6 = FUN_230209a8((&DAT_230034fd)[iVar12]);
          *(ushort *)(&DAT_23003484 + iVar12) = uVar6 & 0xff | uVar6 << 8;
          uVar8 = FUN_230209b4((&DAT_230034fd)[iVar12]);
          if ((byte)(&DAT_23003483)[iVar12] != uVar8) {
            uVar11 = (uint)DAT_230032ca;
            sVar1 = *(short *)(&DAT_2300347e + uVar10 * 0x3e1);
            (&DAT_23003470)[uVar10 * 0x7c2] = 0;
            *(undefined2 *)((int)&DAT_230033e8 + (uVar10 * 0x7c2 + uVar11 + 0x48) * 2) = 0;
            if (sVar1 != 0) {
              cVar9 = (&DAT_23003482)[iVar12] + '\x01';
              if (cVar9 == '\b') {
                cVar9 = '\x01';
              }
              (&DAT_23003482)[iVar12] = cVar9;
              FUN_2302073c(uVar13);
              *(undefined2 *)((int)&DAT_2300347e + iVar12 + 2) =
                   *(undefined2 *)(&DAT_2300347e + uVar10 * 0x3e1);
            }
          }
          (&DAT_23003483)[uVar10 * 0xf84] = (char)uVar8;
          *(undefined2 *)(&DAT_2300347e + uVar10 * 0x3e1) = 0;
          FUN_23021c24(uVar13);
          uVar7 = FUN_230209c8(0,(&DAT_230034fd)[uVar10 * 0xf84]);
          uVar8 = (uint)DAT_230032ca;
          *(undefined2 *)((int)&DAT_230033e8 + (uVar10 * 0x7c2 + uVar8 + 0x48) * 2) = uVar7;
          *(undefined2 *)((int)&DAT_230033e8 + (uVar8 + 0xfcc) * 2) = uVar7;
        }
        else {
          DAT_23003050 = (uint)DAT_23003050._1_3_ << 8;
          if (DAT_2300341c == 1) {
            (&DAT_2300348a)[uVar10 * 0xf84] = 1;
          }
          else if (DAT_230032d0 < 2) {
            (&DAT_2300348a)[uVar10 * 0xf84] = 1;
          }
          else {
            FUN_23023708(1);
          }
        }
        (&DAT_23003468)[uVar10 * 0x3e1] = 0xb;
      }
      else if ((&DAT_23003468)[uVar10 * 0x3e1] == 0xd) {
        FUN_23020f1c(&DAT_23003468 + uVar10 * 0x3e1,&RADIO_S_TASKS_DISABLE);
      }
    }
    dVar2 = RADIO_S_EVENTS_DISABLED;
    if (dVar2 == 1) {
      RADIO_S_EVENTS_DISABLED = 0;
      if ((1 < DAT_23003230) &&
         (uVar8 = DAT_23006274 & 0xffff, (&DAT_23003468)[uVar8 * 0x3e1] == 0xd)) {
        uVar10 = (uint)DAT_230032ca;
        if (2 < *(ushort *)((int)&DAT_230033e8 + (uVar8 * 0x7c2 + uVar10 + 0x48) * 2)) {
          if (DAT_23005384 == '\0') {
            cVar9 = (&DAT_23005349)[uVar10] + '\x01';
            if (DAT_23005353 == cVar9) {
              cVar9 = '\0';
            }
            (&DAT_23005349)[uVar10] = cVar9;
            uVar10 = (uint)DAT_230032ca;
          }
          *(undefined2 *)((int)&DAT_230033e8 + (uVar8 * 0x7c2 + uVar10 + 0x48) * 2) = 0;
        }
        (&DAT_23003468)[uVar8 * 0x3e1] = 0xd;
      }
      FUN_23020c30();
      return;
    }
    return;
  }
  if (uVar10 != 2) {
    return;
  }
  dVar2 = RADIO_S_EVENTS_TXREADY;
  if (dVar2 == 1) {
    RADIO_S_EVENTS_TXREADY = 0;
  }
  dVar2 = RADIO_S_EVENTS_RXREADY;
  if (dVar2 == 1) {
    RADIO_S_EVENTS_RXREADY = 0;
  }
  dVar2 = RADIO_S_EVENTS_END;
  if (dVar2 != 0) {
    RADIO_S_EVENTS_END = 0;
  }
  dVar2 = RADIO_S_EVENTS_DISABLED;
  if (dVar2 == 1) {
    RADIO_S_EVENTS_DISABLED = 0;
    if (1 < DAT_23003230) {
      uVar10 = (uint)DAT_230032d0;
      switch((&DAT_23003468)[uVar10 * 0x3e1]) {
      case 8:
        (&DAT_23003468)[uVar10 * 0x3e1] = 7;
        break;
      case 9:
        dVar2 = RADIO_S_EVENTS_CRCOK;
        if (dVar2 == 1) {
          uVar8 = FUN_230223f0(uVar10,&DAT_230034bc + uVar10 * 0xf84);
          if (uVar8 < 2) {
            (&DAT_23003468)[uVar10 * 0x3e1] = 7;
          }
          else if (uVar8 == 2) {
            FUN_23020f1c(&DAT_23003468 + uVar10 * 0x3e1,&RADIO_S_TASKS_DISABLE,10);
          }
        }
        else {
          (&DAT_23003468)[uVar10 * 0x3e1] = 7;
        }
        break;
      case 10:
        RADIO_S_SUBSCRIBE_TXEN = 0;
        RADIO_S_SUBSCRIBE_RXEN = 0;
        RADIO_S_SUBSCRIBE_DISABLE = 0;
        RADIO_S_SUBSCRIBE_TXEN = 0;
        RADIO_S_SUBSCRIBE_RXEN = 0;
        RADIO_S_SUBSCRIBE_DISABLE = 0;
        RADIO_S_SUBSCRIBE_TXEN = 0;
        FUN_23020f1c(&DAT_23003468 + uVar10 * 0x3e1,&RADIO_S_TASKS_DISABLE);
        FUN_23021dbc((char)uVar6);
        local_28 = CONCAT22(local_28._2_2_,uVar6);
        FUN_2302546c(&local_28);
        break;
      case 0xb:
        (&DAT_23003468)[uVar10 * 0x3e1] = 0xb;
        break;
      case 0xc:
        dVar2 = RADIO_S_EVENTS_CRCOK;
        if (dVar2 == 1) {
          iVar12 = uVar10 * 0xf84;
          DAT_23003050 = DAT_23003050 & 0xffffff00;
          *(uint *)(&DAT_230034fc + iVar12) = uVar8;
          *(undefined4 *)(&DAT_23003500 + iVar12) = uVar3;
          *(undefined4 *)(&DAT_23003504 + iVar12) = uVar4;
          *(undefined4 *)(&DAT_23003508 + iVar12) = uVar5;
          (&DAT_23003487)[iVar12] = 1;
          uVar6 = FUN_230209a8((&DAT_230034fd)[iVar12]);
          *(ushort *)(&DAT_23003484 + iVar12) = uVar6 & 0xff | uVar6 << 8;
          uVar8 = FUN_230209b4((&DAT_230034fd)[iVar12]);
          if ((byte)(&DAT_23003483)[iVar12] != uVar8) {
            uVar13 = (uint)DAT_230032ca;
            sVar1 = *(short *)(&DAT_2300347e + uVar10 * 0x3e1);
            (&DAT_23003470)[uVar10 * 0x7c2] = 0;
            *(undefined2 *)((int)&DAT_230033e8 + (uVar10 * 0x7c2 + uVar13 + 0x48) * 2) = 0;
            if (sVar1 != 0) {
              cVar9 = (&DAT_23003482)[iVar12] + '\x01';
              if (cVar9 == '\b') {
                cVar9 = '\x01';
              }
              (&DAT_23003482)[iVar12] = cVar9;
              FUN_2302073c(uVar10);
              *(undefined2 *)((int)&DAT_2300347e + iVar12 + 2) =
                   *(undefined2 *)(&DAT_2300347e + uVar10 * 0x3e1);
            }
          }
          (&DAT_23003483)[uVar10 * 0xf84] = (char)uVar8;
          *(undefined2 *)(&DAT_2300347e + uVar10 * 0x3e1) = 0;
          FUN_23021c24(uVar10);
        }
        (&DAT_23003468)[uVar10 * 0x3e1] = 0xb;
        break;
      case 0xd:
        (&DAT_23003468)[uVar10 * 0x3e1] = 0xd;
      }
    }
    FUN_23020c30();
    return;
  }
  return;
}


