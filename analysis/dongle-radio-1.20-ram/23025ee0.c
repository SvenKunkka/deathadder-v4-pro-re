/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025ee0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_23025ee0(void)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint local_30;
  int iStack_2c;
  
  _DAT_23002cb4 = DAT_23002d90._1_2_;
  DAT_23002cb6 = DAT_23002d90._3_1_;
  DAT_23006c7c = DAT_23006c7c & 0xffffffef;
  FUN_0e067700(&PTR_s_gpio_938000_0e06f5dc,4,0x60000);
  piVar7 = &DAT_0e06f968;
  do {
    iVar11 = 0;
    piVar6 = piVar7;
    do {
      iVar2 = thunk_FUN_0e06c6c0(*piVar6);
      if (iVar2 == 0) {
        return 0xfffffffa;
      }
      iVar9 = *piVar6;
      iVar10 = piVar6[1];
      uVar8 = piVar6[2];
      iVar2 = piVar6[3];
      iVar3 = (**(code **)(*(int *)(iVar9 + 8) + 4))(iVar9,iVar10,&local_30);
      if ((-1 < iVar3) &&
         (lVar1 = (ulonglong)local_30 * (ulonglong)uVar8,
         uVar8 = uVar8 * iStack_2c + (int)((ulonglong)lVar1 >> 0x20),
         uVar4 = thunk_FUN_0e05ba10((int)lVar1,uVar8,1000000000,0), uVar8 < 1000000000)) {
        (*(code *)**(undefined4 **)(iVar9 + 8))(iVar9,iVar10,uVar4,0,(short)iVar2);
      }
      iVar11 = iVar11 + 4;
      piVar6 = piVar6 + 4;
    } while (iVar11 != 0xc);
    piVar7 = piVar7 + 0xc;
  } while (piVar7 != &DAT_0e06f9f8);
  if ((int)(DAT_23006c7c << 0x1b) < 0) {
    pcVar5 = (code *)0xe0679b1;
  }
  else {
    pcVar5 = (code *)0xe06796d;
  }
  (*pcVar5)(&PTR_s_gpio_938000_0e06f5dc,0x10);
  return 0;
}


