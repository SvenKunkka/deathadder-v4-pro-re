/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091708. Types and names are inferred; NOT original source. */

undefined4 FUN_0e091708(uint *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar6 = (uint)(byte)param_1[1];
  iVar1 = uVar6 * 0x28;
  if ((&DAT_230072fa)[iVar1] == '\0') {
    *(undefined4 *)(&DAT_230072e0 + iVar1) = 0;
    *(undefined4 *)(&DAT_230072d8 + uVar6 * 0x28) = param_3;
    *(undefined4 *)(&DAT_230072dc + iVar1) = param_4;
    (&DAT_230072fd)[iVar1] = 0;
    (&DAT_230072fc)[iVar1] = 0;
    if (param_2 != (undefined4 *)0x0) {
      cVar2 = *(char *)((int)param_2 + 0xe);
      (&DAT_230072ff)[iVar1] = cVar2;
      if (cVar2 == '\0') {
        FUN_0e091634(param_2);
      }
      (&DAT_230072fe)[uVar6 * 0x28] = *(undefined1 *)((int)param_2 + 0xd);
      uVar3 = param_2[2];
      uVar4 = *param_1;
      if (*(char *)((int)param_2 + 0xf) == '\0') {
        uVar5 = param_2[1];
        *(undefined4 *)(uVar4 + 0x600) = *param_2;
        *(undefined4 *)(uVar4 + 0x604) = uVar5;
      }
      *(undefined4 *)(uVar4 + 0x524) = uVar3;
      if (*(int *)(&DAT_230072d8 + (uint)(byte)param_1[1] * 0x28) != 0) {
        FUN_0e089e2c((*param_1 & 0x1fffff) >> 0xc);
      }
    }
    (&DAT_230072fa)[uVar6 * 0x28] = 1;
    return 0xbad0000;
  }
  return 0xbad000c;
}


