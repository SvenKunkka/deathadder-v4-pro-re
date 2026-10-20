/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0804b4. Types and names are inferred; NOT original source. */

void FUN_0e0804b4(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  undefined4 uVar10;
  
  iVar7 = DAT_0e080544;
  iVar3 = DAT_0e080540;
  bVar2 = *(byte *)(DAT_0e080540 + 6);
  bVar9 = *(byte *)(DAT_0e080544 + 3);
  *DAT_0e08053c = *DAT_0e08053c | 1;
  puVar4 = DAT_0e08054c;
  uVar10 = *(undefined4 *)(iVar3 + 7 + (uint)bVar2 * 6);
  *DAT_0e080548 = uVar10;
  *DAT_0e080550 = uVar10;
  iVar7 = iVar7 + (uint)bVar9 * 0xf4;
  *(byte *)(iVar7 + 0x60) = bVar2;
  *(undefined4 *)(iVar7 + 0x56) = uVar10;
  FUN_0e07d638(8);
  pbVar5 = DAT_0e080554;
  uVar8 = (uint)*DAT_0e080554;
  *puVar4 = 0;
  bVar9 = (byte)(uVar8 + 1);
  if (7 < (uVar8 + 1 & 0xff)) {
    bVar9 = 0;
  }
  *pbVar5 = bVar9;
  *DAT_0e080558 = *DAT_0e080558 | 0x80;
  pcVar6 = DAT_0e080560;
  *DAT_0e08055c = 2;
  cVar1 = *pcVar6;
  *(undefined1 *)(DAT_0e080564 + uVar8) = 2;
  *(undefined1 *)(DAT_0e080568 + uVar8) = 0;
  if ((cVar1 == '\x01') && (*DAT_0e08056c != '\0')) {
                    /* WARNING: Could not recover jumptable at 0x0e097700. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_0e097704)();
    return;
  }
  return;
}


