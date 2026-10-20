/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23025ab0. Types and names are inferred; NOT original source. */

uint FUN_23025ab0(undefined4 param_1,uint param_2,byte *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_94;
  byte local_89;
  byte abStack_88 [32];
  byte local_68;
  undefined1 auStack_67 [67];
  
  if (param_2 < 6) {
    local_94 = param_4;
    switch(param_2) {
    case 1:
      DAT_23006b64._0_2_ =
           (*(ushort *)(param_3 + 2) << 8 | *(ushort *)(param_3 + 2) >> 8) + (short)DAT_23006b64;
      DAT_23006b64._2_2_ =
           (*(ushort *)(param_3 + 4) << 8 | *(ushort *)(param_3 + 4) >> 8) + DAT_23006b64._2_2_;
      DAT_23006b60._1_1_ = DAT_23006b60._1_1_ + param_3[1];
      DAT_23006b60._0_1_ = (byte)DAT_23006b60 | *param_3;
      *param_3 = (byte)DAT_23006b60;
      param_3[1] = DAT_23006b60._1_1_;
      param_3[2] = DAT_23006b64._1_1_;
      param_3[3] = (byte)(short)DAT_23006b64;
      param_3[4] = DAT_23006b64._3_1_;
      param_3[5] = (byte)DAT_23006b64._2_2_;
      break;
    case 2:
      thunk_FUN_0e0973ea(abStack_88,0,0x20);
      thunk_FUN_0e09739c(abStack_88,param_3,param_4);
      param_3 = abStack_88;
      local_89 = 8;
      FUN_23020e44(param_3,&local_89);
      local_94 = (uint)local_89;
      break;
    case 3:
      DAT_23006b68 = 0;
      break;
    case 4:
      thunk_FUN_0e0973ea(abStack_88,0,0x20);
      thunk_FUN_0e09739c(abStack_88,param_3,param_4);
      param_3 = abStack_88;
      local_89 = 0x10;
      FUN_23020e44(param_3,&local_89);
      local_94 = (uint)local_89;
    }
    uVar1 = FUN_23021488(param_1,param_2);
    uVar6 = (local_94 + 5) / 6 - 1 & 0xffff;
    if (uVar6 < uVar1) {
      uVar4 = 0;
      uVar3 = 0;
      uVar1 = local_94;
      do {
        if (uVar3 == uVar6) {
          local_68 = 0;
          uVar3 = uVar1 + 1 & 0xffff;
          uVar5 = uVar1;
        }
        else {
          uVar3 = 7;
          local_68 = 0x80;
          uVar5 = 6;
        }
        local_68 = local_68 | (byte)uVar4;
        thunk_FUN_0e09739c(auStack_67,param_3);
        iVar2 = FUN_230215ac(param_1,param_2,&local_68,uVar3,0xff);
        uVar4 = uVar4 + 1;
        uVar3 = uVar4 & 0xffff;
      } while ((iVar2 != 0) &&
              (uVar1 = uVar1 - uVar5 & 0xffff, param_3 = param_3 + uVar5, uVar3 <= uVar6));
      if (uVar1 != 0) {
        return local_94;
      }
      if (param_2 == 1) {
        DAT_23006b60._1_1_ = 0;
        DAT_23006b60._0_1_ = 0;
        DAT_23006b64._2_2_ = 0;
        DAT_23006b64._0_2_ = 0;
      }
      return local_94;
    }
  }
  return 0;
}


