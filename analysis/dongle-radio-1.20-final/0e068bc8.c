/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068bc8. Types and names are inferred; NOT original source. */

byte FUN_0e068bc8(int *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int *piVar6;
  undefined4 local_34;
  int local_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 *local_20;
  undefined4 uStack_1c;
  byte *pbVar5;
  
  piVar6 = &local_30;
  local_34 = param_2;
  pbVar5 = &DAT_0e070714;
  do {
    pbVar4 = pbVar5 + 1;
    bVar1 = *(byte *)((int)&local_34 + (uint)(*pbVar5 >> 3)) >> (*pbVar5 & 7);
    if ((bVar1 & 1) != 0) {
      local_30 = 0x5f938000;
      puStack_2c = &SUB_5f938200;
      uStack_28 = 0x5f938400;
      uStack_24 = 0x5f938c00;
      local_20 = &SUB_5f938e00;
      uStack_1c = 0x5f939200;
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
  } while (pbVar4 != &DAT_0e07071a);
  return 0;
}


