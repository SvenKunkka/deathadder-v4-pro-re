/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ae5e4. Types and names are inferred; NOT original source. */

void FUN_0e0ae5e4(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  uint local_14;
  
  if (-1 < *(int *)(*param_1 + 0x334) << 0xc) {
    *(undefined4 *)(*param_1 + 0x334) = 0x80000;
  }
  local_14 = param_2;
  uVar3 = FUN_0e0ae0d8(param_2);
  iVar1 = (int)((ulonglong)uVar3 >> 0x20);
  if (((int)uVar3 != 0) && (iVar1 = FUN_0e0ae0c0(iVar1), iVar1 == 0)) {
    uVar3 = FUN_0e0ae0a8(param_2);
    iVar1 = (short)uVar3 * 4;
    *(int *)(*param_1 + iVar1 + 0x100) = (int)((ulonglong)uVar3 >> 0x20);
    iVar1 = *param_1 + iVar1;
    *(uint *)(iVar1 + 0x510) = *(uint *)(iVar1 + 0x510) | 1;
    if (param_3 != 0) {
      *(int *)(*param_1 + 0x334) = 1 << ((uint)uVar3 & 0xff);
    }
    return;
  }
  iVar1 = FUN_0e0ae054(param_2,iVar1);
  uVar2 = (*(ushort *)(&DAT_2f01137c + (iVar1 + 8) * 2) & 0x1f) >> 2;
  if (uVar2 == 4) {
    iVar1 = 3;
  }
  else if (uVar2 == 5) {
    iVar1 = 2;
  }
  else {
    local_14 = param_2;
    iVar1 = FUN_0e0ae034(&local_14);
    iVar1 = (*(uint *)(iVar1 + 0xc) >> (local_14 & 0xff) & 1) + 2;
  }
  FUN_0e0b210c(param_2,iVar1);
  return;
}


