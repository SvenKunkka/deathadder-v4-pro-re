/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091818. Types and names are inferred; NOT original source. */

undefined4 FUN_0e091818(int *param_1,byte *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  
  uVar4 = (uint)*(byte *)(param_1 + 1);
  iVar2 = *param_1;
  (&DAT_230072fb)[uVar4 * 0x28] = 0;
  if (((*(int *)(param_2 + 4) != 0) && ((*(uint *)(param_2 + 0xc) & 0xe0000000) != 0x20000000)) ||
     ((*param_2 - 2 < 2 && ((*(uint *)(param_2 + 0x10) & 0xe0000000) != 0x20000000)))) {
    return 0xbad000a;
  }
  *(undefined4 *)(iVar2 + 0x308) = 0x1ff86422;
  iVar1 = uVar4 * 0x28;
  if ((&DAT_230072fc)[iVar1] != '\0') {
    *(undefined4 *)(iVar2 + 0x304) = *(undefined4 *)(&DAT_230072e0 + iVar1);
    return 0xbad000b;
  }
  (&DAT_230072fc)[iVar1] = (param_3 & 0x14) == 0;
  (&DAT_230072f8)[iVar1] = *param_2;
  (&DAT_230072f9)[iVar1] = param_2[1];
  *(undefined4 *)(&DAT_230072e4 + iVar1) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(&DAT_230072e8 + iVar1) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(&DAT_230072ec + iVar1) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(&DAT_230072f0 + iVar1) = *(undefined4 *)(param_2 + 8);
  *(uint *)(&DAT_230072f4 + iVar1) = param_3;
  (&DAT_230072fd)[iVar1] = (byte)((param_3 << 0x1b) >> 0x1f);
  *(uint *)(iVar2 + 0x588) = (uint)param_2[1];
  *(undefined4 *)(iVar2 + 0x138) = 0;
  *(undefined4 *)(iVar2 + 0x128) = 0;
  *(undefined4 *)(iVar2 + 0x114) = 0;
  *(undefined4 *)(iVar2 + 0x104) = 0;
  *(uint *)(iVar2 + 0x74c) = (uint)((param_3 & 1) != 0);
  *(uint *)(iVar2 + 0x714) = (uint)((param_3 & 2) != 0);
  iVar1 = uVar4 * 0x28;
  switch(*param_2) {
  case 0:
    uVar5 = *(undefined4 *)(&DAT_230072e8 + iVar1);
    *(undefined4 *)(iVar2 + 0x73c) = *(undefined4 *)(&DAT_230072e4 + iVar1);
    *(undefined4 *)(iVar2 + 0x740) = uVar5;
    if ((int)(param_3 << 0x1a) < 0) {
      *(undefined4 *)(iVar2 + 0x200) = 0x100;
      *(undefined4 *)(&DAT_230072e0 + uVar4 * 0x28) = 0x400;
    }
    else {
      *(undefined4 *)(iVar2 + 0x200) = 0x200;
      *(undefined4 *)(&DAT_230072e0 + uVar4 * 0x28) = 2;
    }
    *(undefined4 *)(iVar2 + 0x10) = 1;
    break;
  case 1:
    uVar5 = 0x1000;
    uVar6 = *(undefined4 *)(&DAT_230072e4 + iVar1);
    uVar8 = *(undefined4 *)(&DAT_230072e8 + iVar1);
    goto LAB_0e091a06;
  case 2:
    uVar5 = *(undefined4 *)(&DAT_230072e8 + iVar1);
    *(undefined4 *)(iVar2 + 0x73c) = *(undefined4 *)(&DAT_230072e4 + iVar1);
    *(undefined4 *)(iVar2 + 0x740) = uVar5;
    uVar5 = 0x1080;
    uVar6 = *(undefined4 *)(&DAT_230072ec + iVar1);
    uVar8 = *(undefined4 *)(&DAT_230072f0 + iVar1);
LAB_0e091a06:
    *(undefined4 *)(iVar2 + 0x704) = uVar6;
    *(undefined4 *)(iVar2 + 0x708) = uVar8;
    *(undefined4 *)(iVar2 + 0x200) = uVar5;
    *(undefined4 *)(iVar2 + 0x10) = 1;
    *(undefined4 *)(&DAT_230072e0 + uVar4 * 0x28) = 2;
    break;
  case 3:
    *(undefined4 *)(iVar2 + 0x200) = 0x100;
    uVar5 = *(undefined4 *)(&DAT_230072e8 + iVar1);
    *(undefined4 *)(iVar2 + 0x73c) = *(undefined4 *)(&DAT_230072e4 + iVar1);
    *(undefined4 *)(iVar2 + 0x740) = uVar5;
    *(undefined4 *)(iVar2 + 0x50) = 1;
    iVar7 = *(int *)(iVar2 + 0x16c);
    while (iVar7 != 0) {
      *(undefined4 *)(iVar2 + 0x16c) = 0;
      iVar7 = *(int *)(iVar2 + 0x16c);
    }
    uVar5 = *(undefined4 *)(&DAT_230072f0 + iVar1);
    *(undefined4 *)(iVar2 + 0x73c) = *(undefined4 *)(&DAT_230072ec + iVar1);
    *(undefined4 *)(iVar2 + 0x740) = uVar5;
    *(undefined4 *)(&DAT_230072e0 + uVar4 * 0x28) = 0x400;
    break;
  default:
    uVar5 = 0xbad0004;
    goto LAB_0e09194a;
  }
  uVar5 = 0xbad0000;
LAB_0e09194a:
  iVar7 = *(int *)(&DAT_230072d8 + uVar4 * 0x28);
  if (((param_3 & 8) == 0) && (*param_2 != 3)) {
    if (*param_2 == 1) {
      *(undefined4 *)(iVar2 + 0x28) = 1;
      if (iVar7 == 0) {
        if (*(int *)(&DAT_230072e8 + uVar4 * 0x28) == 0) {
          *(undefined4 *)(iVar2 + 4) = 1;
        }
        uVar3 = 0;
LAB_0e091b6e:
        if (uVar3 == 0) {
          uVar3 = 0;
          if (*(int *)(iVar2 + 0x128) != 0) {
            uVar3 = 0x400;
            *(undefined4 *)(iVar2 + 0x128) = 0;
          }
          if (*(int *)(iVar2 + 0x104) == 0) goto code_r0x0e091b90;
          *(undefined4 *)(iVar2 + 0x104) = 0;
          if (*(int *)(iVar2 + 0x114) != 0) {
            uVar3 = uVar3 | 2;
            goto LAB_0e091b9a;
          }
        }
      }
      goto LAB_0e091afa;
    }
    if (iVar7 == 0) {
      iVar7 = *(int *)(&DAT_230072e8 + uVar4 * 0x28);
      *(undefined4 *)(iVar2 + 0x50) = 1;
      if (iVar7 == 0) {
        *(undefined4 *)(iVar2 + 4) = 1;
      }
      uVar3 = 0;
LAB_0e091aa6:
      if (uVar3 == 0) {
        uVar3 = 0;
        if (*(int *)(iVar2 + 0x128) != 0) {
          *(undefined4 *)(iVar2 + 0x128) = 0;
          uVar3 = 0x400;
        }
        if (*(int *)(iVar2 + 0x104) == 0) goto code_r0x0e091ac4;
        *(undefined4 *)(iVar2 + 0x104) = 0;
        if (*(int *)(iVar2 + 0x114) != 0) {
          uVar3 = uVar3 | 2;
          goto LAB_0e091acc;
        }
      }
LAB_0e091afa:
      if (*(int *)(param_2 + 4) != 0) goto LAB_0e091984;
      if (*(int *)(&DAT_230072d8 + uVar4 * 0x28) == 0) goto LAB_0e091990;
    }
    else {
      *(undefined4 *)(iVar2 + 0x50) = 1;
      if (*(int *)(param_2 + 4) != 0) goto LAB_0e091a3a;
    }
    *(undefined4 *)(iVar2 + 4) = 1;
  }
LAB_0e091984:
  if (*(int *)(&DAT_230072d8 + uVar4 * 0x28) == 0) {
LAB_0e091990:
    uVar3 = *(uint *)(iVar2 + 0x4c4);
    *(uint *)(iVar2 + 0x4c4) = uVar3;
    (&DAT_230072fc)[uVar4 * 0x28] = 0;
    if (uVar3 == 0) {
      if ((-1 < (int)(param_3 << 0x19)) &&
         (iVar2 = FUN_0e0913f0(iVar2,&DAT_230072d8 + iVar1), iVar2 == 0)) {
        uVar5 = 0xbad0001;
      }
    }
    else {
      uVar5 = 0xbad0001;
      if ((uVar3 & 1) != 0) {
        uVar5 = 0xbae0000;
      }
      if ((uVar3 & 2) != 0) {
        uVar5 = 0xbae0001;
      }
      if ((uVar3 & 4) != 0) {
        uVar5 = 0xbae0002;
      }
    }
    return uVar5;
  }
LAB_0e091a3a:
  if ((int)(param_3 << 0x1d) < 0) {
    *(undefined4 *)(&DAT_230072e0 + uVar4 * 0x28) = 0;
  }
  if (-1 < (int)(param_3 << 0x19)) {
    *(uint *)(&DAT_230072e0 + uVar4 * 0x28) = *(uint *)(&DAT_230072e0 + uVar4 * 0x28) | 2;
  }
  iVar1 = uVar4 * 0x28;
  *(uint *)(&DAT_230072e0 + iVar1) = *(uint *)(&DAT_230072e0 + iVar1) | 0x20;
  *(undefined4 *)(iVar2 + 0x304) = *(undefined4 *)(&DAT_230072e0 + iVar1);
  return uVar5;
code_r0x0e091b90:
  if (*(int *)(iVar2 + 0x114) != 0) {
LAB_0e091b9a:
    *(undefined4 *)(iVar2 + 0x114) = 0;
    *(undefined4 *)(iVar2 + 4) = 1;
  }
  goto LAB_0e091b6e;
code_r0x0e091ac4:
  if (*(int *)(iVar2 + 0x114) != 0) {
LAB_0e091acc:
    *(undefined4 *)(iVar2 + 0x114) = 0;
    if (*(int *)(iVar2 + 0x138) == 0) {
      *(undefined4 *)(iVar2 + 0x10) = 1;
      *(undefined4 *)(iVar2 + 4) = 1;
    }
    else {
      *(undefined4 *)(iVar2 + 0x138) = 0;
      if ((*(uint *)(iVar2 + 0x200) & 0x200) == 0) {
        *(undefined4 *)(iVar2 + 0x10) = 1;
        *(undefined4 *)(iVar2 + 4) = 1;
        uVar3 = 0;
      }
      if (-1 < (int)(*(uint *)(iVar2 + 0x200) << 0x17)) goto LAB_0e091aa6;
      if (*(int *)(iVar2 + 0x128) != 0) {
        *(undefined4 *)(iVar2 + 0x128) = 0;
      }
    }
    uVar3 = 0;
  }
  goto LAB_0e091aa6;
}


