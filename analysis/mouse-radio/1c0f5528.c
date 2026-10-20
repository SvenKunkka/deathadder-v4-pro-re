/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f5528. Types and names are inferred; NOT original source. */

/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_1c0f5528(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_1c0ffc00(param_1,7);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(char *)(param_2 + 0x3c) == '\0') {
    iVar1 = FUN_1c0ffbd4(param_1,1);
    if ((((iVar1 == 0) || (iVar1 = FUN_1c0ffbb4(param_1,param_2), iVar1 == 0)) ||
        (iVar1 = FUN_1c0ffbb4(param_1,param_2 + 4), iVar1 == 0)) ||
       (iVar1 = FUN_1c0ffc00(param_1,0xc), iVar1 == 0)) goto switchD_1c0f5544_default;
    iVar1 = FUN_1c0ffcc8(0,6,param_2 + 0x38,DAT_1c0f58b4,param_1,param_2 + 8,8);
    if (iVar1 == 0) {
      FUN_1c0ffc48(param_1);
      goto switchD_1c0f5544_default;
    }
    iVar1 = FUN_1c0ffc40(param_1,0xc);
    goto joined_r0x1c0f584c;
  }
  switch(*(char *)(param_2 + 0x3c)) {
  case '\x01':
    iVar1 = FUN_1c0ffbd4(param_1,2);
    if (((iVar1 == 0) || (iVar1 = FUN_1c0ffbf8(param_1,param_2), iVar1 == 0)) ||
       (iVar1 = FUN_1c0ffb7c(param_1,param_2 + 8), iVar1 == 0)) goto switchD_1c0f5544_default;
    iVar1 = FUN_1c0ffbf8(param_1,param_2 + 0xc);
    break;
  case '\x02':
    iVar1 = FUN_1c0ffbd4(param_1,3);
    goto joined_r0x1c0f56a2;
  case '\x03':
    iVar1 = FUN_1c0ffbd4(param_1,4);
    break;
  case '\x04':
    iVar1 = FUN_1c0ffbd4(param_1,10);
    if (((((iVar1 == 0) || (iVar1 = FUN_1c0ffbf8(param_1,param_2), iVar1 == 0)) ||
         (iVar1 = FUN_1c0ffbb4(param_1,param_2 + 8), iVar1 == 0)) ||
        ((iVar1 = FUN_1c0ffbf8(param_1,param_2 + 0xc), iVar1 == 0 ||
         (iVar1 = FUN_1c0ffbf8(param_1,param_2 + 0x14), iVar1 == 0)))) ||
       (iVar1 = FUN_1c0ffbb4(param_1,param_2 + 0x1c), iVar1 == 0)) goto switchD_1c0f5544_default;
    iVar1 = FUN_1c0ffbb4(param_1,param_2 + 0x20);
    break;
  case '\x05':
    iVar1 = FUN_1c0ffbd4(param_1,0xb);
joined_r0x1c0f56a2:
    if (iVar1 == 0) goto switchD_1c0f5544_default;
    iVar1 = FUN_1c0ffbf8(param_1,param_2);
    break;
  case '\x06':
    iVar1 = FUN_1c0ffbd4(param_1,0xc);
    if (((iVar1 == 0) || (iVar1 = FUN_1c0ffbf8(param_1,param_2), iVar1 == 0)) ||
       (iVar1 = FUN_1c0ffbb4(param_1,param_2 + 8), iVar1 == 0)) goto switchD_1c0f5544_default;
    iVar1 = FUN_1c0ffbb4(param_1,param_2 + 0xc);
    break;
  case '\a':
    iVar1 = FUN_1c0ffbd4(param_1,0xd);
    if ((iVar1 == 0) || (iVar1 = FUN_1c0ffbf8(param_1,param_2), iVar1 == 0))
    goto switchD_1c0f5544_default;
    iVar1 = FUN_1c0ffbf8(param_1,param_2 + 8);
    break;
  case '\b':
    iVar1 = FUN_1c0ffbd4(param_1,0x12);
    break;
  case '\t':
    iVar1 = FUN_1c0ffbd4(param_1,0x13);
    goto joined_r0x1c0f587c;
  case '\n':
    iVar1 = FUN_1c0ffbd4(param_1,0x15);
    if (((iVar1 == 0) || (iVar1 = FUN_1c0ffbf8(param_1,param_2), iVar1 == 0)) ||
       (iVar1 = FUN_1c0ffbf8(param_1,param_2 + 8), iVar1 == 0)) goto switchD_1c0f5544_default;
    iVar1 = FUN_1c0ffb7c(param_1,param_2 + 0x10);
    break;
  case '\v':
    iVar1 = FUN_1c0ffbd4(param_1,0xe);
    goto joined_r0x1c0f585c;
  case '\f':
    iVar1 = FUN_1c0ffbd4(param_1,0xf);
    if ((iVar1 == 0) || (iVar1 = FUN_1c0ffbb4(param_1,param_2), iVar1 == 0))
    goto switchD_1c0f5544_default;
    iVar1 = FUN_1c0ffbb4(param_1,param_2 + 4);
    break;
  case '\r':
    iVar1 = FUN_1c0ffbd4(param_1,0x28);
    if (iVar1 == 0) goto switchD_1c0f5544_default;
    iVar1 = FUN_1c0ffc54(param_1,param_2);
    break;
  case '\x0e':
    iVar1 = FUN_1c0ffbd4(param_1,0x2b);
    if ((((iVar1 == 0) || (iVar1 = FUN_1c0ffbb4(param_1,param_2), iVar1 == 0)) ||
        ((iVar1 = FUN_1c0ffbb4(param_1,param_2 + 4), iVar1 == 0 ||
         ((iVar1 = FUN_1c0ffbb4(param_1,param_2 + 8), iVar1 == 0 ||
          (iVar1 = FUN_1c0ffc54(param_1,param_2 + 0xc), iVar1 == 0)))))) ||
       (iVar1 = FUN_1c0ffbb4(param_1,param_2 + 0x10), iVar1 == 0)) goto switchD_1c0f5544_default;
    iVar1 = FUN_1c0ffbb4(param_1,param_2 + 0x14);
    break;
  case '\x0f':
    iVar1 = FUN_1c0ffbd4(param_1,0x2c);
joined_r0x1c0f585c:
    if (iVar1 == 0) goto switchD_1c0f5544_default;
    iVar1 = FUN_1c0ffbb4(param_1,param_2);
    break;
  case '\x10':
    iVar1 = FUN_1c0ffbd4(param_1,0x32);
    break;
  case '\x11':
    iVar1 = FUN_1c0ffbd4(param_1,0x33);
joined_r0x1c0f587c:
    if (iVar1 == 0) goto switchD_1c0f5544_default;
    iVar1 = FUN_1c0ffb7c(param_1,param_2);
    break;
  case '\x12':
    iVar1 = FUN_1c0ffbd4(param_1,0x34);
    break;
  case '\x13':
    iVar1 = FUN_1c0ffbd4(param_1,0x35);
    break;
  default:
    goto switchD_1c0f5544_default;
  }
joined_r0x1c0f584c:
  if (iVar1 != 0) {
    uVar2 = FUN_1c0ffc40(param_1,7);
    return uVar2;
  }
switchD_1c0f5544_default:
  FUN_1c0ffc48(param_1);
  return 0;
}


