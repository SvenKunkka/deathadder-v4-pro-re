/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ae0f0. Types and names are inferred; NOT original source. */

byte FUN_0e0ae0f0(int param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 local_34;
  int local_30 [6];
  
  iVar4 = 0;
  local_34 = param_2;
  pbVar5 = &DAT_0e0b3e8d;
  do {
    bVar1 = *(byte *)((int)local_30 + ((*pbVar5 >> 3) - 4)) >> (*pbVar5 & 7);
    if ((bVar1 & 1) != 0) {
      local_30[0] = 0x5f938000;
      local_30[1] = 0x5f938200;
      local_30[2] = 0x5f938400;
      local_30[3] = 0x5f938c00;
      local_30[4] = 0x5f938e00;
      local_30[5] = 0x5f939200;
      iVar2 = local_30[iVar4];
      iVar3 = *(int *)(iVar2 + 0x20);
      *(int *)(param_1 + iVar4 * 4) = iVar3;
      *(int *)(iVar2 + 0x20) = iVar3;
      if (iVar3 != 0) {
        return bVar1 & 1;
      }
    }
    iVar4 = iVar4 + 1;
    pbVar5 = pbVar5 + 1;
  } while (iVar4 != 6);
  return 0;
}


