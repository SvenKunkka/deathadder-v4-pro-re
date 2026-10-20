/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0adbd8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0adbd8(int param_1,uint param_2,int param_3,int param_4)

{
  code *pcVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  undefined1 uStack_2d;
  uint local_2c;
  undefined1 *local_28;
  undefined4 local_24;
  uint *local_20;
  undefined4 uStack_1c;
  
  iVar3 = *(int *)(param_1 + 4);
  uVar6 = param_2 & 0x1f | (uint)*(byte *)(iVar3 + 0xc) << 5;
  if (*(int *)(iVar3 + 0x10) == 0) {
    uVar4 = 0xffffff7a;
  }
  else {
    iVar7 = iVar3 + 0x10;
    if (param_3 == 0x200000) {
      thunk_FUN_0e0b212a(iVar7,uVar6);
    }
    else {
      local_20 = &local_2c;
      local_28 = (undefined1 *)0x0;
      if (param_3 == 0x400000) {
        if (param_4 == 0x2000000) {
          bVar5 = 4;
        }
        else {
          bVar5 = 5;
        }
      }
      else if (param_4 == 0x6000000) {
        bVar5 = 3;
      }
      else if (param_4 == 0x2000000) {
        bVar5 = 2;
      }
      else {
        bVar5 = 1;
      }
      local_2c = (uint)bVar5;
      uStack_1c = 0;
      local_24 = 0;
      puVar2 = local_28;
      if (((*(uint *)(iVar3 + 8) >> (param_2 & 0xff) & 1) == 0) && (param_3 == 0x1400000)) {
        if (0x13f < uVar6) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)software_udf(0xff,0xe0adcc8);
          (*pcVar1)();
        }
        if (-1 < *(int *)(*(int *)(&DAT_0e0b3bd8 + (uint)*(byte *)(iVar3 + 0xc) * 4) +
                         ((param_2 & 0x1f) + 0x20) * 4) << 0x1f) {
          iVar3 = FUN_0e0ae51c(iVar7,uVar6,&uStack_2d);
          puVar2 = &uStack_2d;
          if ((iVar3 == 0xbad0004) && (iVar3 = FUN_0e0ae5d8(iVar7,&uStack_2d), iVar3 != 0xbad0000))
          {
            return 0xfffffff4;
          }
        }
      }
      local_28 = puVar2;
      iVar3 = FUN_0e0ae290(iVar7,uVar6,&local_24);
      if (iVar3 != 0xbad0000) {
        return 0xffffffea;
      }
      FUN_0e0ae5e4(iVar7,uVar6,1);
    }
    uVar4 = 0;
  }
  return uVar4;
}


