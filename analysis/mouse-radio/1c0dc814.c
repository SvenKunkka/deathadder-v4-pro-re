/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0dc814. Types and names are inferred; NOT original source. */

void FUN_1c0dc814(void)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  char cVar11;
  byte bVar12;
  short sVar13;
  uint uVar14;
  int iVar15;
  undefined4 uVar16;
  short sVar17;
  uint uVar18;
  
  pcVar4 = DAT_1c0dcb68;
  iVar15 = DAT_1c0dcb58;
  iVar2 = DAT_1c0dcb54;
  if (*(short *)(DAT_1c0dcb54 + 0x34) == 1) {
    if (*DAT_1c0dcb68 == '\0') {
      sVar17 = *(short *)(DAT_1c0dcb58 + 0xa8);
      if (sVar17 == 0) {
        if ((int)((uint)*(ushort *)(DAT_1c0dcb54 + 0x92) << 0x1f) < 0) {
          sVar17 = 2;
          do {
            puVar8 = (undefined4 *)FUN_1c0d9c7c(0,sVar17);
            sVar13 = sVar17 + 1;
            if (puVar8 != (undefined4 *)0x0) {
              *(undefined1 *)(iVar2 + 0xa8) = 1;
              goto LAB_1c0dcaf8;
            }
            sVar17 = sVar13;
          } while (sVar13 != 6);
        }
        uVar14 = 0;
        do {
          uVar18 = uVar14 & 0xffff;
          puVar8 = (undefined4 *)FUN_1c0d9c7c(0,uVar18);
          uVar14 = uVar14 + 1;
          if (puVar8 != (undefined4 *)0x0) goto LAB_1c0dcb1e;
        } while (uVar14 != 6);
LAB_1c0dc93a:
        cVar11 = pcVar4[1];
        *(undefined1 *)(iVar2 + 0xa8) = 1;
        if (cVar11 == '\0') goto LAB_1c0dc844;
        if (*(short *)(iVar15 + 0xa8) == 3) {
          *pcVar4 = '\x01';
          goto LAB_1c0dc97e;
        }
      }
      else {
        if (sVar17 == 1) {
          if (*(char *)(DAT_1c0dcb54 + 0xae) == '\x01') {
            return;
          }
          puVar8 = (undefined4 *)FUN_1c0d9c7c();
          if (puVar8 != (undefined4 *)0x0) {
            *(undefined1 *)(iVar2 + 0xa8) = 1;
            goto LAB_1c0dca00;
          }
          if (pcVar4[1] != '\0') {
            return;
          }
          goto LAB_1c0dc844;
        }
        if (sVar17 == 2) {
          if (*(char *)(DAT_1c0dcb54 + 0xae) == '\x01') {
            return;
          }
          if (DAT_1c0dcb68[1] != '\0') {
            puVar8 = (undefined4 *)FUN_1c0d9c7c(0,1);
            if (puVar8 == (undefined4 *)0x0) {
              return;
            }
LAB_1c0dc9fc:
            *(undefined1 *)(iVar2 + 0xa8) = 1;
            goto LAB_1c0dca00;
          }
          uVar14 = 0;
          do {
            uVar18 = uVar14 & 0xffff;
            puVar8 = (undefined4 *)FUN_1c0d9c7c(0,uVar18);
            uVar14 = uVar14 + 1;
            if (puVar8 != (undefined4 *)0x0) goto LAB_1c0dcb1e;
          } while (uVar14 != 6);
          goto LAB_1c0dc93a;
        }
        if (sVar17 != 3) goto LAB_1c0dc844;
        if (*(char *)(DAT_1c0dcb54 + 0xae) == '\x01') {
          return;
        }
        puVar8 = (undefined4 *)FUN_1c0d9c7c(0,1);
        if (puVar8 != (undefined4 *)0x0) goto LAB_1c0dc9fc;
        cVar11 = pcVar4[1];
        *(undefined1 *)(iVar2 + 0xa8) = 1;
        if (cVar11 == '\0') goto LAB_1c0dc844;
        if (*(short *)(iVar15 + 0xa8) == 3) goto LAB_1c0dcaea;
      }
      if (*pcVar4 != '\0') {
LAB_1c0dc95e:
        uVar6 = *(undefined1 *)(iVar2 + 0xa8);
        goto LAB_1c0dc980;
      }
    }
    else {
      cVar11 = DAT_1c0dcb68[1];
      *(undefined1 *)(DAT_1c0dcb54 + 0xa8) = 1;
      if (cVar11 != '\0') {
        if (*(short *)(iVar15 + 0xa8) == 3) {
LAB_1c0dcaea:
          *pcVar4 = '\x01';
        }
LAB_1c0dc97e:
        uVar6 = 1;
        goto LAB_1c0dc980;
      }
    }
  }
  else {
    uVar14 = 0;
    *(undefined1 *)(DAT_1c0dcb54 + 0xa8) = 1;
    do {
      sVar17 = (short)uVar14;
      puVar8 = (undefined4 *)FUN_1c0d9c7c(0,uVar14 & 0xffff);
      uVar14 = uVar14 + 1;
      iVar15 = DAT_1c0dcb58;
      if (puVar8 != (undefined4 *)0x0) goto LAB_1c0dc9aa;
    } while (uVar14 != 6);
  }
LAB_1c0dc844:
  *(undefined1 *)((uint)*(ushort *)(iVar15 + 0xa2) + iVar2 + 0x59) = 0;
  *(undefined2 *)(iVar2 + 0xa2) = 0xff;
  *(undefined1 *)(iVar2 + 0xfe) = 5;
  *(undefined1 *)(iVar2 + 0xa8) = 1;
  uVar6 = FUN_1c0d9e28(1,0,0);
  *(undefined1 *)(iVar2 + 0xff) = uVar6;
  uVar7 = FUN_1c0d9e34(0,*(undefined1 *)(iVar2 + 0xb2));
  uVar6 = *(undefined1 *)(iVar2 + (uint)*(ushort *)(iVar15 + 0xa2) * 2 + 0x9c);
  cVar11 = *(char *)(iVar2 + 0xb2) + '\x01';
  if (cVar11 == '\b') {
    cVar11 = '\x01';
  }
  *(char *)(iVar2 + 0xb2) = cVar11;
  *(undefined1 *)(iVar2 + 0x100) = uVar7;
  *(ushort *)(iVar2 + 0x102) = *(ushort *)(iVar2 + 0x98) << 8 | *(ushort *)(iVar2 + 0x98) >> 8;
  *(undefined1 *)(iVar2 + 0x101) = 0x17;
  uVar6 = FUN_1c0d9e28(1,*(undefined1 *)(iVar2 + 0xa6),uVar6);
  puVar8 = DAT_1c0dcb5c;
  *(undefined1 *)(iVar2 + 0xff) = uVar6;
  goto LAB_1c0dc8c2;
LAB_1c0dcb1e:
  sVar17 = (short)uVar18;
  *(undefined1 *)(iVar2 + 0xa8) = 1;
  if (uVar18 == 1) {
LAB_1c0dca00:
    bVar12 = *(byte *)((int)puVar8 + 3);
    pcVar4[1] = '\x01';
    bVar12 = bVar12 | *(byte *)(iVar2 + 0xa1);
    *(byte *)((int)puVar8 + 3) = bVar12;
    bVar12 = bVar12 | pcVar4[0x17];
    pcVar4[0x17] = bVar12;
    pcVar4[0x16] = pcVar4[0x16] + *(char *)(puVar8 + 1);
    uVar1 = *(ushort *)((int)puVar8 + 7);
    *(ushort *)(pcVar4 + 0x12) =
         (*(ushort *)((int)puVar8 + 5) << 8 | *(ushort *)((int)puVar8 + 5) >> 8) +
         *(short *)(pcVar4 + 0x12);
    *(ushort *)(pcVar4 + 0x14) = *(short *)(pcVar4 + 0x14) + (uVar1 << 8 | uVar1 >> 8);
    *(byte *)((int)puVar8 + 3) = bVar12;
    *(char *)(puVar8 + 1) = pcVar4[0x16];
    *(char *)((int)puVar8 + 5) = (char)((ushort)*(undefined2 *)(pcVar4 + 0x12) >> 8);
    *(char *)((int)puVar8 + 6) = (char)*(undefined2 *)(pcVar4 + 0x12);
    *(char *)((int)puVar8 + 7) = (char)((ushort)*(undefined2 *)(pcVar4 + 0x14) >> 8);
    uVar9 = puVar8[1];
    *(char *)(puVar8 + 2) = (char)*(undefined2 *)(pcVar4 + 0x14);
    *(undefined4 *)(pcVar4 + 2) = *puVar8;
    iVar5 = DAT_1c0dcb6c;
    *(undefined4 *)(DAT_1c0dcb6c + 4) = uVar9;
    *(undefined1 *)(iVar5 + 8) = *(undefined1 *)(puVar8 + 2);
    if (*(short *)(iVar15 + 0xa8) != 3) {
      *(undefined1 *)(iVar2 + 0xa8) = 0;
    }
    FUN_1c0d9bf8(0,1);
    if (pcVar4[1] != '\0') {
      if (*(short *)(iVar15 + 0xa8) == 3) {
        *pcVar4 = '\x01';
      }
LAB_1c0dcb1a:
      sVar17 = 0xff;
      goto LAB_1c0dc9aa;
    }
    sVar17 = 1;
    uVar6 = *(undefined1 *)(iVar2 + 0xa8);
  }
  else {
LAB_1c0dcaf8:
    cVar11 = pcVar4[1];
    *(undefined1 *)(iVar2 + 0xae) = 1;
    if (cVar11 == '\0') {
LAB_1c0dc9aa:
      uVar6 = *(undefined1 *)(iVar2 + 0xa8);
    }
    else {
      if (*(short *)(iVar15 + 0xa8) != 3) {
        if (*pcVar4 == '\0') goto LAB_1c0dcb1a;
        goto LAB_1c0dc95e;
      }
      uVar6 = *(undefined1 *)(iVar2 + 0xa8);
      *pcVar4 = '\x01';
LAB_1c0dc980:
      sVar17 = 0xff;
      pcVar4[5] = pcVar4[5] | *(byte *)(iVar2 + 0xa1);
      puVar8 = DAT_1c0dcb5c;
      *(undefined4 *)(iVar2 + 0xfe) = *(undefined4 *)(pcVar4 + 2);
      uVar7 = *(undefined1 *)(DAT_1c0dcb6c + 8);
      puVar8[1] = *(undefined4 *)(DAT_1c0dcb6c + 4);
      *(undefined1 *)(puVar8 + 2) = uVar7;
    }
  }
  uVar1 = *(ushort *)(iVar15 + 0xa2);
  *(undefined4 *)(iVar2 + 0x98) = 0;
  *(undefined1 *)((uint)uVar1 + iVar2 + 0x59) = 0;
  uVar7 = *(undefined1 *)(iVar2 + (uint)uVar1 * 2 + 0x9c);
  *(short *)(iVar2 + 0xa2) = sVar17;
  uVar6 = FUN_1c0d9e28(uVar6,*(undefined1 *)(iVar2 + 0xa6),uVar7);
  *(undefined1 *)((int)puVar8 + 1) = uVar6;
LAB_1c0dc8c2:
  puVar3 = DAT_1c0dcb60;
  uVar16 = *puVar8;
  uVar9 = puVar8[2];
  uVar10 = puVar8[3];
  DAT_1c0dcb60[1] = puVar8[1];
  iVar2 = DAT_1c0dcb64;
  *puVar3 = uVar16;
  puVar3[2] = uVar9;
  puVar3[3] = uVar10;
  *(undefined4 **)(iVar2 + 0xed0) = puVar8;
  return;
}


