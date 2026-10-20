/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f3dc0. Types and names are inferred; NOT original source. */

void FUN_1c0f3dc0(undefined1 *param_1,uint param_2,int param_3)

{
  byte bVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 local_20;
  int local_1c;
  
  piVar5 = *(int **)(param_3 + 0x10);
  if ((2 < param_2) && (uVar6 = (uint)(byte)param_1[1], uVar6 < 4)) {
    switch(*param_1) {
    case 0:
      uVar2 = param_1[2];
      iVar7 = *piVar5;
      iVar4 = FUN_1c0f382c(iVar7 + 0x10,uVar2,&local_20,1);
      piVar3 = (int *)FUN_1c0f3a94(piVar5,uVar6);
      if ((iVar4 != 0) && (piVar3 != (int *)0x0)) {
        FUN_1c0f2278(*(undefined4 *)(iVar7 + 0x2c),uVar2);
        (**(code **)(*piVar3 + 0xc))(iVar4,local_20,*(undefined4 *)(*piVar3 + 0x14));
        FUN_1c0f22bc(*(undefined4 *)(iVar7 + 0x2c),uVar2,&local_1c);
        if (local_1c == 0) {
          FUN_1c0f3bd8(piVar5,iVar4,1);
        }
      }
      break;
    case 1:
      FUN_1c0f3d60(piVar5,param_1[2]);
      return;
    case 2:
      bVar1 = param_1[2];
      uVar8 = FUN_1c0f382c(*piVar5 + 0x10,bVar1,&local_1c,1);
      if ((int)uVar8 != 0) {
        FUN_1c100d84(piVar5 + 0x1e,(int)((ulonglong)uVar8 >> 0x20),0xffffffff,0xffffffff);
        *(ushort *)((int)piVar5 + (uVar6 + 0x78) * 2) = (ushort)bVar1;
        FUN_1c100e80(piVar5 + 0x1e);
        FUN_1c1013d4(DAT_1c0f3ea8,piVar5 + 0x23);
        return;
      }
      break;
    case 3:
      iVar4 = FUN_1c0f3d60(piVar5,param_1[2]);
      if (-1 < iVar4) {
        FUN_1c0f3a94(piVar5,uVar6);
        return;
      }
    }
  }
  return;
}


