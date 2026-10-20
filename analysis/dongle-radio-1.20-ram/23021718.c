/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021718. Types and names are inferred; NOT original source. */

void FUN_23021718(void)

{
  byte bVar1;
  dword dVar2;
  dword dVar3;
  int iVar4;
  undefined1 uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  undefined1 *puVar10;
  
  DAT_230030d9 = DAT_230030de;
  DAT_230030dd = DAT_230030e2;
  if ((1 < DAT_2300323e) && (DAT_2300323e - 2 < 2)) {
    iVar4 = 0;
    uVar7 = 0;
    pbVar9 = (byte *)0x230030d8;
    do {
      bVar6 = 1;
      pbVar9 = pbVar9 + 1;
      bVar1 = *pbVar9;
      puVar10 = (undefined1 *)(uVar7 + 0x23003131);
      uVar8 = uVar7 + 8;
      do {
        uVar5 = (undefined1)uVar7;
        if ((bVar1 & bVar6) == 0) {
          uVar5 = 0xff;
        }
        else {
          (&DAT_230030e8)[iVar4] = (char)iVar4;
          (&DAT_2300310d)[iVar4] = uVar5;
          iVar4 = iVar4 + 1;
        }
        uVar7 = uVar7 + 1;
        puVar10 = puVar10 + 1;
        *puVar10 = uVar5;
        bVar6 = bVar6 << 1;
      } while ((uVar7 < 0x25) && (uVar8 != uVar7));
    } while (pbVar9 != &DAT_230030dd);
    DAT_23003157 = (char)iVar4;
    dVar2 = RADIO_S_BASE1;
    dVar3 = RADIO_S_BASE1;
    DAT_230030e6 = (ushort)dVar3 ^ (ushort)(dVar2 >> 0x10);
    return;
  }
  return;
}


