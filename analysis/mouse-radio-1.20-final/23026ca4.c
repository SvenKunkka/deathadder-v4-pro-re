/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23026ca4. Types and names are inferred; NOT original source. */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23026ca4(void)

{
  byte bVar1;
  ushort uVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  uint uVar8;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  uint uVar9;
  uint local_38;
  ushort local_34;
  undefined1 local_28;
  char cStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  ushort uStack_24;
  undefined2 local_22;
  undefined2 uStack_20;
  undefined2 local_1e;
  undefined2 uStack_1c;
  undefined2 local_1a;
  
  FUN_2302807c();
  if (DAT_23007723 == '\x04') {
    if (DAT_230076d2 != 0) {
      uStack_1c = (undefined2)unaff_r5;
      local_1a = (undefined2)((uint)unaff_r5 >> 0x10);
      uStack_20 = (undefined2)unaff_r4;
      local_1e = (undefined2)((uint)unaff_r4 >> 0x10);
      pbVar7 = (byte *)0x230018a0;
      if ((DAT_23006bac & 1) == 0) {
        pbVar7 = &DAT_23001880;
      }
      if ((DAT_23006bb4 < 2) && ((DAT_230076d2 & 7) != 0)) {
        uVar8 = (uint)DAT_23006730._1_1_;
        uVar9 = (uint)DAT_23007789;
        uVar5 = (uint)(short)DAT_230076d6;
        *pbVar7 = (byte)DAT_23006730 | DAT_230066e0 | (byte)DAT_230076b8 & 0x3f;
        uVar2 = DAT_230076d4;
        *(uint *)(pbVar7 + 3) =
             uVar8 + uVar9 & 0xff | (uVar5 & 0xff) << 8 | ((int)uVar5 >> 8 & 0xffU) << 0x10 |
             (int)(short)DAT_230076d4 << 0x18;
        bVar1 = DAT_23006bb4;
        pbVar7[7] = (byte)(uVar2 >> 8);
        if (bVar1 < 2) {
          DAT_23006bb4 = DAT_23006bb4 + 1;
        }
        iVar4 = thunk_FUN_0e08d04c(&PTR_s_hid_dev_0_0e097958,8);
        if (iVar4 == 0) {
          DAT_23007789 = 0;
          DAT_230076d2 = DAT_230076d2 & 0xfff8;
          DAT_230076d4 = 0;
          DAT_23006bac = DAT_23006bac ^ 1;
          DAT_23006730 = 0;
          DAT_23006734 = 0;
          DAT_230076d6 = DAT_230076d4;
        }
        else if (DAT_23006bb4 != 0) {
          DAT_23006bb4 = DAT_23006bb4 - 1;
        }
      }
      if ((DAT_23006bba == '\0') && ((int)((uint)DAT_230076d2 << 0x1c) < 0)) {
        DAT_23006ba4 = _DAT_23006720;
        DAT_23006ba8 = DAT_23006724;
        iVar4 = thunk_FUN_0e08d04c(&PTR_s_hid_dev_2_0e097930,8,&DAT_23006ba4);
        if (iVar4 == 0) {
          DAT_23006bba = '\x01';
          DAT_230076d2 = DAT_230076d2 & 0xfff7;
          DAT_23006bbe = 5;
        }
      }
      if ((DAT_23006bb8._1_1_ == '\0') && (uVar8 = (uint)DAT_230076d2, (DAT_230076d2 & 0xf0) != 0))
      {
        if ((int)(uVar8 << 0x19) < 0) {
          DAT_23006b94 = (undefined1)DAT_230066f0;
          DAT_23006b95 = (char)((uint)DAT_230066f0 >> 8);
          DAT_23006b96._0_1_ = (undefined1)((uint)DAT_230066f0 >> 0x10);
          DAT_23006b96._1_1_ = (undefined1)((uint)DAT_230066f0 >> 0x18);
          DAT_23006b96._2_2_ = (ushort)DAT_230066f4;
          DAT_23006b9a._0_2_ = (undefined2)((uint)DAT_230066f4 >> 0x10);
          DAT_23006b9a._2_2_ = (ushort)DAT_230066f8;
          DAT_23006b9e._0_2_ = (undefined2)((uint)DAT_230066f8 >> 0x10);
          DAT_23006b9e._2_2_ = (ushort)DAT_230066fc;
          DAT_23006ba2 = (undefined2)((uint)DAT_230066fc >> 0x10);
          iVar4 = thunk_FUN_0e08d04c(&PTR_s_hid_dev_1_0e097944,0x10,&DAT_23006b94);
          if (iVar4 == 0) {
            DAT_23006bb8._1_1_ = '\x01';
            DAT_230076d2 = DAT_230076d2 & 0xffbf;
            DAT_23006bbc._1_1_ = 5;
          }
        }
        else if ((int)(uVar8 << 0x1b) < 0) {
          DAT_23006b94 = (undefined1)_DAT_23006710;
          DAT_23006b95 = (char)((uint)_DAT_23006710 >> 8);
          DAT_23006b96._0_1_ = (undefined1)((uint)_DAT_23006710 >> 0x10);
          DAT_23006b96._1_1_ = (undefined1)((uint)_DAT_23006710 >> 0x18);
          DAT_23006b96._2_2_ = (ushort)DAT_23006714;
          DAT_23006b9a._0_2_ = (undefined2)((uint)DAT_23006714 >> 0x10);
          DAT_23006b9a._2_2_ = (ushort)DAT_23006718;
          DAT_23006b9e._0_2_ = (undefined2)((uint)DAT_23006718 >> 0x10);
          DAT_23006b9e._2_2_ = (ushort)DAT_2300671c;
          DAT_23006ba2 = (undefined2)((uint)DAT_2300671c >> 0x10);
          iVar4 = thunk_FUN_0e08d04c(&PTR_s_hid_dev_1_0e097944,0x10,&DAT_23006b94);
          if (iVar4 == 0) {
            DAT_23006bb8._1_1_ = '\x01';
            DAT_230076d2 = DAT_230076d2 & 0xffef;
            DAT_23006bbc._1_1_ = 5;
          }
        }
        else if ((DAT_230076d2 & 0x20) == 0) {
          if ((int)(uVar8 << 0x18) < 0) {
            DAT_23006b94 = 5;
            DAT_2300771e = *(char *)((int)&DAT_23004a98 + (uint)DAT_2300771b);
            DAT_2300771d = *(undefined1 *)((int)&DAT_23004a90 + (uint)DAT_2300771b);
            DAT_23006b96._0_1_ = (undefined1)(uVar8 & 0x20);
            DAT_23006b96._1_1_ = 0;
            DAT_23006b96._2_2_ = 0;
            DAT_23006b9a._2_2_ = DAT_23006b96._2_2_;
            DAT_23006b9a._0_2_ = (undefined2)(uVar8 & 0x20);
            DAT_23006ba2 = (undefined2)DAT_23006b9a;
            DAT_23006b95 = DAT_2300771e;
            DAT_23006b9e._0_2_ = (undefined2)DAT_23006b9a;
            DAT_23006b9e._2_2_ = DAT_23006b9a._2_2_;
            if (DAT_2300771e == '\x02') {
              if (DAT_23007766 == '\x01') {
                puVar6 = (undefined4 *)&DAT_23004a88;
              }
              else {
                puVar6 = &DAT_23004a8c;
              }
              DAT_23006b96._1_1_ = (undefined1)*(undefined2 *)puVar6;
              DAT_23006b96._2_2_ =
                   *(ushort *)((int)puVar6 + 2) >> 8 |
                   (ushort)(((uint)*(ushort *)((int)puVar6 + 2) << 0x18) >> 0x10);
              DAT_23006b96._0_1_ = (undefined1)((ushort)*(undefined2 *)puVar6 >> 8);
              uVar3 = (undefined1)DAT_23006b96;
            }
            else {
              uVar3 = DAT_2300771d;
              if (DAT_2300771e != '\n') {
                if (DAT_2300771e == '1') {
                  DAT_23006b94 = (undefined1)_DAT_23004aa0;
                  DAT_23006b95 = (char)((uint)_DAT_23004aa0 >> 8);
                  DAT_23006b96._0_1_ = (undefined1)((uint)_DAT_23004aa0 >> 0x10);
                  DAT_23006b96._1_1_ = (undefined1)((uint)_DAT_23004aa0 >> 0x18);
                  DAT_23006b96._2_2_ = (ushort)ram0x23004aa4;
                  DAT_23006b9a._0_2_ = (undefined2)((uint)ram0x23004aa4 >> 0x10);
                  DAT_23006b9a._2_2_ = (ushort)ram0x23004aa8;
                  DAT_23006b9e._0_2_ = (undefined2)((uint)ram0x23004aa8 >> 0x10);
                  DAT_23006b9e._2_2_ = (ushort)ram0x23004aac;
                  DAT_23006ba2 = (undefined2)((uint)ram0x23004aac >> 0x10);
                  uVar3 = (undefined1)DAT_23006b96;
                }
                else {
                  if (DAT_2300771e != '\t') {
                    DAT_23006b94 = 5;
                    DAT_23006b96._1_1_ = 0;
                    DAT_23006b96._2_2_ = 0;
                    DAT_23006b9a._2_2_ = 0;
                    DAT_23006b9e._0_2_ = (undefined2)DAT_23006b9a;
                    DAT_23006b9e._2_2_ = 0;
                    DAT_23006ba2 = (undefined2)DAT_23006b9a;
                    DAT_230076d2 = DAT_230076d2 & 0xff7f;
                    return;
                  }
                  DAT_23006b96._1_1_ = 1;
                }
              }
            }
            DAT_23006b96._0_1_ = uVar3;
            iVar4 = thunk_FUN_0e08d04c(&PTR_s_hid_dev_1_0e097944,0x10,&DAT_23006b94);
            if (iVar4 == 0) {
              DAT_23006bb8._1_1_ = '\x01';
              DAT_2300771b = DAT_2300771b + 1;
              DAT_23006bbc._1_1_ = 5;
              if (DAT_2300771c <= DAT_2300771b) {
                DAT_2300771c = 0;
                DAT_230076d2 = DAT_230076d2 & 0xff7f;
                DAT_2300771b = 0;
                DAT_23004a90 = 0;
                DAT_23004a94 = 0;
                DAT_23004a98 = 0;
                DAT_23004a9c = 0;
              }
            }
          }
        }
        else {
          DAT_23006b94 = (undefined1)_DAT_23006700;
          DAT_23006b95 = (char)((uint)_DAT_23006700 >> 8);
          DAT_23006b96._0_1_ = (undefined1)((uint)_DAT_23006700 >> 0x10);
          DAT_23006b96._1_1_ = (undefined1)((uint)_DAT_23006700 >> 0x18);
          DAT_23006b96._2_2_ = (ushort)DAT_23006704;
          DAT_23006b9a._0_2_ = (undefined2)((uint)DAT_23006704 >> 0x10);
          DAT_23006b9a._2_2_ = (ushort)DAT_23006708;
          DAT_23006b9e._0_2_ = (undefined2)((uint)DAT_23006708 >> 0x10);
          DAT_23006b9e._2_2_ = (ushort)DAT_2300670c;
          DAT_23006ba2 = (undefined2)((uint)DAT_2300670c >> 0x10);
          iVar4 = thunk_FUN_0e08d04c(&PTR_s_hid_dev_1_0e097944,0x10,&DAT_23006b94);
          if (iVar4 == 0) {
            DAT_23006bb8._1_1_ = '\x01';
            DAT_230076d2 = DAT_230076d2 & 0xffdf;
            DAT_23006bbc._1_1_ = 5;
          }
        }
      }
      return;
    }
  }
  else if ((DAT_23007723 == '\x01') && (DAT_230076d2 != 0)) {
    if (((DAT_230076d2 & 7) != 0 || (DAT_230076d6 != 0 || DAT_230076d4 != 0)) || (DAT_23007789 != 0)
       ) {
      local_38 = (uint)((byte)DAT_23006730 | DAT_230066e0) | DAT_230076b8 & 0x3f |
                 (uint)(byte)(DAT_23007789 + DAT_23006730._1_1_) << 8 |
                 ((int)(short)DAT_230076d6 >> 8 & 0xffU) << 0x10 | (int)(short)DAT_230076d6 << 0x18;
      local_34 = DAT_230076d4 << 8 | DAT_230076d4 >> 8;
      FUN_2302125c(1,&local_38,6);
      DAT_230076d2 = DAT_230076d2 & 0xfff8;
      DAT_23007789 = 0;
      DAT_230076d4 = 0;
      DAT_230076d6 = 0;
      DAT_23006730 = 0;
      DAT_23006734 = 0;
      DAT_230076c8 = 0;
    }
    if (DAT_2300777f != '\0') {
      uVar8 = (uint)DAT_230076d2;
      if ((int)(uVar8 << 0x1c) < 0) {
        FUN_2302125c(2,&DAT_23006720,8);
        DAT_230076d2 = DAT_230076d2 & 0xfff7;
        uVar8 = (uint)DAT_230076d2;
      }
      if ((int)(uVar8 << 0x19) < 0) {
        FUN_2302125c(4,&DAT_230066f0,0x10);
        DAT_230076d2 = DAT_230076d2 & 0xffbf;
        uVar8 = (uint)DAT_230076d2;
      }
      if (((int)(uVar8 << 0x18) < 0) && (uVar5 = (uint)DAT_2300771b, DAT_2300771c != uVar5)) {
        local_28 = 5;
        DAT_2300771e = *(char *)((int)&DAT_23004a98 + uVar5);
        DAT_2300771d = *(undefined1 *)((int)&DAT_23004a90 + uVar5);
        local_1a = 0;
        uStack_26 = 0;
        uStack_25 = 0;
        uStack_24 = 0;
        local_22 = 0;
        uStack_20 = 0;
        local_1e = 0;
        uStack_1c = 0;
        cStack_27 = DAT_2300771e;
        if (DAT_2300771e == '\x02') {
          if (DAT_23007766 == '\x01') {
            puVar6 = (undefined4 *)&DAT_23004a88;
          }
          else {
            puVar6 = &DAT_23004a8c;
          }
          uStack_25 = (undefined1)*(undefined2 *)puVar6;
          uStack_24 = *(ushort *)((int)puVar6 + 2) >> 8 |
                      (ushort)(((uint)*(ushort *)((int)puVar6 + 2) << 0x18) >> 0x10);
          uStack_26 = (undefined1)((ushort)*(undefined2 *)puVar6 >> 8);
          uVar3 = uStack_26;
        }
        else {
          uVar3 = DAT_2300771d;
          if (((DAT_2300771e != '\n') && (uVar3 = DAT_2300771d, DAT_2300771e != '\x01')) &&
             (uVar3 = uStack_26, DAT_2300771e == '1')) {
            local_28 = (undefined1)_DAT_23004aa0;
            cStack_27 = (char)((uint)_DAT_23004aa0 >> 8);
            uStack_26 = (undefined1)((uint)_DAT_23004aa0 >> 0x10);
            uStack_25 = (undefined1)((uint)_DAT_23004aa0 >> 0x18);
            uStack_24 = (ushort)unique0x10000325;
            local_22 = (undefined2)((uint)unique0x10000325 >> 0x10);
            uStack_20 = (undefined2)unique0x10000329;
            local_1e = (undefined2)((uint)unique0x10000329 >> 0x10);
            uStack_1c = (undefined2)unique0x1000032d;
            local_1a = (undefined2)((uint)unique0x1000032d >> 0x10);
            uVar3 = uStack_26;
          }
        }
        uStack_26 = uVar3;
        FUN_2302125c(4,&local_28);
        DAT_2300771b = DAT_2300771b + 1;
        if (7 < DAT_2300771b) {
          DAT_2300771b = 0;
        }
        uVar8 = (uint)DAT_230076d2;
        if (DAT_2300771c <= DAT_2300771b) {
          uVar8 = uVar8 & 0xffffff7f;
          DAT_230076d2 = (ushort)uVar8;
        }
      }
      if ((int)(uVar8 << 0x1a) < 0) {
        FUN_2302125c(4,&DAT_23006700,0x10);
        DAT_230076d2 = DAT_230076d2 & 0xffdf;
        uVar8 = (uint)DAT_230076d2;
      }
      if ((int)(uVar8 << 0x1b) < 0) {
        FUN_2302125c(4,&DAT_23006710,0x10);
        DAT_230076d2 = DAT_230076d2 & 0xffef;
        return;
      }
    }
    return;
  }
  return;
}


