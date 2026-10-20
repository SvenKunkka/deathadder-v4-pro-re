/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08bf18. Types and names are inferred; NOT original source. */

void FUN_0e08bf18(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 local_24 [4];
  int local_20;
  int local_1c;
  
  uVar1 = DAT_0e08c0b8;
switchD_0e08bf40_default:
  FUN_0e094cb4(uVar1,local_24,0xffffffff,0xffffffff);
  iVar5 = *(int *)(*(int *)(local_1c + 0x10) + 0x9c);
  switch(local_24[0]) {
  case 0:
    FUN_0e08ccc0(iVar5,0);
    goto switchD_0e08bf40_default;
  case 1:
    FUN_0e08ccc0(iVar5,1,0);
    goto switchD_0e08bf40_default;
  case 2:
    *(byte *)(iVar5 + 0x60) = *(byte *)(iVar5 + 0x60) & 0xfb;
    if (*(char *)(iVar5 + 0x2c) == '\x02') {
      FUN_0e08bec8(iVar5,local_24);
    }
    FUN_0e08ccc0(iVar5,2,0);
    goto switchD_0e08bf40_default;
  case 3:
    *(byte *)(iVar5 + 0x60) = *(byte *)(iVar5 + 0x60) | 4;
    if (*(char *)(iVar5 + 0x2c) == '\x02') {
      FUN_0e08bec8(iVar5,local_24);
    }
    FUN_0e08ccc0(iVar5,3,0);
    goto switchD_0e08bf40_default;
  case 4:
    iVar2 = *(int *)(iVar5 + 0x18);
    *(byte *)(iVar5 + 0x60) = *(byte *)(iVar5 + 0x60) & 0xfb;
    iVar6 = *(int *)(iVar2 + 8);
    uVar4 = *(uint *)(*(int *)(iVar2 + 0x10) + 0xa0);
    if ((int)(uVar4 << 0x1e) < 0) {
      (**(code **)(iVar6 + 0x3c))(iVar2);
      iVar3 = (**(code **)(iVar6 + 0x24))(iVar2,0);
      (**(code **)(iVar6 + 0x40))(iVar2);
      if ((iVar3 == 0) && (iVar3 = FUN_0e08c460(iVar5,0), iVar3 == 0)) {
        FUN_0e08cb8c(iVar5,0x80);
        iVar2 = FUN_0e08d7dc(*(undefined4 *)(iVar5 + 0x18));
        *(undefined1 *)(iVar5 + 0x2c) = 0;
        *(byte *)(iVar5 + 0x60) = *(byte *)(iVar5 + 0x60) & 199 | (iVar2 == 2) << 4;
        FUN_0e08ccc0(iVar5,4,0);
      }
      else {
        FUN_0e08ccc0(iVar5,4,0);
        FUN_0e08ccc0(iVar5,7,iVar3);
      }
      goto switchD_0e08bf40_default;
    }
    FUN_0e08ccc0(iVar5,4,(uVar4 & 3) >> 1);
    iVar2 = -1;
    break;
  case 5:
    if (*(char *)(iVar5 + 0x2c) == '\x02') {
      FUN_0e08bec8(iVar5,local_24);
    }
    goto switchD_0e08bf40_default;
  case 6:
    if ((*(byte *)(local_20 + 0x18) & 0x7f) == 0) {
      iVar2 = FUN_0e08b414();
    }
    else {
      iVar2 = FUN_0e08c758(iVar5,local_20,*(undefined4 *)(local_20 + 0x1e));
    }
    if (iVar2 == 0) goto switchD_0e08bf40_default;
    break;
  case 7:
    goto switchD_0e08bf40_caseD_7;
  default:
    goto switchD_0e08bf40_default;
  }
  FUN_0e08ccc0(iVar5,7,iVar2);
  goto switchD_0e08bf40_default;
switchD_0e08bf40_caseD_7:
  FUN_0e08ccc0(iVar5,6,local_20);
  goto switchD_0e08bf40_default;
}


