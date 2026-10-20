/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024f64. Types and names are inferred; NOT original source. */

void ram_candidate_23024f64(void)

{
  undefined4 extraout_r1;
  int unaff_r5;
  uint in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000014;
  uint in_stack_00000018;
  
code_r0x23024f64:
  *(undefined1 *)(unaff_r5 + 2) = 1;
  FUN_23024d54();
  FUN_230221f8(1);
  if (*(char *)(unaff_r5 + 3) != '\0') {
    FUN_23022008();
    *(undefined2 *)(unaff_r5 + 0x54) = 5;
    ram_candidate_23024e46();
    return;
  }
code_r0x23024e46:
  thunk_FUN_0e06cc94();
  switch(in_stack_00000014) {
  case 1:
    in_stack_00000008 = in_stack_00000018;
    in_stack_0000000c = 4;
    FUN_2302206c(&stack0x00000008);
    FUN_23020108(in_stack_00000008 & 0xffff);
    ram_candidate_23024e46();
    return;
  default:
    goto code_r0x23024e46;
  case 4:
    FUN_23021f88(0);
    FUN_23022008();
    *(undefined2 *)(unaff_r5 + 0x54) = 5;
    ram_candidate_23024e46();
    return;
  case 8:
    FUN_23020fcc(0,in_stack_00000018);
    FUN_23020108(in_stack_00000018 & 0xffff);
    ram_candidate_23024e46();
    return;
  case 9:
    FUN_23021094(0,in_stack_00000018);
    ram_candidate_23024e46();
    return;
  case 10:
  case 0x28:
    *(undefined2 *)(unaff_r5 + 2) = 0;
    FUN_23024d54();
    ram_candidate_23024e46();
    return;
  case 0x29:
    *(undefined2 *)(unaff_r5 + 2) = 0x101;
    FUN_230221f8(1);
    FUN_23022008();
    thunk_FUN_0e06ebe0(&DAT_23001b10,extraout_r1,100000,0);
    *(undefined2 *)(unaff_r5 + 0x54) = 5;
    ram_candidate_23024e46();
    return;
  case 0x2b:
    *(undefined1 *)(unaff_r5 + 2) = 0;
    FUN_23024cd4();
    FUN_230221f8(0);
    ram_candidate_23024e46();
    return;
  case 0x2c:
    goto code_r0x23024f64;
  }
}


