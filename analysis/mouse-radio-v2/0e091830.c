/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091830. Types and names are inferred; NOT original source. */

undefined4 FUN_0e091830(uint *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  iVar2 = DAT_0e0918c8;
  uVar7 = (uint)(byte)param_1[1];
  iVar3 = DAT_0e0918c8 + uVar7 * 0x28;
  if (*(char *)(iVar3 + 0x22) == '\0') {
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar2 + uVar7 * 0x28) = param_3;
    *(undefined4 *)(iVar3 + 4) = param_4;
    *(undefined1 *)(iVar3 + 0x25) = 0;
    *(undefined1 *)(iVar3 + 0x24) = 0;
    if (param_2 != (undefined4 *)0x0) {
      cVar1 = *(char *)((int)param_2 + 0xe);
      *(char *)(iVar3 + 0x27) = cVar1;
      if (cVar1 == '\0') {
        FUN_0e09175c(param_2);
      }
      *(undefined1 *)(iVar2 + uVar7 * 0x28 + 0x26) = *(undefined1 *)((int)param_2 + 0xd);
      uVar4 = param_2[2];
      uVar5 = *param_1;
      if (*(char *)((int)param_2 + 0xf) == '\0') {
        uVar6 = param_2[1];
        *(undefined4 *)(uVar5 + 0x600) = *param_2;
        *(undefined4 *)(uVar5 + 0x604) = uVar6;
      }
      *(undefined4 *)(uVar5 + 0x524) = uVar4;
      if (*(int *)(iVar2 + (uint)(byte)param_1[1] * 0x28) != 0) {
        FUN_0e089fb8((*param_1 & 0x1fffff) >> 0xc);
      }
    }
    *(undefined1 *)(iVar2 + uVar7 * 0x28 + 0x22) = 1;
    return DAT_0e0918cc;
  }
  return DAT_0e0918d0;
}


