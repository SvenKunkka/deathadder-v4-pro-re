/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302455c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2302455c(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  int iVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  undefined local_30;
  byte local_2f;
  char local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  
  iVar10 = param_1 * 0xf84;
  cVar9 = (&DAT_230034fc)[iVar10];
  if ((char)(&DAT_230034fc)[iVar10] < '\x01') {
    return;
  }
  uVar1 = (&DAT_230034fe)[iVar10];
  iVar2 = FUN_230209ec(uVar1);
  uVar3 = FUN_230209f0(uVar1);
  iVar4 = FUN_230209f8(uVar1);
  uVar5 = FUN_230209e4(uVar1);
  if (iVar4 == 0) {
    cVar9 = (&DAT_230034ff)[iVar10];
    if (cVar9 == '+') {
      DAT_230033d2 = *(ushort *)(&DAT_23003501 + iVar10) << 8 |
                     *(ushort *)(&DAT_23003501 + iVar10) >> 8;
      DAT_230033d4 = *(ushort *)(&DAT_23003503 + iVar10) << 8 |
                     *(ushort *)(&DAT_23003503 + iVar10) >> 8;
      DAT_230033ce = (byte)(&DAT_23003500)[iVar10] & 0x3f;
      DAT_230033d0 = (ushort)((byte)(&DAT_23003500)[iVar10] >> 6);
      FUN_2302233c(0,2);
    }
    else if (cVar9 == ',') {
      (&DAT_2300341e)[param_1 * 0x7c2] = (ushort)(byte)(&DAT_23003500)[iVar10];
      (&DAT_23003420)[param_1 * 0x7c2] =
           *(ushort *)(&DAT_23003501 + iVar10) << 8 | *(ushort *)(&DAT_23003501 + iVar10) >> 8;
    }
    else if (cVar9 == '\x17') {
      (&DAT_23003474)[param_1 * 0x3e1] =
           (*(ushort *)(&DAT_23003500 + iVar10) & 0xff) << 8 |
           (uint)(*(ushort *)(&DAT_23003500 + iVar10) >> 8);
    }
    FUN_2302552c(param_1,(&DAT_23003451)[param_1 * 0xf84]);
    goto LAB_23024606;
  }
  if (*(byte *)((int)&DAT_230033e8 + iVar4 + iVar10 + 0xb7) == uVar5) {
    if (iVar4 == 1) {
      if (((&DAT_23003485)[iVar10] == '\x01') && (iVar2 == 0)) {
        DAT_230030a6 = 0;
        _DAT_230030a2 = 0;
      }
      (&DAT_23003474)[param_1 * 0x3e1] = 0;
    }
    goto LAB_23024606;
  }
  *(char *)((int)&DAT_230033e8 + iVar4 + iVar10 + 0xb7) = (char)uVar5;
  if (iVar4 == 1) {
    if ((iVar2 == 1) && ((byte)(&DAT_2300348e)[iVar10] != uVar3)) {
      uVar6 = 0;
      (&DAT_2300348e)[iVar10] = (char)uVar3;
      uVar3 = uVar6;
      uVar5 = uVar6;
    }
    else {
      uVar6 = (uint)(byte)DAT_230030a6;
      uVar3 = _DAT_230030a2 & 0xffff;
      uVar5 = _DAT_230030a2 >> 0x10;
    }
    _DAT_230030a2 =
         (*(ushort *)(&DAT_23003501 + iVar10) & 0xff) << 8 |
         (uint)(*(ushort *)(&DAT_23003501 + iVar10) >> 8);
    iVar8 = _DAT_230030a2 - uVar3;
    uVar3 = (*(ushort *)(&DAT_23003503 + iVar10) & 0xff) << 8 |
            (uint)(*(ushort *)(&DAT_23003503 + iVar10) >> 8);
    iVar11 = uVar3 - uVar5;
    _DAT_230030a2 = _DAT_230030a2 | uVar3 << 0x10;
    cVar9 = (&DAT_23003500)[iVar10];
    local_2e = cVar9 - (char)uVar6;
    local_2b = (undefined1)((uint)iVar11 >> 8);
    local_2f = (&DAT_230034ff)[iVar10];
    uVar3 = (uint)local_2f;
    uVar5 = (uint)cVar9;
    local_2a = (undefined1)iVar11;
    local_2d = (undefined1)((uint)iVar8 >> 8);
    local_2c = (undefined1)iVar8;
    if ((&DAT_23003485)[param_1 * 0xf84] == '\0') {
      DAT_230030a6 = CONCAT11(local_2f,cVar9);
    }
    else {
      if (iVar2 != 1) {
        uVar5 = 0;
        uVar3 = uVar5;
        _DAT_230030a2 = uVar5;
      }
      DAT_230030a6 = CONCAT11((char)uVar3,(char)uVar5);
    }
    local_30 = 0;
    cVar9 = '\a';
    puVar7 = &local_30;
LAB_230245d6:
    FUN_230254a0(0,iVar4,puVar7,cVar9,(&DAT_23003451)[param_1 * 0xf84]);
  }
  else {
    cVar9 = cVar9 + -2;
    if ('\0' < cVar9) {
      puVar7 = &DAT_230034ff + iVar10;
      goto LAB_230245d6;
    }
  }
  (&DAT_23003474)[param_1 * 0x3e1] = 0;
  DAT_230033dc._2_2_ = DAT_230033dc._2_2_ + 1;
LAB_23024606:
  DAT_230033dc._0_2_ = (short)DAT_230033dc + 1;
  return;
}


