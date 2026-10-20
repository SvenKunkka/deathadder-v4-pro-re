/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026290. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ram_candidate_23026290(void)

{
  uint uVar1;
  undefined1 *unaff_r4;
  
  uVar1 = *(uint *)(unaff_r4 + 8);
  if (((((DAT_23002dcf & 0xff) != (uVar1 & 0xff)) ||
       ((DAT_23002dcf >> 8 & 0xff) != (uVar1 & 0xffff) >> 8)) ||
      ((DAT_23002dcf >> 0x10 & 0xff) != (uVar1 & 0xffffff) >> 0x10)) ||
     (DAT_23002dcf >> 0x18 != uVar1 >> 0x18)) {
    unique0x10000095 = uVar1;
    DAT_23002dcf = uVar1;
    if (0xfffffffc < uVar1 - 1 && uVar1 != 0xfffffffe) {
      register0x0000002c =
           _DAT_0fffe010 >> 0x18 | ((_DAT_0fffe010 & 0xffffff) >> 0x10) << 8 |
           ((_DAT_0fffe010 & 0xffff) >> 8) << 0x10 | _DAT_0fffe010 << 0x18;
      DAT_23002dcf = CONCAT13((char)_DAT_0fffe010,
                              CONCAT12((char)(_DAT_0fffe010 >> 8),
                                       CONCAT11((char)(_DAT_0fffe010 >> 0x10),
                                                (char)(_DAT_0fffe010 >> 0x18))));
    }
    FUN_23026f30(4);
    FUN_23026f30(2);
    thunk_FUN_230252a4(DAT_23002dcf << 0x18 | (DAT_23002dcf >> 8 & 0xff) << 0x10 |
                       (DAT_23002dcf >> 0x10 & 0xff) << 8 | DAT_23002dcf >> 0x18);
  }
  *unaff_r4 = 2;
  return 1;
}


