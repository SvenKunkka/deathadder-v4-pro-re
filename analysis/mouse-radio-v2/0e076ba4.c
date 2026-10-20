/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e076ba4. Types and names are inferred; NOT original source. */

void FUN_0e076ba4(void)

{
  ushort uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  ushort *puVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  byte *pbVar8;
  byte bVar9;
  uint uVar10;
  byte bVar11;
  undefined4 in_r3;
  char cVar12;
  
  pbVar8 = DAT_0e076cd4;
  bVar11 = *DAT_0e076ccc | *DAT_0e076cc8 << 1;
  if (*DAT_0e076cd0 == bVar11) {
    bVar11 = *DAT_0e076cdc;
    pbVar8 = DAT_0e076cdc;
  }
  else {
    *DAT_0e076cd0 = bVar11;
    bVar11 = bVar11 | *pbVar8 << 2;
    bVar9 = bVar11 & 0x3f;
    *pbVar8 = bVar11;
    pbVar8 = DAT_0e076cdc;
    if (bVar9 == 0x34) {
LAB_0e076bdc:
      if (*DAT_0e076cd8 == '\x03') {
        bVar11 = *DAT_0e076cdc + 1;
        *DAT_0e076cdc = bVar11;
      }
      else {
        FUN_0e073ab0(1,6,bVar9,*DAT_0e076cd8,in_r3);
        pbVar8 = DAT_0e076cdc;
        *DAT_0e076d08 = 0x102;
        bVar11 = *pbVar8;
      }
    }
    else {
      if (bVar9 < 0x35) {
        if (bVar9 != 7) {
          if (bVar9 != 0xb) goto LAB_0e076bf4;
          goto LAB_0e076bdc;
        }
      }
      else if (bVar9 != 0x38) {
LAB_0e076bf4:
        bVar11 = *DAT_0e076cdc;
        goto LAB_0e076bf8;
      }
      if (*DAT_0e076cd8 == '\x03') {
        bVar11 = *DAT_0e076cdc - 1;
        *DAT_0e076cdc = bVar11;
      }
      else {
        FUN_0e073ab0(1,7,bVar9,*DAT_0e076cd8,in_r3);
        pbVar8 = DAT_0e076cdc;
        DAT_0e076d08[1] = 0x102;
        bVar11 = *pbVar8;
      }
    }
LAB_0e076bf8:
    puVar2 = DAT_0e076ce4;
    *DAT_0e076ce0 = 1;
    puVar3 = DAT_0e076ce8;
    *puVar2 = 0;
    *puVar3 = 0;
  }
  puVar4 = DAT_0e076cf0;
  uVar7 = (uint)*DAT_0e076cf0;
  uVar10 = (uint)*(byte *)(DAT_0e076cec + 7) * 2;
  if (bVar11 == 0) {
    if (uVar7 <= uVar10 && uVar10 - uVar7 != 0) {
      *DAT_0e076cf0 = *DAT_0e076cf0 + 1;
      return;
    }
    cVar12 = *DAT_0e076cf4;
    *DAT_0e076cf8 = '\0';
    pcVar5 = DAT_0e076cfc;
    *puVar4 = (ushort)uVar10;
    *pcVar5 = cVar12;
    return;
  }
  if ((bVar11 & 0x80) == 0) {
    cVar12 = '\x01';
  }
  else {
    cVar12 = '\x02';
  }
  *DAT_0e076cf4 = cVar12;
  if (uVar10 < uVar7 || uVar10 - uVar7 == 0) {
    *DAT_0e076cfc = cVar12;
  }
  else if (*DAT_0e076cfc != cVar12) {
    *DAT_0e076cf8 = '\x01';
    goto LAB_0e076c62;
  }
  pcVar5 = DAT_0e076cf8;
  *puVar4 = 0;
  pcVar6 = DAT_0e076d00;
  if (*pcVar5 == '\0') {
    *pbVar8 = 0;
    puVar4 = DAT_0e076d04;
    uVar1 = *DAT_0e076d04;
    *pcVar6 = bVar11 + *pcVar6;
    *puVar4 = uVar1 | 2;
    return;
  }
LAB_0e076c62:
  *pbVar8 = 0;
  return;
}


