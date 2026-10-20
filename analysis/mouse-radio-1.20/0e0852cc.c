/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0852cc. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0852cc(undefined1 *param_1,ushort *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  switch(*param_1) {
  case 1:
    if (param_1[1] == '\0') {
      *(undefined1 *)param_2 = 0;
      iVar1 = FUN_0e085240(param_1[1],param_1[0x5e]);
      if (iVar1 == 0) {
        return 0;
      }
    }
    else {
      iVar1 = FUN_0e085240(param_1[1],param_1[0x5e]);
      if (iVar1 == 0) {
        return 0;
      }
      if (param_2 == (ushort *)0x0) {
        return 1;
      }
    }
    if (param_1[0x5e] == '\x01') {
      *(undefined1 *)param_2 = (undefined1)DAT_23006c98;
    }
    else if (param_1[0x5e] == '\x02') {
      *param_2 = DAT_23006c98 << 8 | DAT_23006c98 >> 8;
    }
    break;
  case 2:
    uVar2 = FUN_0e0851d4(param_1[1],param_1 + 4,param_1[0x5e],param_4);
    return uVar2;
  case 3:
    iVar1 = FUN_0e085240(param_1[1],param_1[0x5e]);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = FUN_0e0973fa(&DAT_23006c98,param_1 + 4,param_1[0x5e]);
    if ((iVar1 == 0) && (param_1[1] == '\x10')) {
      DAT_23006c2a = 0xc;
    }
    break;
  case 4:
    DAT_23006c1c = (uint)*(ushort *)(param_1 + 0x5c);
    break;
  default:
    return 0;
  }
  return 1;
}


