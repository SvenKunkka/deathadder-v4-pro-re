/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302c178. Types and names are inferred; NOT original source. */

int FUN_2302c178(void)

{
  int iVar1;
  undefined4 in_r3;
  undefined **ppuVar2;
  int iVar3;
  undefined4 *puVar4;
  
  DAT_23006bb8 = 0;
  DAT_23006bba = 0;
  DAT_230077a1 = 0;
  DAT_230077a0 = 0;
  iVar3 = 0;
  DAT_230077a2 = 0;
  DAT_230077a4 = 0;
  DAT_23006bbc = 0;
  DAT_23006bbe = 0;
  DAT_2300779e = 0;
  puVar4 = &DAT_0e09ac74;
  ppuVar2 = &PTR_ram_candidate_2302bd48_1_23000500;
  DAT_23007784 = 1;
  while( true ) {
    iVar1 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    if ((&DAT_0e09ac5c)[iVar1] == 0) {
      return -6;
    }
    iVar1 = thunk_FUN_0e08d054((&DAT_0e09ac5c)[iVar1],*puVar4,*(undefined2 *)(puVar4 + 1),ppuVar2,
                               in_r3);
    puVar4 = puVar4 + 2;
    ppuVar2 = ppuVar2 + 9;
    if (iVar1 != 0) break;
    if (iVar3 == 3) {
      DAT_23006bc0 = thunk_FUN_0e079bd0(0x2302bbd5);
      if (DAT_23006bc0 == 0) {
        iVar3 = -0x13;
      }
      else {
        FUN_2302b970();
        thunk_FUN_0e092628(DAT_2300773b,0x5f9a3154,&DAT_5f9a200c);
        thunk_FUN_0e092568(DAT_2300773b,0x5f9a2000);
        DAT_230077a4 = 1;
        DAT_230077a3 = 0;
        iVar3 = 0;
      }
      return iVar3;
    }
  }
  return iVar1;
}


