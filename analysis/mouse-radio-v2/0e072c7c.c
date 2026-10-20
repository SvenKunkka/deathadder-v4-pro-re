/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e072c7c. Types and names are inferred; NOT original source. */

void FUN_0e072c7c(void)

{
  ushort uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  ushort *puVar5;
  char *pcVar6;
  undefined1 *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  uint local_24 [2];
  
  pcVar3 = DAT_0e072dbc;
  if (*DAT_0e072dbc != '\x01') {
    return;
  }
  iVar8 = *DAT_0e072dc0;
  uVar1 = *DAT_0e072dc4;
  iVar2 = DAT_0e072dc0[1];
  puVar11 = *(uint **)(iVar8 + 0x10);
  uVar9 = (**(code **)(*(int *)(iVar8 + 8) + 4))(iVar8,local_24);
  if (uVar9 == 0) {
    if (((local_24[0] ^ *puVar11) & 1 << (sbyte)iVar2) == 0) {
      uVar9 = 0;
    }
    else {
      uVar9 = 1;
    }
  }
  iVar8 = *DAT_0e072dc8;
  iVar2 = DAT_0e072dc8[1];
  puVar11 = *(uint **)(iVar8 + 0x10);
  iVar8 = (**(code **)(*(int *)(iVar8 + 8) + 4))(iVar8,local_24);
  if (iVar8 == 0) {
    if (((local_24[0] ^ *puVar11) & 1 << (sbyte)iVar2) == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = 1;
    }
  }
  iVar10 = *DAT_0e072dcc;
  iVar2 = DAT_0e072dcc[1];
  puVar11 = *(uint **)(iVar10 + 0x10);
  iVar10 = (**(code **)(*(int *)(iVar10 + 8) + 4))(iVar10,local_24);
  pcVar6 = DAT_0e072ddc;
  puVar5 = DAT_0e072dd4;
  pcVar4 = DAT_0e072dd0;
  if (iVar10 == 0) {
    if (((local_24[0] ^ *puVar11) & 1 << (sbyte)iVar2) == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = 1;
    }
  }
  if (((uVar9 | iVar8 << 1 | iVar10 << 2) & (uint)uVar1) == 0) {
    if (*DAT_0e072dd0 == '\0') {
      *DAT_0e072dd0 = '\x01';
      *puVar5 = 0;
    }
    else if (6999 < *DAT_0e072dd4) {
      *DAT_0e072dd8 = 0;
      goto LAB_0e072d64;
    }
    *DAT_0e072dd8 = 1;
  }
  else {
    if (*DAT_0e072ddc != '\x01') {
      if (6999 < *DAT_0e072dd4) {
        return;
      }
      *DAT_0e072dd8 = 0;
      *pcVar4 = '\0';
      return;
    }
LAB_0e072d64:
    puVar7 = DAT_0e072de0;
    *puVar5 = 0;
    *puVar7 = 0;
    puVar7 = DAT_0e072de4;
    *pcVar4 = '\0';
    *puVar7 = 1;
    *DAT_0e072de8 = 0x8f;
    *DAT_0e072dec = 0xc;
    *DAT_0e072df0 = 0xb;
    *DAT_0e072df4 = 0;
    *DAT_0e072df8 = 0;
    *DAT_0e072dfc = 0;
    *DAT_0e072e00 = 0x55;
    thunk_FUN_0e0806c4();
    FUN_0e078fcc();
    if (*pcVar6 == '\0') {
      thunk_FUN_0e080570(10,3);
    }
    *pcVar3 = '\0';
    *pcVar6 = '\0';
  }
  return;
}


