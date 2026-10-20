/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23028c08. Types and names are inferred; NOT original source. */

void FUN_23028c08(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  uint local_18;
  uint uStack_14;
  
  FUN_23029b84(&local_18);
  if (param_4 < uStack_14 || uStack_14 - param_4 < (uint)(param_3 <= local_18)) {
    uVar3 = param_3 - DAT_230021c0;
    uVar2 = uVar3 & 0xffffffe0;
    iVar1 = (param_4 - DAT_230021c4) - (uint)(param_3 < DAT_230021c0);
    bVar4 = CARRY4(uVar2,DAT_230021c0);
    DAT_230021c0 = uVar2 + DAT_230021c0;
    DAT_230021c4 = DAT_230021c4 + iVar1 + (uint)bVar4;
    FUN_0e09668c(uVar3 >> 5 | iVar1 * 0x8000000);
    return;
  }
  return;
}


