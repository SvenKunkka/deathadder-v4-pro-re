/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07d864. Types and names are inferred; NOT original source. */

void FUN_0e07d864(int param_1)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  char *pcVar4;
  short *psVar5;
  undefined4 uVar6;
  ushort *puVar7;
  uint uVar8;
  undefined4 unaff_r4;
  
  psVar5 = DAT_0e07d908;
  pcVar4 = DAT_0e07d900;
  pbVar3 = DAT_0e07d8ec;
  if (param_1 == 0) {
    bVar1 = *DAT_0e07d8ec;
    *DAT_0e07d8f0 = 0;
    while (bVar1 != 0) {
      FUN_0e07d71c();
      bVar1 = *pbVar3;
    }
    goto LAB_0e07d87c;
  }
  if (*DAT_0e07d8f8 < 6) {
    if (*DAT_0e07d904 != '\0') {
      cVar2 = *DAT_0e07d900;
      goto joined_r0x0e07d8ba;
    }
  }
  else {
    if ((0x3c < *DAT_0e07d8fc) && (*DAT_0e07d908 == 0)) {
      FUN_0e07d71c();
      *psVar5 = 0x3c;
      goto LAB_0e07d87c;
    }
    cVar2 = *DAT_0e07d900;
joined_r0x0e07d8ba:
    if (cVar2 != '\0') {
      FUN_0e07d71c();
      if (*DAT_0e07d8ec == 0) {
        *pcVar4 = '\0';
      }
      goto LAB_0e07d87c;
    }
    if (-1 < (int)((uint)*DAT_0e07d8ec << 0x1e)) goto LAB_0e07d87c;
  }
  FUN_0e07d71c();
LAB_0e07d87c:
  uVar8 = (uint)*DAT_0e07d8f4;
  if ((uVar8 != 0) && ((int)(uVar8 << 0x1f) < 0)) {
    *DAT_0e07d8f4 = (byte)(uVar8 & 0xfffffffe);
    puVar7 = DAT_0e080664;
    uVar6 = DAT_0e080660;
    FUN_0e094d84(DAT_0e080660,uVar8 << 0x1f,0x9d,0,uVar8 & 0xfffffffe,unaff_r4);
    FUN_0e0977f8(0x48,(char)*puVar7);
    FUN_0e0977f8(0x49,*puVar7 >> 8);
    FUN_0e0977f8(0x4a,(char)puVar7[1]);
    FUN_0e0977f8(0x4b,puVar7[1] >> 8);
    FUN_0e0977f8(0x47,1);
    FUN_0e094e80(uVar6);
    return;
  }
  return;
}


