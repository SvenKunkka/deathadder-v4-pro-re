/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23028290. Types and names are inferred; NOT original source. */

void FUN_23028290(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  int iVar11;
  byte local_28;
  byte local_27;
  undefined2 local_26;
  undefined2 local_24;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  
  if (DAT_230077a7 == '\x01') {
    iVar11 = thunk_FUN_0e094c5c(&DAT_23006788,param_2,0,0);
    if (iVar11 != 0) {
      return;
    }
    iVar11 = FUN_2302a8a8(0x16,&local_28,0xc);
    thunk_FUN_0e094d58(&DAT_23006788);
    uVar2 = DAT_230077ac;
    uVar3 = DAT_230077ad;
    uVar4 = DAT_230077ae;
    uVar5 = DAT_230077af;
    uVar6 = DAT_230077b0;
    uVar7 = DAT_230077b1;
    uVar8 = DAT_230077b2;
    uVar9 = DAT_230077b3;
    uVar10 = DAT_230077b4;
    bVar1 = DAT_230077b5;
    DAT_230077b5 = local_27;
    DAT_230077b3 = local_22;
    DAT_230077b4 = local_22;
    DAT_230077b0 = local_21;
    DAT_230077b1 = local_21;
    DAT_230077af = local_20;
    DAT_230077ae = local_1f;
    DAT_230077ad = local_1e;
    DAT_230077ac = local_1d;
    DAT_230077b2 = local_1c;
  }
  else {
    iVar11 = thunk_FUN_0e094c5c(&DAT_23006788,param_2,0,0);
    if (iVar11 != 0) {
      return;
    }
    iVar11 = FUN_2302a8a8(0x16,&local_28,6);
    thunk_FUN_0e094d58(&DAT_23006788);
    uVar2 = DAT_230077ac;
    uVar3 = DAT_230077ad;
    uVar4 = DAT_230077ae;
    uVar5 = DAT_230077af;
    uVar6 = DAT_230077b0;
    uVar7 = DAT_230077b1;
    uVar8 = DAT_230077b2;
    uVar9 = DAT_230077b3;
    uVar10 = DAT_230077b4;
    bVar1 = DAT_230077b5;
    DAT_230077b5 = local_27;
  }
  if (iVar11 != 0) {
    if ((char)local_28 < '\0') {
      DAT_230076e8 = local_24;
      DAT_230076ea = local_26;
    }
    DAT_230077a6 = (byte)(((uint)local_28 << 0x1d) >> 0x1f);
    iVar11 = (uint)local_28 << 0x1c;
    DAT_230077a5 = (byte)((uint)iVar11 >> 0x1f);
    bVar1 = DAT_230077ab;
    if (((DAT_230077a9 == '\x01') && (bVar1 = DAT_230077a5, iVar11 < 0)) &&
       (bVar1 = DAT_230077ab, DAT_230077ab == 0)) {
      DAT_230077a8 = DAT_230077a8 + '\x01';
      bVar1 = 1;
    }
    DAT_230077ab = bVar1;
    if ((DAT_230077b5 & 0xf7) != 0xb7) {
      DAT_23006bd8 = DAT_23006bd8 + 1;
      thunk_FUN_0e084b08();
    }
    DAT_23001508._1_1_ = local_28 & 0x20;
    if ((local_28 & 0x20) != 0) {
      DAT_230077bd = 0;
      return;
    }
    DAT_230077bd = DAT_230077bd + 1;
    DAT_23006bd4 = DAT_23006bd4 + 1;
    uVar2 = DAT_230077ac;
    uVar3 = DAT_230077ad;
    uVar4 = DAT_230077ae;
    uVar5 = DAT_230077af;
    uVar6 = DAT_230077b0;
    uVar7 = DAT_230077b1;
    uVar8 = DAT_230077b2;
    uVar9 = DAT_230077b3;
    uVar10 = DAT_230077b4;
    bVar1 = DAT_230077b5;
    if (2 < DAT_230077bd) {
      DAT_230077bd = 0;
      thunk_FUN_0e084b08();
      uVar2 = DAT_230077ac;
      uVar3 = DAT_230077ad;
      uVar4 = DAT_230077ae;
      uVar5 = DAT_230077af;
      uVar6 = DAT_230077b0;
      uVar7 = DAT_230077b1;
      uVar8 = DAT_230077b2;
      uVar9 = DAT_230077b3;
      uVar10 = DAT_230077b4;
      bVar1 = DAT_230077b5;
    }
  }
  DAT_230077b5 = bVar1;
  DAT_230077b4 = uVar10;
  DAT_230077b3 = uVar9;
  DAT_230077b2 = uVar8;
  DAT_230077b1 = uVar7;
  DAT_230077b0 = uVar6;
  DAT_230077af = uVar5;
  DAT_230077ae = uVar4;
  DAT_230077ad = uVar3;
  DAT_230077ac = uVar2;
  return;
}


