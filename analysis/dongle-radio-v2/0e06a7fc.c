/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a7fc. Types and names are inferred; NOT original source. */

void FUN_0e06a7fc(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  int iVar14;
  
  uVar2 = FUN_0e06ac1c(param_2);
  uVar3 = FUN_0e06ac1c(param_3);
  iVar4 = FUN_0e06ac0c(uVar2);
  iVar14 = param_1 * 0xc;
  if (iVar4 == 0xf) {
    iVar4 = iVar14 + 8;
  }
  else {
    iVar4 = iVar14 + 9;
  }
  iVar5 = FUN_0e06ac0c(uVar3);
  iVar1 = DAT_0e06a974;
  if (iVar5 == 0xf) {
    iVar5 = iVar14 + 8;
  }
  else {
    iVar5 = iVar14 + 9;
  }
  pbVar11 = (byte *)(DAT_0e06a974 + iVar5);
  iVar5 = FUN_0e06ac0c(uVar2);
  iVar6 = FUN_0e06ac0c(uVar3);
  iVar12 = iVar1 + param_1 * 0xc;
  pbVar13 = (byte *)(iVar4 + iVar1);
  if (iVar5 == iVar6) {
    iVar4 = FUN_0e06a520(uVar2,uVar3,pbVar13);
    if (iVar4 == DAT_0e06a978) goto LAB_0e06a904;
    FUN_0e06a300(uVar2,uVar3,*pbVar13);
  }
  else {
    puVar7 = (undefined4 *)FUN_0e06ac90(uVar2);
    puVar8 = (undefined4 *)FUN_0e06ac90(uVar3);
    uVar9 = FUN_0e06ac1c(*puVar7);
    uVar10 = FUN_0e06ac1c(*puVar8);
    iVar4 = FUN_0e06a520(uVar2,uVar9,pbVar13);
    if (((iVar4 == DAT_0e06a978) && (iVar5 = FUN_0e06a520(uVar10,uVar3,pbVar11), iVar5 == iVar4)) &&
       (iVar4 = FUN_0e06a3c8(puVar7,puVar8,iVar12), iVar4 == iVar5)) {
LAB_0e06a904:
      *(undefined4 *)(iVar1 + param_1 * 0xc) = uVar2;
      if (param_2 + 0xacfd4000U < 0x1065) {
        iVar4 = 0x100;
      }
      else {
        iVar4 = 0x80;
      }
      if (param_3 + 0xacfd4000U < 0x1065) {
        iVar14 = 0x100;
      }
      else {
        iVar14 = 0x80;
      }
      *(undefined4 *)(iVar1 + param_1 * 0xc + 4) = uVar3;
      *(uint *)(iVar4 + param_2) = *pbVar13 | 0x80000000;
      *(uint *)(iVar14 + param_3) = *pbVar11 | 0x80000000;
      return;
    }
    FUN_0e06a300(uVar2,uVar9,*pbVar13);
    FUN_0e06a300(uVar10,uVar3,*pbVar11);
    FUN_0e06a3c8(puVar7,puVar8,iVar12);
  }
  *(undefined4 *)(iVar1 + iVar14) = 0;
  *(undefined4 *)(iVar12 + 4) = 0;
  *(undefined4 *)(iVar12 + 8) = 0;
  *(undefined2 *)(iVar1 + param_1 * 0xc + 8) = 0xffff;
  *(undefined1 *)(param_1 * 0xc + iVar1 + 10) = 0xff;
  return;
}


