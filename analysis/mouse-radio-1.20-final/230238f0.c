/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230238f0. Types and names are inferred; NOT original source. */

void FUN_230238f0(int param_1,int param_2)

{
  int iVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  char cVar5;
  
  if ((param_2 != 0) && (DAT_23002a25 == '\0')) {
    return;
  }
  if (DAT_23002794 == 3) {
    uVar4 = (uint)DAT_230029ac;
    if (uVar4 < 9) {
      uVar4 = -0x117 >> (uVar4 & 0xff);
    }
    else {
      if (uVar4 != 0x10) {
        if (uVar4 == 0x20) {
          uVar3 = DAT_23002a0a & 3;
        }
        else {
          if (uVar4 != 0x40) {
            DAT_23002a25 = 0;
            return;
          }
          uVar3 = DAT_23002a0a & 7;
        }
        if (uVar3 != 0) {
          DAT_23002a25 = 0;
          return;
        }
        goto LAB_23023926;
      }
      uVar4 = (uint)DAT_23002a0a;
    }
    if ((int)(uVar4 << 0x1f) < 0) {
      DAT_23002a25 = 0;
      return;
    }
  }
  else {
    if (DAT_23002794 != 4) {
      DAT_23002a25 = 0;
      return;
    }
    if (param_1 != 1) {
      DAT_23002a25 = 0;
      return;
    }
  }
LAB_23023926:
  uVar4 = (uint)DAT_23002836;
  iVar1 = (uVar4 + 0x4c) * 2;
  sVar2 = *(short *)(&DAT_2300297c + iVar1);
  *(ushort *)(&DAT_2300297c + iVar1) = sVar2 + 1U;
  if (3 < (ushort)(sVar2 + 1U)) {
    cVar5 = (&DAT_230029d5)[uVar4] + '\x01';
    if (DAT_230029df == cVar5) {
      cVar5 = '\0';
    }
    (&DAT_230029d5)[uVar4] = cVar5;
    *(undefined2 *)(&DAT_2300297c + iVar1) = 0;
  }
  DAT_23002a25 = 0;
  return;
}


