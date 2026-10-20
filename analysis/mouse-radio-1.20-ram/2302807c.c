/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302807c. Types and names are inferred; NOT original source. */

void FUN_2302807c(void)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  undefined4 in_r3;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  bVar5 = DAT_2300495b._3_1_;
  bVar4 = DAT_2300495b._1_1_;
  cVar1 = DAT_230077a5;
  if (DAT_230077a5 == '\0') {
    if (DAT_2300776c != '\0') {
      iVar8 = 0;
      do {
        iVar6 = iVar8 * 5;
        iVar8 = iVar8 + 1;
        (&DAT_23006638)[iVar6] = (&DAT_23006638)[iVar6] | 2;
        (&DAT_2300663a)[iVar6] = bVar5;
        (&DAT_2300663c)[iVar6] = 0;
        DAT_2300776c = cVar1;
      } while (iVar8 != 8);
    }
  }
  else {
    bVar5 = DAT_2300495b._3_1_ - DAT_2300495b._2_1_;
    bVar4 = DAT_2300495b._1_1_ - (byte)DAT_2300495b;
    DAT_2300663c = 1;
    DAT_23006641 = 1;
    DAT_2300776c = '\x01';
    DAT_23006646 = 1;
    DAT_2300664b = 1;
    DAT_23006650 = 1;
    DAT_23006655 = 1;
    DAT_2300665a = 1;
    DAT_2300665f = 1;
  }
  if (0x1e < bVar4) {
    bVar4 = 0x1c;
  }
  if (0x1e < bVar5) {
    bVar5 = 0x1c;
  }
  uVar9 = 0;
LAB_230280b8:
  do {
    iVar8 = uVar9 * 5;
    iVar6 = uVar9 * 4;
    pbVar7 = &DAT_23006638 + iVar8;
    uVar10 = (int)(uint)DAT_23001502 >> (uVar9 & 0xff) & 1;
    if ((int)((uint)(byte)(&DAT_23006638)[iVar8] << 0x1e) < 0) {
      if ((&DAT_2300663a)[iVar8] == '\0') {
        *pbVar7 = *pbVar7 & 0xfd;
        goto LAB_230280e0;
      }
      if ((byte)(&DAT_23006639)[iVar8] == uVar10) {
        if (bVar4 <= (byte)(&DAT_2300663b)[iVar8]) {
          *pbVar7 = *pbVar7 & 0xfd;
        }
      }
      else {
        (&DAT_2300663b)[iVar8] = 0;
      }
    }
    else {
LAB_230280e0:
      if (uVar10 == 0) {
        iVar8 = uVar9 * 5;
        pbVar7 = &DAT_23006638 + iVar8;
        bVar3 = (&DAT_23006639)[iVar8];
        if (bVar3 == 1) {
          (&DAT_2300663a)[iVar8] = 0;
        }
        else if ((int)((uint)(byte)(&DAT_23006638)[iVar8] << 0x1f) < 0) {
          if ((&DAT_2300663c)[iVar8] != '\x01') {
            bVar3 = 0;
          }
          iVar2 = uVar9 * 5;
          if ((&DAT_2300663c)[iVar8] == '\x01') {
            bVar3 = (byte)DAT_2300495b;
          }
          if (bVar3 < (byte)(&DAT_2300663a)[iVar2]) {
            (&DAT_23006639)[iVar2] = 1;
            FUN_23027170(1,uVar9,iVar6,(&DAT_2300663a)[iVar2],in_r3);
            (&DAT_23006638)[iVar2] = (&DAT_23006638)[iVar2] | 2;
            (&DAT_2300663a)[iVar2] = bVar4;
            (&DAT_2300663c)[iVar2] = 0;
          }
        }
        else {
          *pbVar7 = *pbVar7 | 1;
          (&DAT_2300663a)[iVar8] = 1;
          if (((&DAT_2300663c)[iVar8] == '\0') && (uVar9 < 2)) {
            FUN_23027170(1,uVar9,iVar6,0,in_r3);
            (&DAT_23006639)[iVar8] = 1;
            *pbVar7 = *pbVar7 | 2;
            (&DAT_2300663a)[iVar8] = bVar4;
            (&DAT_2300663c)[iVar8] = 0;
            uVar9 = uVar9 + 1;
            goto LAB_230280b8;
          }
        }
      }
      else {
        iVar8 = uVar9 * 5;
        if ((&DAT_23006639)[iVar8] == '\0') {
          (&DAT_2300663a)[iVar8] = 0;
        }
        else if (((&DAT_23006638)[iVar8] & 1) == 0) {
          iVar2 = uVar9 * 5;
          bVar3 = (&DAT_23006638)[iVar8] & 1;
          if ((&DAT_2300663c)[iVar8] == '\x01') {
            bVar3 = DAT_2300495b._2_1_;
          }
          if (bVar3 < (byte)(&DAT_2300663a)[iVar2]) {
            (&DAT_23006639)[iVar2] = 0;
            FUN_23027170(0,uVar9,iVar6,(&DAT_2300663a)[iVar2],in_r3);
            (&DAT_23006638)[iVar2] = (&DAT_23006638)[iVar2] | 2;
            (&DAT_2300663a)[iVar2] = bVar5;
            (&DAT_2300663c)[iVar2] = 0;
          }
        }
        else {
          (&DAT_23006638)[iVar8] = 0;
          (&DAT_2300663a)[iVar8] = 1;
        }
      }
    }
    uVar9 = uVar9 + 1;
    if (uVar9 == 6) {
      return;
    }
  } while( true );
}


