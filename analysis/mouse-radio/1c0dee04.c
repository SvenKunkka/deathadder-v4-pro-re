/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0dee04. Types and names are inferred; NOT original source. */

void FUN_1c0dee04(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  byte *pbVar4;
  char *pcVar5;
  int iVar6;
  byte bVar7;
  uint *puVar8;
  uint local_14;
  
  if ((*DAT_1c0def28 == '\0') && ((*DAT_1c0def2c == '\0' || (*DAT_1c0def30 == '\0')))) {
    return;
  }
  iVar6 = *DAT_1c0def34;
  iVar2 = DAT_1c0def34[1];
  puVar8 = *(uint **)(iVar6 + 0x10);
  iVar6 = (**(code **)(*(int *)(iVar6 + 8) + 4))(iVar6,&local_14);
  pbVar4 = DAT_1c0def3c;
  pcVar3 = DAT_1c0def38;
  if ((iVar6 == 0) && (((local_14 ^ *puVar8) & 1 << (sbyte)iVar2) == 0)) {
    if ((*DAT_1c0def38 == '\0') &&
       (bVar7 = *DAT_1c0def3c, *DAT_1c0def3c = bVar7 + 1, 0x1d < (byte)(bVar7 + 1))) {
      *pcVar3 = '\x01';
    }
  }
  else {
    *DAT_1c0def38 = '\0';
    *pbVar4 = 0;
  }
  iVar6 = *DAT_1c0def40;
  iVar2 = DAT_1c0def40[1];
  puVar8 = *(uint **)(iVar6 + 0x10);
  iVar6 = (**(code **)(*(int *)(iVar6 + 8) + 4))(iVar6,&local_14);
  pbVar4 = DAT_1c0def48;
  pcVar5 = DAT_1c0def44;
  if ((iVar6 == 0) && (((local_14 ^ *puVar8) & 1 << (sbyte)iVar2) == 0)) {
    if (((*DAT_1c0def44 == '\0') &&
        (bVar7 = *DAT_1c0def48, *DAT_1c0def48 = bVar7 + 1, 0x1d < (byte)(bVar7 + 1))) &&
       (cVar1 = *pcVar3, *pcVar5 = '\x01', iVar2 = DAT_1c0def50, pcVar3 = DAT_1c0def4c,
       cVar1 != '\0')) {
      if (*DAT_1c0def4c == '\x04') {
        bVar7 = *(byte *)(DAT_1c0def50 + 1);
      }
      else {
        bVar7 = *(byte *)(DAT_1c0def50 + 3);
      }
      if (bVar7 == 1) {
        bVar7 = 0x40;
      }
      else if (bVar7 == 0x40) {
        bVar7 = 0x10;
      }
      else {
        bVar7 = bVar7 >> 1;
      }
      FUN_1c0df620(*DAT_1c0def4c,bVar7);
      if (*pcVar3 == '\x01') {
        FUN_1c0d9a74(*(undefined1 *)(iVar2 + 3));
        *(undefined1 *)((uint)*(byte *)(DAT_1c0def54 + 3) * 0xf4 + DAT_1c0def54 + 0x5d) =
             *(undefined1 *)(iVar2 + 3);
      }
      else {
        *(undefined1 *)((uint)*(byte *)(DAT_1c0def54 + 3) * 0xf4 + DAT_1c0def54 + 0x5b) =
             *(undefined1 *)(iVar2 + 1);
      }
      thunk_EXT_FUN_0e07d638(8,0);
      if (*DAT_1c0def58 == '\x03') {
        thunk_EXT_FUN_0e080570(0x58,bVar7);
        return;
      }
    }
  }
  else {
    *DAT_1c0def44 = '\0';
    *pbVar4 = 0;
  }
  return;
}


