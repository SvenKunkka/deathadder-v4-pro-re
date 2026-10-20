/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078218. Types and names are inferred; NOT original source. */

void FUN_0e078218(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = DAT_0e078300;
  iVar1 = DAT_0e0782fc;
  *(undefined4 *)(DAT_0e0782fc + 0x540) = 0;
  *(undefined4 *)(iVar1 + 0x544) = 0;
  *(undefined4 *)(iVar1 + 0x548) = 0;
  *(undefined4 *)(iVar1 + 0x54c) = 0;
  *(undefined4 *)(iVar1 + 0x550) = 0;
  *(undefined4 *)(iVar1 + 0x554) = 0;
  *(uint *)(iVar1 + 0x200) = *(uint *)(iVar1 + 0x200) & 0xff00ff00;
  *(undefined4 *)(iVar1 + 0x308) = 0xff0000;
  if (*(char *)(iVar2 + 3) == '\x01') {
    uVar3 = FUN_0e0765bc(DAT_0e078304,0x5a);
    FUN_0e076444(DAT_0e078304,0,uVar3,0x80008,1);
    uVar3 = FUN_0e0765bc(DAT_0e078304,0xd7);
    FUN_0e076444(DAT_0e078304,1,uVar3,0x80008,1);
    uVar3 = FUN_0e0765bc(DAT_0e078304,0x154);
    FUN_0e076444(DAT_0e078304,2,uVar3,0x80008,1);
    uVar3 = 0x1d1;
  }
  else {
    if (*(char *)(iVar2 + 3) != '\x02') {
      uVar3 = FUN_0e0765bc(DAT_0e078304,10);
      FUN_0e076444(DAT_0e078304,3,uVar3,0x80008,1);
      return;
    }
    uVar3 = FUN_0e0765bc(DAT_0e078304,10);
    FUN_0e076444(DAT_0e078304,0,uVar3,0x80008,1);
    uVar3 = 0x104;
  }
  uVar3 = FUN_0e0765bc(DAT_0e078304,uVar3);
  FUN_0e076444(DAT_0e078304,3,uVar3,0x80008,1);
  return;
}


