/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020250. Types and names are inferred; NOT original source. */

void FUN_23020250(uint param_1,byte *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_18;
  int iStack_14;
  
  if (DAT_23002c82 == 1) {
    switch(param_1) {
    case 1:
      if (DAT_23002c88 == '\x01') {
        *param_2 = (byte)DAT_23002c8a | *param_2;
        param_2[1] = param_2[1] + DAT_23002c8a._2_1_;
        param_2[2] = param_2[2] + DAT_23002c8a._3_1_;
        *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + (short)DAT_23002c8e;
        *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + DAT_23002c8e._2_2_;
        param_2[3] = param_2[3] + DAT_23002c8a._1_1_;
        DAT_23002c88 = '\0';
        uRam23002c89 = 0;
        DAT_23002c8a._0_1_ = 0;
        DAT_23002c8a._1_1_ = '\0';
        DAT_23002c8a._2_1_ = '\0';
        DAT_23002c8a._3_1_ = '\0';
        DAT_23002c8e._0_2_ = 0;
        DAT_23002c8e._2_2_ = 0;
      }
      iVar1 = FUN_230268b0(1,param_2,param_3 & 0xff);
      if (iVar1 == 0) {
        uVar2 = *(undefined4 *)param_2;
        DAT_23002c8a._0_1_ = (byte)uVar2;
        DAT_23002c8a._1_1_ = (char)((uint)uVar2 >> 8);
        DAT_23002c8a._2_1_ = (char)((uint)uVar2 >> 0x10);
        DAT_23002c8a._3_1_ = (char)((uint)uVar2 >> 0x18);
        DAT_23002c88 = '\x01';
        DAT_23002c8e._0_2_ = (short)*(undefined4 *)(param_2 + 4);
        DAT_23002c8e._2_2_ = (short)((uint)*(undefined4 *)(param_2 + 4) >> 0x10);
      }
      break;
    case 2:
      FUN_230268b0(2,param_2,param_3 & 0xff);
      return;
    case 3:
      if (*param_2 == 0xb1) {
        DAT_230071b5 = param_2[6];
        DAT_230071b6 = param_2[7];
        DAT_230071b4 = param_2[5];
        FUN_23025b40(0xe1);
        FUN_23025b40(0xe2,DAT_230071b5);
        FUN_23025b40(0xe3,DAT_230071b6);
        DAT_230071b8 = 1;
        DAT_2300341c = (ushort)DAT_230071b4;
        return;
      }
      break;
    case 4:
      FUN_230268b0(4,param_2,param_3 & 0xff);
      if (param_2[1] == 0x31) {
        DAT_230071b6 = param_2[2];
        FUN_23025b40(0xe3);
        return;
      }
      break;
    case 5:
      if (*param_2 == 0x5a) {
        thunk_FUN_0e06f35c(&DAT_23002d1c,param_2 + 2,param_3 - 2);
        DAT_23002d74 = param_2[1];
      }
    }
  }
  else {
    iVar1 = FUN_23020160(0,param_1 & 0xff,param_2);
    if ((iVar1 != 0) && (local_18 = FUN_23026ad8(), local_18 == 0)) {
      FUN_23026928(1);
      iStack_14 = local_18;
      FUN_230268b0(1,&local_18,8);
    }
  }
  return;
}


