/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025ce0. Types and names are inferred; NOT original source. */

void FUN_23025ce0(int param_1,int param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint local_30;
  int iStack_2c;
  
  uVar10 = (&DAT_0e06f96c)[param_1 * 0xc];
  uVar9 = (&DAT_0e06f970)[param_1 * 0xc];
  uVar1 = (&DAT_0e06f974)[param_1 * 0x18];
  iVar7 = (&DAT_0e06f968)[param_1 * 0xc];
  iVar3 = (**(code **)(*(int *)(iVar7 + 8) + 4))(iVar7,uVar10,&local_30);
  iVar6 = iStack_2c;
  uVar5 = local_30;
  if (-1 < iVar3) {
    uVar8 = uVar9 * iStack_2c + (int)((ulonglong)uVar9 * (ulonglong)local_30 >> 0x20);
    uVar4 = thunk_FUN_0e05ba10((int)((ulonglong)uVar9 * (ulonglong)local_30),uVar8,1000000000,0);
    if ((uVar8 < 1000000000) &&
       (uVar9 = (uVar9 * param_2) / 0xff, lVar2 = (ulonglong)uVar9 * (ulonglong)uVar5,
       uVar9 = uVar9 * iVar6 + (int)((ulonglong)lVar2 >> 0x20),
       uVar5 = thunk_FUN_0e05ba10((int)lVar2,uVar9,1000000000,0), uVar9 < 1000000000)) {
      if (uVar5 <= uVar4) {
        (*(code *)**(undefined4 **)(iVar7 + 8))(iVar7,uVar10,uVar4,uVar5,uVar1);
      }
    }
  }
  iVar6 = param_1 * 0x30;
  uVar9 = *(uint *)(&DAT_0e06f980 + iVar6);
  iVar7 = (&DAT_0e06f978)[param_1 * 0xc];
  uVar10 = *(undefined4 *)(&DAT_0e06f97c + iVar6);
  uVar1 = *(undefined2 *)(&DAT_0e06f984 + iVar6);
  iVar3 = (**(code **)(*(int *)(iVar7 + 8) + 4))(iVar7,uVar10,&local_30);
  iVar6 = iStack_2c;
  uVar5 = local_30;
  if (-1 < iVar3) {
    uVar8 = uVar9 * iStack_2c + (int)((ulonglong)uVar9 * (ulonglong)local_30 >> 0x20);
    uVar4 = thunk_FUN_0e05ba10((int)((ulonglong)uVar9 * (ulonglong)local_30),uVar8,1000000000,0);
    if ((uVar8 < 1000000000) &&
       (uVar9 = (uVar9 * param_3) / 0xff, lVar2 = (ulonglong)uVar9 * (ulonglong)uVar5,
       uVar9 = uVar9 * iVar6 + (int)((ulonglong)lVar2 >> 0x20),
       uVar5 = thunk_FUN_0e05ba10((int)lVar2,uVar9,1000000000,0), uVar9 < 1000000000)) {
      if (uVar5 <= uVar4) {
        (*(code *)**(undefined4 **)(iVar7 + 8))(iVar7,uVar10,uVar4,uVar5,uVar1);
      }
    }
  }
  param_1 = param_1 * 0x30;
  uVar5 = *(uint *)(&DAT_0e06f990 + param_1);
  iVar3 = *(int *)(&DAT_0e06f988 + param_1);
  uVar10 = *(undefined4 *)(&DAT_0e06f98c + param_1);
  uVar1 = *(undefined2 *)(&DAT_0e06f994 + param_1);
  iVar6 = (**(code **)(*(int *)(iVar3 + 8) + 4))(iVar3,uVar10,&local_30);
  if (-1 < iVar6) {
    uVar4 = uVar5 * iStack_2c + (int)((ulonglong)uVar5 * (ulonglong)local_30 >> 0x20);
    uVar9 = thunk_FUN_0e05ba10((int)((ulonglong)uVar5 * (ulonglong)local_30),uVar4,1000000000,0);
    if ((uVar4 < 1000000000) &&
       (uVar5 = (uVar5 * param_4) / 0xff, lVar2 = (ulonglong)uVar5 * (ulonglong)local_30,
       uVar4 = uVar5 * iStack_2c + (int)((ulonglong)lVar2 >> 0x20),
       uVar5 = thunk_FUN_0e05ba10((int)lVar2,uVar4,1000000000,0), uVar4 < 1000000000)) {
      if (uVar5 <= uVar9) {
        (*(code *)**(undefined4 **)(iVar3 + 8))(iVar3,uVar10,uVar9,uVar5,uVar1);
      }
    }
  }
  return;
}


