/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a08c. Types and names are inferred; NOT original source. */

uint FUN_0e06a08c(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = *param_1;
  uVar4 = *(uint *)(iVar2 + 0x510);
  uVar3 = DAT_0e06a0fc;
  if ((iVar2 != DAT_0e06a0f4) && (iVar2 != DAT_0e06a0f4 + 0x1000)) {
    if ((iVar2 == DAT_0e06a0f8) || (iVar2 == DAT_0e06a0f8 + 0x1000)) {
      uVar3 = 32000;
    }
    else if (iVar2 == DAT_0e06a0f8 + 0x2000) {
      uVar3 = 32000;
    }
    else {
      uVar3 = 16000;
    }
  }
  uVar1 = (uint)((ulonglong)param_2 * (ulonglong)uVar3 >> 0x20);
  return uVar1 >> (uVar4 - 0x20 & 0xff) |
         (uint)((ulonglong)param_2 * (ulonglong)uVar3) >> (uVar4 & 0xff) |
         uVar1 << (0x20 - uVar4 & 0xff);
}


