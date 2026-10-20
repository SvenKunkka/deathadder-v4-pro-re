/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069b50. Types and names are inferred; NOT original source. */

undefined4 FUN_0e069b50(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 4);
  if ((&DAT_23006e0c)[uVar1 * 0x14] == '\0') {
    (&DAT_23006e04)[uVar1 * 5] = param_3;
    (&DAT_23006e08)[uVar1 * 5] = param_4;
    if (param_2 != 0) {
      (&DAT_23006e14)[uVar1 * 0x14] = *(undefined1 *)(param_2 + 0x1c);
      FUN_0e069a24();
    }
    (&DAT_23006e0c)[uVar1 * 0x14] = 1;
    return 0xbad0000;
  }
  return 0xbad000c;
}


