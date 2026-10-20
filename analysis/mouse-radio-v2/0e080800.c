/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e080800. Types and names are inferred; NOT original source. */

void FUN_0e080800(void)

{
  undefined1 uVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  iVar4 = DAT_0e080854;
  uVar1 = *(undefined1 *)(DAT_0e080854 + 0x2d);
  *DAT_0e080858 = *(undefined1 *)(DAT_0e080854 + 0x2c);
  puVar5 = DAT_0e080860;
  *DAT_0e08085c = uVar1;
  puVar6 = DAT_0e080864;
  *puVar5 = *(undefined1 *)(iVar4 + 0x2e);
  cVar2 = *(char *)(iVar4 + 0x2b);
  *puVar6 = *(undefined1 *)(iVar4 + 0x2f);
  puVar6 = DAT_0e080870;
  puVar5 = DAT_0e08086c;
  uVar1 = *(undefined1 *)(iVar4 + 0x30);
  uVar3 = *(undefined1 *)(iVar4 + 0x31);
  *DAT_0e080868 = cVar2;
  *puVar5 = uVar1;
  *puVar6 = uVar3;
  if (cVar2 != '\x04') {
    FUN_0e0806c4();
    return;
  }
  FUN_0e080724();
  return;
}


