/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23022360. Types and names are inferred; NOT original source. */

void FUN_23022360(uint param_1)

{
  byte bVar1;
  uint uVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  
  iVar5 = param_1 * 0xf84;
  (&DAT_230034bc)[iVar5] = 0xb;
  uVar3 = FUN_23020978(0,param_1 & 0xff);
  (&DAT_230034bd)[iVar5] = uVar3;
  uVar3 = FUN_230209dc(0,(&DAT_2300348f)[iVar5]);
  (&DAT_230034be)[iVar5] = uVar3;
  uVar2 = DAT_23003244;
  (&DAT_230034bf)[iVar5] = 0x11;
  *(uint *)(&DAT_230034c0 + iVar5) =
       uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18;
  bVar1 = (byte)DAT_23003238;
  (&DAT_230034c5)[iVar5] = 0;
  (&DAT_230034c4)[iVar5] =
       bVar1 & 0xf | (&DAT_2300346d)[iVar5] << 7 |
       (byte)(*(short *)(&DAT_23003402 + iVar5) << 6) & 0x40;
  (&DAT_230034c6)[iVar5] = (char)((ushort)DAT_23005376 >> 8);
  (&DAT_230034c7)[iVar5] = (char)DAT_23005376;
  cVar4 = (&DAT_2300348f)[iVar5] + '\x01';
  if (cVar4 == '\b') {
    cVar4 = '\x01';
  }
  (&DAT_2300348f)[iVar5] = cVar4;
  return;
}


