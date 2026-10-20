/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302003c. Types and names are inferred; NOT original source. */

void FUN_2302003c(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  
  uVar3 = *param_1;
  puVar2 = param_1 + param_2 + 0x3fffffff;
  uVar6 = (0x34 / param_2 + 6) * -0x61c88647;
  do {
    uVar5 = uVar3;
    if (param_2 != 1) {
      uVar5 = *puVar2;
      uVar4 = param_2 - 1;
      puVar7 = puVar2;
      do {
        uVar1 = puVar7[-1];
        uVar3 = uVar5 - ((*(uint *)(param_3 + ((uVar6 >> 2 ^ uVar4) & 3) * 4) ^ uVar1) +
                         (uVar3 ^ uVar6) ^ (uVar1 << 4 ^ uVar3 >> 3) + (uVar3 << 2 ^ uVar1 >> 5));
        uVar4 = uVar4 - 1;
        *puVar7 = uVar3;
        uVar5 = uVar1;
        puVar7 = puVar7 + -1;
      } while (uVar4 != 0);
      uVar5 = *param_1;
    }
    uVar4 = *puVar2;
    uVar3 = uVar5 - ((uVar4 << 4 ^ uVar3 >> 3) + (uVar3 << 2 ^ uVar4 >> 5) ^
                    (*(uint *)(param_3 + (uVar6 >> 2 & 3) * 4) ^ uVar4) + (uVar3 ^ uVar6));
    uVar6 = uVar6 + 0x61c88647;
    *param_1 = uVar3;
  } while (uVar6 != 0);
  return;
}


