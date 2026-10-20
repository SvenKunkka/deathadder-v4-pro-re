/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063240. Types and names are inferred; NOT original source. */

void FUN_0e063240(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 local_24 [4];
  int local_20;
  int local_1c;
  
switchD_0e063268_default:
  FUN_0e06cc94(&DAT_23001c2c,local_24,0xffffffff,0xffffffff);
  iVar4 = *(int *)(*(int *)(local_1c + 0x10) + 0x9c);
  switch(local_24[0]) {
  case 0:
    FUN_0e064050(iVar4,0);
    goto switchD_0e063268_default;
  case 1:
    FUN_0e064050(iVar4,1,0);
    goto switchD_0e063268_default;
  case 2:
    *(byte *)(iVar4 + 0x60) = *(byte *)(iVar4 + 0x60) & 0xfb;
    if (*(char *)(iVar4 + 0x2c) == '\x02') {
      FUN_0e0631f0(iVar4,local_24);
    }
    FUN_0e064050(iVar4,2,0);
    goto switchD_0e063268_default;
  case 3:
    *(byte *)(iVar4 + 0x60) = *(byte *)(iVar4 + 0x60) | 4;
    if (*(char *)(iVar4 + 0x2c) == '\x02') {
      FUN_0e0631f0(iVar4,local_24);
    }
    FUN_0e064050(iVar4,3,0);
    goto switchD_0e063268_default;
  case 4:
    iVar1 = *(int *)(iVar4 + 0x18);
    *(byte *)(iVar4 + 0x60) = *(byte *)(iVar4 + 0x60) & 0xfb;
    iVar5 = *(int *)(iVar1 + 8);
    uVar3 = *(uint *)(*(int *)(iVar1 + 0x10) + 0xa0);
    if ((int)(uVar3 << 0x1e) < 0) {
      (**(code **)(iVar5 + 0x3c))(iVar1);
      iVar2 = (**(code **)(iVar5 + 0x24))(iVar1,0);
      (**(code **)(iVar5 + 0x40))(iVar1);
      if ((iVar2 == 0) && (iVar2 = FUN_0e063788(iVar4,0), iVar2 == 0)) {
        FUN_0e063f18(iVar4,0x80);
        iVar1 = FUN_0e064bbc(*(undefined4 *)(iVar4 + 0x18));
        *(undefined1 *)(iVar4 + 0x2c) = 0;
        *(byte *)(iVar4 + 0x60) = *(byte *)(iVar4 + 0x60) & 199 | (iVar1 == 2) << 4;
        FUN_0e064050(iVar4,4,0);
      }
      else {
        FUN_0e064050(iVar4,4,0);
        FUN_0e064050(iVar4,7,iVar2);
      }
      goto switchD_0e063268_default;
    }
    FUN_0e064050(iVar4,4,(uVar3 & 3) >> 1);
    iVar1 = -1;
    break;
  case 5:
    if (*(char *)(iVar4 + 0x2c) == '\x02') {
      FUN_0e0631f0(iVar4,local_24);
    }
    goto switchD_0e063268_default;
  case 6:
    if ((*(byte *)(local_20 + 0x18) & 0x7f) == 0) {
      iVar1 = FUN_0e06273c();
    }
    else {
      iVar1 = FUN_0e063a80(iVar4,local_20,*(undefined4 *)(local_20 + 0x1e));
    }
    if (iVar1 == 0) goto switchD_0e063268_default;
    break;
  case 7:
    goto switchD_0e063268_caseD_7;
  default:
    goto switchD_0e063268_default;
  }
  FUN_0e064050(iVar4,7,iVar1);
  goto switchD_0e063268_default;
switchD_0e063268_caseD_7:
  FUN_0e064050(iVar4,6,local_20);
  goto switchD_0e063268_default;
}


