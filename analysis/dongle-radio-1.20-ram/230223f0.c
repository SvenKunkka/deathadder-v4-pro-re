/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230223f0. Types and names are inferred; NOT original source. */

undefined4 FUN_230223f0(uint param_1,char *param_2)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  short sVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  int iVar8;
  undefined4 uVar9;
  char cVar10;
  uint uVar11;
  int iVar12;
  undefined2 uVar13;
  undefined2 local_34;
  undefined2 local_32;
  undefined4 local_30;
  undefined2 local_2c;
  undefined2 local_2a;
  
  iVar12 = param_1 * 0xf84;
  uVar13 = (&DAT_230034b0)[param_1 * 0x7c2];
  iVar8 = FUN_23020988(param_2[1]);
  uVar11 = DAT_230033e8;
  if (iVar8 == 0) {
    sVar5 = (&DAT_230034b0)[param_1 * 0x7c2];
    if (sVar5 == 2) {
      if ((param_2[3] == '\x14') && (*param_2 == '\v')) {
        (&DAT_2300341c)[param_1 * 0x7c2] = (ushort)(byte)param_2[4];
        (&DAT_230034bc)[iVar12] = 0xb;
        uVar7 = FUN_23020978(0,param_1 & 0xff,0);
        (&DAT_230034bd)[iVar12] = uVar7;
        uVar7 = FUN_230209dc(0,(&DAT_2300348f)[iVar12]);
        (&DAT_230034be)[iVar12] = uVar7;
        sVar5 = DAT_2300323e;
        (&DAT_230034bf)[iVar12] = 0x15;
        uVar6 = DAT_2300534f;
        uVar9 = DAT_23003158;
        uVar7 = DAT_230030dd;
        if ((sVar5 == 0) || (sVar5 == 1)) {
          *(undefined4 *)(&DAT_230034c0 + iVar12) = DAT_2300534b;
          *(undefined4 *)(&DAT_230034c4 + iVar12) = uVar6;
        }
        else if (sVar5 == 2) {
          *(undefined4 *)(&DAT_230034c0 + iVar12) = DAT_230030d9;
          (&DAT_230034c4)[iVar12] = uVar7;
          (&DAT_230034c5)[iVar12] = (char)uVar9;
        }
        else if (sVar5 == 3) {
          *(undefined4 *)(&DAT_230034c0 + iVar12) = DAT_230030d9;
          (&DAT_230034c4)[iVar12] = uVar7;
        }
        uVar9 = 1;
        cVar10 = (&DAT_2300348f)[param_1 * 0xf84] + '\x01';
        if (cVar10 == '\b') {
          cVar10 = '\x01';
        }
        (&DAT_2300348f)[param_1 * 0xf84] = cVar10;
        uVar13 = 3;
        *(undefined4 *)(&DAT_230034b4 + param_1 * 0x7c2) = 0x40000;
        goto LAB_23022416;
      }
    }
    else if (sVar5 == 3) {
      if ((param_2[3] == '\x16') && (*param_2 == '\v')) {
        if ((&DAT_230033fc)[param_1 * 0x3e1] != 0) {
          local_32 = 1;
          local_30 = DAT_23003244;
          local_2c = CONCAT11((&DAT_230033ee)[iVar12],(&DAT_230033ef)[iVar12]);
          local_34 = (undefined2)param_1;
          local_2a = CONCAT11((&DAT_230033f0)[iVar12],(&DAT_230033f1)[iVar12]);
          FUN_23025580(&local_34);
          (&DAT_230033fc)[param_1 * 0x3e1] = 0;
          iVar8 = DAT_230033fc;
          *(undefined2 *)(&DAT_23003402 + iVar12) = 0;
          if (iVar8 == 0 && DAT_23004380 == 0) {
            FUN_23020bd4(0xff);
          }
        }
        uVar9 = 2;
        uVar13 = 6;
        *(undefined4 *)(&DAT_230034b4 + param_1 * 0x7c2) = 0;
        goto LAB_23022416;
      }
    }
    else if ((((sVar5 == 0) && (param_2[3] == '\x12')) && (*param_2 == '\v')) &&
            ((((&DAT_230033fc)[param_1 * 0x3e1] == 0 || (*(short *)(&DAT_230033ee + iVar12) == -1))
             || ((param_2[6] == (&DAT_230033ee)[iVar12] && (param_2[7] == (&DAT_230033ef)[iVar12])))
             ))) {
      (&DAT_2300346c)[param_1 * 0xf84] = (byte)param_2[4] >> 7;
      bVar1 = (byte)DAT_23003234;
      if ((uVar11 < 3) && (DAT_2300436c < 3)) {
        bVar1 = (byte)DAT_23003238;
      }
      uVar11 = (uint)(param_2[4] & bVar1);
      if ((param_2[4] & bVar1 & 0xf) != 0) {
        iVar8 = param_1 * 0xf84;
        cVar10 = param_2[6];
        (&DAT_230033ee)[iVar8] = cVar10;
        cVar2 = param_2[7];
        (&DAT_230033ef)[iVar8] = cVar2;
        cVar3 = param_2[8];
        (&DAT_230033f0)[iVar8] = cVar3;
        cVar4 = param_2[9];
        *(ushort *)(&DAT_230033f2 + param_1 * 0x3e1) = CONCAT11(cVar10,cVar2);
        *(ushort *)((int)&DAT_230033f2 + iVar8 + 2) = CONCAT11(cVar3,cVar4);
        (&DAT_230033f1)[iVar8] = cVar4;
        if ((int)(uVar11 << 0x1c) < 0) {
          DAT_23003236 = 8;
          uVar11 = 8;
        }
        else if ((int)(uVar11 << 0x1d) < 0) {
          uVar11 = 4;
          DAT_23003236 = 4;
        }
        else {
          uVar11 = 2 - (uVar11 & 1) & 0xff;
          DAT_23003236 = (undefined2)uVar11;
        }
        iVar8 = param_1 * 0xf84;
        (&DAT_230034bc)[iVar8] = 0xb;
        uVar7 = FUN_23020978(0,param_1 & 0xff);
        (&DAT_230034bd)[iVar8] = uVar7;
        uVar7 = FUN_230209dc(0,(&DAT_2300348f)[iVar8]);
        sVar5 = DAT_2300323e;
        (&DAT_230034be)[iVar8] = uVar7;
        (&DAT_230034bf)[iVar8] = 0x13;
        (&DAT_230034c1)[iVar8] = 0;
        (&DAT_230034c0)[iVar8] = (byte)uVar11 | ((byte)sVar5 & 3) << 4;
        (&DAT_230034c2)[iVar8] = DAT_23005349 & 0xf | DAT_2300534a << 4;
        cVar10 = (&DAT_2300348f)[iVar8] + '\x01';
        if (cVar10 == '\b') {
          cVar10 = '\x01';
        }
        (&DAT_2300348f)[iVar8] = cVar10;
        uVar13 = 2;
        *(undefined4 *)(&DAT_230034b4 + param_1 * 0x7c2) = 0x40000;
        uVar9 = 1;
        goto LAB_23022416;
      }
    }
  }
  uVar9 = 0;
LAB_23022416:
  (&DAT_230034b0)[param_1 * 0x7c2] = uVar13;
  return uVar9;
}


