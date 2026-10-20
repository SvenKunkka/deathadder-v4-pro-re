/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e094a84. Types and names are inferred; NOT original source. */

undefined4 FUN_0e094a84(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar1 = DAT_0e094ad4;
  uVar3 = DAT_0e094ad0;
  while( true ) {
    if (uVar1 <= uVar3) {
      return 0;
    }
    puVar5 = *(undefined4 **)(uVar3 + 8);
    if ((((uint)puVar5 | *(uint *)(uVar3 + 0x14)) & 3) != 0) break;
    *(undefined4 *)(uVar3 + 0xc) = 0;
    puVar4 = (undefined4 *)(*(uint *)(uVar3 + 0x14) * (*(int *)(uVar3 + 0x10) + -1) + (int)puVar5);
    puVar2 = (undefined4 *)0x0;
    if (puVar5 <= puVar4) {
      do {
        puVar5 = puVar4;
        *puVar5 = puVar2;
        puVar4 = (undefined4 *)((int)puVar5 - *(int *)(uVar3 + 0x14));
        puVar2 = puVar5;
      } while (*(undefined4 **)(uVar3 + 8) <= puVar4);
      *(undefined4 **)(uVar3 + 0xc) = puVar5;
    }
    uVar3 = uVar3 + 0x1c;
  }
  return 0xffffffea;
}


