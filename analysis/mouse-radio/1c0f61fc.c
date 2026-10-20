/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f61fc. Types and names are inferred; NOT original source. */

uint FUN_1c0f61fc(uint param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = DAT_1c0f624c;
  uVar2 = param_2[2];
  uVar5 = *param_2;
  uVar4 = param_2[1];
  uVar1 = *(ushort *)((int)param_2 + 10);
  if (param_1 <= ((*(uint *)(DAT_1c0f624c + 0x90) & 0xffff) >> 8) - 1) {
    *(uint *)(DAT_1c0f624c + 0x98) = param_1;
    *(uint *)(iVar3 + 0x9c) = (ushort)uVar2 & 0x1f | uVar5 & 0xffffffe0;
    *(uint *)(iVar3 + 0xa0) = (uVar4 - 1) + (uVar5 & 0xffffffe0) & 0xffffffe0 | (uVar1 & 7) << 1 | 1
    ;
    return param_1;
  }
  return 0xffffffea;
}


