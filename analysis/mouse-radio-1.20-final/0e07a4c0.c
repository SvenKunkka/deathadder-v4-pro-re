/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07a4c0. Types and names are inferred; NOT original source. */

void FUN_0e07a4c0(undefined4 param_1)

{
  dword dVar1;
  
  switch(param_1) {
  case 1:
    dVar1 = 0xf;
    break;
  case 2:
    dVar1 = 0x16;
    break;
  case 3:
    dVar1 = 0x17;
    break;
  case 4:
    dVar1 = 0x18;
    break;
  case 5:
    dVar1 = 0x19;
    break;
  case 6:
    dVar1 = 0x1a;
    break;
  case 7:
    dVar1 = 0x1b;
    break;
  case 8:
    dVar1 = 0x1c;
    break;
  case 9:
    dVar1 = 0x1d;
    break;
  case 10:
    dVar1 = 0x1f;
    break;
  case 0xffffffba:
    dVar1 = 0;
    break;
  default:
    FUN_0e085e6c("TX power to enumerator conversion failed, defaulting to 0 dBm\n");
  case 0:
    dVar1 = 0xe;
    break;
  case 0xffffffd8:
    dVar1 = 1;
    break;
  case 0xffffffe2:
    dVar1 = 2;
    break;
  case 0xffffffec:
    dVar1 = 3;
    break;
  case 0xfffffff0:
    dVar1 = 8;
    break;
  case 0xfffffff4:
    dVar1 = 9;
    break;
  case 0xfffffff8:
    dVar1 = 10;
    break;
  case 0xfffffffc:
    dVar1 = 0xb;
    break;
  case 0xfffffffe:
    dVar1 = 0xc;
    break;
  case 0xffffffff:
    dVar1 = 0xd;
  }
  RADIO_S_TXPOWER = dVar1;
  if (DAT_23007712 != '\0') {
    return;
  }
  FUN_0e085e6c("Requested tx output power: %hhi dBm\n",param_1);
  FUN_0e085e6c("Tx output power set to: %hhi dBm\n",param_1);
  return;
}


