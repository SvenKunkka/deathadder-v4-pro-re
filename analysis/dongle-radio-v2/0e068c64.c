/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068c64. Types and names are inferred; NOT original source. */

byte FUN_0e068c64(int *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int *piVar6;
  byte *pbVar7;
  undefined4 local_34;
  int local_30 [4];
  undefined4 local_20;
  undefined4 uStack_1c;
  byte *pbVar5;
  
  piVar6 = local_30;
  local_34 = param_2;
  pbVar7 = PTR_DAT_0e068cd4 + 6;
  pbVar5 = PTR_DAT_0e068cd4;
  do {
    pbVar4 = pbVar5 + 1;
    bVar1 = *(byte *)((int)local_30 + ((*pbVar5 >> 3) - 4)) >> (*pbVar5 & 7);
    if ((bVar1 & 1) != 0) {
      local_30[0] = *(int *)PTR_DAT_0e068cd8;
      local_30[1] = *(undefined4 *)(PTR_DAT_0e068cd8 + 4);
      local_30[2] = *(undefined4 *)(PTR_DAT_0e068cd8 + 8);
      local_30[3] = *(undefined4 *)(PTR_DAT_0e068cd8 + 0xc);
      local_20 = *(undefined4 *)(PTR_DAT_0e068cd8 + 0x10);
      uStack_1c = *(undefined4 *)(PTR_DAT_0e068cd8 + 0x14);
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
  } while (pbVar7 != pbVar4);
  return 0;
}


