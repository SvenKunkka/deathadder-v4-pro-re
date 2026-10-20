/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07dc78. Types and names are inferred; NOT original source. */

void FUN_0e07dc78(void)

{
  undefined1 *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 in_r3;
  uint uVar7;
  
  uVar4 = DAT_0e07dedc;
  puVar3 = DAT_0e07deb0;
  puVar2 = DAT_0e07deac;
  puVar1 = DAT_0e07dea8;
  uVar7 = (uint)(byte)DAT_0e07dea8[7];
  if (uVar7 < 6) {
    if ((uVar7 != 0) && (uVar7 - 1 < 5)) {
                    /* WARNING: Could not recover jumptable at 0x0e07dc90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0e07dc90::switchdataD_0e07dc94 +
                (&switchD_0e07dc90::switchdataD_0e07dc94)[uVar7 - 1]))();
      return;
    }
switchD_0e07dc90_caseD_3:
    *DAT_0e07dea8 = 5;
    return;
  }
  if (uVar7 == 0x80) {
    *(undefined4 *)(DAT_0e07dea8 + 0xc) = 0;
    *(undefined4 *)(puVar1 + 8) = uVar4;
    puVar1[0x10] = 0xbe;
    return;
  }
  if (uVar7 != 0x83) goto switchD_0e07dc90_caseD_3;
  uVar7 = *DAT_0e07deac;
  if (uVar7 != 0) {
    uVar6 = *DAT_0e07dec4;
    iVar5 = uVar7 - uVar6 * (uVar7 / uVar6);
    if (iVar5 != 0) {
      uVar7 = (uVar7 + uVar6) - iVar5;
    }
    iVar5 = FUN_0e088b28(*DAT_0e07deb0,*DAT_0e07debc,DAT_0e07decc,uVar7,in_r3);
    if (iVar5 != 0) goto LAB_0e07dcc8;
    *puVar2 = 0;
  }
  uVar7 = *(uint *)(puVar1 + 9);
  iVar5 = FUN_0e088af0(*puVar3,uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 |
                               (uVar7 >> 0x10 & 0xff) << 8 | uVar7 >> 0x18,DAT_0e07deb4,puVar1[8]);
  if (iVar5 == 0) {
    return;
  }
LAB_0e07dcc8:
  *puVar1 = 3;
  return;
}


