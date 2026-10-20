/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091940. Types and names are inferred; NOT original source. */

int FUN_0e091940(int *param_1,byte *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  
  iVar2 = DAT_0e091c58;
  uVar4 = (uint)*(byte *)(param_1 + 1);
  iVar1 = *param_1;
  *(undefined1 *)(DAT_0e091c58 + uVar4 * 0x28 + 0x23) = 0;
  if ((*(int *)(param_2 + 4) != 0) && ((*(uint *)(param_2 + 0xc) & 0xe0000000) != 0x20000000)) {
    return DAT_0e091c60;
  }
  if ((*param_2 - 2 < 2) && ((*(uint *)(param_2 + 0x10) & 0xe0000000) != 0x20000000)) {
    return DAT_0e091c60;
  }
  *(undefined4 *)(iVar1 + 0x308) = DAT_0e091c5c;
  iVar5 = DAT_0e091c74;
  iVar11 = iVar2 + uVar4 * 0x28;
  if (*(char *)(iVar11 + 0x24) != '\0') {
    *(undefined4 *)(iVar1 + 0x304) = *(undefined4 *)(iVar11 + 8);
    return iVar5;
  }
  *(bool *)(iVar11 + 0x24) = (param_3 & 0x14) == 0;
  *(byte *)(iVar11 + 0x20) = *param_2;
  *(byte *)(iVar11 + 0x21) = param_2[1];
  *(undefined4 *)(iVar11 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(iVar11 + 0x10) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(iVar11 + 0x14) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(iVar11 + 0x18) = *(undefined4 *)(param_2 + 8);
  *(uint *)(iVar11 + 0x1c) = param_3;
  *(byte *)(iVar11 + 0x25) = (byte)((param_3 << 0x1b) >> 0x1f);
  *(uint *)(iVar1 + 0x588) = (uint)param_2[1];
  *(undefined4 *)(iVar1 + 0x138) = 0;
  *(undefined4 *)(iVar1 + 0x128) = 0;
  *(undefined4 *)(iVar1 + 0x114) = 0;
  *(undefined4 *)(iVar1 + 0x104) = 0;
  *(uint *)(iVar1 + 0x74c) = (uint)((param_3 & 1) != 0);
  *(uint *)(iVar1 + 0x714) = (uint)((param_3 & 2) != 0);
  iVar11 = iVar2 + uVar4 * 0x28;
  iVar5 = DAT_0e091d64;
  switch(*param_2) {
  case 0:
    uVar6 = *(undefined4 *)(iVar11 + 0x10);
    *(undefined4 *)(iVar1 + 0x73c) = *(undefined4 *)(iVar11 + 0xc);
    *(undefined4 *)(iVar1 + 0x740) = uVar6;
    if ((int)(param_3 << 0x1a) < 0) {
      *(undefined4 *)(iVar1 + 0x200) = 0x100;
      *(undefined4 *)(iVar2 + uVar4 * 0x28 + 8) = 0x400;
    }
    else {
      *(undefined4 *)(iVar1 + 0x200) = 0x200;
      *(undefined4 *)(iVar2 + uVar4 * 0x28 + 8) = 2;
    }
    *(undefined4 *)(iVar1 + 0x10) = 1;
    iVar5 = DAT_0e091c64;
    break;
  case 1:
    uVar6 = 0x1000;
    uVar8 = *(undefined4 *)(iVar11 + 0xc);
    uVar10 = *(undefined4 *)(iVar11 + 0x10);
    goto LAB_0e091b2e;
  case 2:
    uVar6 = *(undefined4 *)(iVar11 + 0x10);
    *(undefined4 *)(iVar1 + 0x73c) = *(undefined4 *)(iVar11 + 0xc);
    *(undefined4 *)(iVar1 + 0x740) = uVar6;
    uVar6 = 0x1080;
    uVar8 = *(undefined4 *)(iVar11 + 0x14);
    uVar10 = *(undefined4 *)(iVar11 + 0x18);
LAB_0e091b2e:
    *(undefined4 *)(iVar1 + 0x704) = uVar8;
    *(undefined4 *)(iVar1 + 0x708) = uVar10;
    *(undefined4 *)(iVar1 + 0x200) = uVar6;
    *(undefined4 *)(iVar1 + 0x10) = 1;
    *(undefined4 *)(iVar2 + uVar4 * 0x28 + 8) = 2;
    iVar5 = DAT_0e091c64;
    break;
  case 3:
    *(undefined4 *)(iVar1 + 0x200) = 0x100;
    uVar6 = *(undefined4 *)(iVar11 + 0x10);
    *(undefined4 *)(iVar1 + 0x73c) = *(undefined4 *)(iVar11 + 0xc);
    *(undefined4 *)(iVar1 + 0x740) = uVar6;
    *(undefined4 *)(iVar1 + 0x50) = 1;
    iVar5 = *(int *)(iVar1 + 0x16c);
    while (iVar5 != 0) {
      *(undefined4 *)(iVar1 + 0x16c) = 0;
      iVar5 = *(int *)(iVar1 + 0x16c);
    }
    uVar6 = *(undefined4 *)(iVar11 + 0x18);
    *(undefined4 *)(iVar1 + 0x73c) = *(undefined4 *)(iVar11 + 0x14);
    *(undefined4 *)(iVar1 + 0x740) = uVar6;
    *(undefined4 *)(iVar2 + uVar4 * 0x28 + 8) = 0x400;
    iVar5 = DAT_0e091c64;
  }
  iVar9 = *(int *)(iVar2 + uVar4 * 0x28);
  iVar7 = iVar2 + uVar4 * 0x28;
  if (((param_3 & 8) == 0) && (*param_2 != 3)) {
    if (*param_2 == 1) {
      *(undefined4 *)(iVar1 + 0x28) = 1;
      if (iVar9 == 0) {
        if (*(int *)(iVar7 + 0x10) == 0) {
          *(undefined4 *)(iVar1 + 4) = 1;
        }
        uVar3 = 0;
LAB_0e091c96:
        if (uVar3 == 0) {
          uVar3 = 0;
          if (*(int *)(iVar1 + 0x128) != 0) {
            uVar3 = 0x400;
            *(undefined4 *)(iVar1 + 0x128) = 0;
          }
          if (*(int *)(iVar1 + 0x104) == 0) goto code_r0x0e091cb8;
          *(undefined4 *)(iVar1 + 0x104) = 0;
          if (*(int *)(iVar1 + 0x114) != 0) {
            uVar3 = uVar3 | 2;
            goto LAB_0e091cc2;
          }
        }
      }
      goto LAB_0e091c22;
    }
    if (iVar9 == 0) {
      iVar7 = *(int *)(iVar7 + 0x10);
      *(undefined4 *)(iVar1 + 0x50) = 1;
      if (iVar7 == 0) {
        *(undefined4 *)(iVar1 + 4) = 1;
      }
      uVar3 = 0;
LAB_0e091bce:
      if (uVar3 == 0) {
        uVar3 = 0;
        if (*(int *)(iVar1 + 0x128) != 0) {
          *(undefined4 *)(iVar1 + 0x128) = 0;
          uVar3 = 0x400;
        }
        if (*(int *)(iVar1 + 0x104) == 0) goto code_r0x0e091bec;
        *(undefined4 *)(iVar1 + 0x104) = 0;
        if (*(int *)(iVar1 + 0x114) != 0) {
          uVar3 = uVar3 | 2;
          goto LAB_0e091bf4;
        }
      }
LAB_0e091c22:
      if (*(int *)(param_2 + 4) != 0) goto LAB_0e091aac;
      if (*(int *)(iVar2 + uVar4 * 0x28) == 0) goto LAB_0e091ab8;
    }
    else {
      *(undefined4 *)(iVar1 + 0x50) = 1;
      if (*(int *)(param_2 + 4) != 0) goto LAB_0e091b62;
    }
    *(undefined4 *)(iVar1 + 4) = 1;
  }
LAB_0e091aac:
  if (*(int *)(iVar2 + uVar4 * 0x28) == 0) {
LAB_0e091ab8:
    uVar3 = *(uint *)(iVar1 + 0x4c4);
    *(uint *)(iVar1 + 0x4c4) = uVar3;
    *(undefined1 *)(iVar2 + uVar4 * 0x28 + 0x24) = 0;
    if (uVar3 == 0) {
      if ((-1 < (int)(param_3 << 0x19)) && (iVar2 = FUN_0e091518(iVar1,iVar11), iVar2 == 0)) {
        iVar5 = DAT_0e091c70;
      }
    }
    else {
      iVar5 = DAT_0e091c70;
      if ((uVar3 & 1) != 0) {
        iVar5 = DAT_0e091c68;
      }
      if ((uVar3 & 2) != 0) {
        iVar5 = DAT_0e091c6c;
      }
      if ((uVar3 & 4) != 0) {
        iVar5 = DAT_0e091c68 + 2;
      }
    }
    return iVar5;
  }
LAB_0e091b62:
  if ((int)(param_3 << 0x1d) < 0) {
    *(undefined4 *)(iVar2 + uVar4 * 0x28 + 8) = 0;
  }
  if (-1 < (int)(param_3 << 0x19)) {
    iVar11 = iVar2 + uVar4 * 0x28;
    *(uint *)(iVar11 + 8) = *(uint *)(iVar11 + 8) | 2;
  }
  iVar2 = iVar2 + uVar4 * 0x28;
  *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | 0x20;
  *(undefined4 *)(iVar1 + 0x304) = *(undefined4 *)(iVar2 + 8);
  return iVar5;
code_r0x0e091cb8:
  if (*(int *)(iVar1 + 0x114) != 0) {
LAB_0e091cc2:
    *(undefined4 *)(iVar1 + 0x114) = 0;
    *(undefined4 *)(iVar1 + 4) = 1;
  }
  goto LAB_0e091c96;
code_r0x0e091bec:
  if (*(int *)(iVar1 + 0x114) != 0) {
LAB_0e091bf4:
    *(undefined4 *)(iVar1 + 0x114) = 0;
    if (*(int *)(iVar1 + 0x138) == 0) {
      *(undefined4 *)(iVar1 + 0x10) = 1;
      *(undefined4 *)(iVar1 + 4) = 1;
    }
    else {
      *(undefined4 *)(iVar1 + 0x138) = 0;
      if ((*(uint *)(iVar1 + 0x200) & 0x200) == 0) {
        *(undefined4 *)(iVar1 + 0x10) = 1;
        *(undefined4 *)(iVar1 + 4) = 1;
        uVar3 = 0;
      }
      if (-1 < (int)(*(uint *)(iVar1 + 0x200) << 0x17)) goto LAB_0e091bce;
      if (*(int *)(iVar1 + 0x128) != 0) {
        *(undefined4 *)(iVar1 + 0x128) = 0;
      }
    }
    uVar3 = 0;
  }
  goto LAB_0e091bce;
}


