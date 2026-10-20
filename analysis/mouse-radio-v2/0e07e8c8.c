/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07e8c8. Types and names are inferred; NOT original source. */

void FUN_0e07e8c8(int param_1,byte *param_2,int param_3)

{
  char cVar1;
  short sVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  
  cVar1 = *(char *)(param_1 + 3);
  sVar2 = (short)param_3;
  if (cVar1 == '\x02') {
    uVar7 = (uint)*(byte *)(param_1 + 1);
    uVar10 = (uint)*(ushort *)(DAT_0e07ea08 + 0x26);
    cVar1 = *(char *)(DAT_0e07ea08 + uVar7 + 0x22);
    if (cVar1 == '\0') {
      uVar8 = (uint)*(byte *)(DAT_0e07ea08 + 0x1e);
      uVar7 = (uint)*(byte *)(DAT_0e07ea08 + 0x1f);
      uVar6 = (uint)*(byte *)(DAT_0e07ea08 + 0x20);
    }
    else if (cVar1 == '\x01') {
      iVar5 = DAT_0e07ea08 + (uVar7 + 2) * 8;
      uVar8 = (uint)*(byte *)(iVar5 + 6);
      uVar7 = (uint)*(byte *)(iVar5 + 7);
      uVar6 = (uint)*(byte *)(iVar5 + 8);
    }
    else {
      iVar5 = DAT_0e07ea08 + ((uint)*(byte *)(DAT_0e07ea08 + 0x23) + uVar7 * 2 + 4) * 4;
      uVar8 = (uint)*(byte *)(iVar5 + 6);
      uVar7 = (uint)*(byte *)(iVar5 + 7);
      uVar6 = (uint)*(byte *)(iVar5 + 8);
    }
    if (param_3 != 0) {
      pbVar4 = param_2 + sVar2 * 0xc;
      do {
        param_2[4] = (byte)(uVar10 * uVar8 >> 0x10);
        param_2[5] = (byte)(uVar10 * uVar7 >> 0x10);
        param_2[6] = (byte)(uVar10 * uVar6 >> 0x10);
        param_2[7] = 0xff;
        param_2 = param_2 + 0xc;
      } while (param_2 != pbVar4);
      return;
    }
  }
  else if (cVar1 == '\x03') {
    uVar7 = (uint)*(ushort *)(DAT_0e07ea08 + 0x39);
    if (*(char *)(DAT_0e07ea08 + 0x36) == '\0') {
      if (param_3 != 0) goto LAB_0e07e986;
    }
    else if (param_3 != 0) {
      puVar9 = (undefined4 *)(DAT_0e07ea08 + 0x2d);
      pbVar4 = param_2;
      do {
        *(undefined4 *)(pbVar4 + 8) = *(undefined4 *)(pbVar4 + 4);
        pbVar3 = pbVar4 + 0xc;
        *(undefined4 *)pbVar4 = *puVar9;
        pbVar4 = pbVar3;
      } while (pbVar3 != param_2 + sVar2 * 0xc);
LAB_0e07e986:
      pbVar4 = param_2 + sVar2 * 0xc;
      do {
        param_2[4] = (byte)(uVar7 * ((uint)*param_2 - (uint)param_2[8]) + (uint)param_2[8] * 0x100 +
                            0x80 >> 8);
        param_2[5] = (byte)(uVar7 * ((uint)param_2[1] - (uint)param_2[9]) + (uint)param_2[9] * 0x100
                            + 0x80 >> 8);
        param_2[6] = (byte)(uVar7 * ((uint)param_2[2] - (uint)param_2[10]) +
                            (uint)param_2[10] * 0x100 + 0x80 >> 8);
        param_2[7] = (byte)(uVar7 * ((uint)param_2[3] - (uint)param_2[0xb]) +
                            (uint)param_2[0xb] * 0x100 + 0x80 >> 8);
        param_2 = param_2 + 0xc;
      } while (param_2 != pbVar4);
      return;
    }
  }
  else if (cVar1 == '\0') {
    if (param_3 != 0) {
      pbVar4 = param_2 + 4;
      do {
        pbVar3 = pbVar4 + 0xc;
        pbVar4[0] = 0;
        pbVar4[1] = 0;
        pbVar4[2] = 0;
        pbVar4[3] = 0;
        pbVar4 = pbVar3;
      } while (pbVar3 != param_2 + 4 + sVar2 * 0xc);
    }
    *DAT_0e07ea04 = 0;
    return;
  }
  return;
}


