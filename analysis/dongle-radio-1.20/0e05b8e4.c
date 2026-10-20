/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05b8e4. Types and names are inferred; NOT original source. */

void thunk_FUN_0e0621b8(int param_1,uint param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  bool bVar5;
  int iStack_24;
  
  if (param_2 != 0) {
    do {
      uVar4 = 0;
      bVar5 = (bool)isCurrentModePrivileged();
      if (bVar5) {
        uVar4 = getBasePriority();
      }
      bVar5 = (bool)isCurrentModePrivileged();
      if ((bVar5) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar2 = FUN_0e068540();
      bVar5 = CARRY4(uVar2,DAT_23000230);
      uVar2 = uVar2 + DAT_23000230;
      lVar1 = (ulonglong)uVar2 * 0x87b0b0fd;
      uVar3 = (uint)lVar1;
      DAT_23000230 = uVar3 + 0xb504f32d;
      DAT_23000234 = (DAT_23000234 + (uint)bVar5) * -0x784f4f03 + uVar2 * 0x27bb2ee6 +
                     (int)((ulonglong)lVar1 >> 0x20) + (uint)(0x4afb0cd2 < uVar3);
      bVar5 = (bool)isCurrentModePrivileged();
      if (bVar5) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar2 = param_2;
      if (3 < param_2) {
        uVar2 = 4;
      }
      iStack_24 = DAT_23000234;
      FUN_0e06f35c(param_1,&iStack_24,uVar2);
      param_2 = param_2 - uVar2;
      param_1 = param_1 + uVar2;
    } while (param_2 != 0);
    return;
  }
  return;
}


