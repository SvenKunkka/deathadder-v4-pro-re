/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e074efc. Types and names are inferred; NOT original source. */

void FUN_0e074efc(void)

{
  byte bVar1;
  byte bVar2;
  sbyte sVar3;
  char cVar4;
  ushort uVar5;
  byte *pbVar6;
  byte *pbVar7;
  char *pcVar8;
  ushort *puVar9;
  int iVar10;
  byte bVar11;
  undefined4 *puVar12;
  uint *puVar13;
  uint local_14;
  
  pbVar7 = DAT_0e075020;
  pbVar6 = DAT_0e07501c;
  bVar1 = *DAT_0e07501c;
  bVar2 = *DAT_0e075024;
  bVar11 = *DAT_0e075020 + 1;
  *DAT_0e075020 = bVar11;
  *pbVar6 = bVar1 + 1;
  pcVar8 = DAT_0e075028;
  if ((byte)(bVar1 + 1) < bVar2) {
LAB_0e074f62:
    if (bVar11 < *DAT_0e075038) goto LAB_0e074f6a;
  }
  else {
    *pbVar6 = 0;
    if (*pcVar8 != '\0') {
      puVar12 = (undefined4 *)*DAT_0e075064;
      puVar12[3] = 1;
      *puVar12 = 1;
    }
    iVar10 = *(int *)(DAT_0e07502c + 0xc);
    sVar3 = *(sbyte *)(DAT_0e07502c + 0x10);
    puVar13 = *(uint **)(iVar10 + 0x10);
    iVar10 = (**(code **)(*(int *)(iVar10 + 8) + 4))(iVar10,&local_14);
    pcVar8 = DAT_0e075030;
    if ((iVar10 == 0) && (((local_14 ^ *puVar13) & 1 << sVar3) == 0)) {
      *DAT_0e075030 = '\x02';
LAB_0e074f50:
      thunk_FUN_0e095414(DAT_0e075034);
      cVar4 = *pcVar8;
      *pbVar7 = 0;
      *pcVar8 = cVar4 + -1;
      bVar11 = 0;
      goto LAB_0e074f62;
    }
    if (*DAT_0e075030 != '\0') goto LAB_0e074f50;
    if (*pbVar7 < *DAT_0e075038) goto LAB_0e074f6a;
  }
  thunk_FUN_0e095414(DAT_0e075034);
  *pbVar7 = 0;
LAB_0e074f6a:
  pbVar6 = DAT_0e07503c;
  bVar1 = *DAT_0e07503c;
  bVar2 = *DAT_0e075040;
  *DAT_0e07503c = bVar1 + 1;
  puVar9 = DAT_0e075048;
  pcVar8 = DAT_0e075044;
  if ((bVar2 <= (byte)(bVar1 + 1)) &&
     ((cVar4 = *DAT_0e075044, *pbVar6 = 0, cVar4 != '\0' ||
      (uVar5 = *puVar9, *puVar9 = uVar5 + 1, 7 < (ushort)(uVar5 + 1))))) {
    FUN_0e075b80(DAT_0e07504c,0x29);
    if (*DAT_0e075050 != '\0') {
      puVar12 = (undefined4 *)*DAT_0e075068;
      puVar12[3] = 1;
      *puVar12 = 1;
    }
    cVar4 = *pcVar8;
    *puVar9 = 0;
    puVar9 = DAT_0e075054;
    if ((cVar4 != '\0') &&
       (uVar5 = *DAT_0e075054, *DAT_0e075054 = uVar5 + 1, 1999 < (ushort)(uVar5 + 1))) {
      *pcVar8 = '\0';
      *puVar9 = 0;
    }
  }
  pbVar6 = DAT_0e075058;
  bVar1 = *DAT_0e075058;
  bVar2 = *DAT_0e07505c;
  *DAT_0e075058 = bVar1 + 1;
  if (bVar2 <= (byte)(bVar1 + 1)) {
    *pbVar6 = 0;
                    /* WARNING: Could not recover jumptable at 0x0e078e74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_0e078e78)(DAT_0e075060);
    return;
  }
  return;
}


