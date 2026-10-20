/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0765bc. Types and names are inferred; NOT original source. */

uint FUN_0e0765bc(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = *param_1;
  uVar4 = *(uint *)(iVar2 + 0x510);
  if ((iVar2 == DAT_0e076620) || (iVar2 == DAT_0e076620 + 0x1000)) {
    uVar3 = 0x140;
  }
  else if ((iVar2 == DAT_0e076624) || (iVar2 == DAT_0e076624 + 0x1000)) {
    uVar3 = 0x20;
  }
  else if (iVar2 == DAT_0e076624 + 0x2000) {
    uVar3 = 0x20;
  }
  else {
    uVar3 = 0x10;
  }
  uVar1 = (uint)((ulonglong)param_2 * (ulonglong)uVar3 >> 0x20);
  return uVar1 >> (uVar4 - 0x20 & 0xff) |
         (uint)((ulonglong)param_2 * (ulonglong)uVar3) >> (uVar4 & 0xff) |
         uVar1 << (0x20 - uVar4 & 0xff);
}


