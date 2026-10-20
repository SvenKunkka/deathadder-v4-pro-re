/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07e880. Types and names are inferred; NOT original source. */

void FUN_0e07e880(int param_1,byte *param_2,int param_3)

{
  char cVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  cVar1 = *(char *)(param_1 + 0x11);
  if (cVar1 == '\x02') {
    if (*(ushort *)(param_1 + 0x12) <= *(ushort *)(param_1 + 0x22)) {
      uVar5 = *(uint *)(param_1 + 0x1a);
      uVar4 = *(int *)(param_1 + 0x16) + (uint)*(ushort *)(param_1 + 0x14);
      bVar6 = uVar5 <= uVar4;
      if (bVar6) {
        uVar4 = 9;
      }
      *(undefined1 *)(param_1 + 0x22) = 0;
      *(undefined1 *)(param_1 + 0x23) = 0;
      if (bVar6) {
        *(uint *)(param_1 + 0x16) = uVar5;
        *(char *)(param_1 + 0x11) = (char)uVar4;
      }
      else {
        *(uint *)(param_1 + 0x16) = uVar4;
      }
      return;
    }
  }
  else if (cVar1 == '\x03') {
    if (*(ushort *)(param_1 + 0x12) <= *(ushort *)(param_1 + 0x22)) {
      *(undefined1 *)(param_1 + 0x22) = 0;
      *(undefined1 *)(param_1 + 0x23) = 0;
      if ((uint)*(ushort *)(param_1 + 0x14) < *(uint *)(param_1 + 0x16)) {
        *(uint *)(param_1 + 0x16) = *(uint *)(param_1 + 0x16) - (uint)*(ushort *)(param_1 + 0x14);
        return;
      }
      *(undefined1 *)(param_1 + 0x16) = 0;
      *(undefined1 *)(param_1 + 0x17) = 0;
      *(undefined1 *)(param_1 + 0x18) = 0;
      *(undefined1 *)(param_1 + 0x19) = 0;
      *(char *)(param_1 + 3) = *(char *)(param_1 + 4);
      if (DAT_23007750 == '\0') {
        DAT_23007750 = 1;
        return;
      }
      DAT_23007750 = 0;
      if (*(char *)(param_1 + 4) == '\x01') {
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
    uVar5 = *(int *)(param_1 + 0x1e) + (uint)*(ushort *)(param_1 + 0x14);
    *(uint *)(param_1 + 0x1e) = uVar5;
    *(undefined1 *)(param_1 + 0x23) = 0;
    if (0xfe < uVar5) {
      if (param_3 != 0) {
        pbVar3 = param_2 + 4;
        do {
          pbVar2 = pbVar3 + 0xc;
          *(undefined4 *)pbVar3 = *(undefined4 *)(pbVar3 + -4);
          *(undefined4 *)(pbVar3 + 4) = *(undefined4 *)(pbVar3 + -4);
          pbVar3 = pbVar2;
        } while (pbVar2 != param_2 + 4 + (short)param_3 * 0xc);
      }
      *(undefined1 *)(param_1 + 0x11) = 9;
      *(undefined1 *)(param_1 + 3) = *(undefined1 *)(param_1 + 4);
      return;
    }
    if (param_3 != 0) {
      pbVar3 = param_2;
      while( true ) {
        pbVar3[4] = (byte)(uVar5 * ((uint)*pbVar3 - (uint)pbVar3[8]) +
                           (uint)pbVar3[8] * 0x100 + 0x80 >> 8);
        pbVar3[5] = (byte)(*(int *)(param_1 + 0x1e) * ((uint)pbVar3[1] - (uint)pbVar3[9]) +
                           (uint)pbVar3[9] * 0x100 + 0x80 >> 8);
        pbVar3[6] = (byte)(*(int *)(param_1 + 0x1e) * ((uint)pbVar3[2] - (uint)pbVar3[10]) +
                           (uint)pbVar3[10] * 0x100 + 0x80 >> 8);
        pbVar3[7] = (byte)(*(int *)(param_1 + 0x1e) * ((uint)pbVar3[3] - (uint)pbVar3[0xb]) +
                           (uint)pbVar3[0xb] * 0x100 + 0x80 >> 8);
        if (param_2 + (short)param_3 * 0xc == pbVar3 + 0xc) break;
        uVar5 = *(uint *)(param_1 + 0x1e);
        pbVar3 = pbVar3 + 0xc;
      }
      return;
    }
  }
  return;
}


