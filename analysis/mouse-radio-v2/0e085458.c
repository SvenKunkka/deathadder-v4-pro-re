/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e085458. Types and names are inferred; NOT original source. */

undefined4 FUN_0e085458(undefined1 *param_1,ushort *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  switch(*param_1) {
  case 1:
    if (param_1[1] == '\0') {
      *(undefined1 *)param_2 = 0;
      iVar1 = FUN_0e0853cc(param_1[1],param_1[0x5e]);
      if (iVar1 == 0) {
        return 0;
      }
    }
    else {
      iVar1 = FUN_0e0853cc(param_1[1],param_1[0x5e]);
      if (iVar1 == 0) {
        return 0;
      }
      if (param_2 == (ushort *)0x0) {
        return 1;
      }
    }
    if (param_1[0x5e] == '\x01') {
      *(undefined1 *)param_2 = *(undefined1 *)(DAT_0e085500 + 0x80);
    }
    else if (param_1[0x5e] == '\x02') {
      *param_2 = *(ushort *)(DAT_0e085500 + 0x80) << 8 | *(ushort *)(DAT_0e085500 + 0x80) >> 8;
    }
    break;
  case 2:
    uVar2 = FUN_0e085360(param_1[1],param_1 + 4,param_1[0x5e],param_4);
    return uVar2;
  case 3:
    iVar1 = FUN_0e0853cc(param_1[1],param_1[0x5e]);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = FUN_0e097522(DAT_0e085504,param_1 + 4,param_1[0x5e]);
    if ((iVar1 == 0) && (param_1[1] == '\x10')) {
      *(undefined1 *)(DAT_0e085500 + 0x12) = 0xc;
    }
    break;
  case 4:
    *(uint *)(DAT_0e085500 + 4) = (uint)*(ushort *)(param_1 + 0x5c);
    break;
  default:
    return 0;
  }
  return 1;
}


