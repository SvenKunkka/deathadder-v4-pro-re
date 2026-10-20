/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07e73c. Types and names are inferred; NOT original source. */

void FUN_0e07e73c(int param_1,byte *param_2,int param_3)

{
  char cVar1;
  short sVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  cVar1 = *(char *)(param_1 + 3);
  sVar2 = (short)param_3;
  if (cVar1 == '\x02') {
    uVar7 = (uint)*(byte *)(param_1 + 1);
    uVar9 = (uint)DAT_23004d44._2_2_;
    if ((&DAT_23004d42)[uVar7] == '\0') {
      uVar8 = (uint)(byte)DAT_23004d3e;
      uVar7 = (uint)DAT_23004d3e._1_1_;
      uVar6 = (uint)DAT_23004d3e._2_1_;
    }
    else if ((&DAT_23004d42)[uVar7] == '\x01') {
      iVar3 = uVar7 + 2;
      uVar8 = (uint)*(byte *)(&DAT_23004d26 + iVar3 * 4);
      uVar7 = (uint)*(byte *)((int)&DAT_23004d26 + iVar3 * 8 + 1);
      uVar6 = (uint)*(byte *)(&DAT_23004d28 + iVar3 * 4);
    }
    else {
      iVar3 = (uint)DAT_23004d43 + uVar7 * 2 + 4;
      uVar8 = (uint)*(byte *)(&DAT_23004d26 + iVar3 * 2);
      uVar7 = (uint)*(byte *)((int)&DAT_23004d26 + iVar3 * 4 + 1);
      uVar6 = (uint)*(byte *)(&DAT_23004d28 + iVar3 * 2);
    }
    if (param_3 != 0) {
      pbVar5 = param_2 + sVar2 * 0xc;
      do {
        param_2[4] = (byte)(uVar9 * uVar8 >> 0x10);
        param_2[5] = (byte)(uVar9 * uVar7 >> 0x10);
        param_2[6] = (byte)(uVar9 * uVar6 >> 0x10);
        param_2[7] = 0xff;
        param_2 = param_2 + 0xc;
      } while (param_2 != pbVar5);
      return;
    }
  }
  else if (cVar1 == '\x03') {
    uVar7 = (uint)DAT_23004d59;
    if (DAT_23004d56 == '\0') {
      if (param_3 != 0) goto LAB_0e07e7fa;
    }
    else if (param_3 != 0) {
      pbVar5 = param_2;
      do {
        *(undefined4 *)(pbVar5 + 8) = *(undefined4 *)(pbVar5 + 4);
        pbVar4 = pbVar5 + 0xc;
        *(undefined4 *)pbVar5 = DAT_23004d4d;
        pbVar5 = pbVar4;
      } while (pbVar4 != param_2 + sVar2 * 0xc);
LAB_0e07e7fa:
      pbVar5 = param_2 + sVar2 * 0xc;
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
      } while (param_2 != pbVar5);
      return;
    }
  }
  else if (cVar1 == '\0') {
    if (param_3 != 0) {
      pbVar5 = param_2 + 4;
      do {
        pbVar4 = pbVar5 + 0xc;
        pbVar5[0] = 0;
        pbVar5[1] = 0;
        pbVar5[2] = 0;
        pbVar5[3] = 0;
        pbVar5 = pbVar4;
      } while (pbVar4 != param_2 + 4 + sVar2 * 0xc);
    }
    DAT_23007751 = 0;
    return;
  }
  return;
}


