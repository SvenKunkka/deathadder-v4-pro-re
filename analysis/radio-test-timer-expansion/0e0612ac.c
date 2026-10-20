
void FUN_0e0612ac(short param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (-1 < (int)uVar1) {
    *(int *)((uVar1 >> 5) * 4 + -0x1fff1f00) = 1 << (uVar1 & 0x1f);
  }
  return;
}


