/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a760. Types and names are inferred; NOT original source. */

void FUN_0e06a760(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  byte *pbVar11;
  byte *pbVar12;
  int iVar13;
  
  uVar1 = FUN_0e06ab80(param_2);
  uVar2 = FUN_0e06ab80(param_3);
  iVar3 = FUN_0e06ab70(uVar1);
  iVar13 = param_1 * 0xc;
  if (iVar3 == 0xf) {
    iVar3 = iVar13 + 8;
  }
  else {
    iVar3 = iVar13 + 9;
  }
  iVar4 = FUN_0e06ab70(uVar2);
  if (iVar4 == 0xf) {
    iVar4 = iVar13 + 8;
  }
  else {
    iVar4 = iVar13 + 9;
  }
  pbVar11 = &DAT_23006e58 + iVar4;
  iVar5 = FUN_0e06ab70(uVar1);
  iVar6 = FUN_0e06ab70(uVar2);
  iVar4 = param_1 * 0xc;
  pbVar12 = &DAT_23006e58 + iVar3;
  if (iVar5 == iVar6) {
    iVar3 = FUN_0e06a484(uVar1,uVar2,pbVar12);
    if (iVar3 == 0xbad0000) goto LAB_0e06a868;
    FUN_0e06a264(uVar1,uVar2,*pbVar12);
  }
  else {
    puVar7 = (undefined4 *)FUN_0e06abf4(uVar1);
    puVar8 = (undefined4 *)FUN_0e06abf4(uVar2);
    uVar9 = FUN_0e06ab80(*puVar7);
    uVar10 = FUN_0e06ab80(*puVar8);
    iVar3 = FUN_0e06a484(uVar1,uVar9,pbVar12);
    if (((iVar3 == 0xbad0000) && (iVar3 = FUN_0e06a484(uVar10,uVar2,pbVar11), iVar3 == 0xbad0000))
       && (iVar3 = FUN_0e06a32c(puVar7,puVar8,&DAT_23006e58 + iVar4), iVar3 == 0xbad0000)) {
LAB_0e06a868:
      *(undefined4 *)(&DAT_23006e58 + param_1 * 0xc) = uVar1;
      if (param_2 + 0xacfd4000U < 0x1065) {
        iVar3 = 0x100;
      }
      else {
        iVar3 = 0x80;
      }
      if (param_3 + 0xacfd4000U < 0x1065) {
        iVar13 = 0x100;
      }
      else {
        iVar13 = 0x80;
      }
      *(undefined4 *)(&DAT_23006e5c + param_1 * 0xc) = uVar2;
      *(uint *)(iVar3 + param_2) = *pbVar12 | 0x80000000;
      *(uint *)(iVar13 + param_3) = *pbVar11 | 0x80000000;
      return;
    }
    FUN_0e06a264(uVar1,uVar9,*pbVar12);
    FUN_0e06a264(uVar10,uVar2,*pbVar11);
    FUN_0e06a32c(puVar7,puVar8,&DAT_23006e58 + iVar4);
  }
  *(undefined4 *)(&DAT_23006e58 + iVar13) = 0;
  *(undefined4 *)(&DAT_23006e5c + iVar4) = 0;
  *(undefined4 *)(&DAT_23006e60 + iVar4) = 0;
  *(undefined2 *)(&DAT_23006e60 + param_1 * 0xc) = 0xffff;
  (&DAT_23006e62)[param_1 * 0xc] = 0xff;
  return;
}


