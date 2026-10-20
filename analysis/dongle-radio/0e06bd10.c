/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bd10. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e06bbbe) */

int FUN_0e06bd10(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_24 [2];
  int local_1c;
  
  local_1c = param_1[2];
  iVar4 = *param_1;
  local_24[0] = param_2;
  iVar1 = FUN_0e06b3f4(local_24);
  iVar2 = FUN_0e06b3f4(&local_1c,4);
  iVar3 = FUN_0e06b240(param_1,3,0xffffffff);
  if (iVar3 != 0) {
    if (iVar1 - 1U < iVar2 - 1U) {
      iVar1 = param_1[8];
      if ((iVar1 != 0) && ((*(char *)(iVar1 + 0x10) == '\0' || (*(int *)(iVar1 + 0xc) == 0)))) {
        *(undefined4 *)(iVar1 + 0xc) = 4;
      }
    }
    else {
      iVar3 = FUN_0e06b3f4(&local_1c,4);
      iVar3 = FUN_0e06ba74(param_1,4,&local_1c,iVar3 + -1);
      if (iVar3 != 0) {
        if (iVar1 != iVar2) {
          iVar1 = (iVar1 - iVar2) + *param_1;
          iVar4 = iVar4 - iVar1;
          FUN_0e06f412(*param_1,iVar1,iVar4);
          iVar4 = iVar4 + *param_1;
        }
        *param_1 = iVar4;
        return iVar3;
      }
    }
  }
  return 0;
}


