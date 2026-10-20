/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020bd4. Types and names are inferred; NOT original source. */

void FUN_23020bd4(undefined4 param_1)

{
  dword dVar1;
  
  switch(param_1) {
  case 0:
    dVar1 = RADIO_S_RXADDRESSES;
    RADIO_S_RXADDRESSES = dVar1 & 0xfffffff5;
    return;
  case 1:
    dVar1 = RADIO_S_RXADDRESSES;
    RADIO_S_RXADDRESSES = dVar1 & 0xfffffff3;
    return;
  case 2:
    dVar1 = RADIO_S_RXADDRESSES;
    RADIO_S_RXADDRESSES = dVar1 & 0xfffffff9;
    return;
  default:
    dVar1 = RADIO_S_RXADDRESSES;
    RADIO_S_RXADDRESSES = dVar1 & 0xfffffffe;
    return;
  case 7:
    dVar1 = RADIO_S_RXADDRESSES;
    RADIO_S_RXADDRESSES = dVar1 & 0xffffff7f;
    return;
  }
}


