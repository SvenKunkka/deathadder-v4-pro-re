/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0725a0. Types and names are inferred; NOT original source. */

void FUN_0e0725a0(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined1 param_4,
                 short param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_0e072188(param_1,param_2,param_3,param_4);
  iVar1 = DAT_0e0725d0;
  uVar2 = (uint)(ushort)(*(short *)(DAT_0e0725d0 + 0x1e) + 1);
  uVar3 = uVar2;
  if (30000 < uVar2) {
    uVar3 = 0;
  }
  *(short *)(DAT_0e0725d0 + 0x1c) = param_5 + *(short *)(DAT_0e0725d0 + 0x1c);
  if (uVar2 < 0x7531) {
    *(short *)(iVar1 + 0x1e) = (short)uVar3;
  }
  else {
    *(uint *)(iVar1 + 0x1c) = uVar3;
  }
  return;
}


