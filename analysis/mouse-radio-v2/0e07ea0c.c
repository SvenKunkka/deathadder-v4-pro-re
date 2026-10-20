/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07ea0c. Types and names are inferred; NOT original source. */

void FUN_0e07ea0c(int param_1,byte *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  cVar1 = *(char *)(param_1 + 0x11);
  if (cVar1 == '\x02') {
    if (*(ushort *)(param_1 + 0x12) <= *(ushort *)(param_1 + 0x22)) {
      uVar7 = *(uint *)(param_1 + 0x1a);
      uVar6 = *(int *)(param_1 + 0x16) + (uint)*(ushort *)(param_1 + 0x14);
      bVar8 = uVar7 <= uVar6;
      if (bVar8) {
        uVar6 = 9;
      }
      *(undefined1 *)(param_1 + 0x22) = 0;
      *(undefined1 *)(param_1 + 0x23) = 0;
      if (bVar8) {
        *(uint *)(param_1 + 0x16) = uVar7;
        *(char *)(param_1 + 0x11) = (char)uVar6;
      }
      else {
        *(uint *)(param_1 + 0x16) = uVar6;
      }
      return;
    }
  }
  else if (cVar1 == '\x03') {
    if (*(ushort *)(param_1 + 0x12) <= *(ushort *)(param_1 + 0x22)) {
      *(undefined1 *)(param_1 + 0x22) = 0;
      *(undefined1 *)(param_1 + 0x23) = 0;
      pcVar3 = DAT_0e07eb70;
      if ((uint)*(ushort *)(param_1 + 0x14) < *(uint *)(param_1 + 0x16)) {
        *(uint *)(param_1 + 0x16) = *(uint *)(param_1 + 0x16) - (uint)*(ushort *)(param_1 + 0x14);
        return;
      }
      cVar1 = *(char *)(param_1 + 4);
      cVar2 = *DAT_0e07eb70;
      *(undefined1 *)(param_1 + 0x16) = 0;
      *(undefined1 *)(param_1 + 0x17) = 0;
      *(undefined1 *)(param_1 + 0x18) = 0;
      *(undefined1 *)(param_1 + 0x19) = 0;
      *(char *)(param_1 + 3) = cVar1;
      if (cVar2 == '\0') {
        *pcVar3 = '\x01';
        return;
      }
      *pcVar3 = '\0';
      if (cVar1 == '\x01') {
        *(undefined1 *)(param_1 + 0x11) = 1;
        return;
      }
      *(undefined1 *)(param_1 + 0x1c) = 0;
      *(undefined1 *)(param_1 + 0x1d) = 0;
      *(undefined1 *)(param_1 + 0x11) = 2;
      *(undefined1 *)(param_1 + 0x1a) = 0xd0;
      *(undefined1 *)(param_1 + 0x1b) = 7;
      return;
    }
  }
  else if ((cVar1 == '\x01') && (*(ushort *)(param_1 + 0x12) <= *(ushort *)(param_1 + 0x22))) {
    *(undefined1 *)(param_1 + 0x22) = 0;
    uVar7 = *(int *)(param_1 + 0x1e) + (uint)*(ushort *)(param_1 + 0x14);
    *(uint *)(param_1 + 0x1e) = uVar7;
    *(undefined1 *)(param_1 + 0x23) = 0;
    if (0xfe < uVar7) {
      if (param_3 != 0) {
        pbVar5 = param_2 + 4;
        do {
          pbVar4 = pbVar5 + 0xc;
          *(undefined4 *)pbVar5 = *(undefined4 *)(pbVar5 + -4);
          *(undefined4 *)(pbVar5 + 4) = *(undefined4 *)(pbVar5 + -4);
          pbVar5 = pbVar4;
        } while (pbVar4 != param_2 + 4 + (short)param_3 * 0xc);
      }
      *(undefined1 *)(param_1 + 0x11) = 9;
      *(undefined1 *)(param_1 + 3) = *(undefined1 *)(param_1 + 4);
      return;
    }
    if (param_3 != 0) {
      pbVar5 = param_2;
      while( true ) {
        pbVar5[4] = (byte)(uVar7 * ((uint)*pbVar5 - (uint)pbVar5[8]) +
                           (uint)pbVar5[8] * 0x100 + 0x80 >> 8);
        pbVar5[5] = (byte)(*(int *)(param_1 + 0x1e) * ((uint)pbVar5[1] - (uint)pbVar5[9]) +
                           (uint)pbVar5[9] * 0x100 + 0x80 >> 8);
        pbVar5[6] = (byte)(*(int *)(param_1 + 0x1e) * ((uint)pbVar5[2] - (uint)pbVar5[10]) +
                           (uint)pbVar5[10] * 0x100 + 0x80 >> 8);
        pbVar5[7] = (byte)(*(int *)(param_1 + 0x1e) * ((uint)pbVar5[3] - (uint)pbVar5[0xb]) +
                           (uint)pbVar5[0xb] * 0x100 + 0x80 >> 8);
        if (param_2 + (short)param_3 * 0xc == pbVar5 + 0xc) break;
        uVar7 = *(uint *)(param_1 + 0x1e);
        pbVar5 = pbVar5 + 0xc;
      }
      return;
    }
  }
  return;
}


