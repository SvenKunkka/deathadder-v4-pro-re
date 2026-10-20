/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091634. Types and names are inferred; NOT original source. */

void FUN_0e091634(uint *param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *param_1;
  if (0x13f < uVar3) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)software_udf(0xff,0xe0916dc);
    (*pcVar1)();
  }
  iVar2 = *(int *)(&DAT_0e09b6f0 + (uVar3 >> 5) * 4) + (uVar3 & 0x1f) * 4;
  *(uint *)(iVar2 + 0x80) = *(uint *)(iVar2 + 0x80) & 0xfffcf0f0 | 0x80c;
  uVar3 = param_1[1];
  if (0x13f < uVar3) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)software_udf(0xff,0xe0916fc);
    (*pcVar1)();
  }
  iVar2 = *(int *)(&DAT_0e09b6f0 + (uVar3 >> 5) * 4) + (uVar3 & 0x1f) * 4;
  *(uint *)(iVar2 + 0x80) = *(uint *)(iVar2 + 0x80) & 0xfffcf0f0 | 0x80c;
  uVar3 = *param_1;
  if (0x13f < uVar3) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)software_udf(0xff,0xe0916f0);
    (*pcVar1)();
  }
  iVar2 = *(int *)(&DAT_0e09b6f0 + (uVar3 >> 5) * 4) + (uVar3 & 0x1f) * 4;
  *(uint *)(iVar2 + 0x80) = *(uint *)(iVar2 + 0x80) | 0x80000000;
  uVar3 = param_1[1];
  if (uVar3 < 0x140) {
    iVar2 = *(int *)(&DAT_0e09b6f0 + (uVar3 >> 5) * 4) + (uVar3 & 0x1f) * 4;
    *(uint *)(iVar2 + 0x80) = *(uint *)(iVar2 + 0x80) | 0x80000000;
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0xe0916e6);
  (*pcVar1)();
}


