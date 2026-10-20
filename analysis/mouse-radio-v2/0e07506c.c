/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07506c. Types and names are inferred; NOT original source. */

void FUN_0e07506c(void)

{
  byte bVar1;
  undefined1 uVar2;
  ushort uVar3;
  short sVar4;
  byte *pbVar5;
  byte *pbVar6;
  short *psVar7;
  ushort *puVar8;
  ushort *puVar9;
  char *pcVar10;
  undefined4 uVar11;
  byte bVar12;
  uint uVar13;
  undefined2 *puVar14;
  uint uVar15;
  uint local_38;
  ushort local_34;
  undefined1 local_28;
  char cStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  ushort uStack_24;
  undefined2 local_22;
  undefined2 uStack_20;
  undefined2 local_1e;
  undefined2 uStack_1c;
  undefined2 local_1a;
  
  pbVar5 = DAT_0e075264;
  pcVar10 = DAT_0e075250;
  puVar9 = DAT_0e07524c;
  puVar8 = DAT_0e075248;
  psVar7 = DAT_0e075244;
  sVar4 = *DAT_0e075244;
  uVar3 = *DAT_0e075248;
  if (((*DAT_0e07524c & 7) != 0 || (sVar4 != 0 || uVar3 != 0)) || (*DAT_0e075250 != '\0')) {
    local_38 = (uint)(*DAT_0e075264 | *DAT_0e075268) | *DAT_0e075260 & 0x3f |
               (uint)(byte)(*DAT_0e075250 + DAT_0e075264[1]) << 8 |
               ((int)sVar4 >> 8 & 0xffU) << 0x10 | (int)sVar4 << 0x18;
    local_34 = uVar3 << 8 | uVar3 >> 8;
    FUN_0e06d9f8(1,&local_38,6);
    puVar14 = DAT_0e07526c;
    uVar3 = *puVar9;
    *pcVar10 = '\0';
    *puVar8 = 0;
    *psVar7 = 0;
    pbVar5[0] = 0;
    pbVar5[1] = 0;
    pbVar5[2] = 0;
    pbVar5[3] = 0;
    pbVar5[4] = 0;
    pbVar5[5] = 0;
    pbVar5[6] = 0;
    pbVar5[7] = 0;
    *puVar9 = uVar3 & 0xfff8;
    *puVar14 = 0;
  }
  if (*DAT_0e075254 != '\0') {
    uVar15 = (uint)*puVar9;
    if ((int)(uVar15 << 0x1c) < 0) {
      FUN_0e06d9f8(2,DAT_0e075274,8);
      uVar15 = (uint)(*puVar9 & 0xfff7);
      *puVar9 = *puVar9 & 0xfff7;
    }
    pbVar5 = DAT_0e075258;
    pbVar6 = DAT_0e07525c;
    if ((int)(uVar15 << 0x19) < 0) {
      FUN_0e06d9f8(4,DAT_0e075270,0x10);
      uVar15 = (uint)(*puVar9 & 0xffbf);
      *puVar9 = *puVar9 & 0xffbf;
      pbVar5 = DAT_0e075258;
      pbVar6 = DAT_0e07525c;
    }
    DAT_0e075258 = pbVar5;
    DAT_0e07525c = pbVar6;
    if (((int)(uVar15 << 0x18) < 0) && (uVar13 = (uint)*pbVar5, *pbVar6 != uVar13)) {
      local_28 = 5;
      cStack_27 = *(char *)(DAT_0e075280 + uVar13);
      uVar2 = *(undefined1 *)(DAT_0e075284 + uVar13);
      *DAT_0e075288 = cStack_27;
      local_1a = 0;
      uStack_26 = 0;
      uStack_25 = 0;
      uStack_24 = 0;
      local_22 = 0;
      uStack_20 = 0;
      local_1e = 0;
      uStack_1c = 0;
      *DAT_0e07528c = uVar2;
      if (cStack_27 == '\x02') {
        puVar14 = DAT_0e075298;
        if (*DAT_0e075294 != '\x01') {
          puVar14 = DAT_0e07529c;
        }
        uStack_25 = (undefined1)*puVar14;
        uStack_24 = (ushort)puVar14[1] >> 8 | (ushort)(((uint)(ushort)puVar14[1] << 0x18) >> 0x10);
        uStack_26 = (undefined1)((ushort)*puVar14 >> 8);
        uVar2 = uStack_26;
      }
      else if ((((cStack_27 != '\n') && (cStack_27 != '\x01')) && (cStack_27 != 'X')) &&
              (uVar2 = uStack_26, cStack_27 == '1')) {
        uVar11 = *DAT_0e075290;
        local_28 = (undefined1)uVar11;
        cStack_27 = (char)((uint)uVar11 >> 8);
        uStack_26 = (undefined1)((uint)uVar11 >> 0x10);
        uStack_25 = (undefined1)((uint)uVar11 >> 0x18);
        uStack_24 = (ushort)DAT_0e075290[1];
        local_22 = (undefined2)((uint)DAT_0e075290[1] >> 0x10);
        uStack_20 = (undefined2)DAT_0e075290[2];
        local_1e = (undefined2)((uint)DAT_0e075290[2] >> 0x10);
        uStack_1c = (undefined2)DAT_0e075290[3];
        local_1a = (undefined2)((uint)DAT_0e075290[3] >> 0x10);
        uVar2 = uStack_26;
      }
      uStack_26 = uVar2;
      FUN_0e06d9f8(4,&local_28);
      bVar1 = *pbVar6;
      bVar12 = *pbVar5 + 1;
      if (7 < bVar12) {
        bVar12 = 0;
      }
      *pbVar5 = bVar12;
      uVar15 = (uint)*puVar9;
      if (bVar1 <= bVar12) {
        uVar15 = uVar15 & 0xffffff7f;
        *puVar9 = (ushort)uVar15;
      }
    }
    if ((int)(uVar15 << 0x1a) < 0) {
      FUN_0e06d9f8(4,DAT_0e07527c,0x10);
      uVar15 = (uint)(*puVar9 & 0xffdf);
      *puVar9 = *puVar9 & 0xffdf;
    }
    if ((int)(uVar15 << 0x1b) < 0) {
      FUN_0e06d9f8(4,DAT_0e075278,0x10);
      *puVar9 = *puVar9 & 0xffef;
      return;
    }
  }
  return;
}


