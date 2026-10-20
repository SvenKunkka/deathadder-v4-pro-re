/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e65e0. Types and names are inferred; NOT original source. */

void FUN_1c0e65e0(undefined4 param_1)

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
    FUN_1c0f1ff8(DAT_1c0e66bc);
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
  pcVar1 = DAT_1c0e66c4;
  *(undefined4 *)(DAT_1c0e66c0 + 0x710) = uVar2;
  if (*pcVar1 != '\0') {
    return;
  }
  FUN_1c0f1ff8(DAT_1c0e66c8,param_1);
  FUN_1c0f1ff8(DAT_1c0e66cc,param_1);
  return;
}


