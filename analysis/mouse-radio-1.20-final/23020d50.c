/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23020d50. Types and names are inferred; NOT original source. */

void FUN_23020d50(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = 0;
  uVar3 = param_1[param_2 + 0x3fffffff];
  do {
    uVar7 = uVar7 + 0x9e3779b9;
    uVar8 = uVar7 >> 2;
    if (param_2 != 1) {
      uVar4 = 0;
      uVar5 = *param_1;
      puVar6 = param_1;
      do {
        uVar2 = uVar8 ^ uVar4;
        uVar1 = puVar6[1];
        uVar4 = uVar4 + 1;
        uVar3 = ((*(uint *)(param_3 + (uVar2 & 3) * 4) ^ uVar3) + (uVar7 ^ uVar1) ^
                (uVar1 << 2 ^ uVar3 >> 5) + (uVar3 << 4 ^ uVar1 >> 3)) + uVar5;
        *puVar6 = uVar3;
        uVar5 = uVar1;
        puVar6 = puVar6 + 1;
      } while (uVar4 != param_2 - 1U);
      uVar8 = uVar8 ^ param_2 - 1U;
    }
    uVar5 = *param_1;
    uVar3 = param_1[param_2 + 0x3fffffff] +
            ((uVar5 << 2 ^ uVar3 >> 5) + (uVar3 << 4 ^ uVar5 >> 3) ^
            (*(uint *)(param_3 + (uVar8 & 3) * 4) ^ uVar3) + (uVar5 ^ uVar7));
    param_1[param_2 + 0x3fffffff] = uVar3;
  } while (uVar7 != (0x34 / param_2) * -0x61c88647 + 0xb54cda56U);
  return;
}


