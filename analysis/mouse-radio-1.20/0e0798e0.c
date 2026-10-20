/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0798e0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0798e0(void)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint local_30;
  int iStack_2c;
  
  piVar5 = &DAT_0e0991b8;
  DAT_23007744 = 0;
  do {
    iVar2 = FUN_0e094560(*piVar5);
    if (iVar2 == 0) {
      return 0xfffffffa;
    }
    iVar6 = *piVar5;
    iVar7 = piVar5[1];
    iVar2 = piVar5[3];
    uVar8 = piVar5[2];
    iVar3 = (**(code **)(*(int *)(iVar6 + 8) + 4))(iVar6,iVar7,&local_30);
    if ((-1 < iVar3) &&
       (lVar1 = (ulonglong)local_30 * (ulonglong)uVar8,
       uVar8 = uVar8 * iStack_2c + (int)((ulonglong)lVar1 >> 0x20),
       uVar4 = FUN_0e0795d8((int)lVar1,uVar8,1000000000,0), uVar8 < 1000000000)) {
      (*(code *)**(undefined4 **)(iVar6 + 8))(iVar6,iVar7,uVar4,0,(short)iVar2);
    }
    piVar5 = piVar5 + 4;
  } while (piVar5 != (int *)&DAT_0e0991e8);
  DAT_23007744 = 1;
  return 0;
}


