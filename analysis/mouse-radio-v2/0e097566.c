/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e097566. Types and names are inferred; NOT original source. */

void FUN_0e097566(uint param_1,uint param_2,char *param_3,byte param_4)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  do {
    uVar6 = param_1 & 0xff;
    if ((param_4 & 0x1f) == 8) {
      bVar2 = (byte)param_1 & 7;
      param_1 = param_1 >> 3 | param_2 << 0x1d;
      param_2 = param_2 >> 3;
    }
    else {
      if ((param_4 & 0x1f) == 0x10) {
        uVar6 = param_1 & 0xf;
        param_1 = param_1 >> 4 | param_2 << 0x1c;
        param_2 = param_2 >> 4;
      }
      else {
        uVar3 = param_1 >> 1 | param_2 << 0x1f;
        uVar1 = param_1 >> 2 | param_2 << 0x1e;
        uVar4 = uVar3 + uVar1;
        uVar3 = (param_2 >> 2) + (param_2 >> 1) + (uint)CARRY4(uVar3,uVar1);
        uVar1 = uVar4 >> 4 | uVar3 * 0x10000000;
        uVar5 = uVar4 + uVar1;
        uVar3 = uVar3 + (uVar3 >> 4) + (uint)CARRY4(uVar4,uVar1);
        uVar1 = uVar5 >> 8 | uVar3 * 0x1000000;
        uVar4 = uVar5 + uVar1;
        uVar3 = uVar3 + (uVar3 >> 8) + (uint)CARRY4(uVar5,uVar1);
        uVar1 = uVar4 >> 0x10 | uVar3 * 0x10000;
        uVar5 = uVar4 + uVar1;
        uVar3 = uVar3 + (uVar3 >> 0x10) + (uint)CARRY4(uVar4,uVar1);
        param_2 = uVar3 + CARRY4(uVar5,uVar3);
        param_1 = uVar5 + uVar3 >> 3 | param_2 * 0x20000000;
        param_2 = param_2 >> 3;
        uVar6 = uVar6 + param_1 * -10;
        uVar1 = uVar6 & 0xff;
        bVar2 = (byte)uVar6;
        if (uVar1 < 10) goto LAB_0e0975ee;
        bVar7 = 0xfffffffe < param_1;
        param_1 = param_1 + 1;
        param_2 = param_2 + bVar7;
        uVar6 = uVar1 - 10 & 0xff;
      }
      bVar2 = (byte)uVar6;
      if (9 < uVar6) {
        bVar2 = bVar2 + ('7' - param_4);
      }
    }
LAB_0e0975ee:
    *param_3 = bVar2 + 0x30;
    param_3 = param_3 + 1;
    if (param_1 == 0 && param_2 == 0) {
      return;
    }
  } while( true );
}


