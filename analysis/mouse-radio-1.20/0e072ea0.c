/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e072ea0. Types and names are inferred; NOT original source. */

void FUN_0e072ea0(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar4 = (uint)DAT_230076d0;
  do {
    iVar1 = uVar3 * 5;
    uVar2 = (int)uVar4 >> (uVar3 & 0xff) & 1;
    if ((((&DAT_23006638)[iVar1] & 2) == 0) || ((&DAT_2300663a)[iVar1] == '\0')) {
      iVar1 = uVar3 * 5;
      if (uVar2 == 0) {
        if (((&DAT_23006639)[iVar1] != '\x01') &&
           ((int)((uint)(byte)(&DAT_23006638)[iVar1] << 0x1f) < 0)) goto LAB_0e072ebc;
      }
      else if (((&DAT_23006639)[iVar1] != '\0') &&
              (-1 < (int)((uint)(byte)(&DAT_23006638)[iVar1] << 0x1f))) {
LAB_0e072ebc:
        (&DAT_2300663a)[iVar1] = (&DAT_2300663a)[iVar1] + '\x01';
      }
    }
    else if ((byte)(&DAT_23006639)[iVar1] == uVar2) {
      (&DAT_2300663b)[iVar1] = (&DAT_2300663b)[iVar1] + '\x01';
    }
    else {
      (&DAT_2300663a)[iVar1] = (&DAT_2300663a)[iVar1] + -1;
    }
    uVar3 = uVar3 + 1;
    if (uVar3 == 6) {
      return;
    }
  } while( true );
}


