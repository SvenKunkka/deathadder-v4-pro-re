
void vendor_rom_e069d98(int param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar2 = 0x40;
  do {
    while (*(int *)(param_1 + 0x100 + uVar2) != 0) {
      *(undefined4 *)(param_1 + 0x100 + uVar2) = 0;
      uVar1 = uVar2 >> 2;
      uVar2 = uVar2 + 4;
      uVar4 = uVar4 | 1 << (uVar1 & 0xff);
      if (uVar2 == 0x60) goto LAB_0e069dce;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 != 0x60);
LAB_0e069dce:
  uVar2 = 0x40;
  uVar1 = *(uint *)(param_1 + 0x304);
  do {
    uVar3 = 1 << (uVar2 >> 2 & 0xff);
    if (((uVar1 & 0xff0000 & uVar3) != 0) && ((uVar3 & uVar4) != 0)) {
      if ((code *)*param_2 != (code *)0x0) {
        (*(code *)*param_2)(uVar2 + 0x100 & 0xffff,param_2[1]);
      }
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 != 0x60);
  return;
}


