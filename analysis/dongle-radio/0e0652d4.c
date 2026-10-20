/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0652d4. Types and names are inferred; NOT original source. */

void FUN_0e0652d4(int param_1,uint *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  undefined4 extraout_r1_00;
  int iVar4;
  code *pcVar5;
  undefined8 uVar6;
  int local_20;
  int iStack_1c;
  
  FUN_0e06ea7c(&local_20,param_2,DAT_0e065328,0);
  iVar2 = iStack_1c;
  iVar1 = local_20;
  uVar3 = extraout_r1;
  do {
    if ((param_3 & *param_2) != 0) {
      return;
    }
    iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x18);
    if ((iVar4 != 0) && (pcVar5 = *(code **)(iVar4 + 0x1c), pcVar5 != (code *)0x0)) {
      uVar6 = (*pcVar5)(param_1);
      uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
      if ((int)uVar6 != 0) {
        return;
      }
    }
    FUN_0e06eb0c(&local_20,uVar3,iVar1,iVar2);
    uVar3 = extraout_r1_00;
  } while (iStack_1c != 0 || local_20 != 0);
  return;
}


