/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e072e04. Types and names are inferred; NOT original source. */

void FUN_0e072e04(void)

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
  
  if ((*DAT_0e072f28 == '\0') && ((*DAT_0e072f2c == '\0' || (*DAT_0e072f30 == '\0')))) {
    return;
  }
  iVar6 = *DAT_0e072f34;
  iVar2 = DAT_0e072f34[1];
  puVar8 = *(uint **)(iVar6 + 0x10);
  iVar6 = (**(code **)(*(int *)(iVar6 + 8) + 4))(iVar6,&local_14);
  pbVar4 = DAT_0e072f3c;
  pcVar3 = DAT_0e072f38;
  if ((iVar6 == 0) && (((local_14 ^ *puVar8) & 1 << (sbyte)iVar2) == 0)) {
    if ((*DAT_0e072f38 == '\0') &&
       (bVar7 = *DAT_0e072f3c, *DAT_0e072f3c = bVar7 + 1, 0x1d < (byte)(bVar7 + 1))) {
      *pcVar3 = '\x01';
    }
  }
  else {
    *DAT_0e072f38 = '\0';
    *pbVar4 = 0;
  }
  iVar6 = *DAT_0e072f40;
  iVar2 = DAT_0e072f40[1];
  puVar8 = *(uint **)(iVar6 + 0x10);
  iVar6 = (**(code **)(*(int *)(iVar6 + 8) + 4))(iVar6,&local_14);
  pbVar4 = DAT_0e072f48;
  pcVar5 = DAT_0e072f44;
  if ((iVar6 == 0) && (((local_14 ^ *puVar8) & 1 << (sbyte)iVar2) == 0)) {
    if (((*DAT_0e072f44 == '\0') &&
        (bVar7 = *DAT_0e072f48, *DAT_0e072f48 = bVar7 + 1, 0x1d < (byte)(bVar7 + 1))) &&
       (cVar1 = *pcVar3, *pcVar5 = '\x01', iVar2 = DAT_0e072f50, pcVar3 = DAT_0e072f4c,
       cVar1 != '\0')) {
      if (*DAT_0e072f4c == '\x04') {
        bVar7 = *(byte *)(DAT_0e072f50 + 1);
      }
      else {
        bVar7 = *(byte *)(DAT_0e072f50 + 3);
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
      FUN_0e073620(*DAT_0e072f4c,bVar7);
      if (*pcVar3 == '\x01') {
        FUN_0e06da74(*(undefined1 *)(iVar2 + 3));
        *(undefined1 *)((uint)*(byte *)(DAT_0e072f54 + 3) * 0xf4 + DAT_0e072f54 + 0x5d) =
             *(undefined1 *)(iVar2 + 3);
      }
      else {
        *(undefined1 *)((uint)*(byte *)(DAT_0e072f54 + 3) * 0xf4 + DAT_0e072f54 + 0x5b) =
             *(undefined1 *)(iVar2 + 1);
      }
      thunk_FUN_0e07d638(8,0);
      if (*DAT_0e072f58 == '\x03') {
        thunk_FUN_0e080570(0x58,bVar7);
        return;
      }
    }
  }
  else {
    *DAT_0e072f44 = '\0';
    *pbVar4 = 0;
  }
  return;
}


