/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e6fd4. Types and names are inferred; NOT original source. */

uint FUN_0e0e6fd4(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  
  uVar6 = param_1[3];
  if (-1 < (int)(uVar6 << 0x1e)) {
    iVar7 = param_1[2];
    iVar2 = FUN_0e0e6f92(param_1 + 3,2);
    if (iVar2 != 0) {
      puVar1 = *(undefined4 **)(iVar7 + 0x90);
      puVar8 = (undefined4 *)((uVar6 & 3) >> 1);
      while (puVar4 = puVar1, puVar4 != (undefined4 *)0x0) {
        if (param_1 == puVar4) {
          uVar5 = *param_1;
          if (puVar8 == (undefined4 *)0x0) {
            *(undefined4 *)(iVar7 + 0x90) = uVar5;
            if (param_1 == *(undefined4 **)(iVar7 + 0x94)) {
              *(undefined4 *)(iVar7 + 0x94) = uVar5;
            }
          }
          else {
            *puVar8 = uVar5;
            if (param_1 == *(undefined4 **)(iVar7 + 0x94)) {
              *(undefined4 **)(iVar7 + 0x94) = puVar8;
            }
          }
          *param_1 = 0;
          break;
        }
        puVar8 = puVar4;
        puVar1 = (undefined4 *)*puVar4;
      }
    }
  }
  uVar3 = param_1[3] & 0x1f;
  uVar6 = 0;
  if (uVar3 != 0) {
    param_1[3] = param_1[3] | 2;
    uVar6 = uVar3 | 2;
  }
  return uVar6;
}


