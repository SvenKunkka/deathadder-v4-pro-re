/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06edbc. Types and names are inferred; NOT original source. */

void FUN_0e06edbc(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 extraout_r1;
  
  puVar3 = DAT_0e06ee38;
  puVar2 = DAT_0e06ee34;
  if (*(char *)((int)DAT_0e06ee34 + 0x27) == '\0') {
    if (*(char *)(DAT_0e06ee38 + 1) == '\0') {
      return;
    }
    *(undefined1 *)(DAT_0e06ee38 + 1) = 0;
    *puVar3 = 0;
  }
  else {
    *(undefined1 *)((int)DAT_0e06ee34 + 0x27) = 0;
    *puVar3 = 0;
    puVar3[0x23] = 0;
    *(undefined2 *)((int)puVar3 + 0xd6) = 0;
    *(undefined4 *)((int)puVar3 + 0xa2) = 0;
  }
  *puVar2 = 0;
  FUN_0e06e294(2);
  iVar4 = DAT_0e06ee3c;
  *(undefined4 *)(DAT_0e06ee3c + 0x540) = 0;
  *(undefined4 *)(iVar4 + 0x544) = 0;
  *(undefined4 *)(iVar4 + 0x548) = 0;
  *(undefined4 *)(iVar4 + 0x54c) = 0;
  *(undefined4 *)(iVar4 + 0x550) = 0;
  *(undefined4 *)(iVar4 + 0x554) = 0;
  *(undefined4 *)(iVar4 + 0x558) = 0;
  *(undefined4 *)(iVar4 + 0x55c) = 0;
  *(undefined4 *)(iVar4 + 0x200) = 1;
  *(undefined4 *)(iVar4 + 0x304) = 0x7f0000;
  *(undefined4 *)(iVar4 + 0x308) = 0x800000;
  puVar2 = DAT_0e06f4f4;
  puVar3 = DAT_0e06f4f0;
  DAT_0e06f4f0[8] = 1000;
  uVar1 = puVar2[0x57];
  puVar3[5] = 0;
  puVar3[6] = 0;
  puVar3[0x23] = 0x13;
  *(undefined2 *)((int)puVar3 + 0xd2) = 0;
  puVar2[0x58] = uVar1;
  *puVar3 = 2;
  *puVar2 = 2;
  FUN_0e06e058();
  thunk_FUN_0e089fd4(0x28);
  iVar4 = DAT_0e06f4fc;
  *(undefined4 *)(DAT_0e06f4f8 + 0x184) = 0x100;
  *(undefined4 *)(iVar4 + 0xc) = 1;
  thunk_FUN_0e089fb8(0x28);
  thunk_FUN_0e096b78(DAT_0e06f500,extraout_r1,0x20,0,0x20,0);
  return;
}


