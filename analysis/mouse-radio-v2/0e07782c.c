/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07782c. Types and names are inferred; NOT original source. */

void FUN_0e07782c(void)

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
  
  pcVar2 = DAT_0e07798c;
  if (*DAT_0e07798c != '\0') {
    iVar6 = *DAT_0e077990;
    iVar7 = DAT_0e077990[1];
    puVar9 = *(uint **)(iVar6 + 0x10);
    iVar6 = (**(code **)(*(int *)(iVar6 + 8) + 4))(iVar6,local_20);
    puVar3 = DAT_0e07799c;
    if (iVar6 == 0) {
      if (((*puVar9 ^ local_20[0]) & 1 << (sbyte)iVar7) == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = 1;
      }
    }
    if ((iVar6 == 1) && (*(char *)(DAT_0e077994 + 10) == '\0')) {
      *DAT_0e077998 = 0;
      *puVar3 = 1;
      FUN_0e06dad8();
      thunk_FUN_0e09628c(0x271,0);
      FUN_0e0780e8();
      FUN_0e077e1c();
      FUN_0e078008();
      FUN_0e077ef0();
      FUN_0e0732b4();
      thunk_FUN_0e07d864(0);
      FUN_0e076ba0();
      FUN_0e077048(0x16,local_20,6);
      thunk_FUN_0e09467c(1000);
      thunk_FUN_0e0849ac();
      FUN_0e078d7c();
      FUN_0e076e44();
      FUN_0e072fd0(0);
      thunk_FUN_0e085724(1);
      thunk_FUN_0e0855c8();
      thunk_FUN_0e08504c();
      iVar7 = *(int *)(DAT_0e0779a0 + 0xc);
      sVar1 = *(sbyte *)(DAT_0e0779a0 + 0x10);
      puVar9 = *(uint **)(iVar7 + 0x10);
      iVar7 = (**(code **)(*(int *)(iVar7 + 8) + 4))(iVar7,&local_24);
      if ((iVar7 != 0) || (puVar8 = DAT_0e0779a4, ((local_24 ^ *puVar9) & 1 << sVar1) != 0)) {
        FUN_0e074d48();
        thunk_FUN_0e07e19c(1);
        thunk_FUN_0e07e218();
        *DAT_0e0779c0 = 1;
        puVar8 = DAT_0e0779a4;
        thunk_FUN_0e0950f0(DAT_0e0779c4,extraout_r1,0,0);
        *puVar8 = 1;
        thunk_FUN_0e0950f0(DAT_0e0779c4,extraout_r1_00,0xffffffff,0xffffffff);
        thunk_FUN_0e07e19c(0);
        thunk_FUN_0e07e1d8();
      }
      puVar4 = DAT_0e0779ac;
      *DAT_0e0779a8 = 0;
      puVar5 = DAT_0e0779b0;
      *puVar3 = 0;
      *puVar5 = 0xff;
      puVar3 = DAT_0e0779b4;
      *puVar4 = 0;
      *puVar3 = 0;
      puVar3 = DAT_0e0779bc;
      *DAT_0e0779b8 = 0;
      *puVar3 = 0xff;
      *puVar8 = 0;
      thunk_FUN_0e08497c();
      thunk_FUN_0e07f794();
      FUN_0e076d0c();
      thunk_FUN_0e085640();
      thunk_FUN_0e0850c4();
      thunk_FUN_0e07ed0c();
      thunk_FUN_0e07ee28();
      FUN_0e072fe0();
      FUN_0e076b80();
      thunk_FUN_0e085724(0);
      FUN_0e077eb0();
      FUN_0e073280();
      *pcVar2 = '\0';
    }
  }
  return;
}


