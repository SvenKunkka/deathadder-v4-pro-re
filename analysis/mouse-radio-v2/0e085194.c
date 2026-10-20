/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e085194. Types and names are inferred; NOT original source. */

void FUN_0e085194(void)

{
  char cVar1;
  char cVar2;
  short sVar3;
  ushort uVar4;
  char *pcVar5;
  int iVar6;
  undefined4 in_r3;
  uint uVar7;
  code *pcVar8;
  short *psVar9;
  
  pcVar5 = DAT_0e085314;
  if (*(char *)(DAT_0e085310 + (uint)*(byte *)(DAT_0e08530c + 1) * 0xe + 8) == '\0') {
    return;
  }
  if (9 < (byte)DAT_0e085314[6]) {
    iVar6 = *(int *)(*(int *)(DAT_0e08530c + 0xc) + 8);
    if ((1 << *(sbyte *)(DAT_0e08530c + 0x10) & **(uint **)(*(int *)(DAT_0e08530c + 0xc) + 0x10)) ==
        0) {
      pcVar8 = *(code **)(iVar6 + 0xc);
    }
    else {
      pcVar8 = *(code **)(iVar6 + 0x10);
    }
    (*pcVar8)();
    FUN_0e097512(DAT_0e085314,0,0x34);
    psVar9 = DAT_0e085318;
    pcVar5[2] = '\x01';
    pcVar5[3] = '\0';
    pcVar5[0xc] = 'P';
    pcVar5[0xd] = '\0';
    *(undefined1 *)((int)psVar9 + 0xb) = 0;
    return;
  }
  cVar1 = DAT_0e085314[0xf];
  if (cVar1 == '\0') goto LAB_0e0851b6;
  if (*DAT_0e08531c == '\0') {
    cVar2 = DAT_0e085314[0xe];
    pcVar5[8] = '\0';
    pcVar5[9] = '\0';
    pcVar5[10] = '\0';
    pcVar5[0xb] = '\0';
    if (cVar2 == '\0') goto LAB_0e08522e;
    pcVar5[0xe] = '\0';
    pcVar5[0xc] = 'P';
    pcVar5[0xd] = '\0';
    pcVar5[0x10] = '\x01';
    if (pcVar5[0x11] != '\0') goto LAB_0e0851b6;
  }
  else {
    uVar7 = *(uint *)(DAT_0e085314 + 8);
    if (uVar7 == 1000) {
      iVar6 = *(int *)(*(int *)(DAT_0e08530c + 0xc) + 8);
      if ((1 << (uint)*(byte *)(DAT_0e08530c + 0x10) &
          **(uint **)(*(int *)(DAT_0e08530c + 0xc) + 0x10)) == 0) {
        pcVar8 = *(code **)(iVar6 + 0x10);
      }
      else {
        pcVar8 = *(code **)(iVar6 + 0xc);
      }
      (*pcVar8)();
      uVar7 = *(uint *)(pcVar5 + 8);
      pcVar5[0x12] = '\x01';
LAB_0e085224:
      if (2000 < uVar7) goto LAB_0e08522e;
    }
    else {
      if (uVar7 != 2000) goto LAB_0e085224;
      if (DAT_0e085314[0xe] == '\0') {
        DAT_0e085314[0x10] = '\x01';
        pcVar5[0xc] = -0x70;
        pcVar5[0xd] = '\x01';
        pcVar5[0xe] = '\x01';
      }
    }
    *(uint *)(pcVar5 + 8) = uVar7 + 1;
LAB_0e08522e:
    if (pcVar5[0x11] != '\0') goto LAB_0e0851b6;
    if (pcVar5[0x10] == '\0') {
      pcVar5[0x11] = '\0';
      goto LAB_0e0851b6;
    }
  }
  psVar9 = DAT_0e085318;
  if (*DAT_0e085318 == 0x602) {
    sVar3 = *(short *)(pcVar5 + 0xc);
    *(undefined1 *)((int)DAT_0e085318 + 0xb) = 1;
    psVar9[2] = sVar3;
  }
  pcVar5[0x10] = '\0';
  pcVar5[0x11] = cVar1;
LAB_0e0851b6:
  sVar3 = *(short *)(pcVar5 + 4);
  uVar4 = *(ushort *)(pcVar5 + 2);
  *(ushort *)(pcVar5 + 4) = sVar3 + 1U;
  if (uVar4 <= (ushort)(sVar3 + 1U)) {
    cVar1 = *pcVar5;
    pcVar5[2] = '\x01';
    pcVar5[3] = '\0';
    pcVar5[4] = '\0';
    pcVar5[5] = '\0';
    if (cVar1 == '\0') {
      iVar6 = DAT_0e085320 + (uint)(byte)pcVar5[1] * 0xc;
      iVar6 = FUN_0e084d4c(iVar6,*(undefined4 *)(iVar6 + 4),uVar4,(uint)(byte)pcVar5[1] * 3,in_r3);
      if (iVar6 != 0) {
        if ((byte)(pcVar5[1] + 1U) < 0x13) {
          pcVar5[1] = pcVar5[1] + 1U;
        }
        else {
          pcVar5[0xf] = '\x01';
          pcVar5[0] = '\x02';
          pcVar5[1] = '\0';
        }
        return;
      }
    }
    else if (cVar1 == '\x02') {
      if (pcVar5[0x11] != '\0') {
        uVar7 = (uint)(byte)pcVar5[1];
        psVar9 = DAT_0e085318 + uVar7 * 6;
        if (*(char *)((int)psVar9 + 0xb) != '\0') {
          iVar6 = FUN_0e084d4c(psVar9,*(undefined4 *)(psVar9 + 2),*(char *)((int)psVar9 + 0xb),uVar7
                               ,in_r3);
          if (iVar6 == 0) {
            return;
          }
          uVar7 = (uint)(byte)pcVar5[1];
        }
        *(undefined1 *)((int)psVar9 + 0xb) = 0;
        pcVar5[1] = '\0';
        if (uVar7 != 0xff) {
          pcVar5[0x11] = '\0';
        }
        return;
      }
    }
    else {
      pcVar5[0] = '\0';
      pcVar5[1] = '\0';
    }
  }
  return;
}


