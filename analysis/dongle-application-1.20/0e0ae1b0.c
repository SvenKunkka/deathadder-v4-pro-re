/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ae1b0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0e0ae1b0(uint param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = 0;
  for (uVar4 = 0; uVar4 != param_2; uVar4 = uVar4 + 1) {
    uVar3 = 1 << (uVar4 & 0xff);
    if (((param_1 & uVar3) != 0) &&
       (piVar2 = (int *)((uVar4 & 0xff) * 4 + 0x5f934100), *piVar2 != 0)) {
      *piVar2 = 0;
      uVar1 = uVar1 | uVar3;
    }
  }
  if (_DAT_5f93414c != 0) {
    _DAT_5f93414c = 0;
    uVar1 = uVar1 | 0x80000;
  }
  return uVar1;
}


