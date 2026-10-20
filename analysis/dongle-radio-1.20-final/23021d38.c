/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021d38. Types and names are inferred; NOT original source. */

void FUN_23021d38(void)

{
  uint uVar1;
  undefined4 in_r3;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  thunk_FUN_0e06f3aa(&DAT_230033e8,0,0x2e8c,in_r3,in_r3);
  thunk_FUN_0e06f3aa(&DAT_23003230,0,0x1b8);
  thunk_FUN_0e06f3aa(&DAT_230030a8,0,0x188);
  puVar2 = &DAT_2300349f;
  do {
    uVar1 = uVar3 & 0xffff;
    *(undefined4 *)((int)puVar2 + -0xb7) = 0;
    *(undefined4 *)((int)puVar2 + -0x37) = 0;
    *puVar2 = 0xffffffff;
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[3] = 0xffffffff;
    uVar3 = uVar3 + 1;
    FUN_2302083c(uVar1);
    puVar2 = puVar2 + 0x3e1;
  } while (uVar3 != 3);
  return;
}


