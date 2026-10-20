/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e4218. Types and names are inferred; NOT original source. */

void FUN_1c0e4218(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = DAT_1c0e4300;
  iVar1 = DAT_1c0e42fc;
  *(undefined4 *)(DAT_1c0e42fc + 0x540) = 0;
  *(undefined4 *)(iVar1 + 0x544) = 0;
  *(undefined4 *)(iVar1 + 0x548) = 0;
  *(undefined4 *)(iVar1 + 0x54c) = 0;
  *(undefined4 *)(iVar1 + 0x550) = 0;
  *(undefined4 *)(iVar1 + 0x554) = 0;
  *(uint *)(iVar1 + 0x200) = *(uint *)(iVar1 + 0x200) & 0xff00ff00;
  *(undefined4 *)(iVar1 + 0x308) = 0xff0000;
  if (*(char *)(iVar2 + 3) == '\x01') {
    uVar3 = FUN_1c0e25bc(DAT_1c0e4304,0x5a);
    FUN_1c0e2444(DAT_1c0e4304,0,uVar3,0x80008,1);
    uVar3 = FUN_1c0e25bc(DAT_1c0e4304,0xd7);
    FUN_1c0e2444(DAT_1c0e4304,1,uVar3,0x80008,1);
    uVar3 = FUN_1c0e25bc(DAT_1c0e4304,0x154);
    FUN_1c0e2444(DAT_1c0e4304,2,uVar3,0x80008,1);
    uVar3 = 0x1d1;
  }
  else {
    if (*(char *)(iVar2 + 3) != '\x02') {
      uVar3 = FUN_1c0e25bc(DAT_1c0e4304,10);
      FUN_1c0e2444(DAT_1c0e4304,3,uVar3,0x80008,1);
      return;
    }
    uVar3 = FUN_1c0e25bc(DAT_1c0e4304,10);
    FUN_1c0e2444(DAT_1c0e4304,0,uVar3,0x80008,1);
    uVar3 = 0x104;
  }
  uVar3 = FUN_1c0e25bc(DAT_1c0e4304,uVar3);
  FUN_1c0e2444(DAT_1c0e4304,3,uVar3,0x80008,1);
  return;
}


