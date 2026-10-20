/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e076440. Types and names are inferred; NOT original source. */

void FUN_0e076440(int *param_1,uint param_2,undefined4 param_3,uint param_4,char param_5)

{
  uint uVar1;
  
  uVar1 = 0x10000 << (param_2 & 0xff);
  *(uint *)(*param_1 + 0x200) = *(uint *)(*param_1 + 0x200) & ~(uVar1 | 1 << (param_2 & 0xff));
  *(uint *)(*param_1 + 0x200) = *(uint *)(*param_1 + 0x200) | param_4;
  if (param_5 == '\0') {
    *(uint *)(*param_1 + 0x308) = uVar1;
  }
  else {
    *(undefined4 *)(*param_1 + param_2 * 4 + 0x140) = 0;
    *(uint *)(*param_1 + 0x304) = uVar1;
  }
  *(undefined4 *)(*param_1 + (param_2 + 0x150) * 4) = param_3;
  return;
}


