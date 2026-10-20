/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230256e8. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_230256e8(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 extraout_r1;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *extraout_r2;
  uint *puVar7;
  short sVar8;
  uint extraout_r3;
  uint *unaff_r5;
  uint unaff_r6;
  bool bVar9;
  undefined4 local_3c [10];
  
  if (DAT_230065b4._2_2_ == 0) goto LAB_2302576c;
  DAT_230065b4._2_2_ = DAT_230065b4._2_2_ + -1;
  if (DAT_230065b4._2_2_ != 0) goto LAB_2302576c;
  unaff_r6 = (uint)DAT_230065e0;
  DAT_230065b4._2_2_ = (short)DAT_230065b4;
  puVar1 = &DAT_230065dc;
  puVar6 = &DAT_230065b4;
  unaff_r5 = &DAT_230065bc;
  DAT_230065c8 = 0;
LAB_23025712:
  do {
    puVar7 = puVar6 + 1;
    uVar3 = 0;
    if (*puVar7 == 0) goto LAB_230257d2;
    uVar4 = *puVar7 / puVar6[3];
    uVar5 = uVar4 & 0xff;
    puVar1[-4] = (char)uVar4;
    puVar6 = puVar7;
    if (unaff_r6 == 0) {
      if (uVar5 == 0) goto LAB_230257da;
      if (DAT_23002da8._2_1_ < uVar5) {
        if (DAT_23002da8._3_1_ < uVar5) {
          if ((byte)DAT_23002dac < uVar5) {
            *puVar1 = 1;
          }
          else {
            *puVar1 = 2;
          }
        }
        else {
          *puVar1 = 3;
        }
      }
      else {
        *puVar1 = 4;
      }
    }
    while( true ) {
      *puVar6 = DAT_230065c8;
      puVar6[2] = DAT_230065c8;
      puVar1 = puVar1 + 1;
      if (puVar6 != unaff_r5) break;
      while( true ) {
        DAT_230065cc = DAT_230065c8;
        DAT_230065d0 = DAT_230065c8;
        DAT_230065d4 = DAT_230065c8;
        if (_DAT_230065dc != DAT_230065de) {
          if (DAT_23006590 != 0) {
            FUN_230203fc(2,&DAT_230065dc);
          }
          DAT_230065de = _DAT_230065dc;
        }
LAB_2302576c:
        if ((ushort)DAT_230065e2 != 0) {
          DAT_230065e2._0_2_ = (ushort)DAT_230065e2 - 1;
          unaff_r5 = (uint *)(uint)(ushort)DAT_230065e2;
          if (unaff_r5 == (uint *)0x0) {
            DAT_230065e2._2_2_ = 5;
            DAT_23006590 = (ushort)DAT_230065e2;
            thunk_FUN_0e06ec54(&DAT_23001a30);
            FUN_230201b4(1,0);
          }
        }
        if (((DAT_23006595 == '\0') && (DAT_230065e2._2_2_ != 0)) &&
           (sVar8 = DAT_230065e2._2_2_ + -1, bVar9 = DAT_230065e2._2_2_ == 1,
           DAT_230065e2._2_2_ = sVar8, bVar9)) {
          unaff_r5 = (uint *)&DAT_23001bb4;
          local_3c[0] = 4;
          while (iVar2 = thunk_FUN_0e06cbdc(&DAT_23001bb4,local_3c,0,0), iVar2 != 0) {
            thunk_FUN_0e06cd54(&DAT_23001bb4);
          }
        }
        if ((DAT_23006590 == 0) ||
           ((DAT_230065e6 != 0 &&
            (sVar8 = DAT_230065e6 + -1, bVar9 = DAT_230065e6 != 1, DAT_230065e6 = sVar8, bVar9)))) {
          return;
        }
        puVar1 = (undefined1 *)thunk_FUN_0e05d698(0);
        puVar7 = extraout_r2;
        DAT_230065c8 = extraout_r3;
        uVar3 = extraout_r1;
LAB_230257d2:
        puVar1[-4] = uVar3;
        puVar6 = puVar7;
        if (unaff_r6 != 0) break;
LAB_230257da:
        *puVar1 = 0;
        *puVar6 = DAT_230065c8;
        puVar6[2] = DAT_230065c8;
        puVar1 = puVar1 + 1;
        if (puVar6 != unaff_r5) goto LAB_23025712;
      }
    }
  } while( true );
}


