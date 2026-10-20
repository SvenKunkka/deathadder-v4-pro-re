/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ae20c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0ae20c(int *param_1,int param_2,undefined4 param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  int local_1c;
  undefined4 uStack_18;
  
  local_1c = param_2;
  uStack_18 = param_3;
  uVar6 = FUN_0e0ae054(param_2);
  iVar3 = (int)((ulonglong)uVar6 >> 0x20);
  iVar5 = (int)uVar6 + 8;
  if ((int)((uint)*(ushort *)(&DAT_2f01137c + iVar5 * 2) << 0x1f) < 0) {
    FUN_0e0b212a(param_1);
    iVar2 = FUN_0e0ae0d8(iVar3);
    if (iVar2 != 0) {
      sVar1 = FUN_0e0ae0a8(iVar3);
      iVar2 = *param_1 + sVar1 * 4;
      *(undefined4 *)(iVar2 + 0x510) = 0;
      *(undefined4 *)(iVar2 + 0x510) = 0;
    }
    FUN_0e0ae158(iVar3);
    *(undefined2 *)(&DAT_2f01137c + iVar5 * 2) = 0;
    local_1c = iVar3;
    iVar3 = FUN_0e0ae034(&local_1c);
    iVar3 = iVar3 + local_1c * 4;
    *(uint *)(iVar3 + 0x80) = *(uint *)(iVar3 + 0x80) & 0xfffcf0f0 | 2;
    uVar4 = 0xbad0000;
  }
  else {
    uVar4 = 0xbad0004;
  }
  return uVar4;
}


