/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e085da4. Types and names are inferred; NOT original source. */

void FUN_0e085da4(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_2 * 8;
  iVar2 = param_2 + (uint)(*(ushort *)(param_1 + iVar3 + 2) >> 1);
  uVar1 = *(ushort *)(param_1 + iVar2 * 8 + 2);
  if (-1 < (int)((uint)uVar1 << 0x1f)) {
    FUN_0e085cfc(param_1,iVar2,0x1f - LZCOUNT((uint)(uVar1 >> 1)));
    FUN_0e085c6c(param_1,param_2,param_2 + (uint)(*(ushort *)(param_1 + iVar3 + 2) >> 1));
  }
  iVar2 = param_2 - (uint)*(ushort *)(param_1 + iVar3);
  uVar1 = *(ushort *)(param_1 + iVar2 * 8 + 2);
  if ((int)((uint)uVar1 << 0x1f) < 0) {
    FUN_0e085ca0(param_1,param_2,(uint)uVar1,param_4);
    return;
  }
  FUN_0e085cfc(param_1,iVar2,0x1f - LZCOUNT((uint)(uVar1 >> 1)));
  FUN_0e085c6c(param_1,param_2 - (uint)*(ushort *)(param_1 + iVar3),param_2);
  FUN_0e085ca0(param_1,param_2 - (uint)*(ushort *)(param_1 + iVar3));
  return;
}


