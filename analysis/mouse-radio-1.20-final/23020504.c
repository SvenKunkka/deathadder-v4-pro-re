/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23020504. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ram_candidate_23020504(undefined4 param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint extraout_r1;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  
  thunk_FUN_0e094fc8(&DAT_230002a0,param_2,0xffffffff,0xffffffff);
  bVar2 = DAT_230002f8;
  uVar7 = param_2[1];
  iVar3 = param_2[4];
  if (uVar7 - 1 < 0xff) {
    uVar5 = 0;
    uVar8 = 0;
    do {
      while( true ) {
        if ((uVar7 >> (uVar5 & 0xff) & 1) != 0) break;
        *(uint *)(uVar5 * 0x10 + 0x5f982518) = *(uint *)(uVar5 * 0x10 + 0x5f982518) & 0xfffff7ff;
        iVar4 = uVar5 + 0x51;
        uVar5 = uVar5 + 1;
        *(undefined4 *)(&DAT_5f982000 + iVar4 * 0x10) = 0;
        if (uVar5 == 8) goto LAB_230205c4;
      }
      uVar8 = uVar8 + 1 & 0xff;
      if (((byte)(&DAT_230002f0)[uVar5] == 0) ||
         (((int)((uint)(bVar2 >> (uVar5 & 0xff)) << 0x1f) < 0 && ((char)iVar3 == '\b'))))
      goto switchD_230205cc_caseD_9;
      bVar1 = (&DAT_0e09b268)[(byte)(&DAT_230002f0)[uVar5]];
      *(uint *)(uVar5 * 0x10 + 0x5f982518) =
           *(uint *)(uVar5 * 0x10 + 0x5f982518) & 0xfffff7ff |
           (uint)(*(char *)((int)param_2 + 0x11) != '\0') << 0xb;
      iVar4 = uVar5 + 0x51;
      uVar5 = uVar5 + 1;
      *(uint *)(&DAT_5f982000 + iVar4 * 0x10) = bVar1 & 0x1f | (uint)(bVar1 >> 5) << 8 | 0x40000000;
    } while (uVar5 != 8);
LAB_230205c4:
    switch((char)param_2[4]) {
    case '\b':
      _DAT_5f9825f0 = 0;
      break;
    default:
      goto switchD_230205cc_caseD_9;
    case '\n':
      _DAT_5f9825f0 = 1;
      break;
    case '\f':
      _DAT_5f9825f0 = 2;
      break;
    case '\x0e':
      _DAT_5f9825f0 = 3;
    }
    uVar7 = (uint)*(byte *)((int)param_2 + 0x11);
    if (uVar8 < 2) {
      if (uVar7 < 9) goto LAB_23020602;
    }
    else if (uVar7 == 0) {
LAB_23020602:
      uVar5 = uVar8;
      if ((char)param_2[4] != '\b') {
        uVar5 = uVar8 << 1;
      }
      if (*param_2 != 0) {
        uVar5 = *(ushort *)(*param_2 + 0xc) * uVar5 + uVar5;
      }
      _DAT_5f9825f4 = uVar7;
      if ((uint)param_2[3] < uVar5) {
        iVar3 = -0xc;
        iVar4 = DAT_230002c0;
        goto LAB_230205e0;
      }
      DAT_23000300 = param_2[2];
      DAT_23000304 = (undefined1)uVar8;
      if (_DAT_5f9825f0 != 0) {
        uVar8 = (int)(short)uVar8 << 1;
      }
      _DAT_5f98262c = DAT_230002fc;
      DAT_230002c4 = (undefined4 *)*param_2;
      DAT_230002c8 = param_2[1];
      DAT_230002cc = param_2[2];
      DAT_230002d0 = param_2[3];
      _DAT_230002d4 = param_2[4];
      DAT_230002c0 = 0;
      puVar6 = (uint *)*param_2;
      _DAT_5f982630 = uVar8;
      if (puVar6 == (uint *)0x0) {
LAB_23020678:
        uVar7 = _DAT_230002d4 >> 0x10 & 0xff;
        _DAT_5f982500 = 1;
        if (uVar7 == 0) {
          _DAT_5f982000 = 1;
          _DAT_5f982004 = 1;
        }
        else {
          _DAT_5f98200c = 1;
        }
      }
      else {
        DAT_230002d8 = *puVar6;
        DAT_230002dc = puVar6[1];
        DAT_230002e0 = puVar6[2];
        DAT_230002e4 = puVar6[3];
        DAT_230002c4 = &DAT_230002d8;
        DAT_230002e8 = 0;
        if (DAT_230002d8 == 0) goto LAB_23020678;
        DAT_23000260 = 0;
        thunk_FUN_0e096a50(&DAT_23000268,0,0,0,
                           DAT_230002d8 + 0x1f >> 5 | (uint)(0xffffffe0 < DAT_230002d8) << 0x1b,0);
        uVar7 = extraout_r1;
      }
      iVar3 = thunk_FUN_0e094fc8(&DAT_230002b0,uVar7,0xffffffff,0xffffffff);
      iVar4 = iVar3;
      if (iVar3 == 0) {
        iVar3 = DAT_230002c0;
        iVar4 = DAT_230002c0;
      }
      goto LAB_230205e0;
    }
  }
switchD_230205cc_caseD_9:
  iVar3 = -0x16;
  iVar4 = DAT_230002c0;
LAB_230205e0:
  DAT_230002c0 = iVar4;
  thunk_FUN_0e094f80(&DAT_230002a0);
  return iVar3;
}


