/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23020000. Types and names are inferred; NOT original source. */

void ram_candidate_23020000(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  
  DAT_230076b4 = (ushort)param_1;
  uVar2 = (ushort)(param_1 >> 0x1f);
  DAT_230076b2 = (ushort)param_2;
  uVar1 = (ushort)(param_2 >> 0x1f);
  DAT_230076b0 = (DAT_230076b4 ^ uVar2) - uVar2;
  DAT_230076ae = (DAT_230076b2 ^ uVar1) - uVar1;
  iVar11 = (int)DAT_230076b0;
  iVar12 = (int)DAT_230076ae;
  iVar4 = iVar11;
  iVar9 = iVar12;
  DAT_230076aa = DAT_230076ae;
  DAT_230076ac = DAT_230076b0;
  if (DAT_23007723 == '\x01') {
    bVar8 = DAT_23004a5f;
    if (DAT_23004a5f < 2) {
LAB_230202a0:
      DAT_230076ac = (short)(iVar11 << 3);
      DAT_230076aa = (short)(iVar12 << 3);
      iVar4 = (int)DAT_230076ac;
      iVar9 = (int)DAT_230076aa;
      goto LAB_2302005a;
    }
LAB_23020240:
    if (bVar8 == 2) {
      DAT_230076ac = (short)(iVar11 << 2);
      DAT_230076aa = (short)(iVar12 << 2);
      iVar4 = (int)DAT_230076ac;
      iVar9 = (int)DAT_230076aa;
      goto LAB_2302005a;
    }
    if (bVar8 < 5) {
      DAT_230076ac = (short)(iVar11 << 1);
      DAT_230076aa = (short)(iVar12 << 1);
      iVar4 = (int)DAT_230076ac;
      iVar9 = (int)DAT_230076aa;
      goto LAB_2302005a;
    }
    if (bVar8 < 9) goto LAB_2302005a;
    if (bVar8 < 0x11) goto LAB_230202c0;
    if (bVar8 < 0x21) goto LAB_23020340;
  }
  else {
    if (DAT_23007723 != '\x04') goto LAB_2302005a;
    if (DAT_2300779e != '\0') {
      bVar8 = DAT_23004a5d;
      if (1 < DAT_23004a5d) goto LAB_23020240;
      goto LAB_230202a0;
    }
    if (DAT_23004a5c == 1) goto LAB_2302005a;
    if (DAT_23004a5c < 3) {
LAB_230202c0:
      iVar4 = iVar11 >> 1;
      iVar9 = iVar12 >> 1;
      DAT_230076aa = (short)(iVar12 >> 1);
      DAT_230076ac = (short)(iVar11 >> 1);
      goto LAB_2302005a;
    }
    if (DAT_23004a5c < 5) {
LAB_23020340:
      iVar4 = iVar11 >> 2;
      iVar9 = iVar12 >> 2;
      DAT_230076aa = (short)(iVar12 >> 2);
      DAT_230076ac = (short)(iVar11 >> 2);
      goto LAB_2302005a;
    }
  }
  iVar4 = iVar11 >> 3;
  iVar9 = iVar12 >> 3;
  DAT_230076aa = (short)(iVar12 >> 3);
  DAT_230076ac = (short)(iVar11 >> 3);
LAB_2302005a:
  thunk_FUN_0e07925c(iVar4 * iVar4 + iVar9 * iVar9);
  thunk_FUN_0e0971d0();
  uVar2 = thunk_FUN_0e079330();
  if (uVar2 < 0xfa) {
    if (uVar2 == 0) {
      uVar10 = 0;
    }
    else {
      uVar10 = (uint)(ushort)(uVar2 - 1);
    }
  }
  else {
    uVar10 = 0xf9;
  }
  DAT_230076a8 = (undefined2)uVar10;
  DAT_230004f8 = 0x3f800000;
  if (*(byte *)((int)&DAT_23004a54 + DAT_23004a50._1_1_ + 1) <= uVar10) {
    switch((uint)DAT_23004a50._1_1_) {
    case 0:
      DAT_230004f8 = *(undefined4 *)(&DAT_230061b4 + uVar10 * 4);
      break;
    case 1:
      DAT_230004f8 = *(undefined4 *)(&DAT_23005bd4 + uVar10 * 4);
      break;
    case 2:
      DAT_230004f8 = *(undefined4 *)(&DAT_230055f4 + uVar10 * 4);
      break;
    case 3:
      DAT_230004f8 = *(undefined4 *)(&DAT_23005014 + uVar10 * 4);
    }
  }
  uVar7 = DAT_230004f8;
  uVar5 = thunk_FUN_0e0794e4(iVar11);
  uVar10 = (uint)DAT_230076b6;
  uVar5 = thunk_FUN_0e078e50(uVar5,uVar7);
  if (uVar10 == 0) {
    uVar5 = FUN_2302c568(uVar5,DAT_23004e14);
    sVar3 = thunk_FUN_0e07958c();
    uVar6 = thunk_FUN_0e0794e4((int)sVar3);
    DAT_23004dc8 = thunk_FUN_0e079378(uVar5,uVar6);
    DAT_230076a2 = sVar3;
    if (param_1 < 0) {
      DAT_230076a2 = -sVar3;
    }
    DAT_23004e1c = uVar5;
    DAT_230076a6 = sVar3;
    uVar5 = thunk_FUN_0e0794e4(iVar12);
    uVar7 = thunk_FUN_0e078e50(uVar5,uVar7);
    uVar7 = FUN_2302c568(uVar7,DAT_23004dc4);
    DAT_23004e18 = uVar7;
    sVar3 = thunk_FUN_0e07958c();
    DAT_230076a4 = sVar3;
    uVar5 = thunk_FUN_0e0794e4((int)sVar3);
    DAT_23004d78 = thunk_FUN_0e079378(uVar7,uVar5);
    if (-1 < param_2) {
      DAT_230076a0 = sVar3;
      DAT_230076b6 = 1;
      return;
    }
    DAT_230076a0 = -sVar3;
    DAT_230076b6 = 1;
    return;
  }
  uVar5 = FUN_2302c568(uVar5,(&DAT_23004dc8)[uVar10 - 1]);
  sVar3 = thunk_FUN_0e07958c();
  uVar6 = thunk_FUN_0e0794e4((int)sVar3);
  uVar6 = thunk_FUN_0e079378(uVar5,uVar6);
  DAT_230076a2 = sVar3;
  if (param_1 < 0) {
    DAT_230076a2 = -sVar3;
  }
  (&DAT_23004dc8)[uVar10] = uVar6;
  DAT_23004e1c = uVar5;
  DAT_230076a6 = sVar3;
  uVar5 = thunk_FUN_0e0794e4(iVar12);
  uVar7 = thunk_FUN_0e078e50(uVar5,uVar7);
  uVar7 = FUN_2302c568(uVar7,(&DAT_23004d78)[uVar10 - 1]);
  DAT_23004e18 = uVar7;
  sVar3 = thunk_FUN_0e07958c();
  DAT_230076a4 = sVar3;
  uVar5 = thunk_FUN_0e0794e4((int)sVar3);
  uVar7 = thunk_FUN_0e079378(uVar7,uVar5);
  (&DAT_23004d78)[uVar10] = uVar7;
  if (param_2 < 0) {
    sVar3 = -sVar3;
  }
  DAT_230076b6 = (ushort)(uVar10 + 1);
  if (0x13 < (uVar10 + 1 & 0xffff)) {
    DAT_230076b6 = 0;
  }
  DAT_230076a0 = sVar3;
  return;
}


