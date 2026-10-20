/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302633a. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ram_candidate_2302633a(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *unaff_r4;
  
  cVar1 = unaff_r4[8];
  if (cVar1 == '\x01') {
    FUN_23026f68();
    thunk_FUN_23025300(ram0x23002d8b << 0x18 | (ram0x23002d8b >> 8 & 0xff) << 0x10 |
                       (ram0x23002d8b >> 0x10 & 0xff) << 8 | ram0x23002d8b >> 0x18);
    uVar2 = ram_candidate_23026216();
    return uVar2;
  }
  if (cVar1 != '\x03') {
    if (cVar1 == '\x05') {
      FUN_23020608(0x2ee);
      *unaff_r4 = 2;
      uVar2 = ram_candidate_23026216();
      return uVar2;
    }
    return 1;
  }
  DAT_23002d80._2_2_ = 0xffff;
  FUN_23026f30(2);
  FUN_23020608(0x2ee);
  *unaff_r4 = 2;
  uVar2 = ram_candidate_23026216();
  return uVar2;
}


