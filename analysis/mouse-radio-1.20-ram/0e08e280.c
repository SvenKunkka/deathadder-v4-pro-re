/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08e280. Types and names are inferred; NOT original source. */

void FUN_0e08e280(int param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  
  bVar1 = *(byte *)(param_2 + 0x18);
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  uVar3 = bVar1 & 0x7f;
  bVar8 = *(byte *)(param_2 + 0x19) & 3;
  iVar7 = iVar4 + uVar3 * 0x20;
  if ((int)((uint)bVar1 << 0x18) < 0) {
    uVar2 = *(uint *)(iVar7 + 0x900);
    if (((bVar8 != 1) && ((int)(uVar2 << 0xe) < 0)) && (-1 < (int)uVar2)) {
      iVar7 = uVar3 + 0x48;
      goto LAB_0e08e360;
    }
    iVar6 = uVar3 * 0x20 + 0x908 + iVar4;
    uVar5 = uVar2 | 0x88000000;
    if (param_3 != 0) {
      uVar5 = uVar2 | 0x88200000;
    }
    *(uint *)(iVar7 + 0x900) = uVar5;
    FUN_0e08dd30(param_1,iVar6,0x40);
    *(uint *)(iVar7 + 0x900) = uVar5 | 0xc0000000;
    FUN_0e08dd30(param_1,iVar6,2);
    *(undefined4 *)(iVar4 + uVar3 * 0x20 + 0x908) = 3;
    iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    *(uint *)(iVar4 + 0x10) = (uVar5 & 0x3c00000) >> 0x10 | 0x20;
    do {
    } while (*(int *)(iVar4 + 0x10) << 0x1a < 0);
    goto LAB_0e08e30a;
  }
  uVar2 = *(uint *)(iVar7 + 0xb00);
  if (((bVar8 != 1) && ((int)(uVar2 << 0xe) < 0)) && (-1 < (int)uVar2)) {
    iVar7 = uVar3 + 0x58;
LAB_0e08e360:
    if (param_3 != 0) {
      *(uint *)(iVar4 + iVar7 * 0x20) = uVar2 | 0x200000;
    }
    return;
  }
  uVar5 = *(uint *)(iVar4 + 0x804);
  if (*(int *)(iVar4 + 0x14) << 0x18 < 0) {
    FUN_0e08dd30(param_1,iVar4 + 0x14,0x80);
    if ((bVar1 & 0x7f) == 0) goto LAB_0e08e31a;
LAB_0e08e2da:
    if (param_3 == 0) {
      *(uint *)(iVar7 + 0xb00) = uVar2 | 0xc8000000;
    }
    else {
      *(uint *)(iVar7 + 0xb00) = uVar2 | 0xc0200000;
    }
    FUN_0e08dd30(param_1,uVar3 * 0x20 + 0xb08 + iVar4,2);
  }
  else {
    *(uint *)(iVar4 + 0x804) = uVar5 | 0x200;
    uVar5 = uVar5 & 0xfffffdff;
    FUN_0e08dd30(param_1,iVar4 + 0x14,0x80);
    if ((bVar1 & 0x7f) != 0) goto LAB_0e08e2da;
LAB_0e08e31a:
    if (param_3 == 0) {
      *(uint *)(iVar7 + 0xb00) = uVar2 | 0x8000000;
    }
    else {
      *(uint *)(iVar7 + 0xb00) = uVar2 | 0x200000;
    }
  }
  *(undefined4 *)(iVar4 + uVar3 * 0x20 + 0xb08) = 3;
  *(uint *)(iVar4 + 0x804) = uVar5 | 0x400;
LAB_0e08e30a:
  FUN_0e08d180(param_1,*(undefined1 *)(param_2 + 0x18),0);
  return;
}


