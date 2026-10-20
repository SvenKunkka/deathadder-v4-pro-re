/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e067634. Types and names are inferred; NOT original source. */

undefined4 FUN_0e067634(int param_1,uint param_2,int param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  uint uVar6;
  undefined1 uStack_25;
  uint local_24;
  undefined1 *local_20;
  undefined4 local_1c;
  uint *local_18;
  undefined4 local_14;
  
  iVar2 = *(int *)(param_1 + 4);
  uVar6 = param_2 & 0x1f | (uint)*(byte *)(iVar2 + 0xc) << 5;
  if (*(int *)(iVar2 + 0x10) == 0) {
    uVar4 = 0xffffff7a;
  }
  else {
    if (param_3 == 0x200000) {
      thunk_FUN_0e068f60(iVar2 + 0x10,uVar6);
    }
    else {
      local_20 = (undefined1 *)0x0;
      if (param_3 == 0x400000) {
        if (param_4 == 0x2000000) {
          bVar5 = 4;
        }
        else {
          bVar5 = 5;
        }
        local_18 = &local_24;
        local_1c = 0;
        local_14 = 0;
        local_24 = (uint)bVar5;
      }
      else {
        if (param_4 == 0x6000000) {
          bVar5 = 3;
        }
        else if (param_4 == 0x2000000) {
          bVar5 = 2;
        }
        else {
          bVar5 = 1;
        }
        local_24 = (uint)bVar5;
        local_18 = &local_24;
        local_1c = 0;
        local_14 = 0;
        if (((*(uint *)(iVar2 + 8) >> (param_2 & 0xff) & 1) == 0) && (param_3 == 0x1400000)) {
          if (0x13f < uVar6) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)software_udf(0xff,0xe067740);
            (*pcVar1)();
          }
          if (-1 < *(int *)(*(int *)(DAT_0e067748 + (uint)*(byte *)(iVar2 + 0xc) * 4) +
                           ((param_2 & 0x1f) + 0x20) * 4) << 0x1f) {
            iVar3 = FUN_0e06945c(iVar2 + 0x10,uVar6,&uStack_25);
            if ((iVar3 == DAT_0e06774c) &&
               (iVar3 = FUN_0e06955c(iVar2 + 0x10,&uStack_25), iVar3 != DAT_0e067744)) {
              return 0xfffffff4;
            }
            local_20 = &uStack_25;
          }
        }
      }
      iVar3 = FUN_0e0690a4(iVar2 + 0x10,uVar6,&local_1c);
      if (iVar3 != DAT_0e067744) {
        return 0xffffffea;
      }
      FUN_0e069574(iVar2 + 0x10,uVar6,1);
    }
    uVar4 = 0;
  }
  return uVar4;
}


