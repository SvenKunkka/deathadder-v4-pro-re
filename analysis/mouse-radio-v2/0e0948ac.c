/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0948ac. Types and names are inferred; NOT original source. */

/* WARNING: Control flow encountered bad instruction data */

void FUN_0e0948ac(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined8 uVar9;
  
  uVar9 = FUN_0e0946d0(0);
  iVar3 = DAT_0e094978;
  iVar2 = DAT_0e094974;
  iVar8 = iRam0e094970 + 0xa00;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(iVar8);
  }
  setMainStackPointerLimit(iRam0e094970);
  *(undefined1 *)(DAT_0e094974 + 0x22) = 0xe0;
  *(undefined1 *)(iVar2 + 0x1f) = 0;
  *(undefined1 *)(iVar2 + 0x18) = 0;
  *(undefined1 *)(iVar2 + 0x19) = 0;
  *(undefined1 *)(iVar2 + 0x1a) = 0;
  iVar4 = DAT_0e09497c;
  *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) | 0x70000;
  *(undefined1 *)(iVar2 + 0x23) = 0;
  FUN_0e089d84((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),iVar8);
  FUN_0e08a128();
  *(undefined4 *)(iVar2 + 0x28) = 0xffffffff;
  *(undefined4 *)(iVar2 + 0x2c) = 0xffffffff;
  FUN_0e08a478();
  FUN_0e08a1c0();
  *(undefined2 *)(iVar3 + 0xc) = 0x101;
  *(undefined4 *)(iVar3 + 0x74) = 0;
  *(undefined4 *)(iVar3 + 0x78) = 0;
  FUN_0e096dc0(iVar3);
  *(int *)(iVar4 + 8) = iVar3;
  FUN_0e094684();
  FUN_0e0946d0(1);
  iVar2 = DAT_0e094980;
  FUN_0e0946d0(2);
  uVar5 = DAT_0e094984;
  FUN_0e096124();
  uVar6 = DAT_0e09498c;
  uVar7 = DAT_0e094988;
  *(int *)(iVar4 + 0x18) = iVar2;
  uVar7 = FUN_0e095838(iVar2,uVar6,0x400,uVar5,0,0,0,0,1,uVar7);
  *(byte *)(iVar2 + 0xd) = *(byte *)(iVar2 + 0xd) & 0xfb;
  FUN_0e095cfc(iVar2);
  FUN_0e094828(0);
  FUN_0e08a0d0(iVar2,uVar7,uVar5);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


