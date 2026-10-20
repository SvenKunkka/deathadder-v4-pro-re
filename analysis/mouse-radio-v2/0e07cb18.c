/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07cb18. Types and names are inferred; NOT original source. */

void FUN_0e07cb18(void)

{
  undefined1 *puVar1;
  char cVar2;
  byte bVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  iVar5 = DAT_0e07cb68;
  puVar4 = DAT_0e07cb64;
  cVar2 = DAT_0e07cb64[7];
  if (cVar2 == -0x7f) {
    uVar6 = 1;
    uVar7 = 0;
    puVar1 = DAT_0e07cb64 + 8;
    *puVar1 = 1;
    bVar3 = *(byte *)(iVar5 + 4);
    do {
      if (((int)(uint)bVar3 >> (uVar7 & 0xff)) << 0x1f < 0) {
        puVar1[uVar6] = (char)uVar7;
        uVar6 = uVar6 + 1 & 0xff;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 != 8);
    puVar4[5] = (char)uVar6;
    return;
  }
  if ((cVar2 != -0x76) && (cVar2 != -0x80)) {
    *DAT_0e07cb64 = 3;
    return;
  }
  DAT_0e07cb64[8] = 1;
  return;
}


