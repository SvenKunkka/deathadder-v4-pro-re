/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091c60. Types and names are inferred; NOT original source. */

void FUN_0e091c60(uint *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  uVar2 = FUN_0e0795d8(param_2[1] << 0xf,param_2[1] >> 0x11,1000,0,param_4);
  uVar4 = *param_1;
  *(uint *)(uVar4 + 0x50c) = *param_2;
  *(undefined4 *)(uVar4 + 0x504) = uVar2;
  uVar4 = *param_2;
  iVar1 = (uint)(byte)param_1[1] * 0x10;
  iVar3 = *(int *)(&DAT_2300732c + iVar1);
  (&DAT_23007334)[iVar1] = (byte)((uVar4 << 0x19) >> 0x1f);
  if (iVar3 != 0) {
    uVar5 = *param_1;
    if ((uVar4 & 0x40) == 0) {
      uVar6 = 1;
      *(undefined4 *)(uVar5 + 0x100) = 0;
      uVar2 = *(undefined4 *)(uVar5 + 0x100);
    }
    else {
      *(undefined4 *)(uVar5 + 0x100) = 0;
      *(undefined4 *)(uVar5 + 0x104) = 0;
      uVar6 = 3;
      uVar2 = *(undefined4 *)(uVar5 + 0x104);
    }
    FUN_0e089e2c((uVar5 & 0x1fffff) >> 0xc,iVar3,&DAT_23007328 + iVar1,uVar2);
    *(undefined4 *)(uVar5 + 0x304) = uVar6;
  }
  return;
}


