/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1804. Types and names are inferred; NOT original source. */

int FUN_0e0b1804(int param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  
  if ((param_2 < 4) && (uVar4 = (uint)*(byte *)(param_2 + param_1 + 0xec), uVar4 < 4)) {
    iVar6 = uVar4 * 0x10;
    puVar2 = (uint *)(iVar6 + 0xb0 + param_1);
    uVar1 = *puVar2 & 0xff;
    if (uVar1 == 3) {
      if (*(int *)(param_1 + iVar6 + 0xb4) == 0) {
LAB_0e0b1838:
        return param_1 + iVar6 + 0xac;
      }
    }
    else if (uVar1 == 2) {
      *puVar2 = 3;
      iVar3 = *(int *)(param_1 + uVar4 * 0x10 + 0xac);
      pcVar5 = *(code **)(iVar3 + 8);
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)(*(undefined4 *)(iVar3 + 0x14));
      }
      goto LAB_0e0b1838;
    }
  }
  return 0;
}


