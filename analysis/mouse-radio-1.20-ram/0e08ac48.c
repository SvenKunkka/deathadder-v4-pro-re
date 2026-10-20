/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08ac48. Types and names are inferred; NOT original source. */

uint FUN_0e08ac48(uint param_1)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined1 auStack_20 [4];
  undefined1 *local_1c;
  uint local_18;
  uint local_14;
  
  if ((param_1 < 5) && (puVar2 = (&PTR_DAT_0e09b058)[param_1], puVar2 != (undefined *)0x0)) {
    local_14 = (DAT_23006d58 & 7) >> 2;
    if ((int)(DAT_23006d58 << 0x1d) < 0) {
      uVar1 = 0xfffffffb;
    }
    else {
      local_1c = (undefined1 *)(uint)DAT_230077ca;
      if (local_1c == (undefined1 *)0x0) {
        local_18 = 1;
        local_14 = (uint)local_1c;
        uVar1 = FUN_0e0865f8(puVar2,auStack_20);
        if (-1 < (int)uVar1) {
          do {
          } while ((local_18 & 3) != 0);
          return local_14;
        }
      }
      else {
        local_1c = &LAB_0e08a98c_1;
        puVar3 = puVar2 + 0x24;
        local_18 = 3;
        FUN_0e094c5c(puVar3,&LAB_0e08a98c_1,0xffffffff,0xffffffff);
        uVar4 = FUN_0e0865f8(puVar2,auStack_20);
        uVar1 = (uint)uVar4;
        if ((int)uVar1 < 0) {
          FUN_0e094d58(puVar3);
        }
        else {
          FUN_0e094fc8(puVar2 + 0x38,(int)((ulonglong)uVar4 >> 0x20),0xffffffff,0xffffffff);
          uVar1 = *(uint *)(puVar2 + 0x48);
          FUN_0e094d58(puVar3);
        }
      }
    }
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}


