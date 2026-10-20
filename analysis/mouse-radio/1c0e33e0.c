/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e33e0. Types and names are inferred; NOT original source. */

void FUN_1c0e33e0(byte param_1,int param_2)

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
  
  piVar3 = DAT_1c0e348c;
  pbVar2 = DAT_1c0e3488;
  DAT_1c0e3488[1] = 0;
  piVar5 = DAT_1c0e3494;
  puVar4 = DAT_1c0e3490;
  cVar1 = *(char *)((int)piVar3 + 2);
  *DAT_1c0e3490 = 2;
  *pbVar2 = param_1 & 0x7f;
  *piVar5 = param_2 + 2;
  if (cVar1 == -0x72) {
    if ((DAT_1c0e34a4 & (uint)pbVar2) != 0x2f000000) {
      if ((DAT_1c0e34a8 & (uint)pbVar2) != DAT_1c0e34ac) goto LAB_1c0e345e;
    }
LAB_1c0e346a:
    uVar10 = DAT_1c0e349c;
    if (((DAT_1c0e34a4 & DAT_1c0e349c) == 0x2f000000) ||
       ((DAT_1c0e34a8 & DAT_1c0e349c) == DAT_1c0e34ac)) goto LAB_1c0e341e;
  }
  else {
    if ((DAT_1c0e3498 & (uint)pbVar2) != 0x2fc00000) {
LAB_1c0e345e:
      thunk_EXT_FUN_0e085ff8(DAT_1c0e34b0);
      if (*(char *)((int)piVar3 + 2) == -0x72) goto LAB_1c0e346a;
    }
    uVar10 = DAT_1c0e349c;
    if ((DAT_1c0e3498 & DAT_1c0e349c) == 0x2fc00000) goto LAB_1c0e341e;
  }
  uVar10 = DAT_1c0e349c;
  thunk_EXT_FUN_0e085ff8(DAT_1c0e34b4);
LAB_1c0e341e:
  iVar9 = *piVar3;
  uVar7 = *puVar4;
  *(byte **)(iVar9 + 0x73c) = pbVar2;
  *(undefined4 *)(iVar9 + 0x740) = uVar7;
  iVar8 = *piVar5;
  *(uint *)(iVar9 + 0x704) = uVar10;
  *(int *)(iVar9 + 0x708) = iVar8;
  puVar6 = DAT_1c0e34a0;
  *(undefined4 *)(iVar9 + 0x108) = 0;
  *puVar6 = 1;
  return;
}


