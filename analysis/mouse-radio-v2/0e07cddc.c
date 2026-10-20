/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07cddc. Types and names are inferred; NOT original source. */

void FUN_0e07cddc(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  puVar2 = DAT_0e07d2d4;
  puVar1 = DAT_0e07cf98;
  uVar5 = (uint)(byte)DAT_0e07cf98[7];
  if (uVar5 < 0x7f) {
    if ((0x30 < uVar5) && (uVar5 - 0x31 < 0x4e)) {
                    /* WARNING: Could not recover jumptable at 0x0e07cdf2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0e07cdf2::switchdataD_0e07cdf6 +
                (&switchD_0e07cdf2::switchdataD_0e07cdf6)[uVar5 - 0x31]))();
      return;
    }
  }
  else {
    if (0xc2 < uVar5) {
      if (uVar5 == 0xf3) {
        uVar6 = DAT_0e07d2d4[3];
        uVar3 = DAT_0e07d2d4[1];
        uVar4 = DAT_0e07d2d4[2];
        *(undefined4 *)(DAT_0e07cf98 + 8) = *DAT_0e07d2d4;
        *(undefined4 *)(puVar1 + 0xc) = uVar3;
        *(undefined4 *)(puVar1 + 0x10) = uVar4;
        *(undefined4 *)(puVar1 + 0x14) = uVar6;
        uVar3 = puVar2[4];
        *(undefined2 *)(puVar1 + 0x1c) = *(undefined2 *)(puVar2 + 5);
        *(undefined4 *)(puVar1 + 0x18) = uVar3;
      }
      else if (uVar5 != 0xfe) {
        if (uVar5 == 0xf1) {
                    /* WARNING: Could not recover jumptable at 0x0e097640. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*DAT_0e097644)(DAT_0e07cf98 + 8);
          return;
        }
        goto switchD_0e07cdf2_caseD_34;
      }
      return;
    }
    if ((0xa8 < uVar5) && (uVar5 - 0xa9 < 0x1a)) {
                    /* WARNING: Could not recover jumptable at 0x0e07cea0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0e07cea0::switchdataD_0e07cea4 +
                (uint)*(byte *)((int)&USHORT_0e07cdfa + uVar5 + 1) * 2))();
      return;
    }
  }
switchD_0e07cdf2_caseD_34:
  *DAT_0e07cf98 = 3;
  return;
}


