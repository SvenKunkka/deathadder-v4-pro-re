/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07506c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e07506c(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
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
  
  if (((DAT_230076d2 & 7) != 0 || (DAT_230076d6 != 0 || DAT_230076d4 != 0)) ||
     (DAT_23007789 != '\0')) {
    local_38 = (uint)((byte)DAT_23006730 | DAT_230066e0) | DAT_230076b8 & 0x3f |
               (uint)(byte)(DAT_23007789 + DAT_23006730._1_1_) << 8 |
               ((int)DAT_230076d6 >> 8 & 0xffU) << 0x10 | (int)DAT_230076d6 << 0x18;
    local_34 = DAT_230076d4 << 8 | DAT_230076d4 >> 8;
    FUN_0e06d9f8(1,&local_38,6);
    DAT_230076d2 = DAT_230076d2 & 0xfff8;
    DAT_23007789 = '\0';
    DAT_230076d4 = 0;
    DAT_230076d6 = 0;
    DAT_23006730 = 0;
    DAT_23006734 = 0;
    DAT_230076c8 = 0;
  }
  if (DAT_2300777f != '\0') {
    uVar4 = (uint)DAT_230076d2;
    if ((int)(uVar4 << 0x1c) < 0) {
      FUN_0e06d9f8(2,&DAT_23006720,8);
      DAT_230076d2 = DAT_230076d2 & 0xfff7;
      uVar4 = (uint)DAT_230076d2;
    }
    if ((int)(uVar4 << 0x19) < 0) {
      FUN_0e06d9f8(4,&DAT_230066f0,0x10);
      DAT_230076d2 = DAT_230076d2 & 0xffbf;
      uVar4 = (uint)DAT_230076d2;
    }
    if (((int)(uVar4 << 0x18) < 0) && (uVar2 = (uint)DAT_2300771b, DAT_2300771c != uVar2)) {
      local_28 = 5;
      DAT_2300771e = (&DAT_23004a98)[uVar2];
      DAT_2300771d = (&DAT_23004a90)[uVar2];
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
          puVar3 = (undefined4 *)&DAT_23004a88;
        }
        else {
          puVar3 = &DAT_23004a8c;
        }
        uStack_25 = (undefined1)*(undefined2 *)puVar3;
        uStack_24 = *(ushort *)((int)puVar3 + 2) >> 8 |
                    (ushort)(((uint)*(ushort *)((int)puVar3 + 2) << 0x18) >> 0x10);
        uStack_26 = (undefined1)((ushort)*(undefined2 *)puVar3 >> 8);
        uVar1 = uStack_26;
      }
      else {
        uVar1 = DAT_2300771d;
        if (((DAT_2300771e != '\n') && (uVar1 = DAT_2300771d, DAT_2300771e != '\x01')) &&
           (uVar1 = uStack_26, DAT_2300771e == '1')) {
          local_28 = (undefined1)_DAT_23004aa0;
          cStack_27 = (char)((uint)_DAT_23004aa0 >> 8);
          uStack_26 = (undefined1)((uint)_DAT_23004aa0 >> 0x10);
          uStack_25 = (undefined1)((uint)_DAT_23004aa0 >> 0x18);
          uStack_24 = (ushort)unique0x1000015d;
          local_22 = (undefined2)((uint)unique0x1000015d >> 0x10);
          uStack_20 = (undefined2)unique0x10000161;
          local_1e = (undefined2)((uint)unique0x10000161 >> 0x10);
          uStack_1c = (undefined2)unique0x10000165;
          local_1a = (undefined2)((uint)unique0x10000165 >> 0x10);
          uVar1 = uStack_26;
        }
      }
      uStack_26 = uVar1;
      FUN_0e06d9f8(4,&local_28);
      DAT_2300771b = DAT_2300771b + 1;
      if (7 < DAT_2300771b) {
        DAT_2300771b = 0;
      }
      uVar4 = (uint)DAT_230076d2;
      if (DAT_2300771c <= DAT_2300771b) {
        uVar4 = uVar4 & 0xffffff7f;
        DAT_230076d2 = (ushort)uVar4;
      }
    }
    if ((int)(uVar4 << 0x1a) < 0) {
      FUN_0e06d9f8(4,&DAT_23006700,0x10);
      DAT_230076d2 = DAT_230076d2 & 0xffdf;
      uVar4 = (uint)DAT_230076d2;
    }
    if ((int)(uVar4 << 0x1b) < 0) {
      FUN_0e06d9f8(4,&DAT_23006710,0x10);
      DAT_230076d2 = DAT_230076d2 & 0xffef;
      return;
    }
  }
  return;
}


