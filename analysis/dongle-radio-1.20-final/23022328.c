/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23022328. Types and names are inferred; NOT original source. */

void ram_candidate_23022328(void)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  char cVar12;
  char *pcVar13;
  byte *pbVar11;
  
  uVar7 = (uint)DAT_230071a2;
  if (DAT_230071a0 == 0) {
    iVar6 = uVar7 * 0xf84;
    if ((&DAT_23003450)[iVar6] == '\0') {
      if ((&DAT_2300344e)[iVar6] == '\0') {
        (&DAT_2300344e)[iVar6] = (&DAT_23003451)[iVar6];
      }
      iVar6 = uVar7 * 0xf84;
      if ((&DAT_2300344f)[iVar6] == '\0') {
        (&DAT_2300344f)[iVar6] = (&DAT_23003451)[iVar6];
      }
      iVar6 = uVar7 * 0xf84;
      bVar1 = (&DAT_23003451)[iVar6];
      if (bVar1 != 0) {
        if (bVar1 < (byte)(&DAT_2300344e)[iVar6]) {
          (&DAT_2300344e)[iVar6] = bVar1;
        }
        else if ((byte)(&DAT_2300344f)[iVar6] < bVar1) {
          (&DAT_2300344f)[iVar6] = bVar1;
        }
      }
      iVar6 = uVar7 * 0xf84;
      sVar2 = *(short *)(&DAT_23003456 + iVar6);
      *(ushort *)(&DAT_23003456 + iVar6) = sVar2 + 1U;
      if (0x1f < (ushort)(sVar2 + 1U)) {
        *(undefined2 *)(&DAT_23003456 + iVar6) = 0;
        (&DAT_2300344d)[iVar6] = (&DAT_2300344e)[iVar6];
        *(undefined2 *)(&DAT_2300344e + iVar6) = 0xff;
      }
      return;
    }
    bVar1 = (&DAT_23003452)[iVar6];
    if (((&DAT_2300315c)[bVar1] == 0) ||
       ((byte)(&DAT_23003451)[iVar6] < (byte)(&DAT_2300315c)[bVar1])) {
      (&DAT_2300315c)[bVar1] = (&DAT_23003451)[iVar6];
    }
    (&DAT_23003181)[bVar1] = (&DAT_23003181)[bVar1] + '\x01';
    return;
  }
  if (DAT_230071a0 != 1) {
    return;
  }
  bVar3 = true;
  if (DAT_230031f6 == 0) {
    bVar4 = false;
  }
  else {
    bVar4 = false;
    pbVar9 = (byte *)((int)&DAT_230031aa + 1);
    do {
      pbVar9 = pbVar9 + 1;
      if (10 < *(ushort *)(&DAT_23003332 + (uint)*pbVar9 * 2)) {
        if (0xd < *(ushort *)(&DAT_23003332 + (uint)*pbVar9 * 2)) {
          bVar4 = true;
        }
        bVar3 = false;
      }
    } while (pbVar9 != (byte *)((int)&DAT_230031aa + DAT_230031f6 + 1));
  }
  cVar12 = '\0';
  uVar7 = 0xff;
  pbVar9 = &DAT_230003e0;
  pcVar13 = &DAT_230003dc;
  do {
    uVar8 = (uint)pbVar9[1];
    if (uVar8 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = 0;
      pbVar11 = &DAT_230003e8 + *pbVar9;
      do {
        pbVar10 = pbVar11 + 1;
        uVar5 = uVar5 + (byte)(&DAT_2300315c)[*pbVar11];
        pbVar11 = pbVar10;
      } while (&DAT_230003e8 + uVar8 + *pbVar9 != pbVar10);
    }
    pbVar9 = pbVar9 + 2;
    if (uVar5 / uVar8 < uVar7) {
      cVar12 = *pcVar13;
      uVar7 = uVar5 / uVar8;
    }
    pcVar13 = pcVar13 + 1;
  } while (pbVar9 != &DAT_230003e8);
  uVar8 = (uint)DAT_2300344d;
  if (cVar12 == 'B') {
    if (((uVar8 != 0) && (DAT_230031f7 != '\0')) && ((uint)DAT_230031f9 <= uVar7 + 0xc)) {
      cVar12 = '\x06';
      goto LAB_23021a2e;
    }
    bVar3 = false;
    cVar12 = '\x06';
LAB_23021974:
    if (DAT_230031fa != '\0') goto LAB_23021950;
    FUN_230211c8(cVar12);
  }
  else {
    if (((uVar8 == 0) || (DAT_230031f7 == '\0')) || (uVar7 + 0xc < (uint)DAT_230031f9)) {
LAB_2302193c:
      if (cVar12 != '\0') {
LAB_23021a6c:
        bVar3 = false;
        goto LAB_23021974;
      }
    }
    else {
LAB_23021a2e:
      if (!bVar3) {
        if (DAT_230033e0 == 1) {
          if ((7 < DAT_2300341c) && (bVar4)) goto LAB_2302193c;
          if (DAT_230033e2 < 5) {
            DAT_230033e2 = DAT_230033e2 + 1;
          }
        }
        else if (DAT_230033e2 == 0) {
          if (DAT_230031f7 == cVar12) {
            if (DAT_230031f8 < 2) {
              DAT_230031f8 = DAT_230031f8 + 1;
            }
            goto LAB_23021a6c;
          }
          if (uVar7 <= uVar8 + 0x23) {
            if (DAT_230031f8 != 0) {
              DAT_230031f8 = DAT_230031f8 - 1;
              bVar3 = true;
              cVar12 = DAT_230031f7;
              goto LAB_23021974;
            }
            goto LAB_2302193c;
          }
        }
        else {
          DAT_230033e2 = DAT_230033e2 - 1;
        }
      }
    }
    if (DAT_230031fa == '\0') goto LAB_230219ca;
    bVar3 = false;
    cVar12 = '\0';
LAB_23021950:
    DAT_230031f6 = DAT_230031fb;
    thunk_FUN_0e06f35c(&DAT_230031ac);
  }
  iVar6 = FUN_23021114(&DAT_230030de);
  iVar6 = thunk_FUN_0e06f3ba(iVar6 + -5,iVar6,5);
  if (iVar6 != 0) {
    if (DAT_230033e8 == 3) {
      DAT_230033d6 = DAT_23005376 + 100;
    }
    else {
      DAT_230033d6 = DAT_23005376 + 0xfa;
    }
    DAT_2300325d = 1;
    FUN_230214bc();
  }
  if (!bVar3) {
    DAT_230031f9 = (byte)uVar7;
    DAT_230031f8 = 1;
    DAT_230031f7 = cVar12;
  }
LAB_230219ca:
  thunk_FUN_0e06f3aa(&DAT_2300315c,0,0x25);
  thunk_FUN_0e06f3aa(&DAT_23003181,0,0x25);
  DAT_230033c6 = 0;
  thunk_FUN_0e06f3aa(&DAT_230032e8,0,0x4a);
  thunk_FUN_0e06f3aa(&DAT_23003332,0,0x4a);
  thunk_FUN_0e06f3aa(&DAT_2300337c,0,0x4a,&DAT_230071a2);
  return;
}


