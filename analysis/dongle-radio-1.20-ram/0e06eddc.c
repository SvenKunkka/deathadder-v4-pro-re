/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06eddc. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e06ed74) */
/* WARNING: Removing unreachable block (ram,0x0e06ed78) */

uint FUN_0e06eddc(int param_1,uint param_2,int param_3,undefined4 param_4,uint param_5,uint param_6)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if (param_2 != 0) {
    iVar2 = FUN_0e06e3a4();
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x40 < uVar5)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    if (param_3 << 0x1f < 0) {
      *(undefined4 *)(param_1 + 8) = 0;
    }
    else {
      uVar5 = *(uint *)(param_1 + 8) & param_2;
      if (uVar5 != 0) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar4);
        }
        InstructionSynchronizationBarrier(0xf);
        return uVar5;
      }
    }
    if ((param_5 | param_6) == 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
    }
    else {
      *(uint *)(iVar2 + 100) = param_2;
      *(int *)(iVar2 + 0x68) = param_3 << 1;
      iVar3 = FUN_0e06dec8(param_1 + 0xc,uVar4,param_1,param_5 | param_6,param_5,param_6);
      if (iVar3 == 0) {
        return param_2 & *(uint *)(iVar2 + 100);
      }
    }
  }
  return 0;
}


