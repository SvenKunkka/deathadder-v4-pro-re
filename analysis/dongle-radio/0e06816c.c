/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06816c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e06816c(int param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *local_1c [2];
  
  piVar6 = *(int **)(param_1 + 4);
  puVar7 = (undefined4 *)piVar6[0xe];
  iVar2 = FUN_0e067dcc(puVar7,0,local_1c);
  if (-1 < iVar2) {
    FUN_0e067e20(*local_1c[0],*(undefined1 *)(local_1c[0] + 1),*puVar7);
  }
  FUN_0e06217c(piVar6[0xe],0);
  uVar5 = 0;
  uVar3 = 0;
  do {
    uVar4 = *(uint *)(*piVar6 + (uVar5 + 0x158) * 4);
    if (-1 < (int)uVar4) {
      if (0x13f < uVar4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0xe068204);
        (*pcVar1)();
      }
      if ((int)((**(uint **)(DAT_0e068208 + (uVar4 >> 5) * 4) >> (uVar4 & 0x1f)) << 0x1f) < 0) {
        uVar3 = 1 << (uVar5 & 0xff) & 0xffU | uVar3;
      }
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 != 4);
  uVar5 = 0;
  do {
    *(ushort *)(*(int *)(*(int *)(param_1 + 4) + 0x28) + uVar5 * 2) =
         (ushort)((1 << (uVar5 & 0xff) & uVar3) == 0) << 0xf;
    uVar5 = uVar5 + 1;
  } while (uVar5 != 4);
  return 0;
}


