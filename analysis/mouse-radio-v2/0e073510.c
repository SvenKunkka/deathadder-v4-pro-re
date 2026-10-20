/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e073510. Types and names are inferred; NOT original source. */

void FUN_0e073510(void)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  
  puVar4 = DAT_0e0735dc;
  puVar6 = DAT_0e0735d8;
  cVar1 = *DAT_0e0735c8;
  if (cVar1 == '\x04') {
    if (*DAT_0e0735e0 == '\0') {
      *DAT_0e0735d0 = *DAT_0e0735cc;
      puVar4 = DAT_0e0735dc;
      *DAT_0e0735d4 = '\x01';
      *puVar6 = 10;
      *puVar4 = 1;
      return;
    }
    uVar5 = 0x50;
    uVar7 = 8;
    *DAT_0e0735d0 = DAT_0e0735cc[1];
    puVar6 = DAT_0e0735d8;
LAB_0e073560:
    pcVar3 = DAT_0e0735d4;
    *puVar6 = uVar5;
    *pcVar3 = cVar1;
    *DAT_0e0735dc = uVar7;
    return;
  }
  if (cVar1 == '\x01') {
    bVar2 = DAT_0e0735cc[3];
    if (bVar2 == 1) {
      *DAT_0e0735d0 = 1;
      puVar6 = DAT_0e0735d8;
      pcVar3 = DAT_0e0735d4;
      *puVar4 = 8;
      *puVar6 = 0x50;
      *pcVar3 = '\x04';
    }
    else if (bVar2 == 2) {
      *DAT_0e0735d0 = 1;
      puVar6 = DAT_0e0735d8;
      *DAT_0e0735d4 = '\x02';
      puVar4 = DAT_0e0735dc;
      *puVar6 = 0x28;
      *puVar4 = 4;
    }
    else {
      uVar5 = 0x14;
      if (bVar2 == 4) {
        uVar7 = 2;
        *DAT_0e0735d0 = 1;
        goto LAB_0e073560;
      }
      *DAT_0e0735d0 = bVar2 >> 2;
      puVar6 = DAT_0e0735d8;
      *DAT_0e0735d4 = '\x01';
      puVar4 = DAT_0e0735dc;
      *puVar6 = 0x14;
      *puVar4 = 2;
    }
  }
  return;
}


