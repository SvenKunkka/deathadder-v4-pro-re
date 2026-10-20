/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0883bc. Types and names are inferred; NOT original source. */

uint FUN_0e0883bc(int *param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffea;
  }
  if ((param_3 != 0) && (param_2 != 0)) {
    ram_candidate_23020c7c(*(undefined4 *)*param_1,4);
    DataMemoryBarrier(0x1b);
    puVar2 = (undefined4 *)*param_1;
    iVar7 = puVar2[4];
    uVar6 = puVar2[3];
    uVar3 = *(uint *)*puVar2;
    uVar5 = param_1[1];
    if ((uVar3 & 3) == 0) {
      if (uVar5 < uVar3) {
        iVar4 = (uVar6 + uVar5) - uVar3;
      }
      else {
        iVar4 = uVar5 - uVar3;
      }
      if (param_3 + 4 <= (uVar6 - 4) - iVar4) {
        *(undefined4 *)(iVar7 + uVar5) = 0;
        *(char *)(iVar7 + uVar5) = (char)(param_3 >> 8);
        *(char *)(iVar7 + uVar5 + 1) = (char)param_3;
        DataMemoryBarrier(0x1b);
        uVar3 = uVar5 + 4;
        ram_candidate_23020c1c(iVar7 + uVar5,4);
        if (uVar6 <= uVar3) {
          uVar3 = uVar3 - uVar6 * (uVar3 / uVar6);
        }
        uVar5 = uVar6 - uVar3;
        if (param_3 <= uVar6 - uVar3) {
          uVar5 = param_3;
        }
        uVar1 = FUN_0e09739c(iVar7 + uVar3,param_2,uVar5);
        ram_candidate_23020c1c(uVar1,uVar5);
        if (uVar5 < param_3) {
          FUN_0e09739c(iVar7,param_2 + uVar5,param_3 - uVar5);
          ram_candidate_23020c1c(iVar7,param_3 - uVar5);
        }
        uVar3 = param_3 + 3 + uVar3 & 0xfffffffc;
        if (uVar6 <= uVar3) {
          uVar3 = uVar3 - uVar6 * (uVar3 / uVar6);
        }
        param_1[1] = uVar3;
        **(uint **)(*param_1 + 4) = uVar3;
        DataMemoryBarrier(0x1b);
        ram_candidate_23020c1c(*(undefined4 *)(*param_1 + 4),4);
        return param_3;
      }
      return 0xfffffff4;
    }
  }
  return 0xffffffea;
}


