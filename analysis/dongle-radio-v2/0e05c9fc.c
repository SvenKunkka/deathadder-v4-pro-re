/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05c9fc. Types and names are inferred; NOT original source. */

void FUN_0e05c9fc(undefined4 param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  switch(param_1) {
  case 1:
    uVar2 = 0xf;
    break;
  case 2:
    uVar2 = 0x16;
    break;
  case 3:
    uVar2 = 0x17;
    break;
  case 4:
    uVar2 = 0x18;
    break;
  case 5:
    uVar2 = 0x19;
    break;
  case 6:
    uVar2 = 0x1a;
    break;
  case 7:
    uVar2 = 0x1b;
    break;
  case 8:
    uVar2 = 0x1c;
    break;
  case 9:
    uVar2 = 0x1d;
    break;
  case 10:
    uVar2 = 0x1f;
    break;
  case 0xffffffba:
    uVar2 = 0;
    break;
  default:
    FUN_0e05d734(DAT_0e05cad8);
  case 0:
    uVar2 = 0xe;
    break;
  case 0xffffffd8:
    uVar2 = 1;
    break;
  case 0xffffffe2:
    uVar2 = 2;
    break;
  case 0xffffffec:
    uVar2 = 3;
    break;
  case 0xfffffff0:
    uVar2 = 8;
    break;
  case 0xfffffff4:
    uVar2 = 9;
    break;
  case 0xfffffff8:
    uVar2 = 10;
    break;
  case 0xfffffffc:
    uVar2 = 0xb;
    break;
  case 0xfffffffe:
    uVar2 = 0xc;
    break;
  case 0xffffffff:
    uVar2 = 0xd;
  }
  pcVar1 = DAT_0e05cae0;
  *(undefined4 *)(DAT_0e05cadc + 0x710) = uVar2;
  if (*pcVar1 != '\0') {
    return;
  }
  FUN_0e05d734(DAT_0e05cae4,param_1);
  FUN_0e05d734(DAT_0e05cae8,param_1);
  return;
}


