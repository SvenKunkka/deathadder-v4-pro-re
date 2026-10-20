/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c914. Types and names are inferred; NOT original source. */

/* WARNING: Control flow encountered bad instruction data */

void FUN_0e06c914(void)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  
  FUN_0e06c7bc(0);
  iVar3 = DAT_0e06ca10;
  iVar9 = iRam0e06ca0c + 0x800;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setMainStackPointer(iVar9);
  }
  setMainStackPointerLimit(iRam0e06ca0c);
  *(undefined1 *)(DAT_0e06ca10 + 0x22) = 0xe0;
  *(undefined1 *)(iVar3 + 0x1f) = 0x20;
  *(undefined1 *)(iVar3 + 0x18) = 0;
  *(undefined1 *)(iVar3 + 0x19) = 0;
  *(undefined1 *)(iVar3 + 0x1a) = 0;
  iVar4 = DAT_0e06ca14;
  *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) | 0x70000;
  *(undefined1 *)(iVar3 + 0x23) = 0;
  FUN_0e061178();
  FUN_0e061504();
  *(undefined4 *)(iVar3 + 0x28) = 0xffffffff;
  *(undefined4 *)(iVar3 + 0x2c) = 0xffffffff;
  FUN_0e06183c();
  FUN_0e061584();
  iVar3 = DAT_0e06ca18;
  *(undefined2 *)(iVar4 + 0xc) = 0x101;
  *(undefined4 *)(iVar4 + 0x74) = 0;
  *(undefined4 *)(iVar4 + 0x78) = 0;
  FUN_0e06eec4(iVar4);
  *(int *)(iVar3 + 8) = iVar4;
  FUN_0e06c758();
  FUN_0e06c7bc(1);
  iVar4 = DAT_0e06ca1c;
  FUN_0e06c7bc(2);
  FUN_0e06e268();
  uVar6 = DAT_0e06ca28;
  uVar8 = DAT_0e06ca24;
  uVar5 = DAT_0e06ca20;
  *(int *)(iVar3 + 0x14) = iVar4;
  uVar8 = FUN_0e06d8fc(iVar4,uVar8,0x400,uVar6,0,0,0,0,1,uVar5);
  *(byte *)(iVar4 + 0xd) = *(byte *)(iVar4 + 0xd) & 0xfb;
  FUN_0e06ddc0(iVar4);
  iVar7 = DAT_0e06ca2c;
  FUN_0e06d8fc(DAT_0e06ca2c,DAT_0e06ca30,0x140,DAT_0e06ca34,iVar3,0,0,0xf,1,0);
  uVar5 = DAT_0e06ca28;
  bVar1 = *(byte *)(iVar7 + 0xd);
  *(undefined1 *)(iVar3 + 0x10) = 0;
  *(int *)(iVar3 + 4) = iVar9;
  *(int *)(iVar3 + 0xc) = iVar7;
  *(byte *)(iVar7 + 0xd) = bVar1 & 0xfb;
  FUN_0e0614ac(iVar4,uVar8,uVar5);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


