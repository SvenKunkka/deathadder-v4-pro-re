
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_230203cc(int param_1)

{
  if (param_1 == 0) {
    _DAT_23002c84 = (uint)DAT_23002c84;
    return;
  }
  if (param_1 != 1) {
    _DAT_23002c84 = 0;
    DAT_230071bd = 0;
    FUN_2302060c(1);
    return;
  }
  DAT_230071bd = 1;
  _DAT_23002c84 = param_1;
  FUN_2302060c();
  return;
}


