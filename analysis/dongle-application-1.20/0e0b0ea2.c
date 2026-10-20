/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b0ea2. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0b0ea2(uint *param_1,uint param_2,uint *param_3)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  int local_44;
  undefined1 auStack_40 [28];
  
  uVar12 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar12 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar8 = getBasePriority(), uVar8 == 0 || 0x20 < uVar8)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (((param_3 == (uint *)0x0) || (param_2 == 0)) || (uVar8 = *param_1, uVar8 < param_2)) {
    uVar6 = 0xffffffea;
  }
  else {
    for (uVar9 = 0; uVar11 = uVar9 * 0x20, param_1[1] != uVar9; uVar9 = uVar9 + 1) {
      uVar10 = *(uint *)(param_1[2] + uVar9 * 4);
      if (uVar10 != 0xffffffff) {
        if (uVar10 != 0) {
          uVar10 = ~uVar10;
          bVar3 = (byte)uVar10;
          bVar4 = (byte)(uVar10 >> 8);
          bVar5 = (byte)(uVar10 >> 0x10);
          bVar2 = (byte)(uVar10 >> 0x18);
          uVar11 = uVar11 + LZCOUNT((uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
                                                     bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
                                                   bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                                                 bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x18 |
                                    (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 |
                                                     bVar4 >> 2 & 1) << 1 | bVar4 >> 3 & 1) << 1 |
                                                   bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                                                 bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 0x10 |
                                    (uint)(byte)((((((((bVar5 & 1) << 1 | bVar5 >> 1 & 1) << 1 |
                                                     bVar5 >> 2 & 1) << 1 | bVar5 >> 3 & 1) << 1 |
                                                   bVar5 >> 4 & 1) << 1 | bVar5 >> 5 & 1) << 1 |
                                                 bVar5 >> 6 & 1) << 1 | bVar5 >> 7) << 8 |
                                    (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 |
                                                     bVar2 >> 2 & 1) << 1 | bVar2 >> 3 & 1) << 1 |
                                                   bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                                                 bVar2 >> 6 & 1) << 1 | bVar2 >> 7));
        }
        break;
      }
    }
    while (uVar11 <= uVar8 - param_2) {
      iVar7 = FUN_0e0b0d0c(param_1,uVar11,param_2,0,auStack_40,&local_44);
      if (iVar7 != 0) {
        FUN_0e0b0c7c(param_1,uVar11,param_2,1,auStack_40);
        uVar6 = 0;
        *param_3 = uVar11;
        goto LAB_0e0b0f2c;
      }
      uVar11 = local_44 + 1;
    }
    uVar6 = 0xffffffe4;
  }
LAB_0e0b0f2c:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar12);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar6;
}


