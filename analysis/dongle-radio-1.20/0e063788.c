/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063788. Types and names are inferred; NOT original source. */

int FUN_0e063788(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  int *piVar6;
  undefined8 uVar7;
  
  uVar1 = FUN_0e062244();
  if (*(char *)(param_1 + 0x34) != '\0') {
    if (*(char *)(param_1 + 0x2c) != '\x02') {
      return -0x3d;
    }
    uVar3 = FUN_0e062244(param_1);
    iVar4 = FUN_0e063728(param_1,uVar3,*(undefined1 *)(param_1 + 0x34));
    if (iVar4 == 0) {
      return -0x3d;
    }
    iVar2 = FUN_0e063cc0(param_1,iVar4);
    *(undefined4 *)(param_1 + 0x36) = 0;
    *(undefined4 *)(param_1 + 0x3a) = 0;
    *(undefined4 *)(param_1 + 0x3e) = 0;
    *(undefined4 *)(param_1 + 0x42) = 0;
    *(undefined1 *)(param_1 + 0x34) = 0;
    for (piVar6 = *(int **)(iVar4 + 0xc); piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
      pcVar5 = *(code **)(*(int *)(piVar6[1] + 8) + 0x24);
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)();
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x34) = 0;
  }
  else {
    uVar7 = FUN_0e063728(param_1,uVar1,param_2);
    iVar4 = (int)uVar7;
    if (iVar4 == 0) {
      return -0x3d;
    }
    iVar2 = FUN_0e063d20(param_1,(int)((ulonglong)uVar7 >> 0x20),iVar4);
    if (iVar2 != 0) {
      return iVar2;
    }
    *(char *)(param_1 + 0x34) = (char)param_2;
    for (piVar6 = *(int **)(iVar4 + 0xc); piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
      pcVar5 = *(code **)(*(int *)(piVar6[1] + 8) + 0x20);
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)();
      }
    }
  }
  return 0;
}


