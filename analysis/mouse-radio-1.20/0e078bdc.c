/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078bdc. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0e085008(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  undefined4 in_r3;
  code *pcVar6;
  
  cVar1 = DAT_23006beb;
  if ((&DAT_230049e0)[(uint)DAT_2300065d * 0xe] == '\0') {
    return;
  }
  if (9 < DAT_23006be2) {
    if ((1 << DAT_2300066c & **(uint **)(DAT_23000668 + 0x10)) == 0) {
      pcVar6 = *(code **)(*(int *)(DAT_23000668 + 8) + 0xc);
    }
    else {
      pcVar6 = *(code **)(*(int *)(DAT_23000668 + 8) + 0x10);
    }
    (*pcVar6)();
    FUN_0e0973ea(&DAT_23006bdc,0,0x34);
    _DAT_23006bde = CONCAT22(DAT_23006be0,1);
    DAT_23006be8 = 0x50;
    DAT_23000577 = 0;
    return;
  }
  if (DAT_23006beb == '\0') goto LAB_0e08502a;
  if (DAT_230077a2 == '\0') {
    DAT_23006be4 = 0;
    if (DAT_23006bea == '\0') goto LAB_0e0850a2;
    DAT_23006bea = DAT_230077a2;
    DAT_23006be8 = 0x50;
    DAT_23006bec = '\x01';
    if (DAT_23006bed != '\0') goto LAB_0e08502a;
  }
  else {
    if (DAT_23006be4 == 1000) {
      if ((1 << (uint)DAT_2300066c & **(uint **)(DAT_23000668 + 0x10)) == 0) {
        pcVar6 = *(code **)(*(int *)(DAT_23000668 + 8) + 0x10);
      }
      else {
        pcVar6 = *(code **)(*(int *)(DAT_23000668 + 8) + 0xc);
      }
      (*pcVar6)();
      DAT_23006bee = 1;
LAB_0e085098:
      if (2000 < DAT_23006be4) goto LAB_0e0850a2;
    }
    else {
      if (DAT_23006be4 != 2000) goto LAB_0e085098;
      if (DAT_23006bea == '\0') {
        DAT_23006bec = '\x01';
        DAT_23006be8 = 400;
        DAT_23006bea = '\x01';
      }
    }
    DAT_23006be4 = DAT_23006be4 + 1;
LAB_0e0850a2:
    if ((DAT_23006bed != '\0') || (DAT_23006bed = DAT_23006bec, DAT_23006bec == '\0'))
    goto LAB_0e08502a;
  }
  if (DAT_2300056c == 0x602) {
    DAT_23000577 = 1;
    DAT_23000570 = DAT_23006be8;
  }
  DAT_23006bec = '\0';
  DAT_23006bed = cVar1;
LAB_0e08502a:
  uVar4 = _DAT_23006bde & 0xffff;
  uVar5 = DAT_23006be0 + 1;
  _DAT_23006bde = CONCAT22(uVar5,DAT_23006bde);
  if (uVar4 <= uVar5) {
    _DAT_23006bde = 1;
    if ((byte)DAT_23006bdc == '\0') {
      iVar2 = (uint)DAT_23006bdc._1_1_ * 0xc;
      iVar2 = FUN_0e084bc0(iVar2 + 0x23000578,*(undefined4 *)(&DAT_2300057c + iVar2),uVar4,
                           (uint)DAT_23006bdc._1_1_ * 3,in_r3);
      if (iVar2 != 0) {
        if ((byte)(DAT_23006bdc._1_1_ + 1) < 0x13) {
          DAT_23006bdc = CONCAT11(DAT_23006bdc._1_1_ + 1,(byte)DAT_23006bdc);
        }
        else {
          DAT_23006beb = '\x01';
          DAT_23006bdc = 2;
        }
        return;
      }
    }
    else if ((byte)DAT_23006bdc == '\x02') {
      if (DAT_23006bed != '\0') {
        uVar4 = (uint)DAT_23006bdc._1_1_;
        iVar2 = uVar4 * 0xc;
        if ((&DAT_23000577)[iVar2] != '\0') {
          iVar3 = FUN_0e084bc0(&DAT_2300056c + uVar4 * 6,*(undefined4 *)(&DAT_23000570 + uVar4 * 6),
                               (&DAT_23000577)[iVar2],uVar4,in_r3);
          if (iVar3 == 0) {
            return;
          }
          uVar4 = (uint)DAT_23006bdc._1_1_;
        }
        (&DAT_23000577)[iVar2] = 0;
        DAT_23006bdc = (ushort)(byte)DAT_23006bdc;
        if (uVar4 != 0xff) {
          DAT_23006bed = '\0';
        }
        return;
      }
    }
    else {
      DAT_23006bdc = 0;
    }
  }
  return;
}


