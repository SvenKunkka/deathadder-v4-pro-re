/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024190. Types and names are inferred; NOT original source. */

void FUN_23024190(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  dword dVar8;
  char *pcVar9;
  char cVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  
  uVar3 = DAT_2300305c;
  uVar2 = DAT_23003058;
  uVar1 = DAT_23003054;
  uVar12 = (uint)DAT_230032d0;
  if (uVar12 != 2) {
    uVar12 = (uint)(uVar12 == 5) << 1;
  }
  switch((&DAT_23003468)[uVar12 * 0x3e1]) {
  case 0xc:
    if (param_1 != 4) {
      return;
    }
    dVar8 = RADIO_S_EVENTS_CRCOK;
    if ((dVar8 == 1) && (uVar7 = DAT_23003050 & 0xff, uVar7 != 0)) {
      cVar10 = '\0';
      uVar13 = uVar7 - 1 & 0xff;
      RADIO_S_EVENTS_CRCOK = 0;
      DAT_23003050 = CONCAT31(DAT_23003050._1_3_,(char)(uVar7 - 1));
      uVar11 = DAT_23003050;
      if (uVar13 == 0) {
        pcVar14 = (char *)((int)&DAT_23003050 + 1);
        cVar10 = '\0';
      }
      else {
        pcVar14 = (char *)((int)&DAT_23003050 + 1);
        do {
          pcVar9 = pcVar14 + 1;
          cVar10 = cVar10 + *pcVar14;
          pcVar14 = pcVar9;
        } while (pcVar9 != (char *)((int)&DAT_23003050 + uVar7));
        cVar10 = -cVar10;
        pcVar14 = (char *)((int)&DAT_23003050 + uVar13 + 1);
      }
      if (*pcVar14 != cVar10) goto LAB_2302420a;
      iVar6 = uVar12 * 0xf84;
      DAT_23003050 = (uint)DAT_23003050._1_3_ << 8;
      *(uint *)(&DAT_230034fc + iVar6) = uVar11;
      *(undefined4 *)(&DAT_23003500 + iVar6) = uVar1;
      *(undefined4 *)(&DAT_23003504 + iVar6) = uVar2;
      *(undefined4 *)(&DAT_23003508 + iVar6) = uVar3;
      (&DAT_23003487)[iVar6] = 1;
      uVar5 = FUN_230209a8((&DAT_230034fd)[iVar6]);
      *(ushort *)(&DAT_23003484 + iVar6) = uVar5 & 0xff | uVar5 << 8;
      uVar4 = FUN_230209ac((&DAT_230034fd)[iVar6]);
      (&DAT_23003486)[iVar6] = uVar4;
      uVar7 = FUN_230209b4((&DAT_230034fd)[iVar6]);
      if ((byte)(&DAT_23003483)[iVar6] != uVar7) {
        uVar11 = (uint)DAT_230032ca;
        uVar5 = *(ushort *)(&DAT_2300347e + uVar12 * 0x3e1);
        (&DAT_23003470)[uVar12 * 0x7c2] = 0;
        *(undefined2 *)((int)&DAT_230033e8 + (uVar12 * 0x7c2 + uVar11 + 0x48) * 2) = 0;
        if (uVar5 < 6) {
          cVar10 = (&DAT_23003482)[iVar6] + '\x01';
          if (cVar10 == '\b') {
            cVar10 = '\x01';
          }
          (&DAT_23003482)[iVar6] = cVar10;
          FUN_2302073c(uVar12);
          *(undefined2 *)((int)&DAT_2300347e + iVar6 + 2) =
               *(undefined2 *)(&DAT_2300347e + uVar12 * 0x3e1);
        }
      }
      (&DAT_23003483)[uVar12 * 0xf84] = (char)uVar7;
      *(undefined2 *)(&DAT_2300347e + uVar12 * 0x3e1) = 0xff;
      FUN_23021c24(uVar12);
      dVar8 = RADIO_S_RSSISAMPLE;
      DAT_23003451 = (undefined1)dVar8;
      DAT_23003452 = (undefined1)DAT_23003224;
      DAT_23003450 = 0;
      FUN_2302233c(0);
    }
    else {
LAB_2302420a:
      DAT_23003050 = DAT_23003050 & 0xffffff00;
    }
    (&DAT_23003468)[uVar12 * 0x3e1] = 0xb;
    break;
  case 0xd:
    if (param_1 == 5) {
      (&DAT_23003468)[uVar12 * 0x3e1] = 0xd;
    }
    break;
  case 0xe:
    if (param_1 == 5) {
      iVar6 = FUN_23021af4(2);
      if (iVar6 != 0) {
        RADIO_S_SUBSCRIBE_DISABLE = DAT_230071c5 | 0x80000000;
        dVar8 = FUN_230216b0(DAT_2300535a);
        RADIO_S_FREQUENCY = dVar8;
        FUN_23020f1c(&DAT_23003468 + uVar12 * 0x3e1,&RADIO_S_TASKS_RXEN,0xf,param_4);
        return;
      }
      if (DAT_230031a9 == '\x01') {
        DAT_230031a9 = '\0';
        FUN_2302233c(2);
      }
      (&DAT_23003468)[uVar12 * 0x3e1] = 0xd;
    }
    break;
  case 0xf:
    if (param_1 == 0xe) {
      FUN_23020f1c(&DAT_23003468 + uVar12 * 0x3e1,&RADIO_S_TASKS_RSSISTART,0x10,param_4);
      return;
    }
    break;
  case 0x10:
    RADIO_S_SUBSCRIBE_DISABLE = 0;
    dVar8 = RADIO_S_RSSISAMPLE;
    DAT_23005359 = (undefined1)dVar8;
    DAT_23005358 = 1;
    FUN_2302233c(2);
    (&DAT_23003468)[uVar12 * 0x3e1] = 0xd;
  }
  return;
}


