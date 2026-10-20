/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e09175c. Types and names are inferred; NOT original source. */

void FUN_0e09175c(uint *param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = DAT_0e09182c;
  iVar5 = DAT_0e091828;
  uVar3 = *param_1;
  if (0x13f < uVar3) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)software_udf(0xff,0xe091804);
    (*pcVar1)();
  }
  iVar2 = *(int *)(DAT_0e091828 + (uVar3 >> 5) * 4) + (uVar3 & 0x1f) * 4;
  *(uint *)(iVar2 + 0x80) = *(uint *)(iVar2 + 0x80) & DAT_0e09182c | 0x80c;
  uVar3 = param_1[1];
  if (0x13f < uVar3) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)software_udf(0xff,0xe091824);
    (*pcVar1)();
  }
  iVar2 = *(int *)(iVar5 + (uVar3 >> 5) * 4) + (uVar3 & 0x1f) * 4;
  *(uint *)(iVar2 + 0x80) = *(uint *)(iVar2 + 0x80) & uVar4 | 0x80c;
  uVar4 = *param_1;
  if (0x13f < uVar4) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)software_udf(0xff,0xe091818);
    (*pcVar1)();
  }
  iVar2 = *(int *)(iVar5 + (uVar4 >> 5) * 4) + (uVar4 & 0x1f) * 4;
  *(uint *)(iVar2 + 0x80) = *(uint *)(iVar2 + 0x80) | 0x80000000;
  uVar4 = param_1[1];
  if (uVar4 < 0x140) {
    iVar5 = *(int *)(iVar5 + (uVar4 >> 5) * 4) + (uVar4 & 0x1f) * 4;
    *(uint *)(iVar5 + 0x80) = *(uint *)(iVar5 + 0x80) | 0x80000000;
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0xe09180e);
  (*pcVar1)();
}


