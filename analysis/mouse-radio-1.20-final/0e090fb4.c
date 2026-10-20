/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e090fb4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e090fb4(uint *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  char *pcVar5;
  byte *pbVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  byte *pbVar10;
  int iVar11;
  byte bVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  if (*(char *)(param_2 + 7) == '\0') {
    puVar8 = param_2 + -1;
    pcVar5 = (char *)(param_2 + 4);
    do {
      puVar8 = puVar8 + 1;
      uVar9 = *puVar8;
      if (uVar9 != 0xffffffff) {
        uVar7 = uVar9 & 0x1f;
        uVar9 = uVar9 >> 5;
        if (*pcVar5 == '\0') {
          if (9 < uVar9) {
            _NMI = 0;
                    /* WARNING: Does not return */
            pcVar1 = (code *)software_udf(0xff,0xe0910d6);
            (*pcVar1)();
          }
          iVar11 = *(int *)(&DAT_0e09b6c8 + uVar9 * 4);
          *(int *)(iVar11 + 8) = 1 << uVar7;
        }
        else {
          if (9 < uVar9) {
            _Reset = 0;
                    /* WARNING: Does not return */
            pcVar1 = (code *)software_udf(0xff,0xe0910d2);
            (*pcVar1)();
          }
          iVar11 = *(int *)(&DAT_0e09b6c8 + uVar9 * 4);
          *(int *)(iVar11 + 4) = 1 << uVar7;
        }
        iVar11 = iVar11 + uVar7 * 4;
        *(uint *)(iVar11 + 0x80) = *(uint *)(iVar11 + 0x80) & 0xfffcf0f0 | 3;
      }
      pcVar5 = pcVar5 + 1;
    } while (param_2 + 3 != puVar8);
  }
  uVar3 = *(ushort *)(param_2 + 6);
  bVar12 = *(byte *)((int)param_2 + 0x15);
  bVar2 = *(byte *)((int)param_2 + 0x16);
  uVar4 = *(ushort *)((int)param_2 + 0x1a);
  uVar9 = *param_1;
  if (*(char *)((int)param_2 + 0x1d) == '\0') {
    uVar15 = param_2[1];
    uVar14 = param_2[2];
    uVar13 = param_2[3];
    *(undefined4 *)(uVar9 + 0x560) = *param_2;
    *(undefined4 *)(uVar9 + 0x564) = uVar15;
    *(undefined4 *)(uVar9 + 0x568) = uVar14;
    *(undefined4 *)(uVar9 + 0x56c) = uVar13;
  }
  *(uint *)(uVar9 + 0x50c) = (uint)bVar12;
  *(uint *)(uVar9 + 0x504) = (uint)bVar2;
  *(uint *)(uVar9 + 0x508) = (uint)uVar3;
  *(uint *)(uVar9 + 0x510) = (uint)uVar4;
  uVar9 = *param_1;
  *(undefined4 *)(uVar9 + 0x110) = 0;
  *(undefined4 *)(uVar9 + 0x108) = 0;
  *(undefined4 *)(uVar9 + 0x10c) = 0;
  FUN_0e089e2c((uVar9 & 0x1fffff) >> 0xc,*(undefined4 *)(uVar9 + 0x108),0,
               *(undefined4 *)(uVar9 + 0x10c),param_4);
  pbVar10 = (byte *)((int)param_2 + 0xf);
  do {
    pbVar6 = pbVar10 + (-0xf - (int)param_2);
    uVar9 = *param_1;
    pbVar10 = pbVar10 + 1;
    bVar12 = *pbVar10;
    if (*(char *)((int)param_2 + 0x16) == '\0') {
      bVar12 = bVar12 ^ 1;
    }
    uVar7 = 1 << ((uint)pbVar6 & 0xff);
    if (bVar12 == 0) {
      *(uint *)(uVar9 + 0x518) = *(uint *)(uVar9 + 0x518) & ~uVar7;
    }
    else {
      *(uint *)(uVar9 + 0x518) = uVar7 | *(uint *)(uVar9 + 0x518);
    }
  } while (pbVar10 != (byte *)((int)param_2 + 0x13));
  return;
}


