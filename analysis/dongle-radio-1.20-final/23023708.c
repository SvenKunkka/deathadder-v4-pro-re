/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23023708. Types and names are inferred; NOT original source. */

void FUN_23023708(int param_1)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  ushort uVar4;
  
  if ((param_1 != 0) && (DAT_2300348a == '\0')) {
    return;
  }
  if (DAT_230033e8 == 3) {
    uVar1 = (uint)DAT_2300341c;
    if (uVar1 < 9) {
      uVar1 = -0x117 >> (uVar1 & 0xff);
    }
    else {
      if (uVar1 != 0x10) {
        if (uVar1 == 0x20) {
          uVar4 = DAT_2300346e & 3;
        }
        else {
          if (uVar1 != 0x40) {
            DAT_2300348a = 0;
            return;
          }
          uVar4 = DAT_2300346e & 7;
        }
        goto joined_r0x230237c0;
      }
      uVar1 = (uint)DAT_2300346e;
    }
    if (-1 < (int)(uVar1 << 0x1f)) goto LAB_23023748;
  }
  else {
    if (DAT_230033e8 != 4) {
      DAT_2300348a = 0;
      return;
    }
    uVar4 = DAT_23005376 & 0x1d;
joined_r0x230237c0:
    if (uVar4 == 0) {
LAB_23023748:
      uVar1 = (uint)DAT_230032ca;
      iVar2 = uVar1 + 0x48;
      uVar4 = *(short *)((int)&DAT_230033e8 + iVar2 * 2) + 1;
      *(ushort *)((int)&DAT_230033e8 + iVar2 * 2) = uVar4;
      if (3 < uVar4) {
        if (DAT_23005384 == '\0') {
          cVar3 = (&DAT_23005349)[uVar1] + '\x01';
          if (DAT_23005353 == cVar3) {
            cVar3 = '\0';
          }
          (&DAT_23005349)[uVar1] = cVar3;
          iVar2 = DAT_230032ca + 0x48;
        }
        *(undefined2 *)((int)&DAT_230033e8 + iVar2 * 2) = 0;
        DAT_2300348a = 0;
        return;
      }
      DAT_2300348a = 0;
      return;
    }
  }
  DAT_2300348a = 0;
  return;
}


