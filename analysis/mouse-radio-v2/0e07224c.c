/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07224c. Types and names are inferred; NOT original source. */

uint FUN_0e07224c(undefined4 param_1,uint param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  ulonglong uVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint local_94;
  byte local_89;
  byte abStack_88 [32];
  byte local_68;
  undefined1 auStack_67 [67];
  
  pbVar4 = DAT_0e0723c0;
  if (param_2 < 6) {
    local_94 = param_4;
    switch(param_2) {
    case 1:
      bVar1 = param_3[1];
      bVar2 = *param_3;
      *(ushort *)(DAT_0e0723c0 + 4) =
           (*(ushort *)(param_3 + 2) << 8 | *(ushort *)(param_3 + 2) >> 8) +
           *(short *)(DAT_0e0723c0 + 4);
      *(ushort *)(pbVar4 + 6) =
           (*(ushort *)(param_3 + 4) << 8 | *(ushort *)(param_3 + 4) >> 8) + *(short *)(pbVar4 + 6);
      pbVar4[1] = pbVar4[1] + bVar1;
      bVar1 = *pbVar4;
      *pbVar4 = bVar1 | bVar2;
      *param_3 = bVar1 | bVar2;
      param_3[1] = pbVar4[1];
      param_3[2] = pbVar4[5];
      param_3[3] = (byte)*(undefined2 *)(pbVar4 + 4);
      param_3[4] = pbVar4[7];
      param_3[5] = (byte)*(undefined2 *)(pbVar4 + 6);
      break;
    case 2:
      thunk_FUN_0e097512(abStack_88,0,0x20);
      thunk_FUN_0e0974c4(abStack_88,param_3,param_4);
      param_3 = abStack_88;
      local_89 = 8;
      FUN_0e06d5e0(param_3,&local_89);
      local_94 = (uint)local_89;
      break;
    case 3:
      *DAT_0e0723c4 = 0;
      break;
    case 4:
      thunk_FUN_0e097512(abStack_88,0,0x20);
      thunk_FUN_0e0974c4(abStack_88,param_3,param_4);
      param_3 = abStack_88;
      local_89 = 0x10;
      FUN_0e06d5e0(param_3,&local_89);
      local_94 = (uint)local_89;
    }
    uVar3 = (ulonglong)DAT_0e0723bc;
    uVar5 = FUN_0e06dc24(param_1,param_2);
    uVar10 = (uint)(uVar3 * (local_94 + 5) >> 0x22) - 1 & 0xffff;
    if (uVar10 < uVar5) {
      uVar8 = 0;
      uVar7 = 0;
      uVar5 = local_94;
      do {
        if (uVar7 == uVar10) {
          local_68 = 0;
          uVar7 = uVar5 + 1 & 0xffff;
          uVar9 = uVar5;
        }
        else {
          uVar7 = 7;
          local_68 = 0x80;
          uVar9 = 6;
        }
        local_68 = local_68 | (byte)uVar8;
        thunk_FUN_0e0974c4(auStack_67,param_3);
        iVar6 = FUN_0e06dd48(param_1,param_2,&local_68,uVar7,0xff);
        uVar8 = uVar8 + 1;
        uVar7 = uVar8 & 0xffff;
      } while ((iVar6 != 0) &&
              (uVar5 = uVar5 - uVar9 & 0xffff, param_3 = param_3 + uVar9, uVar7 <= uVar10));
      if (uVar5 != 0) {
        return local_94;
      }
      if (param_2 == 1) {
        pbVar4 = DAT_0e0723c0;
        pbVar4[0] = 0;
        pbVar4[1] = 0;
        pbVar4[2] = 0;
        pbVar4[3] = 0;
        pbVar4[4] = 0;
        pbVar4[5] = 0;
        pbVar4[6] = 0;
        pbVar4[7] = 0;
      }
      return local_94;
    }
  }
  return 0;
}


