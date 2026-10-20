/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0dec7c. Types and names are inferred; NOT original source. */

void FUN_1c0dec7c(void)

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
  
  pcVar3 = DAT_1c0dedbc;
  if (*DAT_1c0dedbc != '\x01') {
    return;
  }
  iVar8 = *DAT_1c0dedc0;
  uVar1 = *DAT_1c0dedc4;
  iVar2 = DAT_1c0dedc0[1];
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
  iVar8 = *DAT_1c0dedc8;
  iVar2 = DAT_1c0dedc8[1];
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
  iVar10 = *DAT_1c0dedcc;
  iVar2 = DAT_1c0dedcc[1];
  puVar11 = *(uint **)(iVar10 + 0x10);
  iVar10 = (**(code **)(*(int *)(iVar10 + 8) + 4))(iVar10,local_24);
  pcVar6 = DAT_1c0deddc;
  puVar5 = DAT_1c0dedd4;
  pcVar4 = DAT_1c0dedd0;
  if (iVar10 == 0) {
    if (((local_24[0] ^ *puVar11) & 1 << (sbyte)iVar2) == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = 1;
    }
  }
  if (((uVar9 | iVar8 << 1 | iVar10 << 2) & (uint)uVar1) == 0) {
    if (*DAT_1c0dedd0 == '\0') {
      *DAT_1c0dedd0 = '\x01';
      *puVar5 = 0;
    }
    else if (6999 < *DAT_1c0dedd4) {
      *DAT_1c0dedd8 = 0;
      goto LAB_1c0ded64;
    }
    *DAT_1c0dedd8 = 1;
  }
  else {
    if (*DAT_1c0deddc != '\x01') {
      if (6999 < *DAT_1c0dedd4) {
        return;
      }
      *DAT_1c0dedd8 = 0;
      *pcVar4 = '\0';
      return;
    }
LAB_1c0ded64:
    puVar7 = DAT_1c0dede0;
    *puVar5 = 0;
    *puVar7 = 0;
    puVar7 = DAT_1c0dede4;
    *pcVar4 = '\0';
    *puVar7 = 1;
    *DAT_1c0dede8 = 0x8f;
    *DAT_1c0dedec = 0xc;
    *DAT_1c0dedf0 = 0xb;
    *DAT_1c0dedf4 = 0;
    *DAT_1c0dedf8 = 0;
    *DAT_1c0dedfc = 0;
    *DAT_1c0dee00 = 0x55;
    thunk_EXT_FUN_0e0806c4();
    thunk_EXT_FUN_0e08078c();
    if (*pcVar6 == '\0') {
      thunk_EXT_FUN_0e080570(10,3);
    }
    *pcVar3 = '\0';
    *pcVar6 = '\0';
  }
  return;
}


