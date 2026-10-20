/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230203c0. Types and names are inferred; NOT original source. */

undefined4 ram_candidate_230203c0(undefined4 param_1,undefined1 *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  bVar1 = param_2[4];
  bVar2 = param_2[6];
  uVar6 = bVar1 & 0x1f;
  if (7 < uVar6) {
    return 0xffffffea;
  }
  switch(*param_2) {
  case 5:
    cVar4 = param_2[1];
    iVar9 = 4;
    if (cVar4 != '\x04') goto LAB_230203f2;
    goto LAB_230204a8;
  case 6:
    iVar9 = 0;
    break;
  default:
    goto switchD_230203d8_caseD_7;
  case 8:
    iVar9 = 1;
    break;
  case 9:
    iVar9 = 2;
    break;
  case 0xb:
    iVar9 = 3;
  }
  cVar4 = param_2[1];
  if (cVar4 == '\x04') {
LAB_230204a8:
    uVar7 = (uint)*(ushort *)(param_2 + 2);
    iVar5 = 0;
    if (uVar7 == 0) goto LAB_230204b0;
LAB_230203fe:
    uVar8 = uVar7 & 0x3fff;
    if (uVar7 >> 0xe == 1) {
      uVar8 = uVar8 * 1000 & 0xffff;
    }
    uVar7 = uVar8 / 0x7d - 1 & 0xffff;
    if (0x13f < uVar7) {
      return 0xffffffea;
    }
    if (uVar8 < 0x7d) {
      return 0xffffffea;
    }
  }
  else {
LAB_230203f2:
    if (cVar4 != '\x05') {
      return 0xffffffea;
    }
    uVar7 = (uint)*(ushort *)(param_2 + 2);
    iVar5 = 1;
    if (uVar7 != 0) goto LAB_230203fe;
LAB_230204b0:
    uVar7 = 0x4f;
  }
  uVar8 = bVar1 & 0x20;
  bVar3 = (byte)(1 << uVar6);
  if ((bVar1 & 0x20) == 0) {
    DAT_230002f8 = bVar3 | DAT_230002f8;
    if (7 < (byte)param_2[5] - 1) {
      return 0xffffffea;
    }
    (&DAT_230002f0)[uVar6] = param_2[5];
    *(uint *)(uVar6 * 0x10 + 0x5f982518) = iVar5 << 0xc | iVar9 << 8 | uVar7 << 0x10;
    *(uint *)(uVar6 * 0x10 + 0x5f982510) = uVar8;
  }
  else {
    DAT_230002f8 = DAT_230002f8 & ~bVar3;
    if ((7 < (byte)param_2[5] - 1) || (7 < bVar2 - 1)) {
switchD_230203d8_caseD_7:
      return 0xffffffea;
    }
    (&DAT_230002f0)[uVar6] = param_2[5];
    *(uint *)(uVar6 * 0x10 + 0x5f982518) = iVar5 << 0xc | iVar9 << 8 | uVar7 << 0x10 | 0x8000;
    *(undefined4 *)(uVar6 * 0x10 + 0x5f982510) = 0;
    uVar8 = (byte)(&DAT_0e09b268)[bVar2] & 0x1f | (uint)((byte)(&DAT_0e09b268)[bVar2] >> 5) << 8 |
            0x40000000;
  }
  *(uint *)(uVar6 * 0x10 + 0x5f982514) = uVar8;
  return 0;
}


