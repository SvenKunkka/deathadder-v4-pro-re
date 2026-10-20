/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0773e0. Types and names are inferred; NOT original source. */

void FUN_0e0773e0(byte param_1,int param_2)

{
  char cVar1;
  byte *pbVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  piVar3 = DAT_0e07748c;
  pbVar2 = DAT_0e077488;
  DAT_0e077488[1] = 0;
  piVar5 = DAT_0e077494;
  puVar4 = DAT_0e077490;
  cVar1 = *(char *)((int)piVar3 + 2);
  *DAT_0e077490 = 2;
  *pbVar2 = param_1 & 0x7f;
  *piVar5 = param_2 + 2;
  if (cVar1 == -0x72) {
    if ((DAT_0e0774a4 & (uint)pbVar2) != 0x2f000000) {
      if ((DAT_0e0774a8 & (uint)pbVar2) != DAT_0e0774ac) goto LAB_0e07745e;
    }
LAB_0e07746a:
    uVar10 = DAT_0e07749c;
    if (((DAT_0e0774a4 & DAT_0e07749c) == 0x2f000000) ||
       ((DAT_0e0774a8 & DAT_0e07749c) == DAT_0e0774ac)) goto LAB_0e07741e;
  }
  else {
    if ((DAT_0e077498 & (uint)pbVar2) != 0x2fc00000) {
LAB_0e07745e:
      thunk_FUN_0e085ff8(DAT_0e0774b0);
      if (*(char *)((int)piVar3 + 2) == -0x72) goto LAB_0e07746a;
    }
    uVar10 = DAT_0e07749c;
    if ((DAT_0e077498 & DAT_0e07749c) == 0x2fc00000) goto LAB_0e07741e;
  }
  uVar10 = DAT_0e07749c;
  thunk_FUN_0e085ff8(DAT_0e0774b4);
LAB_0e07741e:
  iVar9 = *piVar3;
  uVar7 = *puVar4;
  *(byte **)(iVar9 + 0x73c) = pbVar2;
  *(undefined4 *)(iVar9 + 0x740) = uVar7;
  iVar8 = *piVar5;
  *(uint *)(iVar9 + 0x704) = uVar10;
  *(int *)(iVar9 + 0x708) = iVar8;
  puVar6 = DAT_0e0774a0;
  *(undefined4 *)(iVar9 + 0x108) = 0;
  *puVar6 = 1;
  return;
}


