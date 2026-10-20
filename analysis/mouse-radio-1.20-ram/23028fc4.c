/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23028fc4. Types and names are inferred; NOT original source. */

byte FUN_23028fc4(int *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int *piVar6;
  undefined4 local_34;
  int local_30 [6];
  byte *pbVar5;
  
  piVar6 = local_30;
  local_34 = param_2;
  pbVar5 = &DAT_0e09b6c0;
  do {
    pbVar4 = pbVar5 + 1;
    bVar1 = *(byte *)((int)local_30 + ((*pbVar5 >> 3) - 4)) >> (*pbVar5 & 7);
    if ((bVar1 & 1) != 0) {
      local_30[0] = 0x5f938000;
      local_30[1] = 0x5f938200;
      local_30[2] = 0x5f938400;
      local_30[3] = 0x5f938c00;
      local_30[4] = 0x5f938e00;
      local_30[5] = 0x5f939200;
      iVar2 = *piVar6;
      iVar3 = *(int *)(iVar2 + 0x20);
      *param_1 = iVar3;
      *(int *)(iVar2 + 0x20) = iVar3;
      if (iVar3 != 0) {
        return bVar1 & 1;
      }
    }
    piVar6 = piVar6 + 1;
    param_1 = param_1 + 1;
    pbVar5 = pbVar4;
  } while (pbVar4 != &DAT_0e09b6c6);
  return 0;
}


