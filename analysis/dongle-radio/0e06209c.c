/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06209c. Types and names are inferred; NOT original source. */

uint FUN_0e06209c(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 auStack_20 [4];
  uint local_1c;
  uint local_18;
  uint local_14;
  
  if ((param_1 < 5) && (iVar2 = *(int *)(DAT_0e06213c + param_1 * 4), iVar2 != 0)) {
    local_14 = (*DAT_0e062140 & 7) >> 2;
    if ((int)(*DAT_0e062140 << 0x1d) < 0) {
      uVar1 = 0xfffffffb;
    }
    else {
      local_1c = (uint)*DAT_0e062144;
      if (local_1c == 0) {
        local_18 = 1;
        local_14 = local_1c;
        uVar1 = FUN_0e05dec0(iVar2,auStack_20);
        if (-1 < (int)uVar1) {
          do {
          } while ((local_18 & 3) != 0);
          return local_14;
        }
      }
      else {
        local_1c = DAT_0e062148;
        iVar3 = iVar2 + 0x24;
        local_18 = 3;
        FUN_0e06ce48(iVar3,DAT_0e062148,0xffffffff,0xffffffff);
        uVar4 = FUN_0e05dec0(iVar2,auStack_20);
        uVar1 = (uint)uVar4;
        if ((int)uVar1 < 0) {
          FUN_0e06cf44(iVar3);
        }
        else {
          FUN_0e06d1b4(iVar2 + 0x38,(int)((ulonglong)uVar4 >> 0x20),0xffffffff,0xffffffff);
          uVar1 = *(uint *)(iVar2 + 0x48);
          FUN_0e06cf44(iVar3);
        }
      }
    }
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}


