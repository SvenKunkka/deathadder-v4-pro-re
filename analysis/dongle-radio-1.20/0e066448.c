/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e066448. Types and names are inferred; NOT original source. */

undefined4 FUN_0e066448(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(iVar4 + 0x10);
  iVar5 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  *(uint *)(iVar3 + 0x804) = *(uint *)(iVar3 + 0x804) | 2;
  iVar1 = FUN_0e064968(param_1,0);
  if ((iVar1 == 0) && (iVar1 = FUN_0e064968(param_1,0x80), iVar1 == 0)) {
    (**(code **)(iVar4 + 0x24))(param_1);
    if ((int)((uint)*(byte *)(iVar5 + 0x362) << 0x1b) < 0) {
      FUN_0e066280(param_1,0,1);
      *(byte *)(iVar5 + 0x362) = *(byte *)(iVar5 + 0x362) & 0xef;
    }
    *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & 0xfffffffe;
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x18);
    uVar2 = 0;
    if ((iVar1 != 0) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0xc), UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0e06649e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(param_1);
      return uVar2;
    }
  }
  else {
    uVar2 = 0xfffffffb;
  }
  return uVar2;
}


