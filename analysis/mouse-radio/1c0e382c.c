/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e382c. Types and names are inferred; NOT original source. */

void FUN_1c0e382c(void)

{
  sbyte sVar1;
  char *pcVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined1 *puVar8;
  uint *puVar9;
  uint local_24;
  uint local_20 [2];
  
  pcVar2 = DAT_1c0e398c;
  if (*DAT_1c0e398c != '\0') {
    iVar6 = *DAT_1c0e3990;
    iVar7 = DAT_1c0e3990[1];
    puVar9 = *(uint **)(iVar6 + 0x10);
    iVar6 = (**(code **)(*(int *)(iVar6 + 8) + 4))(iVar6,local_20);
    puVar3 = DAT_1c0e399c;
    if (iVar6 == 0) {
      if (((*puVar9 ^ local_20[0]) & 1 << (sbyte)iVar7) == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = 1;
      }
    }
    if ((iVar6 == 1) && (*(char *)(DAT_1c0e3994 + 10) == '\0')) {
      *DAT_1c0e3998 = 0;
      *puVar3 = 1;
      FUN_1c0d9ad8();
      thunk_EXT_FUN_0e09628c(0x271,0);
      FUN_1c0e40e8();
      FUN_1c0e3e1c();
      FUN_1c0e4008();
      FUN_1c0e3ef0();
      FUN_1c0df2b4();
      thunk_EXT_FUN_0e07d864(0);
      FUN_1c0e2ba0();
      FUN_1c0e3048(0x16,local_20,6);
      thunk_EXT_FUN_0e09467c(1000);
      thunk_EXT_FUN_0e0849ac();
      thunk_EXT_FUN_0e07ef2c();
      FUN_1c0e2e44();
      FUN_1c0defd0(0);
      thunk_EXT_FUN_0e085724(1);
      thunk_EXT_FUN_0e0855c8();
      thunk_EXT_FUN_0e08504c();
      iVar7 = *(int *)(DAT_1c0e39a0 + 0xc);
      sVar1 = *(sbyte *)(DAT_1c0e39a0 + 0x10);
      puVar9 = *(uint **)(iVar7 + 0x10);
      iVar7 = (**(code **)(*(int *)(iVar7 + 8) + 4))(iVar7,&local_24);
      if ((iVar7 != 0) || (puVar8 = DAT_1c0e39a4, ((local_24 ^ *puVar9) & 1 << sVar1) != 0)) {
        FUN_1c0e0d48();
        thunk_EXT_FUN_0e07e19c(1);
        thunk_EXT_FUN_0e07e218();
        *DAT_1c0e39c0 = 1;
        puVar8 = DAT_1c0e39a4;
        thunk_EXT_FUN_0e0950f0(DAT_1c0e39c4,extraout_r1,0,0);
        *puVar8 = 1;
        thunk_EXT_FUN_0e0950f0(DAT_1c0e39c4,extraout_r1_00,0xffffffff,0xffffffff);
        thunk_EXT_FUN_0e07e19c(0);
        thunk_EXT_FUN_0e07e1d8();
      }
      puVar4 = DAT_1c0e39ac;
      *DAT_1c0e39a8 = 0;
      puVar5 = DAT_1c0e39b0;
      *puVar3 = 0;
      *puVar5 = 0xff;
      puVar3 = DAT_1c0e39b4;
      *puVar4 = 0;
      *puVar3 = 0;
      puVar3 = DAT_1c0e39bc;
      *DAT_1c0e39b8 = 0;
      *puVar3 = 0xff;
      *puVar8 = 0;
      thunk_EXT_FUN_0e08497c();
      thunk_EXT_FUN_0e07f794();
      FUN_1c0e2d0c();
      thunk_EXT_FUN_0e085640();
      thunk_EXT_FUN_0e0850c4();
      thunk_EXT_FUN_0e07ed0c();
      thunk_EXT_FUN_0e07ee28();
      FUN_1c0defe0();
      FUN_1c0e2b80();
      thunk_EXT_FUN_0e085724(0);
      FUN_1c0e3eb0();
      FUN_1c0df280();
      *pcVar2 = '\0';
    }
  }
  return;
}


