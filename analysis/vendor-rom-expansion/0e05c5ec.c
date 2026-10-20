
void FUN_0e05c5ec(undefined1 *param_1)

{
  char cVar1;
  
  cVar1 = DAT_230071d1;
  if (DAT_230071d1 == '\0') {
    if (DAT_230071dd == '\x01') {
      if (DAT_230071c7 == '\0') {
        DAT_230071dd = DAT_230071c7;
      }
      else {
        ram_candidate_23021db0();
        FUN_0e05d230();
        DAT_230071c7 = cVar1;
        DAT_230071dd = cVar1;
      }
    }
    else if (DAT_230071c7 != '\0') goto LAB_0e05c61a;
  }
  else if (DAT_230071c7 != '\0') {
    ram_candidate_23021db0();
    FUN_0e05d230();
    DAT_230071c7 = '\0';
  }
  ram_candidate_23021d9c();
  FUN_0e05d1ac(&DAT_230065e8);
  DAT_230071c7 = '\x01';
LAB_0e05c61a:
  DAT_230071d1 = 1;
  DAT_230071cf = *param_1;
  DAT_230071ce = param_1[1];
  DAT_230071cd = param_1[2];
  DAT_230071cc = param_1[3];
  DAT_230071cb = param_1[4];
  DAT_230071ca = param_1[5];
  DAT_230071ac = *(ushort *)(param_1 + 6) << 8 | *(ushort *)(param_1 + 6) >> 8;
  DAT_230071aa = *(ushort *)(param_1 + 8) << 8 | *(ushort *)(param_1 + 8) >> 8;
  DAT_230071a8 = *(ushort *)(param_1 + 10) << 8 | *(ushort *)(param_1 + 10) >> 8;
  DAT_230071a6 = *(ushort *)(param_1 + 0xc) << 8 | *(ushort *)(param_1 + 0xc) >> 8;
  DAT_230071d0 = 1;
  return;
}


