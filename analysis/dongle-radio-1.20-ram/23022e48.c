/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23022e48. Types and names are inferred; NOT original source. */

void FUN_23022e48(uint param_1)

{
  undefined4 uVar1;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  
  if (2 < (uint)(&DAT_230033e8)[param_1 * 0x3e1]) {
    if (99 < (ushort)(&DAT_23003470)[param_1 * 0x7c2]) {
      FUN_23020f1c(&DAT_23003468 + param_1 * 0x3e1,&RADIO_S_TASKS_DISABLE,0);
      (&DAT_230033e8)[param_1 * 0x3e1] = 0;
      (&DAT_23003468)[param_1 * 0x3e1] = 0xb;
      FUN_23021dfc(param_1 & 0xff);
      FUN_230221a4(param_1 & 0xff);
      local_1c = *(undefined2 *)(&DAT_230033f2 + param_1 * 0x3e1);
      local_1a = *(undefined2 *)((int)&DAT_230033f2 + param_1 * 0xf84 + 2);
      local_20 = (undefined2)param_1;
      local_1e = 0;
      FUN_230254f8(&local_20);
      return;
    }
    if ((uint)(&DAT_23003474)[param_1 * 0x3e1] < 200) {
      uVar1 = 3;
    }
    else {
      uVar1 = 4;
    }
    (&DAT_230033e8)[param_1 * 0x3e1] = uVar1;
  }
  return;
}


