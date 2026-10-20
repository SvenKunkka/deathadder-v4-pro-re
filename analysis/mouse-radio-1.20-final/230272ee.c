/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230272ee. Types and names are inferred; NOT original source. */

void ram_candidate_230272ee(int param_1)

{
  uint uVar1;
  int iVar2;
  int unaff_r4;
  int in_r12;
  
  switch(*(undefined1 *)(unaff_r4 + in_r12 + 6)) {
  case 1:
    if (param_1 == 1) {
      iVar2 = DAT_23004a60._1_1_ - 1;
      if ((int)(DAT_23004a60._2_1_ + 1) <= (int)(DAT_23004a60._1_1_ - 1)) {
        iVar2 = DAT_23004a60._2_1_ + 1;
      }
      DAT_23004a60._2_1_ = (byte)iVar2;
      thunk_FUN_0e080328();
      thunk_FUN_0e07f0c4();
      return;
    }
    break;
  case 2:
    if (param_1 == 1) {
      if (DAT_23004a60._2_1_ == 0) {
        DAT_23004a60._2_1_ = 1;
      }
      DAT_23004a60._2_1_ = DAT_23004a60._2_1_ - 1;
      thunk_FUN_0e080328();
      thunk_FUN_0e07f0c4();
      return;
    }
    break;
  case 3:
    if (param_1 == 1) {
      DAT_23004a60._2_1_ = *(char *)(unaff_r4 + in_r12 + 8) - 1;
      thunk_FUN_0e07f0c4();
      if (DAT_23004a60._2_1_ < 5) {
        thunk_FUN_0e080328();
        return;
      }
    }
    break;
  case 4:
    if (param_1 != 1) {
      DAT_23007765 = 0;
      ram_candidate_23027290();
      return;
    }
    DAT_23007765 = (char)param_1;
    ram_candidate_23027290();
    return;
  case 5:
    if (param_1 != 1) {
      DAT_23007766 = 0;
      thunk_FUN_0e08042c((undefined2)DAT_23004a8c,DAT_23004a8c._2_2_);
      thunk_FUN_0e0803e4(2,0);
      return;
    }
    iVar2 = unaff_r4 + in_r12;
    DAT_23004a8a = CONCAT11(*(undefined1 *)(iVar2 + 0xc),*(undefined1 *)(iVar2 + 0xe));
    DAT_23004a88 = CONCAT11(*(undefined1 *)(iVar2 + 8),*(undefined1 *)(iVar2 + 10));
    DAT_23007766 = (char)param_1;
    thunk_FUN_0e080454(DAT_23004a88);
    thunk_FUN_0e0803e4(2,0);
    return;
  case 6:
    if (*(char *)(unaff_r4 + in_r12) == '`') {
      if (param_1 != 0) {
        return;
      }
      if (DAT_230077a2 == '\0') {
        if ((DAT_2300777c == '\0') && (DAT_2300777b == '\0')) {
          return;
        }
        if (DAT_2300777d != '\0') {
          return;
        }
      }
      uVar1 = (uint)DAT_23004a60._2_1_;
      DAT_23004a60._2_1_ = 0;
      if (uVar1 + 1 < (uint)DAT_23004a60._1_1_) {
        DAT_23004a60._2_1_ = (byte)(uVar1 + 1);
      }
      thunk_FUN_0e080328();
      thunk_FUN_0e07f0c4();
      return;
    }
    if (param_1 != 1) {
      return;
    }
    uVar1 = DAT_23004a60._2_1_ + 1;
    if (DAT_23004a60._1_1_ <= uVar1) {
      DAT_23004a60._2_1_ = 0;
      goto LAB_230277f0;
    }
    goto LAB_230277ee;
  case 7:
    if (param_1 != 1) {
      return;
    }
    uVar1 = (uint)DAT_23004a60._2_1_;
    if (uVar1 == 0) {
      uVar1 = (uint)DAT_23004a60._1_1_;
    }
    uVar1 = uVar1 - 1;
LAB_230277ee:
    DAT_23004a60._2_1_ = (byte)uVar1;
LAB_230277f0:
    thunk_FUN_0e080328();
    thunk_FUN_0e07f0c4();
    return;
  }
  return;
}


