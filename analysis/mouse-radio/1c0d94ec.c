/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0d94ec. Types and names are inferred; NOT original source. */

void FUN_1c0d94ec(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar7 = 0;
  uVar8 = DAT_1c0d95bc * (0x34 / param_2) + DAT_1c0d95b8;
  uVar3 = param_1[param_2 + 0x3fffffff];
  do {
    uVar7 = uVar7 + 0x9e3779b9;
    uVar9 = uVar7 >> 2;
    if (param_2 != 1) {
      uVar4 = 0;
      uVar5 = *param_1;
      puVar6 = param_1;
      do {
        uVar2 = uVar9 ^ uVar4;
        uVar1 = puVar6[1];
        uVar4 = uVar4 + 1;
        uVar3 = ((*(uint *)(param_3 + (uVar2 & 3) * 4) ^ uVar3) + (uVar7 ^ uVar1) ^
                (uVar1 << 2 ^ uVar3 >> 5) + (uVar3 << 4 ^ uVar1 >> 3)) + uVar5;
        *puVar6 = uVar3;
        uVar5 = uVar1;
        puVar6 = puVar6 + 1;
      } while (uVar4 != param_2 - 1U);
      uVar9 = uVar9 ^ param_2 - 1U;
    }
    uVar5 = *param_1;
    uVar3 = param_1[param_2 + 0x3fffffff] +
            ((uVar5 << 2 ^ uVar3 >> 5) + (uVar3 << 4 ^ uVar5 >> 3) ^
            (*(uint *)(param_3 + (uVar9 & 3) * 4) ^ uVar3) + (uVar5 ^ uVar7));
    param_1[param_2 + 0x3fffffff] = uVar3;
  } while (uVar7 != uVar8);
  return;
}


