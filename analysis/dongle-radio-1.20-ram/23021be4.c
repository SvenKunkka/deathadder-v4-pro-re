/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021be4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ram_candidate_23021be4(uint param_1)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined *puVar9;
  uint *puVar10;
  char cVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint local_30;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined local_28;
  undefined1 auStack_27 [3];
  
  if (DAT_23003234 == 4) {
    FUN_2302455c(DAT_230071a4);
    bVar2 = (&DAT_23003486)[(uint)DAT_230071a4 * 0xf84];
    if ((DAT_2300323e == 0) || (DAT_2300323e == 1)) {
      *(ushort *)((int)&DAT_230033e8 + ((byte)DAT_230032ca + 0x48) * 2) = (ushort)bVar2;
    }
    else if ((DAT_2300323e == 2) || (DAT_2300323e == 3)) {
      if ((ushort)(&DAT_23003232)[DAT_23003228 + 0x80] < (ushort)bVar2) {
        (&DAT_23003232)[DAT_23003228 + 0x80] = (ushort)bVar2;
      }
      return 1;
    }
    return 1;
  }
  if (DAT_23003234 != 1) {
    if (DAT_23003234 != 2) {
      return param_1;
    }
    uVar6 = (uint)DAT_230071a4;
    iVar12 = uVar6 * 0xf84;
    cVar11 = (&DAT_230034fc)[iVar12];
    uVar8 = uVar6;
    if ('\0' < (char)(&DAT_230034fc)[iVar12]) {
      uVar1 = (&DAT_230034fe)[iVar12];
      iVar7 = FUN_230209f8(uVar1);
      uVar8 = FUN_230209e4(uVar1);
      if (iVar7 == 0) {
        uVar8 = FUN_2302552c(uVar6,(&DAT_23003451)[iVar12]);
        return uVar8;
      }
      if (*(byte *)((int)&DAT_230033e8 + iVar7 + iVar12 + 0xb7) != uVar8) {
        *(char *)((int)&DAT_230033e8 + iVar7 + iVar12 + 0xb7) = (char)uVar8;
        puVar9 = &DAT_230034ff + iVar12;
        uVar8 = (uint)(char)(cVar11 + -2);
        if (iVar7 == 1) {
          local_28 = 0;
          thunk_FUN_0e06f35c(auStack_27,puVar9,uVar8);
          puVar9 = &local_28;
          uVar8 = (uint)(char)(cVar11 + -1);
        }
        local_30 = (uint)(byte)(&DAT_23003451)[uVar6 * 0xf84];
        uVar8 = FUN_230254a0(uVar6,iVar7,puVar9,uVar8 & 0xffff);
        (&DAT_23003474)[uVar6 * 0x3e1] = 0;
        return uVar8;
      }
    }
    return uVar8;
  }
  uVar8 = (uint)DAT_230071a4;
  iVar12 = uVar8 * 0xf84;
  cVar11 = (&DAT_230034fc)[iVar12];
  if ((char)(&DAT_230034fc)[iVar12] < '\x01') {
    return uVar8;
  }
  uVar1 = (&DAT_230034fe)[iVar12];
  iVar7 = FUN_230209f8(uVar1);
  uVar6 = FUN_230209e4(uVar1);
  if (iVar7 == 0) {
    if ((&DAT_230034ff)[iVar12] == '\x17') {
      (&DAT_23003474)[uVar8 * 0x3e1] =
           (*(ushort *)(&DAT_23003500 + iVar12) & 0xff) << 8 |
           (uint)(*(ushort *)(&DAT_23003500 + iVar12) >> 8);
    }
    else if ((&DAT_230034ff)[iVar12] == ',') {
      (&DAT_2300341e)[uVar8 * 0x7c2] = (ushort)(byte)(&DAT_23003500)[iVar12];
      (&DAT_23003420)[uVar8 * 0x7c2] =
           *(ushort *)(&DAT_23003501 + iVar12) << 8 | *(ushort *)(&DAT_23003501 + iVar12) >> 8;
    }
    uVar8 = FUN_2302552c(uVar8,(&DAT_23003451)[uVar8 * 0xf84]);
    return uVar8;
  }
  if (*(byte *)((int)&DAT_230033e8 + iVar7 + iVar12 + 0xb7) == uVar6) {
    if (iVar7 != 1) {
      return uVar6;
    }
    if ((&DAT_23003485)[iVar12] == '\x01') {
      _DAT_230030a2 = 0;
      DAT_230030a6 = 0;
    }
    (&DAT_23003474)[uVar8 * 0x3e1] = 0;
    return uVar6;
  }
  *(char *)((int)&DAT_230033e8 + iVar7 + iVar12 + 0xb7) = (char)uVar6;
  if (iVar7 == 1) {
    uVar3 = *(ushort *)(&DAT_23003501 + iVar12) << 8 | *(ushort *)(&DAT_23003501 + iVar12) >> 8;
    uVar4 = *(ushort *)(&DAT_23003503 + iVar12) << 8 | *(ushort *)(&DAT_23003503 + iVar12) >> 8;
    cVar5 = (char)DAT_230030a6;
    iVar14 = (int)_DAT_230030a2;
    iVar13 = (int)DAT_230030a4;
    if ((&DAT_23003485)[iVar12] == '\0') {
      _DAT_230030a2 = CONCAT22(uVar4,uVar3);
      DAT_230030a6 = CONCAT11((&DAT_230034ff)[iVar12],(&DAT_23003500)[iVar12]);
    }
    else {
      _DAT_230030a2 = 0;
      DAT_230030a6 = 0;
    }
    iVar14 = (uint)uVar3 - iVar14;
    iVar13 = (uint)uVar4 - iVar13;
    local_2c = (undefined1)iVar14;
    local_2b = (undefined1)((uint)iVar13 >> 8);
    local_2a = (undefined1)iVar13;
    cVar11 = '\a';
    puVar10 = &local_30;
    local_30 = (uint)CONCAT21(CONCAT11((char)((uint)iVar14 >> 8),(&DAT_23003500)[iVar12] - cVar5),
                              (&DAT_230034ff)[iVar12]) << 8;
  }
  else {
    cVar11 = cVar11 + -2;
    if (cVar11 < '\x01') goto LAB_230239ea;
    puVar10 = (uint *)(&DAT_230034ff + iVar12);
  }
  uVar6 = FUN_230254a0(0,iVar7,puVar10,cVar11,(&DAT_23003451)[uVar8 * 0xf84]);
LAB_230239ea:
  (&DAT_23003474)[uVar8 * 0x3e1] = 0;
  return uVar6;
}


