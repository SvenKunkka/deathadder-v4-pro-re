/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e09495c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e09495c(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar2 = &DAT_230015e8;
  do {
    puVar4 = *(undefined4 **)(puVar2 + 8);
    if ((((uint)puVar4 | *(uint *)(puVar2 + 0x14)) & 3) != 0) {
      return 0xffffffea;
    }
    *(undefined4 *)(puVar2 + 0xc) = 0;
    puVar3 = (undefined4 *)(*(uint *)(puVar2 + 0x14) * (*(int *)(puVar2 + 0x10) + -1) + (int)puVar4)
    ;
    puVar1 = (undefined4 *)0x0;
    if (puVar4 <= puVar3) {
      do {
        puVar4 = puVar3;
        *puVar4 = puVar1;
        puVar1 = puVar4;
        puVar3 = (undefined4 *)((int)puVar4 - *(int *)(puVar2 + 0x14));
      } while (*(undefined4 **)(puVar2 + 8) <= (undefined4 *)((int)puVar4 - *(int *)(puVar2 + 0x14))
              );
      *(undefined4 **)(puVar2 + 0xc) = puVar4;
    }
    puVar2 = puVar2 + 0x1c;
  } while (puVar2 < &DAT_23001604);
  return 0;
}


