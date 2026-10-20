/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e090778. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e090778(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 *local_1c [2];
  
  FUN_0e089e70(0x1a4,5,0);
  iVar2 = FUN_0e0910e0(*(int *)(param_1 + 4),*(int *)(param_1 + 4) + 8,&DAT_0e0905f5,
                       *(undefined4 *)(param_1 + 0x10));
  if (iVar2 == 0xbad0000) {
    piVar7 = *(int **)(param_1 + 4);
    puVar8 = (undefined4 *)piVar7[0xe];
    iVar2 = FUN_0e0976e0(puVar8,0,local_1c);
    if (-1 < iVar2) {
      FUN_0e0975d0(*local_1c[0],*(undefined1 *)(local_1c[0] + 1),*puVar8);
    }
    FUN_0e08ad28(piVar7[0xe],0);
    uVar4 = 0;
    uVar6 = 0;
    do {
      uVar5 = *(uint *)(*piVar7 + (uVar6 + 0x158) * 4);
      if (-1 < (int)uVar5) {
        if (0x13f < uVar5) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)software_udf(0xff,0xe090836);
          (*pcVar1)();
        }
        if ((int)((**(uint **)(&DAT_0e09b588 + (uVar5 >> 5) * 4) >> (uVar5 & 0x1f)) << 0x1f) < 0) {
          uVar4 = 1 << (uVar6 & 0xff) & 0xffU | uVar4;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 != 4);
    uVar6 = 0;
    do {
      *(ushort *)(*(int *)(*(int *)(param_1 + 4) + 0x28) + uVar6 * 2) =
           (ushort)((1 << (uVar6 & 0xff) & uVar4) == 0) << 0xf;
      uVar6 = uVar6 + 1;
    } while (uVar6 != 4);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xfffffff0;
  }
  return uVar3;
}


