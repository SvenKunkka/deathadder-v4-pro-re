/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0ff43c. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0ff43c(int *param_1,byte *param_2,uint param_3,undefined1 *param_4)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  char cVar10;
  
  iVar1 = param_1[8];
  if (iVar1 != 0) {
    cVar10 = *(char *)(iVar1 + 0x10);
    if (cVar10 != '\0') {
      if (*(int *)(iVar1 + 0xc) != 0) {
        return 0;
      }
      pbVar2 = (byte *)*param_1;
      pbVar8 = (byte *)param_1[3];
      if (pbVar8 <= pbVar2) goto LAB_1c0ff57e;
      if (param_1[2] == 0) goto LAB_1c0ff596;
      bVar4 = *pbVar2;
      bVar5 = bVar4 & 0x1f;
      if (bVar5 != 0x1f) goto LAB_1c0ff474;
      if (param_4 != (undefined1 *)0x0) goto LAB_1c0ff556;
LAB_1c0ff4be:
      if ((cVar10 != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
        return 0;
      }
LAB_1c0ff4c8:
      *(undefined4 *)(iVar1 + 0xc) = 7;
      return 0;
    }
    pbVar8 = (byte *)param_1[3];
    pbVar2 = (byte *)*param_1;
    if (pbVar8 <= pbVar2) goto LAB_1c0ff57e;
    if (param_1[2] == 0) {
LAB_1c0ff596:
      *(undefined4 *)(iVar1 + 0xc) = 3;
      return 0;
    }
    bVar4 = *pbVar2;
    bVar5 = bVar4 & 0x1f;
    if (bVar5 != 0x1f) goto LAB_1c0ff474;
    if (param_4 == (undefined1 *)0x0) goto LAB_1c0ff4c8;
LAB_1c0ff556:
    if (*(char *)(iVar1 + 0x11) != '\0') {
      if ((cVar10 != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
        return 0;
      }
      *(undefined4 *)(iVar1 + 0xc) = 0x15;
      return 0;
    }
    *param_4 = 1;
LAB_1c0ff55e:
    iVar6 = 1;
LAB_1c0ff560:
    iVar1 = *param_1;
    *param_1 = iVar6 + iVar1;
    param_1[1] = iVar1;
    param_1[2] = param_1[2] + -1;
    return 1;
  }
  pbVar2 = (byte *)*param_1;
  pbVar8 = (byte *)param_1[3];
  if (pbVar8 <= pbVar2) {
    return 0;
  }
  if (param_1[2] == 0) {
    return 0;
  }
  bVar4 = *pbVar2;
  bVar5 = bVar4 & 0x1f;
  if (bVar5 == 0x1f) {
    return 0;
  }
LAB_1c0ff474:
  if (bVar5 < 0x18) {
    if (pbVar2 + 1 <= pbVar8) {
      FUN_1c103512(param_2,0);
      *param_2 = bVar5;
      goto LAB_1c0ff55e;
    }
  }
  else {
    if (3 < (byte)(bVar5 - 0x18)) {
      if (iVar1 == 0) {
        return 0;
      }
      cVar10 = *(char *)(iVar1 + 0x10);
      goto LAB_1c0ff4be;
    }
    uVar7 = 1 << (uint)(byte)(bVar5 - 0x18);
    if (param_3 < uVar7) {
      if (iVar1 == 0) {
        return 0;
      }
      if ((*(char *)(iVar1 + 0x10) != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
        return 0;
      }
      *(undefined4 *)(iVar1 + 0xc) = 5;
      return 0;
    }
    iVar6 = uVar7 + 1;
    if (pbVar2 + iVar6 <= pbVar8) {
      FUN_1c103512(param_2,0);
      pbVar9 = (byte *)*param_1;
      pbVar2 = param_2 + -1;
      pbVar8 = pbVar9 + uVar7;
      do {
        pbVar3 = pbVar8 + -1;
        pbVar2 = pbVar2 + 1;
        *pbVar2 = *pbVar8;
        pbVar8 = pbVar3;
      } while (pbVar9 != pbVar3);
      if ((((param_1[8] == 0) || (*(char *)(param_1[8] + 0x11) != '\0')) && (2 < (byte)(bVar4 + 7)))
         && (iVar1 = FUN_1c0ff324(param_2,param_3), iVar6 != iVar1)) {
        iVar1 = param_1[8];
        if (iVar1 == 0) {
          return 0;
        }
        if ((*(char *)(iVar1 + 0x10) != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
          return 0;
        }
        *(undefined4 *)(iVar1 + 0xc) = 0x15;
        return 0;
      }
      goto LAB_1c0ff560;
    }
  }
  if (iVar1 == 0) {
    return 0;
  }
  if ((*(char *)(iVar1 + 0x10) != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
    return 0;
  }
LAB_1c0ff57e:
  *(undefined4 *)(iVar1 + 0xc) = 8;
  return 0;
}


