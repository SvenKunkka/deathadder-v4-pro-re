/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0adf4c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0adf4c(uint param_1,undefined4 param_2,uint param_3,int param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint local_18;
  int local_14;
  
  if (param_1 == 0xffffffff) {
    param_1 = 0x7fffffff;
  }
  else {
    param_1 = param_1 & ~((int)param_1 >> 0x1f);
  }
  local_18 = param_3;
  local_14 = param_4;
  FUN_0e0ae8d4(&local_18);
  lVar1 = (longlong)(int)param_1 * 0x20 +
          CONCAT44((local_14 - _DAT_2f011684) - (uint)(local_18 < _DAT_2f011680),
                   local_18 - _DAT_2f011680);
  uVar2 = (uint)lVar1;
  uVar3 = (uint)((ulonglong)lVar1 >> 0x20);
  if (uVar3 == 0 && (0x3f < uVar2) <= uVar3) {
    uVar2 = 0x20;
    uVar3 = 0;
  }
  else {
    uVar2 = uVar2 & 0xffffffe0;
  }
  FUN_0e0ae99c(0x2f01136c,1,_DAT_2f011680 + uVar2,
               _DAT_2f011684 + uVar3 + CARRY4(_DAT_2f011680,uVar2),1,param_2);
  return;
}


