/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05da88. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05da88(uint *param_1,uint param_2,uint *param_3)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  int local_44;
  undefined1 auStack_40 [28];
  
  uVar13 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar13 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar11 = getBasePriority(), uVar11 == 0 || 0x40 < uVar11)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (((param_3 == (uint *)0x0) || (param_2 == 0)) || (*param_1 < param_2)) {
    uVar7 = 0xffffffea;
    goto LAB_0e05db1e;
  }
  uVar12 = *param_1 - param_2;
  uVar11 = 0;
  if (param_1[1] == 0) {
LAB_0e05dad0:
    do {
      iVar6 = FUN_0e05d8a4(param_1,uVar11,param_2,0,auStack_40,&local_44);
      if (iVar6 != 0) {
        FUN_0e05d7bc(param_1,uVar11,param_2,1,auStack_40);
        *param_3 = uVar11;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar13);
        }
        InstructionSynchronizationBarrier(0xf);
        return 0;
      }
      uVar11 = local_44 + 1;
    } while (uVar11 <= uVar12);
  }
  else {
    uVar8 = 0;
    uVar11 = 0;
    puVar9 = (uint *)(param_1[2] - 4);
    do {
      puVar9 = puVar9 + 1;
      uVar10 = *puVar9;
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
      uVar8 = uVar8 + 1;
      uVar11 = uVar11 + 0x20;
    } while (uVar8 != param_1[1]);
    if (uVar11 <= uVar12) goto LAB_0e05dad0;
  }
  uVar7 = 0xffffffe4;
LAB_0e05db1e:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar13);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar7;
}


