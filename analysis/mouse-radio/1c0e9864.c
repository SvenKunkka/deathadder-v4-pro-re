/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e9864. Types and names are inferred; NOT original source. */

void FUN_1c0e9864(int param_1)

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
  
  psVar5 = DAT_1c0e9908;
  pcVar4 = DAT_1c0e9900;
  pbVar3 = DAT_1c0e98ec;
  if (param_1 == 0) {
    bVar1 = *DAT_1c0e98ec;
    *DAT_1c0e98f0 = 0;
    while (bVar1 != 0) {
      FUN_1c0e971c();
      bVar1 = *pbVar3;
    }
    goto LAB_1c0e987c;
  }
  if (*DAT_1c0e98f8 < 6) {
    if (*DAT_1c0e9904 != '\0') {
      cVar2 = *DAT_1c0e9900;
      goto joined_r0x1c0e98ba;
    }
  }
  else {
    if ((0x3c < *DAT_1c0e98fc) && (*DAT_1c0e9908 == 0)) {
      FUN_1c0e971c();
      *psVar5 = 0x3c;
      goto LAB_1c0e987c;
    }
    cVar2 = *DAT_1c0e9900;
joined_r0x1c0e98ba:
    if (cVar2 != '\0') {
      FUN_1c0e971c();
      if (*DAT_1c0e98ec == 0) {
        *pcVar4 = '\0';
      }
      goto LAB_1c0e987c;
    }
    if (-1 < (int)((uint)*DAT_1c0e98ec << 0x1e)) goto LAB_1c0e987c;
  }
  FUN_1c0e971c();
LAB_1c0e987c:
  uVar8 = (uint)*DAT_1c0e98f4;
  if ((uVar8 != 0) && ((int)(uVar8 << 0x1f) < 0)) {
    *DAT_1c0e98f4 = (byte)(uVar8 & 0xfffffffe);
    puVar7 = DAT_1c0ec664;
    uVar6 = DAT_1c0ec660;
    FUN_1c100d84(DAT_1c0ec660,uVar8 << 0x1f,0x9d,0,uVar8 & 0xfffffffe,unaff_r4);
    FUN_1c1037f8(0x48,(char)*puVar7);
    FUN_1c1037f8(0x49,*puVar7 >> 8);
    FUN_1c1037f8(0x4a,(char)puVar7[1]);
    FUN_1c1037f8(0x4b,puVar7[1] >> 8);
    FUN_1c1037f8(0x47,1);
    FUN_1c100e80(uVar6);
    return;
  }
  return;
}


