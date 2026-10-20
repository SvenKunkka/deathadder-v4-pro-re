/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091d88. Types and names are inferred; NOT original source. */

void FUN_0e091d88(uint *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  uVar1 = FUN_0e0797c0(param_2[1] << 0xf,param_2[1] >> 0x11,1000,0,param_4);
  iVar3 = DAT_0e091df4;
  uVar4 = *param_1;
  *(uint *)(uVar4 + 0x50c) = *param_2;
  *(undefined4 *)(uVar4 + 0x504) = uVar1;
  uVar4 = *param_2;
  iVar3 = iVar3 + (uint)(byte)param_1[1] * 0x10;
  iVar2 = *(int *)(iVar3 + 4);
  *(byte *)(iVar3 + 0xc) = (byte)((uVar4 << 0x19) >> 0x1f);
  if (iVar2 != 0) {
    uVar5 = *param_1;
    if ((uVar4 & 0x40) == 0) {
      uVar6 = 1;
      *(undefined4 *)(uVar5 + 0x100) = 0;
      uVar1 = *(undefined4 *)(uVar5 + 0x100);
    }
    else {
      *(undefined4 *)(uVar5 + 0x100) = 0;
      *(undefined4 *)(uVar5 + 0x104) = 0;
      uVar6 = 3;
      uVar1 = *(undefined4 *)(uVar5 + 0x104);
    }
    FUN_0e089fb8((uVar5 & 0x1fffff) >> 0xc,iVar2,iVar3,uVar1);
    *(undefined4 *)(uVar5 + 0x304) = uVar6;
  }
  return;
}


