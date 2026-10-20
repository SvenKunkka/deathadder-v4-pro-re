/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e084890. Types and names are inferred; NOT original source. */

void FUN_0e084890(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  FUN_0e0973ea(&DAT_23003f64,0,0x510);
  FUN_0e094c5c(&DAT_23006788,extraout_r1,0x9d,0);
  thunk_FUN_2302ab40(0x7f,0);
  bVar1 = thunk_FUN_2302aa40(0x40);
  thunk_FUN_2302ab40(0x55,4);
  thunk_FUN_2302ab40(0x40,0x80);
  uVar2 = thunk_FUN_2302aa40(2);
  if ((uVar2 & 3) == 0) {
    thunk_FUN_2302ab40(0x1a,0x81);
    while (iVar3 = thunk_FUN_2302aa40(0x1a), iVar3 != 0x81) {
      FUN_0e096164(0x20,0);
    }
    DAT_23007745 = 0;
    puVar4 = (undefined2 *)&DAT_23003f64;
    do {
      puVar5 = puVar4 + 0x12;
      thunk_FUN_2302a8a8((uint)((int)puVar4 + -0x23003f49) & 0xff,puVar4);
      puVar4 = puVar5;
    } while (puVar5 != &DAT_23004474);
    DAT_23007745 = 0;
  }
  thunk_FUN_2302ab40(0x40,bVar1 | 0x80);
  thunk_FUN_2302ab40(0x55,0);
  FUN_0e094d58(&DAT_23006788);
  return;
}


