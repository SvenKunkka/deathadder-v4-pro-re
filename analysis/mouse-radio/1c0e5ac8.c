/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e5ac8. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0e5ac8(void)

{
  longlong lVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  uint local_30;
  int iStack_2c;
  
  piVar6 = DAT_1c0e5b6c;
  puVar2 = DAT_1c0e5b68;
  piVar10 = DAT_1c0e5b6c + 0xc;
  *DAT_1c0e5b68 = 0;
  do {
    iVar3 = FUN_1c100688(*piVar6);
    if (iVar3 == 0) {
      return 0xfffffffa;
    }
    iVar7 = *piVar6;
    iVar8 = piVar6[1];
    iVar3 = piVar6[3];
    uVar9 = piVar6[2];
    iVar4 = (**(code **)(*(int *)(iVar7 + 8) + 4))(iVar7,iVar8,&local_30);
    if ((-1 < iVar4) &&
       (lVar1 = (ulonglong)local_30 * (ulonglong)uVar9,
       uVar9 = uVar9 * iStack_2c + (int)((ulonglong)lVar1 >> 0x20),
       uVar5 = FUN_1c0e57c0((int)lVar1,uVar9,DAT_1c0e5b60,DAT_1c0e5b64), uVar9 <= DAT_1c0e5b70)) {
      (*(code *)**(undefined4 **)(iVar7 + 8))(iVar7,iVar8,uVar5,0,(short)iVar3);
    }
    piVar6 = piVar6 + 4;
  } while (piVar10 != piVar6);
  *puVar2 = 1;
  return 0;
}


