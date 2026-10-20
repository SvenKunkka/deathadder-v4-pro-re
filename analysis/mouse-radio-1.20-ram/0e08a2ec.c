/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08a2ec. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e08a2ec(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int local_2c [2];
  
  if ((_DAT_e000ed90 & 0xffff) >> 8 < 3) {
    uVar3 = 0xffffffff;
  }
  else {
    DataMemoryBarrier(0x1f);
    _DAT_e000ed94 = 0;
    _DAT_e000edc0 = 0x44ffaa;
    puVar4 = &DAT_23001034;
    uVar11 = 0;
    do {
      _DAT_e000ed98 = uVar11;
      _DAT_e000ed9c = *puVar4 & 0xffffffe0 | (byte)puVar4[2] & 0x1f;
      _DAT_e000eda0 = puVar4[3] & 0xffffffe0 | (uint)(byte)((byte)puVar4[2] >> 5) << 1 | 1;
      puVar4 = puVar4 + 4;
      uVar11 = _DAT_e000ed98 + 1;
    } while (_DAT_e000ed98 + 1 != 3);
    DAT_230077c5 = 3;
    iVar2 = FUN_0e0885b8(local_2c);
    if (iVar2 == 0) {
      uVar11 = (uint)DAT_230077c5;
    }
    else {
      bVar1 = false;
      uVar11 = (uint)DAT_230077c5;
      iVar10 = 0;
      uVar6 = uVar11;
      do {
        while (uVar5 = uVar6, uVar6 = *(uint *)(local_2c[0] + 0xc) & 0xfff00000, uVar6 == 0x200000)
        {
          iVar8 = 2;
          uVar7 = *(uint *)(local_2c[0] + 4) & 0xffffffe0;
          uVar9 = 1;
          uVar6 = *(int *)(local_2c[0] + 8) + -1 + uVar7 & 0xffffffe0;
LAB_0e08a3ac:
          if (((_DAT_e000ed90 & 0xffff) >> 8) - 1 < uVar5) {
            if (bVar1) {
              DAT_230077c5 = (byte)uVar5;
            }
            return 0xffffffea;
          }
          bVar1 = true;
          iVar10 = iVar10 + 1;
          _DAT_e000eda0 = uVar6 | iVar8 << 1 | 1;
          _DAT_e000ed9c = uVar7 | uVar9;
          local_2c[0] = local_2c[0] + 0x10;
          uVar6 = uVar5 + 1 & 0xff;
          _DAT_e000ed98 = uVar5;
          if (iVar2 == iVar10) goto LAB_0e08a3ea;
        }
        if (uVar6 == 0x400000) {
          iVar8 = 0;
          uVar9 = 2;
          uVar7 = *(uint *)(local_2c[0] + 4) & 0xffffffe0;
          uVar6 = *(int *)(local_2c[0] + 8) + -1 + uVar7 & 0xffffffe0;
          goto LAB_0e08a3ac;
        }
        if (uVar6 == 0x100000) {
          iVar8 = 1;
          uVar9 = 1;
          uVar7 = *(uint *)(local_2c[0] + 4) & 0xffffffe0;
          uVar6 = *(int *)(local_2c[0] + 8) + -1 + uVar7 & 0xffffffe0;
          goto LAB_0e08a3ac;
        }
        iVar10 = iVar10 + 1;
        local_2c[0] = local_2c[0] + 0x10;
        uVar6 = uVar5;
      } while (iVar2 != iVar10);
LAB_0e08a3ea:
      if (bVar1) {
        DAT_230077c5 = (byte)uVar6;
        uVar11 = uVar6;
      }
    }
    if (uVar11 < (_DAT_e000ed90 & 0xffff) >> 8) {
      do {
        _DAT_e000ed98 = uVar11;
        _DAT_e000eda0 = 0;
        uVar11 = _DAT_e000ed98 + 1;
      } while ((int)(_DAT_e000ed98 + 1) < (int)((_DAT_e000ed90 & 0xffff) >> 8));
    }
    _DAT_e000ed94 = 5;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
    uVar3 = 0;
  }
  return uVar3;
}


