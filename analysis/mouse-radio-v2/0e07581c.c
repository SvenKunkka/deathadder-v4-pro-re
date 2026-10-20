/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07581c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e07581c(int param_1,uint param_2,byte *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = DAT_0e075858;
  uVar1 = *(ushort *)
           (DAT_0e075854 +
           ((uint)*(byte *)(param_1 + 4) * 0x52 +
            ((uint)*(byte *)(DAT_0e075850 + (param_2 >> 5)) + (param_2 & 0x1f) & 0xff) + 8) * 2);
  uVar2 = DAT_0e07585c;
  if ((int)((uint)uVar1 << 0x1a) < 0) {
    *param_3 = (byte)(uVar1 >> 0xd);
    uVar2 = uVar3;
  }
  return uVar2;
}


